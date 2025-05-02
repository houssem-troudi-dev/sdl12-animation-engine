#include "charather1.h"
#include <stdio.h>










void init_charather(charathere1 *c1) {
    c1->count0 = 0;
    c1->count1 = 0;
    c1->count2 = 0;
    c1->count3 = 0; 
    c1->positionimage.x=500;
    c1->positionimage.y=620;
    char filename[256];


// Idle Left & Right
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
// run Left & Right
for (int i = 0; i < 8; ++i) {
    sprintf(filename, "/home/king/Documents/main_charather 3/runleft/run%d.png", i + 1);
    c1->runleftImages[c1->count1] = IMG_Load(filename);
    if (c1->runleftImages[c1->count1] != NULL) {
        sprintf(filename, "/home/king/Documents/main_charather 3/runright/run%d.png", i + 1);
        c1->runrightImages[c1->count1] = IMG_Load(filename);
        if (c1->runrightImages[c1->count1] != NULL) {
            c1->count1++; 
        } else {
            fprintf(stderr, "Error: Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
        }
    } else {
        fprintf(stderr, "Error: Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
    }
}
// hit Left & Right
for (int i = 0; i < 7; ++i) {
    sprintf(filename, "/home/king/Documents/main_charather 3/hitleft/hit%d.png", i + 1);
    c1->hitLeftImages[c1->count2] = IMG_Load(filename);
    if (c1->hitLeftImages[c1->count2] != NULL) {
        sprintf(filename, "/home/king/Documents/main_charather 3/hitright/hit%d.png", i + 1);
        c1->hitRightImages[c1->count2] = IMG_Load(filename);
        if (c1->hitRightImages[c1->count2] != NULL) {
            c1->count2++;
        } else {
            fprintf(stderr, "Error: Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
        }
    } else {
        fprintf(stderr, "Error: Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
    }
}

// Jump Left & Right
for (int i = 0; i < 7; ++i){
    sprintf(filename, "/home/king/Documents/main_charather 3/jumpleft/jump%d.png", i + 1);
    c1->jumpleftImages[c1->count3] = IMG_Load(filename);
    if (c1->jumpleftImages[c1->count3] != NULL) {
        sprintf(filename, "/home/king/Documents/main_charather 3/jumpright/jump%d.png", i + 1);
        c1->jumprightImages[c1->count3] = IMG_Load(filename);
        if (c1->jumprightImages[c1->count3] != NULL) {
            c1->count3++;
        } else {
            fprintf(stderr, "Error: Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
        }
    } else {
        fprintf(stderr, "Error: Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
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

     c1->frameidleleft = 0, c1->frameidleright = 0, c1->framerunleft = 0, c1->framerunright= 0;
     c1->frameHitLeft = 0, c1->frameHitRight = 0;
     c1->ismoving = 0 , c1->ismovingR = 1, c1->ismovingL = 1;
     c1->isHittingLeft = 0, c1->isHittingRight = 0;
     c1->oldwav=0;
     c1->compteurhitleft=0;
     c1->compteurhitright=0;
     c1->jumpSoundPlayed=0;
     c1->walkSoundPlayedleft=0;
     c1->walkSoundPlayedright=0;
     c1->hitSound= Mix_LoadWAV("hit.wav");
     if (c1->hitSound == NULL) {
        printf("Failed to load hit sound: %s\n", Mix_GetError());
        Mix_FreeChunk(c1->hitSound);
        Mix_CloseAudio();
        SDL_Quit();
        return ;
    }
    c1->jumpsound= Mix_LoadWAV("jump.wav");
     if (c1->jumpsound == NULL) {
        printf("Failed to load hit sound: %s\n", Mix_GetError());
        Mix_FreeChunk(c1->jumpsound);
        Mix_CloseAudio();
        SDL_Quit();
        return ;
    }
    c1->runsound= Mix_LoadWAV("run.wav");
     if (c1->runsound == NULL) {
        printf("Failed to load run sound: %s\n", Mix_GetError());
        Mix_FreeChunk(c1->runsound);
        Mix_CloseAudio();
        SDL_Quit();
        return ;
    }

}

void affichercharthere1(SDL_Surface *screen, SDL_Surface *background_principale, charathere1 *c1) {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_BlitSurface(background_principale, NULL, screen, NULL);

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
        SDL_Delay(20);
    } else if (c1->isHittingLeft) {
        SDL_Rect adjust = c1->positionimage;
        adjust.x += 60;
        SDL_BlitSurface(c1->hitLeftImages[c1->frameHitLeft], NULL, screen, &adjust);
        SDL_Delay(40);
    } else if (c1->isHittingRight) {
        SDL_Rect adjust = c1->positionimage;
        SDL_BlitSurface(c1->hitRightImages[c1->frameHitRight], NULL, screen, &adjust);
        SDL_Delay(40);
    } else {
        if (c1->ismovingL) {
            SDL_Rect adjust = c1->positionimage;
            SDL_BlitSurface(c1->idleleftImages[c1->frameidleleft], NULL, screen, &c1->positionimage);
            c1->frameidleleft = (c1->frameidleleft + 1) % 5;
        } else if (c1->ismovingR) {
            SDL_BlitSurface(c1->idlerightImages[c1->frameidleright], NULL, screen, &c1->positionimage);
            c1->frameidleright = (c1->frameidleright + 1) % 5;
        }
        SDL_Delay(90);
    }

    SDL_Flip(screen);
}

void collisionavecclavier(charathere1 *c1) {
    Uint8 *keys = SDL_GetKeyState(NULL);

    c1->ismoving = 0;
    c1->isHittingLeft = 0;
    c1->isHittingRight = 0;
    
    if (keys[SDLK_LEFT]) {
        c1->positionimage.x -= 20;
        c1->ismoving = 1;
        c1->ismovingL = 1;
        c1->ismovingR = 0;
        c1->framerunleft = (c1->framerunleft + 1) % 8;
        if (c1->walkSoundPlayedleft == 0) {
            Mix_PlayChannel(-1, c1->runsound, 0);
            Mix_VolumeChunk(c1->runsound, 128); 
            c1->walkSoundPlayedleft = 1; 
        }
     else {
        c1->walkSoundPlayedleft = 0; 
        
    }
    } else if (keys[SDLK_RIGHT]) {
        c1->positionimage.x += 20;
        c1->ismoving = 1;
        c1->ismovingR = 1;
        c1->ismovingL = 0;
        c1->framerunright = (c1->framerunright + 1) % 8;
        if (c1->walkSoundPlayedright == 0) {
            Mix_PlayChannel(-1, c1->runsound, 0);
            Mix_VolumeChunk(c1->runsound, 128); 
            c1->walkSoundPlayedright = 1;}
        else {
        c1->walkSoundPlayedright = 0; 
    }
    }
    

    if (keys[SDLK_a] && c1->ismovingL) {
        c1->isHittingLeft = 1;
        c1->frameHitLeft = (c1->frameHitLeft + 1) % 7;
        c1->compteurhitleft+=1;
        c1->compteurhitleft=c1->compteurhitleft % 7;
        if ( c1->compteurhitleft == 5) {
            Mix_PlayChannel(-1, c1->hitSound, 0);
            Mix_VolumeChunk(c1->runsound, 128); 
            c1->oldwav = 1;
        }
    } else if (keys[SDLK_z] && c1->ismovingR) {
        c1->isHittingRight = 1;
        c1->frameHitRight = (c1->frameHitRight + 1) % 7;
        c1->compteurhitright+=1;
        c1->compteurhitright=c1->compteurhitright % 7;
       if ( c1->compteurhitright == 5) {
                Mix_PlayChannel(-1, c1->hitSound, 0);
                c1->oldwav = 1; 
            }
    }

    if (!keys[SDLK_a] && !keys[SDLK_z]) {
        c1->oldwav = 0;
        c1->compteurhitleft=0;
        c1->compteurhitright=0;
    }

    if (keys[SDLK_SPACE] && c1->onGround) {
        c1->isJumping = 1;
        c1->yVelocity = c1->jumpHeight;
        c1->onGround = 0;
        c1->frameJump = 0;
        c1->jumpAnimCounter = 0;
        c1->jumpPhase = 1;
    }
}

void miseajourcharthere(charathere1 *c1) {
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
            
    if (!keys[SDLK_SPACE] &&c1->onGround) {
        c1->jumpSoundPlayed = 0;
        

    }
    }
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

    IMG_Quit();
    SDL_Quit();
}

























