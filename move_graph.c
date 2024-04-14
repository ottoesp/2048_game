#include "move_graph.h"

#include <stdio.h>
#include <stdlib.h>

void setProbablility(Graph *graph, double p);
void printGraphNode(Graph *graph);

Graph* newGraph(Board *board) {
    Graph *new = (Graph*)malloc(sizeof(Graph));
    assert(new);

    new->probalility = -1;
    new->board = board;
    new->visited = 0;

    for (int i = 0; i < 4; i += 1) {
        new->possiblePositions[i] = make_empty_list();
    }

    return new;
}

void setProbablility(Graph *graph, double p) {
    graph->probalility = p;
}

void printGraphNode(Graph *graph) {
    node_t *node;
    Graph *position;

    printf("Position\n");
    printBoard(graph->board);

    for (int dir = 0; dir < 4; dir += 1) {
        if (!is_empty_list(graph->possiblePositions[dir])) {
            node = get_head_node(graph->possiblePositions[dir]);
            printf("Possible positions for direction %d\n", dir);

            while (node) {
                position = (Graph*)node->data;
                printBoard(position->board);
                printf("\n");
                node = node->next;
            }
        } else {
            printf("No possible positions for direction %d\n", dir);
        }
    }
}

