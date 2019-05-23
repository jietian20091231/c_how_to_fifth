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

    if ( ( cfPtr = fopen( "credit.dat", "rb+" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    } else {
        printf( "Enter account number"
                " ( 1 to 100, 0 to end input)\n> " );
        scanf( "%d", &client.acctNum );

        while( client.acctNum != 0  ) {
            printf( "Enter firstName, lastName, balance\n> " );

            fscanf( stdin, "%s%s%lf", client.firstName, client.lastName, &client.balance );

            fseek( cfPtr, ( client.acctNum - 1 ) * sizeof( struct clientData ), SEEK_SET );

            fwrite( &client, sizeof( struct clientData ), 1, cfPtr );

            printf( "Enter account number\n> " );
            scanf( "%d", &client.acctNum );

        }

        fclose( cfPtr );

    }

    return 0;
}
