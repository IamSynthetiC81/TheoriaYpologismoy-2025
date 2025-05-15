/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_OUT_MYANALYZER_TAB_H_INCLUDED
# define YY_YY_OUT_MYANALYZER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CONST_INT = 259,               /* CONST_INT  */
    CONST_FLOAT = 260,             /* CONST_FLOAT  */
    CONST_STRING = 261,            /* CONST_STRING  */
    CONST_BOOL_TRUE = 262,         /* CONST_BOOL_TRUE  */
    CONST_BOOL_FALSE = 263,        /* CONST_BOOL_FALSE  */
    KW_INTEGER = 264,              /* KW_INTEGER  */
    KW_SCALAR = 265,               /* KW_SCALAR  */
    KW_STR = 266,                  /* KW_STR  */
    KW_BOOL = 267,                 /* KW_BOOL  */
    KW_CONST = 268,                /* KW_CONST  */
    KW_IF = 269,                   /* KW_IF  */
    KW_ELSE = 270,                 /* KW_ELSE  */
    KW_ENDIF = 271,                /* KW_ENDIF  */
    KW_FOR = 272,                  /* KW_FOR  */
    KW_IN = 273,                   /* KW_IN  */
    KW_ENDFOR = 274,               /* KW_ENDFOR  */
    KW_WHILE = 275,                /* KW_WHILE  */
    KW_ENDWHILE = 276,             /* KW_ENDWHILE  */
    KW_BREAK = 277,                /* KW_BREAK  */
    KW_CONTINUE = 278,             /* KW_CONTINUE  */
    KW_NOT = 279,                  /* KW_NOT  */
    KW_AND = 280,                  /* KW_AND  */
    KW_OR = 281,                   /* KW_OR  */
    KW_DEF = 282,                  /* KW_DEF  */
    KW_ENDDEF = 283,               /* KW_ENDDEF  */
    KW_MAIN = 284,                 /* KW_MAIN  */
    KW_RETURN = 285,               /* KW_RETURN  */
    KW_COMP = 286,                 /* KW_COMP  */
    KW_ENDCOMP = 287,              /* KW_ENDCOMP  */
    KW_OF = 288,                   /* KW_OF  */
    OP_ASSIGN = 289,               /* OP_ASSIGN  */
    OP_PLUSEQ = 290,               /* OP_PLUSEQ  */
    OP_MINUSEQ = 291,              /* OP_MINUSEQ  */
    OP_MULTEQ = 292,               /* OP_MULTEQ  */
    OP_DIVEQ = 293,                /* OP_DIVEQ  */
    OP_MODEQ = 294,                /* OP_MODEQ  */
    OP_DEFINE = 295,               /* OP_DEFINE  */
    OP_EQ = 296,                   /* OP_EQ  */
    OP_NEQ = 297,                  /* OP_NEQ  */
    OP_LT = 298,                   /* OP_LT  */
    OP_LEQ = 299,                  /* OP_LEQ  */
    OP_GT = 300,                   /* OP_GT  */
    OP_GEQ = 301,                  /* OP_GEQ  */
    OP_PLUS = 302,                 /* OP_PLUS  */
    OP_MINUS = 303,                /* OP_MINUS  */
    OP_MULT = 304,                 /* OP_MULT  */
    OP_DIV = 305,                  /* OP_DIV  */
    OP_MOD = 306,                  /* OP_MOD  */
    OP_POW = 307,                  /* OP_POW  */
    LPAREN = 308,                  /* LPAREN  */
    RPAREN = 309,                  /* RPAREN  */
    LBRACKET = 310,                /* LBRACKET  */
    RBRACKET = 311,                /* RBRACKET  */
    COLON = 312,                   /* COLON  */
    SEMICOLON = 313,               /* SEMICOLON  */
    COMMA = 314,                   /* COMMA  */
    DOT = 315                      /* DOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "myanalyzer.y"

    char* string;

#line 128 "out/myanalyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_OUT_MYANALYZER_TAB_H_INCLUDED  */
