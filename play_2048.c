#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "ai.h"

int main(int argc, char *argv[]) {

    int depth;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <depth>\n", argv[0]);
        return EXIT_FAILURE;
    }
    depth = atoi(argv[1]);
    
    Board* b = newBoard();
    generateTile(b);
    generateTile(b);

    initilaiseAi(b, depth);

    printf("completed\n");
    return EXIT_SUCCESS;
}
