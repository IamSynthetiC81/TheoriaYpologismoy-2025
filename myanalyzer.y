%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int line_number;
extern FILE *yyin;

extern char* find_macro(const char*);


int indent_level = 0;

void yyerror(const char *msg) {
    fprintf(stderr, "Syntax error in line %d: %s\n", line_number, msg);
    exit(1);
}

void debug_print(const char* str) {
    fprintf(stderr, "debug: %s\n", str);
}

char* add_indentation(const char* code) {
    char* result = malloc(strlen(code) + 1024);
    result[0] = '\0';
    const char* line = code;
    while (*line) {
        for (int i = 0; i < indent_level; ++i) strcat(result, "    ");
        const char* newline = strchr(line, '\n');
        if (newline) {
            strncat(result, line, newline - line + 1);
            line = newline + 1;
        } else {
            strcat(result, line);
            break;
        }
    }
    return result;
}
%}

%union {
    char* string;
}

%type <string> stmt stmt_list expression function function_list main_function type

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

%left OP_EQ OP_NEQ OP_LT OP_LEQ OP_GT OP_GEQ
%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIV
%left OP_MOD

%%

program:
    function_list main_function
    ;

function_list:
    /* empty */ { $$ = strdup(""); }
    | function_list function { $$ = strdup(""); }
    ;

function:
    KW_DEF IDENTIFIER LPAREN RPAREN COLON stmt_list KW_ENDDEF SEMICOLON
    {
        indent_level++;
        char* body = add_indentation($6);
        indent_level--;
        char* code = malloc(strlen($2) + strlen(body) + 64);
        sprintf(code, "void %s() {\n%s}\n\n", $2, body);
        free(body);
        printf("%s", code);
        $$ = strdup("");
    }
    ;

main_function:
    KW_DEF KW_MAIN LPAREN RPAREN COLON stmt_list KW_ENDDEF SEMICOLON
    {
        indent_level++;
        char* body = add_indentation($6);
        indent_level--;
        char* code = malloc(strlen(body) + 64);
        sprintf(code, "int main() {\n%s}\n", body);
        free(body);
        printf("%s", code);
        free(code);
        $$ = strdup("");    
    }
    ;

stmt_list:
    /* empty */ { $$ = strdup(""); }
    | stmt_list stmt {
        char* tmp = malloc(strlen($1) + strlen($2) + 2);
        sprintf(tmp, "%s%s", $1, $2);
        $$ = tmp;
    }
    ;

type:
    KW_INTEGER  { $$ = strdup("int"); }
  | KW_SCALAR   { $$ = strdup("float"); }
  | KW_STR      { $$ = strdup("char*"); }
  | KW_BOOL     { $$ = strdup("bool"); }
  ;

stmt:
    IDENTIFIER OP_ASSIGN expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);

        fprintf(stderr, "Assigning: %s = %s\n", $1, $3);

        sprintf(line, "%s = %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    }
    | IDENTIFIER LPAREN expression RPAREN SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);

        fprintf(stderr, "Calling: %s(%s)\n", $1, $3);

        sprintf(line, "%s(%s);\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    }
    | KW_RETURN expression SEMICOLON {
        char* line = malloc(strlen($2) + 16);

        fprintf(stderr, "Returning: %s\n", $2);

        sprintf(line, "return %s;\n", $2);
        $$ = add_indentation(line);
        free(line);
    }
    | KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON {
        indent_level++;
        char* body = add_indentation($6);
        indent_level--;
        char* code = malloc(strlen($3) + strlen(body) + 64);

        fprintf(stderr, "If statement: %s\n", $3);

        sprintf(code, "if (%s) {\n%s}\n", $3, body);
        $$ = code;
        free(body);
    }
    | KW_IF LPAREN expression RPAREN COLON stmt_list KW_ELSE COLON stmt_list KW_ENDIF SEMICOLON {
        indent_level++;
        char* then_part = add_indentation($6);
        char* else_part = add_indentation($9);
        indent_level--;
        char* code = malloc(strlen($3) + strlen(then_part) + strlen(else_part) + 128);

        fprintf(stderr, "If-else statement: %s\n", $3);

        sprintf(code, "if (%s) {\n%s} else {\n%s}\n", $3, then_part, else_part);
        $$ = code;
        free(then_part);
        free(else_part);
    }
    | KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON {
        indent_level++;
        char* body = add_indentation($10);
        indent_level--;
        char* code = malloc(strlen($2) + strlen($5) + strlen($7) + strlen(body) + 128);

        fprintf(stderr, "For loop: %s in [%s:%s]\n", $2, $5, $7);

        sprintf(code, "for (int %s = %s; %s <= %s; %s++) {\n%s}\n", $2, $5, $2, $7, $2, body);
        $$ = code;
        free(body);
    }
    | KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON {
        indent_level++;
        char* body = add_indentation($6);
        indent_level--;
        char* code = malloc(strlen($3) + strlen(body) + 64);

        fprintf(stderr, "While loop: %s\n", $3);

        sprintf(code, "while (%s) {\n%s}\n", $3, body);
        $$ = code;
        free(body);
    }
    | KW_BREAK SEMICOLON {
        $$ = add_indentation("break;\n");
    }
    | KW_CONTINUE SEMICOLON {
        $$ = add_indentation("continue;\n");
    }
    | IDENTIFIER COLON type SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        sprintf(line, "%s %s;\n", $3, $1);
        $$ = add_indentation(line);
        free(line);
    }
    | SEMICOLON {
        fprintf(stderr, "STMT SEMICOLON\n");
        $$ = strdup(";");
    }
    | KW_RETURN SEMICOLON
    {   
        fprintf(stderr, "STMT RET SEMICOLON\n");
        $$ = strdup("return;\n");
    }
    ;

expression:
    CONST_INT              { fprintf(stderr, "CONST_INT = %s\n", $1); $$ = strdup($1); }
    | CONST_FLOAT          { fprintf(stderr, "CONST_FLOAT = %s\n", $1); $$ = strdup($1);}
    | CONST_STRING         { fprintf(stderr, "CONST_STRING = %s\n", $1);$$ = strdup($1); }
    | CONST_BOOL_TRUE      { fprintf(stderr, "CONST_BOOL_TRUE\n");$$ = strdup("1"); }
    | CONST_BOOL_FALSE     { fprintf(stderr, "CONST_BOOL_FALSE\n");$$ = strdup("0"); }
    | IDENTIFIER {
        char* val = find_macro($1);
        if (val) {
            $$ = strdup(val);
        } else {
            $$ = strdup($1);
        }

        fprintf(stderr, "Identifier: %s\n", $1);
    }
    | expression OP_PLUS expression {
        char* code = malloc(strlen($1) + strlen($3) + 4);

        fprintf(stderr, "Adding: %s + %s\n", $1, $3);

        sprintf(code, "%s + %s", $1, $3);
        $$ = code;
    }
    | expression OP_MULT expression {
        char* code = malloc(strlen($1) + strlen($3) + 4);
        fprintf(stderr, "Multiplying: %s * %s\n", $1, $3);
        sprintf(code, "%s * %s", $1, $3);

        $$ = code;
    }
    | expression OP_GT expression {
        char* code = malloc(strlen($1) + strlen($3) + 4);

        fprintf(stderr, "Greater than: %s > %s\n", $1, $3);

        sprintf(code, "%s > %s", $1, $3);
        $$ = code;
    }
    | expression OP_LT expression {
        char* code = malloc(strlen($1) + strlen($3) + 4);
        
        fprintf(stderr, "Less than: %s < %s\n", $1, $3);
        
        sprintf(code, "%s < %s", $1, $3);
        $$ = code;
    }
    | expression OP_EQ expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        
        fprintf(stderr, "Equal: %s == %s\n", $1, $3);

        sprintf(code, "%s == %s", $1, $3);
        $$ = code;
    }
    | expression OP_NEQ expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        
        fprintf(stderr, "Not equal: %s != %s\n", $1, $3);        

        sprintf(code, "%s != %s", $1, $3);
        $$ = code;
    }
    | expression OP_GEQ expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        
        fprintf(stderr, "Greater than or equal: %s >= %s\n", $1, $3);

        sprintf(code, "%s >= %s", $1, $3);
        $$ = code;
    }
    | expression OP_LEQ expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        
        fprintf(stderr, "Less than or equal: %s <= %s\n", $1, $3);
        
        sprintf(code, "%s <= %s", $1, $3);
        $$ = code;
    }
    | LPAREN expression RPAREN {
        char* code = malloc(strlen($2) + 3);

        fprintf(stderr, "Parentheses: (%s)\n", $2);

        sprintf(code, "(%s)", $2);
        $$ = code;
    }
    ;

%%

int main() {
    return yyparse();
}
