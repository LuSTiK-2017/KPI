#include <stdio.h>
#include <stdlib.h>

#define NUM_STRUCT 5
#define MAX_SIZE 999

// Struct for list of route
typedef struct ROUTE
{
    char start_point[MAX_SIZE];
    char finish_point[MAX_SIZE];
    int route_number;
} ROUTE;

void struct_route()
{
    ROUTE routes[NUM_STRUCT];
    
    // Inputing data route
    for (int i = 0; i < NUM_STRUCT; i++)
    {
        printf("Input name of the starting point of route\n");
        scanf("%s", routes[i].start_point);
        
        printf("Input name of the finish point of route\n");
        scanf("%s", routes[i].finish_point);

        printf("Number route\n");
        routes[i].route_number = validation_int();

        printf("\n");
    }

    // Sort list of route
    ROUTE tmp;
    for (int i = 0; i <= (NUM_STRUCT - 2); i++)
        for (int j = 0; j <= (NUM_STRUCT - i - 2); j++)
            if (routes[j].route_number > routes[j + 1].route_number)
            {
                tmp = routes[j];
                routes[j] = routes[j + 1];
                routes[j + 1] = tmp;
            }
    
    // Output list of route
    printf("\nLIST OF ROUTES:\n");
    for (int i = 0; i < NUM_STRUCT; i++)
    {
        printf("\tSTART POINT:  %s\n", routes[i].start_point);
        printf("\tFINISH POINT: %s\n", routes[i].finish_point);
        printf("\tNUMBER ROUTE: %d\n\n", routes[i].route_number);
    }

    // Output searching route
    int average_idx = 0, first_idx = 0, last_idx = (NUM_STRUCT - 1);
    printf("Enter searching number route: ");
    int search_value = validation_int();

    while (first_idx < last_idx)
    {
        average_idx = first_idx + (last_idx - first_idx) / 2;
        if (search_value <= routes[average_idx].route_number)
            last_idx = average_idx;
        else
            first_idx = average_idx + 1;
    }

    if (routes[last_idx].route_number == search_value)
    {
        printf("\tSTART POINT:  %s\n", routes[last_idx].start_point);
        printf("\tFINISH POINT: %s\n", routes[last_idx].finish_point);
        printf("\tNUMBER ROUTE: %d\n\n", routes[last_idx].route_number);
    }
    else
        printf("This route is not found");
}