all: main.c scan.c parse.c wrap.c error.c expr.c statement.c decl.c util.c
	gcc main.c scan.c parse.c wrap.c error.c expr.c statement.c decl.c util.c -o compiler -ll

parse.c: parse.y
	bison --defines=token.h --output=parse.c parse.y

scan.c: scan.l
	flex --header-file=scan.h --outfile=scan.c scan.l

test: all 
	./compiler < input

test2: all
	./compiler < input2

test3: all
	./compiler < input2 > generated.c
	gcc generated.c -o program
	./program

test4: all
	./compiler < input3 > generated.c
	gcc generated.c -o program
	./program

clean:
	$(RM) scan.h scan.c parse.c generated.c token.h compiler program

