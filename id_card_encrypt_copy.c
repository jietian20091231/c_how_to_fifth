#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const char key18[] = "472468468426443214";
const char key17[] = "74207466141801081";

const char encrypt_sequence[] = "0123456789JQK";

int encrypt_idcard(char* id_card, char* target);

int decrypt_idcard(char* encrypt_idcode, char* target);

void copy_s(char* src, char* dist, int begin, int end );

int main()
{

    char* id_card = "15232119910111241X";
    //char* id_card = "430482198609233078";
    char encrypt_buffer[20], decrypt_buffer[20];

    memset(encrypt_buffer, 0, 20);
    memset(decrypt_buffer, 0, 20);

    encrypt_idcard(id_card, encrypt_buffer);

    decrypt_idcard(encrypt_buffer, decrypt_buffer);

    if(strcmp(id_card, decrypt_buffer) == 0 ) {
        printf("==============> Pass\n");
    }



    return 0;
}

int encrypt_idcard(char* id_card, char* target)
{
    if(NULL == id_card || strlen(id_card) == 0) {
        return 1;
    }

    char temp_idcard[20], temp_key[20];
    memset(temp_idcard, 0, 20);
    memset(temp_key, 0, 20);

    char c = *(id_card + strlen(id_card) - 1);
    if(c == 'X' || c == 'x') {
        copy_s(id_card, temp_idcard, 0, strlen(id_card) - 1);
        strcpy(temp_key, key17);
    } else {
        strcpy(temp_idcard, id_card);
        strcpy(temp_key, key18);
    }

    int lenA = strlen(temp_key);
    int lenB = strlen(temp_idcard);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;
    
    int i;
    for(i = 0; i < maxlen; i++)
    {
        a = (lenA + i - maxlen < 0) ? 0 : temp_key[lenA + i - maxlen] - '0';
        b = (lenB + i - maxlen < 0) ? 0 : temp_idcard[lenB + i - maxlen] - '0';
    
        char c = '0';
        if((maxlen - i) % 2) {
            c = encrypt_sequence[(a + b) % 13];
        } else {
            c = '0' + (b - a < 0 ? b - a + 10 : b - a);            
        }
        
        target[i] = c;
    } 

    if(lenB == 17) {
        target[17] = c;
    }

    return 0;
}


int decrypt_idcard(char* encrypt_idcode, char* target)
{
    if(NULL == encrypt_idcode || strlen(encrypt_idcode) == 0) {
        return 1;
    }

    char temp_idcard[20], temp_key[20];
    memset(temp_idcard, 0, 20);
    memset(temp_key, 0, 20);

    char c = *(encrypt_idcode + strlen(encrypt_idcode) - 1);
    if(c == 'X' || c == 'x') {
        copy_s(encrypt_idcode, temp_idcard, 0, strlen(encrypt_idcode) - 1);
        strcpy(temp_key, key17);
    } else {
        strcpy(temp_idcard, encrypt_idcode);
        strcpy(temp_key, key18);
    }

    int lenA = strlen(temp_key);
    int lenB = strlen(temp_idcard);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;

    int i;
    for(i = 0; i < maxlen; i++)
    {
        a = (lenA + i - maxlen < 0) ? 0 : temp_key[lenA + i - maxlen] - '0';
        b = (lenB + i - maxlen < 0) ? 0 : temp_idcard[lenB + i - maxlen] - '0';       
        
        if((maxlen - i) % 2) {
            int c1 = b + 13 - a;
            int c2 = 13 - b;
            int x = 0; 
            char c = '*';
            if(temp_idcard[i] != 'J' && temp_idcard[i] != 'Q' && temp_idcard[i] != 'K') {
                if(c1 >= 0 && c2 >=0 ) {                    
                    if (c1 < 13 && c2 < 13) {
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

                c  = encrypt_sequence[x % 13];

            } else {                
                if(temp_idcard[i] == 'J' ) {
                    x = 10;                                   
                } else  if(temp_idcard[i] == 'Q') {
                    x = 11;
                } else if(temp_idcard[i] == 'K') {
                    x = 12;
                }
                if((x -a ) > 0 ) {
                    c  = encrypt_sequence[x - a];
                }
                
            }

            target[i] = c;
            
        } else {

           int c1 = b + a - 10;
           int c2 = b + a;
           char c = '*';
           
           if( c1 >= 0 && c1 < 10 ) {
                c = '0' + c1;
           } else if( c2 >= 0 && c2 < 10 ) {
                c = '0' + c2;
           }  
           
           target[i] = c;

        }        

    } 

    if(strlen(target) == 17) {
        target[17] = c;
    }              

    return 0;
}

void copy_s(char* src, char* dist, int begin, int end )
{
    int i = 0;
    for( i = 0; i < end; i++)
    {
        *(dist + i ) = *(src + i);
    }
}