all: main

main: list.o main.o
	gcc src/dstring.o src/main.o -o main
list.o: src/dstring.c
	gcc -c src/dstring.c -o src/dstring.o
main.o: src/main.c
	gcc -c src/main.c -o src/main.o
clean:
	rm src/*.o
