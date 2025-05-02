#include "sousmenu_joueur.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

int main(int argc, char *argv[]) {
    // Initialisation
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("Erreur SDL : %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        printf("Erreur TTF : %s\n", TTF_GetError());
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Erreur IMG_Init : %s\n", IMG_GetError());
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Erreur Mix_OpenAudio : %s\n", Mix_GetError());
        return 1;
    }

    SDL_Surface *Fenetre = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    if (!Fenetre) {
        printf("Erreur création fenêtre : %s\n", SDL_GetError());
        return 1;
    }
    
    Menu menu;
    init_menu_joueur(&menu);

    int quitter = 0;
    SDL_Event event;
    while (!quitter) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || 
                (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                quitter = 1;
            }}
            afficher_menu_joueur(&menu,Fenetre,event);

       

 
    }
  liberer_menu_joueur(&menu);
  Mix_CloseAudio();           
  Mix_Quit();
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
    return 0;
}
