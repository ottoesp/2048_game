#include "listops.h"
#include "board.h"

typedef struct Graph {
    list_t *possiblePositions[4];
    Board *board;
    double probalility;
    int visited;
} Graph;

Graph* newGraph(Board *board);
void generateChildren(Graph *graph);
void printGraphNode(Graph *graph);
void setProbablility(Graph *graph, double p);