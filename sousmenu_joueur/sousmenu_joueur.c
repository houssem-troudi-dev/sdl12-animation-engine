#include "sousmenu_joueur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void init_menu_joueur(Menu *menu) {
    // Background
    menu->background_principale = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/bg.png");
    if (!menu->background_principale) {
        fprintf(stderr, "Error loading background: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }

    // Load font 
    menu->font = TTF_OpenFont("/home/king/Desktop/sousmenu_joueur/assets/BrownieStencil-8O8MJ.ttf", 24); 
    if (!menu->font) {
        fprintf(stderr, "Error loading font: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    //load j1 j2
     menu->j1= IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/j1.png");
     menu->j2= IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/j2.png");
     menu->posj1 = (SDL_Rect){0, 550, 0, 0};
     menu->posj2  = (SDL_Rect){1500, 550, 0, 0};
     menu->j11= IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/j11.png");
     menu->j22= IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/j22.png");
     menu->posj11 = (SDL_Rect){300, 100, 0, 0};
     menu->posj22  = (SDL_Rect){460, 100, 0, 0};
     menu->j11_index = 0;
     menu->j11_positions[0] = (SDL_Rect){300, 100, 0, 0};
     menu->j11_positions[1] = (SDL_Rect){600, 100, 0, 0};
     menu->j11_positions[2] = (SDL_Rect){900, 100, 0, 0};
     menu->j11_positions[3] = (SDL_Rect){1200,100, 0, 0};
     menu->posj11 = menu->j11_positions[0];
     menu->j22_index = 0;
     menu->j22_positions[0] = (SDL_Rect){300, 100, 0, 0};
     menu->j22_positions[1] = (SDL_Rect){600, 100, 0, 0};
     menu->j22_positions[2] = (SDL_Rect){900, 100, 0, 0};
     menu->j22_positions[3] = (SDL_Rect){1200,100, 0, 0};
     menu->posj22 = menu->j22_positions[0];
    // Load images for buttons
    menu->singlebuttons[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/bouton1.png");
    menu->singlebuttons[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/bouton2.png");
    menu->multibuttons[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/bouton3.png");
    menu->multibuttons[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/bouton4.png");
    menu->back[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/bouton5.png");
    menu->back[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/bouton6.png");

    // Character selection buttons
    menu->c1[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/33.png");
    menu->c1[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/33(copy).png");
    menu->c2[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/34.png");
    menu->c2[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/34(copy).png");
    menu->c3[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/35.png");
    menu->c3[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/35(copy).png");
    menu->c4[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/4.png");
    menu->c4[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/4(copy).png");

    // Input buttons
    menu->input[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/p1.png");
    menu->input[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/p1 (copy).png");
    menu->input1[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/p2.png");
    menu->input1[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/p2 (copy).png");

    // Buttons  Valider and Cancel
    menu->valider[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/valider.png");
    menu->valider[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/valider.png");
    menu->cancel[0] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/cancel.png");
    menu->cancel[1] = IMG_Load("/home/king/Desktop/sousmenu_joueur/assets/cancel.png");

    // Positionsfor the elements
    menu->possingle = (SDL_Rect){700, 150, 0, 0};
    menu->posmulti  = (SDL_Rect){700, 400, 0, 0};
    menu->posback   = (SDL_Rect){700, 650, 0, 0};
    menu->posc1 = (SDL_Rect){300, 200, 0, 0};
    menu->posc2 = (SDL_Rect){600, 200, 0, 0};
    menu->posc3 = (SDL_Rect){900, 200, 0, 0};
    menu->posc4 = (SDL_Rect){1200, 200, 0, 0};
    menu->posinput = (SDL_Rect){300, 780, 0, 0};
    menu->posinput1 = (SDL_Rect){1100, 770, 0, 0};
    menu->posvalider = (SDL_Rect){730, 700, 0, 0};
    menu->poscancel = (SDL_Rect){730, 850, 0, 0};

    // States
    menu->btn_c1_select = 0;
    menu->btn_c2_select = 0;
    menu->btn_c3_select = 0;
    menu->btn_c4_select = 0;
    menu->btn_input_select = 0;
    menu->btn_input1_select = 0;

    menu->clickSound = Mix_LoadWAV("/home/king/Desktop/sousmenu_joueur/assets/click.wav");
    menu->soundPlayed = 0;
    menu->indiceEcranjoueur = 0;
}

int colision_avec_souris(SDL_Rect pos_btn) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return (x >= pos_btn.x && x < pos_btn.x + pos_btn.w && y >= pos_btn.y && y < pos_btn.y + pos_btn.h);
}

void afficher_menu_joueur(Menu *menu, SDL_Surface *Fenetre, SDL_Event event) {
    SDL_BlitSurface(menu->background_principale, NULL, Fenetre, NULL);

    if (menu->indiceEcranjoueur == 0) {
        menu->btn_single_select = colision_avec_souris(menu->possingle);
        menu->btn_multi_select = colision_avec_souris(menu->posmulti);
        menu->btn_back_select = colision_avec_souris(menu->posback);

        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            if (colision_avec_souris(menu->possingle)) {
                Mix_PlayChannel(-1, menu->clickSound, 0);
                menu->indiceEcranjoueur = 1;
            }
            if (colision_avec_souris(menu->posmulti)) {
                Mix_PlayChannel(-1, menu->clickSound, 0);
                menu->indiceEcranjoueur = 2;
            }
        }

        SDL_BlitSurface(menu->singlebuttons[menu->btn_single_select], NULL, Fenetre, &menu->possingle);
        SDL_BlitSurface(menu->multibuttons[menu->btn_multi_select], NULL, Fenetre, &menu->posmulti);
        SDL_BlitSurface(menu->back[menu->btn_back_select], NULL, Fenetre, &menu->posback);
    }

    if (menu->indiceEcranjoueur == 1) {
        static int mouseClicked = 0;
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && mouseClicked == 0) {
            mouseClicked = 1;

            if (colision_avec_souris(menu->posc1)) {
                menu->btn_c1_select = !menu->btn_c1_select;
                menu->btn_c2_select = menu->btn_c3_select = menu->btn_c4_select = 0;
                Mix_PlayChannel(-1, menu->clickSound, 0);
            } else if (colision_avec_souris(menu->posc2)) {
                menu->btn_c2_select = !menu->btn_c2_select;
                menu->btn_c1_select = menu->btn_c3_select = menu->btn_c4_select = 0;
                Mix_PlayChannel(-1, menu->clickSound, 0);
            } else if (colision_avec_souris(menu->posc3)) {
                menu->btn_c3_select = !menu->btn_c3_select;
                menu->btn_c1_select = menu->btn_c2_select = menu->btn_c4_select = 0;
                Mix_PlayChannel(-1, menu->clickSound, 0);
            } else if (colision_avec_souris(menu->posc4)) {
                menu->btn_c4_select = !menu->btn_c4_select;
                menu->btn_c1_select = menu->btn_c2_select = menu->btn_c3_select = 0;
                Mix_PlayChannel(-1, menu->clickSound, 0);
            } else if (colision_avec_souris(menu->posinput)) {
                menu->btn_input_select = !menu->btn_input_select;
                menu->btn_input1_select = 0;
                Mix_PlayChannel(-1, menu->clickSound, 0);
            } else if (colision_avec_souris(menu->posinput1)) {
                menu->btn_input1_select = !menu->btn_input1_select;
                menu->btn_input_select = 0;
                Mix_PlayChannel(-1, menu->clickSound, 0);
            } else if (colision_avec_souris(menu->posvalider)) {
                // Valider button
                FILE *fichier = fopen("selections.txt", "w");
                if (fichier == NULL) {
                    fprintf(stderr, "Error opening file for writing\n");
                    exit(EXIT_FAILURE);
                }

                // Save character selection
                if (menu->btn_c1_select) {
                    fprintf(fichier, "Character: c1\n");
                } else if (menu->btn_c2_select) {
                    fprintf(fichier, "Character: c2\n");
                } else if (menu->btn_c3_select) {
                    fprintf(fichier, "Character: c3\n");
                } else if (menu->btn_c4_select) {
                    fprintf(fichier, "Character: c4\n");
                }

                // Save input method
                if (menu->btn_input_select) {
                    fprintf(fichier, "Input: Keyboard\n");
                } else if (menu->btn_input1_select) {
                    fprintf(fichier, "Input: Gamepad\n");
                }

                fclose(fichier); 
                Mix_PlayChannel(-1, menu->clickSound, 0);
            } else if (colision_avec_souris(menu->poscancel)) {
                menu->indiceEcranjoueur = 0;
                Mix_PlayChannel(-1, menu->clickSound, 0);
            }
        }

        if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            mouseClicked = 0;
        }

        SDL_BlitSurface(menu->c1[menu->btn_c1_select], NULL, Fenetre, &menu->posc1);
        SDL_BlitSurface(menu->c2[menu->btn_c2_select], NULL, Fenetre, &menu->posc2);
        SDL_BlitSurface(menu->c3[menu->btn_c3_select], NULL, Fenetre, &menu->posc3);
        SDL_BlitSurface(menu->c4[menu->btn_c4_select], NULL, Fenetre, &menu->posc4);
        SDL_BlitSurface(menu->input[menu->btn_input_select], NULL, Fenetre, &menu->posinput);
        SDL_BlitSurface(menu->input1[menu->btn_input1_select], NULL, Fenetre, &menu->posinput1);
        SDL_BlitSurface(menu->valider[0], NULL, Fenetre, &menu->posvalider);
        SDL_BlitSurface(menu->cancel[0], NULL, Fenetre, &menu->poscancel);
        SDL_Color color = {255, 255, 255};  // White
        SDL_Surface *msg = TTF_RenderText_Blended(menu->font, "Please make your selection after due consideration.", color);
        if (msg) {
        SDL_Rect pos = {570, 150, 0, 0};
        SDL_BlitSurface(msg, NULL, Fenetre, &pos);
        SDL_FreeSurface(msg);}}
  if (menu->indiceEcranjoueur == 2) {

static int keyHandled = 0;
static int mouseClicked = 0;
if (event.type == SDL_KEYDOWN && !keyHandled) {
    SDLKey k = event.key.keysym.sym;
    keyHandled = 1;

    switch (k) {
      case SDLK_RIGHT:
        menu->j11_index = (menu->j11_index + 1) % 4;
        menu->posj11   = menu->j11_positions[menu->j11_index];
        Mix_PlayChannel(-1, menu->clickSound, 0);
        break;

      case SDLK_LEFT:
        menu->j11_index = (menu->j11_index + 3) % 4;
        menu->posj11   = menu->j11_positions[menu->j11_index];
        Mix_PlayChannel(-1, menu->clickSound, 0);
        break;
      case SDLK_z:
        menu->j22_index = (menu->j22_index + 1) % 4;
        menu->posj22   = menu->j22_positions[menu->j22_index];
        Mix_PlayChannel(-1, menu->clickSound, 0);
        break;

      case SDLK_a:
        menu->j22_index = (menu->j22_index + 3) % 4;
        menu->posj22   = menu->j22_positions[menu->j22_index];
        Mix_PlayChannel(-1, menu->clickSound, 0);
        break;

      default:
        keyHandled = 0;
        break;
    }
}
if (event.type == SDL_KEYUP) {
    SDLKey k = event.key.keysym.sym;
    if (k == SDLK_RIGHT || k == SDLK_LEFT || k == SDLK_z || k == SDLK_a) {
        keyHandled = 0;
    }
}

     if (event.type == SDL_MOUSEBUTTONDOWN &&
        event.button.button == SDL_BUTTON_LEFT && mouseClicked == 0) {
        mouseClicked = 1;
        if (colision_avec_souris(menu->posvalider)) {
            FILE *f = fopen("selections.txt", "w");
            if (f) {
                fprintf(f, "Player1: c%d\n", menu->j11_index + 1);
                fprintf(f, "Player2: c%d\n", menu->j22_index + 1);
                fclose(f);
            } else {
                fprintf(stderr, "Error opening selections.txt for writing\n");
            }
            Mix_PlayChannel(-1, menu->clickSound, 0);
        }
        else if (colision_avec_souris(menu->poscancel)) {
            menu->indiceEcranjoueur = 0;
            Mix_PlayChannel(-1, menu->clickSound, 0);
        }
    }
    if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            mouseClicked = 0;
        }
    SDL_BlitSurface(menu->c1[0], NULL, Fenetre, &menu->posc1);
    SDL_BlitSurface(menu->c2[0], NULL, Fenetre, &menu->posc2);
    SDL_BlitSurface(menu->c3[0], NULL, Fenetre, &menu->posc3);
    SDL_BlitSurface(menu->c4[0], NULL, Fenetre, &menu->posc4);
    SDL_BlitSurface(menu->valider[0], NULL, Fenetre, &menu->posvalider);
    SDL_BlitSurface(menu->cancel[0], NULL, Fenetre, &menu->poscancel);
    SDL_BlitSurface(menu->j1, NULL, Fenetre, &menu->posj1);
    SDL_BlitSurface(menu->j2, NULL, Fenetre, &menu->posj2);
    SDL_BlitSurface(menu->j11, NULL, Fenetre, &menu->posj11);
    SDL_BlitSurface(menu->j22, NULL, Fenetre, &menu->posj22);

    SDL_Flip(Fenetre);
}

    SDL_Flip(Fenetre); 
}

void liberer_menu_joueur(Menu *menu) {
    if (menu->background_principale) SDL_FreeSurface(menu->background_principale);

    for (int i = 0; i < 2; i++) {
        if (menu->singlebuttons[i]) SDL_FreeSurface(menu->singlebuttons[i]);
        if (menu->multibuttons[i]) SDL_FreeSurface(menu->multibuttons[i]);
        if (menu->back[i]) SDL_FreeSurface(menu->back[i]);
        if (menu->c1[i]) SDL_FreeSurface(menu->c1[i]);
        if (menu->c2[i]) SDL_FreeSurface(menu->c2[i]);
        if (menu->c3[i]) SDL_FreeSurface(menu->c3[i]);
        if (menu->c4[i]) SDL_FreeSurface(menu->c4[i]);
        if (menu->input[i]) SDL_FreeSurface(menu->input[i]);
        if (menu->input1[i]) SDL_FreeSurface(menu->input1[i]);
        if (menu->valider[i]) SDL_FreeSurface(menu->valider[i]);
        if (menu->cancel[i]) SDL_FreeSurface(menu->cancel[i]);
    }

    if (menu->clickSound) Mix_FreeChunk(menu->clickSound);
    if (menu->font) TTF_CloseFont(menu->font);
}

