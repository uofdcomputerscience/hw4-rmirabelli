all: main.c scan.c parse.c wrap.c error.c
	gcc main.c scan.c parse.c wrap.c error.c -o simple -ll

parse.c: parse.y
	bison --defines=token.h --output=parse.c parse.y

scan.c: scan.l
	flex --outfile=scan.c scan.l

test: simple
	./simple < input

clean:
	$(RM) scan.c parse.c token.h simple
