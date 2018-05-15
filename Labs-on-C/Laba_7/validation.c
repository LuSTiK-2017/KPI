#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validation.h"

#define ISCONTINUE 1

// Function for check input value on integer
int validation_int() {
    char input_data[65];
    int number;

    while (ISCONTINUE) {
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

    while (ISCONTINUE) {
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