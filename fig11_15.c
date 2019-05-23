#include <stdio.h>

struct clientData {
    int acctNum;
    char lastName[ 50 ];
    char firstName[ 50 ];
    double balance;
};

int main( void )
{
    FILE *cfPtr;
    struct clientData client = { 0 };

    if ( ( cfPtr = fopen( "credit.dat", "r" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    } else {
        printf( "%-6s%-16s%-11s%10s\n", "Acct", "FisrtName", "LastName", "Balance" );

        while( !feof( cfPtr ) ) {
            fread( &client, sizeof( struct clientData ), 1, cfPtr );

            if( client.acctNum != 0 ) {
                printf( "%-6d%-16s%-11s%10.2f\n",
                    client.acctNum,
                    client.firstName,
                    client.lastName,
                    client.balance
                );
            }
        }



        fclose( cfPtr );

    }

    return 0;
}
