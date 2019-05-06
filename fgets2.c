#include <stdio.h>
#define STLEN 100

int main()
{
    char words[STLEN];

    puts("Enter strings (empty line to quite): ");
    while( fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Done.");

    return 0;
}
