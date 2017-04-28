all: main

main: main.o command.o coder.o
	gcc -Wall -Werror -o main main.o command.o coder.o
	rm -rf *.o

main.o: src/main.c
	gcc -Wall -Werror -o main.o -c src/main.c

command.o: src/command.c
	gcc -Wall -Werror -o command.o -c src/command.c

coder.o: src/coder.c
	gcc -Wall -Werror -o coder.o -c src/coder.c