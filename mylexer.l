%{
#include "myanalyzer.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int line_num;

char* macro_buffer = NULL;
int macro_buffer_index = 0;
int macro_buffer_len = 0;

int using_macro_input = 0;
int macro_expansion_depth = 0;
#define MAX_MACRO_EXPANSION_DEPTH 100

#undef YY_INPUT
#define YY_INPUT(buf, result, max_size)                                 \
if (using_macro_input && macro_buffer && macro_buffer_index < macro_buffer_len) { \
    int i = 0;                                                      \
    while (i < max_size && macro_buffer_index < macro_buffer_len)  \
        buf[i++] = macro_buffer[macro_buffer_index++];             \
    result = i;                                                    \
    if (macro_buffer_index >= macro_buffer_len) {                  \
        free(macro_buffer);                                        \
        macro_buffer = NULL;                                       \
        using_macro_input = 0;                                     \
        macro_expansion_depth = 0;                                 \
        yypop_buffer_state();                                      \
    }                                                              \
} else {                                                           \
    result = read(yyin->_fileno, buf, max_size);                   \
}


%}

%option noyywrap
%option stack
%option noyy_top_state noyy_pop_state noyy_push_state noinput 

%x DECLCHECK

%%

[a-zA-Z_][a-zA-Z0-9_]*[ \t]*: {
	int id_len = 0;
	while (yytext[id_len] != ' ' && yytext[id_len] != '\t' && yytext[id_len] != ':')
			id_len++;
	char* id = (char*)malloc(id_len + 1);
	strncpy(id, yytext, id_len);
	id[id_len] = '\0';
	yylval.string = id;
	return DECL_IDENT;
}

"--"[^\n]*                        { /* Comment */ }
[\r]?\n {
	line_num++;
	/* Do NOT return NEWLINE — just ignore it */
}

[ \t]+                            { /* skip whitespace */ }
^@defmacro[ \t]+([a-zA-Z_][a-zA-Z0-9_]*)[ \t]+([^\n\r]+)[\r]?\n {
    // Extract name and replacement from yytext
    // char name[256];
    // char replacement[1024];

    // // Use sscanf with format to separate name and replacement safely
    // if (sscanf(yytext, "@defmacro %255s %1023[^\n\r]", name, replacement) == 2) {
    //     add_macro(name, replacement);

    //     fprintf(stderr, "Macro defined: %s -> %s\n", name, replacement);

    //     // If we are currently expanding a macro, we need to push the new state
    //     if (macro_expansion_depth >= MAX_MACRO_EXPANSION_DEPTH) {
    //         fprintf(stderr, "Error: Maximum macro expansion depth exceeded\n");
    //         exit(1);
    //     }

    //     return KW_DEFMACRO;
    // }
    //  else {
    //     fprintf(stderr, "Invalid macro definition line %d: %s\n", line_num, yytext);
    //     exit(1);
    // }   

    // line_num++;
    return KW_DEFMACRO;
}

"True"                            { fprintf(stderr, "CONST_BOOL_TRUE\n"); return CONST_BOOL_TRUE; }
"False"                           { fprintf(stderr, "CONST_BOOL_FALSE\n"); return CONST_BOOL_FALSE; }

[0-9]+\.[0-9]+ {
    fprintf(stderr, "CONST_FLOAT: %s\n", yytext);
    yylval.string = strdup(yytext);
    return CONST_FLOAT;
}
[0-9]+\.[0-9]+([eE][+-]?[0-9]+)? {
    fprintf(stderr, "CONST_FLOAT: %s\n", yytext);
    yylval.string = strdup(yytext);
    return CONST_FLOAT;
}
[0-9]+ {
    fprintf(stderr, "CONST_INT: %s\n", yytext);
    yylval.string = strdup(yytext);
    return CONST_INT;
}
\"([^\"\\]|\\.)*\"                { fprintf(stderr, "CONST_STRING\n"); yylval.string = strdup(yytext); return CONST_STRING; }


"while"         { fprintf(stderr, "KW_WHILE\n"); return KW_WHILE; }
"endwhile"      { fprintf(stderr, "KW_ENDWHILE\n"); return KW_ENDWHILE; }
"break"         { fprintf(stderr, "KW_BREAK\n"); return KW_BREAK; }
"continue"      { fprintf(stderr, "KW_CONTINUE\n"); return KW_CONTINUE; }
"comp"          { fprintf(stderr, "KW_COMP\n"); return KW_COMP; }
"endcomp"       { fprintf(stderr, "KW_ENDCOMP\n"); return KW_ENDCOMP; }
"of"            { fprintf(stderr, "KW_OF\n"); return KW_OF; }

"**"            { fprintf(stderr, "OP_POW\n"); return OP_POW; }
"+="            { fprintf(stderr, "OP_PLUSEQ\n"); return OP_PLUSEQ; }
"-="            { fprintf(stderr, "OP_MINUSEQ\n"); return OP_MINUSEQ; }
"*="            { fprintf(stderr, "OP_MULTEQ\n"); return OP_MULTEQ; }
"/="            { fprintf(stderr, "OP_DIVEQ\n"); return OP_DIVEQ; }
"%="            { fprintf(stderr, "OP_MODEQ\n"); return OP_MODEQ; }
"->"            { fprintf(stderr, "OP_ARROW\n"); return OP_ARROW; }

"#"             { fprintf(stderr, "HASH\n"); return HASH; }
","            { fprintf(stderr, "COMMA\n"); return COMMA; }

"def"                             { fprintf(stderr, "KW_DEF\n"); return KW_DEF; }
"enddef"                          { fprintf(stderr, "KW_ENDDEF\n");return KW_ENDDEF; }
"main"                            { fprintf(stderr, "KW_MAIN\n");return KW_MAIN; }
"return"                          { fprintf(stderr, "KW_RETURN\n");return KW_RETURN; }

"if"                              { fprintf(stderr, "KW_IF\n"); return KW_IF; }
"else"                            { fprintf(stderr, "KW_ELSE\n"); return KW_ELSE; }
"endif"                           { fprintf(stderr, "KW_ENDIF\n"); return KW_ENDIF; }

"for"                             { fprintf(stderr, "KW_FOR\n"); return KW_FOR; }
"in"                              { fprintf(stderr, "KW_IN\n"); return KW_IN; }
"endfor"                          { fprintf(stderr, "KW_ENDFOR\n"); return KW_ENDFOR; }

"integer"                         { fprintf(stderr, "KW_INTEGER\n"); return KW_INTEGER; }
"scalar"                          { fprintf(stderr, "KW_SCALAR\n"); return KW_SCALAR; }
"str"                             { fprintf(stderr, "KW_STR\n"); return KW_STR; }
"bool"                            { fprintf(stderr, "KW_BOOL\n"); return KW_BOOL; }
"const"                           { fprintf(stderr, "KW_CONST\n"); return KW_CONST; }

"not"                             { fprintf(stderr, "KW_NOT\n"); return KW_NOT; }
"and"                             { fprintf(stderr, "KW_AND\n"); return KW_AND; }
"or"                              { fprintf(stderr, "KW_OR\n"); return KW_OR; }

"=="                              { fprintf(stderr, "OP_EQ\n"); return OP_EQ; }
"!="                              { fprintf(stderr, "OP_NEQ\n"); return OP_NEQ; }
"<="                              { fprintf(stderr, "OP_LEQ\n"); return OP_LEQ; }
">="                              { fprintf(stderr, "OP_GEQ\n"); return OP_GEQ; }
"<"                               { fprintf(stderr, "OP_LT\n"); return OP_LT; }
">"                               { fprintf(stderr, "OP_GT\n"); return OP_GT; }

":="                              { fprintf(stderr, "OP_DEFINE\n"); return OP_DEFINE; }
"="                               { fprintf(stderr, "OP_ASSIGN\n"); return OP_ASSIGN; }
"+"                               { fprintf(stderr, "OP_PLUS\n"); return OP_PLUS; }
"-"                               { fprintf(stderr, "OP_MINUS\n"); return OP_MINUS; }
"*"                               { fprintf(stderr, "OP_MULT\n"); return OP_MULT; }
"/"                               { fprintf(stderr, "OP_DIV\n"); return OP_DIV; }
"%"                               { fprintf(stderr, "OP_MOD\n"); return OP_MOD; }

"("                               { fprintf(stderr, "LPAREN\n"); return LPAREN; }
")"                             	{ fprintf(stderr, "RPAREN\n"); return RPAREN; }


"["                               { fprintf(stderr, "LBRACKET\n"); return LBRACKET; }
"]"                               { fprintf(stderr, "RBRACKET\n"); return RBRACKET; }
":"                               { fprintf(stderr, "COLON\n"); return COLON; }
";"                               { fprintf(stderr, "SEMICOLON\n"); return SEMICOLON; }
"."                               { fprintf(stderr, "DOT\n"); return DOT; }



[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.string = strdup(yytext);
    BEGIN(DECLCHECK);
    return IDENTIFIER;
}

<DECLCHECK>[ \t\r]+    { /* skip whitespace */ }
<DECLCHECK>\n          { line_num++; /* skip newline */ }
<DECLCHECK>--[^\n]*    { /* skip comment */ }
<DECLCHECK>:           { BEGIN(INITIAL); return DECL_IDENT; }
<DECLCHECK>.           { BEGIN(INITIAL); unput(yytext[0]); }

. { fprintf(stderr, "Unknown character '%c' (ASCII %d) at line %d\n", *yytext, (int)*yytext, line_num); exit(1); }

%%