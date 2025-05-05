%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int line_number;
extern FILE *yyin;

void yyerror(const char *msg) {
    fprintf(stderr, "Syntax error in line %d: %s\n", line_number, msg);
    exit(1);
}

void debug_print(const char* str) {
    fprintf(stderr, "debug: %s\n", str);
}
%}



%union {
    char* string;
}

%type <string> stmt stmt_list expression function main_function

%token <string> IDENTIFIER CONST_INT CONST_FLOAT CONST_STRING
%token CONST_BOOL_TRUE CONST_BOOL_FALSE

%token KW_INTEGER KW_SCALAR KW_STR KW_BOOL KW_CONST
%token KW_IF KW_ELSE KW_ENDIF
%token KW_FOR KW_IN KW_ENDFOR
%token KW_WHILE KW_ENDWHILE
%token KW_BREAK KW_CONTINUE KW_NOT KW_AND KW_OR
%token KW_DEF KW_ENDDEF KW_MAIN KW_RETURN
%token KW_COMP KW_ENDCOMP KW_OF

%token OP_ASSIGN OP_PLUSEQ OP_MINUSEQ OP_MULTEQ OP_DIVEQ OP_MODEQ OP_DEFINE
%token OP_EQ OP_NEQ OP_LT OP_LEQ OP_GT OP_GEQ
%token OP_PLUS OP_MINUS OP_MULT OP_DIV OP_MOD OP_POW
%token LPAREN RPAREN LBRACKET RBRACKET COLON SEMICOLON COMMA DOT

%%

program:
    function main_function
    ;


function:
    KW_DEF IDENTIFIER LPAREN RPAREN COLON stmt_list KW_ENDDEF SEMICOLON
    {
        printf("void %s() {\n%s}\n\n", $2, $6);
        $$ = strdup(""); // optional
    }
    ;

main_function:
    KW_DEF KW_MAIN LPAREN RPAREN COLON stmt_list KW_ENDDEF SEMICOLON
    {
        /* successfullly parsed the main function */
        /* e.g. def main(): */

        debug_print("Parsed main function");

        char* code = malloc(strlen($6) + 128);
        sprintf(code, "#include \"lambdalib.h\"\n\nint main() {\n%sreturn 0;\n}\n", $6);
        printf("%s", code);
        $$ = code;
    }
    ;

stmt_list:
    /* empty */           { $$ = strdup(""); }
    | stmt_list stmt      {
        char* tmp = malloc(strlen($1) + strlen($2) + 2);
        sprintf(tmp, "%s%s", $1, $2);
        $$ = tmp;
    }
    ;

stmt:
    IDENTIFIER OP_ASSIGN expression SEMICOLON
    {
        /* successfullly parsed an assignment statement */
        /* e.g. x = 1 + 2; */
        /* or x = y * 3.14; */

        char* code = malloc(strlen($1) + strlen($3) + 16);
        sprintf(code, "%s = %s;\n", $1, $3);
        $$ = code;
    }
    | IDENTIFIER LPAREN expression RPAREN SEMICOLON
    {
        /* successfullly parsed a function call statement */
        /* e.g. writeStr("Hello World") */
        /* or writeStr(1 + 2) */


        char* code = malloc(strlen($1) + strlen($3) + 16);
        sprintf(code, "%s(%s);\n", $1, $3);
        $$ = code;
    }
    | KW_RETURN expression SEMICOLON
    {
        char* code = malloc(strlen($2) + 16);
        sprintf(code, "return %s;\n", $2);
        $$ = code;
    }
    | KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON
    {
        char* code = malloc(strlen($3) + strlen($6) + 64);
        sprintf(code, "if (%s) {\n%s}\n", $3, $6);
        $$ = code;
    }
    | KW_IF LPAREN expression RPAREN COLON stmt_list KW_ELSE COLON stmt_list KW_ENDIF SEMICOLON
    {
        /* successfullly parsed an if-else statement */
        /* debug print expression, stmt_list, stmt_list */

        char* code = malloc(strlen($3) + strlen($6) + strlen($9) + 128);
        sprintf(code, "if (%s) {\n%s} else {\n%s}\n", $3, $6, $9);
        $$ = code;
    }
    | KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON
    {
        /* successfullly parsed a for loop statement */
        /* e.g. for i in [1:10]: */
        
        char* code = malloc(strlen($2) + strlen($5) + strlen($7) + strlen($10) + 128);
        sprintf(code,
            "for (int %s = %s; %s <= %s; %s++) {\n%s}\n",
            $2, $5, $2, $7, $2, $10);
        $$ = code;
    }
    | SEMICOLON { $$ = strdup(""); }
    ;

expression:
    CONST_INT              { $$ = strdup($1); }
    | CONST_FLOAT          { $$ = strdup($1); }
    | CONST_STRING         { $$ = strdup($1); }
    | CONST_BOOL_TRUE      { $$ = strdup("1"); }
    | CONST_BOOL_FALSE     { $$ = strdup("0"); }
    | IDENTIFIER           { $$ = strdup($1); }
    | expression OP_PLUS expression {
        char* code = malloc(strlen($1) + strlen($3) + 4);
        sprintf(code, "%s + %s", $1, $3);
        $$ = code;
    }
    | expression OP_MULT expression {
        char* code = malloc(strlen($1) + strlen($3) + 4);
        sprintf(code, "%s * %s", $1, $3);
        $$ = code;
    }
    | LPAREN expression RPAREN {
        char* code = malloc(strlen($2) + 3);
        sprintf(code, "(%s)", $2);
        $$ = code;
    }
    ;

%%

int main() {
    return yyparse();
}
