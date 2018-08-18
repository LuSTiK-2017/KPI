#ifndef TASK_2_H
#define TASK_2_H

#include <stdio.h>
#include <stdlib.h>
#include "run.h"
#include "task_1.h"
#include "validation.h"

#define MAX_SIZE 999

typedef struct MusicDisk
{
    char name[MAX_SIZE];
    char autor[MAX_SIZE];

    float duration;
    float price;

    int status;
} MusicDisk;

void menu_2();
void task_2();
void create_file_bin();
FILE *open_file_bin(char *name);
void print(FILE *fp);
void edit_file_bin(FILE *file, char *name);
void add_struct(FILE *file, char *name);
void delete_struct(FILE *file, char *name);
void reset_struct(FILE *file, char *name);
void save_bin_as(FILE *file, char *name);
void edit_struct(FILE *file, char *name);
void save_file_bin(FILE *file, char *name);
void save_file_plus(FILE *file, char *name);
void save_bin_as_plus(FILE *file, char *name);
void delete_dur(FILE *file, char *name);
void add(FILE *file, char *name);
int num_struct(FILE *file);

#endif