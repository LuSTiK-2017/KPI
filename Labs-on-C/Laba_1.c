#include <stdio.h>
#include <stdlib.h>

void clrscr() 
{ 
    char a[80]; 
    printf("\033[2J"); /* Clear the entire screen. */ 
    printf("\033[0;0f"); /* Move cursor to the top left hand corner */ 
}

float validation_float(){
    float number;
    char c = '0';
    
    while(scanf("%f", &number) == 0) {
        printf("Invalid input! Try again: \n");
        do {
            c = getchar();
        }
        while (c != '\n');

        ungetc(c, stdin);
    }

    return number;
}

int validation_int(){
    int number;
    char c = '0';
    
    while(scanf("%d", &number) == 0) {
        printf("Invalid input! Try again: \n");
        do {
            c = getchar();
        }
        while (c != '\n');

        ungetc(c, stdin);
    }

    return number;
}

void volume_of_prism() {
    printf("\nVOLUME OF PRISM\n");
    float a, b, h, v;
    
    printf("Enter a: ");
    a = validation_float();
    printf("Enter b: ");
    b = validation_float();
    
    printf("Enter height of prism: ");
    h = validation_float();
        
    v = 0.5 * a * b * h;

    printf("Volume of prism: %.2f\n", v);
}

void calulate_form() {
    printf("\nCALCULATE f(x) = x + b, WHERE x = 1, 2, 3, 4, 5\n");
    float b;
    printf("Enter b: ");
    b = validation_float();

    for (int i = 0; i < 5; ++i) {
        printf("f(%d) = %.2f\n", i, (i + 1) + b);
    }
}

int validation_range(int x, int  y, float num) {
    while(num < x || num > y){
        printf("Out of range! Try again: \n");
        fflush(stdin);
        scanf("%f", &num);
    }
    
    return num;
}

void bin () {
    printf("\nPROGRAM FOR COMPUTING BINNARY CODE\n");
    int g; /*ID group*/
    char s; /*code of system*/
    char p; /*priveligs of user*/
    unsigned int UnitStateWord; /*code of state*/

    /*input of compotent system*/
    printf("Group id to which the user belongs (0 - 255): ");
    g = validation_int();
    g = validation_range(0, 255, g);

    printf("System code that is downloaded to the user (0 - 15): ");
    s = validation_int();
    s = validation_range(0, 15, s);

    printf("A sign of a privileged user (0 / 1): ");
    p = validation_int();
    p = validation_range(0, 1, p);

    /*packaged code formation*/
    UnitStateWord = ((unsigned int) g & 0x1FF) << 8;
    UnitStateWord |= ((unsigned int) s & 0xF) << 4;
    UnitStateWord |= ((unsigned int) p & 1) << 3;
    UnitStateWord |= 0 & 3;
    
    /*output result*/
    printf("\nWord state of the device = %04x\n", UnitStateWord);
}

void hex() {
    printf("\nPROGRAM FOR COMPUTING 'HEX' VALUE\n");
    unsigned char g; /*ID group*/
    char s; /*code of system*/
    char p; /*priveligs of user*/
    unsigned int UnitStateWord; /*state word*/

    /*Entering the state word of device*/
    printf("Input state word of device: \n");
    printf("(Hexadecimal number from 0 to 0xFFFF): ");
    scanf("%x", &UnitStateWord);

    /**/
    g = (UnitStateWord >> 8) & 0x1FF;
    s = (UnitStateWord >> 4) & 0xF;
    p = (UnitStateWord >> 3) & 1;

    /*selection of component parts*/
    putchar('\n');
    printf("Group id to which the user belongs = %d\n", g);
    printf("System code that is downloaded to the user = %d\n", s);
    printf("A sign of a privileged user = %d\n", p);
}

int main() 
{
    float iscontinue = 1;
    int num_prog;
    
    while (iscontinue) {
        clrscr();
        printf("------------------------------------------------------------------\n");
        printf("LABARATORY WORK\n");
        printf("BASIC DATA TYPES, INPUT-OUTPUT BIT OPERATIONS, SHIFT OPERATION\n");
        printf("AUTHOR: ZELENIY DMYTRO, STUDENT OF GROUP KM-73 <VARIANT 10>\n");
        printf("------------------------------------------------------------------\n");
        printf("1. VOLUME OF PRISM\n");
        printf("2. CALCULATE f(x) = x + b, WHERE x = 1, 2, 3, 4, 5\n");
        printf("3. PROGRAM FOR COMPUTING BINNARY CODE\n");
        printf("4. PROGRAM FOR COMPUTING 'HEX' VALUE\n");
        printf("5. EXIT (BYE)\n\n");
        fflush(stdin);
        num_prog = validation_int();
       
        switch(num_prog) {
            case 1:
                volume_of_prism();
                break;
            case 2:
                calulate_form();
                break;
            case 3:
                bin();
                break;
            case 4:
                hex();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid value!\n");
                break;
        }

        printf("\nIf you want to continue input 1 or another digit to exit\n");
        iscontinue = validation_int();
        if (iscontinue == 1)
            ;
        else
            iscontinue = 0;
    }

    return 0;
}