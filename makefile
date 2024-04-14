# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRC_FILES = ai.c board.c game.c listops.c move_graph.c play_2048.c
# Header files
HEADER_FILES = ai.h board.h game.h listops.h move_graph.h

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Main executable
EXECUTABLE = play_2048

.PHONY: all clean

# Default target
all: $(EXECUTABLE)

# Rule to compile object files
%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target
clean:
	rm -f $(EXECUTABLE) $(OBJ_FILES)
