#include <stdio.h>

void put1(const char*);
int put2(const char*);

int main()
{
    put1("If I'd as much money");
    put2(" as I could spend,");
    printf("I count %d characters.\n",
           put2("I never would cry old chairs to mend."));

    return 0;
}

void put1(const char* msg)
{
    while(*msg)
       putchar(*msg++);
}

int put2(const char* msg)
{
    int count = 0;
    while(*msg)
    {
        putchar(*msg++);
        count++;
    }
    putchar('\n');

    return count;
}
