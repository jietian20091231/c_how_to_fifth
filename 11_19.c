#include <stdio.h>
#include <string.h>

#define SIZE 30
#define BUGSIZE 13

char* s_gets(char* st, int n);

int main()
{
    char flower[SIZE];
    char addon[] = "s small like old shoes.";
    char bug[BUGSIZE];
    const char temp [] = "this is test string.";
    int available;

    printf("flower = %p\n", flower);
    printf("addon = %p\n", addon);
    printf("bug = %p\n", bug);
    printf("temp = %p\n", temp);

    puts("What is your favorite flower?");
    s_gets(flower, SIZE);
    if((strlen(addon) + strlen(flower) + 1) < SIZE)
        strcat(flower, addon);
    puts(flower);
    puts(temp);

    puts("What is your favorite bug?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) -1;
    //strncat(bug, addon, available);
    strcat(bug, addon);
    puts(bug);
    puts(temp);

    printf("bug = %ld\n", strlen(bug));
    printf("bug = %p\n", bug);
    printf("temp = %p\n", temp);

    int index;
    for(index = 0; index < strlen(bug); index++)
        printf("%d : %c(%p)\n", index, *(bug + index), bug + index);

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
