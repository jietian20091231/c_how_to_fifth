#include <stdio.h>

void printArray( const int a[][ 3 ] );


int main()
{

  int array1[ 2 ][ 3 ] = { { 1, 2, 3 }, { 4, 5, 6 } };
  int array2[ 2 ][ 3 ] = { 1, 2, 3, 4 };
  int array3[ 2 ][ 3 ] = { { 1, 2 }, { 4 } };
  int array4[ 4 ][ 3 ] = { 0 };

  int aIndex = sizeof( array4 ) / sizeof( int[] );
  printf( "aIndex = %d.\n", aIndex );
  
  printf( "Values in array1 by row are:\n" );
  printArray( array1 );

  printf( "Values is array2 by row are:\n" );
  printArray( array2 );

  printf( "Values is array3 by row are:\n" );
  printArray( array3 );

  return 0;
}


void printArray( const int a[][ 3 ] )
{
  int i, j;

  for ( i = 0; i <= 1; i++ ) {
    for( j = 0; j <= 2; j++ ) {
      printf( "%d ", a[ i ][ j ] );
    }
    
    printf( "\n" );
    
  }
}
