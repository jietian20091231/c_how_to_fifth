#include <stdio.h>

int main()
{

    int i = 0;
    for( i = 0; i< 100; i++)
    {
        int n = i % 13;
        printf("[%d] %d\n", i ,n);
    }

    return 0;
}