/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_MYANALYZER_TAB_H_INCLUDED
# define YY_YY_MYANALYZER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_INTEGER = 258,
    KW_SCALAR = 259,
    KW_STR = 260,
    KW_BOOLEAN = 261,
    KW_TRUE = 262,
    KW_FALSE = 263,
    KW_CONST = 264,
    KW_IF = 265,
    KW_ELSE = 266,
    KW_ENDIF = 267,
    KW_FOR = 268,
    KW_IN = 269,
    KW_ENDFOR = 270,
    KW_WHILE = 271,
    KW_ENDWHILE = 272,
    KW_BREAK = 273,
    KW_CONTINUE = 274,
    KW_NOT = 275,
    KW_AND = 276,
    KW_OR = 277,
    KW_DEF = 278,
    KW_MAIN = 279,
    KW_RETURN = 280,
    KW_ENDDEF = 281,
    KW_COMP = 282,
    KW_ENDCOMP = 283,
    IDENTIFIER = 284,
    CONST_INT = 285,
    CONST_SCALAR = 286,
    CONST_STRING = 287,
    PLUS_OP = 288,
    MINUS_OP = 289,
    MULTIPLY_OP = 290,
    DIVIDE_OP = 291,
    MODULO_OP = 292,
    POWER_OP = 293,
    EQ_SIGN = 294,
    NOTEQ_SIGN = 295,
    LT_SIGN = 296,
    LTEQ_SIGN = 297,
    GT_SIGN = 298,
    GTEQ_SIGN = 299,
    ASSIGN = 300,
    COMMA = 301,
    LBRACKET = 302,
    RBRACKET = 303,
    DECLARE = 304,
    ACCESS = 305,
    SEMICOLON = 306,
    LPARENTHESIS = 307,
    RPARENTHESIS = 308,
    HASHTAG = 309,
    LARROW = 310,
    PLUS_ASSIGN = 311,
    MINUS_ASSIGN = 312,
    MULTIPLY_ASSIGN = 313,
    DIVIDE_ASSIGN = 314,
    MODULO_ASSIGN = 315,
    END_OF_FILE = 316,
    NEGATIVE = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "myanalyzer.y"

	char* str;

#line 124 "myanalyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYANALYZER_TAB_H_INCLUDED  */
