/*Fig. 7.13: fig07_13.c
  Attempting to modify a constant pointer to non-constant data */

#include <stdio.h>

int main(int argc, char *argv[])
{

  int x;
  int y;

  /* ptr is a constant pointer to an integer that can be modified 
     through ptr, but ptr always pointer to the same memory location */
  int * const ptr = &x;

  *ptr = 7;  /* allowed: *ptr is not const */

  printf( "x = %d\n", x );

  ptr = &y; /* error: ptr is const; can't assign new address */
  
  return 0;
}
