# Compiler
CC = gcc

# Target executable
TARGET = run

# Directories
SRC_DIR = src

# Source files
SRC = ${SRC_DIR}/main.c ${SRC_DIR}/venue.c ${SRC_DIR}/event.c ${SRC_DIR}/event_utils.c ${SRC_DIR}/venue_utils.c ${SRC_DIR}/parsing_input.c

# Compile the program
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

# Clean up
clean:
	rm -f $(TARGET)

.PHONY: all test clean