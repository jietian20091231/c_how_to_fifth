// crt_memcpy.c
// Illustrate overlapping copy: memmove always handles it correctly; memcpy may handle
// it correctly.

#include <memory.h>
#include <string.h>
#include <stdio.h>

char str[7] = "112233";

int main( void )
{
    char str1[ sizeof( str ) / sizeof( char )];
    char str2[ sizeof( str ) / sizeof( char )];

    memcpy( str1, str, 7 );
    memcpy( str2, str, 7 );

    printf( "str + 2 = %s\n", str + 2 );
  
    printf( "The string: %s\n", str1 );
    memcpy( str1 + 2, str1, 4 );
    printf( "New string: %s\n", str1 );

    printf( "The string: %s\n", str2 );
    memmove( str2 + 2, str2, 4 );
    printf( "New string: %s\n", str2 );
}
