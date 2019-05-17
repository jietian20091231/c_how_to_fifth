#include <stdio.h>

struct card {
  char *face;
  char *suit;
};

void changeCard( struct card );
void changeCardByPointer( struct card* );

int main( void )
{

  struct card aCard = { "Ace", "Spades" };
  struct card *cardPtr;
  
  cardPtr = &aCard;

  printf( "%s%s%s\n%s%s%s\n%s%s%s\n",
	  aCard.face, " of ", aCard.suit,
	  cardPtr -> face, " of ", cardPtr -> suit,
	  ( *cardPtr ).face, " of ", ( *cardPtr ).suit );

  printf( "Call function prototype [void changeCard( struct card )]\n" );
  changeCard( aCard );
  printf( "aCard = %s, aCard = %s\n", aCard.face, aCard.suit );
  printf( "-----------------------------\n" );

  printf( "Call function prototype [void changeCardByPointer( struct card* )]\n" );
  changeCardByPointer( cardPtr );
  printf( "aCard = %s, aCard = %s\n", aCard.face, aCard.suit );
  printf( "-----------------------------\n" );

  return 0;
}


void changeCard( struct card aCard )
{

  aCard.face = "King";
  aCard.suit = "Heart";
}

void changeCardByPointer( struct card *aCard )
{

  aCard -> face = "King";
  aCard -> suit = "Heart";
}
