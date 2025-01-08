// /*

// this is where the algorithm behind the sand_sim is implemented

// */

#include<stdio.h>
#include<stdlib.h>
#include <SDL2/SDL.h>
#include <time.h>
#include "window.h"
#include "process.h"




//generation of a pseudo random integer betwen 1 and 0
int generate_Num(void) {
    srand(time(NULL));
    int random_number = rand() % 2;
    return random_number;
}


void simulate_sandfall(Matrix *m) {
    
    for (int i = m->height - 2; i >= 0; i--) { // browse for bottom to top 
        for (int j = 0; j < m->width; j++) {
            if (m->matrix[i][j] == 1) { // Check if particule is sand 
                if (m->matrix[i + 1][j] == 0) {
                    // grain fall directly 
                    m->matrix[i + 1][j] = 1;
                    m->matrix[i][j] = 0;
                } else if (j > 0 && m->matrix[i + 1][j - 1] == 0 ) {
                    // fall to the left 
                    m->matrix[i + 1][j - 1] = 1;
                    m->matrix[i][j] = 0;
                } else if (j < m->width - 1 && m->matrix[i + 1][j + 1] == 0 ) {
                    // Fall to the right 
                    m->matrix[i + 1][j + 1] = 1;
                    m->matrix[i][j] = 0;
                }  
                // accumulation 
            }
        }
    }
}

void simulate_waterfall(Matrix *m) {
    for (int i = m->height - 2; i >= 0; i--) { // browse for bottom to top 
        for (int j = 0; j < m->width; j++) {
            if (m->matrix[i][j] == 1) { // Check if particule is sand
                if (m->matrix[i + 1][j] == 0) {
                    // grain fall directly 
                    m->matrix[i + 1][j] = 1;
                    m->matrix[i][j] = 0;
                } else if (j > 0 && m->matrix[i][j - 1] == 0 ) {
                        m->matrix[i][j - 1] = 1;
                        m->matrix[i][j] = 0;
                        j--; // grain falls to the left
                       
                    } else if (j < m->width - 1 && m->matrix[i][j + 1] == 0 ) {
                        m->matrix[i][j + 1] = 1;
                        m->matrix[i][j] = 0;
                        j++; // grain falls to the right
                       
                    }
                
                // accumulation
                
            }
        }
    }
}


void simulate_wetsandfall(Matrix *m) {
    
    for (int i = m->height - 2; i >= 0; i--) { // browse for bottom to top 
        for (int j = 0; j < m->width; j++) {
            if (m->matrix[i][j] == 1) { // Check if particule is sand
                if (m->matrix[i + 1][j] == 0) {
                    // grain fall directly 
                    m->matrix[i + 1][j] = 1;
                    m->matrix[i][j] = 0;
                } else if (j > 0 && m->matrix[i + 1][j - 1] == 0 && generate_Num() == 0  ) { //create the wet effect
                    // grain falls to the left
                    m->matrix[i + 1][j - 1] = 1;
                    m->matrix[i][j] = 0;
                } else if (j < m->width - 1 && m->matrix[i + 1][j + 1] == 0 && generate_Num() == 0) { //create the wet effect
                    // Lgrain falls to the right
                    m->matrix[i + 1][j + 1] = 1;
                    m->matrix[i][j] = 0;
                }  
                // accumulation
            }
        }
    }
}