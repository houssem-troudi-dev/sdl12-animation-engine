#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include "charather3.h"


void init_animal(Animal *animal, charathere1 *c1) {
    char filename[256];
    for (int i = 0; i < ANIMAL_FRAMES; i++) {
        sprintf(filename, "/home/king/Documents/main_charather 3/pet/idleleft/idle%d.png", i+1);
        animal->idleLeft[i] = IMG_Load(filename);
        
        sprintf(filename, "/home/king/Documents/main_charather 3/pet/idleright/idle%d.png", i+1);
        animal->idleRight[i] = IMG_Load(filename);
        
        sprintf(filename, "/home/king/Documents/main_charather 3/pet/runleft/run%d.png", i+1);
        animal->moveLeft[i] = IMG_Load(filename);
        
        sprintf(filename, "/home/king/Documents/main_charather 3/pet/runright/run%d.png", i+1);
        animal->moveRight[i] = IMG_Load(filename);
    }
    
    animal->currentFrame = 0;
    animal->animationSpeed = 100;
    animal->lastFrameTime = 0;
    animal->isMoving = 0;
    animal->direction = 1;
    
    animal->position.x = c1->positionimage.x;
    animal->position.y = 500;
    animal->position.w = 50;
    animal->position.h = 50;
}

void update_animal(Animal *animal, charathere1 *c1) {
    Uint32 currentTime = SDL_GetTicks();
    
    animal->position.x = c1->positionimage.x - 80;

    animal->isMoving = c1->ismoving;
    animal->direction = c1->ismovingR ? 1 : 0;
    
    if (currentTime - animal->lastFrameTime > animal->animationSpeed) {
        animal->currentFrame = (animal->currentFrame + 1) % ANIMAL_FRAMES;
        animal->lastFrameTime = currentTime;
    }
}

void render_animal(SDL_Surface *screen, Animal *animal) {
    SDL_Surface *currentFrame = NULL;
    
    if (animal->isMoving) {
        if (animal->direction == 0) {
            currentFrame = animal->moveLeft[animal->currentFrame];
        } else {
            currentFrame = animal->moveRight[animal->currentFrame];
        }
    } else {
        if (animal->direction == 0) {
            currentFrame = animal->idleLeft[animal->currentFrame];
        } else {
            currentFrame = animal->idleRight[animal->currentFrame];
        }
    }
    
    if (currentFrame) {
        SDL_BlitSurface(currentFrame, NULL, screen, &animal->position);
    }
}

void init_health_system(charathere1 *c1) {
    char filename[256];
    
    for (int i = 0; i < 3; i++) {
        sprintf(filename, "/home/king/Documents/main_charather 3/health_bar/h%d.png", i+1);
        c1->healthImages[i] = IMG_Load(filename);
        if (!c1->healthImages[i]) {
            printf("Failed to load health image %d: %s\n", i+1, IMG_GetError());
        }
    }
    for (int i = 0; i < MAX_DEATH_FRAMES; i++) {
        sprintf(filename, "/home/king/Documents/main_charather 3/health_bar/d%d.png", i+1);
        c1->deathAnimation[i] = IMG_Load(filename);
        if (!c1->deathAnimation[i]) {
            printf("Failed to load death frame %d: %s\n", i+1, IMG_GetError());
        }
    }
    
    c1->health = MAX_HEALTH;
    c1->isDead = 0;
    c1->deathAnimPlaying = 0;
    c1->deathFrame = 0;
}

void update_health(charathere1 *c1) {
    if (c1->health > 0) {
        c1->health--;
        
        if (c1->health <= 0) {
            c1->isDead = 1;
            c1->deathAnimPlaying = 1;
            c1->deathFrame = 0;
        }
    }
}

void render_health(SDL_Surface *screen, charathere1 *c1) {
    SDL_Rect healthPos = {10, 10, 0, 0};
    
    if (c1->health > 0) {
        SDL_BlitSurface(c1->healthImages[c1->health-1], NULL, screen, &healthPos);
    }
}

void render_death_animation(SDL_Surface *screen, charathere1 *c1) {
    if (c1->deathAnimPlaying) {
        SDL_Rect deathPos = c1->positionimage;
        
        if (c1->deathFrame < MAX_DEATH_FRAMES) {
            SDL_BlitSurface(c1->deathAnimation[c1->deathFrame], NULL, screen, &deathPos);
            c1->deathFrame++;
            SDL_Delay(100);
        } else {
            c1->deathAnimPlaying = 0;
        }
    }
}

void init_charather(charathere1 *c1) {
    c1->count0 = 0;
    c1->count1 = 0;
    c1->count2 = 0;
    c1->count3 = 0; 
    c1->positionimage.x = 500;
    c1->positionimage.y = 620;
    char filename[256];

    for (int i = 0; i < 5; ++i) {
    sprintf(filename, "/home/king/Documents/main_charather 3/idleleft/idle%d.png", i + 1);
    c1->idleleftImages[c1->count0] = IMG_Load(filename);
    if (c1->idleleftImages[c1->count0] != NULL) {
        sprintf(filename, "/home/king/Documents/main_charather 3/idleright/idle%d.png", i + 1);
        c1->idlerightImages[c1->count0] = IMG_Load(filename);
        if (c1->idlerightImages[c1->count0] != NULL) {
            c1->count0++; 
        } else {
            fprintf(stderr, "Error: Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
        }
    } else {
        fprintf(stderr, "Error: Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
    }
}

    for (int i = 0; i < 8; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/runleft/run%d.png", i + 1);
        c1->runleftImages[c1->count1] = IMG_Load(filename);
        if (c1->runleftImages[c1->count1] != NULL) {
            sprintf(filename, "/home/king/Documents/main_charather 3/runright/run%d.png", i + 1);
            c1->runrightImages[c1->count1] = IMG_Load(filename);
            if (c1->runrightImages[c1->count1] != NULL) {
                c1->count1++; 
            }
        }
    }

    for (int i = 0; i < 7; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/hitleft/hit%d.png", i + 1);
        c1->hitLeftImages[c1->count2] = IMG_Load(filename);
        if (c1->hitLeftImages[c1->count2] != NULL) {
            sprintf(filename, "/home/king/Documents/main_charather 3/hitright/hit%d.png", i + 1);
            c1->hitRightImages[c1->count2] = IMG_Load(filename);
            if (c1->hitRightImages[c1->count2] != NULL) {
                c1->count2++;
            }
        }
    }

    for (int i = 0; i < 7; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/jumpleft/jump%d.png", i + 1);
        c1->jumpleftImages[c1->count3] = IMG_Load(filename);
        if (c1->jumpleftImages[c1->count3] != NULL) {
            sprintf(filename, "/home/king/Documents/main_charather 3/jumpright/jump%d.png", i + 1);
            c1->jumprightImages[c1->count3] = IMG_Load(filename);
            if (c1->jumprightImages[c1->count3] != NULL) {
                c1->count3++;
            }
        }
    }

    c1->isJumping = 0;
    c1->onGround = 1;
    c1->yVelocity = 0;
    c1->gravity = 1;
    c1->jumpHeight = -20;
    c1->frameJump = 0;
    c1->jumpAnimCounter = 0;
    c1->jumpPhase = 0;

    c1->frameidleleft = 0;
    c1->frameidleright = 0;
    c1->framerunleft = 0;
    c1->framerunright = 0;
    c1->frameHitLeft = 0;
    c1->frameHitRight = 0;
    c1->ismoving = 0;
    c1->ismovingR = 1;
    c1->ismovingL = 1;
    c1->isHittingLeft = 0;
    c1->isHittingRight = 0;
    c1->oldwav = 0;
    c1->compteurhitleft = 0;
    c1->compteurhitright = 0;
    c1->jumpSoundPlayed = 0;
    c1->walkSoundPlayedleft = 0;
    c1->walkSoundPlayedright = 0;
    c1->canThrow = 1;
    c1->throwSoundPlayed = 0;
    c1->isSprinting = 0;

    c1->hitSound = Mix_LoadWAV("hit.wav");
    c1->jumpsound = Mix_LoadWAV("jump.wav");
    c1->runsound = Mix_LoadWAV("run.wav");
    c1->throwSound = Mix_LoadWAV("throw.wav");
    c1->throwSound1 = Mix_LoadWAV("throw2.wav");
    
    for (int i = 0; i < THROW_ANTICIP_FRAMES; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/projectileleft/phase1/proj%d.png", i+1);
        c1->throwAnticipLeft[i] = IMG_Load(filename);
    }
    for (int i = 0; i < THROW_EXEC_FRAMES; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/projectileleft/phase2/proj%d.png", i+1);
        c1->throwExecLeft[i] = IMG_Load(filename);
    }
    for (int i = 0; i < THROW_RECOV_FRAMES; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/projectileleft/phase3/proj%d.png", i+1);
        c1->throwRecovLeft[i] = IMG_Load(filename);
    }
    for (int i = 0; i < PROJ_FRAMES; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/projectileleft/projectile/proj%d.png", i+1);
        c1->projFramesLeft[i] = IMG_Load(filename);
    }

    for (int i = 0; i < THROW_ANTICIP_FRAMES; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/projectileright/phase1/proj%d.png", i+1);
        c1->throwAnticipRight[i] = IMG_Load(filename);
    }
    for (int i = 0; i < THROW_EXEC_FRAMES; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/projectileright/phase2/proj%d.png", i+1);
        c1->throwExecRight[i] = IMG_Load(filename);
    }
    for (int i = 0; i < THROW_RECOV_FRAMES; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/projectileright/phase3/proj%d.png", i+1);
        c1->throwRecovRight[i] = IMG_Load(filename);
    }
    for (int i = 0; i < PROJ_FRAMES; ++i) {
        sprintf(filename, "/home/king/Documents/main_charather 3/projectileright/projectile/proj%d.png", i+1);
        c1->projFramesRight[i] = IMG_Load(filename);
    }

    c1->isThrowingLeft = 0;
    c1->isThrowingRight = 0;
    c1->throwPhase = 0;
    c1->throwFrame = 0;
    c1->throwTimer = 0;
    c1->projActive = 0;
    c1->projFrame = 0;
    c1->projTimer = 0;
    c1->projDir = 0;

    init_health_system(c1);
    init_animal(&c1->pet, c1);
}

void affichercharthere1(SDL_Surface *screen, SDL_Surface *background_principale, charathere1 *c1) {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_BlitSurface(background_principale, NULL, screen, NULL);

    render_health(screen, c1);

    if (c1->isDead && c1->deathAnimPlaying) {
        render_death_animation(screen, c1);
    } 
    else if (!c1->isDead) {
        if (c1->isJumping) {
            SDL_Rect jumpPos = c1->positionimage;
            
            if (c1->ismovingL) {
                SDL_BlitSurface(c1->jumpleftImages[c1->frameJump], NULL, screen, &jumpPos);
            } else if (c1->ismovingR) {
                SDL_BlitSurface(c1->jumprightImages[c1->frameJump], NULL, screen, &jumpPos);
            } else {
                SDL_BlitSurface(c1->jumprightImages[c1->frameJump], NULL, screen, &jumpPos);
            }
        } else if (c1->ismoving) {
            if (c1->ismovingL)
                SDL_BlitSurface(c1->runleftImages[c1->framerunleft], NULL, screen, &c1->positionimage);
            else if (c1->ismovingR)
                SDL_BlitSurface(c1->runrightImages[c1->framerunright], NULL, screen, &c1->positionimage);
            if (c1->isSprinting) {
                SDL_Delay(10);
            } else {
                SDL_Delay(20);
            }
        } else if (c1->isHittingLeft) {
            SDL_Rect adjust = c1->positionimage;
            adjust.x += 60;
            SDL_BlitSurface(c1->hitLeftImages[c1->frameHitLeft], NULL, screen, &adjust);
            SDL_Delay(20);
        } else if (c1->isHittingRight) {
            SDL_Rect adjust = c1->positionimage;
            SDL_BlitSurface(c1->hitRightImages[c1->frameHitRight], NULL, screen, &adjust);
            SDL_Delay(20);
        } 
        else if (c1->isThrowingLeft) {
            SDL_Rect dst = c1->positionimage;
            switch (c1->throwPhase) {
                case 0:
                    SDL_BlitSurface(c1->throwAnticipLeft[c1->throwFrame], NULL, screen, &dst);
                    break;
                case 1:
                    SDL_BlitSurface(c1->throwExecLeft[c1->throwFrame], NULL, screen, &dst);
                    break;
                case 2:
                    SDL_BlitSurface(c1->throwRecovLeft[c1->throwFrame], NULL, screen, &dst);
                    break;
            }
            SDL_Delay(20);
        }
        else if (c1->isThrowingRight) {
            SDL_Rect dst = c1->positionimage;
            switch (c1->throwPhase) {
                case 0:
                    SDL_BlitSurface(c1->throwAnticipRight[c1->throwFrame], NULL, screen, &dst);
                    break;
                case 1:
                    SDL_BlitSurface(c1->throwExecRight[c1->throwFrame], NULL, screen, &dst);
                    break;
                case 2:
                    SDL_BlitSurface(c1->throwRecovRight[c1->throwFrame], NULL, screen, &dst);
                    break;
            }
            SDL_Delay(20);
        }
        
        if (c1->projActive) {
            SDL_Rect dst = { c1->projX, c1->projY, 290, 25 };
            if (c1->projDir < 0) {
                SDL_BlitSurface(c1->projFramesLeft[c1->projFrame], NULL, screen, &dst);
            } else {
                SDL_BlitSurface(c1->projFramesRight[c1->projFrame], NULL, screen, &dst);
            }
        }
        
        if (!c1->isJumping && !c1->ismoving && !c1->isHittingLeft && !c1->isHittingRight && 
            !c1->isThrowingLeft && !c1->isThrowingRight) {
            if (c1->ismovingL) {
                SDL_BlitSurface(c1->idleleftImages[c1->frameidleleft], NULL, screen, &c1->positionimage);
                c1->frameidleleft = (c1->frameidleleft + 1) % 5;
            } else if (c1->ismovingR) {
                SDL_BlitSurface(c1->idlerightImages[c1->frameidleright], NULL, screen, &c1->positionimage);
                c1->frameidleright = (c1->frameidleright + 1) % 5;
            }
            SDL_Delay(50);
        }
        render_animal(screen, &c1->pet);
    }

    SDL_Flip(screen);
}

void collisionavecclavier(charathere1 *c1) {
    Uint8 *keys = SDL_GetKeyState(NULL);
    
    if (c1->isDead) return;
    
    c1->ismoving = 0;
    c1->isHittingLeft = 0;
    c1->isHittingRight = 0;
    
    c1->isSprinting = keys[SDLK_q];
    
    if (keys[SDLK_LEFT]) {
        int moveAmount = c1->isSprinting ? 30 : 20;
        c1->positionimage.x -= moveAmount;
        
        c1->ismoving = 1;
        c1->ismovingL = 1;
        c1->ismovingR = 0;
        c1->framerunleft = (c1->framerunleft + 1) % 8;
        
        if (c1->walkSoundPlayedleft == 0) {
            Mix_PlayChannel(-1, c1->runsound, 0);
            Mix_VolumeChunk(c1->runsound, c1->isSprinting ? 192 : 128); 
            c1->walkSoundPlayedleft = 1;
        }
        else {
            c1->walkSoundPlayedleft = 0;
        }
    } 
    
    if (keys[SDLK_RIGHT]) {
        int moveAmount = c1->isSprinting ? 30 : 20;
        c1->positionimage.x += moveAmount;
        
        c1->ismoving = 1;
        c1->ismovingR = 1;
        c1->ismovingL = 0;
        c1->framerunright = (c1->framerunright + 1) % 8;
        
        if (c1->walkSoundPlayedright == 0) {
            Mix_PlayChannel(-1, c1->runsound, 0);
            Mix_VolumeChunk(c1->runsound, c1->isSprinting ? 192 : 128);
            c1->walkSoundPlayedright = 1;
        }
        else {
            c1->walkSoundPlayedright = 0;
        }
    } 

    if (keys[SDLK_a] && c1->ismovingL) {
        c1->isHittingLeft = 1;
        c1->frameHitLeft = (c1->frameHitLeft + 1) % 7;
        c1->compteurhitleft = (c1->compteurhitleft + 1) % 7;
        if (c1->compteurhitleft == 5) {
            Mix_PlayChannel(-1, c1->hitSound, 0);
            Mix_VolumeChunk(c1->runsound, 128); 
            c1->oldwav = 1;
        }
    } else if (keys[SDLK_z] && c1->ismovingR) {
        c1->isHittingRight = 1;
        c1->frameHitRight = (c1->frameHitRight + 1) % 7;
        c1->compteurhitright = (c1->compteurhitright + 1) % 7;
        if (c1->compteurhitright == 5) {
            Mix_PlayChannel(-1, c1->hitSound, 0);
            c1->oldwav = 1; 
        }
    }

    if (!keys[SDLK_a] && !keys[SDLK_z]) {
        c1->oldwav = 0;
        c1->compteurhitleft = 0;
        c1->compteurhitright = 0;
    }

    if (keys[SDLK_SPACE] && c1->onGround) {
        c1->isJumping = 1;
        c1->yVelocity = c1->jumpHeight;
        c1->onGround = 0;
        c1->frameJump = 0;
        c1->jumpAnimCounter = 0;
        c1->jumpPhase = 1;
    }

    if (keys[SDLK_f] && c1->canThrow && !c1->isThrowingLeft && !c1->isThrowingRight) {
        c1->isThrowingLeft = 1;
        c1->canThrow = 0;
        c1->throwPhase = 0;
        c1->throwFrame = 0;
        c1->throwTimer = SDL_GetTicks();
        c1->throwSoundPlayed = 0;
    }
    else if (keys[SDLK_g] && c1->canThrow && !c1->isThrowingLeft && !c1->isThrowingRight) {
        c1->isThrowingRight = 1;
        c1->canThrow = 0;
        c1->throwPhase = 0;
        c1->throwFrame = 0;
        c1->throwTimer = SDL_GetTicks();
        c1->throwSoundPlayed = 0;
    }
    
    if (!keys[SDLK_f] && !keys[SDLK_g]) {
        c1->canThrow = 1;
    }
}

void miseajourcharthere(charathere1 *c1) {
    if (c1->isDead) return;
    
    Uint8 *keys = SDL_GetKeyState(NULL);
    
    if (c1->isJumping) {
        if (!c1->jumpSoundPlayed) {
            Mix_VolumeChunk(c1->jumpsound, 128);
            Mix_PlayChannel(-1, c1->jumpsound, 0);
            c1->jumpSoundPlayed = 1;
        }

        c1->positionimage.y += c1->yVelocity;
        c1->yVelocity += c1->gravity;
        c1->jumpAnimCounter++;

        if (c1->jumpPhase == 1) {
            c1->frameJump = 0;
            if (c1->jumpAnimCounter >= 5) {
                c1->jumpPhase = 2;
                c1->jumpAnimCounter = 0;
            }
        } else if (c1->jumpPhase == 2) {
            c1->frameJump = (c1->jumpAnimCounter / 5) % 3 + 1;
            if (c1->yVelocity >= 0) {
                c1->jumpPhase = 3;
                c1->jumpAnimCounter = 0;
            }
        } else if (c1->jumpPhase == 3) {
            c1->frameJump = (c1->jumpAnimCounter / 5) + 5;
            if (c1->positionimage.y >= 620) {
                c1->positionimage.y = 620;
                c1->isJumping = 0;
                c1->yVelocity = 0;
                c1->onGround = 1;
                c1->jumpPhase = 0;
            }
        }

        if (c1->frameJump >= 6)
            c1->frameJump = 5;
            
        if (!keys[SDLK_SPACE] && c1->onGround) {
            c1->jumpSoundPlayed = 0;
        }
    }

    Uint32 now = SDL_GetTicks();

    if (c1->isThrowingLeft) {
        if (now - c1->throwTimer > 80) {
            c1->throwTimer = now;
            c1->throwFrame++;
        }

        switch (c1->throwPhase) {
            case 0:
                if (c1->throwFrame >= THROW_ANTICIP_FRAMES) {
                    c1->throwPhase = 1;
                    c1->throwFrame = 0;
                }
                break;
            case 1: 
                if (c1->throwFrame == 0) {
                    c1->projActive = 1;
                    c1->projDir = -1;
                    c1->projX = c1->positionimage.x - 20;
                    c1->projY = c1->positionimage.y + 40;
                    c1->projFrame = 0;
                    c1->projTimer = now;
                    if (!c1->throwSoundPlayed) {
                        Mix_PlayChannel(-1, c1->throwSound1, 0);
                        c1->throwSoundPlayed = 1;
                    }
                }
                if (c1->throwFrame >= THROW_EXEC_FRAMES) {
                    c1->throwPhase = 2;
                    c1->throwFrame = 0;
                }
                break;
            case 2:
                if (c1->throwFrame >= THROW_RECOV_FRAMES) {
                    c1->isThrowingLeft = 0;
                    c1->throwPhase = 0;
                }
                break;
        }
    }
    else if (c1->isThrowingRight) {
        if (now - c1->throwTimer > 80) {
            c1->throwTimer = now;
            c1->throwFrame++;
        }

        switch (c1->throwPhase) {
            case 0:
                if (c1->throwFrame >= THROW_ANTICIP_FRAMES) {
                    c1->throwPhase = 1;
                    c1->throwFrame = 0;
                }
                break;
            case 1:
                if (c1->throwFrame == 0) {
                    c1->projActive = 1;
                    c1->projDir = 1;
                    c1->projX = c1->positionimage.x + 50;
                    c1->projY = c1->positionimage.y + 40;
                    c1->projFrame = 0;
                    c1->projTimer = now;
                    if (!c1->throwSoundPlayed) {
                        Mix_PlayChannel(-1, c1->throwSound, 0);
                        c1->throwSoundPlayed = 1;
                    }
                }
                if (c1->throwFrame >= THROW_EXEC_FRAMES) {
                    c1->throwPhase = 2;
                    c1->throwFrame = 0;
                }
                break;
            case 2:
                if (c1->throwFrame >= THROW_RECOV_FRAMES) {
                    c1->isThrowingRight = 0;
                    c1->throwPhase = 0;
                }
                break;
        }
    }

    if (c1->projActive) {
        if (now - c1->projTimer > 100) {
            c1->projTimer = now;
            c1->projFrame = (c1->projFrame + 1) % PROJ_FRAMES;
        }
        c1->projX += c1->projDir * 60;

        if (c1->projX < 0 || c1->projX > 1920) {
            c1->projActive = 0;
        }
    }
    
    update_animal(&c1->pet, c1);
}

void libererCharathere(charathere1 *c1, SDL_Surface *background) {
    if (background != NULL)
        SDL_FreeSurface(background);

    for (int i = 0; i < c1->count0; ++i) {
        SDL_FreeSurface(c1->idleleftImages[i]);
        SDL_FreeSurface(c1->idlerightImages[i]);
    }
    for (int i = 0; i < c1->count1; ++i) {
        SDL_FreeSurface(c1->runleftImages[i]);
        SDL_FreeSurface(c1->runrightImages[i]);
    }
    for (int i = 0; i < c1->count2; ++i) {
        SDL_FreeSurface(c1->hitLeftImages[i]);
        SDL_FreeSurface(c1->hitRightImages[i]);
    }
    for (int i = 0; i < c1->count3; ++i) {
        SDL_FreeSurface(c1->jumpleftImages[i]);
        SDL_FreeSurface(c1->jumprightImages[i]);
    }

    for (int i = 0; i < THROW_ANTICIP_FRAMES; ++i) {
        if (c1->throwAnticipLeft[i]) SDL_FreeSurface(c1->throwAnticipLeft[i]);
    }
    for (int i = 0; i < THROW_EXEC_FRAMES; ++i) {
        if (c1->throwExecLeft[i]) SDL_FreeSurface(c1->throwExecLeft[i]);
    }
    for (int i = 0; i < THROW_RECOV_FRAMES; ++i) {
        if (c1->throwRecovLeft[i]) SDL_FreeSurface(c1->throwRecovLeft[i]);
    }
    for (int i = 0; i < PROJ_FRAMES; ++i) {
        if (c1->projFramesLeft[i]) SDL_FreeSurface(c1->projFramesLeft[i]);
    }

    for (int i = 0; i < THROW_ANTICIP_FRAMES; ++i) {
        if (c1->throwAnticipRight[i]) SDL_FreeSurface(c1->throwAnticipRight[i]);
    }
    for (int i = 0; i < THROW_EXEC_FRAMES; ++i) {
        if (c1->throwExecRight[i]) SDL_FreeSurface(c1->throwExecRight[i]);
    }
    for (int i = 0; i < THROW_RECOV_FRAMES; ++i) {
        if (c1->throwRecovRight[i]) SDL_FreeSurface(c1->throwRecovRight[i]);
    }
    for (int i = 0; i < PROJ_FRAMES; ++i) {
        if (c1->projFramesRight[i]) SDL_FreeSurface(c1->projFramesRight[i]);
    }
    for (int i = 0; i < 3; i++) {
        if (c1->healthImages[i]) SDL_FreeSurface(c1->healthImages[i]);
    }
    for (int i = 0; i < MAX_DEATH_FRAMES; i++) {
        if (c1->deathAnimation[i]) SDL_FreeSurface(c1->deathAnimation[i]);
    }
    for (int i = 0; i < ANIMAL_FRAMES; i++) {
        if (c1->pet.idleLeft[i]) SDL_FreeSurface(c1->pet.idleLeft[i]);
        if (c1->pet.idleRight[i]) SDL_FreeSurface(c1->pet.idleRight[i]);
        if (c1->pet.moveLeft[i]) SDL_FreeSurface(c1->pet.moveLeft[i]);
        if (c1->pet.moveRight[i]) SDL_FreeSurface(c1->pet.moveRight[i]);
    }

    if (c1->hitSound) Mix_FreeChunk(c1->hitSound);
    if (c1->jumpsound) Mix_FreeChunk(c1->jumpsound);
    if (c1->runsound) Mix_FreeChunk(c1->runsound);
    if (c1->throwSound) Mix_FreeChunk(c1->throwSound);
    if (c1->throwSound1) Mix_FreeChunk(c1->throwSound1);

    IMG_Quit();
    SDL_Quit();
}
