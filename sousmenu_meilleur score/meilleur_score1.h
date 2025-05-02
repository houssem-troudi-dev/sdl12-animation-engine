#ifndef MEILLEUR_SCORE1_H
#define MEILLEUR_SCORE1_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define MAX_NAME_LENGTH 13

typedef struct {
    SDL_Surface *background_principale;
    SDL_Surface *background_secondaire;
    SDL_Rect posbgs1;
    SDL_Surface *title2;
    SDL_Rect  postitle2;
    SDL_Surface *star[3];
    SDL_Rect posstar0;
    SDL_Rect posstar1;
    SDL_Rect posstar2;
    SDL_Surface *next[2];
    SDL_Rect posnext;
    SDL_Surface *taper[2];
    SDL_Rect postaper;
    SDL_Surface *typecursor;
    SDL_Rect postypecursor;
    Uint32 lastBlinkTime;
    int cursorVisible;
    TTF_Font *font;
    TTF_Font *font1;
    SDL_Color fontColor;
    SDL_Surface *title;
    SDL_Surface *note;
    SDL_Rect postext;
    SDL_Rect  posnote;
    int btn_next_select;
    int btn_taper_select;
    int typingActive;
    int nameLength;
    char name[MAX_NAME_LENGTH];
    SDL_Surface *textTexture;
    Mix_Chunk *clickSound;
    int soundPlayed;
    int indiceEcranMeilleur;
    int score;
    int bestScore;
    char bestName[MAX_NAME_LENGTH] ;
    SDL_Surface *save[2];
    SDL_Rect possave;
    int btn_save_select;
    SDL_Rect gifPosition;
    SDL_Surface *images[10];
    int count;
    int frame;
    int count1;
    SDL_Surface *images1[10];
    SDL_Rect gifPosition1;
     int frame1;
     Mix_Music *music;
} Menu;

void init_menu_score(Menu *menu);
void handle_text_input(Menu *menu, SDL_Event event);
void afficher_nom_utilisateur(Menu *menu, SDL_Surface *Fenetre);
void afficher_menu(Menu *menu, SDL_Surface *Fenetre, SDL_Event event);
int colision_avec_souris(SDL_Rect pos_btn);
void liberer_menu_score(Menu *menu);
void sauvegarder_nom_utilisateur(const char *nom, const char *fichier);
#endif
