#ifndef BOARD_H
#define BOARD_H

#define FREE -1

typedef struct Board Board;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

Board *newBoard();
void printBoard(Board *board);
Board *setTile(Board *board, int x, int y, int value);
int getTile(Board *board, int x, int y);
int swipe(Board *board, int dir);
void freeBoard(Board *board);
void generateTile(Board *board);
Board *copyBoard(Board *board);
int cmpBoard(Board *b1, Board *b2);

#endif