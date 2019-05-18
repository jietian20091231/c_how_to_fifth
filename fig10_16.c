#include <stdio.h>

typedef struct {
  unsigned int face : 4;
  unsigned int suit : 2;
  unsigned int color : 1;
} Card;


void fillDeck( Card * const wDeck );
void deal( const Card * const wDeck );

int main( int argc, char *argv[] )
{

  Card deck[ 52 ];

  fillDeck( deck );
  deal( deck );
  
  return 0;
}

void fillDeck( Card * const wDeck )
{
  int i ;
  for ( i = 0; i < 52; ++i ) {
    wDeck[ i ].face = i % 13;
    wDeck[ i ].suit = i % 4;
    wDeck[ i ].color = i % 2;
  }

}

void deal( const Card * const wDeck )
{
  int i, j;

  for ( i = 0, j = i + 26; i < 25; i++, j++ ) {
    printf( "Card:%3d Suit:%2d Color:%2d\n", wDeck[ i ].face, wDeck[ i ].suit, wDeck[ i ].color );
    printf( "Card:%3d Suit:%2d Color:%2d\n", wDeck[ j ].face, wDeck[ j ].suit, wDeck[ j ].color );
    
  }

  
}



