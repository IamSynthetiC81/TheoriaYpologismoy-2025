CC = gcc
FLEX = flex
BISON = bison

all: mycompiler

mycompiler: mylexer.l myanalyzer.y
	$(BISON) -d -v -r all myanalyzer.y
	$(FLEX) mylexer.l
	$(CC) -o mycompiler lex.yy.c myanalyzer.tab.c -lfl

run: mycompiler
	./mycompiler < example.la

clean:
	rm -f mycompiler lex.yy.c myanalyzer.tab.* myanalyzer.output
