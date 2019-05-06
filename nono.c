#include <stdio.h>

int print_self(const char* msg);

int main()
{

    char side_a[] = "Side A";
    char dont[4] = {'W', 'O', 'W', '!'};
    char side_b[] = "Side B";

    printf("side_a = %p\n", side_a);
    printf("dont = %p\n", dont);
    printf("side_b =%p\n", side_b);

    puts(dont);
    int number = print_self("hello,world");
    printf("%s is %d characters.\n", "hello,world", number);

    return 0;
}


int print_self(const char* msg)
{
    int count = 0;
    while(*msg != '\0')
    {
        putchar(*msg++);
        count++;
    }
    putchar('\n');

    return count;
}
