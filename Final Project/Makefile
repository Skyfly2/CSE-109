all: lib
	mkdir -p build/bin
	mkdir -p build/lib
	mkdir -p build/objects
	gcc -c src/bin/main.c -g -lhashset -llinkedlist -Llib -Iinclude
	gcc main.o lib.o -o main -g -lhashset -llinkedlist -Llib -Iinclude
	mv *.a build/lib
	mv *.o build/objects
	mv main build/bin

lib: src/lib.c
	gcc -c -g src/lib.c -Iinclude
	ar rs libbenchmarker.a lib.o

clean:
	rm -rf build
