#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sentence.h"
#include "validation.h"

size_t MAX_SIZE = 999;  

char** input_sentences(int n)
{
    char **array = (char **)malloc(MAX_SIZE * sizeof(char*));
    for (int i = 0; i < MAX_SIZE; i++)
        array[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            char * tmp = (char *)malloc(MAX_SIZE * sizeof(char));
            getline(&tmp, &MAX_SIZE, stdin);
        }
        else {
            getline(&array[i - 1], &MAX_SIZE, stdin);
        }
    }

    return array;
}


int words_sentences(char* s)
{
    int i = 0;
    while (s[i] == ' ' && s[i] != '\0')
        i++;
    
    int word = 0, count = 0;
    while (s[i] != '\0') {
        if (s[i] != ' ' && s[i] != '\n' && word == 0)
        {
            word = 1;
            count++;
        }
        else if (s[i] == ' ')
            word = 0;
        i++;
    }

    return count;
    
}

void sort_sentences(int n)
{
    char **array = input_sentences(n);

    char swap[MAX_SIZE];
    int a = 0, b = 0;
    for (int c = 0 ; c <= ( n - 2 ); c++)
    for (int d = 0 ; d <= n - c - 2; d++)
        {
            a = words_sentences(array[d]);
            b = words_sentences(array[d + 1]);
            if (a > b)
            {
                memcpy (swap, array[d], strlen(array[d]) + 1);
                memcpy (array[d], array[d+1], strlen(array[d+1]) + 1);
                memcpy (array[d+1], swap, strlen(swap) + 1);
            }
        }

    printf("\nOUTPUT: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s", array[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        free(array[i]);
    }

    free(array);
}

int sentence()
{
    printf("Enter number of sentences what you want to input: ");
    int n = validation_int();

    sort_sentences(n);

    return 0;
}