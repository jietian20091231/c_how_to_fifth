#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char x[] = "Happy Birthday to you";
  char y[ 25 ];
  char z[ 15 ];

  printf( "x len eq %ld\n", sizeof( x ) / sizeof( char ) );

  int i;
  for (i = 0; i < sizeof( x ) / sizeof( char ); i++) {
    printf( "x[ %d ] = %c( %d )\n", i, x[ i ], x[ i ] );
    
  }


  printf("%s%s\n%s%s\n",
	 "The string in array x is : ", x,
	 "The string in array y is : ", strcpy( y, x ) );

  //printf( "n = %ld", sizeof( z ) / sizeof( char ) - 1 );
  strncpy( z, x, sizeof( z ) / sizeof( char ) - 1 );
  z[ sizeof( z ) / sizeof( char ) - 1 ] = '\0';

  printf("The string in array z is : %s\n", z);
  
  return 0;
}
