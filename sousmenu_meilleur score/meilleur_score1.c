#include "meilleur_score1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

void init_menu_score(Menu *menu) {

    menu->background_principale = NULL;
    menu->background_secondaire=NULL;
    menu->next[0] = menu->next[1] = NULL;
    menu->save[0] = menu->save[1] = NULL;
    menu->taper[0] = menu->taper[1] = NULL;
    menu->typecursor = NULL;
    menu->font = NULL;
    menu->title = NULL;
    menu->textTexture = NULL;
    menu->font1 = NULL;
    menu->note = NULL;
    menu->star[0] = menu->star[1] = menu->star[2] = NULL;
    menu->clickSound = NULL; 

    // Load background
    menu->background_principale = IMG_Load("backgroundM.png");
    if (!menu->background_principale) {
        fprintf(stderr, "Error loading background: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    // load background secondaire
      menu->background_secondaire = IMG_Load("backgroundM1.png");
    if (!menu->background_secondaire) {
        fprintf(stderr, "Error loading background: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);}
   menu->posbgs1 = (SDL_Rect){500, 100, menu->background_secondaire->w, menu->background_secondaire->h};
     // load victory
      menu->frame=0;
      menu->gifPosition.x=100;
      menu->gifPosition.y=100;
      menu->count = 0;
      for (int i =0 ; i < 9; ++i) {
        char filename[256];
        sprintf(filename, "/home/king/Desktop/sousmenu_meilleur score/assets/frame%d.png", i + 1);
        menu->images[menu->count] = IMG_Load(filename);
        if (menu->images[menu->count] != NULL) {
            menu->count++;
        }
    }
     // load vitory 1
       menu->frame1=0;
      menu->count1 = 0;
      menu->gifPosition1.x=1300;
      menu->gifPosition1.y=100;
      menu->count1 = 0;
      for (int i =0 ; i < 9; ++i) {
        char filename[256];
        sprintf(filename, "/home/king/Desktop/sousmenu_meilleur score/assets/frame%d.png", i + 1);
        menu->images1[menu->count1] = IMG_Load(filename);
        if (menu->images1[menu->count1] != NULL) {
            menu->count1++;
        }
    }
     // load music
     menu->music = Mix_LoadMUS("/home/king/Desktop/sousmenu_meilleur score/tadaa.mp3");
        if (!menu->music) {
    printf("Failed to load music: %s\n", Mix_GetError());
}

     
     
      //load star
       menu->star[0] = IMG_Load("etoile.png");
       menu->star[1] = IMG_Load("etoile.png");
       menu->star[2] = IMG_Load("etoile.png");
    if (!menu->star[0] || !menu->star[1] || !menu->star[2]) {
    fprintf(stderr, "Error loading stars: %s\n", IMG_GetError());
    exit(EXIT_FAILURE);
}

    
     menu->posstar0=(SDL_Rect){300, 300, menu->star[0]->w, menu->star[0]->h};
     menu->posstar1=(SDL_Rect){1500, 300, menu->star[0]->w, menu->star[0]->h};
     menu->posstar2=(SDL_Rect){870, 600, menu->star[0]->w, menu->star[0]->h};
      // Load buttons
    menu->next[0] = IMG_Load("next1.png");
    menu->next[1] = IMG_Load("next2.png");
    if (!menu->next[0] || !menu->next[1]) {
        fprintf(stderr, "Error loading next buttons: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }

    menu->taper[0] = IMG_Load("taper1.png");
    menu->taper[1] = IMG_Load("taper2.png");
    if (!menu->taper[0] || !menu->taper[1]) {
        fprintf(stderr, "Error loading taper buttons: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }

    menu->typecursor = IMG_Load("typecursor.png");
    if (!menu->typecursor) {
        fprintf(stderr, "Error loading cursor: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    //load save
    menu->save[0] = IMG_Load("save1.png");
    menu->save[1] = IMG_Load("save2.png");
    if (!menu->save[0] || !menu->save[1]) {
        fprintf(stderr, "Error loading next buttons: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    
    menu->possave=(SDL_Rect){1000, 800, menu->next[0]->w, menu->next[0]->h};
    
    //positions
    menu->posnext = (SDL_Rect){600, 800, menu->next[0]->w, menu->next[0]->h};
    menu->postaper = (SDL_Rect){500, 500, menu->taper[0]->w, menu->taper[0]->h};
    menu->postypecursor = (SDL_Rect){500, 550, 0, 0};

    // timing
    menu->lastBlinkTime = SDL_GetTicks();
    menu->cursorVisible = 1;
    menu->btn_next_select = 0;
    menu->btn_taper_select = 0;
    menu->typingActive = 0;
    menu->nameLength = 0;
    memset(menu->name, 0, MAX_NAME_LENGTH);

    // Load font
    menu->font = TTF_OpenFont("BrownieStencil-8O8MJ.ttf", 80);
    if (!menu->font) {
        fprintf(stderr, "Error loading font: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    //title
    menu->fontColor = (SDL_Color){255, 255, 255};
    menu->title = TTF_RenderText_Blended(menu->font, "What should we call you?", menu->fontColor);
    if (!menu->title) {
        fprintf(stderr, "Error rendering title: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    menu->postext = (SDL_Rect){410, 220, 0, 0};
    //title background secondaire
    menu->title2 = TTF_RenderText_Blended(menu->font, "Record Holder:", menu->fontColor);
    if (!menu->title) {
        fprintf(stderr, "Error rendering title: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    menu->postitle2 = (SDL_Rect){650, 240, 0, 0};
    // note
     menu->font1 = TTF_OpenFont("BrownieStencil-8O8MJ.ttf", 30);
if (!menu->font1) {
    fprintf(stderr, "Error loading font1: %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
}
    menu->note= TTF_RenderText_Blended(menu->font1, "NOTE:Do not include spaces or special characters in your name", menu->fontColor);
    if (!menu->note) {
        fprintf(stderr, "Error rendering title: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    menu->posnote = (SDL_Rect){450, 350, 0, 0};
    //sound bref
    menu->clickSound = Mix_LoadWAV("click.wav");
    if (!menu->clickSound) {
        fprintf(stderr, "Error loading click sound: %s\n", Mix_GetError());
        exit(EXIT_FAILURE);
    }
    menu->soundPlayed = 0;
    menu->indiceEcranMeilleur = 0;
    menu->score = 300; 
    menu->bestScore = 50;
    menu->bestName[0] = '\0';
    menu->btn_save_select=0;
    menu->frame=0;

}

void handle_text_input(Menu *menu, SDL_Event event) {
    static Uint32 lastKeyTime = 0;
    static SDLKey lastKey = SDLK_UNKNOWN;
    const Uint32 repeatDelay = 300;
    const Uint32 repeatInterval = 30;

    if (!menu->typingActive || event.type != SDL_KEYDOWN)
        return;

    Uint32 currentTime = SDL_GetTicks();
    SDLKey key = event.key.keysym.sym;

    if (key == lastKey) {
        if (currentTime - lastKeyTime < repeatDelay) return;
        if (currentTime - lastKeyTime < repeatInterval) return;
    }
    lastKey = key;
    lastKeyTime = currentTime;

    if (key == SDLK_BACKSPACE && menu->nameLength > 0) {
        menu->name[--menu->nameLength] = '\0';
        return;
    }

    if (menu->nameLength < MAX_NAME_LENGTH-1 && key >= SDLK_a && key <= SDLK_z) {
        menu->name[menu->nameLength++] = 'a' + (key - SDLK_a);
        menu->name[menu->nameLength] = '\0';
    }
}

void afficher_nom_utilisateur(Menu *menu, SDL_Surface *Fenetre) {
    if (menu->textTexture) {
        SDL_FreeSurface(menu->textTexture);
        menu->textTexture = NULL;
    }

    if (menu->nameLength > 0) {
        menu->textTexture = TTF_RenderText_Blended(menu->font, menu->name, menu->fontColor);
        if (menu->textTexture) {
            SDL_Rect pos = {550, 550, 0, 0};
            SDL_BlitSurface(menu->textTexture, NULL, Fenetre, &pos);
        }
    }
}

void afficher_menu(Menu *menu, SDL_Surface *Fenetre, SDL_Event event) {
    SDL_BlitSurface(menu->background_principale, NULL, Fenetre, NULL);

    if (menu->indiceEcranMeilleur == 0) {
        menu->btn_next_select = colision_avec_souris(menu->posnext) ? 1 : 0;
        menu->btn_save_select = colision_avec_souris(menu->possave) ? 1 : 0;

        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            if (colision_avec_souris(menu->postaper)) {
                menu->typingActive = 1;
                menu->btn_taper_select = 1;
            }
        } else {
            menu->btn_taper_select = colision_avec_souris(menu->postaper) ? 1 : 0;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            if (colision_avec_souris(menu->posnext) && !menu->soundPlayed) {
                Mix_PlayChannel(-1, menu->clickSound, 0);
                menu->soundPlayed = 1;
                menu->indiceEcranMeilleur = 1;  // Move to the next screen
            }
        

        if (colision_avec_souris(menu->possave) && !menu->soundPlayed) {
            sauvegarder_nom_utilisateur(menu->name, "nom_utilisateur.txt");
            Mix_PlayChannel(-1, menu->clickSound, 0);
            menu->soundPlayed = 1;
        }}

        if (colision_avec_souris(menu->postaper)) {
            menu->typingActive = 1;
            menu->btn_taper_select = 1;
        }

        if (event.type == SDL_MOUSEMOTION && !colision_avec_souris(menu->posnext)) {
            menu->soundPlayed = 0;
        }
        if (event.type == SDL_MOUSEMOTION && !colision_avec_souris(menu->possave)) {
            menu->soundPlayed = 0;
        } else {
            menu->btn_taper_select = colision_avec_souris(menu->postaper) ? 1 : 0;
        }

        SDL_BlitSurface(menu->save[menu->btn_save_select], NULL, Fenetre, &menu->possave);
        SDL_BlitSurface(menu->next[menu->btn_next_select], NULL, Fenetre, &menu->posnext);
        SDL_BlitSurface(menu->taper[menu->btn_taper_select], NULL, Fenetre, &menu->postaper);

        SDL_BlitSurface(menu->title, NULL, Fenetre, &menu->postext);
        if (menu->note) {
            SDL_BlitSurface(menu->note, NULL, Fenetre, &menu->posnote);
        } else {
            fprintf(stderr, "Error: menu->note is NULL!\n");
        }

        handle_text_input(menu, event);

        if (menu->typingActive) {
            afficher_nom_utilisateur(menu, Fenetre);

            Uint32 currentTime = SDL_GetTicks();
            if (currentTime - menu->lastBlinkTime > 500) {
                menu->cursorVisible = !menu->cursorVisible;
                menu->lastBlinkTime = currentTime;
            }

            if (menu->cursorVisible) {
                int textWidth = 0;
                if (menu->nameLength > 0) {
                    TTF_SizeText(menu->font, menu->name, &textWidth, NULL);
                }
                menu->postypecursor.x = 550 + textWidth;
                SDL_BlitSurface(menu->typecursor, NULL, Fenetre, &menu->postypecursor);
            }
        }
    } else if (menu->indiceEcranMeilleur == 1) {
        // Load best score and name from file
        FILE *bestScoreFile = fopen("best_score.txt", "r");
        if (bestScoreFile) {
            fscanf(bestScoreFile, "%d\n", &menu->bestScore);
            fgets(menu->bestName, MAX_NAME_LENGTH, bestScoreFile);
            fclose(bestScoreFile);
            // Remove newline character at the end of the name, if present
            size_t len = strlen(menu->bestName);
            if (len > 0 && menu->bestName[len - 1] == '\n') {
                menu->bestName[len - 1] = '\0';
            }
        }

        // Render the background and decorations
        SDL_BlitSurface(menu->background_secondaire, NULL, Fenetre, &menu->posbgs1);
        SDL_BlitSurface(menu->title2, NULL, Fenetre, &menu->postitle2);
        SDL_BlitSurface(menu->star[0], NULL, Fenetre, &menu->posstar0);
        SDL_BlitSurface(menu->star[1], NULL, Fenetre, &menu->posstar1);
        SDL_BlitSurface(menu->star[2], NULL, Fenetre, &menu->posstar2);

        // Display Best Score Name (Always)
        if (menu->bestName[0] != '\0') {
            SDL_Surface *bestNameSurface = TTF_RenderText_Blended(menu->font, menu->bestName, menu->fontColor);
            if (bestNameSurface) {
                SDL_Rect posBestName = {850, 430, 0, 0};  // Adjust position if needed
                SDL_BlitSurface(bestNameSurface, NULL, Fenetre, &posBestName);
                SDL_FreeSurface(bestNameSurface);
            }
        }

        // Check if the best score needs to be updated only if the player's score exceeds the current best score
        if (menu->score > menu->bestScore) {
    // Update the best score and associated name
    menu->bestScore = menu->score;
    Mix_PlayMusic(menu->music, 0); // Play once

    // Safely copy the player's name
    strncpy(menu->bestName, menu->name, MAX_NAME_LENGTH - 1);
    menu->bestName[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null-termination

    // Save to file
    FILE *bestScoreFile = fopen("best_score.txt", "w");
    if (bestScoreFile == NULL) {
        perror("Error opening best_score.txt");
        return;
    }
    fprintf(bestScoreFile, "%d\n%s", menu->bestScore, menu->bestName);
    fclose(bestScoreFile);

    // Play the winning animation (GIF-like loop)
    int animationFrames = 100;
    for (int i = 0; i < animationFrames; ++i) {
        SDL_BlitSurface(menu->background_principale, NULL, Fenetre, NULL);
        SDL_BlitSurface(menu->background_secondaire, NULL, Fenetre, &menu->posbgs1);
        SDL_BlitSurface(menu->title2, NULL, Fenetre, &menu->postitle2);
        SDL_BlitSurface(menu->star[0], NULL, Fenetre, &menu->posstar0);
        SDL_BlitSurface(menu->star[1], NULL, Fenetre, &menu->posstar1);
        SDL_BlitSurface(menu->star[2], NULL, Fenetre, &menu->posstar2);
;
        SDL_Delay(10);
        SDL_BlitSurface(menu->images[menu->frame], NULL, Fenetre, &menu->gifPosition);
        SDL_BlitSurface(menu->images1[menu->frame1], NULL, Fenetre, &menu->gifPosition1);
        SDL_Flip(Fenetre);
        menu->frame = (menu->frame + 1) % menu->count;
         menu->frame1 = (menu->frame1 + 1) % menu->count1;
        SDL_Delay(60);
    }
}

    }


    SDL_Flip(Fenetre);
}

int colision_avec_souris(SDL_Rect pos_btn) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return (x >= pos_btn.x && x < pos_btn.x + pos_btn.w &&
            y >= pos_btn.y && y < pos_btn.y + pos_btn.h);
}
void sauvegarder_nom_utilisateur(const char *nom, const char *fichier) {
    FILE *fp = fopen(fichier, "w");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(fp, "%s\n", nom);
    fclose(fp);
}

void liberer_menu_score(Menu *menu) {
    if (!menu) return;

    // Free surfaces in reverse order of creation
    if (menu->textTexture) {
        SDL_FreeSurface(menu->textTexture);
        menu->textTexture = NULL;
    }
    if (menu->note) {
        SDL_FreeSurface(menu->note);
        menu->note = NULL;
    }
    if (menu->title2) {
        SDL_FreeSurface(menu->title2);
        menu->title2 = NULL;
    }
    if (menu->title) {
        SDL_FreeSurface(menu->title);
        menu->title = NULL;
    }

    // Free animation frames
    for (int i = 0; i < 9; i++) {
        if (menu->images[i]) {
            SDL_FreeSurface(menu->images[i]);
            menu->images[i] = NULL;
        }
        if (menu->images1[i]) {
            SDL_FreeSurface(menu->images1[i]);
            menu->images1[i] = NULL;
        }
    }

    // Free button surfaces
    for (int i = 0; i < 2; i++) {
        if (menu->taper[i]) {
            SDL_FreeSurface(menu->taper[i]);
            menu->taper[i] = NULL;
        }
        if (menu->next[i]) {
            SDL_FreeSurface(menu->next[i]);
            menu->next[i] = NULL;
        }
        if (menu->save[i]) {
            SDL_FreeSurface(menu->save[i]);
            menu->save[i] = NULL;
        }
    }

    // Free star surfaces
    for (int i = 0; i < 3; i++) {
        if (menu->star[i]) {
            SDL_FreeSurface(menu->star[i]);
            menu->star[i] = NULL;
        }
    }

    if (menu->typecursor) {
        SDL_FreeSurface(menu->typecursor);
        menu->typecursor = NULL;
    }
    if (menu->background_secondaire) {
        SDL_FreeSurface(menu->background_secondaire);
        menu->background_secondaire = NULL;
    }
    if (menu->background_principale) {
        SDL_FreeSurface(menu->background_principale);
        menu->background_principale = NULL;
    }

    // Free fonts
    if (menu->font1) {
        TTF_CloseFont(menu->font1);
        menu->font1 = NULL;
    }
    if (menu->font) {
        TTF_CloseFont(menu->font);
        menu->font = NULL;
    }

    // Free sound
    if (menu->clickSound) {
        Mix_FreeChunk(menu->clickSound);
        menu->clickSound = NULL;
    }
}

