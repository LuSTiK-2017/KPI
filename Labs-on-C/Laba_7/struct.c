#include "struct.h"

#define IS_CONTINUE 1

// Input elements of struct
ROUTE input_data()
{
    ROUTE data;

    printf("Input name of the starting point of route: ");
    scanf("%s", data.start_point);
    
    printf("Input name of the finish point of route: ");
    scanf("%s", data.finish_point);

    printf("Number route: ");
    data.route_number = validation_int();

    return data;
}

// Menu linked list
void struct_route()
{
    List *routes = initList();

    printf("\n1. Add first in list\n");
    printf("2. Add last in list\n");
    printf("3. Add element in list\n");
    printf("4. Add element in list on the key\n");

    printf("5. Remove first in list\n");
    printf("6. Remove last in list\n");
    printf("7. Remove element in list\n");
    printf("8. Remove element in list on the key\n");

    printf("9. Print list\n");
    printf("10.Sort list\n");
    printf("11. Exit\n");

    while (IS_CONTINUE)
    {
        ROUTE data;

        printf("\nYour chose: ");
        int my_variant = validation_int();

        switch (my_variant)
        {
            case 1:
                data = input_data();
                addFirst(data, routes);
                break;
            case 2:
                data = input_data();
                addLast(data, routes);
                break;
            case 3:
                printf("Enter number after you want to insert (0 - insert to head): ");
                int num_i = validation_int();
                data = input_data();
                add(data, routes, num_i);
                break;
            case 4:
                printf("Enter route number after you want to insert: ");
                int num_route = validation_int();
                data = input_data();
                addKey(data, routes, num_route);
                break;
            case 5:
                removeFirst(routes);
                break;
            case 6:
                removeLast(routes);
                break;
            case 7:
                printf("Enter number you want to remove: ");
                int num_r = validation_int();
                remov(routes, num_r);
                break;
            case 8:
                printf("Enter route number you want to remove: ");
                int num_routeR = validation_int();
                removeKey(routes, num_routeR);
                break;
            case 9:
                display(routes);
                break;
            case 10:
                sortList(routes);
                break;
            case 11:
                exit(0);
            default:
                printf("Not found this variant.");
        }
    }
}
