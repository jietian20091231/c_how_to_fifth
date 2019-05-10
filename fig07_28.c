/*Fig. 7.28: fig07_28.c
  Demonstrating an array of pointers of functions */
#include <stdio.h>

void function1( int a );
void function2( int b );
void function3( int c );

int main( void )
{

  /* initialize array of 3 pointers to functions that each take an
     int argument and return void */
  void (*f[3])( int ) = { function1, function2, function3 };

  int choice;

  printf( "Enter a number between 0 and 2, 3 to end: " );
  scanf( "%d", &choice );

  while ( choice >= 0 && choice < 3 ) {
    (*f[ choice ])( choice );
    printf( "Entet a number between 0 and 2, 3 to end : " );
    scanf( "%d", &choice );
  }

  return 0;
}


void function1( int a )
{
  printf( "You entered %d so function1 was called\n\n", a );
}


void function2( int a )
{
  printf( "You entered %d so function2 was called\n\n", a );  
}


void function3( int a )
{
  printf( "You entered %d so function3 was called\n\n", a );  
}
