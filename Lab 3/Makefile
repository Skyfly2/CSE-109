all: hello
	mkdir -p build
	mkdir -p build/bin
	mkdir -p build/objects
	mv *.o build/objects
	mv hello build/bin
hello: factorial.o main.o hello.o
	gcc main.o factorial.o  hello.o -o hello
factorial.o: src/factorial.c
	gcc src/factorial.c -c -I include
main.o: src/main.c
	gcc src/main.c -c -I include
hello.o: src/hello.c
	gcc src/hello.c -c -I include
clear:
	rm -rf build
	

