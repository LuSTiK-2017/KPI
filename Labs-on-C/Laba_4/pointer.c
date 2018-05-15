#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "validation.h"
#include "pointer.h"

#define ROW_MATRIX 10
#define COLUMN_MATRIX 2
#define X 0
#define Y 1

// funktion of filling the massive
int** input_coord(int *r)
{
    srand(time(0));

    int **matrix = (int **)malloc(ROW_MATRIX * sizeof(int *));
    for (int i = 0; i < ROW_MATRIX; i++)
         matrix[i] = (int *)malloc(COLUMN_MATRIX * sizeof(int));

    printf("1 - RANDOM FILLING\n");
    printf("2 - KEYBOARD FILLING\n");

    while(1) {
        int add_arr;
        add_arr = validation_int();
        
        switch (add_arr) {
            case 1:
                for (int i = 0; i < ROW_MATRIX; i++) {
                    printf("DOT [%d]: ", i + 1);
                    matrix[i][X] = (-2 * (int)*r) + rand() % (4 * (int)*r);
                    matrix[i][Y] = -20 + rand() % 40;
                    printf("(%d, %d)\n", matrix[i][X], matrix[i][Y]);
                }
                break;
            case 2:
                for (int i = 0; i < ROW_MATRIX; i++) {
                    printf("X[%d]: ", i + 1);
                    matrix[i][X] = validation_int();
                    printf("Y[%d]: ", i + 1);
                    matrix[i][Y] = validation_int();
                }
                break;
            default:
                printf("Not corect data!");
            }
    
            break;
    }

    return matrix;
}

// Culculate distance
float distance(int *x, int *y)
{
    return sqrt(*x * *x + *y * *y);
}

// Count the number of points
void circle()
{
    printf("Input radius of circle: ");
    int r = validation_int();

    int **coords = input_coord(&r);

    float d;
    int count = 0;
    for (int i = 0; i < ROW_MATRIX; i++) {
        d = distance(&coords[i][X], &coords[i][Y]);
        if (d < r)
            count++;
        printf("D[%d] = %.2f\n", i + 1, d);
    }

    printf("Number of dot in circle: %d", count);

    for (int i = 0; i < COLUMN_MATRIX; i++) {
        free(coords[i]);
    }
    free(coords);
}