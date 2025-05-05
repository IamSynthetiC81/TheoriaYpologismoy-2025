%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myanalyzer.tab.h"

// Για την αποθήκευση defmacro αντικαταστάσεων
typedef struct {
    char* name;
    char* replacement;
} Macro;

#define MAX_MACROS 100
Macro macros[MAX_MACROS];
int macro_count = 0;

void add_macro(const char* name, const char* replacement) {
    for (int i = 0; i < macro_count; ++i) {
        if (strcmp(macros[i].name, name) == 0) {
            free(macros[i].replacement);
            macros[i].replacement = strdup(replacement);
            return;
        }
    }
    macros[macro_count].name = strdup(name);
    macros[macro_count].replacement = strdup(replacement);
    macro_count++;
}

char* find_macro(const char* name) {
    for (int i = macro_count - 1; i >= 0; --i) {
        if (strcmp(macros[i].name, name) == 0)
            return macros[i].replacement;
    }
    return NULL;
}

int line_number = 1;
%}

%option noyywrap

%%

"--".*                                 { /* Σχόλια */ line_number++; }
[\n\r]+                                { line_number++; }
[ \t]+                                 { /* Λευκοί χαρακτήρες */ }

"@defmacro"    {
    char name[256], value[1024];
    if (sscanf(yytext, "@defmacro %255s %[^\n\r]", name, value) == 2) {
        add_macro(name, value);
    } else {
        fprintf(stderr, "Invalid macro definition in line %d\n", line_number);
        exit(1);
    }
    line_number++;
}

"True"              { return CONST_BOOL_TRUE; }
"False"             { return CONST_BOOL_FALSE; }

/* Λέξεις-κλειδιά */
"integer"           { return KW_INTEGER; }
"scalar"            { return KW_SCALAR; }
"str"               { return KW_STR; }
"bool"              { return KW_BOOL; }
"const"             { return KW_CONST; }
"if"                { return KW_IF; }
"else"              { return KW_ELSE; }
"endif"             { return KW_ENDIF; }
"for"               { return KW_FOR; }
"in"                { return KW_IN; }
"endfor"            { return KW_ENDFOR; }
"while"             { return KW_WHILE; }
"endwhile"          { return KW_ENDWHILE; }
"break"             { return KW_BREAK; }
"continue"          { return KW_CONTINUE; }
"not"               { return KW_NOT; }
"and"               { return KW_AND; }
"or"                { return KW_OR; }
"def"               { return KW_DEF; }
"enddef"            { return KW_ENDDEF; }
"main"              { return KW_MAIN; }
"return"            { return KW_RETURN; }
"comp"              { return KW_COMP; }
"endcomp"           { return KW_ENDCOMP; }
"of"                { return KW_OF; }

/* Τελεστές */
"=="                { return OP_EQ; }
"!="                { return OP_NEQ; }
"<="                { return OP_LEQ; }
">="                { return OP_GEQ; }
"<"                 { return OP_LT; }
">"                 { return OP_GT; }
"**"                { return OP_POW; }
"\+="               { return OP_PLUSEQ; }
"-="                { return OP_MINUSEQ; }
"\*="               { return OP_MULTEQ; }
"/="                { return OP_DIVEQ; }
"%="                { return OP_MODEQ; }
":="                { return OP_DEFINE; }
"="                 { return OP_ASSIGN; }
"+"                 { return OP_PLUS; }
"-"                 { return OP_MINUS; }
"*"                 { return OP_MULT; }
"/"                 { return OP_DIV; }
"%"                 { return OP_MOD; }

/* Διαχωριστές */
";"                 { return SEMICOLON; }
":"                 { return COLON; }
","                 { return COMMA; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"."                 { return DOT; }

/* Σταθερές */
[0-9]+"."[0-9]+([eE][+-]?[0-9]+)?     { yylval.string = strdup(yytext); return CONST_FLOAT; }
[0-9]+                                { yylval.string = strdup(yytext); return CONST_INT; }
\"([^\"\\]|\\[ntr\"\\])*\"            { yylval.string = strdup(yytext); return CONST_STRING; }

/* Αναγνωριστικά ή μακροεντολές */
[a-zA-Z_][a-zA-Z0-9_]* {
    char* macro = find_macro(yytext);
    if (macro) {
        unput('\n'); // βάζει newline για να μη χαθεί η γραμμή
        for (int i = strlen(macro) - 1; i >= 0; i--) unput(macro[i]);
        return yylex(); // ξανά κάλεσε για νέο token
    } else {
        yylval.string = strdup(yytext);
        return IDENTIFIER;
    }
}

/* Οτιδήποτε άλλο */
. {
    fprintf(stderr, "Unrecognized token '%s' in line %d\n", yytext, line_number);
    exit(1);
}

%%

int yywrap() { return 1; }
