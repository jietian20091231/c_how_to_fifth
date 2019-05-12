#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

  const char* string1 = "A zoo has many animals include zebras";
  char* c = "za";

  printf( "%s\n%s'%c'%s\"%s\"\n",
	  "The remainder of string1 beginning with the",
	  "last occurrence of character ", *( c + 1 ), " is: ", strrchr( string1, *( c + 1 ) ) );
  char* s = strpbrk( string1, c );
  printf( "s = %s\n", s);

  
  return 0;
}
