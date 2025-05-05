%{
#include <stdarg.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "pi_parser.tab.h"
#include "cgen.h"


int line_num = 1;
%}

DIGIT  [0-9]
NUM  {DIGIT}{DIGIT}*
STRING  ('[^'\n]*')|(\"[^"\n]*\")
IDENTIFIER [a-zA-Z_]([a-zA-Z_]|{DIGIT})*
INTEGER (0|[1-9][0-9]*)
REAL {INTEGER}?\.{DIGIT}?+([eE][+-]?{NUM})?

%x comment


%%

"begin"     {  printf("token KW_BEGIN: %s \n", yytext); return KW_BEGIN; }
"func"      {  printf("token KW_FUNC: %s \n", yytext); return KW_FUNC;}
"int"       {  printf("token KW_INT: %s \n", yytext); return KW_INT; }
"real"      {  printf("token KW_REAL: %s \n", yytext); return KW_REAL;}
"string"    {  printf("token KW_STRING: %s \n", yytext); return KW_STRING;}
"bool"      {  printf("token KW_BOOL: %s \n", yytext); return KW_BOOL;}
"true"      {  printf("token KW_TRUE: %s \n", yytext); return KW_TRUE;}
"false"     {  printf("token KW_FALSE: %s \n", yytext); return KW_FALSE;}
"var"       {  printf("token KW_VAR: %s \n", yytext); return KW_VAR;}
"const"     {  printf("token KW_CONST: %s \n", yytext) ; return KW_CONST;}
"if"        {  printf("token KW_IF: %s \n", yytext); return KW_IF; }
"else"      {  printf("token KW_ELSE: %s \n", yytext); return KW_ELSE;}
"for"       {  printf("token KW_FOR: %s \n", yytext); return KW_FOR;}
"while"     {  printf("token KW_WHILE: %s \n", yytext); return KW_WHILE; }
"break"     {  printf("token KW_BREAK: %s \n", yytext); return KW_BREAK;}
"continue"  {  printf("token KW_CONTINUE: %s \n", yytext); return KW_CONTINUE;}
"nil"       {  printf("token KW_NIL: %s \n", yytext); return KW_NIL;} 
"and"       {  printf("token KW_AND: %s \n", yytext); return KW_AND; }
"or"        {  printf("token KW_OR: %s \n", yytext); return KW_OR; }
"not"       {  printf("token KW_NOT: %s \n", yytext); return KW_NOT; }
"return"    {  printf("token KW_RETURN: %s \n", yytext); return KW_RETURN;} 

{STRING}     {  yylval.crepr = strdup(yytext); printf("token STRING: %s \n",yytext); return STRING; }
{IDENTIFIER} {  yylval.crepr = strdup(yytext); printf("token IDENTIFIER: %s \n",yytext); return IDENTIFIER; } 
{INTEGER}    {  yylval.crepr = strdup(yytext); printf("token INTEGER: %s \n",yytext); return INTEGER;}
{REAL}       {  yylval.crepr = strdup(yytext); printf("token REAL: %s \n",yytext); return REAL; }



 
"+"     { printf("token OP_PLUS: %s \n",yytext); return '+'; }
"-"     { printf("token OP_MINUS: %s \n",yytext); return '-'; }
"*"     { printf("token OP_MUL: %s \n",yytext); return '*'; }
"/"     { printf("token OP_DIV: %s \n",yytext); return '/'; }
"%"     { printf("token OP_MOD: %s \n",yytext); return '%'; }
"**"    { printf("token OP_POWER: %s \n",yytext); return OP_POWER; }
"="     { printf("token OP_ ASSIGN: %s \n",yytext); return '='; }

"=="    { printf("token OP_EQUAL: %s \n",yytext); return EQ; }
">"     { printf("token OP_GREATER: %s \n",yytext) ;return '>'; }
"<"     { printf("token OP_LOWER: %s \n",yytext); return '<'; }
">="    { printf("token OP_GREATER_EQUAL: %s \n",yytext); return GEQ; }
"<="    { printf("token OP_LOWER_EQUAL: %s \n",yytext); return SEQ; }
"!="    { printf("token OP_UNEQUAL: %s \n",yytext); return UNEQ; }

";"     { printf("token DEl_SEMICOLON: %s \n",yytext); return ';' ; }
")"	    { printf("token DEL_RIGHT_PARENTHESIS: %s \n",yytext); return ')'; }
"("	    { printf("token DEl_LEFT_PARENTHESIS: %s \n",yytext); return '('; }
","     { printf("token DEl_COMMA: %s \n",yytext); return ','; }
"["     { printf("token DEl_LEFT_BRACKET: %s \n",yytext); return '['; }
"]"     { printf("token DEl_RIGHT_BRACKET: %s \n",yytext); return ']'; }
"{"     { printf("token DEl_LEFT_CURLY_BRACKET: %s \n",yytext); return '{'; }
"}"	    { printf("token DEl_RIGHT_CURLY_BRACKET: %s \n",yytext); return '}'; }

"//"[^\n]*  	/* eat line comments */






"/*"		BEGIN(comment);
<comment>[^*\n]*        /* eat anything that'\n not a '*' */
<comment>"*"+[^*/\n]*   /* eat up '*'\n not followed by '/'\n */
<comment>\n             ++line_num;
<comment>"*"+"/"        BEGIN(INITIAL);



[ \r\t]		/* skip whitespace */
\n 		++line_num;
<<EOF>> 	return EOF;

.             { yyerror("Unrecognized token %s in line: %d \n \n", yytext,line_num); } 



%%