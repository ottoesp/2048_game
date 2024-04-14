#include <stdio.h>
#include <stdlib.h>

#include "game.h"

Game *newGame() {
    Game *new = (Game*)malloc(sizeof(Game));
    new->board = NULL;
    return new;
}

void freeGame(Game *game) {
    freeBoard(game->board);
    free(game);
}

int getMove() {
    char c;
    while (1) {
        printf("Enter move: ");
        scanf(" %c", &c);
        switch (c) {
            case 'w':
                return UP;
            case 'a':
                return LEFT;
            case 's':
                return DOWN;
            case 'd':
                return RIGHT;
            default:
                printf("Invalid move\n");
        }
    }
}

void startGame(Game *game) {
    Board *board = newBoard();
    game->board = board;

    generateTile(board);
    generateTile(board);


    printBoard(board);
    printf("\n");

    while (1) {
        int dir = getMove();
        if (swipe(board, dir)) {
            generateTile(board);
        } else {
            printf("Invalid move\n");
        }
        printBoard(board);
        printf("\n");
    }

    printBoard(board);
    printf("\n");
}