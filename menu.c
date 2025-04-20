#include "menu.h"









void init_menu(Menu *menu){


menu->background_principale=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/background_principale1.png");
if(menu->background_principale==NULL){
     printf("error load background principale");
}
//button jouer**********************************************************
menu->jouer_btn[0]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/jouer0.png");
if (menu->jouer_btn[0] == NULL) {
    printf("Erreur chargement jouer0.png : %s\n", IMG_GetError());
}
menu->jouer_btn[1]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/jouer1.png");
if (menu->jouer_btn[1] == NULL) {
    printf("Erreur chargement jouer0.png : %s\n", IMG_GetError());
}
menu->posbutton_jouer.x=0;
menu->posbutton_jouer.y=100;
menu->posbutton_jouer.w=menu->jouer_btn[0]->w;
menu->posbutton_jouer.h=menu->jouer_btn[0]->h;
//button option**********************************************************
menu->option_btn[0]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/option0.png");
if (menu->option_btn[0] == NULL) {
    printf("Erreur chargement option0.png : %s\n", IMG_GetError());
}
menu->option_btn[1]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/option1.png");
if (menu->option_btn[1] == NULL) {
    printf("Erreur chargement option0.png : %s\n", IMG_GetError());
}
menu->posbutton_option.x=0;
menu->posbutton_option.y=320;
menu->posbutton_option.w=menu->option_btn[0]->w;
menu->posbutton_option.h=menu->option_btn[0]->h;
//button meilleur**********************************************************
menu->meilleur_btn[0]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/meilleur0.png");
if (menu->meilleur_btn[0] == NULL) {
    printf("Erreur chargement meilleur0.png : %s\n", IMG_GetError());
}
menu->meilleur_btn[1]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/meilleur1.png");
if (menu->meilleur_btn[1] == NULL) {
    printf("Erreur chargement meilleur0.png : %s\n", IMG_GetError());
}
menu->posbutton_meilleur.x=0;
menu->posbutton_meilleur.y=570;
menu->posbutton_meilleur.w=menu->meilleur_btn[0]->w;
menu->posbutton_meilleur.h=menu->meilleur_btn[0]->h;
//button histoire**********************************************************
menu->histoire_btn[0]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/histoire0.png");
if (menu->histoire_btn[0] == NULL) {
    printf("Erreur chargement histoire0.png : %s\n", IMG_GetError());
}
menu->histoire_btn[1]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/histoire1.png");
if (menu->histoire_btn[1] == NULL) {
    printf("Erreur chargement histoire1.png : %s\n", IMG_GetError());
}
menu->posbutton_histoire.x=1495;
menu->posbutton_histoire.y=235;
menu->posbutton_histoire.w=menu->histoire_btn[0]->w;
menu->posbutton_histoire.h=menu->histoire_btn[0]->h;
//button quit**********************************************************
menu->quit_btn[0]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/quit0.png");
if (menu->quit_btn[0] == NULL) {
    printf("Erreur chargement quit0.png : %s\n", IMG_GetError());
}
menu->quit_btn[1]=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/quit1.png");
if (menu->quit_btn[1] == NULL) {
    printf("Erreur chargement quit0.png : %s\n", IMG_GetError());
}
menu->posbutton_quit.x=0;
menu->posbutton_quit.y=800;
menu->posbutton_quit.w=menu->quit_btn[0]->w;
menu->posbutton_quit.h=menu->quit_btn[0]->h;


menu->music= Mix_LoadMUS("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/game_start.mp3");
menu->font=TTF_OpenFont("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/BrownieStencil-8O8MJ.ttf",80);
if (menu->title == NULL) {
        printf("Erreur rendu texte : %s\n", TTF_GetError());
    }
menu->fontColor.r=255;
menu->fontColor.g=255;
menu->fontColor.b=255;
menu->title=TTF_RenderText_Blended(menu->font,"welcome to pixel prison",menu->fontColor);
menu->postext.x=500;
menu->postext.y=10;


menu->logo=IMG_Load("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/logo.png");
if(menu->logo==NULL){

     printf("error load logo");
}
menu->logo_pos.x=1694;
menu->logo_pos.y=20;
menu->sonclick = Mix_LoadWAV("/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/click.wav");
if (!menu->sonclick) {
    printf("Failed to load sound: %s\n", Mix_GetError());
    return;
}
//Mix_VolumeChunk(menu->sonclick, MIX_MAX_VOLUME);
      menu->gifPosition.x=760;
      menu->gifPosition.y=165;
      menu->count = 0;
      for (int i = 0; i < 100; ++i) {
        char filename[256];
        sprintf(filename, "/home/king/Documents/GitHub/sdl12-animation-engine/assets/assets_menu_principale/gif/image%d.png", i + 1); // Assuming images are named image1.png, image2.png, etc.
        
        // Load the image and check if successful
        menu->images[menu->count] = IMG_Load(filename);
        if (menu->images[menu->count] != NULL) {
            menu->count++;
        }
    }































}




void afficher_menu(Menu *m,SDL_Surface *Fenetre){



SDL_BlitSurface(m->background_principale,NULL,Fenetre,NULL);
if(colision_avec_souris(m->posbutton_jouer)==0&&m->btn_select!=1)
{
SDL_BlitSurface(m->jouer_btn[0],NULL,Fenetre,&m->posbutton_jouer);
}
else{SDL_BlitSurface(m->jouer_btn[1],NULL,Fenetre,&m->posbutton_jouer);}
//****************************************************************************
if(colision_avec_souris(m->posbutton_option)==0&&m->btn_select!=2)
     {SDL_BlitSurface(m->option_btn[0],NULL,Fenetre,&m->posbutton_option);}
else
     {SDL_BlitSurface(m->option_btn[1],NULL,Fenetre,&m->posbutton_option);}
//***********************************************************************************
if(colision_avec_souris(m->posbutton_meilleur)==0&&m->btn_select!=3)
     {SDL_BlitSurface(m->meilleur_btn[0],NULL,Fenetre,&m->posbutton_meilleur);}
else
     {SDL_BlitSurface(m->meilleur_btn[1],NULL,Fenetre,&m->posbutton_meilleur);}
//*******************************************************************************
if(colision_avec_souris(m->posbutton_histoire)==0&&m->btn_select!=4)
     {SDL_BlitSurface(m->histoire_btn[0],NULL,Fenetre,&m->posbutton_histoire);}
else
     {SDL_BlitSurface(m->histoire_btn[1],NULL,Fenetre,&m->posbutton_histoire);}
//*****************************************************************************
if(colision_avec_souris(m->posbutton_quit)==0&&m->btn_select!=5)
     {SDL_BlitSurface(m->quit_btn[0],NULL,Fenetre,&m->posbutton_quit);}
else
     {SDL_BlitSurface(m->quit_btn[1],NULL,Fenetre,&m->posbutton_quit);}



      SDL_BlitSurface(m->title,NULL,Fenetre,&m->postext);
      SDL_BlitSurface(m->logo,NULL,Fenetre,&m->logo_pos);
      SDL_BlitSurface(m->images[m->frame], NULL, Fenetre, &m->gifPosition);
      SDL_Delay(m->FRAME_DELAY);
      m->frame = (m->frame + 1) % m->count;
   
}















int colision_avec_souris(SDL_Rect pos_btn){

int x_souris,y_souris;
SDL_GetMouseState(&x_souris,&y_souris) ;
if((x_souris>pos_btn.x)&&(x_souris<pos_btn.x+pos_btn.w)&&(y_souris>pos_btn.y)&&y_souris<pos_btn.y+pos_btn.h){
     return 1;
}
else {
     return 0;
}



}



void misajour_menu(Menu *m) {
       int prev_btn_select = 0; 

    if (colision_avec_souris(m->posbutton_jouer) == 1) {
        if (m->btn_select != 1) { 
            m->btn_select = 1;
            Mix_PlayChannel(-1, m->sonclick, 0); 
        }
    } else if (colision_avec_souris(m->posbutton_option) == 1) {
        if (m->btn_select != 2) {
            m->btn_select = 2;
            Mix_PlayChannel(-1, m->sonclick, 0);
        }
    } else if (colision_avec_souris(m->posbutton_meilleur) == 1) {
        if (m->btn_select != 3) { 
            m->btn_select = 3;
            Mix_PlayChannel(-1, m->sonclick, 0);
        }
    } else if (colision_avec_souris(m->posbutton_histoire) == 1) {
        if (m->btn_select != 4) { 
            m->btn_select = 4;
           Mix_PlayChannel(-1, m->sonclick, 0);
        }
    } else if (colision_avec_souris(m->posbutton_quit) == 1) {
        if (m->btn_select != 5) { 
            m->btn_select = 5;
           Mix_PlayChannel(-1, m->sonclick, 0);
        }
    } else {
        m->btn_select = 0;
    }

    prev_btn_select = m->btn_select;
}

void handle_menu_events(SDL_Event event, int *quitter, int *indice_ecran, Menu *menu)
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                *quitter = 1;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (menu->btn_select == 5)
                    {
                        *quitter = 1;
                    }

                    if (menu->btn_select == 1)
                    {
                        *indice_ecran = 1;
                    }

                    if (menu->btn_select == 2)
                    {
                        *indice_ecran = 2;
                    }

                    if (menu->btn_select == 3)
                    {
                        *indice_ecran = 3;
                    }

                    if (menu->btn_select == 4)
                    {
                        *indice_ecran = 4;
                    }
                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_DOWN)
                {
                    menu->btn_select++;
                    if (menu->btn_select > 5)
                        menu->btn_select = 1;
                }

                if (event.key.keysym.sym == SDLK_UP)
                {
                    menu->btn_select--;
                    if (menu->btn_select < 1)
                        menu->btn_select = 5;
                }

                if (event.key.keysym.sym == SDLK_j ||
                    (menu->btn_select == 1 && event.key.keysym.sym == SDLK_RETURN))
                {
                    *indice_ecran = 1;
                }

                if (event.key.keysym.sym == SDLK_o)
                {
                    *indice_ecran = 2;
                }

                if (event.key.keysym.sym == SDLK_m)
                {
                    *indice_ecran = 3;
                }

                if (event.key.keysym.sym == SDLK_h)
                {
                    *indice_ecran = 4;
                }

                if (event.key.keysym.sym == SDLK_q)
                {
                    *quitter = 1;
                }
                break;

            default:
                break;
        }
    }
}


































































