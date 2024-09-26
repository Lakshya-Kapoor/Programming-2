# compiler
CC = g++

# Source directory
SRC_DIR = src

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

compile: $(SRC_FILES)
	$(CC) $(SRC_FILES) -o exe

run: compile
	./exe

clean:
	rm -rf exe