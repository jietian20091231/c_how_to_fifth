#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct clientData {
    int accountNum;
    char lastName[ 50 ];
    char firstName[ 50 ];
    double balance;
};

int enterChoice( void );
void textFile( FILE *readPtr );
void updateRecord( FILE *fPtr );
void newRecord( FILE *fPtr );
void deleteRecord( FILE *fPtr );

int main( int argc, char const *argv[] )
{
	FILE *cfPtr;
	int choice;

	if ( NULL ==  ( cfPtr = fopen( "credit.dat", "rb+" ) ) ) {
		printf( "File [%s] pointer is NULL, Could not do anythings!\n", "credit.dat" );
		return 0;
	}

	choice = enterChoice();
	while ( choice >= 1 && choice < 5 ) {
		switch ( choice ) {
			case 1:
				textFile( cfPtr );
				break;
			case 2:
				newRecord( cfPtr );
			 	break;
			case 3:
				updateRecord( cfPtr );
				break;
			case 4:
				deleteRecord( cfPtr );
				break;
			default:
				printf( "Incorrect choice\n" );
				break;
		}

		choice = enterChoice();
	}

	if( cfPtr != NULL )
		fclose( cfPtr );

	return 0;
}

int enterChoice( void )
{
	int numberChoice;

	printf( "\nEnter your choice\n"
			"1 - store a formatted text file of accounts called\n"
				 "\"accounts.txt\" for printing\n"
			"2 - add a new account\n"
			"3 - update an account\n"
			"4 - delete an account\n"
			"5 - end of program\n" );
	scanf( "%d", &numberChoice );

	return numberChoice;
}

void newRecord( FILE *fPtr )
{
	if ( NULL == fPtr ) {
		printf( "File [%s] pointer is NULL, Could not do anythings!\n", "credit.dat" );
		return;
	}

	struct clientData client = { 0 };

	int accountNum = 0;

	printf( "Enter new account number ( 1 - 100 ):\n> " );
	scanf( "%d", &accountNum );

	if ( accountNum < 1  ) {
		printf( "accountNum isn't in the scope ( 1 - 100 ), additon new Record failed!\n" );
		return;
	}

	rewind( fPtr );
	fseek( fPtr, ( accountNum - 1 ) * sizeof( struct clientData ), SEEK_SET );

	fread( &client, sizeof( struct clientData ), 1 , fPtr );

	printf( "\nShow Record[ #%d ]:\n", client.accountNum );
	printf( "\n%-6s%-16s%-11s%10s\n", "Acct", "FisrtName", "LastName", "Balance" );
	printf("%-6d%-16s%-11s%10.2f\n", client.accountNum, client.firstName, client.lastName, client.balance );

	printf( "====> client.accountNum = %d\n", client.accountNum );
	if ( client.accountNum != 0  ) {
		printf( "accountNum[ %d ] is exist, please choose a number to do it.\n", accountNum );
		return;
	}

	client.accountNum = accountNum;

	printf( "Enter firstName, LastName and Balance:\n> " );
	scanf( "%15s%15s%lf", client.firstName, client.lastName, &client.balance );

	//rewind( fPtr );
	fseek( fPtr,  -1  * sizeof( struct clientData ), SEEK_CUR );
	fwrite( &client, sizeof( struct clientData ), 1, fPtr );

}

void updateRecord( FILE *fPtr )
{
	if ( NULL == fPtr ) {
		printf( "File [%s] pointer is NULL, Could not do anythings!\n", "credit.dat" );
		return;
	}

	double balance = 0.00;
	struct clientData old_client = { 0 };

	int accountNum;

	printf( "Enter new account number ( 1 - 100 ):\n> " );
	scanf( "%d", &accountNum );

	if ( accountNum < 1  ) {
		printf( "accountNum isn't in the scope ( 1 - 100 ), update Record failed!\n" );
		return;
	}

	rewind( fPtr );
	fseek( fPtr, ( accountNum - 1 ) * sizeof( struct clientData ), SEEK_SET );

	fread( &old_client, sizeof( struct clientData ), 1 , fPtr );

	if ( old_client.accountNum == 0  ) {
		printf( "accountNum[ %d ] isn't exist, please choose a number to do it.\n", accountNum );
		return;
	}

	printf( "\nShow Record[ #%d ]:\n", old_client.accountNum );
	printf( "\n%-6s%-16s%-11s%10s\n", "Acct", "FisrtName", "LastName", "Balance" );
	printf("%-6d%-16s%-11s%10.2f\n", old_client.accountNum, old_client.firstName, old_client.lastName, old_client.balance );

	printf( "Enter change ( + ) or payment ( - ) :\n> " );
	scanf( "%lf", &balance );

	old_client.balance += balance;

	rewind( fPtr );
	fseek( fPtr, ( accountNum - 1 ) * sizeof( struct clientData ), SEEK_SET );

	fwrite( &old_client, sizeof( struct clientData ), 1, fPtr );

	printf( "\nShow update Record[ #%d ]:\n", old_client.accountNum );
	printf( "\n%-6s%-16s%-11s%10s\n", "Acct", "FisrtName", "LastName", "Balance" );
	printf("%-6d%-16s%-11s%10.2f\n", old_client.accountNum, old_client.firstName, old_client.lastName, old_client.balance );

	printf( "\nOparation UPDATE record[ #%d ] successful.\n", old_client.accountNum );

	printf( "\n" );

}


void textFile( FILE *fPtr )
{
	if ( NULL == fPtr ) {
		printf( "File [%s] pointer is NULL, Could not do anythings!\n", "credit.dat" );
		return;
	}

	FILE *textFile = fopen( "accounts.txt", "w" );
	if ( NULL == textFile ) {
		printf( "File [%s] pointer is NULL, Could not write records.\n", "accounts.txt" );
		return;
	}

	struct clientData client = { 0 };

	rewind( fPtr );

	fread( &client, sizeof( struct clientData ), 1, fPtr );

	while ( !feof( fPtr ) ) {
		fprintf( textFile, "%-6d%-16s%-11s%10.2f\n", client.accountNum, client.firstName, client.lastName, client.balance );
		fread( &client, sizeof( struct clientData ), 1, fPtr );
	}

	fclose( textFile );
}

void deleteRecord( FILE *fPtr )
{
	if ( NULL == fPtr ) {
		printf(  "File [%s] pointer is NULL, Could not do anythings!\n", "credit.dat" );
		return;
	}

	struct clientData old_client = { 0 };
	int yn;

	int accountNum;

	printf( "Enter new account number ( 1 - 100 ):\n> " );
	scanf( "%d", &accountNum );

	if ( accountNum < 1  ) {
		printf( "accountNum isn't in the scope ( 1 - 100 ), delete  Record failed!\n" );
		return;
	}

	rewind( fPtr );
	fseek( fPtr, ( accountNum - 1 ) * sizeof( struct clientData ), SEEK_SET );

	fread( &old_client, sizeof( struct clientData ), 1 , fPtr );

	if ( old_client.accountNum == 0  ) {
		printf( "accountNum[ %d ] isn't exist", old_client.accountNum );
		return;
	}

	printf( "\nShow Record[ #%d ]:\n", old_client.accountNum );
	printf( "\n%-6s%-16s%-11s%10s\n", "Acct", "FisrtName", "LastName", "Balance" );
	printf("%-6d%-16s%-11s%10.2f\n", old_client.accountNum, old_client.firstName, old_client.lastName, old_client.balance );

	printf( "Could you delete the record?(Yn)\n>" );
	scanf( "%d", &yn );

	yn = tolower( yn );

	if ( 1 != yn ) {
		printf( "CANCEL delete Record [ #%d ].\n", old_client.accountNum );
		return;
	}

	memset( &old_client, 0, sizeof( struct clientData ) );

	rewind( fPtr );
	fseek( fPtr, ( accountNum - 1 ) * sizeof( struct clientData ), SEEK_SET );
	fwrite( &old_client, sizeof( struct clientData ), 1, fPtr );

	printf( "Oparation DELETE record[ #%d ] successful.\n", old_client.accountNum );


	printf( "\n" );
}
