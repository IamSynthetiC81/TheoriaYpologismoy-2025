%{
#include <assert.h>
#include <stdio.h>
#include "cgen.h"
#include "myanalyzer.tab.h"

int line_num = 1;
%}


COMMON_CHARACTERS [a-zA-Z0-9\-\+\/\*\:\_\$%!#@\&~\^\(\)]
STRING_CHARACTERS [a-zA-Z0-9\-\+\/\*\:\_\$\%\!\#\@\&~\^\(\)\.\, ]
ESCAPE_CHARACTERS (\\n|\\t|\\r|\\\\|\\\")
ID [a-zA-Z][0-9a-zA-Z_]*
INTEGERCONSTANTS [0-9]+
FLOATINGCONSTANTS [0-9]+\.[0-9]+([eE]+[+-]*[1-9][0-9]*)*
STRINGCONSTANTS ("\"")({STRING_CHARACTERS}|{ESCAPE_CHARACTERS})*("\"")

%%

integer             {return KW_INTEGER;}
scalar              {return KW_SCALAR;}
str                 {return KW_STR;}
boolean             {return KW_BOOLEAN;}
True                {return KW_TRUE;}
False               {return KW_FALSE;}
const               {return KW_CONST;}
if                  {return KW_IF;}
else                {return KW_ELSE;}
endif               {return KW_ENDIF;}
for                 {return KW_FOR;}
in                  {return KW_IN;}
endfor              {return KW_ENDFOR;}
while               {return KW_WHILE;}
endwhile            {return KW_ENDWHILE;}
break               {return KW_BREAK;}
continue            {return KW_CONTINUE;}
not                 {return KW_NOT;}
and                 {return KW_AND;}
or                  {return KW_OR;}
def                 {return KW_DEF;}
enddef              {return KW_ENDDEF;}
main                {return KW_MAIN;}
return              {return KW_RETURN;}
comp                {return KW_COMP;}
endcomp             {return KW_ENDCOMP;}

{ID}                {yylval.str = strdup(yytext); return IDENTIFIER;}

{INTEGERCONSTANTS}  {yylval.str = strdup(yytext); return CONST_INT;}

{FLOATINGCONSTANTS} {yylval.str = strdup(yytext); return CONST_SCALAR;}

{STRINGCONSTANTS}   {yylval.str = strdup(yytext); return CONST_STRING;}

"+"                 {return PLUS_OP;}
"-"                 {return MINUS_OP;}
"*"                 {return MULTIPLY_OP;}
"/"                 {return DIVIDE_OP;}
"%"                 {return MODULO_OP;}
"**"                {return POWER_OP;}
"=="                {return EQ_SIGN;}
"!="                {return NOTEQ_SIGN;}
"<"                 {return LT_SIGN;}
"<="                {return LTEQ_SIGN;}
">"                 {return GT_SIGN;}
">="                {return GTEQ_SIGN;}
"="                 {return ASSIGN;}
","                 {return COMMA;}
"["                 {return LBRACKET;}
"]"                 {return RBRACKET;}
":"                 {return DECLARE;}
"."                 {return ACCESS;}  
";"                 {return SEMICOLON;}
"("				    {return LPARENTHESIS;}
")"				    {return RPARENTHESIS;}
"#"                 {return HASHTAG;}
"->"                {return LARROW;}
"+="                {return PLUS_ASSIGN;}
"-="                {return MINUS_ASSIGN;}
"*+"                {return MULTIPLY_ASSIGN;}
"/="                {return DIVIDE_ASSIGN;}
"%="                {return MODULO_ASSIGN;}

\n 					++line_num;
[ \t\r]+            /* eat up whitespace */

"--"[^\n]*          /* eat up line-comment */

.                   { printf("Unrecognized token '%s' in line '%d': '%s' \n",yytext, line_num, yytext); }
<<EOF>>             {return END_OF_FILE;}

%%



