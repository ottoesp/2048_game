#ifndef BOARD_H
#define BOARD_H

typedef struct Board Board;
typedef enum {
    UP, 
    RIGHT,
    DOWN,
    LEFT
} Direction;

Board *newBoard();
void printBoard(Board *board);
void setTile(Board *board, int x, int y, int value);
int swipe(Board *board, Direction dir);
void freeBoard(Board *board);
void generateTile(Board *board);

#endif