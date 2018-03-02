#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

// Function for clear screen
void clrscr() { 
    char a[80]; 
    printf("\033[2J"); /* Clear the entire screen. */ 
    printf("\033[0;0f"); /* Move cursor to the top left hand corner */ 
}

// Function for check input value on integer
int validation_int() {
    char input_data[65];
    float number;

    int iscontinue = 1;
    while (iscontinue) {
        int err = 1;
        scanf("%s", input_data);

        if ((!isdigit(input_data[0])) && !(input_data[0] == '-'))
            err = 0;

        for(int i = 1; input_data[i] != '\0'; i++)
            if ((!isdigit(input_data[i]))) {
                err = 0;
                break;
            }
        
        if (err)
            break;
        else
            printf("Invalid error! Try agan: ");
        }

    number = atoi(input_data);
    return number;
}    

// Function for check input value on float
float validation_float() {
    char input_data[65];
    float number;

    int iscontinue = 1;
    while (iscontinue) {
        int err = 1;
        scanf("%s", input_data);
        
        if ((!isdigit(input_data[0])) && !(input_data[0] == '-'))
            err = 0;
        
        for(int i = 1; input_data[i] != '\0'; i++)
            if ((!isdigit(input_data[i])) && (input_data[i] != '.')) {
                err = 0;
                break;
            }

        if (err)
            break;
        else
            printf("Invalid error! Try agan: ");
        }

    number = atof(input_data);
    return number;
}  

// Function for check range and type
int validation_int_range(int x, int  y) {
    int num = validation_int();
    while(num < x || num > y) {
        printf("Out of range! Try again: \n");
        fflush(stdin);
        num = validation_int();
    }
    
    return num;
}

// Function for check range and type
float validation_float_range(int x, int  y) {
    float num = validation_float();
    while(num < x || num > y) {
        printf("Out of range! Try again: \n");
        fflush(stdin);
        num = validation_float();
    }
    
    return num;
}

// Sorted our one-dimensional array
void BubbleSort(float Arr[], int n) {
    float tmp;

    for (int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if (Arr[j] > Arr[j + 1]) {
                tmp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = tmp;
            }

    printf("SORT ARRAY: {");
    for (int i = 0; i < n; i++) {
        if (i < n - 1)
            printf("%.2f, ", Arr[i]);
        else
            printf("%.2f}\n", Arr[i]);
    }
}

// Work with one-dimensional array
void task_1() {
    int n;
    printf("Input size of array (bigger 0): ");
    n = validation_int_range(1, INT_MAX);
    float arr[n];
    
    srand(time(0));

    printf("1 - RANDOM FILLING\n");
    printf("2 - KEYBOARD FILLING\n");

    // Insert filling array : random or keyboard filling
    while(1) {
        int add_arr;
        add_arr = validation_int();
        
        switch (add_arr) {
            case 1:
                for (int i = 0; i < n; i++)
                    arr[i] = -100 + rand() % 200;
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("Array[%d] = ", i);
                    arr[i] = validation_float();
                }
                break;
            default:
                printf("Not corect data!");
        }

        break;
    }

    float first_positive, last_positive;
    int first_idx, last_idx;

    // Find first positive number
    for (int i = 0; i < n; i++)
        if (arr[i] >= 0) {
            first_positive = arr[i];
            first_idx = i;
            break;
        }
    
    // Find last positive number
    for (int i = n - 1; i >= 0; i--)
        if (arr[i] >= 0) {
            last_positive = arr[i];
            last_idx = i;
            break;
        }
    
    // Number of elements between first positive and last positive number
    int count = 0;
    for (int i = first_idx + 1; i < last_idx; i++)
        count++;

    // Output result
    printf("FIRST POSITIVE ELEMENT: %f\n", first_positive);
    printf("LAST POSITIVE ELEMENT: %f\n", last_positive);
    printf("NUM: %d\n", count);

    printf("START ARRAY: {" );
    for (int i = 0; i < n; i++)
        if (i < n - 1)
            printf("%.2f, ", arr[i]);
        else
            printf("%.2f}\n", arr[i]);

    BubbleSort(arr, n);
}

// Work with two-dimensional array
void task_2() {
    int row, column;

    printf("Enret row of matrix: ");
    row = validation_int_range(0, INT_MAX);

    printf("Enret column of matrix: ");
    column = validation_int_range(0, INT_MAX);

    int matrix[row][column];

    srand(time(0));

    printf("1 - HARD WORK\n");
    printf("2 - RANDOM\n");

    // Insert filling array : random or keyboard filling
    while (1) {
        int add_arr;
        add_arr = validation_int();

        switch (add_arr) {
            case 1:
                for (int i = 0; i < row; i++)
                    for(int j = 0; j < column; j++) {
                        printf("MATRIX [%d][%d]: ", i + 1, j + 1);
                        matrix[i][j] = validation_int();
                    }
                break;
            case 2:
                for (int i = 0; i < row; i++)
                    for(int j = 0; j < column; j++) {
                        matrix[i][j] = rand() % 101;
                    }
                break;
            default:
                printf("Not corect data!");
        }

        break;
    }

    int result_matrix[row][column];
    int k = 0;
    int chet = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            if (matrix[i][j] % 2 == 0)
                chet++;
        
        if (chet == column)
            // Replace element in i row
            for (int j = column - 1; j >= 0; j--)
                result_matrix[i][k++] = matrix[i][j];
        else
            for (int j = 0; j < column; j++)
                result_matrix[i][j] = matrix[i][j];
        
        k = 0;
        chet = 0;
    }

    // Output start matrix
    printf("START MARTIX\n");
    for (int i = 0; i < row; i++) {
        printf("[");

        for(int j = 0; j < column; j++)
            if (j < column - 1)
                printf("%d, ", matrix[i][j]);
            else
                printf("%d]\n", matrix[i][j]);

        printf("\n");
    }

    // Output finixh matrix
    printf("FINISH MATRIX\n");
    for (int i = 0; i < row; i++) {
        printf("[");

        for(int j = 0; j < column; j++)
            if (j < column - 1)
                printf("%d, ", result_matrix[i][j]);
            else
                printf("%d]\n", result_matrix[i][j]);

        printf("\n");
    }
}

int main()
{
    int iscontinue = 1;
    int num_prog;
    
    while (iscontinue) {
        clrscr();

        printf("------------------------------------------------------------------\n");
        printf("LABARATORY WORK\n");
        printf("ONE-DIMENSIONAL AND TWO-DIMENSIONAL ARRAYS\n");
        printf("AUTHOR: ZELENIY DMYTRO, STUDENT OF GROUP KM-73 <VARIANT 10>\n");
        printf("------------------------------------------------------------------\n");
        
        printf("1. ARRAY\n");
        printf("2. MATRIX\n");
        printf("3. EXIT (BYE)\n\n");
        
        fflush(stdin);
        num_prog = validation_int();
       
        switch(num_prog) {
            case 1:
                task_1();
                break;
            case 2:
                task_2();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid value!\n");
                break;
        }

        printf("\nIf you want to continue input 1 or another digit to exit\n");
        iscontinue = validation_int();
        if (iscontinue == 1)
            ;
        else
            iscontinue = 0;
    }
    return 0;
}