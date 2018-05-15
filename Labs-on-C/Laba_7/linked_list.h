#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "struct.h"

List *initList();
Node *createNode(ROUTE data);

void addFirst(ROUTE data, List *list);
void addLast(ROUTE data, List *list);
void add(ROUTE data, List *list, int position);
void addKey(ROUTE data, List *list, int routeNum);

void removeFirst(List *list);
void removeLast(List *list);
void remov(List *list, int position);
void removeKey(List *list, int routeNum);

void display(List *list);
void sortList(List *list);

#endif