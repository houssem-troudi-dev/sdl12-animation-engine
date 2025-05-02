#ifndef SOUSMENU_JOUEUR_H
#define SOUSMENU_JOUEUR_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define MAX_NAME_LENGTH 13

typedef struct {
    SDL_Surface *background_principale;
    TTF_Font *font;
    SDL_Surface *singlebuttons[2];
    SDL_Surface *multibuttons[2];
    SDL_Surface *back[2];
    SDL_Surface *c1[2];
    SDL_Surface *c2[2];
    SDL_Surface *c3[2];
    SDL_Surface *c4[2];
    SDL_Surface *input[2];
    SDL_Surface *input1[2];

    SDL_Surface *valider[2];
    SDL_Surface *cancel[2]; 
    SDL_Rect possingle;
    SDL_Rect posmulti;
    SDL_Rect posback;
    SDL_Rect posc1;
    SDL_Rect posc2;
    SDL_Rect posc3;
    SDL_Rect posc4;
    SDL_Rect posinput;
    SDL_Rect posinput1;
    SDL_Rect posvalider;  
    SDL_Rect poscancel;   
      SDL_Surface *j1;
      SDL_Surface *j2;
      SDL_Rect  posj1;
      SDL_Rect  posj2;
      SDL_Surface *j11;
      SDL_Surface *j22;
      SDL_Rect  posj11;
      SDL_Rect  posj22;
      int j11_index;
      SDL_Rect j11_positions[4];
      int j22_index;
      SDL_Rect j22_positions[4];
    
    int indiceEcranjoueur;
    int soundPlayed;
    int btn_single_select;
    int btn_multi_select;
    int btn_back_select;
    int btn_c1_select;
    int btn_c2_select;
    int btn_c3_select;
    int btn_c4_select;
    int btn_input_select;
    int btn_input1_select;
    int btn_valider_select; 
    int btn_cancel_select;   
    Mix_Chunk *clickSound;
    char selected_character[MAX_NAME_LENGTH];
    char selected_input[MAX_NAME_LENGTH];

} Menu;

void init_menu_joueur(Menu *menu);
void afficher_menu_joueur(Menu *menu, SDL_Surface *Fenetre, SDL_Event event);
int colision_avec_souris(SDL_Rect pos_btn);
void liberer_menu_joueur(Menu *menu);
void save_selections(const Menu *menu);

#endif


