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
#line 1 "pi_parser.y"

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>		
#include "cgen.h"

extern int yylex(void);
extern int line_num;

#line 81 "pi_parser.tab.c"

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
#ifndef YY_YY_PI_PARSER_TAB_H_INCLUDED
# define YY_YY_PI_PARSER_TAB_H_INCLUDED
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
    STRING = 258,
    IDENTIFIER = 259,
    REAL = 260,
    INTEGER = 261,
    KW_BEGIN = 262,
    KW_FUNC = 263,
    KW_INT = 264,
    KW_REAL = 265,
    KW_BOOL = 266,
    KW_TRUE = 267,
    KW_STRING = 268,
    KW_FALSE = 269,
    KW_VAR = 270,
    KW_CONST = 271,
    KW_IF = 272,
    KW_ELSE = 273,
    KW_WHILE = 274,
    KW_BREAK = 275,
    KW_CONTINUE = 276,
    KW_NIL = 277,
    KW_AND = 278,
    KW_OR = 279,
    KW_NOT = 280,
    KW_RETURN = 281,
    KW_FOR = 282,
    OP_POWER = 283,
    EQ = 284,
    GEQ = 285,
    UNEQ = 286,
    SEQ = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "pi_parser.y"

	char* crepr;

#line 170 "pi_parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PI_PARSER_TAB_H_INCLUDED  */



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
#define YYLAST   515

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

#define YYUNDEFTOK  2
#define YYMAXUTOK   287


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
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
      40,    41,    37,    35,    45,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      34,    46,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    93,   107,   121,   138,   139,   140,   144,
     145,   150,   154,   155,   156,   157,   161,   162,   166,   170,
     171,   175,   176,   177,   178,   182,   186,   190,   191,   195,
     200,   201,   208,   209,   210,   211,   215,   216,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   249,   250,
     251,   252,   253,   257,   258,   259,   263,   264,   265,   266,
     270,   271,   272,   273,   274,   279,   283,   284,   287,   288,
     289,   290,   291,   292,   293,   294,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   315,   316,   317,   318,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     335,   336,   337,   338,   339,   340,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   357,   358,   359,   360,
     361
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "IDENTIFIER", "REAL",
  "INTEGER", "KW_BEGIN", "KW_FUNC", "KW_INT", "KW_REAL", "KW_BOOL",
  "KW_TRUE", "KW_STRING", "KW_FALSE", "KW_VAR", "KW_CONST", "KW_IF",
  "KW_ELSE", "KW_WHILE", "KW_BREAK", "KW_CONTINUE", "KW_NIL", "KW_AND",
  "KW_OR", "KW_NOT", "KW_RETURN", "KW_FOR", "OP_POWER", "EQ", "GEQ",
  "UNEQ", "SEQ", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('",
  "')'", "'{'", "'}'", "';'", "','", "'='", "'['", "']'", "$accept",
  "program", "decl_list", "mult_var", "decl_var", "decl_var_list",
  "mult_const", "decl_const", "decl_const_list", "item", "decl_array",
  "decl_array_item", "mult_func", "decl_func", "decl_func_list",
  "data_type", "function_data_type", "logical_expr", "arithmetic_expr",
  "basic_expr", "expr", "assignement", "function_expr", "func_call",
  "func_body", "body", "complex_commands", "if_expr", "if_command",
  "else_command", "for_command", "while_command", YY_NULLPTR
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
     285,   286,   287,    62,    60,    43,    45,    42,    47,    37,
      40,    41,   123,   125,    59,    44,    61,    91,    93
};
# endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,   102,     6,    27,    38,    61,    63,  -203,    33,  -203,
      79,  -203,    51,    59,    14,   274,  -203,    72,    14,   384,
    -203,  -203,   153,    99,  -203,    63,  -203,   178,  -203,   121,
      89,   401,   130,  -203,  -203,  -203,  -203,   138,   106,   401,
      27,   117,   126,   215,   140,   111,    47,   155,  -203,  -203,
    -203,  -203,  -203,  -203,   164,   164,  -203,  -203,   150,    14,
    -203,  -203,  -203,  -203,  -203,  -203,   124,   162,   172,   175,
    -203,  -203,   111,   199,  -203,  -203,  -203,  -203,   183,   176,
     184,   417,   185,   111,    85,  -203,   189,  -203,  -203,  -203,
    -203,    71,   192,   202,   203,   207,   248,  -203,  -203,   209,
    -203,   213,  -203,  -203,  -203,   289,  -203,   294,   218,   308,
     363,   363,   169,   169,    11,  -203,   214,   363,  -203,   236,
     327,   238,   242,    46,   228,   356,   356,   451,   470,  -203,
    -203,   103,  -203,   387,   244,    71,  -203,  -203,   451,  -203,
     258,   259,   243,   263,   299,   451,  -203,  -203,   270,  -203,
    -203,  -203,   409,  -203,   425,   432,   356,   356,   356,   356,
     356,   356,   356,   356,   224,   224,   224,   224,   224,   224,
    -203,   363,  -203,  -203,   125,   329,    91,  -203,  -203,  -203,
    -203,  -203,   481,   463,  -203,  -203,  -203,  -203,  -203,  -203,
     224,   287,   386,   386,   287,   287,   287,   451,  -203,   273,
     276,  -203,   310,   310,   282,   285,  -203,   286,   301,    11,
     304,   432,   310,   310,   191,    15,  -203,  -203,  -203,  -203,
     220,  -203,  -203,   297,    11,  -203,  -203,   307,   309,   314,
    -203,  -203,  -203,   315,  -203,  -203,  -203,   321,   328,  -203,
     335,  -203,  -203,   342,   336,   298,  -203,  -203,   310,  -203,
    -203,  -203,   229,  -203,  -203,   345,   358,  -203,   364,   365,
     343,  -203,   368,  -203,  -203,   254,  -203,  -203,   378,   390,
    -203,   391,   400,  -203,  -203,  -203,  -203,   275,  -203,  -203,
    -203
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     7,    10,     6,    17,
       0,    28,     0,     0,    13,     0,    12,     0,     0,     0,
      19,     1,     0,     0,     9,     8,    16,     0,    27,     0,
       0,     0,     0,    32,    34,    35,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    58,
      60,    59,    64,    65,     0,     0,    22,    21,     0,    15,
      14,    11,    24,    23,    20,    18,     0,     0,     0,     0,
      36,    30,     0,     0,    78,    61,    62,    25,     0,     0,
       0,     0,     0,     0,     0,    78,     0,    78,    37,    78,
      31,     0,     0,     0,     0,     0,     0,    79,    80,     0,
      81,     0,    82,    83,    84,     0,    78,     0,     0,     0,
      74,     0,     0,     0,     0,     5,     0,     0,    85,     0,
       0,     0,     0,     0,    58,     0,     0,    70,    38,    49,
      71,     0,    50,     0,     0,    58,    96,    97,    99,    98,
       0,     0,     0,     0,     0,    68,    69,     3,     0,     4,
      29,    77,     0,    46,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,    66,    67,     0,     0,     0,    26,     2,    76,
      39,    57,    47,    48,    40,    42,    45,    44,    41,    43,
       0,    56,    51,    52,    53,    54,    55,    73,    72,     0,
       0,    86,   101,   102,     0,     0,    86,     0,     0,     0,
       0,     0,   103,   104,     0,     0,   106,   107,   130,   129,
       0,   127,   128,     0,     0,   108,   109,     0,     0,     0,
      87,    88,    89,     0,    92,    93,    94,     0,     0,    86,
       0,   111,   115,     0,     0,     0,    90,    91,   100,    95,
     113,   114,     0,   110,   126,     0,     0,    86,     0,     0,
       0,   105,     0,   124,   125,     0,   122,   123,     0,     0,
      86,     0,     0,   112,   121,   119,   120,     0,   117,   118,
     116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,  -203,   344,     0,  -203,  -203,     1,  -203,   112,
    -203,  -203,   382,    23,  -203,    -1,   -49,    30,  -124,   123,
     -34,  -101,  -203,   -81,  -203,   295,  -202,  -106,  -198,  -183,
    -193,  -167
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    97,    15,     8,    98,    19,    16,
      17,    99,    10,    11,    46,    70,    71,   138,   128,   129,
      57,   100,   131,   132,   108,    84,   214,   140,   102,   216,
     103,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,     9,   155,   101,   220,    63,    24,   141,     7,    26,
      14,   139,   139,   143,    38,   142,   234,   242,    41,    91,
     217,   235,   234,    82,   101,    24,   101,   235,   101,   225,
     226,    18,    92,    28,    90,   237,   238,   252,    21,   101,
     191,   192,   193,   194,   195,   196,    28,   236,     2,     3,
     124,    50,    51,   236,   234,   265,     1,   239,    96,   235,
      31,    32,    96,     2,     3,   261,   211,   234,   277,    22,
     210,   125,   235,   202,   207,   139,   130,   134,     2,   234,
      88,    54,    55,   146,   235,   236,   126,    27,    72,    91,
     151,    29,    73,   203,   208,   135,    50,    51,   236,    30,
       2,     3,    92,   136,    93,   137,    12,    43,   223,    13,
     236,   110,    94,   232,   240,    20,   125,   111,    39,   232,
      33,    34,    35,   245,    36,    45,    54,    55,    95,    91,
      47,   126,    96,   233,   241,   209,    58,   198,    96,   233,
     127,   133,    59,   258,   170,   199,   200,   145,   171,    60,
      61,   232,    64,   152,    56,   153,   154,    12,    69,   271,
      42,    65,    62,   259,   232,    78,    66,   201,    49,    50,
      51,   233,    96,   135,    50,    51,   232,    75,    76,   272,
      68,   136,    12,   137,   233,    44,   182,   183,   184,   185,
     186,   187,   188,   189,   125,    91,   233,    74,    77,    54,
      55,   197,    79,    83,    54,    55,     2,     3,    92,   126,
      93,   227,   228,    80,   230,   231,    96,    86,    94,    12,
     230,   231,    67,    81,    91,    85,    87,    89,   124,    50,
      51,   106,   112,    91,   229,     2,     3,    92,    96,    93,
     227,   228,   113,   114,     2,     3,    92,    94,    93,   227,
     228,   115,   230,   231,   116,   117,    94,   118,    91,    54,
      55,   122,   144,   243,   190,   230,   231,    96,   110,     2,
       3,    92,   262,    93,   227,   228,    96,   230,   231,    91,
     147,    94,   149,    33,    34,    35,   150,    36,   173,   111,
       2,     3,    92,    91,    93,   227,   228,   274,    91,   174,
     175,    96,    94,   177,     2,     3,    92,   176,    93,     2,
       3,    92,    91,    93,   178,   164,    94,   212,   280,    37,
     213,    94,    96,     2,     3,    92,   218,    93,   215,   219,
     221,    91,   119,    91,   123,    94,    96,   121,   244,   260,
      91,    96,     2,     3,    92,   222,    93,    91,   224,   204,
     205,   246,    25,   247,    94,    96,   255,   256,   248,   249,
     124,    50,    51,   268,   269,   250,    48,   124,    50,    51,
     148,   206,   251,     0,    96,    52,    96,    53,   257,   253,
     105,   125,   107,    96,   109,   270,   254,    23,   125,   263,
      96,    54,    55,    33,    34,    35,   126,    36,    54,    55,
       0,   120,   264,   126,    48,    49,    50,    51,   266,   267,
     156,   157,   273,    52,   164,    53,   158,   159,   160,   161,
     162,   163,   275,   167,   168,   169,    33,    34,    35,    40,
      36,   172,   156,   157,   276,   278,    54,    55,   158,   159,
     160,   161,   162,   163,   279,     0,     0,     0,   156,   157,
       0,     0,     0,   179,   158,   159,   160,   161,   162,   163,
     164,     0,     0,     0,     0,     0,   180,   165,   166,   167,
     168,   169,     0,   181,   156,   157,     0,     0,     0,     0,
     158,   159,   160,   161,   162,   163,   156,     0,     0,     0,
       0,     0,   158,   159,   160,   161,   162,   163,   164,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     158,   159,   160,   161,   162,   163
};

static const yytype_int16 yycheck[] =
{
       0,     0,   126,    84,   206,    39,     6,   113,     8,     8,
       4,   112,   113,   114,    15,     4,   214,   215,    19,     4,
     203,   214,   220,    72,   105,    25,   107,   220,   109,   212,
     213,     4,    17,    10,    83,    20,    21,   239,     0,   120,
     164,   165,   166,   167,   168,   169,    23,   214,    15,    16,
       4,     5,     6,   220,   252,   257,     8,    42,    47,   252,
      46,    47,    47,    15,    16,   248,   190,   265,   270,     8,
     176,    25,   265,   174,   175,   176,   110,   111,    15,   277,
      81,    35,    36,   117,   277,   252,    40,     8,    41,     4,
      44,    40,    45,   174,   175,     4,     5,     6,   265,    40,
      15,    16,    17,    12,    19,    14,     4,     8,   209,     7,
     277,    40,    27,   214,   215,     3,    25,    46,    46,   220,
       9,    10,    11,   224,    13,     4,    35,    36,    43,     4,
      41,    40,    47,   214,   215,    44,     6,   171,    47,   220,
     110,   111,     4,   244,    41,    20,    21,   117,    45,    37,
      44,   252,    40,   123,    31,   125,   126,     4,    47,   260,
       7,    44,    39,   244,   265,    41,    40,    42,     4,     5,
       6,   252,    47,     4,     5,     6,   277,    54,    55,   260,
      40,    12,     4,    14,   265,     7,   156,   157,   158,   159,
     160,   161,   162,   163,    25,     4,   277,    42,    48,    35,
      36,   171,    40,     4,    35,    36,    15,    16,    17,    40,
      19,    20,    21,    41,   214,   214,    47,    41,    27,     4,
     220,   220,     7,    48,     4,    42,    42,    42,     4,     5,
       6,    42,    40,     4,    43,    15,    16,    17,    47,    19,
      20,    21,    40,    40,    15,    16,    17,    27,    19,    20,
      21,    44,   252,   252,     6,    46,    27,    44,     4,    35,
      36,    43,    48,    43,    40,   265,   265,    47,    40,    15,
      16,    17,    43,    19,    20,    21,    47,   277,   277,     4,
      44,    27,    44,     9,    10,    11,    44,    13,    44,    46,
      15,    16,    17,     4,    19,    20,    21,    43,     4,    41,
      41,    47,    27,     4,    15,    16,    17,    44,    19,    15,
      16,    17,     4,    19,    44,    28,    27,    44,    43,    45,
      44,    27,    47,    15,    16,    17,    44,    19,    18,    44,
      44,     4,    43,     4,    26,    27,    47,    43,    41,    41,
       4,    47,    15,    16,    17,    44,    19,     4,    44,    20,
      21,    44,     8,    44,    27,    47,    20,    21,    44,    44,
       4,     5,     6,    20,    21,    44,     3,     4,     5,     6,
      43,    42,    44,    -1,    47,    12,    47,    14,    42,    44,
      85,    25,    87,    47,    89,    42,    44,     5,    25,    44,
      47,    35,    36,     9,    10,    11,    40,    13,    35,    36,
      -1,   106,    44,    40,     3,     4,     5,     6,    44,    44,
      23,    24,    44,    12,    28,    14,    29,    30,    31,    32,
      33,    34,    44,    37,    38,    39,     9,    10,    11,    45,
      13,    44,    23,    24,    44,    44,    35,    36,    29,    30,
      31,    32,    33,    34,    44,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    44,    29,    30,    31,    32,    33,    34,
      28,    -1,    -1,    -1,    -1,    -1,    41,    35,    36,    37,
      38,    39,    -1,    41,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    23,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    15,    16,    50,    51,    52,    53,    55,    56,
      61,    62,     4,     7,     4,    54,    58,    59,     4,    57,
      58,     0,     8,    61,    53,    52,    56,     8,    62,    40,
      40,    46,    47,     9,    10,    11,    13,    45,    64,    46,
      45,    64,     7,     8,     7,     4,    63,    41,     3,     4,
       5,     6,    12,    14,    35,    36,    68,    69,     6,     4,
      58,    44,    68,    69,    58,    44,    40,     7,    40,    47,
      64,    65,    41,    45,    42,    68,    68,    48,    41,    40,
      41,    48,    65,     4,    74,    42,    41,    42,    64,    42,
      65,     4,    17,    19,    27,    43,    47,    53,    56,    60,
      70,    72,    77,    79,    80,    74,    42,    74,    73,    74,
      40,    46,    40,    40,    40,    44,     6,    46,    44,    43,
      74,    43,    43,    26,     4,    25,    40,    66,    67,    68,
      69,    71,    72,    66,    69,     4,    12,    14,    66,    70,
      76,    76,     4,    70,    48,    66,    69,    44,    43,    44,
      44,    44,    66,    66,    66,    67,    23,    24,    29,    30,
      31,    32,    33,    34,    28,    35,    36,    37,    38,    39,
      41,    45,    44,    44,    41,    41,    44,     4,    44,    44,
      41,    41,    66,    66,    66,    66,    66,    66,    66,    66,
      40,    67,    67,    67,    67,    67,    67,    66,    69,    20,
      21,    42,    70,    72,    20,    21,    42,    70,    72,    44,
      76,    67,    44,    44,    75,    18,    78,    78,    44,    44,
      75,    44,    44,    70,    44,    78,    78,    20,    21,    43,
      53,    56,    70,    72,    77,    79,    80,    20,    21,    42,
      70,    72,    77,    43,    41,    70,    44,    44,    44,    44,
      44,    44,    75,    44,    44,    20,    21,    42,    70,    72,
      41,    78,    43,    44,    44,    75,    44,    44,    20,    21,
      42,    70,    72,    44,    43,    44,    44,    75,    44,    44,
      43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    51,    51,    51,    52,
      52,    53,    54,    54,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    58,    58,    59,    60,    61,    61,    62,
      63,    63,    64,    64,    64,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    68,    68,    69,    69,    69,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    72,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    10,     9,     9,     8,     1,     1,     2,     2,
       1,     4,     1,     1,     3,     3,     2,     1,     4,     1,
       3,     3,     3,     3,     3,     4,     4,     2,     1,    10,
       2,     4,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     2,     2,     1,     1,     1,     4,     4,     3,     3,
       1,     1,     3,     3,     0,     4,     4,     3,     0,     2,
       2,     2,     2,     2,     2,     3,     0,     2,     2,     2,
       3,     3,     2,     2,     2,     3,     1,     1,     1,     1,
       8,     5,     5,     6,     6,     9,     6,     6,     7,     7,
       3,     2,     5,     3,     3,     2,    11,    10,    10,    10,
      10,    10,     9,     9,     9,     9,     8,     6,     6,     6,
       6
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
#line 79 "pi_parser.y"
                                                                        { 

 /* We have a successful parse! 
    Check for any errors and generate output. 
  */
 
  if (yyerror_count == 0) {
    
    puts(c_prologue); 
    printf("%s\n%s\n\n ",(yyvsp[-9].crepr),(yyvsp[-8].crepr));
    printf("int main() { %s\n } \n", (yyvsp[-2].crepr));
  }
}
#line 1594 "pi_parser.tab.c"
    break;

  case 3:
#line 93 "pi_parser.y"
                                                     { 

 /* We have a successful parse! 
    Check for any errors and generate output. 
  */
 
  if (yyerror_count == 0) {
    
    puts(c_prologue); 
    printf("%s\n",(yyvsp[-8].crepr));
    printf("int main() { %s\n } \n", (yyvsp[-2].crepr));
  }
}
#line 1612 "pi_parser.tab.c"
    break;

  case 4:
#line 107 "pi_parser.y"
                                                     { 

 /* We have a successful parse! 
    Check for any errors and generate output. 
  */
 
  if (yyerror_count == 0) {
    
    puts(c_prologue); 
    printf("%s\n",(yyvsp[-8].crepr));
    printf("int main() { %s\n } \n", (yyvsp[-2].crepr));
  }
}
#line 1630 "pi_parser.tab.c"
    break;

  case 5:
#line 121 "pi_parser.y"
                                           { 

 /* We have a successful parse! 
    Check for any errors and generate output. 
  */
 
  if (yyerror_count == 0) {
    
    puts(c_prologue); 
    printf("\n");
    printf("int main() { %s\n } \n", (yyvsp[-2].crepr));
  }
}
#line 1648 "pi_parser.tab.c"
    break;

  case 6:
#line 138 "pi_parser.y"
           {(yyval.crepr) =template("%s\n", (yyvsp[0].crepr));}
#line 1654 "pi_parser.tab.c"
    break;

  case 7:
#line 139 "pi_parser.y"
          {(yyval.crepr) =template("%s\n", (yyvsp[0].crepr));}
#line 1660 "pi_parser.tab.c"
    break;

  case 8:
#line 140 "pi_parser.y"
                     {(yyval.crepr) = template("%s\n%s",(yyvsp[-1].crepr),(yyvsp[0].crepr));}
#line 1666 "pi_parser.tab.c"
    break;

  case 9:
#line 144 "pi_parser.y"
                   { (yyval.crepr) = template("%s\n%s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1672 "pi_parser.tab.c"
    break;

  case 10:
#line 145 "pi_parser.y"
           { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1678 "pi_parser.tab.c"
    break;

  case 11:
#line 150 "pi_parser.y"
                                    { (yyval.crepr) = template ("%s %s;",(yyvsp[-1].crepr),(yyvsp[-2].crepr));}
#line 1684 "pi_parser.tab.c"
    break;

  case 12:
#line 154 "pi_parser.y"
     {(yyval.crepr)=(yyvsp[0].crepr);}
#line 1690 "pi_parser.tab.c"
    break;

  case 13:
#line 155 "pi_parser.y"
           {(yyval.crepr)=(yyvsp[0].crepr);}
#line 1696 "pi_parser.tab.c"
    break;

  case 14:
#line 156 "pi_parser.y"
                         { (yyval.crepr) = template ("%s,%s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 1702 "pi_parser.tab.c"
    break;

  case 15:
#line 157 "pi_parser.y"
                               { (yyval.crepr) = template ("%s,%s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 1708 "pi_parser.tab.c"
    break;

  case 16:
#line 161 "pi_parser.y"
                       { (yyval.crepr) = template("%s\n%s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1714 "pi_parser.tab.c"
    break;

  case 17:
#line 162 "pi_parser.y"
             { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1720 "pi_parser.tab.c"
    break;

  case 18:
#line 166 "pi_parser.y"
                                        { (yyval.crepr) = template ("%s %s;",(yyvsp[-1].crepr),(yyvsp[-2].crepr));}
#line 1726 "pi_parser.tab.c"
    break;

  case 19:
#line 170 "pi_parser.y"
     {(yyval.crepr)=(yyvsp[0].crepr);}
#line 1732 "pi_parser.tab.c"
    break;

  case 20:
#line 171 "pi_parser.y"
                           { (yyval.crepr) = template ("%s,%s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 1738 "pi_parser.tab.c"
    break;

  case 21:
#line 175 "pi_parser.y"
                    { (yyval.crepr) = template ("%s =%s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 1744 "pi_parser.tab.c"
    break;

  case 22:
#line 176 "pi_parser.y"
                            { (yyval.crepr) = template ("%s =%s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 1750 "pi_parser.tab.c"
    break;

  case 23:
#line 177 "pi_parser.y"
                      { (yyval.crepr) = template ("%s =%s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 1756 "pi_parser.tab.c"
    break;

  case 24:
#line 178 "pi_parser.y"
                            { (yyval.crepr) = template ("%s =%s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 1762 "pi_parser.tab.c"
    break;

  case 25:
#line 182 "pi_parser.y"
                           {(yyval.crepr)= template("%s[%s]",(yyvsp[-3].crepr),(yyvsp[-1].crepr));}
#line 1768 "pi_parser.tab.c"
    break;

  case 26:
#line 186 "pi_parser.y"
                            {(yyval.crepr)=template("*%s",(yyvsp[0].crepr));}
#line 1774 "pi_parser.tab.c"
    break;

  case 27:
#line 190 "pi_parser.y"
                     { (yyval.crepr) = template("%s\n%s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1780 "pi_parser.tab.c"
    break;

  case 28:
#line 191 "pi_parser.y"
            { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1786 "pi_parser.tab.c"
    break;

  case 29:
#line 195 "pi_parser.y"
                                                                                    { (yyval.crepr) = template("%s %s(%s){%s\n}",(yyvsp[-4].crepr), (yyvsp[-8].crepr), (yyvsp[-6].crepr), (yyvsp[-2].crepr)); }
#line 1792 "pi_parser.tab.c"
    break;

  case 30:
#line 200 "pi_parser.y"
                              { (yyval.crepr) = template ("%s %s",(yyvsp[0].crepr),(yyvsp[-1].crepr));}
#line 1798 "pi_parser.tab.c"
    break;

  case 31:
#line 201 "pi_parser.y"
                                                   { (yyval.crepr) = template ("%s\n %s %s",(yyvsp[-3].crepr),(yyvsp[0].crepr),(yyvsp[-1].crepr));}
#line 1804 "pi_parser.tab.c"
    break;

  case 32:
#line 208 "pi_parser.y"
       { (yyval.crepr) = "int"; }
#line 1810 "pi_parser.tab.c"
    break;

  case 33:
#line 209 "pi_parser.y"
           { (yyval.crepr) = "char*"; }
#line 1816 "pi_parser.tab.c"
    break;

  case 34:
#line 210 "pi_parser.y"
         { (yyval.crepr) = "double"; }
#line 1822 "pi_parser.tab.c"
    break;

  case 35:
#line 211 "pi_parser.y"
         { (yyval.crepr) = "int"; }
#line 1828 "pi_parser.tab.c"
    break;

  case 36:
#line 215 "pi_parser.y"
          {(yyval.crepr) = (yyvsp[0].crepr);}
#line 1834 "pi_parser.tab.c"
    break;

  case 37:
#line 216 "pi_parser.y"
                   {(yyval.crepr) = (yyvsp[0].crepr);}
#line 1840 "pi_parser.tab.c"
    break;

  case 38:
#line 223 "pi_parser.y"
                {(yyval.crepr) = (yyvsp[0].crepr) ;}
#line 1846 "pi_parser.tab.c"
    break;

  case 39:
#line 224 "pi_parser.y"
                       { (yyval.crepr) = (yyvsp[-1].crepr);}
#line 1852 "pi_parser.tab.c"
    break;

  case 40:
#line 225 "pi_parser.y"
                               { (yyval.crepr) = template("%s == %s", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1858 "pi_parser.tab.c"
    break;

  case 41:
#line 226 "pi_parser.y"
                                { (yyval.crepr) = template("%s > %s", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1864 "pi_parser.tab.c"
    break;

  case 42:
#line 227 "pi_parser.y"
                                { (yyval.crepr) = template("%s >= %s", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1870 "pi_parser.tab.c"
    break;

  case 43:
#line 228 "pi_parser.y"
                                { (yyval.crepr) = template("%s < %s", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1876 "pi_parser.tab.c"
    break;

  case 44:
#line 229 "pi_parser.y"
                                { (yyval.crepr) = template("%s <= %s", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1882 "pi_parser.tab.c"
    break;

  case 45:
#line 230 "pi_parser.y"
                                 { (yyval.crepr) = template("%s != %s", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1888 "pi_parser.tab.c"
    break;

  case 46:
#line 231 "pi_parser.y"
                      { (yyval.crepr) = template("!%s", (yyvsp[0].crepr));}
#line 1894 "pi_parser.tab.c"
    break;

  case 47:
#line 232 "pi_parser.y"
                                   { (yyval.crepr) = template("%s && %s", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1900 "pi_parser.tab.c"
    break;

  case 48:
#line 233 "pi_parser.y"
                                  { (yyval.crepr) = template("%s || %s", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1906 "pi_parser.tab.c"
    break;

  case 49:
#line 237 "pi_parser.y"
           {(yyval.crepr) = (yyvsp[0].crepr) ;}
#line 1912 "pi_parser.tab.c"
    break;

  case 50:
#line 238 "pi_parser.y"
            { (yyval.crepr) = (yyvsp[0].crepr); }
#line 1918 "pi_parser.tab.c"
    break;

  case 51:
#line 239 "pi_parser.y"
                                      { (yyval.crepr) = template("%s + %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1924 "pi_parser.tab.c"
    break;

  case 52:
#line 240 "pi_parser.y"
                                      { (yyval.crepr) = template("%s - %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1930 "pi_parser.tab.c"
    break;

  case 53:
#line 241 "pi_parser.y"
                                      { (yyval.crepr) = template("%s * %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1936 "pi_parser.tab.c"
    break;

  case 54:
#line 242 "pi_parser.y"
                                      { (yyval.crepr) = template("%s / %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1942 "pi_parser.tab.c"
    break;

  case 55:
#line 243 "pi_parser.y"
                                      { (yyval.crepr) = template("%s %%  %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1948 "pi_parser.tab.c"
    break;

  case 56:
#line 244 "pi_parser.y"
                                           {(yyval.crepr) = template("pow(%s,%s)", (yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 1954 "pi_parser.tab.c"
    break;

  case 57:
#line 245 "pi_parser.y"
                           { (yyval.crepr) = template("(%s)",(yyvsp[-1].crepr)); }
#line 1960 "pi_parser.tab.c"
    break;

  case 58:
#line 249 "pi_parser.y"
           { (yyval.crepr) = (yyvsp[0].crepr); }
#line 1966 "pi_parser.tab.c"
    break;

  case 59:
#line 250 "pi_parser.y"
          { (yyval.crepr) = (yyvsp[0].crepr); }
#line 1972 "pi_parser.tab.c"
    break;

  case 60:
#line 251 "pi_parser.y"
       { (yyval.crepr) = (yyvsp[0].crepr);}
#line 1978 "pi_parser.tab.c"
    break;

  case 61:
#line 252 "pi_parser.y"
                 { (yyval.crepr) = template("+%s", (yyvsp[0].crepr)); }
#line 1984 "pi_parser.tab.c"
    break;

  case 62:
#line 253 "pi_parser.y"
                 { (yyval.crepr) = template("-%s", (yyvsp[0].crepr)); }
#line 1990 "pi_parser.tab.c"
    break;

  case 63:
#line 257 "pi_parser.y"
       { (yyval.crepr) = (yyvsp[0].crepr);}
#line 1996 "pi_parser.tab.c"
    break;

  case 64:
#line 258 "pi_parser.y"
          { (yyval.crepr) = "1";}
#line 2002 "pi_parser.tab.c"
    break;

  case 65:
#line 259 "pi_parser.y"
           { (yyval.crepr) = "0";}
#line 2008 "pi_parser.tab.c"
    break;

  case 66:
#line 263 "pi_parser.y"
                                {(yyval.crepr) = template("%s = %s",(yyvsp[-3].crepr), (yyvsp[-1].crepr));}
#line 2014 "pi_parser.tab.c"
    break;

  case 67:
#line 264 "pi_parser.y"
                          {(yyval.crepr) = template("%s = %s",(yyvsp[-3].crepr), (yyvsp[-1].crepr));}
#line 2020 "pi_parser.tab.c"
    break;

  case 68:
#line 265 "pi_parser.y"
                                    {(yyval.crepr) = template("%s = %s",(yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 2026 "pi_parser.tab.c"
    break;

  case 69:
#line 266 "pi_parser.y"
                            {(yyval.crepr) = template("%s = %s",(yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 2032 "pi_parser.tab.c"
    break;

  case 70:
#line 270 "pi_parser.y"
             { (yyval.crepr) = (yyvsp[0].crepr); }
#line 2038 "pi_parser.tab.c"
    break;

  case 71:
#line 271 "pi_parser.y"
       { (yyval.crepr) = (yyvsp[0].crepr); }
#line 2044 "pi_parser.tab.c"
    break;

  case 72:
#line 272 "pi_parser.y"
                         {(yyval.crepr) = template("%s, %s",(yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 2050 "pi_parser.tab.c"
    break;

  case 73:
#line 273 "pi_parser.y"
                                 {(yyval.crepr) = template("%s, %s",(yyvsp[-2].crepr), (yyvsp[0].crepr));}
#line 2056 "pi_parser.tab.c"
    break;

  case 74:
#line 274 "pi_parser.y"
         { (yyval.crepr) = ""; }
#line 2062 "pi_parser.tab.c"
    break;

  case 75:
#line 279 "pi_parser.y"
                                  { (yyval.crepr) = template("%s(%s)", (yyvsp[-3].crepr), (yyvsp[-1].crepr)); }
#line 2068 "pi_parser.tab.c"
    break;

  case 76:
#line 283 "pi_parser.y"
                                  {(yyval.crepr) = template("%s\nreturn(%s); ",(yyvsp[-3].crepr),(yyvsp[-1].crepr));}
#line 2074 "pi_parser.tab.c"
    break;

  case 77:
#line 284 "pi_parser.y"
                       {(yyval.crepr) = template("%s \nreturn; ",(yyvsp[-2].crepr));}
#line 2080 "pi_parser.tab.c"
    break;

  case 78:
#line 287 "pi_parser.y"
             { (yyval.crepr)=" ";}
#line 2086 "pi_parser.tab.c"
    break;

  case 79:
#line 288 "pi_parser.y"
                { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2092 "pi_parser.tab.c"
    break;

  case 80:
#line 289 "pi_parser.y"
                  { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2098 "pi_parser.tab.c"
    break;

  case 81:
#line 290 "pi_parser.y"
                    { (yyval.crepr) = template("%s \n %s;", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2104 "pi_parser.tab.c"
    break;

  case 82:
#line 291 "pi_parser.y"
                  { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2110 "pi_parser.tab.c"
    break;

  case 83:
#line 292 "pi_parser.y"
                   { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2116 "pi_parser.tab.c"
    break;

  case 84:
#line 293 "pi_parser.y"
                     { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2122 "pi_parser.tab.c"
    break;

  case 85:
#line 294 "pi_parser.y"
                     {(yyval.crepr)=template("%s \n %s;",(yyvsp[-2].crepr),(yyvsp[-1].crepr));}
#line 2128 "pi_parser.tab.c"
    break;

  case 86:
#line 298 "pi_parser.y"
       {(yyval.crepr) = " ";}
#line 2134 "pi_parser.tab.c"
    break;

  case 87:
#line 299 "pi_parser.y"
                            { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2140 "pi_parser.tab.c"
    break;

  case 88:
#line 300 "pi_parser.y"
                              { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2146 "pi_parser.tab.c"
    break;

  case 89:
#line 301 "pi_parser.y"
                                { (yyval.crepr) = template("%s \n %s;", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2152 "pi_parser.tab.c"
    break;

  case 90:
#line 302 "pi_parser.y"
                                {(yyval.crepr) = template("break; \n");}
#line 2158 "pi_parser.tab.c"
    break;

  case 91:
#line 303 "pi_parser.y"
                                   {(yyval.crepr) = template("continue; \n");}
#line 2164 "pi_parser.tab.c"
    break;

  case 92:
#line 304 "pi_parser.y"
                              { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2170 "pi_parser.tab.c"
    break;

  case 93:
#line 305 "pi_parser.y"
                               { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2176 "pi_parser.tab.c"
    break;

  case 94:
#line 306 "pi_parser.y"
                                 { (yyval.crepr) = template("%s \n %s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2182 "pi_parser.tab.c"
    break;

  case 95:
#line 307 "pi_parser.y"
                                 { (yyval.crepr) = template("%s \n %s", (yyvsp[-2].crepr), (yyvsp[-1].crepr)); }
#line 2188 "pi_parser.tab.c"
    break;

  case 96:
#line 315 "pi_parser.y"
        {(yyval.crepr) = "1";}
#line 2194 "pi_parser.tab.c"
    break;

  case 97:
#line 316 "pi_parser.y"
           { (yyval.crepr) = "0";}
#line 2200 "pi_parser.tab.c"
    break;

  case 98:
#line 317 "pi_parser.y"
              {(yyval.crepr) = (yyvsp[0].crepr);}
#line 2206 "pi_parser.tab.c"
    break;

  case 99:
#line 318 "pi_parser.y"
               {(yyval.crepr) = (yyvsp[0].crepr);}
#line 2212 "pi_parser.tab.c"
    break;

  case 100:
#line 322 "pi_parser.y"
                                                   {(yyval.crepr) = template("if(%s) {%s}",(yyvsp[-5].crepr),(yyvsp[-2].crepr));}
#line 2218 "pi_parser.tab.c"
    break;

  case 101:
#line 323 "pi_parser.y"
                                     {(yyval.crepr) = template("if(%s)\n %s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 2224 "pi_parser.tab.c"
    break;

  case 102:
#line 324 "pi_parser.y"
                                   {(yyval.crepr) = template("if(%s)\n %s",(yyvsp[-2].crepr),(yyvsp[0].crepr));}
#line 2230 "pi_parser.tab.c"
    break;

  case 103:
#line 325 "pi_parser.y"
                                     {(yyval.crepr) = template("if(%s)\n  break; \n",(yyvsp[-3].crepr));}
#line 2236 "pi_parser.tab.c"
    break;

  case 104:
#line 326 "pi_parser.y"
                                        {(yyval.crepr) = template("if(%s)\n  continue; \n",(yyvsp[-3].crepr));}
#line 2242 "pi_parser.tab.c"
    break;

  case 105:
#line 327 "pi_parser.y"
                                                                  {(yyval.crepr) = template("if(%s) {%s}",(yyvsp[-6].crepr),(yyvsp[-3].crepr));}
#line 2248 "pi_parser.tab.c"
    break;

  case 106:
#line 328 "pi_parser.y"
                                                  {(yyval.crepr) = template("if(%s)\n %s \n%s",(yyvsp[-3].crepr),(yyvsp[-1].crepr),(yyvsp[0].crepr));}
#line 2254 "pi_parser.tab.c"
    break;

  case 107:
#line 329 "pi_parser.y"
                                                {(yyval.crepr) = template("if(%s)\n %s\n%s",(yyvsp[-3].crepr),(yyvsp[-1].crepr),(yyvsp[0].crepr));}
#line 2260 "pi_parser.tab.c"
    break;

  case 108:
#line 330 "pi_parser.y"
                                                  {(yyval.crepr) = template("if(%s)\n  break; \n",(yyvsp[-4].crepr));}
#line 2266 "pi_parser.tab.c"
    break;

  case 109:
#line 331 "pi_parser.y"
                                                     {(yyval.crepr) = template("if(%s)\n  continue; \n",(yyvsp[-4].crepr));}
#line 2272 "pi_parser.tab.c"
    break;

  case 110:
#line 335 "pi_parser.y"
                        { (yyval.crepr) = template("else %s;\n",(yyvsp[-1].crepr));}
#line 2278 "pi_parser.tab.c"
    break;

  case 111:
#line 336 "pi_parser.y"
                    { (yyval.crepr) = template("else %s;\n",(yyvsp[0].crepr));}
#line 2284 "pi_parser.tab.c"
    break;

  case 112:
#line 337 "pi_parser.y"
                                      { (yyval.crepr) = template("else {%s}", (yyvsp[-2].crepr));}
#line 2290 "pi_parser.tab.c"
    break;

  case 113:
#line 338 "pi_parser.y"
                      { (yyval.crepr) = template("else \n break;\n");}
#line 2296 "pi_parser.tab.c"
    break;

  case 114:
#line 339 "pi_parser.y"
                         { (yyval.crepr) = template("else \n continue; \n");}
#line 2302 "pi_parser.tab.c"
    break;

  case 115:
#line 340 "pi_parser.y"
                     { (yyval.crepr) = template("else %s", (yyvsp[0].crepr));}
#line 2308 "pi_parser.tab.c"
    break;

  case 116:
#line 344 "pi_parser.y"
                                                                                {(yyval.crepr) = template("for(%s ;%s; %s)\n {%s}",(yyvsp[-8].crepr),(yyvsp[-6].crepr),(yyvsp[-4].crepr),(yyvsp[-1].crepr));}
#line 2314 "pi_parser.tab.c"
    break;

  case 117:
#line 345 "pi_parser.y"
                                                                        {(yyval.crepr) = template("for(%s ;%s; %s)\n %s",(yyvsp[-7].crepr),(yyvsp[-5].crepr),(yyvsp[-3].crepr),(yyvsp[-1].crepr));}
#line 2320 "pi_parser.tab.c"
    break;

  case 118:
#line 346 "pi_parser.y"
                                                                      {(yyval.crepr) = template("for(%s ;%s; %s)\n %s",(yyvsp[-7].crepr),(yyvsp[-5].crepr),(yyvsp[-3].crepr),(yyvsp[-1].crepr));}
#line 2326 "pi_parser.tab.c"
    break;

  case 119:
#line 347 "pi_parser.y"
                                                                     {(yyval.crepr) = template("for(%s ;%s;%s)\n break \n",(yyvsp[-7].crepr),(yyvsp[-5].crepr),(yyvsp[-3].crepr));}
#line 2332 "pi_parser.tab.c"
    break;

  case 120:
#line 348 "pi_parser.y"
                                                                        {(yyval.crepr) = template("for(%s ;%s; %s)\n continue; \n",(yyvsp[-7].crepr),(yyvsp[-5].crepr),(yyvsp[-3].crepr));}
#line 2338 "pi_parser.tab.c"
    break;

  case 121:
#line 349 "pi_parser.y"
                                                                        {(yyval.crepr) = template("for(%s ;; %s)\n {%s}",(yyvsp[-7].crepr),(yyvsp[-4].crepr),(yyvsp[-1].crepr));}
#line 2344 "pi_parser.tab.c"
    break;

  case 122:
#line 350 "pi_parser.y"
                                                                {(yyval.crepr) = template("for(%s ;; %s)\n %s",(yyvsp[-6].crepr),(yyvsp[-3].crepr),(yyvsp[-1].crepr));}
#line 2350 "pi_parser.tab.c"
    break;

  case 123:
#line 351 "pi_parser.y"
                                                              {(yyval.crepr) = template("for(%s ;; %s) \n %s",(yyvsp[-6].crepr),(yyvsp[-3].crepr),(yyvsp[-1].crepr));}
#line 2356 "pi_parser.tab.c"
    break;

  case 124:
#line 352 "pi_parser.y"
                                                             {(yyval.crepr) = template("for(%s ;;%s) \n break; \n",(yyvsp[-6].crepr),(yyvsp[-3].crepr));}
#line 2362 "pi_parser.tab.c"
    break;

  case 125:
#line 353 "pi_parser.y"
                                                                {(yyval.crepr) = template("for(%s ;; %s) \n continue; \n",(yyvsp[-6].crepr),(yyvsp[-3].crepr));}
#line 2368 "pi_parser.tab.c"
    break;

  case 126:
#line 357 "pi_parser.y"
                                                      {(yyval.crepr) = template("while(%s)\n {%s}",(yyvsp[-5].crepr),(yyvsp[-2].crepr));}
#line 2374 "pi_parser.tab.c"
    break;

  case 127:
#line 358 "pi_parser.y"
                                           {(yyval.crepr) = template("while(%s)\n %s",(yyvsp[-3].crepr),(yyvsp[-1].crepr));}
#line 2380 "pi_parser.tab.c"
    break;

  case 128:
#line 359 "pi_parser.y"
                                         {(yyval.crepr) = template("while(%s) \n%s",(yyvsp[-3].crepr),(yyvsp[-1].crepr));}
#line 2386 "pi_parser.tab.c"
    break;

  case 129:
#line 360 "pi_parser.y"
                                           {(yyval.crepr) = template("while(%s)\ncontinue; \n",(yyvsp[-3].crepr));}
#line 2392 "pi_parser.tab.c"
    break;

  case 130:
#line 361 "pi_parser.y"
                                        {(yyval.crepr) = template("while(%s)\n break; \n",(yyvsp[-3].crepr));}
#line 2398 "pi_parser.tab.c"
    break;


#line 2402 "pi_parser.tab.c"

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
#line 364 "pi_parser.y"

int main () {
  if ( yyparse() != 0 )
    printf("Rejected!\n");
}

