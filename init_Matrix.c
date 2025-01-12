/*
This part only fucuses on the propreties of the matrix  
    - dimentions 
    - memory allocation 
    - memory free
    - type of datas

*/


#include<stdio.h>
#include<stdlib.h>
#include "window.h"
#include "process.h"
#include "matrix.h"
#include <SDL2/SDL.h>


Matrix* initMatrix(int width, int height) {
    // checking dimentions
    if(width < 0 || height < 0) {
        printf("Invalid matrix dimentions\n");
        exit(EXIT_FAILURE);
        }
    
 // struct malloc
    Matrix* matrix = (Matrix*) malloc(height * sizeof(Matrix));
    if(matrix == NULL) {
        printf("Malloc matrix failed\n");
        exit(EXIT_FAILURE);
    }

    matrix->height = height;
    matrix->width = width;

 // matrix malloc
    matrix->matrix = (int**) malloc(height * sizeof(int*));
    // sécu malloc
    if(matrix->matrix == NULL) {
        printf("Malloc matrix failed\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0 ; i < height ; i++) {
        matrix->matrix[i] = (int*) malloc(width * sizeof(int));
        // sécu malloc
        if(matrix->matrix[i] == NULL) {
            printf("Malloc matrix failed\n");
            exit(EXIT_FAILURE);
        }
    }
     // init matrix
    for(int y = 0 ; y < height ; y++) {
        for(int x = 0 ; x < width ; x++) {
            
            matrix->matrix[y][x] = 0;
        }
    }

    return matrix;
}

void freeMatrix(Matrix* matrix) {
    if(matrix == NULL) 
        return;

    if(matrix->matrix != NULL) {
        for(int i = 0 ; i < matrix->height ; i++) {
            if(matrix->matrix[i] == NULL)
                continue;
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }
    free(matrix);
}

void emptyMatrix(Matrix* matrix) {
    if(matrix == NULL)
        return;
    for(int y = 0 ; y < matrix->height ; y++) {
        for(int x = 0 ; x < matrix->width ; x++) {
            matrix->matrix[y][x] = false;
        }
    }
}