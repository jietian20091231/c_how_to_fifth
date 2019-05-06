#include <stdio.h>

int main()
{
  char array[5];

  printf("%9s = %p\n%9s = %p\n%9s = %p\n", "array", array, "&array[0]", &array[0], "&array", &array);

  return 0;
  
}
