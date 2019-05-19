#include <stdio.h>

void print_balance_info( FILE *cfPtr, int mode );


int main( void )
{

  int request;
  int account;
  double balance;
  char name[ 30 ];

  FILE *cfPtr;

  if ( ( cfPtr = fopen( "fig11_03.bat" , "r" ) ) == NULL ) {
    
    printf( "File could not be opened!\n" );
    
  } else {

    printf( "Enter request\n"
	    " 1 - List accounts with zero balance\n"
	    " 2 - List accounts with credit balance\n"
	    " 3 - List accounts with debit balance\n"
	    " 4 - End of run\n?" );
    scanf( "%d", &request );

    while ( request != 4 ) {

      print_balance_info( cfPtr, request );
      
      printf( "Enter request\n"
	      " 1 - List accounts with zero balance\n"
	      " 2 - List accounts with credit balance\n"
	      " 3 - List accounts with debit balance\n"
	      " 4 - End of run\n?" );
      scanf( "%d", &request );
      
    }

    printf( "End of Run.\n" );
    fclose( cfPtr );
  }
  
  return 0;
}


void print_balance_info( FILE *cfPtr, int mode )
{
  rewind( cfPtr );

  int account = 0;
  double balance = 0.00;
  char name[ 30 ] = { 0 };

  switch( mode  ) {
  case 1:
    printf( "\nAccounts with zero balances:\n" );
    break;
  case 2:
    printf( "\nAccounts with credit balances:\n" );
    break;
  case 3:
    printf( "\nAccounts with debit balances:\n" );
    break;
  default:
    printf( "\nThis will never happend." );
  }

  fscanf( cfPtr, "%d%s%lf" , &account, name, &balance );

  while( !feof( cfPtr ) ) {
    
    if( 1 == mode && 0 == balance ) {
      printf( "%-10d%-13s%7.2f\n", account, name, balance );
    } else if ( 2 == mode && balance < 0 ) {
      printf( "%-10d%-13s%7.2f\n", account, name, balance );      
    } else if ( 3 == mode && balance > 0 ) {
      printf( "%-10d%-13s%7.2f\n", account, name, balance );      
    }
    
    fscanf( cfPtr, "%d%s%lf" , &account, name, &balance );    
  }
  
}
