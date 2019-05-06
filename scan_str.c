#include <stdio.h>

int main()
{
    char name1[11], name2[11], name3[11];
    int count;

    printf("Please enter 2 names.\n");
    count = scanf("%5s %10s %10s", name1, name2, name3);
    printf("I read the %d names %s, %s and %s. \n", count, name1, name2, name3);

    return 0;
}
