/* Дано матрицю А розмірності m*n. Упорядкувати матрицю за зростан-
ням елементів у кожному стовпці. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "validation.h"

// Creating dinamic matrix
int** create_matrix(int row, int column)
{
    int **matrix = (int **)malloc(row * sizeof(int *));
    
    if (matrix == NULL)
    {
        return NULL;
    }
    
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc(column * sizeof(int));
        if (matrix[i] == NULL)
        {
            return NULL;
        }
    }

    return matrix;
}

// Filling matrix
void filling_matrix(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = -20 + rand() % 40;
}

// Print matrix
void print_matrix(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%4d ", matrix[i][j]);
        printf("\n");
    }
}

// Sorting column of matrix
void sort_matrix(int **matrix, int row, int column)
{
    int temp;
    for (int k = 0; k < column; k++)
        for (int i = 0; i < row - 1; i++)
            for  (int j = 0; j < row - i - 1; j++)
            {
                if (matrix[j + 1][k] < matrix[j][k])
                {
                    temp = matrix[j + 1][k];
                    matrix[j + 1][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
            }
}

int dinamic()
{
    srand(time(0));

    unsigned int row;
    printf("Enter row: ");
    row = validation_int();

    unsigned int column;
    printf("Enter colum: ");
    column = validation_int();

    int **matrix = create_matrix(row, column);

    if (matrix == NULL)
    {
        printf("ERROR!!!!!!");
        return -1;
    }

    filling_matrix(matrix, row, column);
    printf("\n------------------START MATRIX-------------------------\n");
    print_matrix(matrix, row, column);
    printf("\n------------------SORTING COLUMN-------------------------\n");
    sort_matrix(matrix, row, column);
    print_matrix(matrix, row, column);

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}