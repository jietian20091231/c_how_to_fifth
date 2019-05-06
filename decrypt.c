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
        
        if((maxlen - i) % 2) {
            int c1 = b + 13 - a;
            int c2 = 13 - b;
            int x = 0; 
            char c = '~';
            //printf("------c1= %d, c2 = %d-------------\n", c1, c2);
            if(B[i] != 'J' && B[i] != 'Q' && B[i] != 'K') {
                if(c1 >= 0 && c2 >=0 ) {                    
                    printf("%d < 13 && %d < 13 = %d\n", c1, c2 , (c1 < 13 && c2 < 13) );
                    if (c1 < 13 && c2 < 13) {
                        //printf("-------------------\n");
                        x = (c1 < c2 )? c1 : c2;
                    } else if(c1 >= 13 || c2 >= 13 ) {
                        if(c1 >= 13 || c2 > 13 ) {
                            x = (c1 >= 13 )? c1 : c2;
                        } else if (c2 == 13 ) {
                            x = c1;
                        }
                        
                    }                                        
                } else if( c1 < 0 || c2 < 0 ) {
                    x = (c1 > c2 ) ? c1 : c2;
                }

                //printf("---> x = %d\n", x);

                c  = encrypt[x % 13];

            } else {                
                if(B[i] == 'J' ) {
                    x = 10;                                   
                } else  if(B[i] == 'Q') {
                    x = 11;
                } else if(B[i] == 'K') {
                    x = 12;
                }
                if((x -a ) > 0 ) {
                    c  = encrypt[x - a];
                }
                
            }

            //printf(">>i = %d, a = %d, b = %d, c1 = %d, c2 = %d, A[%d] = %c, B[%d] = %c,
            // c = %c\n", i ,a, b, c1, c2, i, A[i], i, B[i], c);
            C[i] = c;
            
        } else {

           int c1 = b + a - 10;
           int c2 = b + a;
           char c = '^';
           
           if( c1 >= 0 && c1 < 10 ) {
                c = '0' + c1;
           } else if( c2 >= 0 && c2 < 10 ) {
                c = '0' + c2;
           }  
           
           //printf(">i = %d, a = %d, b = %d, c1 = %d, c2 = %d, A[%d] = %c, B[%d] = %c,
           // c = %c\n", i ,a, b, c1, c2, i, A[i], i, B[i], c);
           C[i] = c;

        }        

    }

    printf("key %s, encrypt %s, original %s\n", A ,B, C);

    return 0;
}