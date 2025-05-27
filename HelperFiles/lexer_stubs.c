#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dummy yylval for lexer-only test
typedef union {
    char* string;
} YYSTYPE;
YYSTYPE yylval;

// Dummy line_num
int line_num = 1;

// Dummy find_macro
char* find_macro(const char* name) { return NULL; }