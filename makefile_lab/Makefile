all: hello
	mkdir -p build
	mkdir -p build/bin
	mkdir -p build/objects
	mv hello.o build/objects
	mv factorial.o build/objects
	mv main.o build/objects
	gcc build/objects/main.o build/objects/factorial.o  build/objects/hello.o -o hello -I include
	mv hello build/bin
hello: factorial.o main.o
	gcc src/hello.c -c -I include
factorial.o:
	gcc src/factorial.c -c -I include
main.o: 
	gcc src/main.c -c -I include
clear:
	rm -rf build
	

