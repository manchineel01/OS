all: compile

run:
	./program

compile: functions main

functions: functions.c functions.h
	gcc functions.c -o functions.o -lm
main: main.c functions.o
	gcc main.c -o program functions.o -lm
