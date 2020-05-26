all: main
	mkdir -p build/bin
	mkdir -p build/lib
	mkdir -p build/objects
	mv *.o build/objects
	mv *.a build/lib
	mv main build/bin

main: main.o libhashset.a
	gcc main.o -o main -lhashset -llinkedlist -L. -Llib

test: test.o libhashset.a
	gcc test.o -o test -lhashset -llinkedlist -L. -Llib
	mkdir -p build/bin
	mkdir -p build/lib
	mkdir -p build/objects
	mv *.o build/objects
	mv *.a build/lib

test.o: src/bin/test.c
	gcc src/bin/test.c -c -I include -I lib

main.o: src/bin/main.c
	gcc src/bin/main.c -c -I include -g -I lib

libhashset.a: src/lib.c
	gcc src/lib.c -c -I include -I lib
	ar rs libhashset.a lib.o

clean:
	rm -rf build
	rm -f test
	rm -f main