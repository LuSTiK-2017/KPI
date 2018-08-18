#include "run.h"

// Function for clear screen
void clrscr() 
{ 
    printf("\033[2J"); /* Clear the entire screen. */ 
    printf("\033[0;0f"); /* Move cursor to the top left hand corner */ 
}

// Clear buffer
void clear_buf()
{    
    while (getchar() != '\n' );
}

void title()
{
    clrscr();
    
    printf("------------------------------------------------------------------\n");
    printf("LABORATORY WORK\n");
    printf("WORK WITH FILES\n");
    printf("AUTHOR: ZELENIY DMYTRO, STUDENT OF GROUP KM-73 <VARIANT 10>\n");
    printf("------------------------------------------------------------------\n\n");
}

// Text for menu
void text_menu()
{
    puts("\tMENU");
    puts("1. Task 1");
    puts("2. Task 2");
    puts("0. Exit");
    printf("\n");
}

// Menu of lab
void run()
{
    title(); text_menu();

    char chose;

    while (1)
    {
        printf("Your choose: ");
        
        chose = getchar();
        clear_buf();
        switch (chose)
        {
            case '1':
                task_1();
                clrscr(); 
                text_menu();           
                break;
            case '2':
                task_2();
                clrscr();
                text_menu();
                break;
            case '0':
                clrscr();
                exit(0);
                text_menu();
                break;
            default:
                printf("Error! Please, try agan\n");
                break;
        }
    }
}