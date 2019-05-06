#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    char * str = (char*) calloc(10, sizeof(char));
    char * temp = "this is a test string.";
    strcpy(str, "hello, 01234567890");
    printf("%s, %ld, %p, %p\n", str, strlen(str), str, str + strlen(str));
    printf("%c\n", *(str + strlen(str) - 1));
    printf("%s, %p\n", temp, temp);
    free(str);

    return 0;
}
