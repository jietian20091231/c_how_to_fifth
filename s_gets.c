#include <stdio.h>
#include <string.h>

#define STLEN 10

char* s_gets(char* st, int n);

int main()
{

    char words[STLEN];

    puts("Enter strings (empty line to quit):\n");
    while(strcmp("q", s_gets(words, STLEN)) != 0)
    {
        puts(words);
    }

    puts("Done.");
    return 0;
}


char* s_gets(char* st, int n)
{
    char* ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }

    return ret_val;
}
