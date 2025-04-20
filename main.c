#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"menu.h"
int main(int argc, char* argv[]){
//***************************************
SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO);
TTF_Init();
IMG_Init(IMG_INIT_PNG);
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
if (SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO) < 0) {
        printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
}
//****************************************
SDL_Surface *Fenetre=NULL;
Fenetre=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
  if (Fenetre == NULL) {
    printf("Erreur création fenêtre : %s\n", SDL_GetError());
     return 1;
}




Menu menu;
init_menu(&menu);
Mix_PlayMusic(menu.music,-1);
int indice_ecran=0;
int quitter=0;
SDL_Event event;
menu.frame = 0;
menu.FRAME_DELAY=50;
//****************************************
while(quitter==0)
{ 


switch(indice_ecran)
{
 case 0:
         //Menu principale
          afficher_menu(&menu,Fenetre);
          SDL_Flip(Fenetre);
          handle_menu_events(event, &quitter, &indice_ecran, &menu);
          misajour_menu(&menu);
            break;
case 1://sous menu joueur
        
    SDL_FillRect(Fenetre, NULL, SDL_MapRGB(Fenetre->format, 0, 0, 0)); 
    SDL_Flip(Fenetre);

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quitter = 1;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_ESCAPE)
                   indice_ecran=0;
            default:
                break;
        }
    }
    break; 
case 2://sous menu
          while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quitter = 1;
                break;
            default:
                break;
        }
    }
    break; 
case 3://sous menu
          while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quitter = 1;
                break;
            default:
                break;
        }
    }
    break; 
case 4://sous menu
          while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quitter = 1;
                break;
            default:
                break;
        }
    }
    break; 
 default:
     break;






}
















}






















SDL_FreeSurface(Fenetre);
SDL_Quit();


return 0;
}
