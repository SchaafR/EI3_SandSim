// For SDL

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include<stdbool.h>
#include"matrix.h"
#include <SDL2/SDL.h>


void draw_filled_rectangle(SDL_Renderer *renderer, int x, int y, int width, int height, int colorsID);
void dispMatrix(Matrix* matrix, SDL_Renderer* renderer, bool editing, int brushColor);
void initSDL(SDL_Window** window, SDL_Renderer** renderer);

#endif