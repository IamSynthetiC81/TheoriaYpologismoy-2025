%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgen.h"
#include "lambdalib.h"

extern int yylex();
extern int yyparse();
extern int line_number;
extern FILE *yyin;

extern char* find_macro(const char*);


int indent_level = 0;
int line_num = 1;

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

%type <string> stmt stmt_list expression function main_function type
%type <string> param_list param_decl_list
%type <string> ident_list
%type <string> var_declaration
%type <string> arg_list

%token <string> IDENTIFIER CONST_INT CONST_FLOAT CONST_STRING
%token CONST_BOOL_TRUE CONST_BOOL_FALSE

%token KW_INTEGER KW_SCALAR KW_STR KW_BOOL KW_CONST
%token KW_IF KW_ELSE KW_ENDIF
%token KW_FOR KW_IN KW_ENDFOR
%token KW_WHILE KW_ENDWHILE
%token KW_BREAK KW_CONTINUE KW_NOT KW_AND KW_OR
%token KW_DEF KW_ENDDEF KW_MAIN KW_RETURN
%token KW_COMP KW_ENDCOMP KW_OF

%token KW_DEFMACRO

%token OP_ASSIGN OP_PLUSEQ OP_MINUSEQ OP_MULTEQ OP_DIVEQ OP_MODEQ OP_DEFINE OP_POW
%token OP_EQ OP_NEQ OP_LT OP_LEQ OP_GT OP_GEQ
%token OP_PLUS OP_MINUS OP_MULT OP_DIV OP_MOD
%token LPAREN RPAREN LBRACKET RBRACKET COLON SEMICOLON KW_COMMA DOT
%token OP_ARROW
%token HASH

%left KW_OR
%left KW_AND
%right KW_NOT
%left OP_EQ OP_NEQ OP_LT OP_LEQ OP_GT OP_GEQ
%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIV OP_MOD
%right OP_POW
%nonassoc UMINUS

%%

program:
    macro_def_list top_level_list main_function
    ;

macro_def_list:
    /* empty */
    | macro_def_list macro_def
    ;

macro_def:
    KW_DEFMACRO IDENTIFIER CONST_FLOAT
    ;

top_level_list:
    /* empty */
    | top_level_list top_level
    ;

top_level:
      function
    | component
    | var_declaration
    | const_declaration
    ;

var_declaration:
    ident_list COLON type SEMICOLON{
        char* decl = malloc(strlen($1) + strlen($3) + 16);
        sprintf(decl, "%s %s;\n", $3, $1);
        $$ = add_indentation(decl);
        free(decl);
    }
    ;

const_declaration:
    KW_CONST IDENTIFIER OP_ASSIGN expression COLON type SEMICOLON
    ;

function:
	KW_DEF IDENTIFIER LPAREN param_list RPAREN OP_ARROW type COLON stmt_list KW_ENDDEF SEMICOLON {
			indent_level++;

			// char* body = add_indentation($8);
			indent_level--;
			// char* code = malloc(1024);
			// sprintf(code, "%s %s(%s) {\n%s}\n\n", $7, $2, $4, body);
			// free(body);
			// $$ = code;
	}
	;
param_list:
	/* empty */ { $$ = strdup(""); }
	| param_decl_list { $$ = $1; }
	;

param_decl_list:
    IDENTIFIER COLON type {

			fprintf(stderr, "Param: %s\n", $1);

			$$ = malloc(strlen($1) + strlen($3) + 2);
			sprintf($$, "%s %s", $3, $1);
    } | param_decl_list KW_COMMA IDENTIFIER COLON type {

			fprintf(stderr, "Param: %s\n", $3);

			char* tmp = malloc(strlen($1) + strlen($3) + strlen($5) + 4);
			sprintf(tmp, "%s, %s %s", $1, $5, $3);
			$$ = tmp;
    }

main_function:
	KW_DEF KW_MAIN LPAREN RPAREN COLON stmt_list KW_ENDDEF SEMICOLON {
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
    } | IDENTIFIER LPAREN RPAREN SEMICOLON {
        char* line = malloc(strlen($1) + 16);

				fprintf(stderr, "Calling: %s()\n", $1);

				sprintf(line, "%s();\n", $1);
				$$ = add_indentation(line);
				free(line);
    } | IDENTIFIER LPAREN arg_list RPAREN SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);

				fprintf(stderr, "Calling: %s(%s)\n", $1, $3);

				sprintf(line, "%s(%s);\n", $1, $3);
				$$ = add_indentation(line);
				free(line);
    } | KW_RETURN expression SEMICOLON {
        char* line = malloc(strlen($2) + 16);

        fprintf(stderr, "Returning: %s\n", $2);

        sprintf(line, "return %s;\n", $2);
        $$ = add_indentation(line);
        free(line);
    } | KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON {
        indent_level++;
        char* body = add_indentation($6);
        indent_level--;
        char* code = malloc(strlen($3) + strlen(body) + 64);

        fprintf(stderr, "If statement: %s\n", $3);

        sprintf(code, "if (%s) {\n%s}\n", $3, body);
        $$ = code;
        free(body);
    } | KW_IF LPAREN expression RPAREN COLON stmt_list KW_ELSE COLON stmt_list KW_ENDIF SEMICOLON {
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
    } | KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON {
        indent_level++;
        char* body = add_indentation($10);
        indent_level--;
        char* code = malloc(strlen($2) + strlen($5) + strlen($7) + strlen(body) + 128);

        fprintf(stderr, "For loop: %s\n", $2);

        sprintf(code, "for (int %s = %s; %s < %s; ++%s) {\n%s}\n", $2, $5, $2, $7, $2, body);
        $$ = code;
        free(body);
    } | KW_BREAK SEMICOLON {
        $$ = add_indentation("break;\n");
    } | KW_CONTINUE SEMICOLON {
        $$ = add_indentation("continue;\n");
    } | SEMICOLON {
        fprintf(stderr, "STMT SEMICOLON\n");
        $$ = strdup(";");
    } | KW_RETURN SEMICOLON {   
        fprintf(stderr, "STMT RET SEMICOLON\n");
        $$ = strdup("return;\n");
    } | IDENTIFIER OP_DEFINE LBRACKET expression KW_FOR IDENTIFIER COLON expression RBRACKET COLON type SEMICOLON {
        char* code = malloc(1024);
        sprintf(code, "%s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s = 0; %s < %s; ++%s) {\n    %s[%s] = %s;\n}\n",
            $1, $11, $8, $11, $6, $6, $8, $6, $1, $6, $4);
        $$ = add_indentation(code);
        free(code);
    } | KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON {
        indent_level++;
        char* body = add_indentation($6);
        indent_level--;
        char* code = malloc(strlen($3) + strlen(body) + 64);
        sprintf(code, "while (%s) {\n%s}\n", $3, body);
        $$ = code;
        free(body);
    } | IDENTIFIER OP_PLUSEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        
				sprintf(stderr, "Adding: %s += %s\n", $1, $3);
				
				sprintf(line, "%s += %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | IDENTIFIER OP_MINUSEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);

				fprintf(stderr, "Subtracting: %s -= %s\n", $1, $3);

        sprintf(line, "%s -= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | IDENTIFIER OP_MULTEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        
				sprintf(stderr, "Multiplying: %s *= %s\n", $1, $3);

				sprintf(line, "%s *= %s;\n", $1, $3);
				$$ = add_indentation(line);
				free(line);
		} | IDENTIFIER OP_DIVEQ expression SEMICOLON {
				char* line = malloc(strlen($1) + strlen($3) + 16);
				
				sprintf(stderr, "Dividing: %s /= %s\n", $1, $3);

				sprintf(line, "%s *= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | IDENTIFIER OP_MODEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        
				sprintf(stderr, "Modulo: %s %%= %s\n", $1, $3);
				
				sprintf(line, "%s %%= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | error SEMICOLON { yyerror("Error in statement"); 
		} | var_declaration
    ;

component:
    KW_COMP IDENTIFIER COLON component_body KW_ENDCOMP SEMICOLON
    ;

component_body:
    /* empty */
    | component_body component_member
    ;

component_member:
      hash_ident_list COLON type SEMICOLON
    | function
    ;

field_decl:
    hash_ident_list COLON type SEMICOLON
  | hash_ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON
  ;

hash_ident_list:
	HASH IDENTIFIER { 
		char* name = strdup($2);
		fprintf(stderr, "Hash identifier: %s\n", name);
		free(name);
	} | hash_ident_list KW_COMMA HASH IDENTIFIER {
		char* name = strdup($4);
		fprintf(stderr, "Hash identifier: %s\n", name);
		free(name);
	}
	;

ident_list:
    IDENTIFIER { $$ = strdup($1); }
    | ident_list KW_COMMA IDENTIFIER {
        char* tmp = malloc(strlen($1) + strlen($3) + 2);
        sprintf(tmp, "%s, %s", $1, $3);
        $$ = tmp;
    }
    ;

arg_list:
    expression
  | arg_list KW_COMMA expression
  ;

expression:
    CONST_INT              { fprintf(stderr, "CONST_INT = %s\n", $1); $$ = strdup($1);}
    | CONST_FLOAT          { fprintf(stderr, "CONST_FLOAT = %s\n", $1); $$ = strdup($1);}
    | CONST_STRING         { fprintf(stderr, "CONST_STRING = %s\n", $1);$$ = strdup($1);}
    | CONST_BOOL_TRUE      { fprintf(stderr, "CONST_BOOL_TRUE\n");$$ = strdup("1");}
    | CONST_BOOL_FALSE     { fprintf(stderr, "CONST_BOOL_FALSE\n");$$ = strdup("0");}
    | IDENTIFIER {
			char* val = find_macro($1);
			if (val) {
				$$ = strdup(val);
			} else {
				$$ = strdup($1);
			}

			fprintf(stderr, "Identifier: %s\n", $1);
		} | expression OP_PLUS expression {
			char* code = malloc(strlen($1) + strlen($3) + 4);

			fprintf(stderr, "Adding: %s + %s\n", $1, $3);

			sprintf(code, "%s + %s", $1, $3);
			$$ = code;
    } | expression OP_MINUS expression{
			char* code = malloc(strlen($1) + strlen($3) + 4);
			fprintf(stderr, "Subtracting: %s - %s\n", $1, $3);
			sprintf(code, "%s - %s", $1, $3);
		} | expression OP_MULT expression {
			char* code = malloc(strlen($1) + strlen($3) + 4);
			fprintf(stderr, "Multiplying: %s * %s\n", $1, $3);
			sprintf(code, "%s * %s", $1, $3);
			$$ = code;
    } | expression OP_DIV expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        sprintf(code, "%s / %s", $1, $3);
        $$ = code;
    } | expression OP_MOD expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        sprintf(code, "%s %% %s", $1, $3);
        $$ = code;
    } | expression OP_POW expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        sprintf(code, "%s ** %s", $1, $3);
        $$ = code;
    } | expression OP_EQ expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        
        fprintf(stderr, "Equal: %s == %s\n", $1, $3);

        sprintf(code, "%s == %s", $1, $3);
        $$ = code;
    } | expression OP_NEQ expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        
        fprintf(stderr, "Not equal: %s != %s\n", $1, $3);        

        sprintf(code, "%s != %s", $1, $3);
        $$ = code;
    } | expression OP_LT expression {
        char* code = malloc(strlen($1) + strlen($3) + 4);
        
        fprintf(stderr, "Less than: %s < %s\n", $1, $3);
        
        sprintf(code, "%s < %s", $1, $3);
        $$ = code;
    } | expression OP_LEQ expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        
        fprintf(stderr, "Less than or equal: %s <= %s\n", $1, $3);
        
        sprintf(code, "%s <= %s", $1, $3);
        $$ = code;
    } | expression OP_GT expression {
        char* code = malloc(strlen($1) + strlen($3) + 4);

        fprintf(stderr, "Greater than: %s > %s\n", $1, $3);

        sprintf(code, "%s > %s", $1, $3);
        $$ = code;
    } | expression OP_GEQ expression {
        char* code = malloc(strlen($1) + strlen($3) + 5);
        
        fprintf(stderr, "Greater than or equal: %s >= %s\n", $1, $3);

        sprintf(code, "%s >= %s", $1, $3);
        $$ = code;
    } | expression KW_AND expression {
				char* code = malloc(strlen($1) + strlen($3) + 5);
				sprintf(code, "%s && %s", $1, $3);
				$$ = code;
		} | expression KW_OR expression {
				char* code = malloc(strlen($1) + strlen($3) + 5);
				sprintf(code, "%s || %s", $1, $3);
				$$ = code;
		} | KW_NOT expression %prec KW_NOT {
        char* code = malloc(strlen($2) + 5);
        sprintf(code, "!%s", $2);
        $$ = code;
    } | OP_MINUS expression %prec UMINUS {
        char* code = malloc(strlen($2) + 2);
        sprintf(code, "-%s", $2);
        $$ = code;
    } | LPAREN expression RPAREN {
        char* code = malloc(strlen($2) + 3);

        fprintf(stderr, "Parentheses: (%s)\n", $2);

        sprintf(code, "(%s)", $2);
        $$ = code;
    } | expression DOT IDENTIFIER {
        char* code = malloc(strlen($1) + strlen($3) + 2);
        sprintf(code, "%s.%s", $1, $3);
        $$ = code;
    } | expression LBRACKET expression RBRACKET {
        char* code = malloc(strlen($1) + strlen($3) + 3);
        sprintf(code, "%s[%s]", $1, $3);
        $$ = code;
    } | expression LPAREN arg_list RPAREN {
        char* code = malloc(strlen($1) + strlen($3) + 3);
        sprintf(code, "%s(%s)", $1, $3);
        $$ = code;
    } | expression LPAREN RPAREN {
        char* code = malloc(strlen($1) + 3);
        sprintf(code, "%s()", $1);
        $$ = code;
    }
		;

%%

int main() {
    return yyparse();
}