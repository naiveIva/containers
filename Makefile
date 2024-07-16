UNAME := $(shell uname)
CC=g++
CFLAGS= -Wall -Wextra -Werror -pedantic -fsanitize=address
CPPFLAGS = -lstdc++
HEADERS:=$(shell find . -maxdepth 3 -name "s21_*.h")
TESTS= tests/test_main.cc
RESULT=./build/test

.PHONY: all
all: test

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(RESULT) test report *.gc* *.out *.gch log.txt gcov* cov build

test:
	cmake -S . -B build
	cmake --build build
	$(RESULT)

.PHONY: valgrind
valgrind: test
	valgrind --log-fd=1 --leak-check=full --log-file=log.txt -s $(RESULT)

