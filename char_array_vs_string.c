#include <stdio.h>

int main( void )
{
  char cArr[] = { 'h', 'e', 'l', 'l', 'o' };
  char sArr[] = "hello";

  int i;
  for ( i = 0; i < sizeof( cArr ); i++ ) {
    printf( "cArr[ %d ] = %c[ %d ]\n", i, cArr[ i ], cArr[ i ] );
  }
  printf( "\n" );

  for ( i = 0; i < sizeof( sArr ); i++ ) {
    printf( "sArr[ %d ] = %c[ %d ]\n", i, sArr[ i ], sArr[ i ] );    
  }

  printf( "cArr length %d\n", sizeof( cArr ) );
  printf( "sArr length %d\n", sizeof( sArr ) );

  printf( "cArr strlen %d\n", strlen( cArr ) );
  printf( "sArr strlen %d\n", strlen( sArr ) );

  printf( "cArr is %s\n", cArr );
  printf( "sArr is %s\n", sArr );

  return 0;
  
}
