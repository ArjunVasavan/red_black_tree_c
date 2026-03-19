all:
	gcc -g main.c src/rbtree.c src/rotations.c src/utils.c

clean:
	command rm a.out
