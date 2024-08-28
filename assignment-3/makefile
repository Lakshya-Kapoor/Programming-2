# compiler
CC = g++

# directory
SRC_DIR = src/sources

# files
SRC_FILES = ${SRC_DIR}/congregation.cpp ${SRC_DIR}/venue.cpp ${SRC_DIR}/parsing_input.cpp ${SRC_DIR}/utils.cpp ${SRC_DIR}/date.cpp ${SRC_DIR}/main.cpp

compile: ${SRC_FILES}
	${CC} ${SRC_FILES} -o program

run: compile
	./program

clean:
	rm -rf program