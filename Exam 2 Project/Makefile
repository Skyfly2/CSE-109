all: static shared test

# I consulted my notes to remind myself of the flags for generating static and shared libraries
static:
	mkdir -p build/lib
	gcc -c src/lib.c -Iinclude
	ar rs libbinarytree.a lib.o
	mv libbinarytree.a build/lib
shared:
	mkdir -p build/lib
	gcc -c src/lib.c -Iinclude
	gcc -shared -o libbinarytree.so -fpic lib.o
	mv libbinarytree.so build/lib
test: static
	mkdir -p build/bin
	gcc src/bin/test.c -c -Iinclude
	gcc test.o -lbinarytree -Lbuild/lib -o test
	mv test build/bin
clean:
	rm -rf build
	rm -f *.o
	rm -f *.a
	rm -f *.so
