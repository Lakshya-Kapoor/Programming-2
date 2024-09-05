# compiler
CC = g++

# directories
SRC_DIR = src

# files
SRC_FILES = ${SRC_DIR}/main.cpp ${SRC_DIR}/venue.cpp ${SRC_DIR}/venue_manager.cpp ${SRC_DIR}/event.cpp ${SRC_DIR}/day.cpp ${SRC_DIR}/parsing_input.cpp

compile: ${SRC_FILES}
	${CC} ${SRC_FILES} -o program

test: compile
	bash test.sh

run: compile
	./program

clean:
	rm -f program
	rm -rf results/output.txt