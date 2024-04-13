#include "move_graph.h"
#include "board.h"

typedef struct Graph {
    list_t *possiblePositions[4];
    Board *board;
} Graph;

Graph* newGraph(Board *board) {
    Graph *new = (Graph*)malloc(sizeof(Graph));
    assert(new);

    new->board = board;

    // TODO: Might be more efficient if we have move make a new board
    for (int dir = 0; dir < 4; dir += 1) {
        new->possiblePositions[dir] = make_empty_list();
    }

    return new;
}