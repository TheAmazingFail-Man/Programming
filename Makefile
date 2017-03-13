all: hello // команда запуска makefile. make hello

main.o: main.c 
gcc -c main.c 

int_vector.o: int_vector.h 
gcc -c int_vector.c 

int_vector.o: int_vector.c 
gcc -c int_vecor.c 

hello: main.o int_vector.h int_vector.c // цель 
gcc -o hello main.o int_vector.h int_vector.c 
rm -rf *.o// mylib/*.o рекурсивная проверка во всех файлах и дерикториях
//all: 
//gcc -Wall main.c int_vector.c int_vector.h -o main 
//clean: 
//rm -f main 