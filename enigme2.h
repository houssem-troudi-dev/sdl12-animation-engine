#ifndef ENIGME2_H
#define ENIGME2_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct {
    SDL_Surface *bkg;
    SDL_Surface *puzzle[27];
    SDL_Rect pos_btn_puzzle[27];
    int piece_placee[27];
    SDL_Surface *timer[93];
    SDL_Rect pos_timer;
    int compteur;
    int temps_start_jouer;
    SDL_Surface *win[239];
    SDL_Rect pos_win;
    SDL_Surface *loose[248];
    SDL_Rect pos_loose;
    SDL_Surface *wa9t[323];
    SDL_Rect pos_wa9t;
    SDL_Surface *wa9t2[323];
    SDL_Rect pos_wa9t2;
    SDL_Surface *gamerule;
    SDL_Rect pos_gamerule;
    int fin_jeu;
    int jouer_gagner;
    int afficher_loose;
    TTF_Font *font;
    SDL_Surface *surfaceTexte;
    SDL_Rect pos_btn_text;
    int loose_i;
    int win_i;
    SDL_Rect p12_init, p25_init, p26_init;  // Ajoutez ces membres
    int saved;      
    int gamerule_start_time;
    int show_gamerule;
} Enigme2;

typedef struct {
    SDL_Surface *bkg;
    SDL_Surface *puzzle2[27];
    SDL_Rect pos_btn_puzzle2[27];
    int piece_placee[27];
    SDL_Surface *timer[93];
    SDL_Rect pos_timer;
    int compteur;
    int temps_start_jouer;
    SDL_Surface *win[239];
    SDL_Rect pos_win;
    SDL_Surface *loose[248];
    SDL_Rect pos_loose;
    SDL_Surface *wa9t[323];
    SDL_Rect pos_wa9t;
    SDL_Surface *wa9t2[323];
    SDL_Rect pos_wa9t2;
    SDL_Surface *gamerule;
    SDL_Rect pos_gamerule;
    int fin_jeu;
    int jouer_gagner;
    int afficher_loose;
    TTF_Font *font;
    SDL_Surface *surfaceTexte;
    SDL_Rect pos_btn_text;
    int loose_i;
    int win_i;
    SDL_Rect p12_init, p25_init, p26_init;  // Ajoutez ces membres
    int saved;      
    int gamerule_start_time;
    int show_gamerule;
} Enigme2_2;

typedef struct {
    SDL_Surface *bkg;
    SDL_Surface *puzzle3[27];
    SDL_Rect pos_btn_puzzle3[27];
    int piece_placee[27];
    SDL_Surface *timer[93];
    SDL_Rect pos_timer;
    int compteur;
    int temps_start_jouer;
    SDL_Surface *win[239];
    SDL_Rect pos_win;
    SDL_Surface *loose[248];
    SDL_Rect pos_loose;
    SDL_Surface *wa9t[323];
    SDL_Rect pos_wa9t;
    SDL_Surface *wa9t2[323];
    SDL_Rect pos_wa9t2;
    SDL_Surface *gamerule;
    SDL_Rect pos_gamerule;
    int fin_jeu;
    int jouer_gagner;
    int afficher_loose;
    TTF_Font *font;
    SDL_Surface *surfaceTexte;
    SDL_Rect pos_btn_text;
    int loose_i;
    int win_i;
    SDL_Rect p12_init, p25_init, p26_init;  // Ajoutez ces membres
    int saved;      
    int gamerule_start_time;
    SDL_Event event;
    int show_gamerule;
} Enigme2_3;

void init_bg(Enigme2 *bg);
void init_bg2(Enigme2_2 *bg);
void init_bg3(Enigme2_3 *bg);

void afficher_bg1(Enigme2 *bg, SDL_Surface *ecran);
void afficher_bg2(Enigme2_2 *bg, SDL_Surface *ecran);
void afficher_bg3(Enigme2_3 *bg, SDL_Surface *ecran);

void clickButton(Enigme2 *bg, SDL_Event event);
void clickButton2(Enigme2_2 *bg, SDL_Event event);
void clickButton3(Enigme2_3 *bg, SDL_Event event);

void mettre_a_jour_enigme(Enigme2 *e);
void mettre_a_jour_enigme2(Enigme2_2 *e);
void mettre_a_jour_enigme3(Enigme2_3 *e);

void liberer_enigme(Enigme2 *e);
void liberer_enigme2(Enigme2_2 *e);
void liberer_enigme3(Enigme2_3 *e);
#endif
