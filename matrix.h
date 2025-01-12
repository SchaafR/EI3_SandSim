 #ifndef _MATRIX_H_
 #define _MATRIX_H_
 
 // variables for the window

#define HEIGHT 200
#define WIDTH 170
#define GRAIN_SIZE 4 // in pixel
#define REQ_FPS 60


typedef struct Matrix_ {
    int ** matrix;
    int height, width;
} Matrix;

//for matrix init
Matrix* initMatrix(int width, int height);
void freeMatrix(Matrix* matrix); 
void emptyMatrix(Matrix* matrix);

#endif