%{
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>		
#include "cgen.h"

extern int yylex(void);
extern int line_num;
%}

%union
{
	char* crepr;
}


 
%token <crepr> STRING
%token <crepr> IDENTIFIER
%token <crepr> REAL
%token <crepr> INTEGER

%token     KW_BEGIN
%token     KW_FUNC
%token     KW_INT 
%token     KW_REAL 
%token     KW_BOOL 
%token     KW_TRUE 
%token     KW_STRING   
%token     KW_FALSE 
%token     KW_VAR 
%token     KW_CONST 
%token     KW_IF 
%token     KW_ELSE 
%token     KW_WHILE 
%token     KW_BREAK 
%token     KW_CONTINUE 
%token     KW_NIL 
%token     KW_AND 
%token     KW_OR 
%token     KW_NOT 
%token     KW_RETURN 
%token     KW_FOR 

%token     OP_POWER



%token EQ
%token GEQ
%token UNEQ
%token SEQ





%type <crepr>  body func_call complex_commands func_body decl_list mult_const mult_var mult_func item
%type <crepr> decl_var decl_var_list decl_const decl_const_list decl_func decl_func_list
%type <crepr> decl_array decl_array_item data_type function_data_type
%type <crepr> expr logical_expr arithmetic_expr basic_expr assignement function_expr
%type <crepr> if_expr if_command else_command for_command while_command 



%left KW_OR
%left KW_AND
%left EQ GEQ UNEQ SEQ '>' '<'
%left '+' '-'
%left '*' '/' '%'
%right OP_POWER
%right KW_NOT

%start program

%%

program:  decl_list mult_func KW_FUNC KW_BEGIN '(' ')' '{' body '}' ';' { 

 /* We have a successful parse! 
    Check for any errors and generate output. 
  */
 
  if (yyerror_count == 0) {
    
    puts(c_prologue); 
    printf("%s\n%s\n\n ",$1,$2);
    printf("int main() { %s\n } \n", $8);
  }
} 

|decl_list KW_FUNC KW_BEGIN '(' ')' '{' body '}' ';' { 

 /* We have a successful parse! 
    Check for any errors and generate output. 
  */
 
  if (yyerror_count == 0) {
    
    puts(c_prologue); 
    printf("%s\n",$1);
    printf("int main() { %s\n } \n", $7);
  }
}

|mult_func KW_FUNC KW_BEGIN '(' ')' '{' body '}' ';' { 

 /* We have a successful parse! 
    Check for any errors and generate output. 
  */
 
  if (yyerror_count == 0) {
    
    puts(c_prologue); 
    printf("%s\n",$1);
    printf("int main() { %s\n } \n", $7);
  }
}

|KW_FUNC KW_BEGIN '(' ')' '{' body '}' ';' { 

 /* We have a successful parse! 
    Check for any errors and generate output. 
  */
 
  if (yyerror_count == 0) {
    
    puts(c_prologue); 
    printf("\n");
    printf("int main() { %s\n } \n", $6);
  }
} 
;


decl_list:
mult_const {$$ =template("%s\n", $1);}
|mult_var {$$ =template("%s\n", $1);}
|mult_const mult_var {$$ = template("%s\n%s",$1,$2);}
;

mult_var:
mult_var decl_var  { $$ = template("%s\n%s", $1, $2); }
| decl_var { $$ = template("%s", $1); }
;


decl_var:  
KW_VAR decl_var_list  data_type ';' { $$ = template ("%s %s;",$3,$2);}
;
 
decl_var_list:
item {$$=$1;}
|IDENTIFIER{$$=$1;}
| decl_var_list ',' item { $$ = template ("%s,%s",$1,$3);}
| decl_var_list ',' IDENTIFIER { $$ = template ("%s,%s",$1,$3);}
;

mult_const:
mult_const decl_const  { $$ = template("%s\n%s", $1, $2); }
| decl_const { $$ = template("%s", $1); }
;

decl_const:  
KW_CONST decl_const_list  data_type ';' { $$ = template ("%s %s;",$3,$2);}
;
 
decl_const_list:
item {$$=$1;}
| decl_const_list ',' item { $$ = template ("%s,%s",$1,$3);}
;

item:
IDENTIFIER '=' expr { $$ = template ("%s =%s",$1,$3);}
| IDENTIFIER '=' basic_expr { $$ = template ("%s =%s",$1,$3);}
| decl_array '=' expr { $$ = template ("%s =%s",$1,$3);}
| decl_array '=' basic_expr { $$ = template ("%s =%s",$1,$3);}
;

decl_array:
IDENTIFIER '['INTEGER']'   {$$= template("%s[%s]",$1,$3);}
;

decl_array_item:
'[' INTEGER ']' IDENTIFIER  {$$=template("*%s",$4);}
;

mult_func:
mult_func decl_func  { $$ = template("%s\n%s", $1, $2); }
| decl_func { $$ = template("%s", $1); }
;

decl_func:
KW_FUNC IDENTIFIER '(' decl_func_list ')' function_data_type '{' func_body '}'  ';' { $$ = template("%s %s(%s){%s\n}",$6, $2, $4, $8); }
;


decl_func_list:
IDENTIFIER function_data_type { $$ = template ("%s %s",$2,$1);}
| decl_func_list ',' IDENTIFIER function_data_type { $$ = template ("%s\n %s %s",$1,$4,$3);}

;



data_type:
KW_INT { $$ = "int"; }
|KW_STRING { $$ = "char*"; } 
|KW_REAL { $$ = "double"; }
|KW_BOOL { $$ = "int"; }
 ;

function_data_type:
data_type {$$ = $1;}
|'[' ']' data_type {$$ = $3;}
 ;




logical_expr:
arithmetic_expr {$$ = $1 ;}
| '(' logical_expr ')' { $$ = $2;}
| logical_expr EQ logical_expr { $$ = template("%s == %s", $1, $3);}
| logical_expr '>' logical_expr { $$ = template("%s > %s", $1, $3);}
| logical_expr GEQ logical_expr { $$ = template("%s >= %s", $1, $3);}
| logical_expr '<' logical_expr { $$ = template("%s < %s", $1, $3);}
| logical_expr SEQ logical_expr { $$ = template("%s <= %s", $1, $3);}
| logical_expr UNEQ logical_expr { $$ = template("%s != %s", $1, $3);}
| KW_NOT logical_expr { $$ = template("!%s", $2);}
| logical_expr KW_AND logical_expr { $$ = template("%s && %s", $1, $3);}
| logical_expr KW_OR logical_expr { $$ = template("%s || %s", $1, $3);}
;

arithmetic_expr:
basic_expr {$$ = $1 ;}
| func_call { $$ = $1; }
| arithmetic_expr '+' arithmetic_expr { $$ = template("%s + %s", $1, $3); }
| arithmetic_expr '-' arithmetic_expr { $$ = template("%s - %s", $1, $3); }
| arithmetic_expr '*' arithmetic_expr { $$ = template("%s * %s", $1, $3); }
| arithmetic_expr '/' arithmetic_expr { $$ = template("%s / %s", $1, $3); }
| arithmetic_expr '%' arithmetic_expr { $$ = template("%s %%  %s", $1, $3); }
| arithmetic_expr OP_POWER arithmetic_expr {$$ = template("pow(%s,%s)", $1, $3);}
| '(' arithmetic_expr ')'  { $$ = template("(%s)",$2); }
;

basic_expr:
IDENTIFIER { $$ = $1; }
| INTEGER { $$ = $1; }
| REAL { $$ = $1;}
| '+' basic_expr { $$ = template("+%s", $2); }
| '-' basic_expr { $$ = template("-%s", $2); }
;

expr: 
STRING { $$ = $1;}
| KW_TRUE { $$ = "1";}
| KW_FALSE { $$ = "0";}
;

assignement:
IDENTIFIER '=' logical_expr ';' {$$ = template("%s = %s",$1, $3);}
| IDENTIFIER '=' expr ';' {$$ = template("%s = %s",$1, $3);}
| decl_array_item '=' logical_expr  {$$ = template("%s = %s",$1, $3);}
| decl_array_item '=' expr  {$$ = template("%s = %s",$1, $3);}
;

function_expr:
logical_expr { $$ = $1; }
| expr { $$ = $1; }
| function_expr ',' expr {$$ = template("%s, %s",$1, $3);}
| function_expr ',' logical_expr {$$ = template("%s, %s",$1, $3);}
| %empty { $$ = ""; }
;


func_call:
IDENTIFIER '(' function_expr ')'  { $$ = template("%s(%s)", $1, $3); }
;

func_body:
 body KW_RETURN logical_expr ';'  {$$ = template("%s\nreturn(%s); ",$1,$3);}
|  body KW_RETURN ';'  {$$ = template("%s \nreturn; ",$1);}
;

body: %empty { $$=" ";}
| body decl_var { $$ = template("%s \n %s", $1, $2); }
| body decl_const { $$ = template("%s \n %s", $1, $2); }
| body assignement  { $$ = template("%s \n %s;", $1, $2); }
| body if_command { $$ = template("%s \n %s", $1, $2); }
| body for_command { $$ = template("%s \n %s", $1, $2); }
| body while_command { $$ = template("%s \n %s", $1, $2); }
| body func_call ';' {$$=template("%s \n %s;",$1,$2);}
;

complex_commands:
%empty {$$ = " ";}
| complex_commands decl_var { $$ = template("%s \n %s", $1, $2); }
| complex_commands decl_const { $$ = template("%s \n %s", $1, $2); }
| complex_commands assignement  { $$ = template("%s \n %s;", $1, $2); }
| complex_commands KW_BREAK ';' {$$ = template("break; \n");}
| complex_commands KW_CONTINUE ';' {$$ = template("continue; \n");}
| complex_commands if_command { $$ = template("%s \n %s", $1, $2); }
| complex_commands for_command { $$ = template("%s \n %s", $1, $2); }
| complex_commands while_command { $$ = template("%s \n %s", $1, $2); }
| complex_commands func_call ';' { $$ = template("%s \n %s", $1, $2); }
;





if_expr:
KW_TRUE {$$ = "1";}
| KW_FALSE { $$ = "0";}
| assignement {$$ = $1;}
| logical_expr {$$ = $1;}
;

if_command:
KW_IF '(' if_expr ')' '{' complex_commands '}' ';' {$$ = template("if(%s) {%s}",$3,$6);}
| KW_IF '(' if_expr ')' assignement  {$$ = template("if(%s)\n %s",$3,$5);}
| KW_IF '(' if_expr ')' func_call  {$$ = template("if(%s)\n %s",$3,$5);}
| KW_IF '(' if_expr ')' KW_BREAK ';' {$$ = template("if(%s)\n  break; \n",$3);}
| KW_IF '(' if_expr ')' KW_CONTINUE ';' {$$ = template("if(%s)\n  continue; \n",$3);}
| KW_IF '(' if_expr ')' '{' complex_commands '}' ';' else_command {$$ = template("if(%s) {%s}",$3,$6);}
| KW_IF '(' if_expr ')' assignement  else_command {$$ = template("if(%s)\n %s \n%s",$3,$5,$6);}
| KW_IF '(' if_expr ')' func_call  else_command {$$ = template("if(%s)\n %s\n%s",$3,$5,$6);}
| KW_IF '(' if_expr ')' KW_BREAK ';' else_command {$$ = template("if(%s)\n  break; \n",$3);}
| KW_IF '(' if_expr ')' KW_CONTINUE ';' else_command {$$ = template("if(%s)\n  continue; \n",$3);}
;

else_command:
KW_ELSE assignement ';' { $$ = template("else %s;\n",$2);}
|KW_ELSE func_call  { $$ = template("else %s;\n",$2);}
|KW_ELSE '{' complex_commands '}' ';' { $$ = template("else {%s}", $3);}
|KW_ELSE KW_BREAK ';' { $$ = template("else \n break;\n");}
|KW_ELSE KW_CONTINUE ';' { $$ = template("else \n continue; \n");}
|KW_ELSE if_command  { $$ = template("else %s", $2);}
;

for_command: 
KW_FOR '(' assignement ';' if_expr ';' assignement ')' '{' complex_commands '}' {$$ = template("for(%s ;%s; %s)\n {%s}",$3,$5,$7,$10);}
|KW_FOR '(' assignement ';' if_expr ';' assignement ')' assignement ';' {$$ = template("for(%s ;%s; %s)\n %s",$3,$5,$7,$9);}
|KW_FOR '(' assignement ';' if_expr ';' assignement ')' func_call ';' {$$ = template("for(%s ;%s; %s)\n %s",$3,$5,$7,$9);}
|KW_FOR '(' assignement ';' if_expr ';' assignement ')' KW_BREAK ';' {$$ = template("for(%s ;%s;%s)\n break \n",$3,$5,$7);}
|KW_FOR '(' assignement ';' if_expr ';' assignement ')' KW_CONTINUE ';' {$$ = template("for(%s ;%s; %s)\n continue; \n",$3,$5,$7);}
|KW_FOR '(' assignement ';'';' assignement ')' '{' complex_commands '}' {$$ = template("for(%s ;; %s)\n {%s}",$3,$6,$9);}
|KW_FOR '(' assignement ';' ';' assignement ')' assignement ';' {$$ = template("for(%s ;; %s)\n %s",$3,$6,$8);}
|KW_FOR '(' assignement ';' ';' assignement ')' func_call ';' {$$ = template("for(%s ;; %s) \n %s",$3,$6,$8);}
|KW_FOR '(' assignement ';' ';' assignement ')' KW_BREAK ';' {$$ = template("for(%s ;;%s) \n break; \n",$3,$6);}
|KW_FOR '(' assignement ';' ';' assignement ')' KW_CONTINUE ';' {$$ = template("for(%s ;; %s) \n continue; \n",$3,$6);}
;

while_command:
KW_WHILE '(' if_expr ')' '{' complex_commands '}' ';' {$$ = template("while(%s)\n {%s}",$3,$6);}
| KW_WHILE '(' if_expr ')' assignement ';' {$$ = template("while(%s)\n %s",$3,$5);}
| KW_WHILE '(' if_expr ')' func_call ';' {$$ = template("while(%s) \n%s",$3,$5);}
| KW_WHILE '(' if_expr ')' KW_CONTINUE ';' {$$ = template("while(%s)\ncontinue; \n",$3);}
| KW_WHILE '(' if_expr ')' KW_BREAK ';' {$$ = template("while(%s)\n break; \n",$3);}
;

%%
int main () {
  if ( yyparse() != 0 )
    printf("Rejected!\n");
}

