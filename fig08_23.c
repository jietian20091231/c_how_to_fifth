#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  const char *string = "This is a test";
  const char c1 = 'a';
  const char c2 = 'z';

  if ( strchr( string, c1 ) != NULL ) {
    printf( "\'%c\' was found in \"%s\".\n", c1, string );
  } else {
    printf( "\'%c\' was not found in \"%s\".\n", c1, string );    
  }

  if ( strchr( string, c2 ) != NULL ) {
    printf( "\'%c\' was found in \"%s\".\n", c2, string );
  } else {
    printf( "\'%c\' was not found in \"%s\".\n", c2, string );    
  }  
  
  return 0;
}
