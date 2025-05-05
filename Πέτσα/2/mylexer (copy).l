%{
#include <assert.h>
#include <stdio.h>
#include "cgen.h"

#define END_OF_FILE     0
#define KW_INTEGER      1
#define KW_SCALAR       2
#define KW_STR          3
#define KW_BOOLEAN      4
#define KW_TRUE         5
#define KW_FALSE        6
#define KW_CONST        7
#define KW_IF           8
#define KW_ELSE         9
#define KW_ENDIF        10
#define KW_FOR          11
#define KW_IN           12
#define KW_ENDFOR       13
#define KW_WHILE        14
#define KW_ENDWHILE     15
#define KW_BREAK        16
#define KW_CONTINUE     17
#define KW_NOT          18
#define KW_AND          19
#define KW_OR           20
#define KW_DEF          21
#define KW_MAIN         22
#define KW_RETURN       23
#define KW_ENDDEF       24
#define KW_COMP         25
#define KW_ENDCOMP      26
#define IDENTIFIER      27
#define CONST_INT       28
#define CONST_SCALAR    29
#define CONST_STRING    30
#define PLUS_OP         31
#define MINUS_OP        32
#define MULTIPLY_OP     33
#define DIVIDE_OP       34
#define MODULO_OP       35
#define POWER_OP        36
#define EQ_SIGN         37
#define NOTEQ_SIGN      38
#define LT_SIGN         39
#define LTEQ_SIGN       40
#define GT_SIGN         41
#define GTEQ_SIGN       42
#define ASSIGN          43
#define COMMA           44
#define LBRACKET        45
#define RBRACKET        46
#define DECLARE         47
#define ACCESS          48
#define SEMICOLON       49
#define LPARENTHESIS    50
#define RPARENTHESIS    51


int lineNum = 1;
%}


COMMON_CHARACTERS [a-zA-Z0-9\-\+\/\*\:\_\$%!#@\&~\^\(\)]
STRING_CHARACTERS [a-zA-Z0-9\-\+\/\*\:\_\$%!#@\&~\^\(\) ]
ESCAPE_CHARACTERS (\\n|\\t|\\r|\\\\|\\\")
ID [a-zA-Z][0-9a-zA-Z_]*
INTEGERCONSTANTS [+-]?[0-9]+
FLOATINGCONSTANTS [+-]?[0-9]+\.[0-9]+([eE]+[+-]*[1-9][0-9]*)*
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

{ID}                {return IDENTIFIER;}

{INTEGERCONSTANTS}  {return CONST_INT;}

{FLOATINGCONSTANTS} {return CONST_SCALAR;}

{STRINGCONSTANTS}   {return CONST_STRING;}

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

\n 					++lineNum;
[ \t\r]+            /* eat up whitespace */

"--"[^\n]*          /* eat up line-comment */

.                   { printf("Unrecognized token '%s' in line '%d': '%s' \n",yytext, lineNum, yytext); }
<<EOF>>             {return END_OF_FILE;}

%%

int main( ){

    int token;
    while((token=yylex())!=0){
        printf("token %d: %s \n", token, yytext);
    }
}

