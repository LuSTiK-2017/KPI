#include "linked_list.h"

List *initList()
{
    List *list = malloc(sizeof(List));

    list->head = NULL;
    list->tail = list->head;

    return list;
}

Node *createNode(ROUTE data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

// Add node in the list
void addFirst(ROUTE data, List *list)
{
    Node *newNode = createNode(data);

    if (list->head == NULL)
        list->head = list->tail = newNode;
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
}

void addLast(ROUTE data, List *list)
{
    Node *newNode = createNode(data);

    if (list->head == NULL)
        list->head = list->tail = newNode;
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void add(ROUTE data, List *list, int position)
{
    if (position == 0)
        addFirst(data, list);
    else
    {
        Node *currenNode = list->head;
        Node *newNode;

        int i = 1;
        while (i < position)
        {
            currenNode = currenNode->next;
            i++;
        }

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = currenNode->next;
        currenNode->next = newNode;
    }
}

void addKey(ROUTE data, List *list, int routeNum)
{
    Node *currenNode = list->head;
    Node *newNode;

    while (currenNode->data.route_number != routeNum)
        currenNode = currenNode->next;
    
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = currenNode->next;
    currenNode->next = newNode;
}

// Remove node in the list
void removeFirst(List *list)
{
    Node *head = list->head;
    Node *next;

    if (list->head == NULL)
        printf("The list is empty");
    else
    {
        next = head->next;
        free(head);
        list->head = next;
    }
}

void removeLast(List *list)
{
    Node *currenNode = list->head;
    Node *next = currenNode->next;

    if (list->head == NULL)
        printf("The list is empty");
    else
    {
        while (next->next != NULL)
        {
            next = next->next;
            currenNode = currenNode->next;
        }
        
        currenNode->next = NULL;
        free(next);
    }
}

void remov(List *list, int position)
{
    Node *currenNode = list->head;
    Node *next = currenNode->next;

    if (list->head == NULL)
        printf("The list is empty");
    else
    {
        if (position == 1)
            removeFirst(list);
            
        int i = 1;
        while (i != position - 1)
        {
            currenNode = currenNode->next;
            next = next->next;
            
            i++;
        }

        currenNode->next = next->next;
        free(next);
    }
}

void removeKey(List *list, int routeNum)
{
    Node *currenNode = list->head;
    Node *next = currenNode->next;

    while (currenNode->data.route_number != routeNum) 
    {
        if (currenNode->next->data.route_number == routeNum)
        {
            break;
        }
        currenNode = currenNode->next;
        next = next->next;
    }        
    
    currenNode->next = next->next;
    free(next);
}

// Print list
void display (List *list)
{
    if(list->head == NULL)
        printf("No item");
    else
    {
        Node *currenNode = list->head;
        printf("        START POINT     FINISH POINT    NUMBER ROUTE\n");
        while (currenNode != NULL)
        {
                printf("\t%s", currenNode->data.start_point);
                printf("\t\t%s", currenNode->data.finish_point);
                printf("\t\t%d\n", currenNode->data.route_number);

                currenNode = currenNode->next;
        }
    }
}

void sortList(List *list) 
{
    Node *currenNode = list->head;
    Node *p = NULL;

    if (list->head != NULL)
    {
        while (currenNode->next != NULL)
        {
            p = currenNode->next;

            do {
                if (p->data.route_number < currenNode->data.route_number)
                {
                    ROUTE tmp = p->data;
                    p->data = currenNode->data;
                    currenNode->data = tmp;
                }

                p = p->next;
            } while (p != NULL);

            currenNode = currenNode->next;
        }
    }
}