/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "myanalyzer.y"

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "cgen.h"

#define COMP_SIZE 100
#define COMP_NAME_SIZE 40
#define COMP_FUNCTION_SIZE 1000
#define num_of_all_comp_functions 1000
#define num_of_all_comp_decl 1000

extern int yylex(void);
extern int line_num;
char comps[COMP_SIZE][COMP_NAME_SIZE];
char comp_functions[COMP_SIZE][COMP_FUNCTION_SIZE]; 
char functionName[num_of_all_comp_functions][40];
char DeclName[num_of_all_comp_decl][40];
char DeclType[num_of_all_comp_decl][40];
int decl=0;
char* comp_name;
int numberOfComps=0;
int numberOfCompFunctions=0;
int numberOfDeclaredComps=0;
int tempf, tempd=0;
int counter=0;
char* func_body;
char* conststructtor;



/*char* func_with_body;
char* comp_type;
int func_with_body_size;*/

#line 106 "myanalyzer.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 225 "myanalyzer.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYANALYZER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1621

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  404

#define YYUNDEFTOK  2
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   139,   139,   147,   157,   158,   162,   166,   167,   171,
     172,   173,   174,   175,   176,   177,   181,   182,   186,   187,
     191,   192,   196,   197,   198,   199,   200,   220,   221,   222,
     223,   224,   225,   226,   285,   287,   292,   293,   294,   295,
     300,   301,   302,   303,   305,   309,   311,   315,   316,   320,
     321,   325,   326,   330,   344,   360,   361,   362,   363,   364,
     365,   366,   370,   371,   375,   376,   380,   381,   385,   386,
     390,   391,   392,   396,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     462,   463,   464,   465,   466,   467,   472,   473,   474,   475,
     476,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   521,
     523,   528,   530,   535,   537,   542,   544,   549,   554,   559,
     560,   561,   565,   566,   567
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_INTEGER", "KW_SCALAR", "KW_STR",
  "KW_BOOLEAN", "KW_TRUE", "KW_FALSE", "KW_CONST", "KW_IF", "KW_ELSE",
  "KW_ENDIF", "KW_FOR", "KW_IN", "KW_ENDFOR", "KW_WHILE", "KW_ENDWHILE",
  "KW_BREAK", "KW_CONTINUE", "KW_NOT", "KW_AND", "KW_OR", "KW_DEF",
  "KW_MAIN", "KW_RETURN", "KW_ENDDEF", "KW_COMP", "KW_ENDCOMP",
  "IDENTIFIER", "CONST_INT", "CONST_SCALAR", "CONST_STRING", "PLUS_OP",
  "MINUS_OP", "MULTIPLY_OP", "DIVIDE_OP", "MODULO_OP", "POWER_OP",
  "EQ_SIGN", "NOTEQ_SIGN", "LT_SIGN", "LTEQ_SIGN", "GT_SIGN", "GTEQ_SIGN",
  "ASSIGN", "COMMA", "LBRACKET", "RBRACKET", "DECLARE", "ACCESS",
  "SEMICOLON", "LPARENTHESIS", "RPARENTHESIS", "HASHTAG", "LARROW",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN",
  "MODULO_ASSIGN", "END_OF_FILE", "NEGATIVE", "$accept", "begin",
  "programm", "main", "external_declaration", "body", "IDs", "ARRAYIDs",
  "POINTERIDs", "var_type", "var_declaration", "function_declaration",
  "comp", "comp_variable_declaration", "compIDs", "compARRAYIDs",
  "compPOINTERIDs", "comp_function_declaration", "compbody",
  "plus_arguments", "comp_function_arguments", "args",
  "function_decl_arguments", "function_arguments", "function_call",
  "operation", "ID_access", "equation", "comp_var_type", "loop_body",
  "comp_loop_body", "if_statement", "comp_if_statement", "for_loop",
  "comp_for_loop", "while_loop", "comp_while_loop", "loop", "comp_loop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

#define YYPACT_NINF (-340)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,    -9,   170,    -5,   -33,    22,    41,  -340,  -340,    64,
     182,   201,     6,    14,    -2,    89,   105,     3,    47,    52,
     237,  -340,  -340,  -340,    98,    23,   131,    23,   139,    23,
    -340,  -340,   703,   703,   703,   150,    82,    38,  -340,  -340,
     703,    50,  -340,  -340,  -340,   703,   703,   703,  -340,   703,
     183,  -340,  1277,   206,  -340,  -340,  -340,  -340,  -340,  -340,
    -340,   213,  -340,   227,  -340,  1085,  1109,  1133,   229,  -340,
     223,   241,   243,   272,  -340,   280,   212,    12,   261,   216,
     226,   234,   263,  1577,   703,     4,   703,   281,   281,  1301,
     725,   273,   703,   703,   703,   703,   703,   703,   703,   703,
     703,   703,   703,   703,   703,   703,  -340,     9,   703,   270,
      23,    23,    23,  -340,     7,    82,   145,   171,   271,   277,
     278,    23,  -340,   293,   300,  -340,   298,    69,   302,    69,
     307,    69,  -340,  1325,   279,   295,  -340,   -30,  1541,  -340,
    -340,   703,  1577,  1565,   203,   203,   281,   281,   281,   281,
     305,   305,   615,   615,   615,   615,   317,   330,  1349,  -340,
    -340,  -340,  -340,   154,  -340,    23,  -340,   703,   703,   703,
     341,   274,  -340,  -340,  -340,   347,  -340,  -340,  -340,  -340,
    -340,  -340,   348,  -340,   349,  -340,  -340,  -340,   703,  -340,
    1373,   703,  -340,  -340,   327,   352,   331,   303,   340,   546,
     343,   845,    72,   346,  -340,  -340,  -340,  -340,   493,   333,
    1157,  1181,  1205,   354,   351,   359,  -340,  1397,  -340,   361,
     367,  1541,  -340,    -7,   703,   387,   703,  -340,   869,  -340,
     237,  -340,  -340,   703,   703,   703,   703,   703,   703,  -340,
    -340,  -340,    69,    69,    69,    23,    63,   377,  -340,   703,
     369,  -340,   749,   368,   773,  -340,  1421,  1541,  1541,  1541,
    1541,  1541,  1541,   523,  -340,  -340,  -340,  -340,  -340,    23,
     375,  1445,  -340,   376,   703,   378,   247,  -340,   553,   381,
      23,  -340,   147,  1229,   207,   366,   397,   379,   639,  -340,
     692,   400,   388,   893,   393,  -340,  -340,  -340,  -340,  -340,
    -340,   581,   127,   703,   179,   703,   424,   703,  -340,   917,
     158,  -340,  -340,  -340,   611,   647,   394,   941,   396,   405,
     408,   409,   410,  -340,  1037,   417,   797,   422,   821,  -340,
     274,  -340,   701,   965,   762,   786,   810,    96,  -340,  -340,
    -340,   407,   703,  -340,   425,   703,   426,  1469,   834,   159,
     195,  1493,  -340,  1253,  -340,   249,  -340,   217,   428,   355,
     703,   403,   435,   195,   440,   439,   447,   448,   675,   453,
     989,   454,  -340,  1061,   456,  -340,   236,    96,  -340,  -340,
    -340,  -340,  1013,  -340,  -340,  -340,   442,   703,  -340,   457,
     380,  -340,  -340,  1517,  -340,  -340,   433,   462,   461,  -340,
    -340,   463,   465,  -340
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    16,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     5,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,    66,     0,    78,    79,
       0,   100,    75,    76,    80,     0,     0,     0,    20,     0,
       0,    77,     0,    74,    17,    22,    23,    24,    25,    26,
      27,     0,    28,     0,    29,     0,     0,     0,     0,    68,
       0,    67,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,    70,    84,    85,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
      47,     0,    33,     0,     0,    36,     0,     0,     0,     0,
       0,     0,    37,     0,   102,     0,   104,     0,    71,    82,
      81,     0,    98,    97,    89,    90,    86,    87,    88,    83,
      91,    92,    93,    94,    95,    96,   107,     0,     0,    21,
      30,    31,    32,     0,     9,     0,    69,     0,     0,     0,
      62,     0,    46,    38,    39,     0,   116,   117,   118,   119,
     120,    40,     0,    41,     0,    42,   101,   103,     0,    73,
       0,    70,   108,    19,     0,     0,     0,     0,     0,   100,
       0,     0,    74,     0,   149,   150,   151,    15,     0,     0,
       0,     0,     0,     0,     0,    63,    51,     0,    48,     0,
       0,    72,   106,     0,     0,     0,     0,    14,     0,     6,
       0,    10,    12,     0,     0,     0,     0,     0,     0,    11,
      35,     9,     0,     0,     0,     0,     0,     0,    49,     0,
       0,   109,     0,     0,     0,    13,     0,   110,   111,   112,
     113,   114,   115,     0,    43,    44,    45,    64,    55,     0,
       0,     0,    52,     0,     0,     0,   101,    34,     0,     0,
       0,    50,     9,     0,     9,     0,     0,     0,     0,    54,
     100,     0,     0,     0,     0,   152,   153,   154,    61,    55,
      65,     0,     0,     0,     0,     0,     0,     0,    60,     0,
     105,    56,    58,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,    59,
       0,    53,    14,     0,    10,    12,    11,     9,   139,   122,
     123,     0,     0,   147,     0,     0,     0,     0,    13,     0,
       9,     0,   130,     0,   130,   106,   140,     0,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   144,     0,     9,   141,   131,
     132,   137,     0,   133,   135,   134,     0,     0,   148,     0,
       0,   136,   130,     0,   143,   142,     0,     0,     0,   130,
     146,     0,     0,   145
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -340,  -340,  -340,   478,   508,  -105,    -1,   520,   527,   -16,
       1,  -340,  -340,   -35,   466,   469,   470,   452,   235,  -340,
    -340,  -340,  -340,   344,   459,   -15,  -159,  -157,  -119,  -230,
    -339,  -340,  -340,  -340,  -340,  -340,  -340,  -160,  -269
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,   301,     9,    10,    11,    60,
     200,    13,    77,   369,    79,    80,    81,    82,   278,   214,
     215,    70,    71,   137,    51,   370,    53,   371,   181,   302,
     359,   204,   295,   205,   296,   206,   297,   323,   372
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    12,    78,   207,   202,    52,   203,    12,   163,   298,
     183,    62,   185,    64,    20,   361,   188,    65,    66,    67,
       4,    72,    21,   189,    19,    83,    55,    56,    57,    58,
      87,    88,    89,   134,    90,    73,    76,    69,   156,   188,
     122,    74,   123,    32,    24,   298,   251,    72,   207,   202,
       1,   203,    59,   396,   304,    35,   164,    30,   135,   208,
     401,    73,   165,   157,     2,    31,    75,    74,     3,   133,
       4,   138,   176,   177,   178,   179,    76,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     1,    75,   158,   160,   161,   162,    84,   180,    36,
      85,    37,    86,   207,   202,   172,   203,   349,  -121,     3,
      24,     4,   268,    25,  -121,  -121,   166,   233,   269,   202,
     357,   294,   107,   264,   265,   266,   190,    54,   234,   235,
     236,   237,   238,   376,    33,    26,   263,   194,   319,   320,
     195,   207,   202,   196,   318,   321,   322,   390,   201,   209,
      34,    28,   210,   211,   212,   202,   217,   294,  -121,  -121,
      61,    38,    39,     1,   194,  -121,  -121,   195,    63,   194,
     196,   356,   195,   221,    40,   196,   138,   321,   322,   197,
     198,     3,   228,   199,    42,    43,    44,    45,    46,   194,
     167,   126,   195,   201,    17,   196,   325,   321,   322,    18,
     202,    47,   202,    68,   -47,   330,    49,   -47,    50,   252,
    -121,   254,    91,  -121,  -121,   256,   168,   128,   257,   258,
     259,   260,   261,   262,  -121,  -121,  -121,   194,    26,   267,
     195,    27,   362,   196,   271,   321,   322,   202,    96,    97,
      98,    99,   202,   292,    38,    39,   194,    28,   201,   195,
      29,   389,   196,   279,   321,   322,   107,    40,    24,   283,
     108,   121,   126,   293,   300,   127,    41,    42,    43,    44,
      45,    46,   128,   309,   109,   129,   114,    76,   113,   292,
     130,    38,    39,   131,    47,    48,   317,   115,   324,    49,
     326,    50,   328,   -18,    40,   -49,   -18,    75,   -49,   293,
     333,   119,   316,    41,    42,    43,    44,    45,    46,   120,
      38,    39,   125,    76,   132,   347,   169,   130,   159,    99,
     141,    47,   216,    40,   187,   171,    49,   351,    50,   170,
     353,    86,    41,    42,    43,    44,    45,    46,    94,    95,
      96,    97,    98,    99,   173,   373,   102,   103,   104,   105,
      47,   174,   175,   382,   227,    49,   182,    50,    76,   192,
      76,   184,    38,    39,    72,   285,   364,   365,   286,   191,
     213,   287,   393,   366,   367,    40,   218,   219,   220,   224,
     368,   225,   241,   226,   290,    42,    43,    44,    45,    46,
     194,   229,   395,   195,   231,    76,   196,   239,   321,   322,
      76,   253,    47,   245,   246,   247,   270,    49,   249,   291,
      38,    39,    72,   285,   250,   274,   286,   272,   305,   287,
     374,   366,   367,    40,   280,   282,   306,   284,   368,   310,
     299,   307,   290,    42,    43,    44,    45,    46,   327,   311,
      38,    39,    72,   285,   313,   334,   286,   336,   398,   287,
      47,   366,   367,    40,   337,    49,   350,   291,   368,   338,
     339,   340,   290,    42,    43,    44,    45,    46,   343,   345,
      38,    39,    72,   285,   352,   354,   286,   363,   402,   287,
      47,   366,   367,    40,    22,    49,   375,   291,   368,   377,
     378,   392,   290,    42,    43,    44,    45,    46,   379,   380,
      38,    39,     1,   194,   383,   385,   195,   388,   394,   196,
      47,   399,   400,    40,    23,    49,   403,   291,   197,   240,
       3,    15,   199,    42,    43,    44,    45,    46,    16,   124,
      38,    39,     1,   194,   314,   223,   195,     0,   116,   196,
      47,   117,   118,    40,   136,    49,     0,    50,   197,   277,
       3,     0,   199,    42,    43,    44,    45,    46,     0,     0,
      38,    39,    72,   285,     0,     0,   286,     0,     0,   287,
      47,     0,     0,    40,     0,    49,     0,    50,   288,   289,
       0,     0,   290,    42,    43,    44,    45,    46,    38,    39,
       1,   194,   -16,   230,   195,   -16,    85,   196,    86,     0,
      47,    40,     0,     0,     0,    49,   315,   291,     3,     0,
     199,    42,    43,    44,    45,    46,     0,     0,    38,    39,
      72,   285,     0,     0,   286,     0,     0,   287,    47,     0,
       0,    40,     0,    49,     0,    50,   288,   331,     0,     0,
     290,    42,    43,    44,    45,    46,    38,    39,    94,    95,
      96,    97,    98,    99,    38,    39,     0,     0,    47,    40,
       0,     0,     0,    49,     0,   291,     0,    40,    41,    42,
      43,    44,    45,    46,     0,     0,    41,    42,    43,    44,
      45,    46,    38,    39,     0,     0,    47,     0,     0,     0,
     308,    49,     0,    50,    47,    40,     0,     0,   332,    49,
       0,    50,     0,     0,    41,    42,    43,    44,    45,    46,
      38,    39,  -128,  -128,     0,     0,  -128,     0,  -128,  -128,
    -128,     0,    47,    40,     0,     0,   381,    49,     0,    50,
       0,     0,    41,    42,    43,    44,    45,    46,   -16,    84,
       0,   -16,    85,     0,    86,     0,    92,    93,     0,     0,
      47,     0,     0,     0,     0,    49,     0,    50,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      92,    93,     0,  -124,  -124,     0,     0,  -124,   140,  -124,
    -124,  -124,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    92,    93,     0,  -126,  -126,     0,
       0,  -126,   273,  -126,  -126,  -126,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    92,    93,
       0,  -125,  -125,     0,     0,  -125,   275,  -125,  -125,  -125,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    92,    93,     0,  -127,  -127,     0,     0,  -127,
     344,  -127,  -127,  -127,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    92,    93,     0,     0,
       0,     0,     0,     0,   346,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      92,    93,     0,     0,     0,     0,   232,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    92,    93,     0,     0,     0,     0,
     255,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    92,    93,
       0,     0,     0,     0,   312,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    92,    93,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    92,    93,     0,     0,
       0,     0,   335,     0,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      92,    93,     0,     0,     0,     0,   348,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    92,    93,     0,     0,     0,     0,
     384,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    92,    93,
       0,     0,     0,     0,   391,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    92,    93,     0,   341,   342,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    92,    93,     0,   386,
     387,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      92,    93,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    92,    93,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    92,    93,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    92,    93,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    92,    93,     0,     0,
     243,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      92,    93,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    92,    93,     0,     0,   303,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    92,    93,
       0,     0,   360,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    92,    93,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    92,    93,     0,   139,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      92,    93,     0,   186,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    92,    93,     0,   193,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    92,    93,
       0,   222,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    92,    93,     0,   248,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    92,    93,     0,   276,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      92,    93,     0,   281,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    92,    93,     0,   355,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    92,    93,
       0,   358,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    92,    93,     0,   397,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105
};

static const yytype_int16 yycheck[] =
{
       1,     0,    37,   163,   163,    20,   163,     6,   113,   278,
     129,    27,   131,    29,    47,   354,    46,    32,    33,    34,
      29,     9,     0,    53,    29,    40,     3,     4,     5,     6,
      45,    46,    47,    29,    49,    23,    37,    36,    29,    46,
      28,    29,    77,    45,    46,   314,    53,     9,   208,   208,
       9,   208,    29,   392,   284,    52,    49,    51,    54,   164,
     399,    23,    55,    54,    23,    51,    54,    29,    27,    84,
      29,    86,     3,     4,     5,     6,    77,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     9,    54,   108,   110,   111,   112,    47,    29,    52,
      50,    49,    52,   263,   263,   121,   263,   337,    12,    27,
      46,    29,    49,    49,    18,    19,   115,    45,    55,   278,
     350,   278,    50,   242,   243,   244,   141,    29,    56,    57,
      58,    59,    60,   363,    45,    46,   241,    10,    11,    12,
      13,   301,   301,    16,   301,    18,    19,   377,   163,   165,
      45,    46,   167,   168,   169,   314,   171,   314,    11,    12,
      29,     7,     8,     9,    10,    18,    19,    13,    29,    10,
      16,    12,    13,   188,    20,    16,   191,    18,    19,    25,
      26,    27,   197,    29,    30,    31,    32,    33,    34,    10,
      45,    46,    13,   208,    24,    16,    17,    18,    19,    29,
     359,    47,   361,    53,    46,    47,    52,    49,    54,   224,
      15,   226,    29,    18,    19,   230,    45,    46,   233,   234,
     235,   236,   237,   238,    17,    18,    19,    10,    46,   245,
      13,    49,    15,    16,   249,    18,    19,   396,    35,    36,
      37,    38,   401,   278,     7,     8,    10,    46,   263,    13,
      49,    15,    16,   269,    18,    19,    50,    20,    46,   274,
      47,    49,    46,   278,   280,    49,    29,    30,    31,    32,
      33,    34,    46,   288,    47,    49,    53,   278,    49,   314,
      46,     7,     8,    49,    47,    48,   301,    46,   303,    52,
     305,    54,   307,    46,    20,    46,    49,    54,    49,   314,
     315,    29,   301,    29,    30,    31,    32,    33,    34,    29,
       7,     8,    51,   314,    51,   330,    45,    46,    48,    38,
      47,    47,    48,    20,    29,    47,    52,   342,    54,    52,
     345,    52,    29,    30,    31,    32,    33,    34,    33,    34,
      35,    36,    37,    38,    51,   360,    41,    42,    43,    44,
      47,    51,    54,   368,    51,    52,    54,    54,   359,    29,
     361,    54,     7,     8,     9,    10,    11,    12,    13,    52,
      29,    16,   387,    18,    19,    20,    29,    29,    29,    52,
      25,    29,    49,    52,    29,    30,    31,    32,    33,    34,
      10,    51,    12,    13,    51,   396,    16,    51,    18,    19,
     401,    14,    47,    49,    53,    46,    29,    52,    47,    54,
       7,     8,     9,    10,    47,    47,    13,    48,    52,    16,
      17,    18,    19,    20,    49,    49,    29,    49,    25,    29,
      49,    52,    29,    30,    31,    32,    33,    34,    14,    51,
       7,     8,     9,    10,    51,    51,    13,    51,    15,    16,
      47,    18,    19,    20,    49,    52,    49,    54,    25,    51,
      51,    51,    29,    30,    31,    32,    33,    34,    51,    47,
       7,     8,     9,    10,    49,    49,    13,    49,    15,    16,
      47,    18,    19,    20,     6,    52,    51,    54,    25,    49,
      51,    49,    29,    30,    31,    32,    33,    34,    51,    51,
       7,     8,     9,    10,    51,    51,    13,    51,    51,    16,
      47,    49,    51,    20,     6,    52,    51,    54,    25,    26,
      27,     1,    29,    30,    31,    32,    33,    34,     1,    77,
       7,     8,     9,    10,   299,   191,    13,    -1,    72,    16,
      47,    72,    72,    20,    85,    52,    -1,    54,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
       7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,    16,
      47,    -1,    -1,    20,    -1,    52,    -1,    54,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,     7,     8,
       9,    10,    46,    47,    13,    49,    50,    16,    52,    -1,
      47,    20,    -1,    -1,    -1,    52,    25,    54,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,     7,     8,
       9,    10,    -1,    -1,    13,    -1,    -1,    16,    47,    -1,
      -1,    20,    -1,    52,    -1,    54,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,     7,     8,    33,    34,
      35,    36,    37,    38,     7,     8,    -1,    -1,    47,    20,
      -1,    -1,    -1,    52,    -1,    54,    -1,    20,    29,    30,
      31,    32,    33,    34,    -1,    -1,    29,    30,    31,    32,
      33,    34,     7,     8,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    54,    47,    20,    -1,    -1,    51,    52,
      -1,    54,    -1,    -1,    29,    30,    31,    32,    33,    34,
       7,     8,    11,    12,    -1,    -1,    15,    -1,    17,    18,
      19,    -1,    47,    20,    -1,    -1,    51,    52,    -1,    54,
      -1,    -1,    29,    30,    31,    32,    33,    34,    46,    47,
      -1,    49,    50,    -1,    52,    -1,    21,    22,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    -1,    54,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      21,    22,    -1,    11,    12,    -1,    -1,    15,    53,    17,
      18,    19,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    21,    22,    -1,    11,    12,    -1,
      -1,    15,    53,    17,    18,    19,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    21,    22,
      -1,    11,    12,    -1,    -1,    15,    53,    17,    18,    19,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    21,    22,    -1,    11,    12,    -1,    -1,    15,
      53,    17,    18,    19,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      21,    22,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    21,    22,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    21,    22,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    21,    22,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    21,    22,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      21,    22,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    21,    22,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    21,    22,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    21,    22,    -1,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    21,    22,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      21,    22,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    21,    22,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    21,    22,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    21,    22,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    21,    22,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      21,    22,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    21,    22,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    21,    22,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    21,    22,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    21,    22,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      21,    22,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    21,    22,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    21,    22,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    21,    22,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    21,    22,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      21,    22,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    21,    22,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    21,    22,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    21,    22,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    23,    27,    29,    64,    65,    66,    67,    69,
      70,    71,    73,    74,    69,    70,    71,    24,    29,    29,
      47,     0,    66,    67,    46,    49,    46,    49,    46,    49,
      51,    51,    45,    45,    45,    52,    52,    49,     7,     8,
      20,    29,    30,    31,    32,    33,    34,    47,    48,    52,
      54,    87,    88,    89,    29,     3,     4,     5,     6,    29,
      72,    29,    72,    29,    72,    88,    88,    88,    53,    73,
      84,    85,     9,    23,    29,    54,    69,    75,    76,    77,
      78,    79,    80,    88,    47,    50,    52,    88,    88,    88,
      88,    29,    21,    22,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    48,    50,    47,    47,
      49,    49,    49,    49,    53,    46,    77,    78,    79,    29,
      29,    49,    28,    76,    80,    51,    46,    49,    46,    49,
      46,    49,    51,    88,    29,    54,    87,    86,    88,    48,
      53,    47,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    29,    54,    88,    48,
      72,    72,    72,    68,    49,    55,    73,    45,    45,    45,
      52,    47,    72,    51,    51,    54,     3,     4,     5,     6,
      29,    91,    54,    91,    54,    91,    48,    29,    46,    53,
      88,    52,    29,    48,    10,    13,    16,    25,    26,    29,
      73,    88,    89,    90,    94,    96,    98,   100,    68,    72,
      88,    88,    88,    29,    82,    83,    48,    88,    29,    29,
      29,    88,    48,    86,    52,    29,    52,    51,    88,    51,
      47,    51,    51,    45,    56,    57,    58,    59,    60,    51,
      26,    49,    49,    49,    49,    49,    53,    46,    48,    47,
      47,    53,    88,    14,    88,    51,    88,    88,    88,    88,
      88,    88,    88,    68,    91,    91,    91,    72,    49,    55,
      29,    88,    48,    53,    47,    53,    48,    26,    81,    72,
      49,    48,    49,    88,    49,    10,    13,    16,    25,    26,
      29,    54,    76,    88,    90,    95,    97,    99,   101,    49,
      72,    68,    92,    49,    92,    52,    29,    52,    51,    88,
      29,    51,    51,    51,    81,    25,    73,    88,    90,    11,
      12,    18,    19,   100,    88,    17,    88,    14,    88,    51,
      47,    26,    51,    88,    51,    51,    51,    49,    51,    51,
      51,    48,    49,    51,    53,    47,    53,    88,    51,    92,
      49,    88,    49,    88,    49,    48,    12,    92,    48,    93,
      49,    93,    15,    49,    11,    12,    18,    19,    25,    76,
      88,    90,   101,    88,    17,    51,    92,    49,    51,    51,
      51,    51,    88,    51,    51,    51,    48,    49,    51,    15,
      92,    51,    49,    88,    51,    12,    93,    48,    15,    49,
      51,    93,    15,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    99,   100,
     100,   100,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     8,     2,     2,     0,
       3,     3,     3,     4,     3,     2,     1,     3,     4,     6,
       3,     5,     1,     1,     1,     1,     1,     3,     3,     3,
       6,     6,     6,     5,    10,     8,     2,     2,     3,     3,
       3,     3,     3,     6,     6,     6,     3,     2,     4,     5,
       7,     4,     6,    10,     8,     0,     3,     3,     3,     4,
       3,     2,     0,     1,     3,     5,     0,     1,     1,     3,
       0,     1,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     4,     3,     4,     3,     2,     5,     3,     4,     6,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     0,     3,     3,     3,     3,     3,     4,     3,     2,
       0,     3,     3,     3,     3,     3,     4,     3,     2,     8,
      10,     8,    10,    14,    12,    14,    12,     8,     8,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 140 "myanalyzer.y"
    {
        if (yyerror_count == 0) {
            puts(c_prologue);
            printf("%s\n%s",  (yyvsp[-1].str), (yyvsp[0].str)); 
        }
    }
#line 1918 "myanalyzer.tab.c"
    break;

  case 3:
#line 148 "myanalyzer.y"
    {
        if (yyerror_count == 0) {
            puts(c_prologue);
            printf("%s", (yyvsp[0].str)); 
        }
    }
#line 1929 "myanalyzer.tab.c"
    break;

  case 4:
#line 157 "myanalyzer.y"
                     { (yyval.str) = (yyvsp[0].str); }
#line 1935 "myanalyzer.tab.c"
    break;

  case 5:
#line 158 "myanalyzer.y"
                                { (yyval.str) = template("%s\n%s;", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1941 "myanalyzer.tab.c"
    break;

  case 6:
#line 162 "myanalyzer.y"
                                                                           {(yyval.str) = template("int main(){\n%s\n}", (yyvsp[-2].str)); }
#line 1947 "myanalyzer.tab.c"
    break;

  case 8:
#line 167 "myanalyzer.y"
                                 { (yyval.str) = (yyvsp[-1].str); }
#line 1953 "myanalyzer.tab.c"
    break;

  case 9:
#line 171 "myanalyzer.y"
          { (yyval.str) = ""; }
#line 1959 "myanalyzer.tab.c"
    break;

  case 10:
#line 172 "myanalyzer.y"
                                 { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 1965 "myanalyzer.tab.c"
    break;

  case 11:
#line 173 "myanalyzer.y"
                          { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 1971 "myanalyzer.tab.c"
    break;

  case 12:
#line 174 "myanalyzer.y"
                           { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 1977 "myanalyzer.tab.c"
    break;

  case 13:
#line 175 "myanalyzer.y"
                                     { (yyval.str) = template("%s\nreturn %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1983 "myanalyzer.tab.c"
    break;

  case 14:
#line 176 "myanalyzer.y"
                           { (yyval.str) = template("%s\nreturn;", (yyvsp[-2].str)); }
#line 1989 "myanalyzer.tab.c"
    break;

  case 15:
#line 177 "myanalyzer.y"
            { (yyval.str) = template("%s\n%s;", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1995 "myanalyzer.tab.c"
    break;

  case 16:
#line 181 "myanalyzer.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2001 "myanalyzer.tab.c"
    break;

  case 17:
#line 182 "myanalyzer.y"
                       { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2007 "myanalyzer.tab.c"
    break;

  case 18:
#line 186 "myanalyzer.y"
                                       { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2013 "myanalyzer.tab.c"
    break;

  case 19:
#line 187 "myanalyzer.y"
                                                        { (yyval.str) = template("%s, %s[%s]", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2019 "myanalyzer.tab.c"
    break;

  case 20:
#line 191 "myanalyzer.y"
                             { (yyval.str) = (yyvsp[-2].str); }
#line 2025 "myanalyzer.tab.c"
    break;

  case 21:
#line 192 "myanalyzer.y"
                                                { (yyval.str) = template("%s, %s", (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2031 "myanalyzer.tab.c"
    break;

  case 22:
#line 196 "myanalyzer.y"
           {conststructtor=""; (yyval.str) = template("int"); }
#line 2037 "myanalyzer.tab.c"
    break;

  case 23:
#line 197 "myanalyzer.y"
             {conststructtor="";  (yyval.str) = template("double"); }
#line 2043 "myanalyzer.tab.c"
    break;

  case 24:
#line 198 "myanalyzer.y"
             {conststructtor="";  (yyval.str) = template("char*"); }
#line 2049 "myanalyzer.tab.c"
    break;

  case 25:
#line 199 "myanalyzer.y"
             {conststructtor="";  (yyval.str) = template("int"); }
#line 2055 "myanalyzer.tab.c"
    break;

  case 26:
#line 200 "myanalyzer.y"
             {    
                int counter;
                for(counter=0;counter<numberOfComps;counter++){
                    if(strcmp((yyvsp[0].str), comps[counter])==0){
                        break;
                    }
                }
                if(counter==numberOfComps){
                    printf("ERROR: undeclared struct identifier in line %d", line_num);
                    decl=0;
                    return -1;
                }
                conststructtor=(char*)malloc(50);
                strcat(conststructtor, "= ctor_"); 
                strcat(conststructtor, comps[counter]);
                (yyval.str) = (yyvsp[0].str); 
            }
#line 2077 "myanalyzer.tab.c"
    break;

  case 27:
#line 220 "myanalyzer.y"
                     { (yyval.str) = template("%s %s%s", (yyvsp[0].str), (yyvsp[-2].str), conststructtor); }
#line 2083 "myanalyzer.tab.c"
    break;

  case 28:
#line 221 "myanalyzer.y"
                            { (yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2089 "myanalyzer.tab.c"
    break;

  case 29:
#line 222 "myanalyzer.y"
                              { (yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2095 "myanalyzer.tab.c"
    break;

  case 30:
#line 223 "myanalyzer.y"
                                                 { (yyval.str) = template("const %s %s=%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2101 "myanalyzer.tab.c"
    break;

  case 31:
#line 224 "myanalyzer.y"
                                                      { (yyval.str) = template("const %s %s=%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2107 "myanalyzer.tab.c"
    break;

  case 32:
#line 225 "myanalyzer.y"
                                                        { (yyval.str) = template("const %s* %s=%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2113 "myanalyzer.tab.c"
    break;

  case 33:
#line 226 "myanalyzer.y"
                                              { 
                                                numberOfComps++; 
                                                strcpy(comps[numberOfComps-1], (yyvsp[-3].str));
                                                char* fncts=(char*)malloc(0);
                                                counter=tempf;
                                                for(;counter<numberOfCompFunctions;counter++){
                                                    fncts = (char*)realloc(fncts, strlen(fncts)+COMP_FUNCTION_SIZE);
                                                    strcat(fncts, comp_functions[counter]);
                                                }
                                                fncts = (char*)realloc(fncts, strlen(fncts)+200);
                                                strcat(fncts, "const ");
                                                strcat(fncts, (yyvsp[-3].str));
                                                strcat(fncts, " ctor_");
                                                strcat(fncts, (yyvsp[-3].str));
                                                strcat(fncts, " = { ");
                                                int temp = counter;
                                                counter=tempf;
                                                counter=tempf;
                                                tempf=temp;
                                                if(counter<numberOfCompFunctions){
                                                    strcat(fncts, ".");
                                                    strcat(fncts, functionName[counter]);
                                                    strcat(fncts, "=");
                                                    strcat(fncts, functionName[counter]);
                                                    counter++;
                                                }
                                                else if(counter<numberOfDeclaredComps){
                                                    strcat(fncts, ".");
                                                    strcat(fncts, DeclName[counter]);
                                                    strcat(fncts, "=");
                                                    strcat(fncts, "ctor_");
                                                    strcat(fncts, DeclType[counter]);
                                                    counter++;
                                                }
                                                for(;counter<numberOfCompFunctions;counter++){
                                                    strcat(fncts, ", ");
                                                    strcat(fncts, ".");
                                                    strcat(fncts, functionName[counter]);
                                                    strcat(fncts, "=");
                                                    strcat(fncts, functionName[counter]);
                                                }
                                                counter=tempd;
                                                for(;counter<numberOfDeclaredComps;counter++){
                                                    strcat(fncts, ", ");
                                                    strcat(fncts, ".");
                                                    strcat(fncts, DeclName[counter]);
                                                    strcat(fncts, "=");
                                                    strcat(fncts, "ctor_");
                                                    strcat(fncts, DeclType[counter]);
                                                }
                                                tempd=counter;
                                                strcat(fncts, "};\n#undef SELF");
                                                numberOfComps++;
                                                strcpy(comps[numberOfComps-1], (yyvsp[-3].str));
                                      (yyval.str) =template("#define SELF struct %s *self\ntypedef struct %s {\n%s\n}%s;\n%s", (yyvsp[-3].str), (yyvsp[-3].str), (yyvsp[-1].str), (yyvsp[-3].str), fncts); }
#line 2173 "myanalyzer.tab.c"
    break;

  case 34:
#line 286 "myanalyzer.y"
                                                    { (yyval.str) = template("%s %s (%s) { %s }", (yyvsp[-3].str), (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-1].str)); }
#line 2179 "myanalyzer.tab.c"
    break;

  case 35:
#line 288 "myanalyzer.y"
                                                    { (yyval.str) = template("void %s (%s) { %s }", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2185 "myanalyzer.tab.c"
    break;

  case 36:
#line 292 "myanalyzer.y"
                                    { (yyval.str) = template("%s;", (yyvsp[-1].str)); }
#line 2191 "myanalyzer.tab.c"
    break;

  case 37:
#line 293 "myanalyzer.y"
                                      { (yyval.str) = template("%s;", (yyvsp[-1].str)); }
#line 2197 "myanalyzer.tab.c"
    break;

  case 38:
#line 294 "myanalyzer.y"
                                           { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2203 "myanalyzer.tab.c"
    break;

  case 39:
#line 295 "myanalyzer.y"
                                           { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2209 "myanalyzer.tab.c"
    break;

  case 40:
#line 300 "myanalyzer.y"
                              {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], (yyvsp[-2].str));} (yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2215 "myanalyzer.tab.c"
    break;

  case 41:
#line 301 "myanalyzer.y"
                                     {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], (yyvsp[-2].str));} (yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2221 "myanalyzer.tab.c"
    break;

  case 42:
#line 302 "myanalyzer.y"
                                       {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], (yyvsp[-2].str));} (yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2227 "myanalyzer.tab.c"
    break;

  case 43:
#line 303 "myanalyzer.y"
                                                          {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], (yyvsp[-4].str));}
                                                             (yyval.str) = template("const %s %s=%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2234 "myanalyzer.tab.c"
    break;

  case 44:
#line 305 "myanalyzer.y"
                                                               {if(decl){
                                                                strcpy(DeclName[numberOfDeclaredComps-1],(yyvsp[-4].str));
                                                                }
                                                                (yyval.str) = template("const %s %s=%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2243 "myanalyzer.tab.c"
    break;

  case 45:
#line 309 "myanalyzer.y"
                                                                 {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], (yyvsp[-4].str));}
                                                             (yyval.str) = template("const %s* %s=%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2250 "myanalyzer.tab.c"
    break;

  case 46:
#line 311 "myanalyzer.y"
                       { (yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2256 "myanalyzer.tab.c"
    break;

  case 47:
#line 315 "myanalyzer.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2262 "myanalyzer.tab.c"
    break;

  case 48:
#line 316 "myanalyzer.y"
                                   { (yyval.str) = template("%s, %s", (yyvsp[-3].str), (yyvsp[0].str)); }
#line 2268 "myanalyzer.tab.c"
    break;

  case 49:
#line 320 "myanalyzer.y"
                                               { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2274 "myanalyzer.tab.c"
    break;

  case 50:
#line 321 "myanalyzer.y"
                                                                    { (yyval.str) = template("%s, %s[%s]", (yyvsp[-6].str), (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2280 "myanalyzer.tab.c"
    break;

  case 51:
#line 325 "myanalyzer.y"
                                     { (yyval.str) = template("%s", (yyvsp[-2].str)); }
#line 2286 "myanalyzer.tab.c"
    break;

  case 52:
#line 326 "myanalyzer.y"
                                                            { (yyval.str) = template("%s, %s", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2292 "myanalyzer.tab.c"
    break;

  case 53:
#line 330 "myanalyzer.y"
                                                                                                     {   
                                                        numberOfCompFunctions++;
                                                        strcpy(comp_functions[numberOfCompFunctions-1], "");
                                                        strcat(comp_functions[numberOfCompFunctions-1], (yyvsp[-3].str));
                                                        strcat(comp_functions[numberOfCompFunctions-1], " ");
                                                        strcat(comp_functions[numberOfCompFunctions-1], (yyvsp[-8].str));
                                                        strcat(comp_functions[numberOfCompFunctions-1], " (SELF");
                                                        strcat(comp_functions[numberOfCompFunctions-1], (yyvsp[-6].str));
                                                        strcat(comp_functions[numberOfCompFunctions-1], ") {");
                                                        strcat(comp_functions[numberOfCompFunctions-1], (yyvsp[-1].str));
                                                        strcat(comp_functions[numberOfCompFunctions-1], "\n}\n");
                                                        strcpy(functionName[numberOfCompFunctions-1], (yyvsp[-8].str));
                                                        (yyval.str) = template("%s (*%s) (SELF%s)", (yyvsp[-3].str), (yyvsp[-8].str), (yyvsp[-6].str)); }
#line 2310 "myanalyzer.tab.c"
    break;

  case 54:
#line 344 "myanalyzer.y"
                                                                                       { 
                                                        numberOfCompFunctions++;
                                                        strcpy(comp_functions[numberOfCompFunctions-1], "");
                                                        strcat(comp_functions[numberOfCompFunctions-1], "void ");
                                                        strcat(comp_functions[numberOfCompFunctions-1], (yyvsp[-6].str));
                                                        strcat(comp_functions[numberOfCompFunctions-1], " (SELF");
                                                        strcat(comp_functions[numberOfCompFunctions-1], (yyvsp[-4].str));
                                                        strcat(comp_functions[numberOfCompFunctions-1], ") {");
                                                        strcat(comp_functions[numberOfCompFunctions-1], (yyvsp[-1].str));
                                                        strcat(comp_functions[numberOfCompFunctions-1], "\n}\n");
                                                        strcpy(functionName[numberOfCompFunctions-1], (yyvsp[-6].str));
                                                        (yyval.str) = template("void (*%s) (SELF%s)", (yyvsp[-6].str), (yyvsp[-4].str));}
#line 2327 "myanalyzer.tab.c"
    break;

  case 55:
#line 360 "myanalyzer.y"
          { (yyval.str) = ""; }
#line 2333 "myanalyzer.tab.c"
    break;

  case 56:
#line 361 "myanalyzer.y"
                                               { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2339 "myanalyzer.tab.c"
    break;

  case 57:
#line 362 "myanalyzer.y"
                              { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2345 "myanalyzer.tab.c"
    break;

  case 58:
#line 363 "myanalyzer.y"
                               { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2351 "myanalyzer.tab.c"
    break;

  case 59:
#line 364 "myanalyzer.y"
                                         { (yyval.str) = template("%s\nreturn %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2357 "myanalyzer.tab.c"
    break;

  case 60:
#line 365 "myanalyzer.y"
                               { (yyval.str) = template("%s\nreturn;", (yyvsp[-2].str)); }
#line 2363 "myanalyzer.tab.c"
    break;

  case 61:
#line 366 "myanalyzer.y"
                         { (yyval.str) = template("%s\n%s;", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2369 "myanalyzer.tab.c"
    break;

  case 62:
#line 370 "myanalyzer.y"
          { (yyval.str) = ""; }
#line 2375 "myanalyzer.tab.c"
    break;

  case 63:
#line 371 "myanalyzer.y"
                          { (yyval.str) = template(", %s", (yyvsp[0].str)); }
#line 2381 "myanalyzer.tab.c"
    break;

  case 64:
#line 375 "myanalyzer.y"
                             { (yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2387 "myanalyzer.tab.c"
    break;

  case 65:
#line 376 "myanalyzer.y"
                                                            { (yyval.str) = template("%s, %s %s", (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2393 "myanalyzer.tab.c"
    break;

  case 66:
#line 380 "myanalyzer.y"
          { (yyval.str) = ""; }
#line 2399 "myanalyzer.tab.c"
    break;

  case 67:
#line 381 "myanalyzer.y"
                          { (yyval.str) = template(", %s", (yyvsp[0].str)); }
#line 2405 "myanalyzer.tab.c"
    break;

  case 68:
#line 385 "myanalyzer.y"
                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2411 "myanalyzer.tab.c"
    break;

  case 69:
#line 386 "myanalyzer.y"
                                                { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2417 "myanalyzer.tab.c"
    break;

  case 70:
#line 390 "myanalyzer.y"
          { (yyval.str) = ""; }
#line 2423 "myanalyzer.tab.c"
    break;

  case 71:
#line 391 "myanalyzer.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2429 "myanalyzer.tab.c"
    break;

  case 72:
#line 392 "myanalyzer.y"
                                     { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2435 "myanalyzer.tab.c"
    break;

  case 73:
#line 396 "myanalyzer.y"
                                                        { (yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2441 "myanalyzer.tab.c"
    break;

  case 74:
#line 400 "myanalyzer.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 2447 "myanalyzer.tab.c"
    break;

  case 75:
#line 401 "myanalyzer.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 2453 "myanalyzer.tab.c"
    break;

  case 76:
#line 402 "myanalyzer.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 2459 "myanalyzer.tab.c"
    break;

  case 77:
#line 403 "myanalyzer.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2465 "myanalyzer.tab.c"
    break;

  case 78:
#line 404 "myanalyzer.y"
          { (yyval.str) = "1"; }
#line 2471 "myanalyzer.tab.c"
    break;

  case 79:
#line 405 "myanalyzer.y"
           { (yyval.str) = "0"; }
#line 2477 "myanalyzer.tab.c"
    break;

  case 80:
#line 406 "myanalyzer.y"
               {(yyval.str) = (yyvsp[0].str);}
#line 2483 "myanalyzer.tab.c"
    break;

  case 81:
#line 407 "myanalyzer.y"
                                                   { (yyval.str) = template("(%s)", (yyvsp[-1].str)); }
#line 2489 "myanalyzer.tab.c"
    break;

  case 82:
#line 408 "myanalyzer.y"
                                           { (yyval.str) = template("[%s]", (yyvsp[-1].str)); }
#line 2495 "myanalyzer.tab.c"
    break;

  case 83:
#line 409 "myanalyzer.y"
                               { (yyval.str) = template("pow(%s,%s)", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2501 "myanalyzer.tab.c"
    break;

  case 84:
#line 410 "myanalyzer.y"
                                    { (yyval.str) = template("+%s", (yyvsp[0].str)); }
#line 2507 "myanalyzer.tab.c"
    break;

  case 85:
#line 411 "myanalyzer.y"
                                    { (yyval.str) = template("-%s", (yyvsp[0].str)); }
#line 2513 "myanalyzer.tab.c"
    break;

  case 86:
#line 412 "myanalyzer.y"
                                  { (yyval.str) = template("%s*%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2519 "myanalyzer.tab.c"
    break;

  case 87:
#line 413 "myanalyzer.y"
                                { (yyval.str) = template("%s/%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2525 "myanalyzer.tab.c"
    break;

  case 88:
#line 414 "myanalyzer.y"
                                { (yyval.str) = template("%s%%%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2531 "myanalyzer.tab.c"
    break;

  case 89:
#line 415 "myanalyzer.y"
                              { (yyval.str) = template("%s+%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2537 "myanalyzer.tab.c"
    break;

  case 90:
#line 416 "myanalyzer.y"
                               { (yyval.str) = template("%s-%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2543 "myanalyzer.tab.c"
    break;

  case 91:
#line 417 "myanalyzer.y"
                              { (yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2549 "myanalyzer.tab.c"
    break;

  case 92:
#line 418 "myanalyzer.y"
                                 { (yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2555 "myanalyzer.tab.c"
    break;

  case 93:
#line 419 "myanalyzer.y"
                              { (yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2561 "myanalyzer.tab.c"
    break;

  case 94:
#line 420 "myanalyzer.y"
                                { (yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2567 "myanalyzer.tab.c"
    break;

  case 95:
#line 421 "myanalyzer.y"
                              { (yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2573 "myanalyzer.tab.c"
    break;

  case 96:
#line 422 "myanalyzer.y"
                                { (yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2579 "myanalyzer.tab.c"
    break;

  case 97:
#line 423 "myanalyzer.y"
                            { (yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2585 "myanalyzer.tab.c"
    break;

  case 98:
#line 424 "myanalyzer.y"
                            { (yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2591 "myanalyzer.tab.c"
    break;

  case 99:
#line 425 "myanalyzer.y"
                   { (yyval.str) = template("!%s", (yyvsp[0].str)); }
#line 2597 "myanalyzer.tab.c"
    break;

  case 100:
#line 429 "myanalyzer.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2603 "myanalyzer.tab.c"
    break;

  case 101:
#line 430 "myanalyzer.y"
                                         { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2609 "myanalyzer.tab.c"
    break;

  case 102:
#line 431 "myanalyzer.y"
                               { (yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2615 "myanalyzer.tab.c"
    break;

  case 103:
#line 432 "myanalyzer.y"
                                       { (yyval.str) = template("%s.%s", (yyvsp[-3].str), (yyvsp[0].str)); }
#line 2621 "myanalyzer.tab.c"
    break;

  case 104:
#line 433 "myanalyzer.y"
                                  { (yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2627 "myanalyzer.tab.c"
    break;

  case 105:
#line 434 "myanalyzer.y"
                     { (yyval.str) = template("self->%s", (yyvsp[0].str)); }
#line 2633 "myanalyzer.tab.c"
    break;

  case 106:
#line 435 "myanalyzer.y"
                                                 { (yyval.str) = template("self->%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2639 "myanalyzer.tab.c"
    break;

  case 107:
#line 436 "myanalyzer.y"
                              { (yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2645 "myanalyzer.tab.c"
    break;

  case 108:
#line 437 "myanalyzer.y"
                                      { (yyval.str) = template("%s.%s", (yyvsp[-3].str), (yyvsp[0].str)); }
#line 2651 "myanalyzer.tab.c"
    break;

  case 109:
#line 438 "myanalyzer.y"
                                                                           {
                                                                            char* com=(char*)malloc(2);
                                                                            if(strcmp((yyvsp[-1].str),"")!=0){
                                                                                strcpy(com, ",");
                                                                            }
                                                                            char* ID_access_func=(char*)malloc(300);
                                                                            char* next=(char*)malloc(300);
                                                                            strcpy(ID_access_func, (yyvsp[-5].str));
                                                                            strcpy(next, (yyvsp[-5].str));
                                                                            while(strstr(next,".")){
                                                                                strcpy(ID_access_func, next+1);
                                                                            
                                                                            }
                                                                            if(strstr(ID_access_func,"]")){
                                                                            (yyval.str) = template("%s.%s(&%s%s %s)", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), com, (yyvsp[-1].str));
                                                                            }
                                                                            else{
                                                                            (yyval.str) = template("%s.%s(%s%s %s)", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), com, (yyvsp[-1].str));
                                                                            }
                                                                            }
#line 2676 "myanalyzer.tab.c"
    break;

  case 110:
#line 462 "myanalyzer.y"
                           { (yyval.str) = template("%s=%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2682 "myanalyzer.tab.c"
    break;

  case 111:
#line 463 "myanalyzer.y"
                                  { (yyval.str) = template("%s+=%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2688 "myanalyzer.tab.c"
    break;

  case 112:
#line 464 "myanalyzer.y"
                                   { (yyval.str) = template("%s-=%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2694 "myanalyzer.tab.c"
    break;

  case 113:
#line 465 "myanalyzer.y"
                                      { (yyval.str) = template("%s*=%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2700 "myanalyzer.tab.c"
    break;

  case 114:
#line 466 "myanalyzer.y"
                                    { (yyval.str) = template("%s/=%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2706 "myanalyzer.tab.c"
    break;

  case 115:
#line 467 "myanalyzer.y"
                                    { (yyval.str) = template("%s%=%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2712 "myanalyzer.tab.c"
    break;

  case 116:
#line 472 "myanalyzer.y"
           {decl=0; (yyval.str) = template("int"); }
#line 2718 "myanalyzer.tab.c"
    break;

  case 117:
#line 473 "myanalyzer.y"
             {decl=0; (yyval.str) = template("double"); }
#line 2724 "myanalyzer.tab.c"
    break;

  case 118:
#line 474 "myanalyzer.y"
             {decl=0; (yyval.str) = template("char*"); }
#line 2730 "myanalyzer.tab.c"
    break;

  case 119:
#line 475 "myanalyzer.y"
             {decl=0; (yyval.str) = template("int"); }
#line 2736 "myanalyzer.tab.c"
    break;

  case 120:
#line 476 "myanalyzer.y"
             {    
                int counter;
                for(counter=0;counter<numberOfComps;counter++){
                    if(strcmp((yyvsp[0].str), comps[counter])==0){
                        counter=-1;
                        break;
                    }
                }
                if(counter!=-1){
                    printf("ERROR: undeclared struct identifier in line %d", line_num);
                    decl=0;
                    return -1;
                }
                numberOfDeclaredComps++;
                strcpy(DeclType[numberOfDeclaredComps-1], (yyvsp[0].str));
                decl=1;
                (yyval.str) = (yyvsp[0].str); 
            }
#line 2759 "myanalyzer.tab.c"
    break;

  case 121:
#line 497 "myanalyzer.y"
          { (yyval.str) = ""; }
#line 2765 "myanalyzer.tab.c"
    break;

  case 122:
#line 498 "myanalyzer.y"
                                    {(yyval.str) = template("break;\n");}
#line 2771 "myanalyzer.tab.c"
    break;

  case 123:
#line 499 "myanalyzer.y"
                                    {(yyval.str) = template("continue;\n");}
#line 2777 "myanalyzer.tab.c"
    break;

  case 124:
#line 500 "myanalyzer.y"
                                 { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2783 "myanalyzer.tab.c"
    break;

  case 125:
#line 501 "myanalyzer.y"
                          { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2789 "myanalyzer.tab.c"
    break;

  case 126:
#line 502 "myanalyzer.y"
                           { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2795 "myanalyzer.tab.c"
    break;

  case 127:
#line 503 "myanalyzer.y"
                                     { (yyval.str) = template("%s\nreturn %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2801 "myanalyzer.tab.c"
    break;

  case 128:
#line 504 "myanalyzer.y"
                           { (yyval.str) = template("%s\nreturn;", (yyvsp[-2].str)); }
#line 2807 "myanalyzer.tab.c"
    break;

  case 129:
#line 505 "myanalyzer.y"
                 { (yyval.str) = template("%s\n%s;", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2813 "myanalyzer.tab.c"
    break;

  case 130:
#line 509 "myanalyzer.y"
          { (yyval.str) = ""; }
#line 2819 "myanalyzer.tab.c"
    break;

  case 131:
#line 510 "myanalyzer.y"
                                                        {(yyval.str) = template("break;\n");}
#line 2825 "myanalyzer.tab.c"
    break;

  case 132:
#line 511 "myanalyzer.y"
                                                        {(yyval.str) = template("continue;\n");}
#line 2831 "myanalyzer.tab.c"
    break;

  case 133:
#line 512 "myanalyzer.y"
                                                        { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2837 "myanalyzer.tab.c"
    break;

  case 134:
#line 513 "myanalyzer.y"
                                                        { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2843 "myanalyzer.tab.c"
    break;

  case 135:
#line 514 "myanalyzer.y"
                                                        { (yyval.str) = template("%s\n%s;", (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2849 "myanalyzer.tab.c"
    break;

  case 136:
#line 515 "myanalyzer.y"
                                                        { (yyval.str) = template("%s\nreturn %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2855 "myanalyzer.tab.c"
    break;

  case 137:
#line 516 "myanalyzer.y"
                                                        { (yyval.str) = template("%s\nreturn;", (yyvsp[-2].str)); }
#line 2861 "myanalyzer.tab.c"
    break;

  case 138:
#line 517 "myanalyzer.y"
                                                        { (yyval.str) = template("%s\n%s;", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2867 "myanalyzer.tab.c"
    break;

  case 139:
#line 522 "myanalyzer.y"
                                    { (yyval.str) = template("if (%s){\n%s\n}", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2873 "myanalyzer.tab.c"
    break;

  case 140:
#line 524 "myanalyzer.y"
                                    { (yyval.str) = template("if (%s){\n%s\n} else {\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 2879 "myanalyzer.tab.c"
    break;

  case 141:
#line 529 "myanalyzer.y"
                                    { (yyval.str) = template("if (%s){\n%s\n}", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2885 "myanalyzer.tab.c"
    break;

  case 142:
#line 531 "myanalyzer.y"
                                    { (yyval.str) = template("if (%s){\n%s\n} else {\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 2891 "myanalyzer.tab.c"
    break;

  case 143:
#line 536 "myanalyzer.y"
                                    { (yyval.str) = template("for (int %s=%s;%s<%s;%s+=%s){\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2897 "myanalyzer.tab.c"
    break;

  case 144:
#line 538 "myanalyzer.y"
                                    { (yyval.str) = template("for (int %s=%s;%s<%s;%s++){\n%s\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str)); }
#line 2903 "myanalyzer.tab.c"
    break;

  case 145:
#line 543 "myanalyzer.y"
                                    { (yyval.str) = template("for (int %s=%s;%s<%s;%s+=%s){\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2909 "myanalyzer.tab.c"
    break;

  case 146:
#line 545 "myanalyzer.y"
                                    { (yyval.str) = template("for (int %s=%s;%s<%s;%s++){\n%s\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str)); }
#line 2915 "myanalyzer.tab.c"
    break;

  case 147:
#line 550 "myanalyzer.y"
                                    { (yyval.str) = template("while (%s){\n%s\n}", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2921 "myanalyzer.tab.c"
    break;

  case 148:
#line 555 "myanalyzer.y"
                                    { (yyval.str) = template("while (%s){\n%s\n}", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2927 "myanalyzer.tab.c"
    break;

  case 149:
#line 559 "myanalyzer.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 2933 "myanalyzer.tab.c"
    break;

  case 150:
#line 560 "myanalyzer.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2939 "myanalyzer.tab.c"
    break;

  case 151:
#line 561 "myanalyzer.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 2945 "myanalyzer.tab.c"
    break;

  case 152:
#line 565 "myanalyzer.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 2951 "myanalyzer.tab.c"
    break;

  case 153:
#line 566 "myanalyzer.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2957 "myanalyzer.tab.c"
    break;

  case 154:
#line 567 "myanalyzer.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 2963 "myanalyzer.tab.c"
    break;


#line 2967 "myanalyzer.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 570 "myanalyzer.y"




int main () {
    
    if ( yyparse() != 0 )
        printf("Rejected!\n");
        
}
