all: main
	mkdir -p build/bin
	mkdir -p build/lib
	mkdir -p build/objects
	mv *.o build/objects
	mv *.a build/lib
	mv main build/bin

main: main.o liblinkedlist.a
	gcc main.o -o main -llinkedlist -L.

test: test.o liblinkedlist.a
	gcc test.o -o test -llinkedlist -L.
	mkdir -p build/bin
	mkdir -p build/lib
	mkdir -p build/objects
	mv *.o build/objects
	mv *.a build/lib

test.o: src/bin/test.c
	gcc src/bin/test.c -c -I include

main.o: src/bin/main.c
	gcc src/bin/main.c -c -I include

liblinkedlist.a: src/lib.c
	gcc src/lib.c -c -I include
	ar rs liblinkedlist.a lib.o

clean:
	rm -rf build
	rm -f test
	rm -f main