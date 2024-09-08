# compiler
CC = g++

# directory
SRC_DIR = src/sources

# files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

compile: ${SRC_FILES}
	${CC} ${SRC_FILES} -o program

test: compile
	bash test_script.sh

run: compile
	./program

clean:
	rm -rf program
	rm -rf out/output.txt