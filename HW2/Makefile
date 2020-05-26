all: main.o lib.o
	mkdir -p build/bin
	mkdir -p build/objects
	gcc lib.o main.o -o my_which
	mv main.o build/objects
	mv lib.o build/objects

main.o: src/bin/main.c
	gcc src/bin/main.c -c -I include

lib.o: src/lib.c
	gcc src/lib.c -c -I include

clean: 
	rm -rf build

install:
	mv my_which /root/bin/my_which