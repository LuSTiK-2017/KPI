#include "task_2.h"

void menu_2()
{
    puts("1. Create new file");
    puts("2. Open file");
    puts("3. View file");
    puts("4. Edit file");
    puts("5. Save file");
    puts("6. Save file as");
    puts("7. Close file");
    puts("8. First");
    puts("9. Second");
    puts("0. Exit from this task");
}

void task_2()
{
    menu_2();

    FILE *file;
    char *name;

    char is_continue = '1';
    char chose;
    while (is_continue)
    {
        printf("\nYour choose: ");

        chose = getchar();
        clear_buf();
        switch (chose)
        {
            case '1':
                create_file_bin();
                break;
            case '2':
                printf("Enter name of file what you want to open: ");
                name = input_text();

                file = open_file_bin(name);

                break;
            case '3':
                file = fopen(name, "rb");
                if (file != NULL)
                    print(file);
                else
                    printf("File was not open\n");
                break;
            case '4':
                if (file != NULL)
                    edit_file_bin(file, name);
                else
                    printf("File was not open\n");

                break;
            case '5':
                if (file != NULL)
                    save_file_bin(file, name);
                else
                    printf("File was not open\n");

                break;
            case '6':
                if (file != NULL)
                    save_bin_as(file, name);
                else
                    printf("File was not open\n");

                break;      
            case '7':
                if (file != NULL)
                {
                    fclose(file);
                    printf("File closed\n");
                }
                else
                    printf("File was not open\n");
                
                break;      
            case '8':
                if (file != NULL)
                {
                    delete_dur(file, name);
                }
                else
                    printf("File was not open\n");
                
                break;
            case '9':
                if (file != NULL)
                {
                    add(file, name);
                }
                else
                    printf("File was not open\n");
                
                break;
            case '0':
                is_continue = 0;
                break;
            default:
                printf("Error! Please, try agan\n");
                break;
        }
    }
}


void create_file_bin()
{
    FILE *file;
    printf("Enter name of file what you want to create: ");
    char *name = input_text();

    file = fopen(name, "wb");
    
    if (file != NULL)
        printf("File created\n");
    else
        printf("File was not create");
    
    fclose(file);
}

FILE *open_file_bin(char *name)
{
    FILE *file = fopen(name, "rb");

    if (file == NULL)
        printf("File was not open\n");

    return file;
}

void print(FILE *fp)
{
    int i = 1;
    MusicDisk element;
    fseek(fp, 0L, SEEK_SET);
    fread(&element, sizeof(element), 1, fp);

    printf("Id   Name\t\tAutor\t\tDuration\tPrice\tStatus\n");
    while (!feof(fp))
    {
        printf("%d    %s\t\t%s\t\t%.2f\t\t%.2f\t%d\n", i, element.name, element.autor, element.duration, element.price, element.status);
        fread(&element, sizeof(element), 1, fp);
        i++;
    }
}

void edit_file_bin(FILE *file, char *name)
{
    char ch;

    puts("\t1. Add struct to file");
    puts("\t2. Correct struct");
    puts("\t3. Delete struct from file");
    puts("\t4. Reset deleting struct");
    
    printf("Your choose: ");
    ch = getchar();
    clear_buf();
    switch (ch)
    {
        case '1':
            add_struct(file, name);
            fclose(file);
            file = open_file_bin(name);
            break;
        case '2':
            edit_struct(file, name);
            fclose(file);
            file = open_file_bin(name);           
            break;
        case '3':
            delete_struct(file, name);
            fclose(file);
            file = open_file_bin(name);
            break;
        case '4':
            reset_struct(file, name);
            fclose(file);
            file = open_file_bin(name);
            break;
        default:
            printf("Error! Please, try agan\n");
            break;
    }
}

void add_struct(FILE *file, char *name)
{
    fclose(file);
    file = fopen(name, "ab");

    MusicDisk element;

    printf("Input name of music disk: ");
    scanf("%s", element.name);

    printf("Input name of autor: ");
    scanf("%s", element.autor);

    printf("Input duration of music: ");
    element.duration = validation_float();

    printf("Input price of the disk: ");
    element.price = validation_float();

    element.status = 0;

    fwrite(&element, sizeof(element), 1, file);
}

void edit_struct(FILE *file, char *name)
{
    fclose(file);
    file = fopen(name, "rb+");

    MusicDisk element;

    puts("Input id of struct what you need to edit: ");
    int num = validation_int();

    long int i;
    int j = 1;
    fread(&element, sizeof(element), 1, file);
    while (!feof(file))
    {
        if (j == num)
        {
            printf("Input name of music disk: ");
            scanf("%s", element.name);
            
            printf("Input name of autor: ");
            scanf("%s", element.autor);
            
            printf("Input duration of music: ");
            element.duration = validation_float();

            printf("Input price of the disk: ");
            element.price = validation_float();

            element.status = 0;

            i = sizeof(element);
            fseek(file, -i, 1);
            fwrite(&element, sizeof(element), 1, file);
        }
        fread(&element, sizeof(element), 1, file);
        j++;
    }
}

void delete_struct(FILE *file, char *name)
{
    fclose(file);
    file = fopen(name, "rb+");

    MusicDisk element;

    puts("Enter id of struct what you need to delete: ");
    int num = validation_int();

    long int i;
    int j = 1;
    fread(&element, sizeof(element), 1, file);
    while (!feof(file))
    {
        if (j == num)
        {
            element.status = 1;

            i = sizeof(element);
            fseek(file, -i, 1);
            fwrite(&element, sizeof(element), 1, file);
        }
        fread(&element, sizeof(element), 1, file);
        j++;
    }
}

void reset_struct(FILE *file, char *name)
{
    fclose(file);
    file = fopen(name, "rb+");

    MusicDisk element;

    puts("Enter id of struct what you need to delete: ");
    int num = validation_int();

    long int i;
    int j = 1;
    fread(&element, sizeof(element), 1, file);
    while (!feof(file))
    {
        if (j == num)
        {
            element.status = 0;

            i = sizeof(element);
            fseek(file, -i, 1);
            fwrite(&element, sizeof(element), 1, file);
        }
        fread(&element, sizeof(element), 1, file);
        j++;
    }
}

void save_file_bin(FILE *file, char *name)
{
    char ch;

    puts("\t1. Save file with deleting disactive struct");
    puts("\t2. Save five with saving status of file");
    
    printf("Your choose: ");
    ch = getchar();
    clear_buf();
    switch (ch)
    {
        case '1':
            save_file_plus(file, name);
            printf("File saved\n");
            break;
        case '2':
            if (file != NULL)
            {
                fclose(file);
                file = open_file_bin(name);
                printf("File saved\n");
            }
            else 
                printf("File was not open\n");
            
            break;
        default:
            printf("Error! Please, try agan\n");
            break;
    }
}

void save_file_plus(FILE *file, char *name)
{
    FILE *fp = fopen("tmp.txt", "wb");

    MusicDisk element;

    fseek(file, 0L, SEEK_SET);

    fread(&element, sizeof(element), 1, file);
    while (!feof(file))
    {
        if (element.status == 0)
            fwrite(&element, sizeof(element), 1, fp);
        fread(&element, sizeof(element), 1, file);
    }

    fclose(file);
    fclose(fp);
    remove(name);
    rename("tmp.txt", name);

    file = fopen(name, "rb");
}

void save_bin_as(FILE *file, char *name)
{
    char ch;

    puts("\t1. Save file with deleting disactive struct");
    puts("\t2. Save five with saving status of file");
    
    printf("Your choose: ");
    ch = getchar();
    clear_buf();
    switch (ch)
    {
        case '1':
            save_bin_as_plus(file, name);
            break;
        case '2':
            if (file != NULL)
            {
                printf("Enter name and format of file what you want to save: ");
                char *new_name = input_text();

                rename(name, new_name);

                fclose(file);
                fopen(new_name, "r");
            }
            else 
                printf("File was not open\n");
            
            break;
        default:
            printf("Error! Please, try agan\n");
            break;
    }
}

void save_bin_as_plus(FILE *file, char *name)
{
    printf("Enter new name: ");
    char *name_tmp = input_text();
    FILE *fp = fopen(name_tmp, "wb");

    MusicDisk element;

    fseek(file, 0L, SEEK_SET);

    fread(&element, sizeof(element), 1, file);
    while (!feof(file))
    {
        if (element.status == 0)
            fwrite(&element, sizeof(element), 1, fp);
        fread(&element, sizeof(element), 1, file);
    }

    fclose(file);
    fclose(fp);

    remove(name);   
    rename(name, name_tmp);

    file = fopen(name, "rb");
}

void delete_dur(FILE *file, char *name)
{
    fclose(file);
    file = fopen(name, "rb+");

    MusicDisk element;

    puts("Enter duration of struct what you need to delete: ");
    int num = validation_int();

    long int i;
    fread(&element, sizeof(element), 1, file);
    while (!feof(file))
    {
        if (element.duration == num)
        {
            element.status = 1;

            i = sizeof(element);
            fseek(file, -i, 1);
            fwrite(&element, sizeof(element), 1, file);
        }
        fread(&element, sizeof(element), 1, file);
    }
}

void add(FILE *file, char *name)
{
    FILE *fp = fopen("tmp.txt", "wb");

    puts("Enter id of struct after you want to add: ");
    int num = validation_int();

    MusicDisk element;

    int j = 1;
    fseek(file, 0L, SEEK_SET);

    fread(&element, sizeof(element), 1, file);
    while (!feof(file))
    {
        if (j == num)
        {
            fwrite(&element, sizeof(element), 1, fp);

            for (int i = 0; i < 2; i++)
            {
                printf("Input name of music disk: ");
                scanf("%s", element.name);
                
                printf("Input name of autor: ");
                scanf("%s", element.autor);
                
                printf("Input duration of music: ");
                element.duration = validation_float();

                printf("Input price of the disk: ");
                element.price = validation_float();

                element.status = 0;

                fwrite(&element, sizeof(element), 1, fp);
            }

            fread(&element, sizeof(element), 1, file);
        } 

        fwrite(&element, sizeof(element), 1, fp);
        fread(&element, sizeof(element), 1, file);

        j++;
    }

    fclose(file);
    fclose(fp);
   
    rename("tmp.txt", name);

    file = fopen(name, "rb");
}