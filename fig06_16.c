#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void random_generator(int a[]);
void mean(const int a[]);
void median(int a[]);
void mode(int freq[], const int answer[]);
void bubble_sort(int a[]);
void print_array(const int a[]);



int main(int argc, char *argv[])
{
  int frequency[ 10 ] = { 0 };
  int response[ SIZE ] = { 0 };

  srand( time(NULL) );

  random_generator( response );

  mean( response  );
  median( response );
  mode( frequency, response );
  
  return 0;
}

void print_array(const int a[])
{
  int j;

  for(j = 0; j < SIZE; j++) {
    if (j % 20 == 0) {
      printf("\n");
    }

    printf("%2d", a[j]);
  }
}


void bubble_sort(int a[])
{
  int i, j, tmp;
  for(i = 0; i< SIZE - 1; i++) {
    for(j = i + 1; j < SIZE; j++) {
      if(a[i] >= a[j]) {
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
      }
    }
  }
}

void random_generator(int a[])
{
  int i;
  for(i = 0; i < SIZE; i++) {
    a[i] = 1 + rand() % 9 ;
  }
}


void mean( const int answer[] )
{
  int j;
  int total = 0;

  printf( "%s\n%s\n%s\n", "*************", "    Mean    ", "*********" );

  for(j = 0; j < SIZE; j++) {
    total += answer[ j ];
  }

  printf( "The mean is the average value of the data\n"
	  "items. The mean is equal to the total of\n"
	  "all the data items divided by the number\n"
	  "of data items ( %d ). The mean value for\n"
	  "this run is %d / %d = %.4f\n\n",
	  SIZE, total, SIZE, ( double ) total / SIZE );
  
}


void median( int answer[] )
{
  printf( "\n%s\n%s\n%s\n%s", "************", "   Median   ", "************",
	  "The unsorted array of responses is" );

  print_array( answer );

  bubble_sort( answer );
  
  printf( "\n\nThe sorted array is" );
  print_array( answer );

  printf( "\n\nThe median is element %d of\n"
	  "the sorted %d element array.\n"
	  "For this run the median is %d\n\n",
	  SIZE / 2, SIZE, answer[ SIZE / 2 ] );
  
}

void mode( int freq[], const int answer[] )
{
  int rating;
  int j;
  int h;
  int largest = 0;
  int modeValue = 0;

  printf( "\n%s\n%s\n%s\n", "************", "    Mode    ", "************" );

  for ( rating = 1; rating <= 9; rating++ ) {
    freq[ rating ] = 0;
  }

  for ( j = 0; j < SIZE; j++ ) {
    ++freq[ answer[ j ] ];
  }

  printf( "%s%11s%19s\n\n%54s\n%54s\n\n",
	  "Response", "Frequency", "Histogram",
	  "1    1    2    2", "5    0    5    0    5" );

  for ( rating = 1; rating <= 9; rating++ ) {
    printf("%8d%11d          ", rating, freq[ rating ] );

    if ( freq[ rating ] > largest ) {
      largest = freq[ rating ];
      modeValue = rating;
    }

    for ( h = 1; h <= freq[ rating ]; h++ ) {
      printf( "*" );
    }

    printf("\n");
  }

  printf( "The mode is the most frequency value.\n"
	  "For this run the mode is %d which occurred"
	  " %d times.\n", modeValue, largest );



  
}








