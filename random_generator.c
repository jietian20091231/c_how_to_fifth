#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char encrypt_sequence[] = "0123456789JQK";

void random_generator(char (*buff)[19] , int c, int r);
void encrypt_idcode(char* key, char* original, char* encrypt);
void decrypt_idcode(char* key, char* encrpyt, char* original);

int main()
{
	char original_numbers[100][19] = { {0} };
	char keys[10][19] = { {0} };

	//memset(buff, 0, 10);

	srand( time(NULL) );



	int i, j, loop;
	long counter = 0L;
	for(loop = 0; loop < 1000; loop++)
	{
		random_generator(original_numbers, 19, 100);
		random_generator(keys, 9, 10);

		for( i = 0; i < 10; i++)
		{		
			//printf("keys[%d] = %s\n", i, *(keys + i));
			for( j = 0; j < 100; j++)
			{
				char encrypt[19] = { 0 };
				char decrypt[19] = { 0 };
				encrypt_idcode(*(keys + i) ,*(original_numbers + j), encrypt);
				//printf("key %s, original %s, encrypt  %s\n", *(keys + i) ,*(original_numbers + j), encrypt);			
				decrypt_idcode(*(keys + i) ,encrypt, decrypt);
				//printf("key %s, encrypt %s, original %s\n", *(keys + i) , encrypt, decrypt);

				if(strcmp(decrypt, *(original_numbers + j)) == 0)
				{
					printf("[%3d][%3d] key %s, original %s encrypt algorithm Test PASS.\n", i, j, *(keys + i), *(original_numbers + j));
					counter++;
				}
				else
				{
					printf("[%3d][%3d]key %s, original %s, encrypt  %s\n", i, j, *(keys + i) ,*(original_numbers + j), encrypt);
					printf("[%3d][%3d]key %s, encrypt %s, original %s\n", i, j, *(keys + i) , encrypt, decrypt);
					exit(0);
				}				

			}		
		}
	}	

	printf("\n\n-----\n\nencrypt algorithm Test %ld, all PASSED.\n\n-----\n\n", counter);

    return 0;
}


void random_generator(char (*buff)[19], int c, int r)
{
 	int i, j;

 	for(i = 0; i < r; i++)
 	{
	 	for( j = 0; j < c; j++)
	 	{
	 		int r =  0 + rand() % 9;
	 		char c = '0' + r;
	 		buff[i][j] = c;
	 	} 		
 	}

}

void encrypt_idcode(char* key, char* original, char* encrypt)
{
    int lenA = strlen(key);
    int lenB = strlen(original);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;
    
    int i;
    for(i = 0; i < maxlen; i++)
    {
        a = (lenA + i - maxlen < 0) ? 0 : key[lenA + i - maxlen] - '0';
        b = (lenB + i - maxlen < 0) ? 0 : original[lenB + i - maxlen] - '0';
    
        char c = '0';
        if((maxlen - i) % 2) {
            c = encrypt_sequence[(a + b) % 13];
        } else {
            c = '0' + (b - a < 0 ? b - a + 10 : b - a);            
        }
        
        int index = maxlen - i;
        encrypt[i] = c;
    } 

	//printf("key %s, original %s, encrypt  %s\n", key ,original, encrypt);   
}


void decrypt_idcode(char* key, char* encrpyt, char* original)
{
    int lenA = strlen(key);
    int lenB = strlen(encrpyt);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;

    int i;
    for(i = 0; i < maxlen; i++)
    {
        a = (lenA + i - maxlen < 0) ? 0 : key[lenA + i - maxlen] - '0';
        b = (lenB + i - maxlen < 0) ? 0 : encrpyt[lenB + i - maxlen] - '0'; 

        //printf("a = %d, b = %d\n", a, b);       
        
        if((maxlen - i) % 2) {
            int c1 = b + 13 - a;
            int c2 = 13 - b;
            int x = 0; 
            char c = '~';
            //printf("------c1= %d, c2 = %d-------------\n", c1, c2);
            if(encrpyt[i] != 'J' && encrpyt[i] != 'Q' && encrpyt[i] != 'K') {
                if(c1 >= 0 && c2 >=0 ) {                    
                    //printf("%d < 13 && %d < 13 = %d\n", c1, c2 , (c1 < 13 && c2 < 13) );
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

                c  = encrypt_sequence[x % 13];

            } else {                
                if(encrpyt[i] == 'J' ) {
                    x = 10;                                   
                } else  if(encrpyt[i] == 'Q') {
                    x = 11;
                } else if(encrpyt[i] == 'K') {
                    x = 12;
                }
                if((x -a ) > 0 ) {
                    c  = encrypt_sequence[x - a];
                }
                
            }

            //printf(">>i = %d, a = %d, b = %d, c1 = %d, c2 = %d, key[%d] = %c, encrpyt[%d] = %c, c = %c\n", i ,a, b, c1, c2, i, key[i], i, encrpyt[i], c);
            original[i] = c;
            
        } else {

           int c1 = b + a - 10;
           int c2 = b + a;
           char c = '^';
           
           if( c1 >= 0 && c1 < 10 ) {
                c = '0' + c1;
           } else if( c2 >= 0 && c2 < 10 ) {
                c = '0' + c2;
           }  
           
           //printf(">i = %d, a = %d, b = %d, c1 = %d, c2 = %d, key[%d] = %c, encrpyt[%d] = %c, c = %c\n", i ,a, b, c1, c2, i, key[i], i, encrpyt[i], c);
           original[i] = c;

        }        

    }    
}