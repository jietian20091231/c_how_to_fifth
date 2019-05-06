#include <stdio.h>


void staticArrayInit(void);
void automaticArrayInit(void);

int main()
{
    printf("First call to each function:\n");
    staticArrayInit();
    automaticArrayInit();

    printf("\n\nSecond call to eatch function:\n");
    staticArrayInit();
    automaticArrayInit();

    printf("\n");

    return 0;

}


void staticArrayInit(void)
{
    static int array1[3];
    int i;

    printf("\nValues one entering staticArrayInit:\n");

    for(i = 0; i < 3; i++) {
        printf("array1[%d] = %d  ", i, array1[i]);
    }

    printf("\nValues one exiting staticArrayInit:\n");

    for(i = 0; i < 3; i++) {
        printf("array1[%d] = %d ", i, array1[i] += 5);
    }
}


void automaticArrayInit(void)
{
    int array2[3] = {0, 1, 2};
    int i;

    printf("\n\nValues on entering automaticArrayInit:\n");

    for(i = 0; i< 3; i++)
        printf("array2[%d] = %d ", i, array2[i]);

    
    printf("\nValues on exiting automaticArrayInit:\n");

    for(i = 0; i < 3; i++)
        printf("array2[%d] = %d ", i, array2[i] += 5);
}
