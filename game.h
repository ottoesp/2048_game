#include "board.h"

typedef struct {
    Board *board;
    int score;
} Game;

Game *newGame();
void freeGame(Game *game);
void startGame(Game *game);