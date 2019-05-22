#include <stdio.h>
#include <string.h>

struct clientData {
    int acctNum;
    char lastName[ 15 ];
    char firstName[ 15 ];
    double balance;
};

int main(int argc, char const *argv[])
{
    int i;
    struct clientData blankClient = { 0 };
    FILE *cfPtr;

    if ( ( cfPtr = fopen( "credit.dat", "wb" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    } else {
        for ( i = 0; i < 100; i++ ) {
            fwrite( &blankClient, sizeof( struct clientData ), 1, cfPtr );
        }

        long len = ftell( cfPtr );
        printf( "len = %ld, counter = %ld\n", len, len / sizeof( struct clientData ) );
    }


    return 0;
}
