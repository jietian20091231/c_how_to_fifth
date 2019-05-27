#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *inFilePtr;
	FILE *outFilePtr;
	char buff[ 1024 ] = { 0 };
	size_t len = 0L;

	if ( argc != 3) {
		printf( "Usage: mycopy infile, outfile\n" );
	} else {
		if ( ( inFilePtr = fopen( argv[1], "rb" ) ) != NULL ) {

			if ( ( outFilePtr = fopen( argv[2], "wb") ) != NULL ) {
				while( ( len = fread( buff,  1, 1024, inFilePtr ) ) > 0 ) {
					printf( "len = %u ", len );
					fwrite( buff , 1, len , outFilePtr );
				}

				fclose( inFilePtr );
				fclose( outFilePtr );
			}
		}
	}

	return 0;
}
