#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { DEFAULT , CONTINUE, WON, LOST };

struct _gameble_try {
    int i_status;          // WON OR LOST
    int tryCounter;       // tryCounter
    int myPoint;
};

int rollDice( void );

void gameble( struct _gameble_try* gameble_try );

int main()
{
    int i;    

    srand( time( NULL ) );

    struct _gameble_try gameble_try;
    gameble_try.i_status = 0;
    gameble_try.tryCounter = 0;
    gameble_try.myPoint = 0;

    int gamble_count = 100;
    int lost = 0;
    int won  = 0;


    for( i = 1; i <=100; i++ )
    {
        gameble( &gameble_try );
        printf( "[%d] Game is %s, point is %d, tryCounter is %d.\n", i , ( 0 == gameble_try.i_status)? "LOST" : "WON", 
              gameble_try.myPoint, gameble_try.tryCounter );

        if( 0 == gameble_try.i_status )
            lost++;
        else
            won++;

        gameble_try.i_status = 0;
        gameble_try.tryCounter = 0;
        gameble_try.myPoint = 0;              
    }

    printf( "Gamble count %d, lost %d, won %d.\n", gamble_count, lost, won );

    return 0;
}

void gameble( struct _gameble_try* gameble_try )
{
    int sum;
    int myPoint;

    enum Status gameStatus;    

    sum = rollDice();

    switch( sum ) {
        case 7:
        case 11:
            gameStatus = WON;
            gameble_try -> i_status = 1;
            gameble_try -> myPoint = sum;
            gameble_try -> tryCounter = 1;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            gameble_try -> myPoint = sum;
            gameble_try -> tryCounter = 1;            
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sum;
            printf( "Point is %d\n", myPoint );
            break;
    }

    gameble_try -> tryCounter = 1;

    while( gameStatus == CONTINUE ) {
        sum = rollDice();
        gameble_try -> tryCounter++;

        if( sum == myPoint ) {
            gameStatus = WON;
            gameble_try -> i_status = 1;
            gameble_try -> myPoint = myPoint;
        }
        else {
            if( sum == 7 ) {
                gameStatus = LOST;
                gameble_try -> myPoint = myPoint;                
            }
        }

    }

    // if( gameStatus == WON ) {
    //     printf( "Player wins.\n" );
    // } else {
    //     printf( "Player loses.\n" );
    // }    
}

int rollDice( void )
{
    int die1;
    int die2;
    int workSum;

    die1 = 1 + ( rand() % 6 );
    die2 = 1 + ( rand() % 6 );
    workSum = die1 + die2;

    printf( "Player rolled %d + %d = %d\n", die1, die2, workSum );
    return workSum;
}