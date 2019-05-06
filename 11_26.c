#include <stdio.h>
#include <string.h>

#define WORDS "beastabcd"
#define SIZE 40

int main()
{
    const char* orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;

    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);

    printf("copy = %s\n", copy);

    return 0;
}
