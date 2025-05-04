#include "header.h"

int main() {
    Enemy enemy;
    SDL_Surface* screen = NULL;
    
    if (!init(&screen)) return -1;
    init_enemy(&enemy);
    // Vérification : toutes les surfaces sont-elles bien chargées ?
    if (!enemy.bg || !enemy.spriteSheet1 || !screen) {
        printf("[FATAL] One or more critical resources failed to load. Exiting.\n");
        return -1;
    }
  
    int frameIndex = 0;
    Uint32 lastUpdate = 0;

    int frameIndex2 = 0;
    Uint32 lastUpdate2 = 0;

    int frameIndex3 = 0;
    Uint32 lastUpdate3 = 0;

    int frameIndex4 = 0;
    Uint32 lastUpdate4 = 0;
    
    int frameIndex5 = 1;
    Uint32 lastUpdate5 = 0;

    int image_visible = 0;
    int bonus =0;
    int quitter = 0;
    
    play_music(enemy.bg_music, -1);
    setupAnimation_walk_enemy(enemy.spriteClips1);
    setupAnimation_attaque_enemy(enemy.spriteClips2);
    setupAnimation_walk_perso(enemy.spriteClips3);
    setupAnimation_bonus(enemy.spriteClips4);
    setupAnimation_health_bar(enemy.spriteClips5);
    
    SDL_Event event;
    while (!quitter) {
    	render(enemy,screen, enemy.spriteSheet1, enemy.spriteClips1 , enemy.spriteSheet2, enemy.spriteClips2, enemy.spriteSheet3, enemy.spriteClips3, enemy.spriteSheet4, enemy.spriteClips4, enemy.spriteSheet5, enemy.spriteClips5, frameIndex, frameIndex2, frameIndex3, frameIndex4, frameIndex5, enemy.line, &enemy.destRect, enemy.line2, &enemy.destRect2, &enemy.destRect3, &enemy.destRect4, &image_visible);
        updateAnimation_walk_enemy(&frameIndex, &lastUpdate,image_visible);
        updateAnimation_attaque_enemy(&frameIndex2, &lastUpdate2, &image_visible);
        updateAnimation_walk_perso(&frameIndex3, &lastUpdate3);
        updateAnimation_bonus(&frameIndex4, &lastUpdate4);
        while (SDL_PollEvent(&event)){
            switch (event.type) 
            {
                case SDL_QUIT:
                    quitter = 1;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) 
                        quitter = 1;
                    break;
            }
        }
        colison_BB(&enemy, &image_visible);
        colison_Bonus(&enemy,&bonus);
        updateAnimation_health_bar(&enemy,&frameIndex5, &lastUpdate5, &image_visible, &bonus);
        move_character(&enemy,image_visible);
        SDL_Delay(20);   
    }
    cleanUp(&enemy);
    return 0;
}
