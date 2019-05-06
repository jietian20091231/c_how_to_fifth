#include <stdio.h>
#define ANSWER "Grant"
#define SIZE 40

char * s_gets(char* st, int n);

int main()
{
    char try[SIZE];
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    int tryCount = 0;
    while((tryCount < 5) && (try != ANSWER))
    {
        puts("No, that's wrong. Try again.");
        s_gets(try,SIZE);
        tryCount++;
    }

    if(try == ANSWER)
    {
        puts("That's right!");
    }
    else
    {
        puts("That's wrong!");
    }

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
