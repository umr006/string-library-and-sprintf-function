CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra -std=c11 
TESTFLAGS = -lcheck -coverage -lpthread -pthread

OS := $(shell uname)
ifeq ($(OS), Darwin)
    TESTFLAGS += -lm -fprofile-arcs
else
    TESTFLAGS += -lm -lrt -lsubunit -fprofile-arcs
endif

SOURCE = s21_string.c 
HEADER = s21_string.h
OBJECTS= $(patsubst %.c, %.o, ${SOURCE})

TESTS_SOURCE = $(wildcard ./tests/test_*.c)
TESTS_OBJECTS = $(patsubst ./tests/%.c, ./tests/%.o, ${TESTS_SOURCE})
TESTS_HEADER = ./tests_includes/s21_tests.h

all: s21_string.a gcov_report

s21_string.a: ${SOURCE} $(HEADER)
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar rc s21_string.a $(OBJECTS)
	ranlib s21_string.a
	rm -rf *.o


test: s21_string.a main.c ${TESTS_SOURCE} ${TESTS_HEADER}
	$(CC) $(CFLAGS) main.c $(TESTS_SOURCE) $(TESTFLAGS) s21_string.a -o test
	./test


gcov_report: test
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	-rm -rf *.o *.gcno *.gcda *.info *.a test
open:
	open report/index.html

valgrind: s21_string.a main.c ${TESTS_SOURCE} ${TESTS_HEADER}
	$(CC) $(CFLAGS) main.c $(TESTS_SOURCE) $(TESTFLAGS) s21_string.a -o test 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test


clean:
	rm -rf *.o *.gcno *.a *.gcda
	rm -rf ./report/ *.info
	rm -rf test_report test

rebuild:	clean all

.PHONY: all s21_string.a test gcov_report valgrind clean
