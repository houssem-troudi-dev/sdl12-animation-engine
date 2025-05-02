#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include "charather1.h"

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! IMG_Error: %s\n", IMG_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Surface *screen = SDL_SetVideoMode(1920, 1080, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        printf("Unable to set video mode! SDL_Error: %s\n", SDL_GetError());
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Surface *background_principale = IMG_Load("background_principale.png");
    if (background_principale == NULL) {
        printf("Error loading background image: %s\n", IMG_GetError());
        IMG_Quit();
        SDL_Quit();
        return -1;
    }


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        printf("Failed to initialize SDL_mixer: %s\n", Mix_GetError());
        SDL_Quit();
        return 1;
    }

    Mix_Music *music = Mix_LoadMUS("hollowknight.mp3");
    if (music == NULL) {
        printf("Failed to load music: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(64);

    charathere1 c1;
    init_charather(&c1);
    
    SDL_Event event;
    int quitter = 0;
    
    while (!quitter) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quitter = 1;
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    quitter = 1;
                else if (event.key.keysym.sym == SDLK_u && !c1.isDead)
                    update_health(&c1);
            }
        }

        if (!c1.isDead || c1.deathAnimPlaying) {
            collisionavecclavier(&c1);
            miseajourcharthere(&c1);
            affichercharthere1(screen, background_principale, &c1);
        }
        
        SDL_Delay(30);
    }

    libererCharathere(&c1, background_principale);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    
    return 0;
}
