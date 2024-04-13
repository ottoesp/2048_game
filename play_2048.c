#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "move_graph.h"

int main(int argc, char **argv) {
    // Game *game = newGame();
    // startGame(game);
    
    Board* b = newBoard();
    generateTile(b);
    generateTile(b);

    Graph *g = newGraph(b);

    printf("completed\n");
    return EXIT_SUCCESS;
}
