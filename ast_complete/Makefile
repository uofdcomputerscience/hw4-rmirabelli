all: main.c scan.c parse.c wrap.c error.c expr.c decl.c stmt.c
	gcc main.c scan.c parse.c wrap.c error.c expr.c decl.c stmt.c -o simple -ll

parse.c: parse.y
	bison --defines=token.h --output=parse.c parse.y

scan.c: scan.l
	flex --header-file=scan.h --outfile=scan.c scan.l

test: simple
	./simple < input

clean:
	$(RM) scan.h scan.c parse.c token.h simple
