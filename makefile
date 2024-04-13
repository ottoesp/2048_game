play_2048: play_2048.o board.o game.o move_graph.o listops.o
	gcc -o play_2048 play_2048.o board.o game.o move_graph.o listops.o -Wall -g

play_2048.o: play_2048.c
	gcc -c play_2048.c -Wall -g

board.o: board.c board.h
	gcc -c board.c -Wall -g

game.o: game.c game.h board.h board.o
	gcc -c game.c board.c -Wall -g

move_graph.o: move_graph.c move_graph.h listops.o board.o
	gcc -c move_graph.c listops.c board.c -Wall -g

listops.o: listops.c listops.h
	gcc -c listops.c -Wall -g