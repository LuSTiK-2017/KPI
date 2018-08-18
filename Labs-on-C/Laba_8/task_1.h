#ifndef TASK_1_H
#define TASK_1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "run.h"

void task_1();
void menu_1();
void create_file();
FILE *open_file(char *name);
char *input_text();
void view_file(FILE *file);
void save_as(FILE *file, char *name);
void edit_file(FILE *file, char *name);
void add_text(FILE *file, char *name);
void correct_file(FILE *file, char *name);
void delete_data(FILE *file, char *name);
int size_arr(char *text);
int is_contains_dublic(char *line);
void t_1(FILE *file);
void t_2(FILE *file);

#endif