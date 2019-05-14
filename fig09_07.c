#include  <stdio.h>

int main(int argc, char *argv[])
{
  int *ptr;
  int x = 12345;
  int y;

  ptr = &x;
  printf( "This value of ptr is %p\n", ptr );
  printf( "This address of x is %p\n\n", &x );

  printf( "Total character printed on this line:%n", &y );
  printf( "%d\n\n", y );

  y = printf( "This line has 28 character\n%n" );
  printf( "%d characters were printed\n\n", y );

  printf( "Printing a %% in a format control string\n" );
  
  return 0;
}
