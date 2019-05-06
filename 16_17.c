#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define NUM 100
#define LEN  5
void fillarray(double ar [], int n);
void showarray(const double ar [], int n);
int mycmp(const void* p1, const void* p2);

void fillarray_str(char** str, int n);
void showarray_str(char** str, int n);
int mycmp_str(const void* pl, const void* p2);
char* s_gets(char* st, int n);


int main(void)
{
    /*
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycmp);
    puts("\nSored list:");
    showarray(vals, NUM);
    */

    //char* arr[LEN];
    char** arr = (char**)calloc(LEN, sizeof(char*));
    fillarray_str(arr, LEN);
    printf("Show string array: ");
    showarray_str(arr, LEN);
    qsort(arr, LEN, sizeof(char *), mycmp_str);
    printf("After sort, Show string array: ");
    showarray_str(arr, LEN);

    return 0;
}


void fillarray(double ar[], int n)
{
    int index;
    srand((unsigned) time(NULL));
    for(index = 0; index < n; index++)
        ar[index] = (double) rand() / ((double) rand() + 0.1);
}

void showarray(const double ar[], int n)
{
    int index;
    for(index = 0; index < n; index++)
    {
        printf("%9.4f ", ar[index]);
        if(index % 6 == 5)
            putchar('\n');
    }

    if(index % 6 != 0)
        putchar('\n');
}

int mycmp(const void* p1, const void* p2)
{
    const double* a1 = (const double*) p1;
    const double* a2 = (const double*) p2;

    if(*a1 < *a2)
        return -1;
    else if(*a1 > *a2)
        return 1;
    else
        return 0;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }

    return ret_val;
}

void fillarray_str(char** arr, int n)
{
    printf("Enter %d string:\n", n);
    int index;
    for(index = 0 ; index < n ; index++)
    {
        char* str = (char*)calloc(NUM, sizeof(char));
        s_gets(str, NUM);
        *(arr + index) = str;
    }
}

void showarray_str(char** str, int n)
{
    int index;
    for( index = 0; index < n; index++)
        printf("%s  ", *(str + index) );

    putchar('\n');
}

int mycmp_str(const void* p1, const void* p2)
{

    return tolower(*(*(char**) p1)) - tolower(*(*(char**) p2));

    /*
    printf("p1 = %p, p2 = %p\n", p1, p2);
    char* str1 = *(char**) p1;
    char* str2 = *(char**) p2;

    printf("str1 = [%p]%s\n", str1 ,str1);
    printf("str2 = [%p]%s\n", str2, str2);

    char c1 = *str1;
    char c2 = *str2;


    if(c1 > c2 )
        return 1;
    else if(c1 < c2 )
        return -1;
    else
        return 0;

    return 0;
    */
}
