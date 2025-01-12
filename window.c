/*
This part only focuses on the window where the game will be displayed. 

*/

#include<stdio.h>
#include<stdlib.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "colors.h"
#include "matrix.h"
#include "process.h"


void draw_filled_rectangle(SDL_Renderer *renderer, int x, int y, int width, int height, int colorID) {
    // Define color of a square (light brown)
    SDL_SetRenderDrawColor(renderer, colors[colorID][0], colors[colorID][1], colors[colorID][2], 255); // (R, G, B, A)
    
    // dimention of a square 
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    
    // Draw square
    SDL_RenderFillRect(renderer, &rect);
}

void dispMatrix(Matrix* matrix, SDL_Renderer* renderer, bool editing, int brushColor) {
    u_char tone = editing? 200: 255;
    SDL_SetRenderDrawColor(renderer, tone, tone, tone, 255); // white backgroud
    SDL_RenderClear(renderer);
    
    for(int y = 0 ; y < matrix->height ; y++) {
         for(int x = 0 ; x < matrix->width ; x++) {
            if(matrix->matrix[y][x])
                draw_filled_rectangle(renderer, x*GRAIN_SIZE, y*GRAIN_SIZE, GRAIN_SIZE, GRAIN_SIZE, brushColor);
        }
    }
    // update renderer
    SDL_RenderPresent(renderer);
}

void initSDL(SDL_Window** window, SDL_Renderer** renderer) {
    const int WINDOW_WIDTH = WIDTH * GRAIN_SIZE;
    const int WINDOW_HEIGHT = HEIGHT * GRAIN_SIZE;

    // SDL init
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Error durring SDL initialisation : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // window creation 
    *window = SDL_CreateWindow("Sand Sim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!*window) {
        SDL_Log("Error during window creation : %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    // renderer creation 
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!*renderer) {
        SDL_Log("Error durring renderer creation  : %s", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}
