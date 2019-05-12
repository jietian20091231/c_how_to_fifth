#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
  const char *string1 = "This value is 3.14159";
  const char *string2 = "1245";

  printf( "string1 lenght is %d\n", strlen( string1 ) );

  printf( "%s%s\n%s%s\n\n%s\n%s%u\n",
	  "string1 = ", string1, "string2 = ", string2,
	  "The length of the inital segment of string1",
	  "containing no characters from string2 = ",
	  strcspn( string1, string2 ) );
  
  return 0;
}
