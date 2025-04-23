#include "main.h"
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "serie.h"

volatile sig_atomic_t running = 1;

void handle_signal(int sig) {
    running = 0;
}

int main() {
    const int SCREEN_W = 1600;
    const int SCREEN_H = 700;
    const int SCROLL_SPEED = 5;
    
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }
    
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);
    if (!screen) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    
    Background bg;
    initBackground(&bg, "background_1.png", SCREEN_W, SCREEN_H);
    
    bg.serial_fd = serialport_init("/dev/ttyACM0", 9600);
    if (bg.serial_fd == -1) {
        fprintf(stderr, "Warning: Could not initialize serial port\n");
    }
    
    SDL_Event event;
    Uint32 last_time = SDL_GetTicks();
    
    while (running) {
        bg.serial_left_pressed = 0;
        bg.serial_right_pressed = 0;
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
            handleInput(&bg, &event);
        }
        
        if(bg.serial_fd != -1) {
            char buf[10];
            if(serialport_read_until(bg.serial_fd, buf, '\n', 9, 20) == 0) {
                buf[strcspn(buf, "\r\n")] = 0;
                
                if(strcmp(buf, "LD") == 0 || strcmp(buf, "LH") == 0) {
                    bg.serial_left_pressed = 1;
                }
                else if(strcmp(buf, "LU") == 0) {
                    bg.serial_left_pressed = 0;
                }
                else if(strcmp(buf, "RD") == 0 || strcmp(buf, "RH") == 0) {
                    bg.serial_right_pressed = 1;
                }
                else if(strcmp(buf, "RU") == 0) {
                    bg.serial_right_pressed = 0;
                }
            }
        }
        
        Uint32 current_time = SDL_GetTicks();
        if (current_time - last_time > 16) {  // ~60 FPS
            updateBackground(&bg, SCROLL_SPEED);
            updateTimer(&bg);
            renderBackground(&bg, screen);
            SDL_Flip(screen);
            last_time = current_time;
        }
        else {
            SDL_Delay(1);
        }
    }

    if (bg.serial_fd != -1) {
        serialport_close(bg.serial_fd);
    }
    
    freeBackground(&bg);
    SDL_Quit();
    return 0;
}
