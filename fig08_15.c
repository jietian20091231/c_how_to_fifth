#include <stdio.h>


int main(int argc, char *argv[])
{

  char s[ 80 ];
  int x;
  double y;

  printf( "Enter an integer and a double:\n" );
  scanf( "%d%lf", &x, &y );

  sprintf( s, "integer:%6d\ndouble:%8.2f", x, y );

  printf( "%s\n%s\n", "The formatted output stored in array s is :", s );
  
  return 0;
}
