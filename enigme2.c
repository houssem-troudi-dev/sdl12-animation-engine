    #include "enigme2.h"
    #include <stdio.h>
    #include <SDL/SDL_image.h>
    #include <math.h>

    void init_bg(Enigme2 *bg) {
        bg->bkg = IMG_Load("images/abstract-textured-backgound.jpg");
        if (bg->bkg == NULL) {
            printf("Erreur de chargement de l'image bg.png: %s\n", IMG_GetError());
        }
        bg->puzzle[0] = IMG_Load("images/puzzle image1/p1.png");
        bg->puzzle[1] = IMG_Load("images/puzzle image1/p2.png");
        bg->puzzle[2] = IMG_Load("images/puzzle image1/p3.png");
        bg->puzzle[3] = IMG_Load("images/puzzle image1/p4.png");
        bg->puzzle[4] = IMG_Load("images/puzzle image1/p5.png");
        bg->puzzle[5] = IMG_Load("images/puzzle image1/p6.png");
        bg->puzzle[6] = IMG_Load("images/puzzle image1/p7.png");
        bg->puzzle[7] = IMG_Load("images/puzzle image1/p8.png");
        bg->puzzle[8] = IMG_Load("images/puzzle image1/p9.png");
        bg->puzzle[9] = IMG_Load("images/puzzle image1/p10.png");
        bg->puzzle[10] = IMG_Load("images/puzzle image1/p11.png");
        bg->puzzle[11] = IMG_Load("images/puzzle image1/p12.png");
        bg->puzzle[12] = IMG_Load("images/puzzle image1/p13.png");
        bg->puzzle[13] = IMG_Load("images/puzzle image1/p14.png");
        bg->puzzle[14] = IMG_Load("images/puzzle image1/p15.png");
        bg->puzzle[15] = IMG_Load("images/puzzle image1/p16.png");
        bg->puzzle[16] = IMG_Load("images/puzzle image1/p17.png");
        bg->puzzle[17] = IMG_Load("images/puzzle image1/p18.png");
        bg->puzzle[18] = IMG_Load("images/puzzle image1/p19.png");
        bg->puzzle[19] = IMG_Load("images/puzzle image1/p20.png");
        bg->puzzle[20] = IMG_Load("images/puzzle image1/p21.png");
        bg->puzzle[21] = IMG_Load("images/puzzle image1/p22.png");
        bg->puzzle[22] = IMG_Load("images/puzzle image1/p23.png");
        bg->puzzle[23] = IMG_Load("images/puzzle image1/p24.png");
        bg->puzzle[24] = IMG_Load("images/puzzle image1/p25.png");
        bg->puzzle[25] = IMG_Load("images/puzzle image1/p13v2.png");
        bg->puzzle[26] = IMG_Load("images/puzzle image1/p13v3.png");

        bg->gamerule = IMG_Load("images/gamerule.png");

        bg->pos_btn_puzzle[0].x = 70;
        bg->pos_btn_puzzle[0].y = 120;
        bg->pos_btn_puzzle[0].w = bg->puzzle[0]->w;
        bg->pos_btn_puzzle[0].h = bg->puzzle[0]->h;

        bg->pos_btn_puzzle[1].x = 210;
        bg->pos_btn_puzzle[1].y = 120;
        bg->pos_btn_puzzle[1].w = bg->puzzle[1]->w;
        bg->pos_btn_puzzle[1].h = bg->puzzle[1]->h;

        bg->pos_btn_puzzle[2].x = 365;
        bg->pos_btn_puzzle[2].y = 120;
        bg->pos_btn_puzzle[2].w = bg->puzzle[2]->w;
        bg->pos_btn_puzzle[2].h = bg->puzzle[2]->h;

        bg->pos_btn_puzzle[3].x = 505;
        bg->pos_btn_puzzle[3].y = 120;
        bg->pos_btn_puzzle[3].w = bg->puzzle[3]->w;
        bg->pos_btn_puzzle[3].h = bg->puzzle[3]->h;

        bg->pos_btn_puzzle[4].x = 638; 
        bg->pos_btn_puzzle[4].y = 120;   
        bg->pos_btn_puzzle[4].w = bg->puzzle[4]->w;
        bg->pos_btn_puzzle[4].h = bg->puzzle[4]->h;

        bg->pos_btn_puzzle[5].x = 66;
        bg->pos_btn_puzzle[5].y = 260;
        bg->pos_btn_puzzle[5].w = bg->puzzle[5]->w;
        bg->pos_btn_puzzle[5].h = bg->puzzle[5]->h;

        bg->pos_btn_puzzle[6].x = 192;
        bg->pos_btn_puzzle[6].y = 244;
        bg->pos_btn_puzzle[6].w = bg->puzzle[6]->w;
        bg->pos_btn_puzzle[6].h = bg->puzzle[6]->h;

        bg->pos_btn_puzzle[7].x = 339;
        bg->pos_btn_puzzle[7].y = 247;
        bg->pos_btn_puzzle[7].w = bg->puzzle[7]->w;
        bg->pos_btn_puzzle[7].h = bg->puzzle[7]->h;

        bg->pos_btn_puzzle[8].x = 493;
        bg->pos_btn_puzzle[8].y = 260;
        bg->pos_btn_puzzle[8].w = bg->puzzle[8]->w;
        bg->pos_btn_puzzle[8].h = bg->puzzle[8]->h;

        bg->pos_btn_puzzle[9].x = 636;
        bg->pos_btn_puzzle[9].y = 260;
        bg->pos_btn_puzzle[9].w = bg->puzzle[9]->w;
        bg->pos_btn_puzzle[9].h = bg->puzzle[9]->h;

        bg->pos_btn_puzzle[10].x = 78;
        bg->pos_btn_puzzle[10].y = 410;
        bg->pos_btn_puzzle[10].w = bg->puzzle[10]->w;
        bg->pos_btn_puzzle[10].h = bg->puzzle[10]->h;

        bg->pos_btn_puzzle[11].x = 210;
        bg->pos_btn_puzzle[11].y = 397;
        bg->pos_btn_puzzle[11].w = bg->puzzle[11]->w;
        bg->pos_btn_puzzle[11].h = bg->puzzle[11]->h;

        bg->pos_btn_puzzle[12].x = 1100;
        bg->pos_btn_puzzle[12].y = 400;
        bg->pos_btn_puzzle[12].w = bg->puzzle[12]->w;
        bg->pos_btn_puzzle[12].h = bg->puzzle[12]->h;

        bg->pos_btn_puzzle[13].x = 493;
        bg->pos_btn_puzzle[13].y = 416;
        bg->pos_btn_puzzle[13].w = bg->puzzle[13]->w;
        bg->pos_btn_puzzle[13].h = bg->puzzle[13]->h;

        bg->pos_btn_puzzle[14].x = 633;
        bg->pos_btn_puzzle[14].y = 400;
        bg->pos_btn_puzzle[14].w = bg->puzzle[14]->w;
        bg->pos_btn_puzzle[14].h = bg->puzzle[14]->h;

        bg->pos_btn_puzzle[15].x = 69;
        bg->pos_btn_puzzle[15].y = 545;
        bg->pos_btn_puzzle[15].w = bg->puzzle[15]->w;
        bg->pos_btn_puzzle[15].h = bg->puzzle[15]->h;

        bg->pos_btn_puzzle[16].x = 212;
        bg->pos_btn_puzzle[16].y = 545;
        bg->pos_btn_puzzle[16].w = bg->puzzle[16]->w;
        bg->pos_btn_puzzle[16].h = bg->puzzle[16]->h;

        bg->pos_btn_puzzle[17].x = 362;
        bg->pos_btn_puzzle[17].y = 542;
        bg->pos_btn_puzzle[17].w = bg->puzzle[17]->w;
        bg->pos_btn_puzzle[17].h = bg->puzzle[17]->h;

        bg->pos_btn_puzzle[18].x = 495;
        bg->pos_btn_puzzle[18].y = 535;
        bg->pos_btn_puzzle[18].w = bg->puzzle[18]->w;
        bg->pos_btn_puzzle[18].h = bg->puzzle[18]->h;

        bg->pos_btn_puzzle[19].x = 630;
        bg->pos_btn_puzzle[19].y = 537;
        bg->pos_btn_puzzle[19].w = bg->puzzle[19]->w;
        bg->pos_btn_puzzle[19].h = bg->puzzle[19]->h;

        bg->pos_btn_puzzle[20].x = 81;
        bg->pos_btn_puzzle[20].y = 678;
        bg->pos_btn_puzzle[20].w = bg->puzzle[20]->w;
        bg->pos_btn_puzzle[20].h = bg->puzzle[20]->h;

        bg->pos_btn_puzzle[21].x = 227;
        bg->pos_btn_puzzle[21].y = 676;
        bg->pos_btn_puzzle[21].w = bg->puzzle[21]->w;
        bg->pos_btn_puzzle[21].h = bg->puzzle[21]->h;

        bg->pos_btn_puzzle[22].x = 365;
        bg->pos_btn_puzzle[22].y = 680;
        bg->pos_btn_puzzle[22].w = bg->puzzle[22]->w;
        bg->pos_btn_puzzle[22].h = bg->puzzle[22]->h;

        bg->pos_btn_puzzle[23].x = 500;
        bg->pos_btn_puzzle[23].y = 663;
        bg->pos_btn_puzzle[23].w = bg->puzzle[23]->w;
        bg->pos_btn_puzzle[23].h = bg->puzzle[23]->h;

        bg->pos_btn_puzzle[24].x = 627;
        bg->pos_btn_puzzle[24].y = 675;
        bg->pos_btn_puzzle[24].w = bg->puzzle[24]->w;
        bg->pos_btn_puzzle[24].h = bg->puzzle[24]->h;

        bg->pos_btn_puzzle[25].x = 1100;
        bg->pos_btn_puzzle[25].y = 150;
        bg->pos_btn_puzzle[25].w = bg->puzzle[25]->w;
        bg->pos_btn_puzzle[25].h = bg->puzzle[25]->h;

        bg->pos_btn_puzzle[26].x = 1100;
        bg->pos_btn_puzzle[26].y = 650;
        bg->pos_btn_puzzle[26].w = bg->puzzle[26]->w;
        bg->pos_btn_puzzle[26].h = bg->puzzle[26]->h;

        for (int i = 0; i < 93; i++) {
            char filename[30];
            sprintf(filename, "images/timer/timer_%d.png", i + 1);
            bg->timer[i] = IMG_Load(filename);
        }

        for (int i = 12; i < 239; i++) {
            char filename[60];
            sprintf(filename, "images/win/Wii Sports _You Win_ HD Green Screen%03d.png", i);
            bg->win[i] = IMG_Load(filename);
        }

        for (int i = 0; i < 248; i++) {
            char filename[60];
            sprintf(filename, "images/loose/Wii Sports _You Lose_ Green Screen%03d.png", i+3);
            bg->loose[i] = IMG_Load(filename);
        }

        for (int i = 0; i < 323; i++) {
            char filename[30];
            sprintf(filename, "images/wa9t/p%03d.png", i);
            bg->wa9t[i] = IMG_Load(filename);
        }

        for (int i = 0; i < 67; i++) {
            char filename[30];
            sprintf(filename, "images/wa9t/p%03d.png", i);
            bg->wa9t2[i] = IMG_Load(filename);
        }

        bg->pos_timer.x = 650;
        bg->pos_timer.y = 0;
        bg->pos_win.x = 150;
        bg->pos_win.y = 200;
        bg->pos_loose.x = 170;
        bg->pos_loose.y = 155;
        bg->pos_wa9t.x = 390;
        bg->pos_wa9t.y = 450;
        bg->pos_wa9t2.x = 390;
        bg->pos_wa9t2.y = 450;
        

        bg->compteur = 1;
        bg->jouer_gagner = -1;
        bg->fin_jeu = 0;
        bg->afficher_loose = 0;
        bg->loose_i = 0; 
        bg->win_i = 12;
        bg->saved = 0; 
        bg->gamerule_start_time = SDL_GetTicks();
        bg->temps_start_jouer = SDL_GetTicks();

        if (TTF_Init() == -1) {
            printf("Erreur d'initialisation de SDL_ttf: %s\n", TTF_GetError());
            return;
        }

        bg->font = TTF_OpenFont("Pixel-Game.otf", 120);
        if (!bg->font) {
            printf("Erreur de chargement de la police: %s\n", TTF_GetError());
        }

        SDL_Color textColor = {255, 255, 255};
        bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "FIND THE PERFECT PUZZLE", textColor);
        if (!bg->surfaceTexte) {
            printf("Erreur de rendu du texte: %s\n", TTF_GetError());
        }

        bg->pos_btn_text.x = 200;
        bg->pos_btn_text.y = 950;
        bg->pos_btn_text.w = bg->surfaceTexte->w;
        bg->pos_btn_text.h = bg->surfaceTexte->h;

        bg->show_gamerule = 1;
    }

    void afficher_bg1(Enigme2 *bg, SDL_Surface *ecran) {   
        if (bg->show_gamerule) {
            Uint32 wakt_tawa = SDL_GetTicks();
            if (wakt_tawa - bg->gamerule_start_time < 9000) {
                SDL_BlitSurface(bg->gamerule, NULL, ecran, NULL);
                SDL_Flip(ecran);
                return;
            } else {
                bg->show_gamerule = 0;
            }
        }
        SDL_BlitSurface(bg->bkg, NULL, ecran, NULL);
        
        static int wa9t_frame = 0;
        static int wa9t2_frame = 0;
        static int wa9t3_frame = 0;
        static int afficher_wa9t2 = 0;
        static int afficher_wa9t3 = 0;
        
        if (wa9t_frame < 323 && bg->wa9t[wa9t_frame]) {
            SDL_BlitSurface(bg->wa9t[wa9t_frame], NULL, ecran, &bg->pos_wa9t);
            wa9t_frame++;
        } else {
            afficher_wa9t2 = 1;
        }

        if (afficher_wa9t2 && wa9t2_frame < 323 && bg->wa9t2[wa9t2_frame]) {
            SDL_BlitSurface(bg->wa9t2[wa9t2_frame], NULL, ecran, &bg->pos_wa9t2);
            wa9t2_frame++;
        }
        
        for (int i = 0; i < 27; i++) {
            if (i == 12) continue;
            SDL_BlitSurface(bg->puzzle[i], NULL, ecran, &bg->pos_btn_puzzle[i]);
        }

        SDL_BlitSurface(bg->puzzle[12], NULL, ecran, &bg->pos_btn_puzzle[12]);

        if (bg->timer[bg->compteur])
            SDL_BlitSurface(bg->timer[bg->compteur], NULL, ecran, &bg->pos_timer);


        if (bg->jouer_gagner == 1) {
            if (bg->win_i < 239 && bg->win[bg->win_i]) {
                SDL_BlitSurface(bg->win[bg->win_i], NULL, ecran, &bg->pos_win);
                bg->win_i++;
            } else if (bg->win_i == 239) {
                bg->fin_jeu = 1;
            }  
        }  

        SDL_Color textColor = {255, 255, 255}; 
        if (bg->afficher_loose == 1) {
            bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "    GAME OVER.YOU LOST", textColor);
        }
        else if(bg->jouer_gagner == 1){
            char text[50];
            snprintf(text, sizeof(text), "    VICTORY IN %d SECONDS", bg->compteur);
            bg->surfaceTexte = TTF_RenderText_Solid(bg->font, text, textColor);
        }else {
            bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "FIND THE PERFECT PUZZLE", textColor);
        }

        if (bg->surfaceTexte != NULL) {
            SDL_BlitSurface(bg->surfaceTexte, NULL, ecran, &bg->pos_btn_text);
        }

        
        if (bg->afficher_loose == 1) {
            if (bg->loose_i < 248 && bg->loose[bg->loose_i]) {
                SDL_BlitSurface(bg->loose[bg->loose_i], NULL, ecran, &bg->pos_loose);
                bg->loose_i++;
            } else if (bg->loose_i >= 248) {
                bg->afficher_loose = 1;
                bg->jouer_gagner = 0;
                bg->fin_jeu = 1;
            }
        }
    }

    void clickButton(Enigme2 *bg, SDL_Event event) {
        static int sel = -1, offX = 0, offY = 0;

        if (bg->saved == 0) {
            bg->p12_init = bg->pos_btn_puzzle[12];
            bg->p25_init = bg->pos_btn_puzzle[25];
            bg->p26_init = bg->pos_btn_puzzle[26];
            bg->saved = 1;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN) {
            for (int i = 12; i <= 26; i++) {
                if ((i >= 13 && i <= 24) || (i == 12 && bg->piece_placee[12])) continue;
                SDL_Rect r = bg->pos_btn_puzzle[i];
                if (event.button.x >= r.x && event.button.x <= r.x + r.w && event.button.y >= r.y && event.button.y <= r.y + r.h) {
                    sel = i;
                    offX = event.button.x - r.x;
                    offY = event.button.y - r.y;
                    break;
                }
            }
        } else if (event.type == SDL_MOUSEMOTION && sel != -1 && !(sel == 12 && bg->piece_placee[12])) {
            bg->pos_btn_puzzle[sel].x = event.motion.x - offX;
            bg->pos_btn_puzzle[sel].y = event.motion.y - offY;
        } else if (event.type == SDL_MOUSEBUTTONUP && sel != -1) {
            SDL_Rect *pos = &bg->pos_btn_puzzle[sel];

            if (sel == 12) {
                SDL_Rect correct = {342, 393, 0, 0};
                if ((pos->x - correct.x) < 30 && (pos->y - correct.y) < 30) {
                    *pos = correct;
                    bg->piece_placee[12] = 1;
                    bg->jouer_gagner = 1;
                } else {
                    *pos = bg->p12_init;
                }
            } else if (sel == 25) {
                *pos = bg->p25_init;
                bg->piece_placee[25] = 1;
            } else if (sel == 26) {
                *pos = bg->p26_init;
                bg->piece_placee[26] = 1;
            }

            sel = -1;
        }
    }

    void mettre_a_jour_enigme(Enigme2 *e) {
        if (e->jouer_gagner != -1) return;

        if (SDL_GetTicks() - e->temps_start_jouer >= 500) {
            e->temps_start_jouer = SDL_GetTicks();
            if (e->compteur < 93) {
                e->compteur++;
                
            }
            if (e->compteur == 61 && e->piece_placee[12] == 0) {
                e->afficher_loose = 1;
            }
            else if(e->compteur == 77 ){
                e->fin_jeu = 1;
            }
        }
    }

    void liberer_enigme(Enigme2 *e) {
        SDL_FreeSurface(e->bkg);

        for (int i = 0; i < 27; i++) {
            if (e->puzzle[i]) SDL_FreeSurface(e->puzzle[i]);
        }

        for (int i = 0; i < 93; i++) {
            if (e->timer[i]) SDL_FreeSurface(e->timer[i]);
        }

        for (int i = 12; i < 239; i++) {
            if (e->win[i]) SDL_FreeSurface(e->win[i]);
        }

        for (int i = 0; i < 248; i++) {
            if (e->loose[i]) SDL_FreeSurface(e->loose[i]);
        }

        for (int i = 0; i < 323; i++) {
            if (e->wa9t[i]) SDL_FreeSurface(e->wa9t[i]);
        }

        for (int i = 0; i < 67; i++) {
            if (e->wa9t2[i]) SDL_FreeSurface(e->wa9t2[i]);
        }
        SDL_FreeSurface(e->gamerule);
    }
//---------------------------------------------------------------------//
void init_bg2(Enigme2_2 *bg) {
    bg->bkg = IMG_Load("images/abstract-textured-backgound.jpg");
    if (bg->bkg == NULL) {
        printf("Erreur de chargement de l'image bg.png: %s\n", IMG_GetError());
    }
    bg->puzzle2[0] = IMG_Load("images/puzzle image2/p1.png");
    bg->puzzle2[1] = IMG_Load("images/puzzle image2/p2.png");
    bg->puzzle2[2] = IMG_Load("images/puzzle image2/p3.png");
    bg->puzzle2[3] = IMG_Load("images/puzzle image2/p4.png");
    bg->puzzle2[4] = IMG_Load("images/puzzle image2/p5.png");
    bg->puzzle2[5] = IMG_Load("images/puzzle image2/p6.png");
    bg->puzzle2[6] = IMG_Load("images/puzzle image2/p7.png");
    bg->puzzle2[7] = IMG_Load("images/puzzle image2/p8.png");
    bg->puzzle2[8] = IMG_Load("images/puzzle image2/p9.png");
    bg->puzzle2[9] = IMG_Load("images/puzzle image2/p10.png");
    bg->puzzle2[10] = IMG_Load("images/puzzle image2/p11.png");
    bg->puzzle2[11] = IMG_Load("images/puzzle image2/p12.png");
    bg->puzzle2[12] = IMG_Load("images/puzzle image2/p13.png");
    bg->puzzle2[13] = IMG_Load("images/puzzle image2/p14.png");
    bg->puzzle2[14] = IMG_Load("images/puzzle image2/p15.png");
    bg->puzzle2[15] = IMG_Load("images/puzzle image2/p16.png");
    bg->puzzle2[16] = IMG_Load("images/puzzle image2/p17.png");
    bg->puzzle2[17] = IMG_Load("images/puzzle image2/p18.png");
    bg->puzzle2[18] = IMG_Load("images/puzzle image2/p19.png");
    bg->puzzle2[19] = IMG_Load("images/puzzle image2/p20.png");
    bg->puzzle2[20] = IMG_Load("images/puzzle image2/p21.png");
    bg->puzzle2[21] = IMG_Load("images/puzzle image2/p22.png");
    bg->puzzle2[22] = IMG_Load("images/puzzle image2/p23.png");
    bg->puzzle2[23] = IMG_Load("images/puzzle image2/p24.png");
    bg->puzzle2[24] = IMG_Load("images/puzzle image2/p25.png");
    bg->puzzle2[25] = IMG_Load("images/puzzle image2/p14.png");
    bg->puzzle2[26] = IMG_Load("images/puzzle image2/p12.png");

    bg->pos_btn_puzzle2[0].x = 70;
    bg->pos_btn_puzzle2[0].y = 80;
    bg->pos_btn_puzzle2[0].w = bg->puzzle2[0]->w;
    bg->pos_btn_puzzle2[0].h = bg->puzzle2[0]->h;
    bg->pos_btn_puzzle2[1].x = 210;
    bg->pos_btn_puzzle2[1].y = 95;
    bg->pos_btn_puzzle2[1].w = bg->puzzle2[1]->w;
    bg->pos_btn_puzzle2[1].h = bg->puzzle2[1]->h;
    bg->pos_btn_puzzle2[2].x = 355;
    bg->pos_btn_puzzle2[2].y = 95;
    bg->pos_btn_puzzle2[2].w = bg->puzzle2[2]->w;
    bg->pos_btn_puzzle2[2].h = bg->puzzle2[2]->h;
    bg->pos_btn_puzzle2[3].x = 483;
    bg->pos_btn_puzzle2[3].y = 83;
    bg->pos_btn_puzzle2[3].w = bg->puzzle2[3]->w;
    bg->pos_btn_puzzle2[3].h = bg->puzzle2[3]->h;
    bg->pos_btn_puzzle2[4].x = 612; 
    bg->pos_btn_puzzle2[4].y = 89;   
    bg->pos_btn_puzzle2[4].w = bg->puzzle2[4]->w;
    bg->pos_btn_puzzle2[4].h = bg->puzzle2[4]->h;
    bg->pos_btn_puzzle2[5].x = 80;
    bg->pos_btn_puzzle2[5].y = 210;
    bg->pos_btn_puzzle2[5].w = bg->puzzle2[5]->w;
    bg->pos_btn_puzzle2[5].h = bg->puzzle2[5]->h;
    bg->pos_btn_puzzle2[6].x = 220;
    bg->pos_btn_puzzle2[6].y = 219;
    bg->pos_btn_puzzle2[6].w = bg->puzzle2[6]->w;
    bg->pos_btn_puzzle2[6].h = bg->puzzle2[6]->h;
    bg->pos_btn_puzzle2[7].x = 354;
    bg->pos_btn_puzzle2[7].y = 222;
    bg->pos_btn_puzzle2[7].w = bg->puzzle2[7]->w;
    bg->pos_btn_puzzle2[7].h = bg->puzzle2[7]->h;
    bg->pos_btn_puzzle2[8].x = 485;
    bg->pos_btn_puzzle2[8].y = 212;
    bg->pos_btn_puzzle2[8].w = bg->puzzle2[8]->w;
    bg->pos_btn_puzzle2[8].h = bg->puzzle2[8]->h;
    bg->pos_btn_puzzle2[9].x = 615;
    bg->pos_btn_puzzle2[9].y = 226;
    bg->pos_btn_puzzle2[9].w = bg->puzzle2[9]->w;
    bg->pos_btn_puzzle2[9].h = bg->puzzle2[9]->h;
    bg->pos_btn_puzzle2[10].x = 78;
    bg->pos_btn_puzzle2[10].y = 350;
    bg->pos_btn_puzzle2[10].w = bg->puzzle2[10]->w;
    bg->pos_btn_puzzle2[10].h = bg->puzzle2[10]->h;
    bg->pos_btn_puzzle2[11].x = 214;
    bg->pos_btn_puzzle2[11].y = 347;
    bg->pos_btn_puzzle2[11].w = bg->puzzle2[11]->w;
    bg->pos_btn_puzzle2[11].h = bg->puzzle2[11]->h;
    bg->pos_btn_puzzle2[12].x = 1100;
    bg->pos_btn_puzzle2[12].y = 350;
    bg->pos_btn_puzzle2[12].w = bg->puzzle2[12]->w;
    bg->pos_btn_puzzle2[12].h = bg->puzzle2[12]->h;
    bg->pos_btn_puzzle2[13].x = 496;
    bg->pos_btn_puzzle2[13].y = 348;
    bg->pos_btn_puzzle2[13].w = bg->puzzle2[13]->w;
    bg->pos_btn_puzzle2[13].h = bg->puzzle2[13]->h;
    bg->pos_btn_puzzle2[14].x = 622;
    bg->pos_btn_puzzle2[14].y = 364;
    bg->pos_btn_puzzle2[14].w = bg->puzzle2[14]->w;
    bg->pos_btn_puzzle2[14].h = bg->puzzle2[14]->h;
    bg->pos_btn_puzzle2[15].x = 55;
    bg->pos_btn_puzzle2[15].y = 472;
    bg->pos_btn_puzzle2[15].w = bg->puzzle2[15]->w;
    bg->pos_btn_puzzle2[15].h = bg->puzzle2[15]->h;
    bg->pos_btn_puzzle2[16].x = 192;
    bg->pos_btn_puzzle2[16].y = 487;
    bg->pos_btn_puzzle2[16].w = bg->puzzle2[16]->w;
    bg->pos_btn_puzzle2[16].h = bg->puzzle2[16]->h;
    bg->pos_btn_puzzle2[17].x = 340;
    bg->pos_btn_puzzle2[17].y = 500;
    bg->pos_btn_puzzle2[17].w = bg->puzzle2[17]->w;
    bg->pos_btn_puzzle2[17].h = bg->puzzle2[17]->h;
    bg->pos_btn_puzzle2[18].x = 492;
    bg->pos_btn_puzzle2[18].y = 507;
    bg->pos_btn_puzzle2[18].w = bg->puzzle2[18]->w;
    bg->pos_btn_puzzle2[18].h = bg->puzzle2[18]->h;
    bg->pos_btn_puzzle2[19].x = 625;
    bg->pos_btn_puzzle2[19].y = 500;
    bg->pos_btn_puzzle2[19].w = bg->puzzle2[19]->w;
    bg->pos_btn_puzzle2[19].h = bg->puzzle2[19]->h;
    bg->pos_btn_puzzle2[20].x = 65;
    bg->pos_btn_puzzle2[20].y = 625;
    bg->pos_btn_puzzle2[20].w = bg->puzzle2[20]->w;
    bg->pos_btn_puzzle2[20].h = bg->puzzle2[20]->h;
    bg->pos_btn_puzzle2[21].x = 202;
    bg->pos_btn_puzzle2[21].y = 621;
    bg->pos_btn_puzzle2[21].w = bg->puzzle2[21]->w;
    bg->pos_btn_puzzle2[21].h = bg->puzzle2[21]->h;
    bg->pos_btn_puzzle2[22].x = 350;
    bg->pos_btn_puzzle2[22].y = 633;
    bg->pos_btn_puzzle2[22].w = bg->puzzle2[22]->w;
    bg->pos_btn_puzzle2[22].h = bg->puzzle2[22]->h;
    bg->pos_btn_puzzle2[23].x = 490;
    bg->pos_btn_puzzle2[23].y = 626;
    bg->pos_btn_puzzle2[23].w = bg->puzzle2[23]->w;
    bg->pos_btn_puzzle2[23].h = bg->puzzle2[23]->h;
    bg->pos_btn_puzzle2[24].x = 632;
    bg->pos_btn_puzzle2[24].y = 636;
    bg->pos_btn_puzzle2[24].w = bg->puzzle2[24]->w;
    bg->pos_btn_puzzle2[24].h = bg->puzzle2[24]->h;
    bg->pos_btn_puzzle2[25].x = 1100;
    bg->pos_btn_puzzle2[25].y = 100;
    bg->pos_btn_puzzle2[25].w = bg->puzzle2[25]->w;
    bg->pos_btn_puzzle2[25].h = bg->puzzle2[25]->h;
    bg->pos_btn_puzzle2[26].x = 1100;
    bg->pos_btn_puzzle2[26].y = 600;
    bg->pos_btn_puzzle2[26].w = bg->puzzle2[26]->w;
    bg->pos_btn_puzzle2[26].h = bg->puzzle2[26]->h;

    bg->gamerule = IMG_Load("images/gamerule.png");

    for (int i = 0; i < 93; i++) {
        char filename[30];
        sprintf(filename, "images/timer/timer_%d.png", i + 1);
        bg->timer[i] = IMG_Load(filename);
    }

    for (int i = 12; i < 239; i++) {
        char filename[60];
        sprintf(filename, "images/win/Wii Sports _You Win_ HD Green Screen%03d.png", i);
        bg->win[i] = IMG_Load(filename);
    }

    for (int i = 0; i < 248; i++) {
        char filename[60];
        sprintf(filename, "images/loose/Wii Sports _You Lose_ Green Screen%03d.png", i+3);
        bg->loose[i] = IMG_Load(filename);
    }

    for (int i = 0; i < 323; i++) {
        char filename[30];
        sprintf(filename, "images/wa9t/p%03d.png", i);
        bg->wa9t[i] = IMG_Load(filename);
    }

    for (int i = 0; i < 67; i++) {
        char filename[30];
        sprintf(filename, "images/wa9t/p%03d.png", i);
        bg->wa9t2[i] = IMG_Load(filename);
    }

    

    bg->pos_timer.x = 650;
    bg->pos_timer.y = 0;
    bg->pos_win.x = 150;
    bg->pos_win.y = 200;
    bg->pos_loose.x = 170;
    bg->pos_loose.y = 200;
    bg->pos_wa9t.x = 480;
    bg->pos_wa9t.y = 490;
    bg->pos_wa9t2.x = 480;
    bg->pos_wa9t2.y = 490;

    bg->compteur = 1;
    bg->jouer_gagner = -1;
    bg->fin_jeu = 0;
    bg->afficher_loose = 0;
    bg->loose_i = 0; 
    bg->win_i = 12;
    bg->saved = 0; 
    bg->gamerule_start_time = SDL_GetTicks();
    bg->temps_start_jouer = SDL_GetTicks();


    if (TTF_Init() == -1) {
        printf("Erreur d'initialisation de SDL_ttf: %s\n", TTF_GetError());
        return;
    }

    bg->font = TTF_OpenFont("Pixel-Game.otf", 120);
    if (!bg->font) {
        printf("Erreur de chargement de la police: %s\n", TTF_GetError());
    }

    SDL_Color textColor = {255, 255, 255};
    bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "FIND THE PERFECT PUZZLE", textColor);
    if (!bg->surfaceTexte) {
        printf("Erreur de rendu du texte: %s\n", TTF_GetError());
    }

    bg->pos_btn_text.x = 200;
    bg->pos_btn_text.y = 950;
    bg->pos_btn_text.w = bg->surfaceTexte->w;
    bg->pos_btn_text.h = bg->surfaceTexte->h;

    bg->show_gamerule = 1;
}

void afficher_bg2(Enigme2_2 *bg, SDL_Surface *ecran) {
    SDL_Event event;

    if (bg->show_gamerule) {
        Uint32 wakt_tawa = SDL_GetTicks();
        if (wakt_tawa - bg->gamerule_start_time < 9000) {
            SDL_BlitSurface(bg->gamerule, NULL, ecran, NULL);
            SDL_Flip(ecran);
            return; // Ne pas afficher le reste tant que 'gamerule' est visible
        } else {
            bg->show_gamerule = 0;
        }
    }
    SDL_BlitSurface(bg->bkg, NULL, ecran, NULL);
    
    static int wa9t_frame = 0;
    static int wa9t2_frame = 0;
    static int wa9t3_frame = 0;
    static int afficher_wa9t2 = 0;
    static int afficher_wa9t3 = 0;
    
    if (wa9t_frame < 323 && bg->wa9t[wa9t_frame]) {
        SDL_BlitSurface(bg->wa9t[wa9t_frame], NULL, ecran, &bg->pos_wa9t);
        wa9t_frame++;
    } else {
        afficher_wa9t2 = 1;
    }

    if (afficher_wa9t2 && wa9t2_frame < 323 && bg->wa9t2[wa9t2_frame]) {
        SDL_BlitSurface(bg->wa9t2[wa9t2_frame], NULL, ecran, &bg->pos_wa9t2);
        wa9t2_frame++;
    }
    
    for (int i = 0; i < 27; i++) {
        if (i == 12) continue;
        SDL_BlitSurface(bg->puzzle2[i], NULL, ecran, &bg->pos_btn_puzzle2[i]);
    }

    SDL_BlitSurface(bg->puzzle2[12], NULL, ecran, &bg->pos_btn_puzzle2[12]);

    if (bg->timer[bg->compteur])
        SDL_BlitSurface(bg->timer[bg->compteur], NULL, ecran, &bg->pos_timer);


    if (bg->jouer_gagner == 1) {
        if (bg->win_i < 239 && bg->win[bg->win_i]) {
            SDL_BlitSurface(bg->win[bg->win_i], NULL, ecran, &bg->pos_win);
            bg->win_i++;
        } else if (bg->win_i == 239) {
            bg->fin_jeu = 1;
        }  
    }  

    SDL_Color textColor = {255, 255, 255}; 
    if (bg->afficher_loose == 1) {
        bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "    GAME OVER.YOU LOST", textColor);
    }
    else if(bg->jouer_gagner == 1){
        char text[50];
        snprintf(text, sizeof(text), "    VICTORY IN %d SECONDS", bg->compteur);
        bg->surfaceTexte = TTF_RenderText_Solid(bg->font, text, textColor);
    }else {
        bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "FIND THE PERFECT PUZZLE", textColor);
    }

    if (bg->surfaceTexte != NULL) {
        SDL_BlitSurface(bg->surfaceTexte, NULL, ecran, &bg->pos_btn_text);
    }

    
    if (bg->afficher_loose == 1) {
        if (bg->loose_i < 248 && bg->loose[bg->loose_i]) {
            SDL_BlitSurface(bg->loose[bg->loose_i], NULL, ecran, &bg->pos_loose);
            bg->loose_i++;
        } else if (bg->loose_i >= 248) {
            bg->afficher_loose = 0;
            bg->jouer_gagner = 0;
            bg->fin_jeu = 1;
        }
    }
}
void clickButton2(Enigme2_2 *bg, SDL_Event event) {
    static int sel = -1, offX = 0, offY = 0;

    if (bg->saved == 0) {
        bg->p12_init = bg->pos_btn_puzzle2[12];
        bg->p25_init = bg->pos_btn_puzzle2[25];
        bg->p26_init = bg->pos_btn_puzzle2[26];
        bg->saved = 1;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        for (int i = 12; i <= 26; i++) {
            if ((i >= 13 && i <= 24) || (i == 12 && bg->piece_placee[12])) continue;
            SDL_Rect r = bg->pos_btn_puzzle2[i];
            if (event.button.x >= r.x && event.button.x <= r.x + r.w &&
                event.button.y >= r.y && event.button.y <= r.y + r.h) {
                sel = i;
                offX = event.button.x - r.x;
                offY = event.button.y - r.y;
                break;
            }
        }
    } else if (event.type == SDL_MOUSEMOTION && sel != -1 && !(sel == 12 && bg->piece_placee[12])) {
        bg->pos_btn_puzzle2[sel].x = event.motion.x - offX;
        bg->pos_btn_puzzle2[sel].y = event.motion.y - offY;
    } else if (event.type == SDL_MOUSEBUTTONUP && sel != -1) {
        SDL_Rect *pos = &bg->pos_btn_puzzle2[sel];

        if (sel == 12) {
            SDL_Rect correct = {357, 347, 0, 0};
            if ((pos->x - correct.x) < 30 && (pos->y - correct.y) < 30) {
                *pos = correct;
                bg->piece_placee[12] = 1;
                bg->jouer_gagner = 1;
            } else {
                *pos = bg->p12_init;
            }
        } else if (sel == 25) {
            *pos = bg->p25_init;
            bg->piece_placee[25] = 1;
        } else if (sel == 26) {
            *pos = bg->p26_init;
            bg->piece_placee[26] = 1;
        }

        sel = -1;
    }
}
void mettre_a_jour_enigme2(Enigme2_2 *e) {
    if (e->jouer_gagner != -1) return;

    if (SDL_GetTicks() - e->temps_start_jouer >= 500) {
        if (e->compteur < 93) {
            e->compteur++;
            e->temps_start_jouer = SDL_GetTicks();
        }
        if (e->compteur == 61 && e->piece_placee[12] == 0) {
            e->afficher_loose = 1;
        }
        else if(e->compteur == 77 ){
            e->fin_jeu = 1;
        }
    }
}

void liberer_enigme2(Enigme2_2 *e) {
    SDL_FreeSurface(e->bkg);

    for (int i = 0; i < 27; i++) {
        if (e->puzzle2[i]) SDL_FreeSurface(e->puzzle2[i]);
    }

    for (int i = 0; i < 93; i++) {
        if (e->timer[i]) SDL_FreeSurface(e->timer[i]);
    }

    for (int i = 12; i < 239; i++) {
        if (e->win[i]) SDL_FreeSurface(e->win[i]);
    }

    for (int i = 0; i < 248; i++) {
        if (e->loose[i]) SDL_FreeSurface(e->loose[i]);
    }

    for (int i = 0; i < 323; i++) {
        if (e->wa9t[i]) SDL_FreeSurface(e->wa9t[i]);
    }

    for (int i = 0; i < 67; i++) {
        if (e->wa9t2[i]) SDL_FreeSurface(e->wa9t2[i]);
    }
    SDL_FreeSurface(e->gamerule);
    
}
//---------------------------------------------------------------
void init_bg3(Enigme2_3 *bg) {
    bg->bkg = IMG_Load("images/abstract-textured-backgound.jpg");
    if (bg->bkg == NULL) {
        printf("Erreur de chargement de l'image bg.png: %s\n", IMG_GetError());
    }
    bg->puzzle3[0] = IMG_Load("images/puzzle image3/p1.png");
    bg->puzzle3[1] = IMG_Load("images/puzzle image3/p2.png");
    bg->puzzle3[2] = IMG_Load("images/puzzle image3/p3.png");
    bg->puzzle3[3] = IMG_Load("images/puzzle image3/p4.png");
    bg->puzzle3[4] = IMG_Load("images/puzzle image3/p5.png");
    bg->puzzle3[5] = IMG_Load("images/puzzle image3/p6.png");
    bg->puzzle3[6] = IMG_Load("images/puzzle image3/p7.png");
    bg->puzzle3[7] = IMG_Load("images/puzzle image3/p8.png");
    bg->puzzle3[8] = IMG_Load("images/puzzle image3/p9.png");
    bg->puzzle3[9] = IMG_Load("images/puzzle image3/p10.png");
    bg->puzzle3[10] = IMG_Load("images/puzzle image3/p11.png");
    bg->puzzle3[11] = IMG_Load("images/puzzle image3/p12.png");
    bg->puzzle3[12] = IMG_Load("images/puzzle image3/p13.png");
    bg->puzzle3[13] = IMG_Load("images/puzzle image3/p14.png");
    bg->puzzle3[14] = IMG_Load("images/puzzle image3/p15.png");
    bg->puzzle3[15] = IMG_Load("images/puzzle image3/p16.png");
    bg->puzzle3[16] = IMG_Load("images/puzzle image3/p17.png");
    bg->puzzle3[17] = IMG_Load("images/puzzle image3/p18.png");
    bg->puzzle3[18] = IMG_Load("images/puzzle image3/p19.png");
    bg->puzzle3[19] = IMG_Load("images/puzzle image3/p20.png");
    bg->puzzle3[20] = IMG_Load("images/puzzle image3/p21.png");
    bg->puzzle3[21] = IMG_Load("images/puzzle image3/p22.png");
    bg->puzzle3[22] = IMG_Load("images/puzzle image3/p23.png");
    bg->puzzle3[23] = IMG_Load("images/puzzle image3/p24.png");
    bg->puzzle3[24] = IMG_Load("images/puzzle image3/p25.png");
    bg->puzzle3[25] = IMG_Load("images/puzzle image3/p11.png");
    bg->puzzle3[26] = IMG_Load("images/puzzle image3/p14.png");

    bg->pos_btn_puzzle3[0].x = 75;
    bg->pos_btn_puzzle3[0].y = 100;
    bg->pos_btn_puzzle3[0].w = bg->puzzle3[0]->w;
    bg->pos_btn_puzzle3[0].h = bg->puzzle3[0]->h;
    bg->pos_btn_puzzle3[1].x = 200;
    bg->pos_btn_puzzle3[1].y = 105;
    bg->pos_btn_puzzle3[1].w = bg->puzzle3[1]->w;
    bg->pos_btn_puzzle3[1].h = bg->puzzle3[1]->h;
    bg->pos_btn_puzzle3[2].x = 355;
    bg->pos_btn_puzzle3[2].y = 106;
    bg->pos_btn_puzzle3[2].w = bg->puzzle3[2]->w;
    bg->pos_btn_puzzle3[2].h = bg->puzzle3[2]->h;
    bg->pos_btn_puzzle3[3].x = 506;
    bg->pos_btn_puzzle3[3].y = 115;
    bg->pos_btn_puzzle3[3].w = bg->puzzle3[3]->w;
    bg->pos_btn_puzzle3[3].h = bg->puzzle3[3]->h;
    bg->pos_btn_puzzle3[4].x = 637; 
    bg->pos_btn_puzzle3[4].y = 105;   
    bg->pos_btn_puzzle3[4].w = bg->puzzle3[4]->w;
    bg->pos_btn_puzzle3[4].h = bg->puzzle3[4]->h;
    bg->pos_btn_puzzle3[5].x = 71;
    bg->pos_btn_puzzle3[5].y = 240;
    bg->pos_btn_puzzle3[5].w = bg->puzzle3[5]->w;
    bg->pos_btn_puzzle3[5].h = bg->puzzle3[5]->h;
    bg->pos_btn_puzzle3[6].x = 217;
    bg->pos_btn_puzzle3[6].y = 240;
    bg->pos_btn_puzzle3[6].w = bg->puzzle3[6]->w;
    bg->pos_btn_puzzle3[6].h = bg->puzzle3[6]->h;
    bg->pos_btn_puzzle3[7].x = 354;
    bg->pos_btn_puzzle3[7].y = 250;
    bg->pos_btn_puzzle3[7].w = bg->puzzle3[7]->w;
    bg->pos_btn_puzzle3[7].h = bg->puzzle3[7]->h;
    bg->pos_btn_puzzle3[8].x = 505;
    bg->pos_btn_puzzle3[8].y = 250;
    bg->pos_btn_puzzle3[8].w = bg->puzzle3[8]->w;
    bg->pos_btn_puzzle3[8].h = bg->puzzle3[8]->h;
    bg->pos_btn_puzzle3[9].x = 647;
    bg->pos_btn_puzzle3[9].y = 241;
    bg->pos_btn_puzzle3[9].w = bg->puzzle3[9]->w;
    bg->pos_btn_puzzle3[9].h = bg->puzzle3[9]->h;
    bg->pos_btn_puzzle3[10].x = 76;
    bg->pos_btn_puzzle3[10].y = 378;
    bg->pos_btn_puzzle3[10].w = bg->puzzle3[10]->w;
    bg->pos_btn_puzzle3[10].h = bg->puzzle3[10]->h;
    bg->pos_btn_puzzle3[11].x = 205;
    bg->pos_btn_puzzle3[11].y = 398;
    bg->pos_btn_puzzle3[11].w = bg->puzzle3[11]->w;
    bg->pos_btn_puzzle3[11].h = bg->puzzle3[11]->h;
    bg->pos_btn_puzzle3[12].x = 1100;
    bg->pos_btn_puzzle3[12].y = 100;
    bg->pos_btn_puzzle3[12].w = bg->puzzle3[12]->w;
    bg->pos_btn_puzzle3[12].h = bg->puzzle3[12]->h;
    bg->pos_btn_puzzle3[13].x = 500;
    bg->pos_btn_puzzle3[13].y = 380;
    bg->pos_btn_puzzle3[13].w = bg->puzzle3[13]->w;
    bg->pos_btn_puzzle3[13].h = bg->puzzle3[13]->h;
    bg->pos_btn_puzzle3[14].x = 621;
    bg->pos_btn_puzzle3[14].y = 388;
    bg->pos_btn_puzzle3[14].w = bg->puzzle3[14]->w;
    bg->pos_btn_puzzle3[14].h = bg->puzzle3[14]->h;
    bg->pos_btn_puzzle3[15].x = 76;
    bg->pos_btn_puzzle3[15].y = 502;
    bg->pos_btn_puzzle3[15].w = bg->puzzle3[15]->w;
    bg->pos_btn_puzzle3[15].h = bg->puzzle3[15]->h;
    bg->pos_btn_puzzle3[16].x = 205;
    bg->pos_btn_puzzle3[16].y = 514;
    bg->pos_btn_puzzle3[16].w = bg->puzzle3[16]->w;
    bg->pos_btn_puzzle3[16].h = bg->puzzle3[16]->h;
    bg->pos_btn_puzzle3[17].x = 345;
    bg->pos_btn_puzzle3[17].y = 502;
    bg->pos_btn_puzzle3[17].w = bg->puzzle3[17]->w;
    bg->pos_btn_puzzle3[17].h = bg->puzzle3[17]->h;
    bg->pos_btn_puzzle3[18].x = 500;
    bg->pos_btn_puzzle3[18].y = 507;
    bg->pos_btn_puzzle3[18].w = bg->puzzle3[18]->w;
    bg->pos_btn_puzzle3[18].h = bg->puzzle3[18]->h;
    bg->pos_btn_puzzle3[19].x = 625;
    bg->pos_btn_puzzle3[19].y = 517;
    bg->pos_btn_puzzle3[19].w = bg->puzzle3[19]->w;
    bg->pos_btn_puzzle3[19].h = bg->puzzle3[19]->h;
    bg->pos_btn_puzzle3[20].x = 75;
    bg->pos_btn_puzzle3[20].y = 635;
    bg->pos_btn_puzzle3[20].w = bg->puzzle3[20]->w;
    bg->pos_btn_puzzle3[20].h = bg->puzzle3[20]->h;
    bg->pos_btn_puzzle3[21].x = 203;
    bg->pos_btn_puzzle3[21].y = 645;
    bg->pos_btn_puzzle3[21].w = bg->puzzle3[21]->w;
    bg->pos_btn_puzzle3[21].h = bg->puzzle3[21]->h;
    bg->pos_btn_puzzle3[22].x = 345;
    bg->pos_btn_puzzle3[22].y = 642;
    bg->pos_btn_puzzle3[22].w = bg->puzzle3[22]->w;
    bg->pos_btn_puzzle3[22].h = bg->puzzle3[22]->h;
    bg->pos_btn_puzzle3[23].x = 487;
    bg->pos_btn_puzzle3[23].y = 642;
    bg->pos_btn_puzzle3[23].w = bg->puzzle3[23]->w;
    bg->pos_btn_puzzle3[23].h = bg->puzzle3[23]->h;
    bg->pos_btn_puzzle3[24].x = 628;
    bg->pos_btn_puzzle3[24].y = 636;
    bg->pos_btn_puzzle3[24].w = bg->puzzle3[24]->w;
    bg->pos_btn_puzzle3[24].h = bg->puzzle3[24]->h;
    bg->pos_btn_puzzle3[25].x = 1100;
    bg->pos_btn_puzzle3[25].y = 350;
    bg->pos_btn_puzzle3[25].w = bg->puzzle3[25]->w;
    bg->pos_btn_puzzle3[25].h = bg->puzzle3[25]->h;
    bg->pos_btn_puzzle3[26].x = 1100;
    bg->pos_btn_puzzle3[26].y = 600;
    bg->pos_btn_puzzle3[26].w = bg->puzzle3[26]->w;
    bg->pos_btn_puzzle3[26].h = bg->puzzle3[26]->h;

    bg->gamerule = IMG_Load("images/gamerule.png");

    for (int i = 0; i < 93; i++) {
        char filename[30];
        sprintf(filename, "images/timer/timer_%d.png", i + 1);
        bg->timer[i] = IMG_Load(filename);
    }

    for (int i = 12; i < 239; i++) {
        char filename[60];
        sprintf(filename, "images/win/Wii Sports _You Win_ HD Green Screen%03d.png", i);
        bg->win[i] = IMG_Load(filename);
    }

    for (int i = 0; i < 248; i++) {
        char filename[60];
        sprintf(filename, "images/loose/Wii Sports _You Lose_ Green Screen%03d.png", i+3);
        bg->loose[i] = IMG_Load(filename);
    }

    for (int i = 0; i < 323; i++) {
        char filename[30];
        sprintf(filename, "images/wa9t/p%03d.png", i);
        bg->wa9t[i] = IMG_Load(filename);
    }

    for (int i = 0; i < 67; i++) {
        char filename[30];
        sprintf(filename, "images/wa9t/p%03d.png", i);
        bg->wa9t2[i] = IMG_Load(filename);
    }

    bg->pos_timer.x = 650;
    bg->pos_timer.y = 0;
    bg->pos_win.x = 150;
    bg->pos_win.y = 200;
    bg->pos_loose.x = 170;
    bg->pos_loose.y = 135;
    bg->pos_wa9t.x = 390;
    bg->pos_wa9t.y = 437;
    bg->pos_wa9t2.x = 390;
    bg->pos_wa9t2.y = 437;
    

    bg->compteur = 1;
    bg->jouer_gagner = -1;
    bg->fin_jeu = 0;
    bg->afficher_loose = 0;
    bg->loose_i = 0; 
    bg->win_i = 12;
    bg->saved = 0; 
    bg->gamerule_start_time = SDL_GetTicks();
    bg->temps_start_jouer = SDL_GetTicks();

    if (TTF_Init() == -1) {
        printf("Erreur d'initialisation de SDL_ttf: %s\n", TTF_GetError());
        return;
    }

    bg->font = TTF_OpenFont("Pixel-Game.otf", 120);
    if (!bg->font) {
        printf("Erreur de chargement de la police: %s\n", TTF_GetError());
    }

    SDL_Color textColor = {255, 255, 255};
    bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "FIND THE PERFECT PUZZLE", textColor);
    if (!bg->surfaceTexte) {
        printf("Erreur de rendu du texte: %s\n", TTF_GetError());
    }

    bg->pos_btn_text.x = 200;
    bg->pos_btn_text.y = 950;
    bg->pos_btn_text.w = bg->surfaceTexte->w;
    bg->pos_btn_text.h = bg->surfaceTexte->h;

    bg->show_gamerule = 1;
}

void afficher_bg3(Enigme2_3 *bg, SDL_Surface *ecran) {
    if (bg->show_gamerule) {
        Uint32 wakt_tawa = SDL_GetTicks();
        if (wakt_tawa - bg->gamerule_start_time < 9000) {
            SDL_BlitSurface(bg->gamerule, NULL, ecran, NULL);
            SDL_Flip(ecran);
            return;
        } else {
            bg->show_gamerule = 0;
        }
    }
    SDL_BlitSurface(bg->bkg, NULL, ecran, NULL);
    
    static int wa9t_frame = 0;
    static int wa9t2_frame = 0;
    static int afficher_wa9t2 = 0;
    
    if (wa9t_frame < 323 && bg->wa9t[wa9t_frame]) {
        SDL_BlitSurface(bg->wa9t[wa9t_frame], NULL, ecran, &bg->pos_wa9t);
        wa9t_frame++;
    } else {
        afficher_wa9t2 = 1;
    }

    if (afficher_wa9t2 && wa9t2_frame < 323 && bg->wa9t2[wa9t2_frame]) {
        SDL_BlitSurface(bg->wa9t2[wa9t2_frame], NULL, ecran, &bg->pos_wa9t2);
        wa9t2_frame++;
    }
    
    for (int i = 0; i < 27; i++) {
        if (i == 12) continue;
        SDL_BlitSurface(bg->puzzle3[i], NULL, ecran, &bg->pos_btn_puzzle3[i]);
    }

    SDL_BlitSurface(bg->puzzle3[12], NULL, ecran, &bg->pos_btn_puzzle3[12]);

    if (bg->timer[bg->compteur])
        SDL_BlitSurface(bg->timer[bg->compteur], NULL, ecran, &bg->pos_timer);


    if (bg->jouer_gagner == 1) {
        if (bg->win_i < 239 && bg->win[bg->win_i]) {
            SDL_BlitSurface(bg->win[bg->win_i], NULL, ecran, &bg->pos_win);
            bg->win_i++;
        } else if (bg->win_i == 239) {
            bg->fin_jeu = 1;
        }  
    }  

    SDL_Color textColor = {255, 255, 255}; 
    if (bg->afficher_loose == 1) {
        bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "    GAME OVER.YOU LOST", textColor);
    }
    else if(bg->jouer_gagner == 1){
        char text[50];
        snprintf(text, sizeof(text), "    VICTORY IN %d SECONDS", bg->compteur);
        bg->surfaceTexte = TTF_RenderText_Solid(bg->font, text, textColor);
    }else {
        bg->surfaceTexte = TTF_RenderText_Solid(bg->font, "FIND THE PERFECT PUZZLE", textColor);
    }

    if (bg->surfaceTexte != NULL) {
        SDL_BlitSurface(bg->surfaceTexte, NULL, ecran, &bg->pos_btn_text);
    }

    
    if (bg->afficher_loose == 1) {
        if (bg->loose_i < 248 && bg->loose[bg->loose_i]) {
            SDL_BlitSurface(bg->loose[bg->loose_i], NULL, ecran, &bg->pos_loose);
            bg->loose_i++;
        } else if (bg->loose_i >= 248) {
            bg->afficher_loose = 0;
            bg->jouer_gagner = 0;
            bg->fin_jeu = 1;
        }
    }
}
void clickButton3(Enigme2_3 *bg, SDL_Event event) {
    static int sel = -1, offX = 0, offY = 0;

    if (bg->saved == 0) {
        bg->p12_init = bg->pos_btn_puzzle3[12];
        bg->p25_init = bg->pos_btn_puzzle3[25];
        bg->p26_init = bg->pos_btn_puzzle3[26];
        bg->saved = 1;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        for (int i = 12; i <= 26; i++) {
            if ((i >= 13 && i <= 24) || (i == 12 && bg->piece_placee[12])) continue;
            SDL_Rect r = bg->pos_btn_puzzle3[i];
            if (event.button.x >= r.x && event.button.x <= r.x + r.w &&
                event.button.y >= r.y && event.button.y <= r.y + r.h) {
                sel = i;
                offX = event.button.x - r.x;
                offY = event.button.y - r.y;
                break;
            }
        }
    } else if (event.type == SDL_MOUSEMOTION && sel != -1 && !(sel == 12 && bg->piece_placee[12])) {
        bg->pos_btn_puzzle3[sel].x = event.motion.x - offX;
        bg->pos_btn_puzzle3[sel].y = event.motion.y - offY;
    } else if (event.type == SDL_MOUSEBUTTONUP && sel != -1) {
        SDL_Rect *pos = &bg->pos_btn_puzzle3[sel];

        if (sel == 12) {
            SDL_Rect correct = {358, 378, 0, 0};
            if ((pos->x - correct.x) < 30 && (pos->y - correct.y) < 30) {
                *pos = correct;
                bg->piece_placee[12] = 1;
                bg->jouer_gagner = 1;
            } else {
                *pos = bg->p12_init;
            }
        } else if (sel == 25) {
            *pos = bg->p25_init;
            bg->piece_placee[25] = 1;
        } else if (sel == 26) {
            *pos = bg->p26_init;
            bg->piece_placee[26] = 1;
        }

        sel = -1;
    }
}
void mettre_a_jour_enigme3(Enigme2_3 *e) {
    if (e->jouer_gagner != -1) return;

    if (SDL_GetTicks() - e->temps_start_jouer >= 500) {
        if (e->compteur < 93) {
            e->compteur++;
            e->temps_start_jouer = SDL_GetTicks();
        }
        if (e->compteur == 61 && e->piece_placee[12] == 0) {
            e->afficher_loose = 1;
        }
        else if(e->compteur == 77 ){
            e->fin_jeu = 1;
        }
    }
}

void liberer_enigme3(Enigme2_3 *e) {
    SDL_FreeSurface(e->bkg);

    for (int i = 0; i < 27; i++) {
        if (e->puzzle3[i]) SDL_FreeSurface(e->puzzle3[i]);
    }

    for (int i = 0; i < 93; i++) {
        if (e->timer[i]) SDL_FreeSurface(e->timer[i]);
    }

    for (int i = 12; i < 239; i++) {
        if (e->win[i]) SDL_FreeSurface(e->win[i]);
    }

    for (int i = 0; i < 248; i++) {
        if (e->loose[i]) SDL_FreeSurface(e->loose[i]);
    }

    for (int i = 0; i < 323; i++) {
        if (e->wa9t[i]) SDL_FreeSurface(e->wa9t[i]);
    }

    for (int i = 0; i < 323; i++) {
        if (e->wa9t2[i]) SDL_FreeSurface(e->wa9t2[i]);
    }
    SDL_FreeSurface(e->gamerule);
}
