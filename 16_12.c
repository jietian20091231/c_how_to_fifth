#include <stdio.h>

#define LOG(msg) printf("[%s %s %s %d] : %s\n", __DATE__, __FILE__, __func__, __LINE__, msg)

void why_me();

int main()
{

    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The is standard c ? %s.\n", __STDC__ ? "true" : "false");
    //printf("The version is %ld.\n", __STDC_VERSION__);
    printf("This is line %d.\n", __LINE__);
    printf("This function is %s\n", __func__);
    why_me();

    return 0;
}

void why_me()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d.\n", __LINE__);
    LOG("This is a log message");
}
