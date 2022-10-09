all: descent

descent: main_program.c
	gcc -o descent main_program.c parser_helpers.c recursive_descent.c

test: all
	./descent

submission: clean
	zip your-name-here.zip *

clean:
	$(RM) descent a.out *.zip
