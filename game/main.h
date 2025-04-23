#ifndef MAIN_H
#define MAIN_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>

typedef struct {
    SDL_Rect camera;
    SDL_Rect screen_area;
    bool scroll_left;
    bool scroll_right;
    bool jump_key_held;
    int jump_state;
} ScreenView;

typedef struct {
    SDL_Surface* image;
    SDL_Rect position;
} FallingObject;

typedef struct {
    SDL_Surface* frames[3];
    int current_frame;
    int frame_counter;
    SDL_Rect position;
    bool is_active;
} Bullet;

#define MAX_BULLETS 99

typedef struct {
    SDL_Surface* frames[5];
    SDL_Rect position;
    int current_frame;
    int frame_counter;
    int frame_delay;
    int state;
    int animation_speed;
} LaserTrap;

#define MAX_LASER_TRAPS 6

typedef struct {
    SDL_Surface* frames[8];
    SDL_Rect positions[8];
    int current_frame;
    int frame_counter;
    int frame_delay;
    int base_y;
} LavaAnimation;

typedef struct {
    SDL_Surface* image;
    SDL_Surface* background1;
    SDL_Surface* background2;
    int current_level;
    int level1_width;
    
    ScreenView view1;
    ScreenView view2;
    int is_multiplayer;
    int screen_width;
    int screen_height;
    Uint32 start_time;
    Uint32 current_time;
    SDL_Surface* time_text;
    TTF_Font* font;
    int serial_fd;
    int serial_left_pressed;
    int serial_right_pressed;
    FallingObject falling_object;
    
    SDL_Rect gun_position;
    Bullet bullets[MAX_BULLETS];
    int fire_timer;
    int fire_delay;
    
    LaserTrap laser_traps[MAX_LASER_TRAPS];
    LavaAnimation lava;
    
    SDL_Surface* eye_frames[3];
    SDL_Rect eye_position1;
    SDL_Rect eye_position2;
    SDL_Rect eye_position3;
    int current_eye_frame;
    int eye_frame_counter;
    int eye_frame_delay;

    // Text box guide fields
    SDL_Surface* textboxes[3];
    int current_textbox;
    bool show_textboxes;
} Background;

void initBackground(Background* bg, const char* imagePath, int screenW, int screenH);
void handleInput(Background* bg, SDL_Event* event);
void updateBackground(Background* bg, int scroll_speed);
void updateTimer(Background* bg);
void renderBackground(Background* bg, SDL_Surface* screen);
void freeBackground(Background* bg);

#endif
