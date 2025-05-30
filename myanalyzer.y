%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "cgen.h"
	#include "lambdalib.h"
	#include "myanalyzer.tab.h"
	#include <setjmp.h>

	extern int yylex(void);
	extern int yyparse();
	extern int line_number;
	extern FILE *yyin;

	extern char* find_macro(const char*);
	extern char *yytext;

	int indent_level = 0;
	int line_num = 1;

	int yydebug = 1;

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

char *safe_strdup(const char *str) {
	if (!str) return NULL;
	char *new = strdup(str);
	if (!new) {
			yyerror("Memory allocation failed");
			exit(1);
	}
	return new;
}

void safe_free(void* ptr) {
	if (ptr) free(ptr);
}

char * includes = "#include \"lambdalib.h\"\n#include <stdbool.h>";

// Για την αποθήκευση defmacro αντικαταστάσεων
typedef struct {
	char* name;
	char* replacement;
} Macro;

#define MAX_MACROS 100
Macro macros[MAX_MACROS];
int macro_count = 0;

void add_macro(const char* name, const char* replacement) {

	fprintf(stderr, "Adding macro: %s -> %s\n", name, replacement);

	for (int i = 0; i < macro_count; ++i) {
		if (strcmp(macros[i].name, name) == 0) {
			safe_free(macros[i].replacement);
			macros[i].replacement = strdup(replacement);
			return;
		}
	}
	macros[macro_count].name = strdup(name);
	macros[macro_count].replacement = strdup(replacement);
	macro_count++;

	fprintf(stderr, "Added macro: %s -> %s\n", name, replacement);
	fprintf(stderr, "Total macros: %d\n", macro_count);
	if (macro_count >= MAX_MACROS) {
			fprintf(stderr, "Error: Too many macros defined\n");
			exit(1);
		}
}

char* find_macro(const char* name) {
	for (int i = macro_count - 1; i >= 0; --i) {
		if (strcmp(macros[i].name, name) == 0)
			return macros[i].replacement;
	}
	return NULL;
}

// void yyerror(const char *fmt, ...) {
// 	va_list args;
// 	va_start(args, fmt);
// 	fprintf(stderr, "Parse error: ");
// 	vfprintf(stderr, fmt, args);
// 	fprintf(stderr, "\n");
// 	va_end(args);
// }

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
%type <string> function_call
%type <string> assignment_stmt return_stmt if_stmt for_stmt while_stmt break_stmt continue_stmt empty_stmt

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

%token <string> DECL_IDENT

%left KW_OR
%left KW_AND
%right KW_NOT
%left OP_EQ OP_NEQ OP_LT OP_LEQ OP_GT OP_GEQ
%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIV OP_MOD
%right OP_POW
%nonassoc LBRACKET											// Array access operator
%left DOT													// Member access operator
%nonassoc UMINUS

%nonassoc DECLARATION
%nonassoc STMT
%nonassoc NO_COMPARE


	// %precedence LPAREN RPAREN/
%right OP_ASSIGN

%%

program:
	macro_def_list top_level_list {
		printf("%s\n%s%s",includes, $1, $2);
	}
	;

macro_def_list:
		/* empty */ { $$ = safe_strdup("");}
		| macro_def_list macro_def {
			fprintf(stderr, "Macro definition: %s\n", $1);
			$$ = $1;
			char* tmp = malloc(strlen($1) + strlen($2) + 2);
			sprintf(tmp, "%s%s", $1, $2);
			$$ = tmp;
			safe_free($1);
			safe_free($2);

		}
		;

macro_def:
		KW_DEFMACRO IDENTIFIER expression {
		fprintf(stderr, "Macro defined: %s\n", $2);
		add_macro($2, $3);
		char* macro_code = malloc(strlen($2) + strlen($3) + 16);
		sprintf(macro_code, "#define %s %s\n", $2, $3);
		$$ = add_indentation(macro_code);
		safe_free(macro_code);
		safe_free($2);
		safe_free($3);
	}
	;

top_level_list:
		/* empty */ { $$ = safe_strdup(""); }
		| top_level_list top_level{
			fprintf(stderr, "Top level: %s\n", $1);
			char* tmp = malloc(strlen($1) + strlen($2) + 2);
			sprintf(tmp, "%s%s", $1, $2);
			$$ = tmp;
			safe_free($1); safe_free($2);
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
	}
	| var_declaration {
		fprintf(stderr, "Variable declaration: %s\n", $1);
		$$ = $1;
	}
	| const_declaration {
		fprintf(stderr, "Constant declaration: %s\n", $1);
		$$ = $1;
	}
	;

var_declaration:
	ident_list COLON type SEMICOLON {
	// $1 is the variable name, $3 is the type
	fprintf(stderr, "Processing declaration: %s of type %s\n", $1, $3);
	char* decl = malloc(strlen($1) + strlen($3) + 16);
	sprintf(decl, "%s %s;\n", $3, $1);
	$$ = add_indentation(decl);
	safe_free(decl);
	safe_free($1);
	safe_free($3);
} | IDENTIFIER LBRACKET CONST_INT RBRACKET COLON type SEMICOLON {
	// $1 = variable name, $3 = array size, $6 = type
	char* decl = malloc(strlen($1) + strlen($3) + strlen($6) + 16);
	sprintf(decl, "%s %s[%s];\n", $6, $1, $3);
	$$ = add_indentation(decl);
	safe_free(decl);
	safe_free($1);
	safe_free($3);
	safe_free($6);
}
;

const_declaration:
		KW_CONST IDENTIFIER OP_ASSIGN expression COLON type SEMICOLON {
				fprintf(stderr, "Constant declaration: %s = %s\n", $2, $4);

				char* decl = malloc(strlen($2) + strlen($4) + strlen($6) + 16);
				sprintf(decl, "const %s %s = %s;\n", $6, $2, $4);
				$$ = add_indentation(decl);
				safe_free(decl);
				safe_free($2);
				safe_free($4);
				safe_free($6);
		}
		;

function:
	KW_DEF IDENTIFIER LPAREN param_list RPAREN OP_ARROW type COLON block KW_ENDDEF SEMICOLON {
		fprintf(stderr, "Function with return: %s\n", $2);

		indent_level++;
		char* body = add_indentation($9);
		indent_level--;

		char* code = malloc(strlen(body) + strlen($7) + strlen($2) + strlen($4) +  64);
		sprintf(code, "%s %s(%s) {\n%s}\n", $7, $2, $4, body);
		safe_free(body);
		$$ = code;
	} | KW_DEF IDENTIFIER LPAREN param_list RPAREN COLON block KW_ENDDEF SEMICOLON {
		fprintf(stderr, "Function with no return: %s\n", $2);

		indent_level++;
		char* body = add_indentation($7);
		indent_level--;

		char* code = malloc(strlen(body) +strlen($2)+strlen($4) + 64);
		sprintf(code, "void %s(%s) {\n%s}\n", $2, $4, body);
		safe_free(body);
		$$ = code;
	}
	;

param_list:
	/* empty */ { $$ = safe_strdup(""); }
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
			safe_free($1); safe_free($3); safe_free($5);
		}

main_function:
	KW_DEF KW_MAIN LPAREN RPAREN COLON block KW_ENDDEF SEMICOLON {
		fprintf(stderr, "Main function\n");
		indent_level++;
		char* body = add_indentation($6);
		indent_level--;
		char* code = malloc(strlen(body) + 64);
		sprintf(code, "int main() {\n%s};\n", body);
		safe_free(body);
		$$ = code;
	}
	;

stmt_list:
	/* empty */ { $$ = safe_strdup(""); }
	| stmt_list stmt {
		char* tmp = malloc(strlen($1) + strlen($2) + 2);
		sprintf(tmp, "%s%s", $1, $2);
		$$ = tmp;
		safe_free($1); safe_free($2);
	}
	;

type:
		KW_INTEGER  { $$ = safe_strdup("int"); }
	| KW_SCALAR   { $$ = safe_strdup("float"); }
	| KW_STR      { $$ = safe_strdup("char*"); }
	| KW_BOOL     { $$ = safe_strdup("bool"); }
	| IDENTIFIER  { $$ = safe_strdup($1); safe_free($1);}
	;

stmt:
	assignment_stmt
	| return_stmt
	| if_stmt
	| for_stmt
	| while_stmt
	| break_stmt
	| continue_stmt
	| empty_stmt
	| function_call SEMICOLON {
		char* tmp = malloc(strlen($1) + 3);
		sprintf(tmp, "%s;\n", $1);
		$$ = add_indentation(tmp);
		// free(tmp);
		safe_free($1);
	} | HASH IDENTIFIER OP_ASSIGN expression SEMICOLON {
    // Assignment to a struct field
    char* line = malloc(strlen($2) + strlen($4) + 16);
    sprintf(line, "%s = %s;\n", $2, $4);
    $$ = add_indentation(line);
    safe_free(line);
    safe_free($2);
    safe_free($4);
	} | error SEMICOLON {
		yyerror("Invalid statement");
		yyerrok;
		$$ = safe_strdup("/* ERROR */\n");
	}
	;

assignment_stmt:
	IDENTIFIER OP_ASSIGN expression SEMICOLON {
		fprintf(stderr, "Matched assignment: %s = %s;\n", $1, $3);
		char* line = malloc(strlen($1) + strlen($3) + 16);
		sprintf(line, "%s = %s;\n", $1, $3);
		$$ = safe_strdup(line);
		safe_free(line);
		safe_free($1);
		safe_free($3);
	} | IDENTIFIER LBRACKET expression RBRACKET OP_ASSIGN expression SEMICOLON {
			// $1 = array name, $3 = index, $6 = value
			char* line = malloc(strlen($1) + strlen($3) + strlen($6) + 16);
			sprintf(line, "%s[%s] = %s;\n", $1, $3, $6);
			$$ = add_indentation(line);
			safe_free(line); safe_free($1); safe_free($3); safe_free($6);
	} | primary_expression LBRACKET expression RBRACKET OP_ASSIGN expression SEMICOLON{
	} | IDENTIFIER OP_DEFINE expression SEMICOLON {
		char* line = malloc(strlen($1) + strlen($3) + 16);
		sprintf(line, "%s = %s;\n", $1, $3);
		$$ = safe_strdup(line);
		safe_free(line);
		safe_free($1);
		safe_free($3);
	} | IDENTIFIER OP_DEFINE expression COLON type SEMICOLON {
		char* line = malloc(strlen($1) + strlen($3) + strlen($5) + 32);
		sprintf(line, "%s = %s; // type: %s\n", $1, $3, $5);
		$$ = safe_strdup(line);
		safe_free(line);
		safe_free($1);
		safe_free($3);
		safe_free($5);
	} | IDENTIFIER OP_DEFINE LBRACKET expression KW_FOR IDENTIFIER COLON CONST_INT RBRACKET COLON type SEMICOLON {
		// new_array := [expr for elm:size] : new_type;
		char* code = malloc(strlen($1) + strlen($4) + strlen($6) + strlen($8) + strlen($11) + 256);
		// $1 is the variable name, $4 is the expression, $6 is the loop variable, $8 is the size, $11 is the type

		fprintf(stderr, "New array: %s of size %s with type %s\n", $1, $8, $11);
		
		sprintf(code,
				"%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s = 0; %s < %s; ++%s) {\n    %s[%s] = %s;\n}\n",
				$11, $1, $11, $8, $11, $6, $6, $8, $6, $1, $6, $4
		);
		$$ = add_indentation(code);
		safe_free($1); safe_free($4); safe_free($6); safe_free($8); safe_free($11); 

	} | IDENTIFIER OP_DEFINE LBRACKET expression KW_FOR IDENTIFIER COLON type KW_IN IDENTIFIER KW_OF CONST_INT RBRACKET COLON type SEMICOLON {
		// new_array := [expr for elm:type in array of size] : new_type;
		char* code = malloc(strlen($1)*2 + strlen($6)*2 + strlen($12)*2 + strlen($15)*3 + 256);
		// $1 is the variable name, $12 is the size, $15 is the type

		sprintf(code,
			"%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s = 0; %s < %s; ++%s) {\n    %s[%s] = %s;\n}\n",
			$15, $1, $15, $12, $15, $6, $6, $12, $6, $1, $6, $4
		);
		$$ = add_indentation(code);
		safe_free($1); safe_free($4); safe_free($6); safe_free($12); safe_free($15);
	}
	;

return_stmt:
		KW_RETURN expression SEMICOLON {
				fprintf(stderr, "Returning: %s\n", $2);
				char* line = malloc(strlen($2) + 16);
				sprintf(line, "return %s;\n", $2);
				$$ = add_indentation(line);
				safe_free(line);
		} | KW_RETURN SEMICOLON {
			fprintf(stderr, "Returning void\n");
			$$ = add_indentation("return;\n");
    }
		;

if_stmt:
		KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON {
				fprintf(stderr, "If statement: %s\n", $3);
				indent_level++;
				char* body = add_indentation($6);
				indent_level--;
				char* code = malloc(strlen($3) + strlen(body) + 64);
				sprintf(code, "if (%s) {\n%s}\n", $3, body);
				$$ = code;
				safe_free(body);
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
				safe_free(then_part);
				safe_free(else_part);
		}
		;

for_stmt:
	KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON {
			indent_level++;
			// char* body = add_indentation($10);
			indent_level--;
			char* code = malloc(strlen($2)*3 + strlen($5) + strlen($7) + strlen($10) + 128);
			fprintf(stderr, "For loop: %s\n", $2);
			sprintf(code, "for (int %s = %s; %s < %s; %s++) {\n\t%s\n}\n",
				$2, $5, $2, $7, $2,$10 );
			$$ = code;
			safe_free($2); safe_free($5); safe_free($7); safe_free($10);
	}
	;

while_stmt:
		KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON {
				indent_level++;
				char* body = add_indentation($6);
				indent_level--;
				fprintf(stderr, "While loop: %s\n", $3);
				char* code = malloc(strlen($3) + strlen(body) + 64);
				sprintf(code, "while (%s) {\n%s}\n", $3, body);
				$$ = code;
				safe_free(body);
		}
		;

break_stmt:
		KW_BREAK SEMICOLON {
				$$ = add_indentation("break;\n");
		}
		;

continue_stmt:
		KW_CONTINUE SEMICOLON {
				$$ = add_indentation("continue;\n");
		}
		;

empty_stmt:
		SEMICOLON {
				$$ = safe_strdup(";");
		}
		;


component:
		KW_COMP IDENTIFIER COLON component_body KW_ENDCOMP SEMICOLON {
				fprintf(stderr, "Component: %s\n", $2);

				char* code = malloc(strlen($2) + strlen($4) + 16);
				sprintf(code, "struct %s {\n%s};\n", $2, $4);
				$$ = add_indentation(code);
				// free(code);
		}
		;

component_body:
	/* empty */ { $$ = safe_strdup(""); }
	| component_body component_member {
		fprintf(stderr, "Component member: %s\n", $2);
		char* code = malloc(strlen($1) + strlen($2) + 2);
		sprintf(code, "%s%s", $1, $2);
		$$ = code;
		safe_free($1);
		safe_free($2);
	}
	;

component_member:
	hash_ident_list COLON type SEMICOLON {
		char* decl = malloc(strlen($1) + strlen($3) + 16);
		sprintf(decl, "%s %s;\n", $3, $1);
		$$ = add_indentation(decl);
		// safe_free(decl);
		safe_free($1);
		safe_free($3);
	} | hash_ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON {
		char* decl = malloc(strlen($1) + strlen($3) + strlen($6) + 16);
		sprintf(decl, "%s %s[%s];\n", $6, $1, $3);
		$$ = add_indentation(decl);
		// safe_free(decl);
		safe_free($1);
		safe_free($3);
		safe_free($6);
	} | function {
		char* decl = malloc(strlen($1) + 16);
		sprintf(decl, "%s", $1);
		$$ = add_indentation(decl);
		// free(decl);
	} | SEMICOLON { $$ = safe_strdup("");
	} | error SEMICOLON {
		yyerror("Invalid variable declaration");
		yyerrok;
		$$ = safe_strdup("/* BAD DECLARATION */\n");
	}
	;

hash_ident_list:
	HASH IDENTIFIER { 
		// Prepend # to the identifier for C struct fields if needed, or just use the name
		$$ = safe_strdup($2); 
		safe_free($2);
	} | hash_ident_list COMMA HASH IDENTIFIER {
		char* tmp = malloc(strlen($1) + strlen($4) + 4);
		sprintf(tmp, "%s, %s", $1, $4);
		$$ = tmp;
		safe_free($1); safe_free($4);
	}
	;

ident_list:
	IDENTIFIER {
		$$ = safe_strdup($1);
		safe_free($1);
	}
	| ident_list COMMA IDENTIFIER {
		char* tmp = malloc(strlen($1) + strlen($3) + 2);
		sprintf(tmp, "%s, %s", $1, $3);
		$$ = tmp;
	}
	;


expression:
		primary_expression { $$ = safe_strdup($1); safe_free($1); }
	| expression OP_PLUS expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s + %s", $1, $3);
			safe_free($1); safe_free($3);
	}	| expression OP_MINUS expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s - %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_MULT expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s * %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_DIV expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s / %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_MOD expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s %% %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_POW expression %prec OP_POW {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s ^ %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_EQ expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s == %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_NEQ expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s != %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_LT expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s < %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_LEQ expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s <= %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_GT expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s > %s", $1, $3); safe_free($1); safe_free($3);
	} | expression OP_GEQ expression {
			$$ = malloc(strlen($1) + strlen($3) + 4);
			sprintf($$, "%s >= %s", $1, $3); safe_free($1); safe_free($3);
	} | expression KW_AND expression {
			$$ = malloc(strlen($1) + strlen($3) + 6);
			sprintf($$, "%s && %s", $1, $3); safe_free($1); safe_free($3);
	} | expression KW_OR expression {
			$$ = malloc(strlen($1) + strlen($3) + 5);
			sprintf($$, "%s || %s", $1, $3); safe_free($1); safe_free($3);
	} | KW_NOT expression %prec KW_NOT { $$ = $2; }
	| OP_MINUS expression %prec UMINUS { $$ = $2; } // Unary minus
	| LPAREN expression RPAREN { $$ = $2; } // Parentheses for grouping
	| CONST_BOOL_FALSE { $$ = safe_strdup("false"); }
	| CONST_BOOL_TRUE { $$ = safe_strdup("true"); }
	// | LBRACKET expression KW_FOR IDENTIFIER COLON type KW_IN IDENTIFIER KW_OF CONST_INT RBRACKET {
	// 	// format is for (int i = 0; i < n; ++i)
	// 	fprintf(stderr, "Array comprehension: for (int %s = 0; %s < %s; ++%s)\n", $4, $4, $10, $4);
	// 	char* tmp = malloc(strlen($4) + strlen($10) + 64);
	// }
	;

function_call:
	IDENTIFIER LPAREN arg_list RPAREN {
		$$ = malloc(strlen($1) + strlen($3) + 4);
		sprintf($$, "%s(%s)", $1, $3);
		safe_free($1); safe_free($3);
	}
	;

arg_list:
	/* empty */ { $$ = safe_strdup(""); }
	| expression { $$ = safe_strdup($1);}
	| arg_list COMMA expression {
		char* tmp = malloc(strlen($1) + strlen($3) + 2);
		sprintf(tmp, "%s,%s", $1, $3);
		$$ = tmp;
		safe_free($1); safe_free($3);
	}
	;

primary_expression:
		CONST_INT
	| CONST_FLOAT
	| CONST_STRING
	| IDENTIFIER
	| function_call { $$ = $1; }
	// | IDENTIFIER LPAREN arg_list RPAREN { /* function call */ }
	| primary_expression LBRACKET expression RBRACKET {
		$$ = malloc(strlen($1) + strlen($3) + 4);
		sprintf($$, "%s[%s]", $1, $3);
		safe_free($1); safe_free($3);
	} | primary_expression DOT IDENTIFIER {
		$$ = malloc(strlen($1) + strlen($3) + 2);
		sprintf($$, "%s.%s", $1, $3);
		safe_free($1); safe_free($3);
	} | HASH IDENTIFIER { $$ = safe_strdup($2); safe_free($2); }
	;

block:
	/* empty */ { $$ = safe_strdup(""); }
	| block var_declaration {
		char* tmp = malloc(strlen($1) + strlen($2) + 2);
		sprintf(tmp, "%s%s", $1, $2);
		safe_free($1); safe_free($2);
		$$ = tmp;

	} | block stmt {
		char* tmp = malloc(strlen($1) + strlen($2) + 2);
		sprintf(tmp, "%s%s", $1, $2);
		safe_free($1); safe_free($2);
		$$ = tmp;

	}
	;

decl_list:
	/* empty */ { $$ = safe_strdup(""); }
	| decl_list var_declaration {
		char* tmp = malloc(strlen($1) + strlen($2) + 2);
		sprintf(tmp, "%s%s", $1, $2);
		$$ = tmp;
		safe_free($1);
		safe_free($2);
	} | decl_list error SEMICOLON { yyerrok; }
	;

%%

# ifndef TTLEXER
	int main() {
		yydebug = 1;
		return yyparse();
	}
# endif