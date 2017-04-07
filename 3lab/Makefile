all: main

main: main.o command.o
	gcc -Wall -Werror -o bin/main build/main.o build/command.o
	rm -rf build/*

main.o: src/main.c
	gcc -Wall -Werror -o build/main.o -c src/main.c

command.o: src/command.c
	gcc -Wall -Werror -o build/command.o -c src/command.c

//coder.o: src/coder.c gcc -Wall -Werror -o build/coder.o -c src/coder.c
