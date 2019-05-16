#include <stdio.h>
#include <time.h>

int main( void )
{

  int month;
  int day;
  int year;
  int hour;
  int minute;
  int second;

  char time_s[ 20 ] = { 0 };
  
  printf( "Enter a data in the form mm-dd-yyyy:" );
  scanf( "%d%*c%d%*c%d%*c%d%*c%d%*c%d", &day, &month, &year,
	 &hour, &minute, &second );

  printf( "day = %d, month = %d, year = %d,"
	  "hour = %d, minute = %d, second = %d\n",
	  day, month, year + 1900, hour, minute, second );

  return 0;
}
