#include "task_1.h"

#define MAX_SIZE 999

// Text of menu for task 1
void menu_1()
{
    puts("\n1. Create file");
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

void task_1()
{
    menu_1();

    FILE *file;
    char *name;

    char is_continue = '1';
    char chose;
    while(is_continue)
    {
        printf("\nYour choose: ");
        
        chose = getchar();
        clear_buf();
        switch(chose)
        {
            case '1':
                create_file();
                break;
            case '2':
                printf("Enter name of file what you want to open: ");
                name = input_text();

                file = open_file(name);

                break;
            case '3':
                if (file != NULL)
                    view_file(file);
                else
                    printf("File was not open\n");
                break;
            case '4':
                if (file != NULL)
                    edit_file(file, name);
                else
                    printf("File was not open\n");

                break;
            case '5':
                if (file != NULL)
                {
                    fclose(file);
                    file = open_file(name);
                    printf("File saved\n");
                }
                else 
                    printf("File was not open\n");
                
                break;
            case '6':
                if (file != NULL)
                {
                    save_as(file, name);
                    printf("File saved\n");
                }
                else
                    printf("File was not open\n");

                break;
            case '7':
                if (file != NULL)
                {
                    fclose(file);
                    //free(name);
                    printf("File closed\n");
                }
                else
                    printf("File was not open\n");
                
                break;
            case '8':
                if (file != NULL)
                    t_1(file);
                else 
                    printf("File was not open\n");
                break;
            case '9':
                if (file != NULL)
                    t_2(file);
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

int size_arr(char *text)
{
    int size = 0;
    int idx = 0;
    while (text[idx++] != '\0')
    {
        if (text[idx] == 0)
            break;
        size++;
    }

    return size;
}

// Inputing text
char *input_text()
{
    char *text = (char *)malloc(sizeof(char) * MAX_SIZE);
    memset(text, 1, MAX_SIZE);
    fgets(text, MAX_SIZE, stdin);
    
    return text;
}

// Creating file
void create_file()
{
    FILE *file;
    printf("Enter name of file what you want to create: ");
    char *name = input_text();

    file = fopen(name, "w");
    
    if (file != NULL)
        printf("File created\n");
    else
        printf("File was not create");
    
    fclose(file);
    //free(name);
}

FILE *open_file(char *name)
{
    FILE *file = fopen(name, "r");

    if (file == NULL)
        printf("File was not open\n");

    return file;
}

void view_file(FILE *file)
{
    char ch;
    while ((ch = getc(file)) != EOF)
    {
        printf("%c", ch);
    }
}

void save_as(FILE *file, char *name)
{
    printf("Enter name and format of file what you want to save: ");
    char *new_name = input_text();

    rename(name, new_name);

    fclose(file);
    fopen(new_name, "r");
    //free(new_name);
}

void edit_file(FILE *file, char *name)
{
    char ch;

    puts("\t1. Add text to file");
    puts("\t2. Correct data in file");
    puts("\t3. Delete data in file");
    
    printf("Your choose: ");
    ch = getchar();
    clear_buf();
    switch (ch)
    {
        case '1':
            add_text(file, name);
            break;
        case '2':
            correct_file(file, name);
            break;
        case '3':
            delete_data(file, name);
            break;
        default:
            printf("Error! Please, try agan\n");
            break;
    }
}

void correct_file(FILE *file, char *name)
{
    printf("Input string, which you what to correct: ");
    char *corr = input_text();
    printf("Input string, which is correct: ");
    char *right = input_text();

    int size_corr = size_arr(corr);

    int size = size_arr(right);
    
    file = fopen(name, "r");
    FILE *file2 = fopen("asd.txt", "w");

    char ch;
    int state = 1;
    int idx = 0;
    while ((ch = getc(file)) != EOF)
    {
        for(char *i = corr; *i != '\0' && *i != '\n'; i++)
        {
            if (*i == ch)
            {
                state = 1;
                ch = getc(file);
                idx++;
            }
            else 
            {
                state = 0;
                break;
            }
        }
        if (state)
        {
            idx -= strlen(corr) - 1;
            break;
        }
        idx++;
    }
    

    fseek(file, 0L, SEEK_SET);
    char c;
    int idx_cur = 0;
    char check = '0';
    while ((c = getc(file)) != EOF)
    {
        if (idx_cur < idx)
            putc(c, file2);
        else if (idx_cur >= idx + size_corr)
            putc(c, file2);
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (check == '0')
                    putc(right[i], file2);
                else
                    break;
            }
            check = '1';
        }

        idx_cur++;
    }
    
    fclose (file);
    fclose (file2);
    remove(name);
    rename("asd.txt", name);

    file = fopen(name, "r");
    //free(corr);
    //free(right);
}

void delete_data(FILE *file, char *name)
{
    printf("Input string, which you what to delete: ");
    char *text = input_text();
    int size = size_arr(text);

    file = fopen(name, "r");
    FILE *file2 = fopen("file.txt", "w");

    char ch;
    int state = 1;
    int idx = 0;
    while ((ch = getc(file)) != EOF)
    {
        for(char *i = text; *i != '\0' && *i != '\n'; i++)
        {
            if (*i == ch)
            {
                state = 1;
                ch = getc(file);
                idx++;
            }
            else 
            {
                state = 0;
                break;
            }
        }
        if (state)
        {
            idx -= strlen(text) - 1;
            break;
        }
        idx++;
    }

    fseek(file, 0L, SEEK_SET);
    char c;
    int curr_idx = 0;
    while((c = getc(file)) != EOF)
    {
        if (curr_idx < idx)
            putc(c, file2);
        else if (curr_idx >= idx + size)
            putc(c, file2);
        
        curr_idx++;
    }

    fclose (file);
    fclose (file2);
    remove(name);
    rename("file.txt", name);

    file = fopen(name, "r");
    //free(text);
}

void add_text(FILE *file, char *name)
{
    fclose(file);
    file = fopen(name, "a");
    
    char *text = input_text();
    fputs(text, file);

    fclose(file);
    fopen(name, "r");
    //free(name);
}

int is_contains_dublic(char *line)
{
    char first_letters[MAX_SIZE];
    int size = 0;

    int n = strlen(line);
    int i = 0;

    if (n != 0) {
        first_letters[size++] = line[0];
        i++;
    }

    while (i < n) {
        if (i + 1 < n && line[i] == ' ') {
            first_letters[size++] = line[i + 1];
        }

        i++;
    }

     for (int j = 0; j < size - 1; j++)
        for (int k = j + 1; k < size; k++)
            if (first_letters[j] == first_letters[k])
            {
                return 1;
            }
    
    return 0;
} 

void t_1(FILE *file)
{
    printf("Input name of file: ");
    char *name = input_text();
    FILE *F2 = fopen(name, "w");

    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) 
    {
        if (!is_contains_dublic(line)) {
            fprintf(F2, "%s", line);
        }
    }

    fclose(F2);
}

void t_2(FILE *file)
{
    int min_len = MAX_SIZE;
    char min_word[MAX_SIZE];

    int cur_min_len = 0;
    char cur_min_word[MAX_SIZE];

    int idx = 0;
    char ch;
    fseek(file, 0L, SEEK_SET);
    while ((ch = getc(file)) != EOF)
    {
        if (ch == ' ' || ch == '\n')
        {
            if (min_len > cur_min_len)
            {
                min_len = cur_min_len;
                memset(min_word, '\0', MAX_SIZE);
                int size = size_arr(cur_min_word);
                for (int i = 0; i <= size; i++)
                    min_word[i] = cur_min_word[i];
            }
            memset(cur_min_word, '\0', MAX_SIZE);
            cur_min_len = 0;
            idx = 0;
        }
        if (ch == ' ') { continue; }
        else if (ch == ',') { continue; }
        else if (ch == '\n') { continue; }
        else if (ch == '-') { continue; }
        else if (ch == '.') { continue; }
        else {
            cur_min_word[idx++] = ch;
            cur_min_len++;
        }
    }

    printf("Min word in file: %s", min_word);
}