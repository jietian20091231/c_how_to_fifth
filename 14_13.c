#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

char* s_gets(char* st, int n);

struct _book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

typedef struct _book Book;

int main(void)
{
    Book library[MAXBKS];
    Book temp = {
        "",
        "",
        0.00
    };
    int count = 0;
    int index;
    static int records = 0;
    FILE* pbooks;
    size_t size = sizeof(Book);

    if((pbooks = fopen("books.dat", "a+b")) == NULL)
    {
        fputs("Can't open books.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while(count < MAXBKS && fread(&temp, size, 1, pbooks) == 1)
    {
        //fputs("Current contants of books.dat:", stderr);
        printf("%s by %s: $%.2f\n", temp.title, temp.author, temp.value);
        records++;
        if(records == MAXBKS)
        {
            fputs("The book.dat file is full.\n", stderr);
            exit(2);
        }
    }

    int inputCount = MAXBKS - records;
    int current = 0;

    printf("Please add new book titles, surplus [%d] records.\n", inputCount);
    puts("Press [enter] at the start of a line to stop.");
    while( current < inputCount && s_gets(library[current].title, MAXTITL) != NULL && library[current].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[current].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[current++].value);
        while(getchar() != '\n')
            continue;
        if(current < inputCount)
            puts("Enter the next title.");
    }

    if(current > 0)
    {
        puts("Here is the list of your books:");
        for(index = 0; index < current; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }

        fwrite(&library[count], size, current, pbooks);
    }
    else
    {
        puts("No books? Too bad.\n");
    }

    fclose(pbooks);
    puts("Bye.\n");

    return 0;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }

    return ret_val;
}
