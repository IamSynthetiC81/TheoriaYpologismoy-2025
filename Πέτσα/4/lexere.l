%{
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ms_parser.tab.h"
#include "cgen.h"
int lineNum = 1;
%}

STRING_LITERALS [a-zA-Z0-9\*\/\:_$#\!@\&\~\^()\+\- ]*
SPECIAL_CHARS ("\\"("\'"|"\""|"n"|"t"|"r"|"\\"))*
ID      [a-zA-Z_][0-9a-zA-Z_]*
DIGIT   [0-9]
NUMBERs  [+-]?{DIGIT}{DIGIT}*
DECIMAL ([+-]?"."{NUMBERs})|([+-]?{NUMBERs}("."{NUMBERs}?)?)
REAL    {DECIMAL}([eE][+-]?{NUMBERs})?
STRING "\""({STRING_LITERALS}{SPECIAL_CHARS})*"\""
STRINGS "\'"({STRING_LITERALS}{SPECIAL_CHARS})*"\'"
%x comment

%%

if          return KW_IF;
else		    return KW_ELSE;
number      return KW_NUM;
boolean     return KW_BOOL;
string      return KW_STR;
void        return KW_VOID;
break       return KW_BREAK;
return      return KW_RETURN;
true        return KW_TRUE;
continue    return KW_CONT;
null        return KW_NULL;
false       return KW_FALSE;
for         return KW_FOR;
not         return KW_NOT;
var         return KW_VAR;
while       return KW_WHILE;
and         return KW_AND;
const       return KW_CONST;
function    return KW_FUNC;
or          return KW_OR;
start       return START;


{ID}         { yylval.crepr = strdup(yytext); return TK_IDENT; }
{NUMBERs}    { yylval.crepr = strdup(yytext); return TK_INT; }
{REAL}       { yylval.crepr = strdup(yytext); return TK_REAL; }
{STRING}     { yylval.crepr = strdup(yytext); return TK_STRING; }
{STRINGS}     { yylval.crepr = strdup(yytext); return TK_STRINGS; }


"+"         return '+';
"-"         return '-';
"*"         return '*';
"/"         return '/';
"%"         return '%';
"**"        return POWER;
"=="        return EQEQ;
"!="        return UNEQ;
"<"         return '<';
"<="        return SMEQ;
"="         return '=';
","         return ',';
"["         return '[';
"]"         return ']';
"{"         return '{';
"}"         return '}';
":"         return ':';
";"         return ';';
"("				  return '(';
")"					return ')';

"/*"                    { BEGIN(comment);}

<comment>[^*\n]*        /* eat anything that's not a '*' */
<comment>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
<comment>\n             ++lineNum;
<comment>"*"+"/"        { BEGIN(INITIAL);}




"//"[^\n]*  /* eat line comments */


[ \r\t]+		/* eat whitespace */
\n 					 ++lineNum;

<<EOF>> 	return EOF;
.           { printf("lexical error: unrecognized literal '%s'\n", yytext); }

%%
    /*
      <stringss>[;`\?,.\<\>\=\|\[\]{}]*/
