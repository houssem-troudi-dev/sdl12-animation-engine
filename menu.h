#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct 
{


SDL_Surface *background_principale;

SDL_Surface *jouer_btn[2];
SDL_Rect posbutton_jouer;

SDL_Surface *option_btn[2];
SDL_Rect posbutton_option;

SDL_Surface *meilleur_btn[2];
SDL_Rect posbutton_meilleur;

SDL_Surface *histoire_btn[2];
SDL_Rect posbutton_histoire;

SDL_Surface *quit_btn[2];
SDL_Rect posbutton_quit;

int btn_select;




Mix_Music *music;
Mix_Chunk *sonclick;
SDL_Surface *title;
TTF_Font *font;
SDL_Color fontColor;
SDL_Rect postext;

SDL_Surface *logo;
SDL_Rect logo_pos;


SDL_Rect gifPosition;
SDL_Surface *images[100]; 
int count;
int frame;
int FRAME_DELAY;
}Menu;


void init_menu(Menu *menu);


void afficher_menu(Menu *m,SDL_Surface *Fenetre);

int colision_avec_souris(SDL_Rect pos_btn);

void misajour_menu(Menu *m);

void handle_menu_events(SDL_Event event, int *quitter, int *indice_ecran, Menu *menu);









#endif
