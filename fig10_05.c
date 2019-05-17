#include <stdio.h>
#include <string.h>


typedef union {
  char c;
  short s;
  int i;
} Number;

int main( void )
{
  Number num;

  //  memset( &num, 0, sizeof( num ) );
  num.i = 0;
  printf( "1, num.c = %d, num.s = %d, num.i = %d\n", num.c, num.s, num.i );  
  
  printf( "sizeof( char ) = %zu, sizeof( short ) = %zu, sizeof( int ) = %zu\n" ,
	  sizeof( char ), sizeof( short ), sizeof( int ) );
  printf( "sizeof( num ) = %zu\n", sizeof( num ) );

  printf( "num.c = %p, num.s = %p, num.i = %p\n", &( num.c ), &( num.s ),&( num.i ) );
  printf( "&num = %p\n", &num );

  num.c = 'a';
  printf( "2, num.c = 'a': num.c = %d, num.s = %d, num.i = %d\n", num.c, num.s, num.i );

  num.s = 97;
  printf( "3, num.s = 97 : num.c = %d, num.s = %d, num.i = %d\n", num.c, num.s, num.i );

  num.i = 65535;
  printf( "4, num.i = 65535 : num.c = %d, num.s = %d, num.i = %d\n", num.c, num.s, num.i );

  return 0;
}
