#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initArray( int arr[], int size )
{
  memset( arr, 1, sizeof( arr[ 0 ] ) * size );
}

void printArray( int arr[], int size )
{
  int i;
  for ( i = 0; i < size; i++ ) {
    printf( "%d ", arr[ i ] );
  }

  printf( "\n" );
}

int main()
{
  int a[ 5 ];
  int _size = sizeof( a ) / sizeof ( a[ 0 ] );
  //initArray( a, _size );
  printArray( a, _size );

  int b[ 2 ][ 2 ] = { 0 };

  int i,j;
  for ( i = 0; i < 2; i++ ) {
    for ( j = 0; j < 2; j++ ) {
      printf( "b[ %d ][ %d ] = %d\n", i, j, b[ i ][ j ] );
    }
  }

  return 0;
}
