#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
    char A[101], B[101], C[101];
    char encrypt[] = "0123456789JQK";

    memset(A, 0, 101);
    memset(B, 0, 101);
    memset(C, 0, 101);
 
    scanf("%s %s", A, B);
    int lenA = strlen(A);
    int lenB = strlen(B);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;
    
    int i;
    for(i = 0; i < maxlen; i++)
    {
        a = (lenA + i - maxlen < 0) ? 0 : A[lenA + i - maxlen] - '0';
        b = (lenB + i - maxlen < 0) ? 0 : B[lenB + i - maxlen] - '0';

        //printf("a = %d, b = %d\n", a , b);
    
        char c = '0';
        if((maxlen - i) % 2) {
            c = encrypt[(a + b) % 13];
        } else {
            c = '0' + (b - a < 0 ? b - a + 10 : b - a);            
        }

        //printf("c = %c\n", c);
        
        int index = maxlen - i;
        //printf("index = %d\n", index);
        C[i] = c;
    }

    printf("key %s, original %s, encrypt  %s\n", A ,B, C);
 
    return 0;
}