#include <stdio.h>

typedef struct _point {
  int x;
  int y;
} Point;

size_t getSize( float *ptr );

int main( void )
{

  float array[ 20 ];

  printf( "The Number of bytes in the array is %ld"
	  "\nThe number of bytes returned by getSize is %ld\n",
	  sizeof( array ), getSize( array ) );
  printf ( " array      = %p\n&array[ 0 ] = %p\n", array, &array[ 0 ] );

  int *iPtr;
  Point *pPoint;
  
  printf( "sizeof( iPtr ) = %ld, sizeof( *iPtr ) = %ld\n", sizeof( iPtr), sizeof( *iPtr ) );
  printf( "sizeof( pPoint ) = %ld, sizeof( *pPoint ) = %ld\n", sizeof( pPoint ), sizeof( *pPoint ) );

  return 0;
}

size_t getSize( float *ptr )
{
  return sizeof( ptr );
}
