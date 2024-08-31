# compiler
CC = g++

# directory
SRC_DIR = src/sources

# files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

compile: ${SRC_FILES}
	${CC} ${SRC_FILES} -o program

run: compile
	./program

clean:
	rm -rf program