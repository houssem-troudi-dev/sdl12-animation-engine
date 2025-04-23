#include "header.h"

int init(SDL_Surface** screen) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("[ERROR] SDL Initialization failed: %s\n", SDL_GetError());
        return 0;
    }
    // Initialize SDL_image (required for PNG loading)
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("[ERROR] SDL_image init failed: %s\n", IMG_GetError());
        SDL_Quit();
        return 0;
    }
    if ((TTF_Init())) {
        printf("[ERROR] TTF_Init init failed: %s\n", TTF_GetError());
        SDL_Quit();
        return 0;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("[ERROR] Mix_OpenAudio failed: %s\n", Mix_GetError());
        return -1;
    }

    *screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
    if (!*screen) {
        printf("[ERROR] Video mode setup failed: %s\n", SDL_GetError());
        return 0;
    }
    return 1;
}

SDL_Surface* loadSpriteSheet(const char* path) {
    SDL_Surface* loadedImage = IMG_Load(path);
    if (!loadedImage) {
        printf("[ERROR] Failed to load image %s: %s\n", path, IMG_GetError());
        return NULL;
    }
    SDL_Surface* optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
    if (!optimizedImage) {
        printf("[ERROR] Surface conversion failed: %s\n", SDL_GetError());
        SDL_FreeSurface(loadedImage);
        return NULL;
    }
    SDL_FreeSurface(loadedImage);
    return optimizedImage;
}

void init_enemy(Enemy *m) {
    m->bg = IMG_Load("bg.png");
    m->spriteSheet1 = loadSpriteSheet("sprite_sheet1.png");
    m->spriteSheet2 = loadSpriteSheet("sprite_sheet2.png");
    m->spriteSheet3 = loadSpriteSheet("sprite_sheet3.png");
    m->spriteSheet4 = loadSpriteSheet("sprite_sheet4.png");
    m->spriteSheet5 = loadSpriteSheet("sprite_sheet5.png");

    if (!m->bg || !m->spriteSheet1 || !m->spriteSheet2|| !m->spriteSheet3|| !m->spriteSheet4|| !m->spriteSheet5) {
        printf("[ERROR] Failed to load essential resources\n");
        return;
    }
    m->bg_music = Mix_LoadMUS("walking-sound-effect.mp3");
    if (!m->bg_music) printf("[ERROR] Failed to load music: %s\n", Mix_GetError());

    m->left_boundary = 100;
    m->right_boundary = 1000;
    m->destRect.x = ( m->left_boundary+m->right_boundary) / 2;
    m->destRect.y = SCREEN_HEIGHT / 2 - FRAME_HEIGHT / 2;
    m->destRect4.x = ( m->left_boundary+m->right_boundary) / 2;
    m->destRect4.y = (SCREEN_HEIGHT / 2 - FRAME_HEIGHT / 2)-50;

    m->destRect2.x = ( (m->left_boundary+m->right_boundary) / 2)-150;
    m->destRect2.y = SCREEN_HEIGHT / 2 - FRAME_HEIGHT / 2;

    m->destRect3.x = ( (m->left_boundary+m->right_boundary) / 2)+400;
    m->destRect3.y = (SCREEN_HEIGHT / 2 - FRAME_HEIGHT / 2)+25;

    m->moving_right = 1;
    m->moving_right2 = 1;

    m->speed = 1;
}

// setupAnimations
void setupAnimation_walk_enemy(SDL_Rect spriteClips[NUM_LINES][NUM_FRAMES1]) {
    int j, i;
    for (j = 0; j < NUM_LINES; j++) {
        for (i = 0; i < NUM_FRAMES1; i++) {
            spriteClips[j][i].x = i * FRAME_WIDTH;
            spriteClips[j][i].y = j * FRAME_HEIGHT;
            spriteClips[j][i].w = FRAME_WIDTH;
            spriteClips[j][i].h = FRAME_HEIGHT;
        }
    }
}

void setupAnimation_attaque_enemy(SDL_Rect spriteClips[NUM_LINES][NUM_FRAMES2]) {
    int j, i;
    for (j = 0; j < NUM_LINES; j++) {
        for (i = 0; i < NUM_FRAMES2; i++) {
            spriteClips[j][i].x = i * FRAME_WIDTH;
            spriteClips[j][i].y = j * FRAME_HEIGHT;
            spriteClips[j][i].w = FRAME_WIDTH;
            spriteClips[j][i].h = FRAME_HEIGHT;
        }
    }
}

void setupAnimation_walk_perso(SDL_Rect spriteClips[NUM_LINES][NUM_FRAMES3]) {
    int j, i;
    for (j = 0; j < NUM_LINES; j++) {
        for (i = 0; i < NUM_FRAMES3; i++) {
            spriteClips[j][i].x = i * FRAME_WIDTH;
            spriteClips[j][i].y = j * FRAME_HEIGHT;
            spriteClips[j][i].w = FRAME_WIDTH;
            spriteClips[j][i].h = FRAME_HEIGHT;
        }
    }
}

void setupAnimation_bonus(SDL_Rect spriteClips[NUM_FRAMES4]){
    int i;
        for (i = 0; i < NUM_FRAMES4; i++) {
            spriteClips[i].x = i * FRAME_HEART;
            spriteClips[i].y = 0 * FRAME_HEART;
            spriteClips[i].w = FRAME_HEART;
            spriteClips[i].h = FRAME_HEART;
        }
}

void setupAnimation_health_bar(SDL_Rect spriteClips[NUM_FRAMES5]){
    int i;
        for (i = 0; i < NUM_FRAMES5; i++) {
            spriteClips[i].x = i * FRAME_WIDTH ;
            spriteClips[i].y = 0 * FRAME_HEIGHT2;
            spriteClips[i].w = FRAME_WIDTH;
            spriteClips[i].h = FRAME_HEIGHT2;
        }
}

//updateAnimation
void updateAnimation_walk_enemy(int* frameIndex, Uint32* lastUpdate, int image_visible) {
    if (image_visible==0){
        Uint32 now_walk = SDL_GetTicks();
        if (now_walk - *lastUpdate > FRAME_DELAY) {
            *frameIndex = (*frameIndex + 1) % NUM_FRAMES1;
            *lastUpdate = now_walk;
        }
    }
}

void updateAnimation_attaque_enemy(int* frameIndex, Uint32* lastUpdate, int *image_visible) {
    if (*image_visible==1){
        Uint32 now_walk = SDL_GetTicks();
        if (now_walk - *lastUpdate > FRAME_DELAY) {
            *frameIndex += 1;
            *lastUpdate = now_walk;
            
            if (*frameIndex >= NUM_FRAMES2) {  
                *image_visible = 0;
                *frameIndex = 0;
            }
        }
    }
}

void updateAnimation_walk_perso(int* frameIndex, Uint32* lastUpdate) {
    Uint32 now_walk = SDL_GetTicks();
    if (now_walk - *lastUpdate > FRAME_DELAY) {
        *frameIndex = (*frameIndex + 1) % NUM_FRAMES3;
        *lastUpdate = now_walk;
    }
}

void updateAnimation_bonus(int* frameIndex, Uint32* lastUpdate) {
    Uint32 now_walk = SDL_GetTicks();
    if (now_walk - *lastUpdate > FRAME_DELAY) {
        *frameIndex = (*frameIndex + 1) % NUM_FRAMES4;
        *lastUpdate = now_walk;
    }
}

void updateAnimation_health_bar(Enemy *m, int* frameIndex, Uint32* lastUpdate, int *image_visible, int *bonus) {
    if (*image_visible==1){
        Uint32 now_walk = SDL_GetTicks();
        if (now_walk - *lastUpdate > FRAME_DELAY*10) {
            *frameIndex += 1;
            *lastUpdate = now_walk;
            
            if (*frameIndex >= NUM_FRAMES5) {  
                // Make enemy disappear
                SDL_FreeSurface(m->spriteSheet1);
                m->spriteSheet1 = NULL;
                // Also make attack animation disappear
                SDL_FreeSurface(m->spriteSheet2);
                m->spriteSheet2 = NULL;                
                // Also make heath bar animation disappear
                SDL_FreeSurface(m->spriteSheet5);
                m->spriteSheet5 = NULL;

                printf("Enemy defeated!\n");
                *image_visible=0;
            }
        }
    }
    // Health restoration from bonus
    else if (*bonus==1){
        *bonus = 0;
        if (*frameIndex > 0) {  // Only decrease if not already at minimum
            *frameIndex -= 1;
        }
    }
}

// Movement
void move_character(Enemy *m, int image_visible){
    if (image_visible==0){
        if (m->moving_right) {
            m->line=0;
            m->destRect.x += m->speed;
            m->destRect4.x += m->speed;
            if (m->destRect.x >= m->right_boundary) {
                m->moving_right = 0;
            }
        } else {
            m->line=1;
            m->destRect.x -= m->speed;
            m->destRect4.x -= m->speed;
            if (m->destRect.x <= m->left_boundary) {
                m->moving_right = 1;
            }
        }
        if (m->moving_right2) {
            m->line2=0;
            m->destRect2.x += m->speed;
            if (m->destRect2.x >= m->right_boundary) {
                m->moving_right2 = 0;
            }
        } else {
            m->line2=1;
            m->destRect2.x -= m->speed;
            if (m->destRect2.x <= m->left_boundary) {
                m->moving_right2 = 1;
            }
        }
    }
    
}

// collision 
void colison_BB(Enemy *m, int *image_visible) {
    // Only process bonus if it's visible (spriteSheet3 exists)
    if (m->spriteSheet2 && m->spriteSheet1) {
        if ((m->destRect.x + FRAME_WIDTH < m->destRect2.x) ||
        (m->destRect.x > m->destRect2.x + FRAME_WIDTH) ||
        (m->destRect.y + FRAME_HEIGHT < m->destRect2.y) ||
        (m->destRect.y > m->destRect2.y + FRAME_HEIGHT)) {
            *image_visible = 0;
        } else {
            *image_visible = 1;
        }
    }
}

void colison_Bonus(Enemy *m, int *bonus) {
    // Only process bonus if it's visible (spriteSheet4 exists)
    if (m->spriteSheet4) {
        if ((m->destRect.x + FRAME_HEART < m->destRect3.x) ||
            (m->destRect.x > m->destRect3.x + FRAME_HEART) ||
            (m->destRect.y + FRAME_HEART < m->destRect3.y) ||
            (m->destRect.y > m->destRect3.y + FRAME_HEART)) {
            *bonus = 0;
        } else {
            // go to updateAnimation_health_bar
            *bonus = 1;
            // Instead of freeing, mark it as collected
            SDL_FreeSurface(m->spriteSheet4);
            m->spriteSheet4 = NULL; // Prevent use-after-free
        }
    }
}

// affichage
void render(Enemy m,SDL_Surface* screen, SDL_Surface* sprite_sheet1, SDL_Rect spriteClips1[NUM_LINES][NUM_FRAMES1], SDL_Surface* sprite_sheet2, SDL_Rect spriteClips2[NUM_LINES][NUM_FRAMES2], SDL_Surface* sprite_sheet3, SDL_Rect spriteClips3[NUM_LINES][NUM_FRAMES3], SDL_Surface* sprite_sheet4, SDL_Rect spriteClips4[NUM_FRAMES4], SDL_Surface* sprite_sheet5, SDL_Rect spriteClips5[NUM_FRAMES5], int frameIndex, int frameIndex2, int frameIndex3, int frameIndex4, int frameIndex5, int line, SDL_Rect *destRect, int line2, SDL_Rect *destRect2, SDL_Rect *destRect3, SDL_Rect *destRect4, int *image_visible) {
    
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_BlitSurface(m.bg, NULL, screen, NULL);
    SDL_BlitSurface(sprite_sheet5, &spriteClips5[frameIndex5], screen, destRect4);
    SDL_BlitSurface(sprite_sheet4, &spriteClips4[frameIndex4], screen, destRect3);
    SDL_BlitSurface(sprite_sheet3, &spriteClips3[line2][frameIndex3], screen, destRect2);
    if (*image_visible==0){
        SDL_BlitSurface(sprite_sheet1, &spriteClips1[line][frameIndex], screen, destRect);
    }
    else if (*image_visible==1){
        SDL_BlitSurface(sprite_sheet2, &spriteClips2[line][frameIndex2], screen, destRect);
    }
    SDL_Flip(screen);
}

//Music
void play_music(Mix_Music *music, int loops) {
    if (!music) {
        printf("[WARNING] Tried to play NULL music!\n");
        return;
    }
    
    if (Mix_PlayingMusic() == 0) {  // Only play if no music is playing
        Mix_PlayMusic(music, loops);
    }
}

//liberation
void cleanUp(Enemy* m) {  // Remove SDL_Surface* screen parameter
    if (m->spriteSheet1) SDL_FreeSurface(m->spriteSheet1);
    m->spriteSheet1 = NULL;
    if (m->spriteSheet2) SDL_FreeSurface(m->spriteSheet2);
    m->spriteSheet2= NULL;
    if (m->spriteSheet3) SDL_FreeSurface(m->spriteSheet3);
    m->spriteSheet3= NULL;
    if (m->spriteSheet4) SDL_FreeSurface(m->spriteSheet4);
    m->spriteSheet4= NULL;
    if (m->spriteSheet5) SDL_FreeSurface(m->spriteSheet5);
    m->spriteSheet5= NULL;
    if (m->bg) SDL_FreeSurface(m->bg);
    m->bg= NULL;
    if (m->bg_music) Mix_FreeMusic(m->bg_music);
    m->bg_music=NULL;
    // Do not free the screen surface here
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();  
    SDL_Quit();
}
