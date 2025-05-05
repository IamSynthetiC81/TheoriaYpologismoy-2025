%{
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "cgen.h"

extern int yylex(void);
extern int lineNum;
%}

%union
{
	char* crepr;
}



%token <crepr> TK_REAL
%token <crepr> TK_IDENT
%token <crepr> TK_INT
%token <crepr> TK_STRING
%token <crepr> TK_STRINGS
%token START
%token POWER
%token EQEQ
%token UNEQ
%token SMEQ
%token KW_IF
%token KW_ELSE
%token KW_NUM
%token KW_BOOL
%token KW_STR
%token KW_VOID
%token KW_TRUE
%token KW_FALSE
%token KW_VAR
%token KW_CONST
%token KW_FOR
%token KW_WHILE
%token KW_FUNC
%token KW_BREAK
%token KW_CONT
%token KW_NOT
%token KW_AND
%token KW_OR
%token KW_RETURN
%token KW_NULL

%start program

%type <crepr> conList varList funcList
%type <crepr> voidBody funcBody
%type <crepr> body decl_list_item_id
%type <crepr> const_decl_list const_decl_list_item
%type <crepr> var_decl_list var_decl_list_item
%type <crepr> func_decl_list func_decl_list_item
%type <crepr> type_spec func_type_spec
%type <crepr> expr operation equation logical_equation logical_operation
%type <crepr> funcCall func_expration
%type <crepr> declCon declVar declFunc
%type <crepr> loopbody ifexp
%type <crepr> ifop elseop
%type <crepr> forop whileop

%left KW_OR
%left KW_AND
%left EQEQ SMEQ UNEQ '<'
%left '-' '+'
%left '/' '*' '%'
%right POWER
%right KW_NOT

%%

program:conList varList funcList KW_FUNC START '(' ')' ':' KW_VOID '{' voidBody '}' {
/* We have a successful parse!
  Check for any errors and generate output.
*/
	if (yyerror_count == 0) {
    // include the mslib.h file
	  puts(c_prologue);
	  printf("%s\n%s\n%s\n", $1, $2, $3);
	  printf("int main() {\n%s\n} \n", $11);
	}
}
|varList funcList KW_FUNC START '(' ')' ':' KW_VOID '{' voidBody '}' {
	if (yyerror_count == 0) {
	  puts(c_prologue);
	  printf("%s\n%s\n", $1, $2);
	  printf("int main() {\n%s\n} \n", $10);
	}
}
|conList funcList KW_FUNC START '(' ')' ':' KW_VOID '{' voidBody '}' {
	if (yyerror_count == 0) {
	  puts(c_prologue);
	  printf("%s\n%s\n", $1, $2);
	  printf("int main() {\n%s\n} \n", $10);
	}
}
|conList varList KW_FUNC START '(' ')' ':' KW_VOID '{' voidBody '}' {
	if (yyerror_count == 0) {
	  puts(c_prologue);
	  printf("%s\n%s\n", $1, $2);
	  printf("int main() {\n%s\n} \n", $10);
	}
}
|conList KW_FUNC START '(' ')' ':' KW_VOID '{' voidBody '}' {
	if (yyerror_count == 0) {
	  puts(c_prologue);
	  printf("%s\n", $1);
	  printf("int main() {\n%s\n} \n", $9);
	}
}
|varList KW_FUNC START '(' ')' ':' KW_VOID '{' voidBody '}' {
	if (yyerror_count == 0) {
	  puts(c_prologue);
	  printf("%s\n", $1);
	  printf("int main() {\n%s\n} \n", $9);
	}
}
|funcList KW_FUNC START '(' ')' ':' KW_VOID '{' voidBody '}' {
	if (yyerror_count == 0) {
	  puts(c_prologue);
	  printf("%s\n", $1);
	  printf("int main() {\n%s\n} \n", $9);
	}
}
|KW_FUNC START '(' ')' ':' KW_VOID '{' voidBody '}' {
	if (yyerror_count == 0) {
	  puts(c_prologue);
	  printf("int main() {\n%s\n} \n", $8);
	}
}
;

conList:
conList declCon { $$ = template("%s\n%s", $1, $2); }
| declCon { $$ = template("%s", $1); }
;

declCon:
KW_CONST const_decl_list ':' type_spec ';' { $$ = template("const %s %s;", $4, $2); }
;

varList:
varList declVar { $$ = template("%s\n%s", $1, $2); }
| declVar { $$ = template("%s", $1); }
;

declVar:
KW_VAR var_decl_list ':' type_spec ';' { $$ = template("%s %s;", $4, $2); }
;

funcList:
funcList declFunc { $$ = template("%s\n%s", $1, $2); }
| declFunc { $$ = template("%s", $1); }
;

declFunc:
KW_FUNC TK_IDENT '(' func_decl_list ')' ':' func_type_spec '{' funcBody '}' ';' { $$ = template("%s %s(%s){%s\n}",$7, $2, $4, $9); }
| KW_FUNC TK_IDENT '(' func_decl_list ')' ':' KW_VOID '{' voidBody '}' ';' { $$ = template("void %s(%s){%s\n}", $2, $4, $9); }
;

func_decl_list:
func_decl_list ',' func_decl_list_item { $$ = template("%s, %s", $1, $3); }
| func_decl_list_item { $$ = template("%s", $1); }
| %empty { $$="";}
;

func_decl_list_item:
decl_list_item_id ':' type_spec { $$ = template("%s %s", $3, $1);}
;

var_decl_list:
var_decl_list ',' var_decl_list_item { $$ = template("%s, %s", $1, $3); }
| var_decl_list_item { $$ = template("%s", $1); }
;

var_decl_list_item:
decl_list_item_id '=' expr { $$ = template("%s =%s", $1, $3);}
| decl_list_item_id '=' TK_INT { $$ = template("%s =%s", $1, $3);}
| decl_list_item_id '=' TK_REAL { $$ = template("%s =%s", $1, $3);}
| decl_list_item_id { $$ = template("%s", $1); }
;

const_decl_list:
const_decl_list ',' const_decl_list_item { $$ = template("%s, %s", $1, $3); }
| const_decl_list_item { $$ = template("%s", $1); }
;

const_decl_list_item:
decl_list_item_id '=' expr { $$ = template("%s =%s", $1, $3);}
| decl_list_item_id '=' TK_INT { $$ = template("%s =%s", $1, $3);}
| decl_list_item_id '=' TK_REAL { $$ = template("%s =%s", $1, $3);}
;

decl_list_item_id: TK_IDENT { $$ = $1; }
| TK_IDENT '['']' { $$ = template("*%s", $1); }
;

type_spec: KW_NUM { $$ = "double"; }
| KW_STR { $$ = "char" ;}
| KW_BOOL { $$ = "int"; }
;


func_type_spec: KW_NUM { $$ = "double"; }
| KW_STR { $$ = "char" ;}
| KW_BOOL { $$ = "int"; }
| '[' ']' KW_NUM { $$ = "double"; }
| '[' ']' KW_STR { $$ = "char" ;}
| '[' ']' KW_BOOL { $$ = "int"; }
;

logical_operation:
logical_operation KW_AND logical_operation{ $$ = template("%s && %s", $1, $3); }
| logical_operation KW_OR logical_operation { $$ = template("%s || %s", $1, $3); }
| KW_NOT logical_operation { $$ = template("!%s", $2); }
| operation { $$ = template("%s", $1); }
| logical_equation { $$ = template("%s", $1); }
;


logical_equation:
operation EQEQ operation { $$ = template("%s == %s", $1, $3); }
| operation UNEQ operation { $$ = template("%s != %s", $1, $3); }
| operation SMEQ operation { $$ = template("%s <= %s", $1, $3); }
| operation '<' operation { $$ = template("%s < %s", $1, $3); }
| '(' logical_equation ')' { $$ = template("(%s)", $2); }
;

operation:
TK_IDENT  { $$ = $1; }
| TK_INT { $$ = $1; }
| TK_REAL { $$ = $1; }
| funcCall { $$ = $1; }
| '(' operation ')' { $$ = template("(%s)", $2); }
| operation '+' operation { $$ = template("%s + %s", $1, $3); }
| '+' funcCall { $$ = template("+%s", $2); }
| '-' funcCall { $$ = template("-%s", $2); }
| '+' TK_IDENT { $$ = template("+%s", $2); }
| '-' TK_IDENT { $$ = template("-%s", $2); }
| '+' TK_IDENT '[' operation ']' { $$ = template("+%s[%s]",$2, $4); }
| '-' TK_IDENT '[' operation ']' { $$ = template("-%s[%s]",$2, $4); }
| operation '-' operation { $$ = template("%s - %s", $1, $3); }
| operation '*' operation { $$ = template("%s * %s", $1, $3); }
| operation '/' operation { $$ = template("%s / %s", $1, $3); }
| operation '%' operation { $$ = template("(int)%s %% (int)%s", $1, $3); }
| operation POWER operation { $$ = template("pow(%s,%s)", $1, $3); }
| TK_IDENT '[' operation ']' { $$ = template("%s[%s]",$1, $3); }
;

equation:
TK_IDENT '=' logical_operation { $$ = template("%s = %s", $1, $3); }
| TK_IDENT '=' expr { $$ = template("%s = %s", $1, $3); }
;

expr: KW_TRUE { $$ = "1"; }
| KW_FALSE { $$ = "0"; }
| TK_STRING {$$ = $1;}
| TK_STRINGS {$$ = $1;}
;

func_expration: func_expration ',' expr { $$ = template("%s, %s", $1, $3); }
| func_expration ',' operation { $$ = template("%s, %s", $1, $3); }
| expr { $$ = template("%s", $1); }
| operation { $$ = template("%s", $1); }
| %empty { $$ = ""; }
;

voidBody: body { $$ = template("%s", $1); }
| body KW_RETURN ';' { $$ = template("%s\nreturn;", $1); }
;

funcBody: body KW_RETURN logical_operation ';' { $$ = template("%s\n return %s ;", $1, $3); }
;

funcCall: TK_IDENT '(' func_expration ')' { $$ = template("%s(%s)", $1, $3); }
;

ifexp: logical_operation { $$ = template("%s", $1); }
| equation { $$ = template("%s", $1); }
| KW_TRUE { $$ = "1"; }
| KW_FALSE { $$ = "0"; }
;

ifop: KW_IF '(' ifexp ')' '{' loopbody '}' ';' { $$ = template("if(%s){%s\n}\n", $3, $6); }
| KW_IF '(' ifexp ')' operation ';'{ $$ = template("if(%s) %s;\n", $3, $5); }
| KW_IF '(' ifexp ')' equation ';'{ $$ = template("if(%s) %s;\n", $3, $5); }
| KW_IF '(' ifexp ')' KW_BREAK ';' { $$ = template("if(%s) break;\n", $3); }
| KW_IF '(' ifexp ')' KW_CONT ';' { $$ = template("if(%s) continue;\n", $3); }
| KW_IF '(' ifexp ')' '{' loopbody '}' ';' elseop { $$ = template("if(%s){%s\n}\n%s", $3, $6, $9); }
| KW_IF '(' ifexp ')' operation ';' elseop { $$ = template("if(%s) %s;\n%s", $3, $5, $7); }
| KW_IF '(' ifexp ')' equation ';' elseop { $$ = template("if(%s) %s;\n%s", $3, $5, $7); }
| KW_IF '(' ifexp ')' KW_BREAK ';' elseop { $$ = template("if(%s) break;\n%s", $3, $7); }
| KW_IF '(' ifexp ')' KW_CONT ';' elseop { $$ = template("if(%s) continue;\n%s", $3, $7); }
;

elseop: KW_ELSE '{' loopbody '}' ';' { $$ = template("else{%s\n}", $3); }
| KW_ELSE operation ';' { $$ = template("else %s;\n", $2); }
| KW_ELSE equation ';' { $$ = template("else %s;\n", $2); }
| KW_ELSE KW_BREAK ';' { $$ = template("else break;\n"); }
| KW_ELSE KW_CONT ';' { $$ = template("else continue;\n"); }
| KW_ELSE ifop { $$ = template("else %s\n", $2); }
;

forop: KW_FOR '(' equation ';' ifexp ';' equation ')' '{' loopbody '}' ';' { $$ = template("for(%s;%s;%s)\n{%s\n}\n", $3, $5, $7, $10); }
| KW_FOR '(' equation ';' ifexp ';' equation ')' operation ';' { $$ = template("for(%s;%s;%s) %s;\n", $3, $5, $7, $9); }
| KW_FOR '(' equation ';' ifexp ';' equation ')' equation ';' { $$ = template("for(%s;%s;%s) %s;\n", $3, $5, $7, $9); }
| KW_FOR '(' equation ';' ifexp ';' equation ')' KW_BREAK ';' { $$ = template("for(%s;%s;%s) break;\n", $3, $5, $7); }
| KW_FOR '(' equation ';' ifexp ';' equation ')' KW_CONT ';' { $$ = template("for(%s;%s;%s) continue;\n", $3, $5, $7); }
| KW_FOR '(' equation ';'';' equation ')' '{' loopbody '}' ';' { $$ = template("for(%s;;%s)\n{%s\n}", $3, $6, $9); }
| KW_FOR '(' equation ';'';' equation ')' operation ';'{ $$ = template("for(%s;;%s) %s;\n", $3, $6, $8); }
| KW_FOR '(' equation ';'';' equation ')' equation ';'{ $$ = template("for(%s;;%s) %s;\n", $3, $6, $8); }
| KW_FOR '(' equation ';'';' equation ')' KW_BREAK ';' { $$ = template("for(%s;;%s) break;\n", $3, $6); }
| KW_FOR '(' equation ';'';' equation ')' KW_CONT ';' { $$ = template("for(%s;;%s) continue;\n", $3, $6); }
;

whileop: KW_WHILE '(' ifexp ')' '{' loopbody '}' ';' { $$ = template("while(%s)\n{%s\n}\n", $3, $6); }
| KW_WHILE '(' ifexp ')' operation ';' { $$ = template("while(%s) %s;\n", $3, $5); }
| KW_WHILE '(' ifexp ')' equation ';' { $$ = template("while(%s) %s;\n", $3, $5); }
| KW_WHILE '(' ifexp ')' KW_BREAK ';' { $$ = template("while(%s) break;\n", $3); }
| KW_WHILE '(' ifexp ')' KW_CONT ';'{ $$ = template("while(%s) continue;\n", $3); }
;

body: %empty { $$ = ""; }
| body declVar { $$ = template("%s\n%s", $1, $2); }
| body declCon { $$ = template("%s\n%s", $1, $2); }
| body operation ';' { $$ = template("%s\n%s;", $1, $2); }
| body equation ';' { $$ = template("%s\n%s;", $1, $2); }
| body ifop { $$ = template("%s\n%s", $1, $2); }
| body forop { $$ = template("%s\n%s", $1, $2); }
| body whileop { $$ = template("%s\n%s", $1, $2); }
;

loopbody: %empty { $$ = ""; }
| loopbody declVar { $$ = template("%s\n%s", $1, $2); }
| loopbody declCon { $$ = template("%s\n%s", $1, $2); }
| loopbody operation ';' { $$ = template("%s\n%s;", $1, $2); }
| loopbody equation ';' { $$ = template("%s\n%s;", $1, $2); }
| loopbody KW_BREAK ';' { $$ = template("%s\nbreak;", $1); }
| loopbody KW_CONT ';' { $$ = template("%s\ncontinue;", $1); }
| loopbody ifop { $$ = template("%s\n%s", $1, $2); }
| loopbody forop { $$ = template("%s\n%s", $1, $2); }
| loopbody whileop { $$ = template("%s\n%s", $1, $2); }
;

%%
int main () {
  if ( yyparse() != 0 )
	// ARRAYS EIDIKES ENTOLES POWER
    printf("Rejected!\n");
}
