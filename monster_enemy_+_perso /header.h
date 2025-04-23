#ifndef HEADER_H
#define HEADER_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

// Déclaration des constantes avec #define
#define SCREEN_WIDTH 1300
#define SCREEN_HEIGHT 650

#define FRAME_WIDTH 100
#define FRAME_HEIGHT 100
#define FRAME_HEIGHT2 50
#define FRAME_HEART 60

#define NUM_FRAMES1 8
#define NUM_FRAMES2 3
#define NUM_FRAMES3 4
#define NUM_FRAMES4 10
#define NUM_FRAMES5 4
#define NUM_LINES 2

#define FRAME_DELAY 200

// Structure Enemy
typedef struct {
    SDL_Surface *bg;
    Mix_Music *bg_music;
    //enemy
    SDL_Surface* spriteSheet1;
    SDL_Rect spriteClips1[NUM_LINES][NUM_FRAMES1];
    SDL_Surface* spriteSheet2;
    SDL_Rect spriteClips2[NUM_LINES][NUM_FRAMES2];
    SDL_Rect destRect;
    int line;
    int moving_right;
    //perso
    SDL_Surface* spriteSheet3;
    SDL_Rect spriteClips3[NUM_LINES][NUM_FRAMES3];
    SDL_Rect destRect2;
    int line2;
    int moving_right2;
    //bonus
    SDL_Surface* spriteSheet4;
    SDL_Rect spriteClips4[NUM_FRAMES4];
    SDL_Rect destRect3;
    //health bar
    SDL_Surface* spriteSheet5;
    SDL_Rect spriteClips5[NUM_FRAMES5];
    SDL_Rect destRect4;    
    //commun
    int speed;
    int left_boundary;
    int right_boundary;
} Enemy;


// initialisation
int init(SDL_Surface** screen);
SDL_Surface* loadSpriteSheet(const char* path);
void init_enemy(Enemy *m);
void play_music(Mix_Music *music, int loops);

//Enemy
void setupAnimation_walk_enemy(SDL_Rect spriteClips[NUM_LINES][NUM_FRAMES1]);
void setupAnimation_attaque_enemy(SDL_Rect spriteClips[NUM_LINES][NUM_FRAMES2]);

void updateAnimation_walk_enemy(int* frameIndex, Uint32* lastUpdate, int image_visible);
void updateAnimation_attaque_enemy(int* frameIndex, Uint32* lastUpdate, int *image_visible);
//perso
void setupAnimation_walk_perso(SDL_Rect spriteClips[NUM_LINES][NUM_FRAMES3]);
void updateAnimation_walk_perso(int* frameIndex, Uint32* lastUpdate);
//bonus
void setupAnimation_bonus(SDL_Rect spriteClips[NUM_FRAMES4]);
void updateAnimation_bonus(int* frameIndex, Uint32* lastUpdate);
//health bar
void setupAnimation_health_bar(SDL_Rect spriteClips[NUM_FRAMES5]);
void updateAnimation_health_bar(Enemy *m,int* frameIndex, Uint32* lastUpdate, int *image_visible, int *bonus);
//affichage
void render(Enemy m,SDL_Surface* screen, SDL_Surface* sprite_sheet1, SDL_Rect spriteClips1[NUM_LINES][NUM_FRAMES1], SDL_Surface* sprite_sheet2, SDL_Rect spriteClips2[NUM_LINES][NUM_FRAMES2], SDL_Surface* sprite_sheet3, SDL_Rect spriteClips3[NUM_LINES][NUM_FRAMES3], SDL_Surface* sprite_sheet4, SDL_Rect spriteClips4[NUM_FRAMES4], SDL_Surface* sprite_sheet5, SDL_Rect spriteClips5[NUM_FRAMES5], int frameIndex, int frameIndex2, int frameIndex3, int frameIndex4, int frameIndex5, int line, SDL_Rect *destRect, int line2, SDL_Rect *destRect2, SDL_Rect *destRect3, SDL_Rect *destRect4, int *image_visible);
//colssion
void colison_BB(Enemy *m, int *image_visible);
void colison_Bonus(Enemy *m, int *bonus);
//deplacement
void move_character(Enemy *m, int image_visible);
//liberatiion memoire
void cleanUp(Enemy* m);

#endif
