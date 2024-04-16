#include "move_graph.h"

#include <stdio.h>
#include <stdlib.h>

Root* newGraph(Board *board) {
    Root *new = (Root*)malloc(sizeof(Root));
    assert(new);

    new->currentPosition = newPosition(board);

    return new;
}

NewTile* newTile(int x, int y, int value) {
    NewTile *new = (NewTile*)malloc(sizeof(NewTile));
    assert(new);

    new->x = x;
    new->y = y;
    new->value = value;
    new->probablility = (value == 1 ? 0.9 : 0.1);

    for (int i = 0; i < 4; i++) {
        new->swipesTo[i] = NULL;
    }

    return new;
}

Position* newPosition(Board* board) {
    Position *new = (Position*)malloc(sizeof(Position));
    assert(new);

    new->board = board;
    new->probablility = 0.0;
    new->posibleNewTiles = make_empty_list();

    return new;
}