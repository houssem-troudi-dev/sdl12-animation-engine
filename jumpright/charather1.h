#ifndef CHARATHER1_H_INCLUDED
#define CHARATHER1_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct 
{
SDL_Rect positionimage;
SDL_Surface *idleleftImages[6];
SDL_Surface *idlerightImages[6];
SDL_Surface *runleftImages[8];
SDL_Surface *runrightImages[8];
SDL_Surface *hitLeftImages[9];
SDL_Surface *hitRightImages[9];
SDL_Surface *jumpleftImages[7];
SDL_Surface *jumprightImages[7];

int count0, count1, count2, count3;

    int isJumping;
    int onGround ;
    int yVelocity;
    int gravity ;
    int jumpHeight;
    int frameJump;
    int jumpAnimCounter;
    int jumpPhase;

    int frameidleleft, frameidleright, framerunleft, framerunright;
    int frameHitLeft, frameHitRight;
    int ismoving;
    int ismovingL, ismovingR;
    int isHittingLeft, isHittingRight;
    int oldwav;
    Mix_Chunk *hitSound;
    int compteurhitleft;
    int compteurhitright;    
    Mix_Chunk *jumpsound;
    int jumpSoundPlayed;
    Mix_Chunk *runsound;
    int walkSoundPlayedleft;
    int walkSoundPlayedright;
    int firsttime;





}charathere1;


void init_charather(charathere1 *c1);
void affichercharthere1(SDL_Surface *screen, SDL_Surface *background_principale, charathere1 *c1);

void collisionavecclavier(charathere1 *c1);

void miseajourcharthere(charathere1 *c1);

void libererCharathere(charathere1 *c1, SDL_Surface *background);


#endif

