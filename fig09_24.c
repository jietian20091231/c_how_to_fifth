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

  printf( "Enter a data in the form mm-dd-yyyy:\n" );
  scanf( "%d%*c%d%*c%d%*c%d%*c%d%*c%d", &day, &month, &year,
	 &hour, &minute, &second );

  printf( "day = %d, month = %d, year = %d,"
	  "hour = %d, minute = %d, second = %d\n",
	  day, month, year, hour, minute, second );

  return 0;
}
