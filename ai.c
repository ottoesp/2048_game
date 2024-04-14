#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

void getPossiblePositions(list_t *list, Board *board, int dir);
void generateChildren(Graph *graph);

typedef struct ai {
    Graph *positionGraph;
} ai;

void generateChildren(Graph *graph) {
    for (int dir = 0; dir < 4; dir += 1) {
        getPossiblePositions(graph->possiblePositions[dir], graph->board, dir);
    }
}

void getPossiblePositions(list_t *list, Board *board, int dir) {
    Board *swiped, *positionBoard;
    Graph *position;

    swiped = copyBoard(board);
    int moved = swipe(swiped, dir);

    if (moved) {
        int val;
        for (int y = 0; y < 4; y += 1) {
            for (int x = 0; x < 4; x += 1) {
                val = getTile(swiped, x, y);
                if (val == FREE) {

                    positionBoard = copyBoard(swiped);
                    setTile(positionBoard, x, y, 1);

                    position = newGraph(positionBoard);
                    setProbablility(position, 0.9);
                    insert_at_foot(list, position);

                    positionBoard = copyBoard(swiped);
                    setTile(positionBoard, x, y, 2);

                    setProbablility(position, 0.1);
                    position = newGraph(positionBoard);
                    insert_at_foot(list, position);
                }
            }
        }
    }
}

void buildTree(Graph *graph, int depth, int *leaves, int *nodes) {
    if (depth == 0) {
        *leaves += 1;
        return;
    }

    *nodes += 1;
    generateChildren(graph);

    for (int dir = 0; dir < 4; dir += 1) {
        if (!is_empty_list(graph->possiblePositions[dir])) {
            node_t *node = get_head_node(graph->possiblePositions[dir]);
            while (node) {
                buildTree((Graph*)node->data, depth - 1, leaves, nodes);
                node = node->next;
            }
        }
    }
}

ai *initilaiseAi(Board* board, int depth) {
    ai *player = (ai*)malloc(sizeof(ai));
    player->positionGraph = newGraph(board);

    int count = 0;
    int nodes = 0;
    buildTree(player->positionGraph, depth, &count, &nodes);
    printf("Number of leaves: %d\n", count);
    printf("Number of nodes: %d\n", nodes);

    return player;
}