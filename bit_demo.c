#include <stdio.h>

int main(void)
{
    int a = 5;
    a >>= 1;
    int b = (01 & a);
    char c = ( 01 & a ) + '0';
    printf("a = %d, b = %d ,c = %c\n", a, b, c);
    a >>= 1;
    printf("a = %d\n", a);
    a >>= 1;
    printf("a = %d\n", a);
    return 0;
}
