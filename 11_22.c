#include <stdio.h>
#include <string.h>

int main()
{

    printf("A, A is %d\n", strcmp("A", "A"));
    printf("A, B is %d\n", strcmp("A", "B"));
    printf("B, A is %d\n", strcmp("B", "A"));
    printf("C, A is %d\n", strcmp("C", "A"));
    printf("Z, A is %d\n", strcmp("Z", "A"));
    printf("abcdefg, apple is %d\n", strcmp("abcdefg", "apple"));

    return 0;
}
