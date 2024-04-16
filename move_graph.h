#include "listops.h"
#include "board.h"

typedef struct Position Position;
typedef struct NewTile NewTile;

typedef struct Root { // not quite sure if this is what i want it to be
    Position *currentPosition;
} Root;

typedef struct NewTile { 
    int x;
    int y;
    int value;
    double probablility;
    Position *swipesTo[4];
} NewTile;

typedef struct Position {
    Board* board;
    double probablility;
    list_t *posibleNewTiles;
} Position;

Root* newGraph(Board *board);
NewTile* newTile(int x, int y, int value);
Position* newPosition(Board* board);