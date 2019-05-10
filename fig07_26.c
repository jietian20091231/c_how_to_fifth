#include <stdio.h>

#define SIZE 10

void swap( int *elment1Ptr, int *element2Ptr );
int ascending( int a, int b );
int descending( int a, int b );
void bubble( int work[], const int size, int (*compare)( int a, int b ));

int main( void )
{
  int order;
  int counter;

  int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
  printf( "Enter 1 to sort in ascending order.\n"
	  "Enter 2 to sort in descending order: " );
  scanf( "%d", &order );

  printf( "\nData items in original order\n" );

  for ( counter = 0; counter < SIZE; counter++ ) {
    printf( "%5d", a[ counter ] );
  }

  if ( 1 == order ) {
    bubble( a, SIZE, ascending );
    printf( "\nData items in ascending order\n" );
  } else if ( 2 == order ) {
    bubble( a, SIZE, descending );
    printf( "\nData items in descending order\n" );
  }

  for ( counter = 0; counter < SIZE; counter++ ) {
    printf( "%5d", a[ counter ] );
  }

  printf( "\n" );

  return 0;
}

void bubble( int work[], const int size, int (*compare)( int a, int b ) )
{
  int i, j;
  for ( i = 0; i < size; i++ ) {
    for ( j = i + 1; j < size; j++ ) {
      if ( (*compare)( work[ i ], work[ j ] ) ) {
	swap( &work[ i ], &work[ j ] );
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

int ascending( int a, int b )
{
  return b < a;
}

int descending(int a, int b )
{
  return b > a;
}
