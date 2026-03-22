all:
	gcc -g main.c src/*.c

clean:
	command rm a.out
