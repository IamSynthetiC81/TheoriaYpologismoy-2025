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
		strcat(result, line);
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
%type <string> primary_expression
%type <string> component_member
%type <string> hash_ident_list
%type <string> block
%type <string> decl_list
%type <string> const_declaration
%type <string> component
%type <string> component_body
%type <string> program
%type <string> top_level_list
%type <string> top_level
%type <string> macro_def macro_def_list

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
%token LPAREN RPAREN LBRACKET RBRACKET COLON SEMICOLON COMMA DOT
%token OP_ARROW
%token HASH

%left KW_OR
%left KW_AND
%right KW_NOT
%left OP_EQ OP_NEQ OP_LT OP_LEQ OP_GT OP_GEQ
%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIV OP_MOD
%right OP_POW
%left DOT LBRACKET LPAREN
%nonassoc UMINUS

%%

program:
    macro_def_list top_level_list {
        printf("%s", $2);
    }
    ;

macro_def_list:
    /* empty */ { $$ = strdup(""); }
    | macro_def_list macro_def {
			fprintf(stderr, "Macro definition: %s\n", $1);
			$$ = $1; // or strdup($1) if you want to duplicate
		}
    ;

macro_def:
    KW_DEFMACRO IDENTIFIER CONST_FLOAT {
			fprintf(stderr, "Macro definition: %s = %s\n", $2, $3);
			char* macro = malloc(strlen($2) + strlen($3) + 16);
			sprintf(macro, "float %s = %s;\n", $2, $3);
			$$ = add_indentation(macro);
			free(macro);
			free($2);
			free($3);
		}
    ;

top_level_list:
    /* empty */ { $$ = strdup(""); }
    | top_level_list top_level{
			char* tmp = malloc(strlen($1) + strlen($2) + 2);
			sprintf(tmp, "%s%s", $1, $2);
			$$ = tmp;
			free($1);
			free($2);
		}
    ;

top_level:
	function {
		fprintf(stderr, "Function: %s\n", $1);
		$$ = $1;
	} | main_function {
		fprintf(stderr, "Main function: %s\n", $1);
		$$ = $1;
	} | component {
		fprintf(stderr, "Component: %s\n", $1);
		$$ = $1;
	} | var_declaration {
		fprintf(stderr, "Variable declaration: %s\n", $1);
		$$ = $1;
	} | const_declaration {
		fprintf(stderr, "Constant declaration: %s\n", $1);
		$$ = $1;
	} 
	;

var_declaration:
    ident_list COLON type SEMICOLON{
			fprintf(stderr, "Variable declaration: %s\n", $1);

			char* decl = malloc(strlen($1) + strlen($3) + 16);
			sprintf(decl, "%s %s;\n", $3, $1);
			$$ = add_indentation(decl);
			free(decl);
			free($1);
			free($3);
    } | ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON { 
			fprintf(stderr, "Array declaration: %s[%s]\n", $1, $3);

			char* decl = malloc(strlen($1) + strlen($3) + strlen($6) + 16);
			sprintf(decl, "%s %s[%s];\n", $6, $1, $3);
			$$ = add_indentation(decl);
			free(decl);
		}
    ;

const_declaration:
    KW_CONST IDENTIFIER OP_ASSIGN expression COLON type SEMICOLON {
				fprintf(stderr, "Constant declaration: %s = %s\n", $2, $4);

				char* decl = malloc(strlen($2) + strlen($4) + strlen($6) + 16);
				sprintf(decl, "const %s %s = %s;\n", $6, $2, $4);
				$$ = add_indentation(decl);
				free(decl);
				free($2);
				free($4);
				free($6);
		}
    ;

function:
    KW_DEF IDENTIFIER LPAREN param_list RPAREN OP_ARROW type COLON block KW_ENDDEF SEMICOLON {
        fprintf(stderr, "Function with return: %s\n", $2);

        indent_level++;
        char* body = add_indentation($9);
        indent_level--;

        char* code = malloc(strlen(body) + 64);
        sprintf(code, "%s %s(%s) {\n%s}\n", $7, $2, $4, body);
        free(body);
        $$ = code;
    }
  | KW_DEF IDENTIFIER LPAREN param_list RPAREN COLON block KW_ENDDEF SEMICOLON {
        fprintf(stderr, "Function with no return: %s\n", $2);

        indent_level++;
        char* body = add_indentation($7);
        indent_level--;

        char* code = malloc(strlen(body) + 64);
        sprintf(code, "void %s(%s) {\n%s}\n", $2, $4, body);
        free(body);
        $$ = code;
    }
    ;

param_list:
	/* empty */ { $$ = strdup(""); }
	| param_decl_list { fprintf(stderr, "Param list %s\n", $1);  $$ = $1; }
	;

param_decl_list:
    IDENTIFIER COLON type {
			fprintf(stderr, "Param: %s\n", $1);

			$$ = malloc(strlen($1) + strlen($3) + 2);
			sprintf($$, "%s %s", $3, $1);
    } | param_decl_list COMMA IDENTIFIER COLON type {
			fprintf(stderr, "Param: %s\n", $3);

			char* tmp = malloc(strlen($1) + strlen($3) + strlen($5) + 4);
			sprintf(tmp, "%s, %s %s", $1, $5, $3);
			$$ = tmp;
    }

main_function:
    KW_DEF KW_MAIN LPAREN RPAREN COLON block KW_ENDDEF SEMICOLON {
        fprintf(stderr, "Main function\n");
        indent_level++;
        char* body = add_indentation($6);
        indent_level--;
        char* code = malloc(strlen(body) + 64);
        sprintf(code, "int main() {\n%s}\n", body);
        free(body);
        $$ = code;   // <--- Return the generated code!
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
  | IDENTIFIER  { $$ = strdup($1); }
  ;

stmt:
    IDENTIFIER OP_ASSIGN expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);

        fprintf(stderr, "Assigning: %s = %s\n", $1, $3);

        sprintf(line, "%s = %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | expression OP_ASSIGN expression SEMICOLON {
        // Handles assignments like a[i] = x; or obj.field = x;
        char* line = malloc(strlen($1) + strlen($3) + 16);
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
    } | KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON {
        indent_level++;
        char* body = add_indentation($12);
        indent_level--;

				fprintf(stderr, "For loop with step: %s\n", $2);

        char* code = malloc(strlen($2) + strlen($5) + strlen($7) + strlen($9) + strlen(body) + 128);
        sprintf(code, "for (int %s = %s; %s < %s; %s += %s) {\n%s}\n", $2, $5, $2, $7, $2, $9, body);
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
        // Handles: a := [expr for i:100]:integer;

				fprintf(stderr, "Defining array: %s := [%s for %s:%s]:%s;\n", $1, $4, $6, $8, $11);

        char* code = malloc(1024);
        sprintf(code, "%s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s = 0; %s < %s; ++%s) {\n    %s[%s] = %s;\n}\n",
            $1, $11, $8, $11, $6, $6, $8, $6, $1, $6, $4);
        $$ = add_indentation(code);
        free(code);
    } | IDENTIFIER OP_DEFINE LBRACKET expression KW_FOR IDENTIFIER COLON type KW_IN IDENTIFIER KW_OF CONST_INT RBRACKET COLON type SEMICOLON {
        // Handles: half := [x/2 for x:scalar in a of 100]:scalar;
        char* code = malloc(1024);
        sprintf(code,
            "%s = (%s*)malloc(%s * sizeof(%s));\n"
            "for (int i = 0; i < %s; ++i) {\n"
            "    %s[i] = %s;\n"
            "}\n",
            $1, $15, $12, $15, $12, $1, $4
        );
        $$ = add_indentation(code);
        free(code);
    } | KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON {
        indent_level++;
        char* body = add_indentation($6);
        indent_level--;

				fprintf(stderr, "While loop: %s\n", $3);

        char* code = malloc(strlen($3) + strlen(body) + 64);
        sprintf(code, "while (%s) {\n%s}\n", $3, body);
        $$ = code;
        free(body);
    } | IDENTIFIER OP_PLUSEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        
				fprintf(stderr, "Adding: %s += %s\n", $1, $3);
				
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
        
				fprintf(stderr, "Multiplying: %s *= %s\n", $1, $3);

				sprintf(line, "%s *= %s;\n", $1, $3);
				$$ = add_indentation(line);
				free(line);
		} | IDENTIFIER OP_DIVEQ expression SEMICOLON {
				char* line = malloc(strlen($1) + strlen($3) + 16);
				
				fprintf(stderr, "Dividing: %s /= %s\n", $1, $3);

				sprintf(line, "%s *= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | IDENTIFIER OP_MODEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        
				fprintf(stderr, "Modulo: %s %%= %s\n", $1, $3);
				
				sprintf(line, "%s %%= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | HASH IDENTIFIER OP_ASSIGN expression SEMICOLON {
        char* line = malloc(strlen($2) + strlen($4) + 32);
        sprintf(line, "%s = %s;\n", $2, $4);
        $$ = add_indentation(line);
        free(line);
    } | HASH IDENTIFIER OP_PLUSEQ expression SEMICOLON {
        char* line = malloc(strlen($2) + strlen($4) + 32);
        sprintf(line, "%s += %s;\n", $2, $4);
        $$ = add_indentation(line);
        free(line);
    } | HASH IDENTIFIER OP_MINUSEQ expression SEMICOLON {
        char* line = malloc(strlen($2) + strlen($4) + 32);
        sprintf(line, "%s -= %s;\n", $2, $4);
        $$ = add_indentation(line);
        free(line);
    } | HASH IDENTIFIER DOT IDENTIFIER LPAREN RPAREN SEMICOLON {
        char* line = malloc(strlen($2) + strlen($4) + 32);
        sprintf(line, "%s.%s();\n", $2, $4);
        $$ = add_indentation(line);
        free(line);
    } | HASH IDENTIFIER DOT IDENTIFIER LPAREN arg_list RPAREN SEMICOLON {
        char* line = malloc(strlen($2) + strlen($4) + strlen($6) + 32);
        sprintf(line, "%s.%s(%s);\n", $2, $4, $6);
        $$ = add_indentation(line);
        free(line);
    } | expression OP_PLUSEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        sprintf(line, "%s += %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | expression OP_MINUSEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        sprintf(line, "%s -= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | expression OP_MULTEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        sprintf(line, "%s *= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | expression OP_DIVEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        sprintf(line, "%s /= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | expression OP_MODEQ expression SEMICOLON {
        char* line = malloc(strlen($1) + strlen($3) + 16);
        sprintf(line, "%s %%= %s;\n", $1, $3);
        $$ = add_indentation(line);
        free(line);
    } | expression SEMICOLON {
        char* line = malloc(strlen($1) + 16);
        sprintf(line, "%s;\n", $1);
        $$ = add_indentation(line);
        free(line);
    } | error SEMICOLON {
			fprintf(stderr, "Syntax error at line %d\n", line_num);
			yyerrok;
		}
		;

component:
    KW_COMP IDENTIFIER COLON component_body KW_ENDCOMP SEMICOLON {
				fprintf(stderr, "Component: %s\n", $2);

				char* code = malloc(strlen($2) + 16);
				sprintf(code, "struct %s {\n%s};\n", $2, $4);
				$$ = add_indentation(code);
				free(code);
		}
    ;

component_body:
    /* empty */ { $$ = strdup(""); }
  | component_body component_member {
			fprintf(stderr, "Component member: %s\n", $2);

			char* code = malloc(strlen($1) + strlen($2) + 16);
			sprintf(code, "%s%s", $1, $2);
			$$ = code;
			free(code);
	}
  ;

component_member:
	hash_ident_list COLON type SEMICOLON {
			char* decl = malloc(strlen($1) + strlen($3) + 16);
			sprintf(decl, "%s %s;\n", $3, $1);
			$$ = add_indentation(decl);
			free(decl);
			free($1);
			free($3);
	} | hash_ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON {
			char* decl = malloc(strlen($1) + strlen($3) + strlen($6) + 16);
			sprintf(decl, "%s %s[%s];\n", $6, $1, $3);
			$$ = add_indentation(decl);
			free(decl);
			free($1);
			free($3);
			free($6);
    } | function {
			char* decl = malloc(strlen($1) + 16);
			sprintf(decl, "%s", $1);
			$$ = add_indentation(decl);
			free(decl);
		} | SEMICOLON { $$ = strdup(""); }
  ;

hash_ident_list:
    HASH IDENTIFIER {
        $$ = malloc(strlen($2) + 2);
        sprintf($$, "#%s", $2);
    }
  | hash_ident_list COMMA HASH IDENTIFIER {
        char* tmp = malloc(strlen($1) + strlen($4) + 3);
        sprintf(tmp, "%s, #%s", $1, $4);
        free($1);
        $$ = tmp;
    }
  ;

ident_list:
	IDENTIFIER {
		$$ = strdup($1);
	} | ident_list COMMA IDENTIFIER {
		char* tmp = malloc(strlen($1) + strlen($3) + 2);
		sprintf(tmp, "%s, %s", $1, $3);
			$$ = tmp;
	}
  ;

arg_list:
    /* empty */ { $$ = strdup(""); }
  | expression { $$ = strdup($1); }
  | arg_list COMMA expression {
        char* tmp = malloc(strlen($1) + strlen($3) + 2);
        sprintf(tmp, "%s, %s", $1, $3);
        $$ = tmp;
        free($1);
        free($3);
    }
  ;

expression:
	primary_expression
	| expression OP_PLUS expression {
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
		char* code = malloc(strlen($1) + strlen($3) + 4);
		
		fprintf(stderr, "Field access: %s.%s\n", $1, $3);

		sprintf(code, "%s.%s", $1, $3);
		$$ = code;
	} | expression LBRACKET expression RBRACKET {
		char* code = malloc(strlen($1) + strlen($3) + 4);
		
		fprintf(stderr, "Array access: %s[%s]\n", $1, $3);

		sprintf(code, "%s[%s]", $1, $3);
		$$ = code;
	}
	| primary_expression DOT IDENTIFIER {
		char* code = malloc(strlen($1) + strlen($3) + 4);
		sprintf(code, "%s.%s", $1, $3);
		$$ = code;
	} | primary_expression LBRACKET expression RBRACKET {
		char* code = malloc(strlen($1) + strlen($3) + 4);
		sprintf(code, "%s[%s]", $1, $3);
		$$ = code;
	}
	| primary_expression DOT IDENTIFIER LPAREN arg_list RPAREN {
		char* code = malloc(strlen($1) + strlen($3) + strlen($5) + 8);
		sprintf(code, "%s.%s(%s)", $1, $3, $5);
		$$ = code;
		free($1); free($3); free($5);
	} | primary_expression DOT IDENTIFIER LPAREN RPAREN {
		char* code = malloc(strlen($1) + strlen($3) + 8);
		sprintf(code, "%s.%s()", $1, $3);
		$$ = code;
		free($1); free($3);
	}
	| expression LPAREN arg_list RPAREN {
		char* code = malloc(strlen($1) + strlen($3) + 4);
		sprintf(code, "%s(%s)", $1, $3);
		$$ = code;
		free($1); free($3);
	} | expression LPAREN RPAREN {
		char* code = malloc(strlen($1) + 4);
		sprintf(code, "%s()", $1);
		$$ = code;
		free($1);
	}
	;

primary_expression:
    CONST_INT {
			char* code = malloc(strlen($1) + 16);
			sprintf(code, "%s", $1);
			$$ = code;
	} | CONST_FLOAT {
			char* code = malloc(strlen($1) + 16);
			sprintf(code, "%s", $1);
	} | CONST_STRING {
			char* code = malloc(strlen($1) + 16);
			sprintf(code, "%s", $1);
			$$ = code;
	} | CONST_BOOL_TRUE {
			char* code = malloc(16);
			sprintf(code, "true");
			$$ = code;
	} | CONST_BOOL_FALSE {
			char* code = malloc(16);
			sprintf(code, "false");
			$$ = code;
	} | IDENTIFIER {
			char* code = malloc(strlen($1) + 16);
			sprintf(code, "%s", $1);
			$$ = code;
	} | HASH IDENTIFIER {
			char* code = malloc(strlen($2) + 2);
			sprintf(code, "#%s", $2);
			$$ = code;
	} | IDENTIFIER LPAREN arg_list RPAREN {
			char* code = malloc(strlen($1) + strlen($3) + 4);
			sprintf(code, "%s(%s)", $1, $3);
			$$ = code;
			free($1);
			free($3);
	} | IDENTIFIER LPAREN RPAREN {
			char* code = malloc(strlen($1) + 4);
			sprintf(code, "%s()", $1);
			$$ = code;
			free($1);
	} | primary_expression DOT IDENTIFIER LPAREN arg_list RPAREN {
			char* code = malloc(strlen($1) + strlen($3) + strlen($5) + 8);
			sprintf(code, "%s.%s(%s)", $1, $3, $5);
			$$ = code;
			free($1); free($3); free($5);
	} | primary_expression DOT IDENTIFIER LPAREN RPAREN {
			char* code = malloc(strlen($1) + strlen($3) + 8);
			sprintf(code, "%s.%s()", $1, $3);
			$$ = code;
			free($1); free($3);
	}
;

block:
    decl_list stmt_list {
        char* code = malloc(strlen($1) + strlen($2) + 2);
        sprintf(code, "%s%s", $1, $2);
        $$ = add_indentation(code);
        free(code);
    }
    ;

decl_list:
	/* empty */ { $$ = strdup(""); }
  | decl_list var_declaration {
			char* tmp = malloc(strlen($1) + strlen($2) + 2);
			sprintf(tmp, "%s%s", $1, $2);
			$$ = tmp;
			free($1);
			free($2);
	}
  ;

%%

int main() {
	return yyparse();
}