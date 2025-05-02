#include "meilleur_score.h"
#include <stdio.h>
#include <stdlib.h>

void init_menu_score(Menu *menu){
    // Charger l'arrière-plan
    menu->background_principale = IMG_Load("/home/king/Desktop/sousmenu_meilleur score/backgroundM.png");
    if (!menu->background_principale) {
        printf("Erreur chargement background : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }

    // Boutons NEXT
    menu->next[0] = IMG_Load("next1.png");
    menu->next[1] = IMG_Load("next2.png");
    if (!menu->next[0] || !menu->next[1]) {
        printf("Erreur chargement next*.png : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    menu->posnext.x = 800;
    menu->posnext.y = 800;
    menu->posnext.w = menu->next[0]->w;
    menu->posnext.h = menu->next[0]->h;

    // Boutons TAPER
    menu->taper[0] = IMG_Load("taper1.png");
    menu->taper[1] = IMG_Load("taper2.png");
    if (!menu->taper[0] || !menu->taper[1]) {
        printf("Erreur chargement taper*.png : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    menu->postaper.x = 500;
    menu->postaper.y = 500;
    menu->postaper.w = menu->taper[0]->w;
    menu->postaper.h = menu->taper[0]->h;

    // Type Cursor
    menu->typecursor = IMG_Load("typecursor.png");
    if (!menu->typecursor) {
        printf("Erreur chargement typecursor*.png : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    menu->postypecursor.x = 500;
    menu->postypecursor.y = 550;

    // Blink init
    menu->lastBlinkTime = SDL_GetTicks();
    menu->cursorVisible = 1;

    // Texte
    menu->font = TTF_OpenFont("BrownieStencil-8O8MJ.ttf", 80);
    if (!menu->font) {
        printf("Erreur chargement police : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    menu->fontColor.r = 255;
    menu->fontColor.g = 255;
    menu->fontColor.b = 255;

    menu->title = TTF_RenderText_Blended(menu->font, "What should we call you?", menu->fontColor);
    if (!menu->title) {
        printf("Erreur rendu texte : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    menu->postext.x = 450;
    menu->postext.y = 220;

    menu->btn_next_select = 0;
    menu->btn_taper_select = 0;

}

void afficher_menu(Menu *m, SDL_Surface *Fenetre, SDL_Event event) {
    SDL_BlitSurface(m->background_principale, NULL, Fenetre, NULL);
    SDL_BlitSurface(m->title, NULL, Fenetre, &m->postext);
   
    // Bouton NEXT
    if (colision_avec_souris(m->posnext)) {
        m->btn_next_select = 1;
    } else {
        m->btn_next_select = 0;
    }
    SDL_BlitSurface(m->next[m->btn_next_select], NULL, Fenetre, &m->posnext);

    // Bouton TAPER
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        if (colision_avec_souris(m->postaper)) {
            m->btn_taper_select = 1;
        } else {
            m->btn_taper_select = 0;
        }
    }
    SDL_BlitSurface(m->taper[m->btn_taper_select], NULL, Fenetre, &m->postaper);

    // --- Blink Logic ---
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - m->lastBlinkTime >= 500) { // 500ms blink
        m->cursorVisible = !m->cursorVisible;
        m->lastBlinkTime = currentTime;
    }

    if (m->cursorVisible) {
        SDL_BlitSurface(m->typecursor, NULL, Fenetre, &m->postypecursor);
    }

    SDL_Flip(Fenetre);
}

int colision_avec_souris(SDL_Rect pos_btn){
    int x_souris, y_souris;
    SDL_GetMouseState(&x_souris, &y_souris);
    return (x_souris > pos_btn.x && x_souris < pos_btn.x + pos_btn.w &&
            y_souris > pos_btn.y && y_souris < pos_btn.y + pos_btn.h);
}

