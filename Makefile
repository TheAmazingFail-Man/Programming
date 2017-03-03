all:
	gcc -Wall main.c int_vector.c -o main
clean:
	rm -f main
