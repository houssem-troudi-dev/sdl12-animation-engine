#include "main.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void initBackground(Background* bg, const char* imagePath, int screenW, int screenH) {
    if (TTF_Init() == -1) {
        fprintf(stderr, "TTF_Init failed: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    bg->font = TTF_OpenFont("arial.ttf", 24);
    if (!bg->font) {
        fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    bg->start_time = SDL_GetTicks();
    bg->current_time = 0;
    bg->time_text = NULL;

    bg->background1 = IMG_Load("background_1.png");
    bg->background2 = IMG_Load("background.png");
    if (!bg->background1 || !bg->background2) {
        fprintf(stderr, "Failed to load backgrounds\n");
        exit(EXIT_FAILURE);
    }
    
    bg->current_level = 1;
    bg->level1_width = bg->background1->w;
    bg->image = bg->background1;

    bg->screen_width = screenW;
    bg->screen_height = screenH;

    int y = bg->image->h - screenH;
    bg->view1.camera = (SDL_Rect){0, y, screenW, screenH};
    bg->view2.camera = (SDL_Rect){0, y, screenW / 2, screenH};
    bg->view1.screen_area = (SDL_Rect){0, 0, screenW, screenH};
    bg->view2.screen_area = (SDL_Rect){screenW / 2, 0, screenW / 2, screenH};

    bg->is_multiplayer = false;
    bg->view1.scroll_left = false;
    bg->view1.scroll_right = false;
    bg->view1.jump_state = 0;
    bg->view2.scroll_left = false;
    bg->view2.scroll_right = false;
    bg->view2.jump_state = 0;
    bg->serial_left_pressed = false;
    bg->serial_right_pressed = false;
    bg->serial_fd = -1;

    // Initialize falling object
    bg->falling_object.image = IMG_Load("fireball.png");
    if (!bg->falling_object.image) {
        fprintf(stderr, "Failed to load falling object: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    bg->falling_object.position.x = rand() % (screenW - 50) + 50;
    bg->falling_object.position.y = 0;
    bg->falling_object.position.w = bg->falling_object.image->w;
    bg->falling_object.position.h = bg->falling_object.image->h;

    // Initialize enemy gun system
    bg->gun_position.x = 2065;
    bg->gun_position.y = 580;
    bg->gun_position.w = 0;
    bg->gun_position.h = 0;
    bg->fire_delay = 70;
    bg->fire_timer = 0;
    
    // Initialize bullets
    for (int i = 0; i < MAX_BULLETS; i++) {
        bg->bullets[i].frames[0] = IMG_Load("enemy-shoot1.png");
        bg->bullets[i].frames[1] = IMG_Load("enemy-shoot2.png");
        bg->bullets[i].frames[2] = IMG_Load("enemy-shoot3.png");
        
        if (!bg->bullets[i].frames[0] || !bg->bullets[i].frames[1] || !bg->bullets[i].frames[2]) {
            fprintf(stderr, "Failed to load bullet frames\n");
            exit(1);
        }
        
        bg->bullets[i].current_frame = 0;
        bg->bullets[i].frame_counter = 0;
        bg->bullets[i].is_active = false;
        bg->bullets[i].position.w = bg->bullets[i].frames[0]->w;
        bg->bullets[i].position.h = bg->bullets[i].frames[0]->h;
    }
    
    // Initialize laser traps
    SDL_Rect laser_positions[MAX_LASER_TRAPS] = {
        {2400, 135, 0, 0},
        {2630, 135, 0, 0},
        {2860, 135, 0, 0},
        {5340, 135, 0, 0},
        {5570, 135, 0, 0},
        {5800, 135, 0, 0}
    };

    for (int i = 0; i < MAX_LASER_TRAPS; i++) {
        for (int j = 0; j < 5; j++) {
            char filename[32];
            snprintf(filename, sizeof(filename), "%d.png", j+1);
            bg->laser_traps[i].frames[j] = IMG_Load(filename);
            if (!bg->laser_traps[i].frames[j]) {
                fprintf(stderr, "Failed to load laser frame %s\n", filename);
                exit(1);
            }
        }
        
        bg->laser_traps[i].position = laser_positions[i];
        bg->laser_traps[i].position.w = bg->laser_traps[i].frames[0]->w;
        bg->laser_traps[i].position.h = bg->laser_traps[i].frames[0]->h;
        bg->laser_traps[i].current_frame = 0;
        bg->laser_traps[i].frame_counter = 0;
        bg->laser_traps[i].frame_delay = 5;
        bg->laser_traps[i].state = 0;
        bg->laser_traps[i].animation_speed = 60 + (i * 20);
    }
    
    // Initialize lava animation
    bg->lava.base_y = bg->image->h + 30;
    
    for (int i = 0; i < 8; i++) {
        char filename[32];
        snprintf(filename, sizeof(filename), "lava%d.png", i+1);
        bg->lava.frames[i] = IMG_Load(filename);
        if (!bg->lava.frames[i]) {
            fprintf(stderr, "Failed to load lava frame %s\n", filename);
            exit(1);
        }
        
        bg->lava.positions[i].x = 805;
        bg->lava.positions[i].y = bg->lava.base_y - bg->lava.frames[i]->h;
        bg->lava.positions[i].w = bg->image->w;
        bg->lava.positions[i].h = bg->lava.frames[i]->h;
    }
    
    bg->lava.current_frame = 0;
    bg->lava.frame_counter = 0;
    bg->lava.frame_delay = 5;

    // Initialize eye animation
    for (int i = 0; i < 3; i++) {
        char filename[32];
        snprintf(filename, sizeof(filename), "eye%d.png", i+1);
        bg->eye_frames[i] = IMG_Load(filename);
        if (!bg->eye_frames[i]) {
            fprintf(stderr, "Failed to load eye frame %s\n", filename);
            exit(1);
        }
    }

    // Set positions for three eyes
    bg->eye_position1 = (SDL_Rect){743, 520, bg->eye_frames[0]->w, bg->eye_frames[0]->h};
    bg->eye_position2 = (SDL_Rect){1727, 609, bg->eye_frames[0]->w, bg->eye_frames[0]->h};
    bg->eye_position3 = (SDL_Rect){3667, 614, bg->eye_frames[0]->w, bg->eye_frames[0]->h};
    bg->current_eye_frame = 0;
    bg->eye_frame_counter = 0;
    bg->eye_frame_delay = 10;

    // Initialize text box guide
    bg->textboxes[0] = IMG_Load("textbox1.png");
    bg->textboxes[1] = IMG_Load("textbox2.png");
    bg->textboxes[2] = IMG_Load("textbox3.png");
    for (int i = 0; i < 3; i++) {
        if (!bg->textboxes[i]) {
            fprintf(stderr, "Failed to load textbox%d.png: %s\n", i+1, IMG_GetError());
            for (int j = 0; j < i; j++) {
                SDL_FreeSurface(bg->textboxes[j]);
            }
            freeBackground(bg);
            SDL_Quit();
            exit(EXIT_FAILURE);
        }
    }
    bg->current_textbox = 0;
    bg->show_textboxes = true;
}

void spawnBullet(Background* bg) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bg->bullets[i].is_active) {
            bg->bullets[i].is_active = true;
            bg->bullets[i].position.x = bg->gun_position.x;
            bg->bullets[i].position.y = bg->gun_position.y;
            bg->bullets[i].current_frame = 0;
            bg->bullets[i].frame_counter = 0;
            return;
        }
    }
}

void updateBullets(Background* bg) {
    bg->fire_timer++;
    if (bg->fire_timer >= bg->fire_delay) {
        bg->fire_timer = 0;
        spawnBullet(bg);
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bg->bullets[i].is_active) {
            bg->bullets[i].position.x -= 8;
            
            bg->bullets[i].frame_counter++;
            if (bg->bullets[i].frame_counter >= 5) {
                bg->bullets[i].frame_counter = 0;
                bg->bullets[i].current_frame = (bg->bullets[i].current_frame + 1) % 3;
            }
            
            if (bg->bullets[i].position.x + bg->bullets[i].position.w < 0) {
                bg->bullets[i].is_active = false;
            }
        }
    }
}

void updateEyeAnimation(Background* bg) {
    bg->eye_frame_counter++;
    if (bg->eye_frame_counter >= bg->eye_frame_delay) {
        bg->eye_frame_counter = 0;
        bg->current_eye_frame = (bg->current_eye_frame + 1) % 3;
    }
}

void updateLavaAnimation(LavaAnimation* lava) {
    lava->frame_counter++;
    if (lava->frame_counter >= lava->frame_delay) {
        lava->frame_counter = 0;
        lava->current_frame = (lava->current_frame + 1) % 8;
    }
}

void handleInput(Background* bg, SDL_Event* event) {
    switch (event->type) {
        case SDL_KEYDOWN:
            if (event->key.keysym.sym == SDLK_m) bg->is_multiplayer = !bg->is_multiplayer;
            if (event->key.keysym.sym == SDLK_LEFT) bg->view1.scroll_left = true;
            if (event->key.keysym.sym == SDLK_RIGHT) bg->view1.scroll_right = true;
            if (event->key.keysym.sym == SDLK_UP) bg->view1.jump_key_held = true;
            if (event->key.keysym.sym == SDLK_w) bg->view2.jump_key_held = true;
            if (event->key.keysym.sym == SDLK_a) bg->view2.scroll_left = true;
            if (event->key.keysym.sym == SDLK_d) bg->view2.scroll_right = true;
            break;

        case SDL_KEYUP:
            if (event->key.keysym.sym == SDLK_LEFT) bg->view1.scroll_left = false;
            if (event->key.keysym.sym == SDLK_RIGHT) bg->view1.scroll_right = false;
            if (event->key.keysym.sym == SDLK_UP) bg->view1.jump_key_held = false;
            if (event->key.keysym.sym == SDLK_w) bg->view2.jump_key_held = false;
            if (event->key.keysym.sym == SDLK_a) bg->view2.scroll_left = false;
            if (event->key.keysym.sym == SDLK_d) bg->view2.scroll_right = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (bg->show_textboxes && bg->current_level == 1) {
                bg->current_textbox++;
                if (bg->current_textbox >= 3) {
                    bg->show_textboxes = false;
                }
            }
            break;
    }
}

void updateFallingObject(Background* bg, int speed) {
    FallingObject* obj = &bg->falling_object;
    obj->position.y += speed;
    
    if (obj->position.y > bg->image->h) {
        obj->position.y = 0;
        obj->position.x = rand() % (bg->image->w - 100) + 50;
    }
}

void updateLaserTraps(Background* bg) {
    for (int i = 0; i < MAX_LASER_TRAPS; i++) {
        LaserTrap* trap = &bg->laser_traps[i];
        trap->frame_counter++;
        
        switch (trap->state) {
            case 0: // Off state
                if (trap->frame_counter >= trap->animation_speed) {
                    trap->state = 1;
                    trap->frame_counter = 0;
                    trap->current_frame = 0;
                }
                break;
                
            case 1: // Firing down
                if (trap->frame_counter >= trap->frame_delay) {
                    trap->frame_counter = 0;
                    trap->current_frame++;
                    
                    if (trap->current_frame >= 4) {
                        trap->state = 2;
                    }
                }
                break;
                
            case 2: // Cooldown
                if (trap->frame_counter >= trap->frame_delay) {
                    trap->frame_counter = 0;
                    trap->current_frame--;
                    
                    if (trap->current_frame <= 0) {
                        trap->current_frame = 0;
                        trap->state = 0;
                    }
                }
                break;
        }
    }
}

void updateBackground(Background* bg, int scroll_speed) {
    // Check for level transition
    if (bg->current_level == 1 && bg->view1.camera.x >= bg->level1_width - bg->screen_width) {
        bg->current_level = 2;
        bg->image = bg->background2;
        bg->view1.camera.x = 0;
        bg->view2.camera.x = 0;
        bg->show_textboxes = false;
    }

    int y = bg->image->h - bg->screen_height;

    // Update view1 jump state
    if (bg->view1.jump_state > 0) {
        if (bg->view1.jump_state <= 10) {
            bg->view1.camera.y = y - 10 * bg->view1.jump_state;
        } else if (bg->view1.jump_state <= 20) {
            bg->view1.camera.y = y - 10 * (20 - bg->view1.jump_state);
        }
        bg->view1.jump_state++;
        if (bg->view1.jump_state > 20) {
            bg->view1.jump_state = 0;
            if (bg->view1.jump_key_held) bg->view1.jump_state = 1;
        }
    } else if (bg->view1.jump_key_held) {
        bg->view1.jump_state = 1;
    }

    // Update view2 jump state
    if (bg->view2.jump_state > 0) {
        if (bg->view2.jump_state <= 10) {
            bg->view2.camera.y = y - 10 * bg->view2.jump_state;
        } else if (bg->view2.jump_state <= 20) {
            bg->view2.camera.y = y - 10 * (20 - bg->view2.jump_state);
        }
        bg->view2.jump_state++;
        if (bg->view2.jump_state > 20) {
            bg->view2.jump_state = 0;
            if (bg->view2.jump_key_held) bg->view2.jump_state = 1;
        }
    } else if (bg->view2.jump_key_held) {
        bg->view2.jump_state = 1;
    }

    // Update view1 camera position
    int dx1 = 0;
    if (bg->view1.scroll_left || bg->serial_left_pressed) dx1 -= scroll_speed;
    if (bg->view1.scroll_right || bg->serial_right_pressed) dx1 += scroll_speed;
    bg->view1.camera.x += dx1;
    if (bg->view1.camera.x < 0) bg->view1.camera.x = 0;
    if (bg->view1.camera.x > bg->image->w - bg->screen_width)
        bg->view1.camera.x = bg->image->w - bg->screen_width;

    // Update view2 camera position in multiplayer
    if (bg->is_multiplayer) {
        int dx2 = (bg->view2.scroll_right - bg->view2.scroll_left) * scroll_speed;
        bg->view2.camera.x += dx2;
        if (bg->view2.camera.x < 0) bg->view2.camera.x = 0;
        if (bg->view2.camera.x > bg->image->w - bg->screen_width / 2)
            bg->view2.camera.x = bg->image->w - bg->screen_width / 2;
    } else {
        bg->view2.camera.x = bg->view1.camera.x;
    }

    // Update game objects
    updateFallingObject(bg, 5);
    updateBullets(bg);
    updateLaserTraps(bg);
    updateLavaAnimation(&bg->lava);
    if (bg->current_level == 1) updateEyeAnimation(bg);
}

void updateTimer(Background* bg) {
    bg->current_time = (SDL_GetTicks() - bg->start_time) / 1000;
    char time_str[32];
    snprintf(time_str, sizeof(time_str), "%02d:%02d", bg->current_time / 60, bg->current_time % 60);
    SDL_Color white = {255, 255, 255, 255};
    if (bg->time_text) SDL_FreeSurface(bg->time_text);
    bg->time_text = TTF_RenderText_Solid(bg->font, time_str, white);
}

void renderBackground(Background* bg, SDL_Surface* screen) {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    if (bg->is_multiplayer) {
        SDL_Rect left_half = {0, 0, bg->screen_width / 2, bg->screen_height};
        SDL_Rect right_half = {bg->screen_width / 2, 0, bg->screen_width / 2, bg->screen_height};

        SDL_BlitSurface(bg->image, &bg->view1.camera, screen, &left_half);
        SDL_BlitSurface(bg->image, &bg->view2.camera, screen, &right_half);

        SDL_Rect divider = {bg->screen_width / 2, 0, 5, bg->screen_height};
        SDL_FillRect(screen, &divider, SDL_MapRGB(screen->format, 255, 255, 0));
    } else {
        SDL_BlitSurface(bg->image, &bg->view1.camera, screen, NULL);
    }

    // Render eye animation in level 1
    if (bg->current_level == 1) {
        SDL_Rect eye_positions[3] = {bg->eye_position1, bg->eye_position2, bg->eye_position3};

        if (bg->is_multiplayer) {
            // View 1
            for (int i = 0; i < 3; i++) {
                SDL_Rect eye_pos = eye_positions[i];
                if (eye_pos.x >= bg->view1.camera.x && 
                    eye_pos.x < bg->view1.camera.x + bg->screen_width/2) {
                    SDL_Rect render_pos = {
                        eye_pos.x - bg->view1.camera.x,
                        eye_pos.y - bg->view1.camera.y,
                        eye_pos.w,
                        eye_pos.h
                    };
                    SDL_BlitSurface(bg->eye_frames[bg->current_eye_frame], NULL, screen, &render_pos);
                }
            }
            
            // View 2
            for (int i = 0; i < 3; i++) {
                SDL_Rect eye_pos = eye_positions[i];
                if (eye_pos.x >= bg->view2.camera.x && 
                    eye_pos.x < bg->view2.camera.x + bg->screen_width/2) {
                    SDL_Rect render_pos = {
                        eye_pos.x - bg->view2.camera.x + bg->screen_width/2,
                        eye_pos.y - bg->view2.camera.y,
                        eye_pos.w,
                        eye_pos.h
                    };
                    SDL_BlitSurface(bg->eye_frames[bg->current_eye_frame], NULL, screen, &render_pos);
                }
            }
        } else {
            // Single player
            for (int i = 0; i < 3; i++) {
                SDL_Rect eye_pos = eye_positions[i];
                if (eye_pos.x >= bg->view1.camera.x && 
                    eye_pos.x < bg->view1.camera.x + bg->screen_width) {
                    SDL_Rect render_pos = {
                        eye_pos.x - bg->view1.camera.x,
                        eye_pos.y - bg->view1.camera.y,
                        eye_pos.w,
                        eye_pos.h
                    };
                    SDL_BlitSurface(bg->eye_frames[bg->current_eye_frame], NULL, screen, &render_pos);
                }
            }
        }
    }

    // Render falling object
    SDL_Rect obj_pos = bg->falling_object.position;
    if (bg->is_multiplayer) {
        obj_pos.x -= bg->view1.camera.x;
        obj_pos.y -= bg->view1.camera.y;
        if (obj_pos.x >= 0 && obj_pos.x < bg->screen_width / 2) {
            SDL_BlitSurface(bg->falling_object.image, NULL, screen, &obj_pos);
        }

        obj_pos.x = bg->falling_object.position.x - bg->view2.camera.x;
        obj_pos.y = bg->falling_object.position.y - bg->view2.camera.y;
        obj_pos.x += bg->screen_width / 2;
        if (obj_pos.x >= bg->screen_width / 2 && obj_pos.x < bg->screen_width) {
            SDL_BlitSurface(bg->falling_object.image, NULL, screen, &obj_pos);
        }
    } else {
        obj_pos.x -= bg->view1.camera.x;
        obj_pos.y -= bg->view1.camera.y;
        SDL_BlitSurface(bg->falling_object.image, NULL, screen, &obj_pos);
    }

    // Render bullets
    if (bg->current_level == 2) {
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (bg->bullets[i].is_active) {
                SDL_Rect bullet_pos = bg->bullets[i].position;
                if (bg->is_multiplayer) {
                    bullet_pos.x -= bg->view1.camera.x;
                    bullet_pos.y -= bg->view1.camera.y;
                    if (bullet_pos.x >= 0 && bullet_pos.x < bg->screen_width / 2) {
                        SDL_BlitSurface(bg->bullets[i].frames[bg->bullets[i].current_frame], 
                                       NULL, screen, &bullet_pos);
                    }
                    
                    bullet_pos.x = bg->bullets[i].position.x - bg->view2.camera.x;
                    bullet_pos.y = bg->bullets[i].position.y - bg->view2.camera.y;
                    bullet_pos.x += bg->screen_width / 2;
                    if (bullet_pos.x >= bg->screen_width / 2 && bullet_pos.x < bg->screen_width) {
                        SDL_BlitSurface(bg->bullets[i].frames[bg->bullets[i].current_frame], 
                                       NULL, screen, &bullet_pos);
                    }
                } else {
                    bullet_pos.x -= bg->view1.camera.x;
                    bullet_pos.y -= bg->view1.camera.y;
                    SDL_BlitSurface(bg->bullets[i].frames[bg->bullets[i].current_frame], 
                                   NULL, screen, &bullet_pos);
                }
            }
        }
    }    
    // Render laser traps
    if (bg->current_level == 2) {
        for (int i = 0; i < MAX_LASER_TRAPS; i++) {
            SDL_Rect laser_pos = bg->laser_traps[i].position;
            if (bg->is_multiplayer) {
                laser_pos.x -= bg->view1.camera.x;
                laser_pos.y -= bg->view1.camera.y;
                if (laser_pos.x >= 0 && laser_pos.x < bg->screen_width / 2) {
                    SDL_BlitSurface(bg->laser_traps[i].frames[bg->laser_traps[i].current_frame], 
                                   NULL, screen, &laser_pos);
                }
                
                laser_pos.x = bg->laser_traps[i].position.x - bg->view2.camera.x;
                laser_pos.y = bg->laser_traps[i].position.y - bg->view2.camera.y;
                laser_pos.x += bg->screen_width / 2;
                if (laser_pos.x >= bg->screen_width / 2 && laser_pos.x < bg->screen_width) {
                    SDL_BlitSurface(bg->laser_traps[i].frames[bg->laser_traps[i].current_frame], 
                                   NULL, screen, &laser_pos);
                }
            } else {
                laser_pos.x -= bg->view1.camera.x;
                laser_pos.y -= bg->view1.camera.y;
                SDL_BlitSurface(bg->laser_traps[i].frames[bg->laser_traps[i].current_frame], 
                               NULL, screen, &laser_pos);
            }
        }
    }

    // Render lava animation
    if (bg->current_level == 2) {
        if (bg->is_multiplayer) {
            SDL_Rect lava_pos1 = bg->lava.positions[bg->lava.current_frame];
            lava_pos1.x -= bg->view1.camera.x;
            lava_pos1.y -= bg->view1.camera.y;
            SDL_BlitSurface(bg->lava.frames[bg->lava.current_frame], NULL, screen, &lava_pos1);
            
            SDL_Rect lava_pos2 = bg->lava.positions[bg->lava.current_frame];
            lava_pos2.x = lava_pos2.x - bg->view2.camera.x + bg->screen_width/2;
            lava_pos2.y -= bg->view2.camera.y;
            SDL_BlitSurface(bg->lava.frames[bg->lava.current_frame], NULL, screen, &lava_pos2);
        } else {
            SDL_Rect lava_pos = bg->lava.positions[bg->lava.current_frame];
            lava_pos.x -= bg->view1.camera.x;
            lava_pos.y -= bg->view1.camera.y;
            SDL_BlitSurface(bg->lava.frames[bg->lava.current_frame], NULL, screen, &lava_pos);
        }
    }

    // Render text box guide in level 1
    if (bg->current_level == 1 && bg->show_textboxes) {
        SDL_Rect textbox_pos = {(bg->screen_width - 1000) / 2, (bg->screen_height - 300) / 2, 400, 300};
        if (bg->is_multiplayer) {
            // Render in left view
            SDL_BlitSurface(bg->textboxes[bg->current_textbox], NULL, screen, &textbox_pos);
            // Render in right view
            SDL_Rect textbox_pos2 = {(bg->screen_width / 2 + (bg->screen_width / 2 - 400) / 2), (bg->screen_height - 300) / 2, 400, 300};
            SDL_BlitSurface(bg->textboxes[bg->current_textbox], NULL, screen, &textbox_pos2);
        } else {
            SDL_BlitSurface(bg->textboxes[bg->current_textbox], NULL, screen, &textbox_pos);
        }
    }

    if (bg->time_text) {
        SDL_Rect timer_pos = {10, 10, 0, 0};
        SDL_BlitSurface(bg->time_text, NULL, screen, &timer_pos);
    }
}

void freeBackground(Background* bg) {
    SDL_FreeSurface(bg->background1);
    SDL_FreeSurface(bg->background2);
    SDL_FreeSurface(bg->falling_object.image);
    if (bg->time_text) SDL_FreeSurface(bg->time_text);
    
    for (int i = 0; i < MAX_BULLETS; i++) {
        for (int j = 0; j < 3; j++) {
            if (bg->bullets[i].frames[j]) {
                SDL_FreeSurface(bg->bullets[i].frames[j]);
            }
        }
    }
    
    for (int i = 0; i < MAX_LASER_TRAPS; i++) {
        for (int j = 0; j < 5; j++) {
            if (bg->laser_traps[i].frames[j]) {
                SDL_FreeSurface(bg->laser_traps[i].frames[j]);
            }
        }
    }
    
    for (int i = 0; i < 8; i++) {
        if (bg->lava.frames[i]) {
            SDL_FreeSurface(bg->lava.frames[i]);
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (bg->eye_frames[i]) {
            SDL_FreeSurface(bg->eye_frames[i]);
        }
        if (bg->textboxes[i]) {
            SDL_FreeSurface(bg->textboxes[i]);
        }
    }
    
    TTF_CloseFont(bg->font);
    TTF_Quit();
}
