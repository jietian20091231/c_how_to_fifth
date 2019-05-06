#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81
char* s_gets(char* st, int n);
char showmenu(void);
char eatline(void);
void show( void (*fp) (char*), char *str );
void _toUpper(char *);
void _toLower(char *);
void _transpose(char *);
void dummy(char *);

int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void(*pfun)(char *);

    puts("Enter a string (empty line to quite): ");
    while(s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while((choice = showmenu()) != 'n')
        {
            switch(choice)
            {
            case 'u': pfun = _toUpper; break;
            case 'l': pfun = _toLower; break;
            case 't': pfun = _transpose; break;
            case 'o': pfun = dummy;
            }

            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");

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


void show(void (*fp)(char*), char* str)
{
    (*fp)(str);
    puts(str);
}

char showmenu(void)
{
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase       1) lowercase");
    puts("t) transpose       o) original case");
    puts("n) next string");

    ans = getchar();
    ans = tolower(ans);
    eatline();
    while(strchr("ulton", ans) == NULL)
    {
        puts("Please enter u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

char eatline(void)
{
    while(getchar() != '\n')
        continue;
}

void _toUpper(char* str)
{
    while(*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void _toLower(char* str)
{
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void _transpose(char* str)
{
    while(*str)
    {
        if(islower(*str))
            *str = toupper(*str);
        else if(isupper(*str))
            *str = tolower(*str);

        str++;
    }
}

void dummy(char* str)
{

}
