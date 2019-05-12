#include <stdio.h>


int main(int argc, char *argv[])
{

  char s[] = "31298 87.375";
  int x;
  double y;

  sscanf( s , "%d%lf", &x, &y );

  printf( "%s\n%s%6d\n%s%8.3f\n", "The values stored in character array s are",
	  "integer", x , "double", y );
  
  return 0;
}
