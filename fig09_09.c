#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 873;
  double f = 123.94576;
  char s[] = "Happy Birthday";

  printf( "Using precision for integers\n" );
  printf( "\t%.4d\n\t%.9d\n\n", i, i );

  printf( "Using prcision for floating-point numbers\n" );
  printf( "\t%.3f\n\t%.3e\n\t%.3g\n\n", f, f, f );

  printf(  "Using prcision for strings" );
  printf(  "\t%.11s\n", s );

  printf( "%9.3f\n", 123.456789 );
  printf( "%*.*f\n", 7, 2, 98.736 );
  printf( "%*.*f\n", 7, 2, 123.456789 );
  
  
  
  
  return 0;
}
