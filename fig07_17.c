/*Fig. 7.17: fig07_17.c
  Demonstrating the sizeof operator */
#include <stdio.h>

typedef struct _point {
  int x;
  int y;
} Point;

int main( void )
{

  char c;
  short s;
  int i;
  long l;
  float f;
  double d;
  long double ld;
  int array[ 20 ];
  int *ptr = array;
  Point *pPoint;

  printf( "sizeof c = %ld\tsizeof(char) = %ld"
	  "\nsizeof s = %ld\tsizeof(short) = %ld"
	  "\nsizeof i = %ld\tsizeof(int) = %ld"
	  "\nsizeof l = %ld\tsizeof(long) = %ld"
	  "\nsizeof f = %ld\tsizeof(float) = %ld"
	  "\nsizeof d = %ld\tsizeof(double) = %ld"
	  "\nsizeof ld = %ld\tsizeof(long double) = %ld"
	  "\nsizeof  array = %ld\nsizeof ptr = %ld"
	  "\nsizeof pPoint = %ld\n",
	  sizeof c,    sizeof( char ),
	  sizeof s,    sizeof( short ),
	  sizeof i,    sizeof( int ),
	  sizeof l,    sizeof( long ),
	  sizeof f,    sizeof( float ),
	  sizeof d,    sizeof( double),
	  sizeof ld,   sizeof( long double ),
	  sizeof array, sizeof ptr, sizeof pPoint );

  return 0;
  
}
