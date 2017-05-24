all: rogue
clean:
	rm -rf rogue a.out

rogue:
	gcc -lncurses rogue.c -o rogue
