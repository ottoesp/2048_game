#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

void getPossiblePositions(list_t *list, Board *board, int dir);
void generateChildren(Root *graph);

typedef struct ai {
    Root *positionGraph;
} ai;


// since current position will already have the new tile added, start from next position
void getNextPositions(Position *position, int dir) {
    
}

ai *initilaiseAi(Board* board, int depth) {
    ai *player = (ai*)malloc(sizeof(ai));
    assert(player);

    return player;
}