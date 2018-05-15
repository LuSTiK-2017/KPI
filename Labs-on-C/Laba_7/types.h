#ifndef TYPES_H
#define TYPES_H

#define MAX_SIZE 999

// Struct for list of route
typedef struct ROUTE
{
    char start_point[MAX_SIZE];
    char finish_point[MAX_SIZE];
    int route_number;
} ROUTE;

typedef struct node 
{
    ROUTE data;
    struct node *next;
} Node;

typedef struct list 
{
    Node *head;
    Node *tail;
} List;

#endif