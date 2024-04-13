#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#define FREE -1

typedef struct Board {
    int rows[4][4];
} Board;

Board *newBoard() {
    Board *new = (Board*)malloc(sizeof(Board));
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 4; j += 1) {
            (new->rows)[i][j] = FREE;
        }
    }
    return new;
}

void printBoard(Board *board) {
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 4; j += 1) {
            if ((board->rows)[i][j] == FREE) {
                printf("|   ");
            } else {
                printf("|%2d ", (board->rows)[i][j]);
            }
        }
        printf("|\n-----------------\n");
    }
}

void setTile(Board *board, int x, int y, int value) {
    (board->rows)[y][x] = value;
}

void moveTile(Board *board, int startX, int startY, int destX, int destY) {
    int val = (board->rows)[startY][startX];
    (board->rows)[startY][startX] = FREE;
    (board->rows)[destY][destX] = val;
}


int doCollapse(int *currTile, int currIdx, int *lastTile, int *lastIdx, int *nextTile, int INCDIR, int *canCollapse) {
    int hasMoved = 0;
    // Column is always > last tile
    if (*currTile != FREE) {

        if (*canCollapse && *currTile == *lastTile) {
            // lastTile is collapsable so collapse
            *currTile = FREE;
            *lastTile += 1;
            *canCollapse = 0;

            hasMoved = 1;
        } else if (*lastTile != FREE) {
            // lastTile is not empty but not collapsable so move to next to it
            if (*lastIdx + INCDIR != currIdx) { 
                *nextTile = *currTile;
                *currTile = FREE;
                hasMoved = 1;
            }
            *canCollapse = 1;
            *lastIdx += INCDIR;
        } else {
            // lastTile is empty so move to it
            *lastTile = *currTile;
            *currTile = FREE;
            *canCollapse = 1;
            hasMoved = 1;
        }
    }

    return hasMoved; 
}

int swipe(Board *board, Direction dir) { 
    int *currTile, lastIdx, *lastTile, *nextTile, canCollapse;

    int hasMoved = 0;

    if (dir == LEFT) {
        
        for (int row = 0; row < 4; row += 1) {
        
            lastIdx = 0;
            canCollapse = 1;

            for (int column = 1; column < 4; column += 1) {
                currTile = &(board->rows)[row][column]; 
                lastTile = &(board->rows)[row][lastIdx];
                nextTile = &(board->rows)[row][lastIdx + 1];

                hasMoved = doCollapse(currTile, column, lastTile, &lastIdx, nextTile, 1, &canCollapse) ? 1 : hasMoved;
            }
        }
    } else if (dir == RIGHT) {
        for (int row = 0; row < 4; row += 1) {
        
            lastIdx = 3;
            canCollapse = 1;

            for (int column = 2; column >= 0; column -= 1) {
                currTile = &(board->rows)[row][column]; 
                lastTile = &(board->rows)[row][lastIdx];
                nextTile = &(board->rows)[row][lastIdx - 1];

                hasMoved = doCollapse(currTile, column, lastTile, &lastIdx, nextTile, -1, &canCollapse)  ? 1 : hasMoved;
            }
        }
    } else if (dir == UP) {
        for (int column = 0; column < 4; column += 1) {
        
            lastIdx = 0;
            canCollapse = 1;

            for (int row = 1; row < 4; row += 1) {
                currTile = &(board->rows)[row][column]; 
                lastTile = &(board->rows)[lastIdx][column];
                nextTile = &(board->rows)[lastIdx + 1][column];

                hasMoved = doCollapse(currTile, row, lastTile, &lastIdx, nextTile, 1, &canCollapse)  ? 1 : hasMoved;
            }
        }
    } else if (dir == DOWN) {
        for (int column = 0; column < 4; column += 1) {
        
            lastIdx = 3;
            canCollapse = 1;

            for (int row = 2; row >= 0; row -= 1) {
                currTile = &(board->rows)[row][column]; 
                lastTile = &(board->rows)[lastIdx][column];
                nextTile = &(board->rows)[lastIdx - 1][column];

                hasMoved = doCollapse(currTile, row, lastTile, &lastIdx, nextTile, -1, &canCollapse) ? 1 : hasMoved;
            }
        }
    }

    return hasMoved;
}

void generateTile(Board *board) {
    int x, y;
    time_t t;
    srand((unsigned) time(&t));
    do {
        x = rand() % 4;
        y = rand() % 4;
    } while ((board->rows)[y][x] != FREE);

    (board->rows)[y][x] = (rand() % 10) >= 9 ? 2 : 1;
}

void freeBoard(Board *board) {
    free(board);
}