#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{

  printf( "%d\n", 455 );
  printf( "%i\n", 455 );
  printf( "%d\n", +455);
  printf( "%d\n", -455 );
  printf( "%hd\n", ( short )32768 );
  printf( "%ld\n", time( NULL ) );
  printf( "%o\n", 455 );
  printf( "%u\n", 455 );
  printf( "%u\n", -455 );
  printf( "%x\n" , 455 );
  printf( "%X\n", 455 );
  
  
  return 0;
}
