#ifndef CHARATHER1_H_INCLUDED
#define CHARATHER1_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#define THROW_ANTICIP_FRAMES   7
#define THROW_EXEC_FRAMES      6
#define THROW_RECOV_FRAMES     6
#define PROJ_FRAMES            3
#define MAX_HEALTH             3
#define MAX_DEATH_FRAMES       12
#define ANIMAL_FRAMES          4  
typedef struct {
    SDL_Surface *idleLeft[ANIMAL_FRAMES];
    SDL_Surface *idleRight[ANIMAL_FRAMES];
    SDL_Surface *moveLeft[ANIMAL_FRAMES];
    SDL_Surface *moveRight[ANIMAL_FRAMES];
    SDL_Rect position;
    int currentFrame;
    int animationSpeed;
    Uint32 lastFrameTime;
    int isMoving;
    int direction;
} Animal;
typedef struct 
{   Animal pet;
    SDL_Rect positionimage;
    SDL_Surface *idleleftImages[6];
    SDL_Surface *idlerightImages[6];
    SDL_Surface *runleftImages[8];
    SDL_Surface *runrightImages[8];
    SDL_Surface *hitLeftImages[9];
    SDL_Surface *hitRightImages[9];
    SDL_Surface *jumpleftImages[7];
    SDL_Surface *jumprightImages[7];

  
    SDL_Surface *healthImages[MAX_HEALTH];
    SDL_Surface *deathAnimation[MAX_DEATH_FRAMES];
    int health;
    int isDead;
    int deathAnimPlaying;
    int deathFrame;

    int count0, count1, count2, count3;

    int isJumping;
    int onGround;
    int yVelocity;
    int gravity;
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
    Mix_Chunk *throwSound;
    int throwSoundPlayed;
    Mix_Chunk *throwSound1;

    SDL_Surface *throwAnticipLeft[THROW_ANTICIP_FRAMES];
    SDL_Surface *throwExecLeft[THROW_EXEC_FRAMES];
    SDL_Surface *throwRecovLeft[THROW_RECOV_FRAMES];
    SDL_Surface *projFramesLeft[PROJ_FRAMES];
    SDL_Surface *throwAnticipRight[THROW_ANTICIP_FRAMES];
    SDL_Surface *throwExecRight[THROW_EXEC_FRAMES];
    SDL_Surface *throwRecovRight[THROW_RECOV_FRAMES];
    SDL_Surface *projFramesRight[PROJ_FRAMES];

    int isThrowing;
    int isThrowingLeft;
    int isThrowingRight;
    int throwPhase;      
    int throwFrame;
    Uint32 throwTimer;    

    int projActive;
    int projX, projY;
    int projDir;       
    int projFrame;
    Uint32 projTimer;
    int canThrow;
    int isSprinting;
} charathere1;

void init_charather(charathere1 *c1);
void affichercharthere1(SDL_Surface *screen, SDL_Surface *background_principale, charathere1 *c1);
void collisionavecclavier(charathere1 *c1);
void miseajourcharthere(charathere1 *c1);
void libererCharathere(charathere1 *c1, SDL_Surface *background);


void init_health_system(charathere1 *c1);
void update_health(charathere1 *c1);
void render_health(SDL_Surface *screen, charathere1 *c1);
void render_death_animation(SDL_Surface *screen, charathere1 *c1);


void init_animal(Animal *animal, charathere1 *c1);
void update_animal(Animal *animal, charathere1 *c1);
void render_animal(SDL_Surface *screen, Animal *animal);

#endif
