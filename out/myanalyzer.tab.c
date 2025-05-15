/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

extern int yylex();
extern int yyparse();
extern int line_number;
extern FILE *yyin;

extern char* find_macro(const char*);


int indent_level = 0;

void yyerror(const char *msg) {
    fprintf(stderr, "Syntax error in line %d: %s\n", line_number, msg);
    exit(1);
}

void debug_print(const char* str) {
    fprintf(stderr, "debug: %s\n", str);
}

char* add_indentation(const char* code) {
    char* result = malloc(strlen(code) + 1024);
    result[0] = '\0';
    const char* line = code;
    while (*line) {
        for (int i = 0; i < indent_level; ++i) strcat(result, "    ");
        const char* newline = strchr(line, '\n');
        if (newline) {
            strncat(result, line, newline - line + 1);
            line = newline + 1;
        } else {
            strcat(result, line);
            break;
        }
    }
    return result;
}

#line 114 "out/myanalyzer.tab.c"

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

#include "myanalyzer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONST_INT = 4,                  /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 5,                /* CONST_FLOAT  */
  YYSYMBOL_CONST_STRING = 6,               /* CONST_STRING  */
  YYSYMBOL_CONST_BOOL_TRUE = 7,            /* CONST_BOOL_TRUE  */
  YYSYMBOL_CONST_BOOL_FALSE = 8,           /* CONST_BOOL_FALSE  */
  YYSYMBOL_KW_INTEGER = 9,                 /* KW_INTEGER  */
  YYSYMBOL_KW_SCALAR = 10,                 /* KW_SCALAR  */
  YYSYMBOL_KW_STR = 11,                    /* KW_STR  */
  YYSYMBOL_KW_BOOL = 12,                   /* KW_BOOL  */
  YYSYMBOL_KW_CONST = 13,                  /* KW_CONST  */
  YYSYMBOL_KW_IF = 14,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 15,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 16,                  /* KW_ENDIF  */
  YYSYMBOL_KW_FOR = 17,                    /* KW_FOR  */
  YYSYMBOL_KW_IN = 18,                     /* KW_IN  */
  YYSYMBOL_KW_ENDFOR = 19,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_WHILE = 20,                  /* KW_WHILE  */
  YYSYMBOL_KW_ENDWHILE = 21,               /* KW_ENDWHILE  */
  YYSYMBOL_KW_BREAK = 22,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONTINUE = 23,               /* KW_CONTINUE  */
  YYSYMBOL_KW_NOT = 24,                    /* KW_NOT  */
  YYSYMBOL_KW_AND = 25,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 26,                     /* KW_OR  */
  YYSYMBOL_KW_DEF = 27,                    /* KW_DEF  */
  YYSYMBOL_KW_ENDDEF = 28,                 /* KW_ENDDEF  */
  YYSYMBOL_KW_MAIN = 29,                   /* KW_MAIN  */
  YYSYMBOL_KW_RETURN = 30,                 /* KW_RETURN  */
  YYSYMBOL_KW_COMP = 31,                   /* KW_COMP  */
  YYSYMBOL_KW_ENDCOMP = 32,                /* KW_ENDCOMP  */
  YYSYMBOL_KW_OF = 33,                     /* KW_OF  */
  YYSYMBOL_OP_ASSIGN = 34,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_PLUSEQ = 35,                 /* OP_PLUSEQ  */
  YYSYMBOL_OP_MINUSEQ = 36,                /* OP_MINUSEQ  */
  YYSYMBOL_OP_MULTEQ = 37,                 /* OP_MULTEQ  */
  YYSYMBOL_OP_DIVEQ = 38,                  /* OP_DIVEQ  */
  YYSYMBOL_OP_MODEQ = 39,                  /* OP_MODEQ  */
  YYSYMBOL_OP_DEFINE = 40,                 /* OP_DEFINE  */
  YYSYMBOL_OP_EQ = 41,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 42,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 43,                     /* OP_LT  */
  YYSYMBOL_OP_LEQ = 44,                    /* OP_LEQ  */
  YYSYMBOL_OP_GT = 45,                     /* OP_GT  */
  YYSYMBOL_OP_GEQ = 46,                    /* OP_GEQ  */
  YYSYMBOL_OP_PLUS = 47,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 48,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULT = 49,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 50,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 51,                    /* OP_MOD  */
  YYSYMBOL_OP_POW = 52,                    /* OP_POW  */
  YYSYMBOL_LPAREN = 53,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 54,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 55,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 56,                  /* RBRACKET  */
  YYSYMBOL_COLON = 57,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 58,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 59,                     /* COMMA  */
  YYSYMBOL_DOT = 60,                       /* DOT  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_program = 62,                   /* program  */
  YYSYMBOL_function_list = 63,             /* function_list  */
  YYSYMBOL_function = 64,                  /* function  */
  YYSYMBOL_main_function = 65,             /* main_function  */
  YYSYMBOL_stmt_list = 66,                 /* stmt_list  */
  YYSYMBOL_type = 67,                      /* type  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_expression = 69                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    78,    79,    83,    97,   112,   113,   121,
     122,   123,   124,   128,   137,   146,   155,   167,   181,   193,
     205,   208,   211,   217,   221,   229,   230,   231,   232,   233,
     234,   244,   252,   259,   267,   275,   283,   291,   299,   307
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONST_INT", "CONST_FLOAT", "CONST_STRING", "CONST_BOOL_TRUE",
  "CONST_BOOL_FALSE", "KW_INTEGER", "KW_SCALAR", "KW_STR", "KW_BOOL",
  "KW_CONST", "KW_IF", "KW_ELSE", "KW_ENDIF", "KW_FOR", "KW_IN",
  "KW_ENDFOR", "KW_WHILE", "KW_ENDWHILE", "KW_BREAK", "KW_CONTINUE",
  "KW_NOT", "KW_AND", "KW_OR", "KW_DEF", "KW_ENDDEF", "KW_MAIN",
  "KW_RETURN", "KW_COMP", "KW_ENDCOMP", "KW_OF", "OP_ASSIGN", "OP_PLUSEQ",
  "OP_MINUSEQ", "OP_MULTEQ", "OP_DIVEQ", "OP_MODEQ", "OP_DEFINE", "OP_EQ",
  "OP_NEQ", "OP_LT", "OP_LEQ", "OP_GT", "OP_GEQ", "OP_PLUS", "OP_MINUS",
  "OP_MULT", "OP_DIV", "OP_MOD", "OP_POW", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "COLON", "SEMICOLON", "COMMA", "DOT", "$accept", "program",
  "function_list", "function", "main_function", "stmt_list", "type",
  "stmt", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,     5,    -9,   -36,    21,   -36,   -36,   -28,   -26,   -35,
     -25,   -31,   -11,   -36,   -36,    50,    71,    29,   -10,    46,
      -2,    -6,    -4,     1,     4,   -36,   -36,     3,   129,   129,
      86,   129,    38,   129,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   129,   -36,    97,   -36,   107,   159,   -36,
     -36,   -36,   -36,     7,   173,    11,   187,   201,   129,   129,
     129,   129,   129,   129,   129,   129,   -36,   -36,    10,   -36,
      18,   129,    19,   -36,   -34,   -34,   -34,   -34,   -34,   -34,
      28,   -36,   -36,   -36,   126,   -36,    25,   129,     0,    24,
      31,   143,    32,   -36,   -36,    30,   -36,    89,   -36,    42,
     101,   -36,    44,   -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     0,     0,     0,
       0,     0,     0,     7,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     8,     0,     0,     0,
       0,     0,     0,     0,    20,    21,     5,    30,    25,    26,
      27,    28,    29,     0,    24,     0,     6,     0,     0,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    13,     0,    22,
       0,     0,     0,    39,    35,    36,    34,    38,    33,    37,
      31,    32,    14,     7,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     7,    16,     0,    19,     0,     7,     0,
       0,    17,     0,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,   -36,   -36,   -14,   -36,   -36,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     5,     6,    15,    53,    26,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      16,    47,    48,    17,    54,     3,    56,    37,    38,    39,
      40,    41,    42,    64,    18,    65,    57,    19,     4,    11,
      20,    92,    21,    22,     7,     9,    13,    10,    17,    12,
      24,    74,    75,    76,    77,    78,    79,    80,    81,    18,
      89,    90,    19,    31,    84,    20,    14,    21,    22,    32,
       8,    33,    34,    17,    35,    24,    55,    43,    25,    36,
      91,    46,    44,    28,    18,    69,    71,    19,    82,    86,
      20,    88,    21,    22,    17,    83,    85,    65,    23,    97,
      24,    93,    29,    25,   100,    18,    30,    98,    19,    94,
      96,    20,    17,    21,    22,    49,    50,    51,    52,    27,
     101,    24,   103,    18,    17,    99,    19,     0,    25,    20,
       0,    21,    22,     0,     0,    18,     0,     0,    19,    24,
     102,    20,     0,    21,    22,     0,     0,     0,     0,    25,
       0,    24,    37,    38,    39,    40,    41,    42,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    25,    58,    59,
      60,    61,    62,    63,    64,    66,    65,     0,     0,    25,
       0,     0,     0,     0,     0,    67,     0,    58,    59,    60,
      61,    62,    63,    64,     0,    65,     0,     0,     0,     0,
       0,     0,    43,    87,    58,    59,    60,    61,    62,    63,
      64,     0,    65,     0,     0,     0,     0,     0,     0,    95,
      58,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,     0,    68,    58,    59,    60,    61,    62,    63,
      64,     0,    65,     0,     0,     0,     0,    70,    58,    59,
      60,    61,    62,    63,    64,     0,    65,     0,     0,     0,
       0,    72,    58,    59,    60,    61,    62,    63,    64,     0,
      65,     0,     0,     0,     0,    73
};

static const yytype_int8 yycheck[] =
{
      14,    28,    29,     3,    31,     0,    33,     3,     4,     5,
       6,     7,     8,    47,    14,    49,    43,    17,    27,    54,
      20,    21,    22,    23,     3,    53,    57,    53,     3,    54,
      30,    58,    59,    60,    61,    62,    63,    64,    65,    14,
      15,    16,    17,    53,    71,    20,    57,    22,    23,     3,
      29,    53,    58,     3,    58,    30,    18,    53,    58,    58,
      87,    58,    58,    34,    14,    58,    55,    17,    58,    83,
      20,    85,    22,    23,     3,    57,    57,    49,    28,    93,
      30,    57,    53,    58,    98,    14,    57,    57,    17,    58,
      58,    20,     3,    22,    23,     9,    10,    11,    12,    28,
      58,    30,    58,    14,     3,    16,    17,    -1,    58,    20,
      -1,    22,    23,    -1,    -1,    14,    -1,    -1,    17,    30,
      19,    20,    -1,    22,    23,    -1,    -1,    -1,    -1,    58,
      -1,    30,     3,     4,     5,     6,     7,     8,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    58,    41,    42,
      43,    44,    45,    46,    47,    58,    49,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    57,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    54,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    54,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    54,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    62,    63,     0,    27,    64,    65,     3,    29,    53,
      53,    54,    54,    57,    57,    66,    66,     3,    14,    17,
      20,    22,    23,    28,    30,    58,    68,    28,    34,    53,
      57,    53,     3,    53,    58,    58,    58,     3,     4,     5,
       6,     7,     8,    53,    58,    69,    58,    69,    69,     9,
      10,    11,    12,    67,    69,    18,    69,    69,    41,    42,
      43,    44,    45,    46,    47,    49,    58,    58,    54,    58,
      54,    55,    54,    54,    69,    69,    69,    69,    69,    69,
      69,    69,    58,    57,    69,    57,    66,    57,    66,    15,
      16,    69,    21,    57,    58,    56,    58,    66,    57,    16,
      66,    58,    19,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     8,     8,     0,     2,     1,
       1,     1,     1,     4,     5,     3,     8,    11,    12,     8,
       2,     2,     4,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 3: /* function_list: %empty  */
#line 78 "myanalyzer.y"
                { (yyval.string) = strdup(""); }
#line 1262 "out/myanalyzer.tab.c"
    break;

  case 4: /* function_list: function_list function  */
#line 79 "myanalyzer.y"
                             { (yyval.string) = strdup(""); }
#line 1268 "out/myanalyzer.tab.c"
    break;

  case 5: /* function: KW_DEF IDENTIFIER LPAREN RPAREN COLON stmt_list KW_ENDDEF SEMICOLON  */
#line 84 "myanalyzer.y"
    {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-6].string)) + strlen(body) + 64);
        sprintf(code, "void %s() {\n%s}\n\n", (yyvsp[-6].string), body);
        free(body);
        printf("%s", code);
        (yyval.string) = strdup("");
    }
#line 1283 "out/myanalyzer.tab.c"
    break;

  case 6: /* main_function: KW_DEF KW_MAIN LPAREN RPAREN COLON stmt_list KW_ENDDEF SEMICOLON  */
#line 98 "myanalyzer.y"
    {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen(body) + 64);
        sprintf(code, "int main() {\n%s}\n", body);
        free(body);
        printf("%s", code);
        free(code);
        (yyval.string) = strdup("");    
    }
#line 1299 "out/myanalyzer.tab.c"
    break;

  case 7: /* stmt_list: %empty  */
#line 112 "myanalyzer.y"
                { (yyval.string) = strdup(""); }
#line 1305 "out/myanalyzer.tab.c"
    break;

  case 8: /* stmt_list: stmt_list stmt  */
#line 113 "myanalyzer.y"
                     {
        char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
        sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
        (yyval.string) = tmp;
    }
#line 1315 "out/myanalyzer.tab.c"
    break;

  case 9: /* type: KW_INTEGER  */
#line 121 "myanalyzer.y"
                { (yyval.string) = strdup("int"); }
#line 1321 "out/myanalyzer.tab.c"
    break;

  case 10: /* type: KW_SCALAR  */
#line 122 "myanalyzer.y"
                { (yyval.string) = strdup("float"); }
#line 1327 "out/myanalyzer.tab.c"
    break;

  case 11: /* type: KW_STR  */
#line 123 "myanalyzer.y"
                { (yyval.string) = strdup("char*"); }
#line 1333 "out/myanalyzer.tab.c"
    break;

  case 12: /* type: KW_BOOL  */
#line 124 "myanalyzer.y"
                { (yyval.string) = strdup("bool"); }
#line 1339 "out/myanalyzer.tab.c"
    break;

  case 13: /* stmt: IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 128 "myanalyzer.y"
                                              {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);

        fprintf(stderr, "Assigning: %s = %s\n", (yyvsp[-3].string), (yyvsp[-1].string));

        sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 1353 "out/myanalyzer.tab.c"
    break;

  case 14: /* stmt: IDENTIFIER LPAREN expression RPAREN SEMICOLON  */
#line 137 "myanalyzer.y"
                                                    {
        char* line = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + 16);

        fprintf(stderr, "Calling: %s(%s)\n", (yyvsp[-4].string), (yyvsp[-2].string));

        sprintf(line, "%s(%s);\n", (yyvsp[-4].string), (yyvsp[-2].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 1367 "out/myanalyzer.tab.c"
    break;

  case 15: /* stmt: KW_RETURN expression SEMICOLON  */
#line 146 "myanalyzer.y"
                                     {
        char* line = malloc(strlen((yyvsp[-1].string)) + 16);

        fprintf(stderr, "Returning: %s\n", (yyvsp[-1].string));

        sprintf(line, "return %s;\n", (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 1381 "out/myanalyzer.tab.c"
    break;

  case 16: /* stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON  */
#line 155 "myanalyzer.y"
                                                                        {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-5].string)) + strlen(body) + 64);

        fprintf(stderr, "If statement: %s\n", (yyvsp[-5].string));

        sprintf(code, "if (%s) {\n%s}\n", (yyvsp[-5].string), body);
        (yyval.string) = code;
        free(body);
    }
#line 1398 "out/myanalyzer.tab.c"
    break;

  case 17: /* stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ELSE COLON stmt_list KW_ENDIF SEMICOLON  */
#line 167 "myanalyzer.y"
                                                                                                {
        indent_level++;
        char* then_part = add_indentation((yyvsp[-5].string));
        char* else_part = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-8].string)) + strlen(then_part) + strlen(else_part) + 128);

        fprintf(stderr, "If-else statement: %s\n", (yyvsp[-8].string));

        sprintf(code, "if (%s) {\n%s} else {\n%s}\n", (yyvsp[-8].string), then_part, else_part);
        (yyval.string) = code;
        free(then_part);
        free(else_part);
    }
#line 1417 "out/myanalyzer.tab.c"
    break;

  case 18: /* stmt: KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON  */
#line 181 "myanalyzer.y"
                                                                                                                {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-10].string)) + strlen((yyvsp[-7].string)) + strlen((yyvsp[-5].string)) + strlen(body) + 128);

        fprintf(stderr, "For loop: %s in [%s:%s]\n", (yyvsp[-10].string), (yyvsp[-7].string), (yyvsp[-5].string));

        sprintf(code, "for (int %s = %s; %s <= %s; %s++) {\n%s}\n", (yyvsp[-10].string), (yyvsp[-7].string), (yyvsp[-10].string), (yyvsp[-5].string), (yyvsp[-10].string), body);
        (yyval.string) = code;
        free(body);
    }
#line 1434 "out/myanalyzer.tab.c"
    break;

  case 19: /* stmt: KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON  */
#line 193 "myanalyzer.y"
                                                                              {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-5].string)) + strlen(body) + 64);

        fprintf(stderr, "While loop: %s\n", (yyvsp[-5].string));

        sprintf(code, "while (%s) {\n%s}\n", (yyvsp[-5].string), body);
        (yyval.string) = code;
        free(body);
    }
#line 1451 "out/myanalyzer.tab.c"
    break;

  case 20: /* stmt: KW_BREAK SEMICOLON  */
#line 205 "myanalyzer.y"
                         {
        (yyval.string) = add_indentation("break;\n");
    }
#line 1459 "out/myanalyzer.tab.c"
    break;

  case 21: /* stmt: KW_CONTINUE SEMICOLON  */
#line 208 "myanalyzer.y"
                            {
        (yyval.string) = add_indentation("continue;\n");
    }
#line 1467 "out/myanalyzer.tab.c"
    break;

  case 22: /* stmt: IDENTIFIER COLON type SEMICOLON  */
#line 211 "myanalyzer.y"
                                      {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 1478 "out/myanalyzer.tab.c"
    break;

  case 23: /* stmt: SEMICOLON  */
#line 217 "myanalyzer.y"
                {
        fprintf(stderr, "STMT SEMICOLON\n");
        (yyval.string) = strdup(";");
    }
#line 1487 "out/myanalyzer.tab.c"
    break;

  case 24: /* stmt: KW_RETURN SEMICOLON  */
#line 222 "myanalyzer.y"
    {   
        fprintf(stderr, "STMT RET SEMICOLON\n");
        (yyval.string) = strdup("return;\n");
    }
#line 1496 "out/myanalyzer.tab.c"
    break;

  case 25: /* expression: CONST_INT  */
#line 229 "myanalyzer.y"
                           { fprintf(stderr, "CONST_INT = %s\n", (yyvsp[0].string)); (yyval.string) = strdup((yyvsp[0].string)); }
#line 1502 "out/myanalyzer.tab.c"
    break;

  case 26: /* expression: CONST_FLOAT  */
#line 230 "myanalyzer.y"
                           { fprintf(stderr, "CONST_FLOAT = %s\n", (yyvsp[0].string)); (yyval.string) = strdup((yyvsp[0].string));}
#line 1508 "out/myanalyzer.tab.c"
    break;

  case 27: /* expression: CONST_STRING  */
#line 231 "myanalyzer.y"
                           { fprintf(stderr, "CONST_STRING = %s\n", (yyvsp[0].string));(yyval.string) = strdup((yyvsp[0].string)); }
#line 1514 "out/myanalyzer.tab.c"
    break;

  case 28: /* expression: CONST_BOOL_TRUE  */
#line 232 "myanalyzer.y"
                           { fprintf(stderr, "CONST_BOOL_TRUE\n");(yyval.string) = strdup("1"); }
#line 1520 "out/myanalyzer.tab.c"
    break;

  case 29: /* expression: CONST_BOOL_FALSE  */
#line 233 "myanalyzer.y"
                           { fprintf(stderr, "CONST_BOOL_FALSE\n");(yyval.string) = strdup("0"); }
#line 1526 "out/myanalyzer.tab.c"
    break;

  case 30: /* expression: IDENTIFIER  */
#line 234 "myanalyzer.y"
                 {
        char* val = find_macro((yyvsp[0].string));
        if (val) {
            (yyval.string) = strdup(val);
        } else {
            (yyval.string) = strdup((yyvsp[0].string));
        }

        fprintf(stderr, "Identifier: %s\n", (yyvsp[0].string));
    }
#line 1541 "out/myanalyzer.tab.c"
    break;

  case 31: /* expression: expression OP_PLUS expression  */
#line 244 "myanalyzer.y"
                                    {
        char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);

        fprintf(stderr, "Adding: %s + %s\n", (yyvsp[-2].string), (yyvsp[0].string));

        sprintf(code, "%s + %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = code;
    }
#line 1554 "out/myanalyzer.tab.c"
    break;

  case 32: /* expression: expression OP_MULT expression  */
#line 252 "myanalyzer.y"
                                    {
        char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
        fprintf(stderr, "Multiplying: %s * %s\n", (yyvsp[-2].string), (yyvsp[0].string));
        sprintf(code, "%s * %s", (yyvsp[-2].string), (yyvsp[0].string));

        (yyval.string) = code;
    }
#line 1566 "out/myanalyzer.tab.c"
    break;

  case 33: /* expression: expression OP_GT expression  */
#line 259 "myanalyzer.y"
                                  {
        char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);

        fprintf(stderr, "Greater than: %s > %s\n", (yyvsp[-2].string), (yyvsp[0].string));

        sprintf(code, "%s > %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = code;
    }
#line 1579 "out/myanalyzer.tab.c"
    break;

  case 34: /* expression: expression OP_LT expression  */
#line 267 "myanalyzer.y"
                                  {
        char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
        
        fprintf(stderr, "Less than: %s < %s\n", (yyvsp[-2].string), (yyvsp[0].string));
        
        sprintf(code, "%s < %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = code;
    }
#line 1592 "out/myanalyzer.tab.c"
    break;

  case 35: /* expression: expression OP_EQ expression  */
#line 275 "myanalyzer.y"
                                  {
        char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
        
        fprintf(stderr, "Equal: %s == %s\n", (yyvsp[-2].string), (yyvsp[0].string));

        sprintf(code, "%s == %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = code;
    }
#line 1605 "out/myanalyzer.tab.c"
    break;

  case 36: /* expression: expression OP_NEQ expression  */
#line 283 "myanalyzer.y"
                                   {
        char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
        
        fprintf(stderr, "Not equal: %s != %s\n", (yyvsp[-2].string), (yyvsp[0].string));        

        sprintf(code, "%s != %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = code;
    }
#line 1618 "out/myanalyzer.tab.c"
    break;

  case 37: /* expression: expression OP_GEQ expression  */
#line 291 "myanalyzer.y"
                                   {
        char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
        
        fprintf(stderr, "Greater than or equal: %s >= %s\n", (yyvsp[-2].string), (yyvsp[0].string));

        sprintf(code, "%s >= %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = code;
    }
#line 1631 "out/myanalyzer.tab.c"
    break;

  case 38: /* expression: expression OP_LEQ expression  */
#line 299 "myanalyzer.y"
                                   {
        char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
        
        fprintf(stderr, "Less than or equal: %s <= %s\n", (yyvsp[-2].string), (yyvsp[0].string));
        
        sprintf(code, "%s <= %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = code;
    }
#line 1644 "out/myanalyzer.tab.c"
    break;

  case 39: /* expression: LPAREN expression RPAREN  */
#line 307 "myanalyzer.y"
                               {
        char* code = malloc(strlen((yyvsp[-1].string)) + 3);

        fprintf(stderr, "Parentheses: (%s)\n", (yyvsp[-1].string));

        sprintf(code, "(%s)", (yyvsp[-1].string));
        (yyval.string) = code;
    }
#line 1657 "out/myanalyzer.tab.c"
    break;


#line 1661 "out/myanalyzer.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 317 "myanalyzer.y"


int main() {
    return yyparse();
}
