bison -d -v -r all pi_parser.y
flex pi_lex.l
gcc -o mycomp pi_parser.tab.c lex.yy.c cgen.c -lfl