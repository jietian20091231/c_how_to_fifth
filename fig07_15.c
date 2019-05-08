#include <stdio.h>
#define SIZE 10

void bubbleSort( int * const array, const int size );

int main(int argc, char *argv[])
{

  int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

  int i;

  printf( "Data items in original order\n" );

  for ( i = 0; i < SIZE; i++ ) {
    printf( "%4d", a[ i ] );
  }

  bubbleSort( a, SIZE );

  printf( "\nData items in ascending order\n" );

  for ( i = 0; i < SIZE; i++ ) {
    printf( "%4d", a[ i ] );
  }

  printf( "\n" );

  
  return 0;
}


void bubbleSort( int * const array, const int size )
{
  void swap( int *element1Ptr, int *element2Ptr );
  int i, j;
  for ( i = 0; i < size; i++ ) {
    for ( j = i + 1; j < size; j++ ) {
      if ( array[ i ] > array[ j ] ) {
	swap( &array[ i ], &array[ j ] );
      }
    }
  }
}

void swap( int *element1Ptr, int *element2Ptr )
{
  int temp = *element1Ptr;
  *element1Ptr = *element2Ptr;
  *element2Ptr = temp;
}
