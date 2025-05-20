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
	#include "cgen.h"
	#include "lambdalib.h"

	extern int yylex();
	extern int yyparse();
	extern int line_number;
	extern FILE *yyin;

	extern char* find_macro(const char*);

	int indent_level = 0;
	int line_num = 1;

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
		strcat(result, line);
		return result;
	}

#line 108 "out/myanalyzer.tab.c"

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
  YYSYMBOL_KW_DEFMACRO = 34,               /* KW_DEFMACRO  */
  YYSYMBOL_OP_ASSIGN = 35,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_PLUSEQ = 36,                 /* OP_PLUSEQ  */
  YYSYMBOL_OP_MINUSEQ = 37,                /* OP_MINUSEQ  */
  YYSYMBOL_OP_MULTEQ = 38,                 /* OP_MULTEQ  */
  YYSYMBOL_OP_DIVEQ = 39,                  /* OP_DIVEQ  */
  YYSYMBOL_OP_MODEQ = 40,                  /* OP_MODEQ  */
  YYSYMBOL_OP_DEFINE = 41,                 /* OP_DEFINE  */
  YYSYMBOL_OP_POW = 42,                    /* OP_POW  */
  YYSYMBOL_OP_EQ = 43,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 44,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 45,                     /* OP_LT  */
  YYSYMBOL_OP_LEQ = 46,                    /* OP_LEQ  */
  YYSYMBOL_OP_GT = 47,                     /* OP_GT  */
  YYSYMBOL_OP_GEQ = 48,                    /* OP_GEQ  */
  YYSYMBOL_OP_PLUS = 49,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 50,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULT = 51,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 52,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 53,                    /* OP_MOD  */
  YYSYMBOL_LPAREN = 54,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 55,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 56,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 57,                  /* RBRACKET  */
  YYSYMBOL_COLON = 58,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 59,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 60,                     /* COMMA  */
  YYSYMBOL_DOT = 61,                       /* DOT  */
  YYSYMBOL_OP_ARROW = 62,                  /* OP_ARROW  */
  YYSYMBOL_HASH = 63,                      /* HASH  */
  YYSYMBOL_UMINUS = 64,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_macro_def_list = 67,            /* macro_def_list  */
  YYSYMBOL_macro_def = 68,                 /* macro_def  */
  YYSYMBOL_top_level_list = 69,            /* top_level_list  */
  YYSYMBOL_top_level = 70,                 /* top_level  */
  YYSYMBOL_var_declaration = 71,           /* var_declaration  */
  YYSYMBOL_const_declaration = 72,         /* const_declaration  */
  YYSYMBOL_function = 73,                  /* function  */
  YYSYMBOL_param_list = 74,                /* param_list  */
  YYSYMBOL_param_decl_list = 75,           /* param_decl_list  */
  YYSYMBOL_main_function = 76,             /* main_function  */
  YYSYMBOL_stmt_list = 77,                 /* stmt_list  */
  YYSYMBOL_type = 78,                      /* type  */
  YYSYMBOL_stmt = 79,                      /* stmt  */
  YYSYMBOL_component = 80,                 /* component  */
  YYSYMBOL_component_body = 81,            /* component_body  */
  YYSYMBOL_component_member = 82,          /* component_member  */
  YYSYMBOL_hash_ident_list = 83,           /* hash_ident_list  */
  YYSYMBOL_ident_list = 84,                /* ident_list  */
  YYSYMBOL_arg_list = 85,                  /* arg_list  */
  YYSYMBOL_expression = 86,                /* expression  */
  YYSYMBOL_primary_expression = 87,        /* primary_expression  */
  YYSYMBOL_block = 88,                     /* block  */
  YYSYMBOL_decl_list = 89                  /* decl_list  */
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
#define YYLAST   1511

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  304

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    99,   100,   107,   119,   120,   130,   133,
     136,   139,   142,   149,   158,   169,   183,   195,   210,   211,
     215,   220,   229,   242,   243,   251,   252,   253,   254,   255,
     259,   267,   273,   281,   289,   297,   308,   321,   332,   343,
     345,   347,   350,   353,   363,   375,   386,   394,   402,   410,
     418,   426,   431,   436,   441,   446,   451,   456,   461,   466,
     471,   476,   481,   488,   499,   500,   511,   518,   526,   531,
     535,   539,   548,   550,   558,   559,   560,   570,   571,   578,
     582,   587,   591,   595,   599,   606,   613,   620,   627,   634,
     641,   645,   649,   653,   657,   664,   671,   679,   683,   688,
     693,   699,   704,   713,   717,   720,   724,   728,   732,   736,
     740,   746,   751,   756,   765,   774,   775
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
  "KW_RETURN", "KW_COMP", "KW_ENDCOMP", "KW_OF", "KW_DEFMACRO",
  "OP_ASSIGN", "OP_PLUSEQ", "OP_MINUSEQ", "OP_MULTEQ", "OP_DIVEQ",
  "OP_MODEQ", "OP_DEFINE", "OP_POW", "OP_EQ", "OP_NEQ", "OP_LT", "OP_LEQ",
  "OP_GT", "OP_GEQ", "OP_PLUS", "OP_MINUS", "OP_MULT", "OP_DIV", "OP_MOD",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "COLON", "SEMICOLON",
  "COMMA", "DOT", "OP_ARROW", "HASH", "UMINUS", "$accept", "program",
  "macro_def_list", "macro_def", "top_level_list", "top_level",
  "var_declaration", "const_declaration", "function", "param_list",
  "param_decl_list", "main_function", "stmt_list", "type", "stmt",
  "component", "component_body", "component_member", "hash_ident_list",
  "ident_list", "arg_list", "expression", "primary_expression", "block",
  "decl_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-221)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-115)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -221,     4,   -28,  -221,    11,  -221,    -2,    10,  -221,    13,
       5,    23,  -221,  -221,  -221,  -221,  -221,  -221,    73,  -221,
      20,     2,     7,     0,    61,    87,    66,   496,    77,    26,
    -221,    43,  -221,  -221,  -221,  -221,  -221,    24,  -221,    56,
    -221,  -221,  -221,  -221,  -221,   496,   496,   496,    99,   592,
     -51,    60,    65,    72,    68,     1,    79,  -221,   289,  1450,
    -221,   626,  -221,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   422,   496,    87,
     120,   496,   132,    87,   -35,   151,  -221,   154,   101,  -221,
     158,  -221,  -221,   122,    87,  -221,   -48,  1400,  -221,  1450,
    1430,    28,    63,    63,    63,    63,    63,    63,   186,   186,
      28,    28,    28,  -221,   -38,   658,   103,  -221,   691,   109,
    -221,  -221,    87,   112,   155,   181,  -221,  -221,   187,    87,
     129,   137,  -221,   496,  -221,  -221,  -221,  -221,   428,   166,
     147,    87,   148,  -221,   196,   138,   150,   203,  -221,  1400,
    -221,    48,   152,  -221,  -221,  -221,   153,   136,   160,   214,
     167,   163,   164,   434,  -221,   222,  -221,   526,   169,  -221,
    -221,  -221,  -221,   205,  -221,   496,   496,   496,   496,   496,
     496,   175,   456,   496,   216,   496,  -221,  -221,  -221,   724,
      31,   496,   496,   496,   496,   496,   496,  -221,    87,   176,
     756,   788,   820,   852,   884,   916,   496,   182,    49,   948,
     188,   980,  -221,   496,   496,   496,   240,  1012,  1044,  1076,
    1108,  1140,  1172,   189,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,   488,  -221,   192,   194,   496,   195,  1204,  1236,  1268,
     191,  -221,  -221,  -221,  -221,  -221,  -221,  -221,   251,  -221,
    -221,  1300,  -221,  -221,  -221,  -221,   462,   198,    71,   496,
     257,   207,    67,   135,   199,   208,   558,   209,  -221,   210,
       3,   252,  1334,  -221,  -221,   215,   496,  -221,  -221,   269,
     217,   318,  -221,  1367,   243,    87,   223,   356,   225,   280,
     226,  -221,   227,  -221,   231,  -221,  -221,   394,   232,   230,
      87,  -221,   239,  -221
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     6,     1,     0,     4,     2,     0,    72,     0,
       0,     0,     7,    11,    12,     8,     9,    10,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      64,     0,    29,    25,    26,    27,    28,     0,    73,   108,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
      77,     0,     0,    19,     0,     0,     0,    13,    74,    92,
      93,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,     0,    69,
       0,    68,    65,     0,     0,   111,     0,    75,    94,    90,
      91,    83,    84,    85,    86,    87,    88,    89,    78,    79,
      80,    81,    82,   102,     0,     0,     0,    95,     0,    97,
      20,   115,     0,     0,     0,    23,    63,    70,     0,     0,
       0,     0,   110,     0,   101,    96,    15,    98,    74,     0,
       0,     0,     0,   116,     0,     0,     0,     0,    14,    76,
     100,     0,     0,   115,    21,    22,     0,   108,     0,     0,
       0,     0,     0,     0,    41,     0,    24,     0,     0,    66,
      71,    99,    17,     0,    62,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,    39,    40,    42,     0,
     109,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    30,    46,    47,    48,    49,
      50,     0,    32,   110,     0,     0,     0,     0,     0,     0,
       0,    31,    56,    57,    58,    59,    60,    67,     0,    33,
      23,     0,    23,    51,    52,    53,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
     108,     0,     0,    23,    35,     0,     0,    45,    55,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    23,     0,    43,    37,     0,     0,     0,
       0,    38,     0,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,  -221,  -221,  -221,   174,  -221,   236,  -221,
    -221,  -221,  -220,   -70,  -221,  -221,  -221,  -221,  -221,  -221,
     -75,   -27,  -221,  -118,  -221
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,    12,    13,    14,    15,    52,
      53,    16,   144,    37,   166,    17,    55,    92,    93,    18,
      96,   167,    50,   124,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,     8,   114,   139,     3,    81,     4,   132,    21,   116,
      82,     9,   133,   120,     7,    19,    20,   134,    59,    60,
      61,   -29,   133,   121,   131,    10,    23,   122,    87,    11,
     258,    97,   260,    88,    22,   173,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      97,   115,   140,   281,   118,    27,    28,    58,    30,   146,
      89,    29,   287,   151,    90,    31,   213,   214,   215,    38,
      65,   154,   156,   297,   157,    40,    41,    42,    43,    44,
      51,    54,    77,    57,    78,   158,   264,   265,   159,    80,
      32,   160,   216,   161,   162,    45,    33,    34,    35,    36,
      56,   163,    62,   171,   233,    65,   149,   208,   133,   133,
      58,    97,    72,    73,    74,    75,    76,    77,    83,    78,
      84,    46,   269,   117,    80,    47,    86,   133,   223,    24,
     164,    25,    85,    26,   165,   119,   189,    94,   270,    40,
      41,    42,    43,    44,    33,    34,    35,    36,   200,   201,
     202,   203,   204,   205,   123,    97,   209,    21,   211,    45,
     126,   127,   136,   138,   217,   218,   219,   220,   221,   222,
     141,   175,   176,   177,   178,   179,   180,   181,   128,   231,
     129,   262,   130,   142,     8,    46,   237,   238,   239,    47,
     182,   145,   147,   271,   152,   168,   148,   156,    48,   157,
      40,    41,    42,    43,    44,   153,   170,   155,   251,   169,
     158,   172,   174,   159,   183,   290,   160,   184,   161,   162,
      45,   185,   186,   187,  -114,   190,   163,   198,    65,    97,
     302,   206,   266,   199,   210,   224,   272,    74,    75,    76,
      77,   232,    78,   240,   235,   256,    46,    80,   247,   283,
      47,   249,   250,   252,   257,   164,   263,   273,   156,   165,
     157,    40,    41,    42,    43,    44,   268,   274,   277,   278,
     279,   158,   284,   282,   159,   285,   289,   160,   267,   161,
     162,    45,   291,   293,   294,   295,   296,   163,   298,   301,
     300,    91,    39,    40,    41,    42,    43,    44,   303,   143,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,    47,     0,    45,     0,     0,   164,     0,     0,   156,
     165,   157,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,   158,     0,   286,   159,     0,     0,   160,    46,
     161,   162,    45,    47,    95,     0,     0,     0,   163,     0,
       0,     0,    48,     0,     0,     0,     0,   156,     0,   157,
      40,    41,    42,    43,    44,     0,     0,     0,    46,     0,
     158,     0,    47,   159,     0,   292,   160,   164,   161,   162,
      45,   165,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,   157,    40,    41,
      42,    43,    44,     0,     0,     0,    46,     0,   158,     0,
      47,   159,     0,   299,   160,   164,   161,   162,    45,   165,
       0,     0,     0,     0,   163,    39,    40,    41,    42,    43,
      44,    39,    40,    41,    42,    43,    44,    39,    40,    41,
      42,    43,    44,     0,    46,     0,    45,     0,    47,     0,
       0,     0,    45,   164,     0,     0,     0,   165,    45,    39,
      40,    41,    42,    43,    44,    39,    40,    41,    42,    43,
      44,     0,    46,     0,     0,     0,    47,   113,    46,     0,
      45,     0,    47,   150,    46,    48,    45,     0,    47,     0,
       0,    48,     0,   188,     0,     0,     0,    48,     0,    39,
      40,    41,    42,    43,    44,   248,    46,     0,     0,     0,
      47,   207,    46,    63,    64,     0,    47,   261,     0,    48,
      45,     0,     0,     0,     0,    48,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,     0,    46,     0,     0,    80,
      47,    63,    64,     0,     0,     0,     0,     0,     0,    48,
       0,   191,   192,   193,   194,   195,   196,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    63,    64,   197,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,   275,   276,    63,    64,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,     0,
      79,    63,    64,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    98,    78,    63,    64,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,   135,    63,    64,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    78,   137,    63,
      64,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    63,    64,   212,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    63,    64,   225,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    63,    64,   226,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    63,    64,   227,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    63,
      64,   228,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    63,    64,   229,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    63,    64,   230,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   234,    78,    63,    64,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   236,    78,    63,    64,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    63,
      64,   241,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    63,    64,   242,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    63,    64,   243,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    63,    64,   244,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    63,    64,   245,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    63,
      64,   246,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    63,    64,   253,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    63,    64,   254,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    63,    64,   255,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,     0,   259,    63,
      64,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,   280,    63,    64,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,    78,   288,    63,    64,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    78,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,     0,     0,     0,
       0,    80,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,     0,     0,     0,
       0,    80
};

static const yytype_int16 yycheck[] =
{
      27,     3,    77,   121,     0,    56,    34,    55,     3,    79,
      61,    13,    60,    83,     3,     5,     3,    55,    45,    46,
      47,    18,    60,    58,    94,    27,     3,    62,    27,    31,
     250,    58,   252,    32,    29,   153,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,   122,   273,    81,    35,    54,    54,    58,   129,
      59,    54,   282,   138,    63,     4,    35,    36,    37,     3,
      42,   141,     1,   293,     3,     4,     5,     6,     7,     8,
       3,    55,    54,    59,    56,    14,    15,    16,    17,    61,
       3,    20,    61,    22,    23,    24,     9,    10,    11,    12,
      57,    30,     3,    55,    55,    42,   133,   182,    60,    60,
      54,   138,    49,    50,    51,    52,    53,    54,    58,    56,
      55,    50,    55,     3,    61,    54,    58,    60,   198,    56,
      59,    58,    60,    60,    63,     3,   163,    58,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   175,   176,
     177,   178,   179,   180,     3,   182,   183,     3,   185,    24,
      59,     3,    59,    54,   191,   192,   193,   194,   195,   196,
      58,    35,    36,    37,    38,    39,    40,    41,    56,   206,
      58,   256,    60,    28,     3,    50,   213,   214,   215,    54,
      54,     4,    63,   263,    28,    57,    59,     1,    63,     3,
       4,     5,     6,     7,     8,    58,     3,    59,   235,    59,
      14,    59,    59,    17,    54,   285,    20,     3,    22,    23,
      24,    54,    59,    59,    28,     3,    30,    58,    42,   256,
     300,    56,   259,    28,    18,    59,   263,    51,    52,    53,
      54,    59,    56,     3,    56,    54,    50,    61,    59,   276,
      54,    59,    58,    58,     3,    59,    58,    58,     1,    63,
       3,     4,     5,     6,     7,     8,    59,    59,    59,    59,
      18,    14,     3,    58,    17,    58,    33,    20,    21,    22,
      23,    24,    59,    58,     4,    59,    59,    30,    57,    59,
      58,    55,     3,     4,     5,     6,     7,     8,    59,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    54,    -1,    24,    -1,    -1,    59,    -1,    -1,     1,
      63,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    16,    17,    -1,    -1,    20,    50,
      22,    23,    24,    54,    55,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    50,    -1,
      14,    -1,    54,    17,    -1,    19,    20,    59,    22,    23,
      24,    63,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    50,    -1,    14,    -1,
      54,    17,    -1,    19,    20,    59,    22,    23,    24,    63,
      -1,    -1,    -1,    -1,    30,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    -1,    50,    -1,    24,    -1,    54,    -1,
      -1,    -1,    24,    59,    -1,    -1,    -1,    63,    24,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,    -1,    50,    -1,    -1,    -1,    54,    55,    50,    -1,
      24,    -1,    54,    55,    50,    63,    24,    -1,    54,    -1,
      -1,    63,    -1,    59,    -1,    -1,    -1,    63,    -1,     3,
       4,     5,     6,     7,     8,    17,    50,    -1,    -1,    -1,
      54,    55,    50,    25,    26,    -1,    54,    55,    -1,    63,
      24,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    -1,    50,    -1,    -1,    61,
      54,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    25,    26,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    25,    26,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      58,    25,    26,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    25,    26,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    25,    26,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    25,
      26,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    25,    26,    59,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    25,    26,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    25,    26,    59,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    25,    26,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    25,
      26,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    25,    26,    59,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    25,    26,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    25,    26,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    25,    26,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    25,
      26,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    25,    26,    59,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    25,    26,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    25,    26,    59,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    25,    26,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    25,
      26,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    25,    26,    59,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    25,    26,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    25,    26,    59,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    58,    25,
      26,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    25,    26,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    25,    26,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    25,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      -1,    61,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,    67,     0,    34,    68,    69,     3,     3,    13,
      27,    31,    70,    71,    72,    73,    76,    80,    84,     5,
       3,     3,    29,     3,    56,    58,    60,    35,    54,    54,
      58,     4,     3,     9,    10,    11,    12,    78,     3,     3,
       4,     5,     6,     7,     8,    24,    50,    54,    63,    86,
      87,     3,    74,    75,    55,    81,    57,    59,    54,    86,
      86,    86,     3,    25,    26,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    56,    58,
      61,    56,    61,    58,    55,    60,    58,    27,    32,    59,
      63,    73,    82,    83,    58,    55,    85,    86,    55,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    55,    85,    86,    78,     3,    86,     3,
      78,    58,    62,     3,    88,    89,    59,     3,    56,    58,
      60,    78,    55,    60,    55,    57,    59,    57,    54,    88,
      78,    58,    28,    71,    77,     4,    78,    63,    59,    86,
      55,    85,    28,    58,    78,    59,     1,     3,    14,    17,
      20,    22,    23,    30,    59,    63,    79,    86,    57,    59,
       3,    55,    59,    88,    59,    35,    36,    37,    38,    39,
      40,    41,    54,    54,     3,    54,    59,    59,    59,    86,
       3,    35,    36,    37,    38,    39,    40,    59,    58,    28,
      86,    86,    86,    86,    86,    86,    56,    55,    85,    86,
      18,    86,    59,    35,    36,    37,    61,    86,    86,    86,
      86,    86,    86,    78,    59,    59,    59,    59,    59,    59,
      59,    86,    59,    55,    55,    56,    55,    86,    86,    86,
       3,    59,    59,    59,    59,    59,    59,    59,    17,    59,
      58,    86,    58,    59,    59,    59,    54,     3,    77,    58,
      77,    55,    85,    58,    15,    16,    86,    21,    59,    55,
       3,    78,    86,    58,    59,    57,    58,    59,    59,    18,
      57,    77,    58,    86,     3,    58,    16,    77,    57,    33,
      78,    59,    19,    58,     4,    59,    59,    77,    57,    19,
      58,    59,    78,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    76,    77,    77,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    81,    81,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     0,     2,     1,     1,
       1,     1,     1,     4,     7,     7,    11,     9,     0,     1,
       3,     5,     8,     0,     2,     1,     1,     1,     1,     1,
       4,     4,     4,     5,     3,     8,    11,    12,    14,     2,
       2,     1,     2,    12,    16,     8,     4,     4,     4,     4,
       4,     5,     5,     5,     7,     8,     4,     4,     4,     4,
       4,     2,     2,     6,     0,     2,     4,     7,     1,     1,
       2,     4,     1,     3,     0,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     4,     3,     4,     6,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     6,     5,     2,     0,     2
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
  case 2: /* program: macro_def_list top_level_list  */
#line 93 "myanalyzer.y"
                                  {
        printf("%s", (yyvsp[0].string));
    }
#line 1623 "out/myanalyzer.tab.c"
    break;

  case 3: /* macro_def_list: %empty  */
#line 99 "myanalyzer.y"
                { (yyval.string) = strdup(""); }
#line 1629 "out/myanalyzer.tab.c"
    break;

  case 4: /* macro_def_list: macro_def_list macro_def  */
#line 100 "myanalyzer.y"
                               {
			fprintf(stderr, "Macro definition: %s\n", (yyvsp[-1].string));
			(yyval.string) = (yyvsp[-1].string); // or strdup($1) if you want to duplicate
		}
#line 1638 "out/myanalyzer.tab.c"
    break;

  case 5: /* macro_def: KW_DEFMACRO IDENTIFIER CONST_FLOAT  */
#line 107 "myanalyzer.y"
                                       {
			fprintf(stderr, "Macro definition: %s = %s\n", (yyvsp[-1].string), (yyvsp[0].string));
			char* macro = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 16);
			sprintf(macro, "float %s = %s;\n", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = add_indentation(macro);
			free(macro);
			free((yyvsp[-1].string));
			free((yyvsp[0].string));
		}
#line 1652 "out/myanalyzer.tab.c"
    break;

  case 6: /* top_level_list: %empty  */
#line 119 "myanalyzer.y"
                { (yyval.string) = strdup(""); }
#line 1658 "out/myanalyzer.tab.c"
    break;

  case 7: /* top_level_list: top_level_list top_level  */
#line 120 "myanalyzer.y"
                              {
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			free((yyvsp[-1].string));
			free((yyvsp[0].string));
		}
#line 1670 "out/myanalyzer.tab.c"
    break;

  case 8: /* top_level: function  */
#line 130 "myanalyzer.y"
                 {
		fprintf(stderr, "Function: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1679 "out/myanalyzer.tab.c"
    break;

  case 9: /* top_level: main_function  */
#line 133 "myanalyzer.y"
                          {
		fprintf(stderr, "Main function: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1688 "out/myanalyzer.tab.c"
    break;

  case 10: /* top_level: component  */
#line 136 "myanalyzer.y"
                      {
		fprintf(stderr, "Component: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1697 "out/myanalyzer.tab.c"
    break;

  case 11: /* top_level: var_declaration  */
#line 139 "myanalyzer.y"
                            {
		fprintf(stderr, "Variable declaration: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1706 "out/myanalyzer.tab.c"
    break;

  case 12: /* top_level: const_declaration  */
#line 142 "myanalyzer.y"
                              {
		fprintf(stderr, "Constant declaration: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1715 "out/myanalyzer.tab.c"
    break;

  case 13: /* var_declaration: ident_list COLON type SEMICOLON  */
#line 149 "myanalyzer.y"
                                   {
			fprintf(stderr, "Variable declaration: %s\n", (yyvsp[-3].string));

			char* decl = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
			sprintf(decl, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
			(yyval.string) = add_indentation(decl);
			free(decl);
			free((yyvsp[-3].string));
			free((yyvsp[-1].string));
    }
#line 1730 "out/myanalyzer.tab.c"
    break;

  case 14: /* var_declaration: ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON  */
#line 158 "myanalyzer.y"
                                                                    { 
			fprintf(stderr, "Array declaration: %s[%s]\n", (yyvsp[-6].string), (yyvsp[-4].string));

			char* decl = malloc(strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 16);
			sprintf(decl, "%s %s[%s];\n", (yyvsp[-1].string), (yyvsp[-6].string), (yyvsp[-4].string));
			(yyval.string) = add_indentation(decl);
			free(decl);
		}
#line 1743 "out/myanalyzer.tab.c"
    break;

  case 15: /* const_declaration: KW_CONST IDENTIFIER OP_ASSIGN expression COLON type SEMICOLON  */
#line 169 "myanalyzer.y"
                                                                  {
				fprintf(stderr, "Constant declaration: %s = %s\n", (yyvsp[-5].string), (yyvsp[-3].string));

				char* decl = malloc(strlen((yyvsp[-5].string)) + strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
				sprintf(decl, "const %s %s = %s;\n", (yyvsp[-1].string), (yyvsp[-5].string), (yyvsp[-3].string));
				(yyval.string) = add_indentation(decl);
				free(decl);
				free((yyvsp[-5].string));
				free((yyvsp[-3].string));
				free((yyvsp[-1].string));
		}
#line 1759 "out/myanalyzer.tab.c"
    break;

  case 16: /* function: KW_DEF IDENTIFIER LPAREN param_list RPAREN OP_ARROW type COLON block KW_ENDDEF SEMICOLON  */
#line 183 "myanalyzer.y"
                                                                                             {
        fprintf(stderr, "Function with return: %s\n", (yyvsp[-9].string));

        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;

        char* code = malloc(strlen(body) + 64);
        sprintf(code, "%s %s(%s) {\n%s}\n", (yyvsp[-4].string), (yyvsp[-9].string), (yyvsp[-7].string), body);
        free(body);
        (yyval.string) = code;
    }
#line 1776 "out/myanalyzer.tab.c"
    break;

  case 17: /* function: KW_DEF IDENTIFIER LPAREN param_list RPAREN COLON block KW_ENDDEF SEMICOLON  */
#line 195 "myanalyzer.y"
                                                                               {
        fprintf(stderr, "Function with no return: %s\n", (yyvsp[-7].string));

        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;

        char* code = malloc(strlen(body) + 64);
        sprintf(code, "void %s(%s) {\n%s}\n", (yyvsp[-7].string), (yyvsp[-5].string), body);
        free(body);
        (yyval.string) = code;
    }
#line 1793 "out/myanalyzer.tab.c"
    break;

  case 18: /* param_list: %empty  */
#line 210 "myanalyzer.y"
                    { (yyval.string) = strdup(""); }
#line 1799 "out/myanalyzer.tab.c"
    break;

  case 19: /* param_list: param_decl_list  */
#line 211 "myanalyzer.y"
                          { fprintf(stderr, "Param list %s\n", (yyvsp[0].string));  (yyval.string) = (yyvsp[0].string); }
#line 1805 "out/myanalyzer.tab.c"
    break;

  case 20: /* param_decl_list: IDENTIFIER COLON type  */
#line 215 "myanalyzer.y"
                          {
			fprintf(stderr, "Param: %s\n", (yyvsp[-2].string));

			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf((yyval.string), "%s %s", (yyvsp[0].string), (yyvsp[-2].string));
    }
#line 1816 "out/myanalyzer.tab.c"
    break;

  case 21: /* param_decl_list: param_decl_list COMMA IDENTIFIER COLON type  */
#line 220 "myanalyzer.y"
                                                    {
			fprintf(stderr, "Param: %s\n", (yyvsp[-2].string));

			char* tmp = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf(tmp, "%s, %s %s", (yyvsp[-4].string), (yyvsp[0].string), (yyvsp[-2].string));
			(yyval.string) = tmp;
    }
#line 1828 "out/myanalyzer.tab.c"
    break;

  case 22: /* main_function: KW_DEF KW_MAIN LPAREN RPAREN COLON block KW_ENDDEF SEMICOLON  */
#line 229 "myanalyzer.y"
                                                                 {
        fprintf(stderr, "Main function\n");
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen(body) + 64);
        sprintf(code, "int main() {\n%s}\n", body);
        free(body);
        (yyval.string) = code;   // <--- Return the generated code!
    }
#line 1843 "out/myanalyzer.tab.c"
    break;

  case 23: /* stmt_list: %empty  */
#line 242 "myanalyzer.y"
                            { (yyval.string) = strdup(""); }
#line 1849 "out/myanalyzer.tab.c"
    break;

  case 24: /* stmt_list: stmt_list stmt  */
#line 243 "myanalyzer.y"
                     {
        char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
        sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
        (yyval.string) = tmp;
    }
#line 1859 "out/myanalyzer.tab.c"
    break;

  case 25: /* type: KW_INTEGER  */
#line 251 "myanalyzer.y"
                { (yyval.string) = strdup("int"); }
#line 1865 "out/myanalyzer.tab.c"
    break;

  case 26: /* type: KW_SCALAR  */
#line 252 "myanalyzer.y"
                { (yyval.string) = strdup("float"); }
#line 1871 "out/myanalyzer.tab.c"
    break;

  case 27: /* type: KW_STR  */
#line 253 "myanalyzer.y"
                { (yyval.string) = strdup("char*"); }
#line 1877 "out/myanalyzer.tab.c"
    break;

  case 28: /* type: KW_BOOL  */
#line 254 "myanalyzer.y"
                { (yyval.string) = strdup("bool"); }
#line 1883 "out/myanalyzer.tab.c"
    break;

  case 29: /* type: IDENTIFIER  */
#line 255 "myanalyzer.y"
                { (yyval.string) = strdup((yyvsp[0].string)); }
#line 1889 "out/myanalyzer.tab.c"
    break;

  case 30: /* stmt: IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 259 "myanalyzer.y"
                                              {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);

        fprintf(stderr, "Assigning: %s = %s\n", (yyvsp[-3].string), (yyvsp[-1].string));

        sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 1903 "out/myanalyzer.tab.c"
    break;

  case 31: /* stmt: expression OP_ASSIGN expression SEMICOLON  */
#line 267 "myanalyzer.y"
                                                  {
        // Handles assignments like a[i] = x; or obj.field = x;
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 1915 "out/myanalyzer.tab.c"
    break;

  case 32: /* stmt: IDENTIFIER LPAREN RPAREN SEMICOLON  */
#line 273 "myanalyzer.y"
                                           {
        char* line = malloc(strlen((yyvsp[-3].string)) + 16);

				fprintf(stderr, "Calling: %s()\n", (yyvsp[-3].string));

				sprintf(line, "%s();\n", (yyvsp[-3].string));
				(yyval.string) = add_indentation(line);
				free(line);
    }
#line 1929 "out/myanalyzer.tab.c"
    break;

  case 33: /* stmt: IDENTIFIER LPAREN arg_list RPAREN SEMICOLON  */
#line 281 "myanalyzer.y"
                                                    {
        char* line = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + 16);

				fprintf(stderr, "Calling: %s(%s)\n", (yyvsp[-4].string), (yyvsp[-2].string));

				sprintf(line, "%s(%s);\n", (yyvsp[-4].string), (yyvsp[-2].string));
				(yyval.string) = add_indentation(line);
				free(line);
    }
#line 1943 "out/myanalyzer.tab.c"
    break;

  case 34: /* stmt: KW_RETURN expression SEMICOLON  */
#line 289 "myanalyzer.y"
                                       {
        char* line = malloc(strlen((yyvsp[-1].string)) + 16);

        fprintf(stderr, "Returning: %s\n", (yyvsp[-1].string));

        sprintf(line, "return %s;\n", (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 1957 "out/myanalyzer.tab.c"
    break;

  case 35: /* stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON  */
#line 297 "myanalyzer.y"
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
#line 1974 "out/myanalyzer.tab.c"
    break;

  case 36: /* stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ELSE COLON stmt_list KW_ENDIF SEMICOLON  */
#line 308 "myanalyzer.y"
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
#line 1993 "out/myanalyzer.tab.c"
    break;

  case 37: /* stmt: KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON  */
#line 321 "myanalyzer.y"
                                                                                                                  {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-10].string)) + strlen((yyvsp[-7].string)) + strlen((yyvsp[-5].string)) + strlen(body) + 128);

        fprintf(stderr, "For loop: %s\n", (yyvsp[-10].string));

        sprintf(code, "for (int %s = %s; %s < %s; ++%s) {\n%s}\n", (yyvsp[-10].string), (yyvsp[-7].string), (yyvsp[-10].string), (yyvsp[-5].string), (yyvsp[-10].string), body);
        (yyval.string) = code;
        free(body);
    }
#line 2010 "out/myanalyzer.tab.c"
    break;

  case 38: /* stmt: KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON  */
#line 332 "myanalyzer.y"
                                                                                                                                   {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;

				fprintf(stderr, "For loop with step: %s\n", (yyvsp[-12].string));

        char* code = malloc(strlen((yyvsp[-12].string)) + strlen((yyvsp[-9].string)) + strlen((yyvsp[-7].string)) + strlen((yyvsp[-5].string)) + strlen(body) + 128);
        sprintf(code, "for (int %s = %s; %s < %s; %s += %s) {\n%s}\n", (yyvsp[-12].string), (yyvsp[-9].string), (yyvsp[-12].string), (yyvsp[-7].string), (yyvsp[-12].string), (yyvsp[-5].string), body);
        (yyval.string) = code;
        free(body);
    }
#line 2027 "out/myanalyzer.tab.c"
    break;

  case 39: /* stmt: KW_BREAK SEMICOLON  */
#line 343 "myanalyzer.y"
                           {
        (yyval.string) = add_indentation("break;\n");
    }
#line 2035 "out/myanalyzer.tab.c"
    break;

  case 40: /* stmt: KW_CONTINUE SEMICOLON  */
#line 345 "myanalyzer.y"
                              {
        (yyval.string) = add_indentation("continue;\n");
    }
#line 2043 "out/myanalyzer.tab.c"
    break;

  case 41: /* stmt: SEMICOLON  */
#line 347 "myanalyzer.y"
                  {
        fprintf(stderr, "STMT SEMICOLON\n");
        (yyval.string) = strdup(";");
    }
#line 2052 "out/myanalyzer.tab.c"
    break;

  case 42: /* stmt: KW_RETURN SEMICOLON  */
#line 350 "myanalyzer.y"
                            {   
        fprintf(stderr, "STMT RET SEMICOLON\n");
        (yyval.string) = strdup("return;\n");
    }
#line 2061 "out/myanalyzer.tab.c"
    break;

  case 43: /* stmt: IDENTIFIER OP_DEFINE LBRACKET expression KW_FOR IDENTIFIER COLON expression RBRACKET COLON type SEMICOLON  */
#line 353 "myanalyzer.y"
                                                                                                                  {
        // Handles: a := [expr for i:100]:integer;

				fprintf(stderr, "Defining array: %s := [%s for %s:%s]:%s;\n", (yyvsp[-11].string), (yyvsp[-8].string), (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-1].string));

        char* code = malloc(1024);
        sprintf(code, "%s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s = 0; %s < %s; ++%s) {\n    %s[%s] = %s;\n}\n",
            (yyvsp[-11].string), (yyvsp[-1].string), (yyvsp[-4].string), (yyvsp[-1].string), (yyvsp[-6].string), (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-6].string), (yyvsp[-11].string), (yyvsp[-6].string), (yyvsp[-8].string));
        (yyval.string) = add_indentation(code);
        free(code);
    }
#line 2077 "out/myanalyzer.tab.c"
    break;

  case 44: /* stmt: IDENTIFIER OP_DEFINE LBRACKET expression KW_FOR IDENTIFIER COLON type KW_IN IDENTIFIER KW_OF CONST_INT RBRACKET COLON type SEMICOLON  */
#line 363 "myanalyzer.y"
                                                                                                                                             {
        // Handles: half := [x/2 for x:scalar in a of 100]:scalar;
        char* code = malloc(1024);
        sprintf(code,
            "%s = (%s*)malloc(%s * sizeof(%s));\n"
            "for (int i = 0; i < %s; ++i) {\n"
            "    %s[i] = %s;\n"
            "}\n",
            (yyvsp[-15].string), (yyvsp[-1].string), (yyvsp[-4].string), (yyvsp[-1].string), (yyvsp[-4].string), (yyvsp[-15].string), (yyvsp[-12].string)
        );
        (yyval.string) = add_indentation(code);
        free(code);
    }
#line 2095 "out/myanalyzer.tab.c"
    break;

  case 45: /* stmt: KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON  */
#line 375 "myanalyzer.y"
                                                                                {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;

				fprintf(stderr, "While loop: %s\n", (yyvsp[-5].string));

        char* code = malloc(strlen((yyvsp[-5].string)) + strlen(body) + 64);
        sprintf(code, "while (%s) {\n%s}\n", (yyvsp[-5].string), body);
        (yyval.string) = code;
        free(body);
    }
#line 2112 "out/myanalyzer.tab.c"
    break;

  case 46: /* stmt: IDENTIFIER OP_PLUSEQ expression SEMICOLON  */
#line 386 "myanalyzer.y"
                                                  {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        
				fprintf(stderr, "Adding: %s += %s\n", (yyvsp[-3].string), (yyvsp[-1].string));
				
				sprintf(line, "%s += %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2126 "out/myanalyzer.tab.c"
    break;

  case 47: /* stmt: IDENTIFIER OP_MINUSEQ expression SEMICOLON  */
#line 394 "myanalyzer.y"
                                                   {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);

				fprintf(stderr, "Subtracting: %s -= %s\n", (yyvsp[-3].string), (yyvsp[-1].string));

        sprintf(line, "%s -= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2140 "out/myanalyzer.tab.c"
    break;

  case 48: /* stmt: IDENTIFIER OP_MULTEQ expression SEMICOLON  */
#line 402 "myanalyzer.y"
                                                  {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        
				fprintf(stderr, "Multiplying: %s *= %s\n", (yyvsp[-3].string), (yyvsp[-1].string));

				sprintf(line, "%s *= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
				(yyval.string) = add_indentation(line);
				free(line);
		}
#line 2154 "out/myanalyzer.tab.c"
    break;

  case 49: /* stmt: IDENTIFIER OP_DIVEQ expression SEMICOLON  */
#line 410 "myanalyzer.y"
                                                             {
				char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
				
				fprintf(stderr, "Dividing: %s /= %s\n", (yyvsp[-3].string), (yyvsp[-1].string));

				sprintf(line, "%s *= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2168 "out/myanalyzer.tab.c"
    break;

  case 50: /* stmt: IDENTIFIER OP_MODEQ expression SEMICOLON  */
#line 418 "myanalyzer.y"
                                                 {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        
				fprintf(stderr, "Modulo: %s %%= %s\n", (yyvsp[-3].string), (yyvsp[-1].string));
				
				sprintf(line, "%s %%= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2182 "out/myanalyzer.tab.c"
    break;

  case 51: /* stmt: HASH IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 426 "myanalyzer.y"
                                                       {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 32);
        sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2193 "out/myanalyzer.tab.c"
    break;

  case 52: /* stmt: HASH IDENTIFIER OP_PLUSEQ expression SEMICOLON  */
#line 431 "myanalyzer.y"
                                                       {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 32);
        sprintf(line, "%s += %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2204 "out/myanalyzer.tab.c"
    break;

  case 53: /* stmt: HASH IDENTIFIER OP_MINUSEQ expression SEMICOLON  */
#line 436 "myanalyzer.y"
                                                        {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 32);
        sprintf(line, "%s -= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2215 "out/myanalyzer.tab.c"
    break;

  case 54: /* stmt: HASH IDENTIFIER DOT IDENTIFIER LPAREN RPAREN SEMICOLON  */
#line 441 "myanalyzer.y"
                                                               {
        char* line = malloc(strlen((yyvsp[-5].string)) + strlen((yyvsp[-3].string)) + 32);
        sprintf(line, "%s.%s();\n", (yyvsp[-5].string), (yyvsp[-3].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2226 "out/myanalyzer.tab.c"
    break;

  case 55: /* stmt: HASH IDENTIFIER DOT IDENTIFIER LPAREN arg_list RPAREN SEMICOLON  */
#line 446 "myanalyzer.y"
                                                                        {
        char* line = malloc(strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + 32);
        sprintf(line, "%s.%s(%s);\n", (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2237 "out/myanalyzer.tab.c"
    break;

  case 56: /* stmt: expression OP_PLUSEQ expression SEMICOLON  */
#line 451 "myanalyzer.y"
                                                  {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s += %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2248 "out/myanalyzer.tab.c"
    break;

  case 57: /* stmt: expression OP_MINUSEQ expression SEMICOLON  */
#line 456 "myanalyzer.y"
                                                   {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s -= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2259 "out/myanalyzer.tab.c"
    break;

  case 58: /* stmt: expression OP_MULTEQ expression SEMICOLON  */
#line 461 "myanalyzer.y"
                                                  {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s *= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2270 "out/myanalyzer.tab.c"
    break;

  case 59: /* stmt: expression OP_DIVEQ expression SEMICOLON  */
#line 466 "myanalyzer.y"
                                                 {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s /= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2281 "out/myanalyzer.tab.c"
    break;

  case 60: /* stmt: expression OP_MODEQ expression SEMICOLON  */
#line 471 "myanalyzer.y"
                                                 {
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s %%= %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2292 "out/myanalyzer.tab.c"
    break;

  case 61: /* stmt: expression SEMICOLON  */
#line 476 "myanalyzer.y"
                             {
        char* line = malloc(strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s;\n", (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        free(line);
    }
#line 2303 "out/myanalyzer.tab.c"
    break;

  case 62: /* stmt: error SEMICOLON  */
#line 481 "myanalyzer.y"
                        {
			fprintf(stderr, "Syntax error at line %d\n", line_num);
			yyerrok;
		}
#line 2312 "out/myanalyzer.tab.c"
    break;

  case 63: /* component: KW_COMP IDENTIFIER COLON component_body KW_ENDCOMP SEMICOLON  */
#line 488 "myanalyzer.y"
                                                                 {
				fprintf(stderr, "Component: %s\n", (yyvsp[-4].string));

				char* code = malloc(strlen((yyvsp[-4].string)) + 16);
				sprintf(code, "struct %s {\n%s};\n", (yyvsp[-4].string), (yyvsp[-2].string));
				(yyval.string) = add_indentation(code);
				free(code);
		}
#line 2325 "out/myanalyzer.tab.c"
    break;

  case 64: /* component_body: %empty  */
#line 499 "myanalyzer.y"
                { (yyval.string) = strdup(""); }
#line 2331 "out/myanalyzer.tab.c"
    break;

  case 65: /* component_body: component_body component_member  */
#line 500 "myanalyzer.y"
                                    {
			fprintf(stderr, "Component member: %s\n", (yyvsp[0].string));

			char* code = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 16);
			sprintf(code, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = code;
			free(code);
	}
#line 2344 "out/myanalyzer.tab.c"
    break;

  case 66: /* component_member: hash_ident_list COLON type SEMICOLON  */
#line 511 "myanalyzer.y"
                                             {
			char* decl = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
			sprintf(decl, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
			(yyval.string) = add_indentation(decl);
			free(decl);
			free((yyvsp[-3].string));
			free((yyvsp[-1].string));
	}
#line 2357 "out/myanalyzer.tab.c"
    break;

  case 67: /* component_member: hash_ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON  */
#line 518 "myanalyzer.y"
                                                                             {
			char* decl = malloc(strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 16);
			sprintf(decl, "%s %s[%s];\n", (yyvsp[-1].string), (yyvsp[-6].string), (yyvsp[-4].string));
			(yyval.string) = add_indentation(decl);
			free(decl);
			free((yyvsp[-6].string));
			free((yyvsp[-4].string));
			free((yyvsp[-1].string));
    }
#line 2371 "out/myanalyzer.tab.c"
    break;

  case 68: /* component_member: function  */
#line 526 "myanalyzer.y"
                 {
			char* decl = malloc(strlen((yyvsp[0].string)) + 16);
			sprintf(decl, "%s", (yyvsp[0].string));
			(yyval.string) = add_indentation(decl);
			free(decl);
		}
#line 2382 "out/myanalyzer.tab.c"
    break;

  case 69: /* component_member: SEMICOLON  */
#line 531 "myanalyzer.y"
                              { (yyval.string) = strdup(""); }
#line 2388 "out/myanalyzer.tab.c"
    break;

  case 70: /* hash_ident_list: HASH IDENTIFIER  */
#line 535 "myanalyzer.y"
                    {
        (yyval.string) = malloc(strlen((yyvsp[0].string)) + 2);
        sprintf((yyval.string), "#%s", (yyvsp[0].string));
    }
#line 2397 "out/myanalyzer.tab.c"
    break;

  case 71: /* hash_ident_list: hash_ident_list COMMA HASH IDENTIFIER  */
#line 539 "myanalyzer.y"
                                          {
        char* tmp = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[0].string)) + 3);
        sprintf(tmp, "%s, #%s", (yyvsp[-3].string), (yyvsp[0].string));
        free((yyvsp[-3].string));
        (yyval.string) = tmp;
    }
#line 2408 "out/myanalyzer.tab.c"
    break;

  case 72: /* ident_list: IDENTIFIER  */
#line 548 "myanalyzer.y"
                   {
		(yyval.string) = strdup((yyvsp[0].string));
	}
#line 2416 "out/myanalyzer.tab.c"
    break;

  case 73: /* ident_list: ident_list COMMA IDENTIFIER  */
#line 550 "myanalyzer.y"
                                        {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s, %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = tmp;
	}
#line 2426 "out/myanalyzer.tab.c"
    break;

  case 74: /* arg_list: %empty  */
#line 558 "myanalyzer.y"
                { (yyval.string) = strdup(""); }
#line 2432 "out/myanalyzer.tab.c"
    break;

  case 75: /* arg_list: expression  */
#line 559 "myanalyzer.y"
               { (yyval.string) = strdup((yyvsp[0].string)); }
#line 2438 "out/myanalyzer.tab.c"
    break;

  case 76: /* arg_list: arg_list COMMA expression  */
#line 560 "myanalyzer.y"
                              {
        char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
        sprintf(tmp, "%s, %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = tmp;
        free((yyvsp[-2].string));
        free((yyvsp[0].string));
    }
#line 2450 "out/myanalyzer.tab.c"
    break;

  case 78: /* expression: expression OP_PLUS expression  */
#line 571 "myanalyzer.y"
                                        {
		char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);

		fprintf(stderr, "Adding: %s + %s\n", (yyvsp[-2].string), (yyvsp[0].string));

		sprintf(code, "%s + %s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = code;
	}
#line 2463 "out/myanalyzer.tab.c"
    break;

  case 79: /* expression: expression OP_MINUS expression  */
#line 578 "myanalyzer.y"
                                          {
		char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
		fprintf(stderr, "Subtracting: %s - %s\n", (yyvsp[-2].string), (yyvsp[0].string));
		sprintf(code, "%s - %s", (yyvsp[-2].string), (yyvsp[0].string));
	}
#line 2473 "out/myanalyzer.tab.c"
    break;

  case 80: /* expression: expression OP_MULT expression  */
#line 582 "myanalyzer.y"
                                          {
		char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
		fprintf(stderr, "Multiplying: %s * %s\n", (yyvsp[-2].string), (yyvsp[0].string));
		sprintf(code, "%s * %s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = code;
	}
#line 2484 "out/myanalyzer.tab.c"
    break;

  case 81: /* expression: expression OP_DIV expression  */
#line 587 "myanalyzer.y"
                                         {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			sprintf(code, "%s / %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2494 "out/myanalyzer.tab.c"
    break;

  case 82: /* expression: expression OP_MOD expression  */
#line 591 "myanalyzer.y"
                                         {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			sprintf(code, "%s %% %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2504 "out/myanalyzer.tab.c"
    break;

  case 83: /* expression: expression OP_POW expression  */
#line 595 "myanalyzer.y"
                                         {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			sprintf(code, "%s ** %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2514 "out/myanalyzer.tab.c"
    break;

  case 84: /* expression: expression OP_EQ expression  */
#line 599 "myanalyzer.y"
                                        {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			
			fprintf(stderr, "Equal: %s == %s\n", (yyvsp[-2].string), (yyvsp[0].string));

			sprintf(code, "%s == %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2527 "out/myanalyzer.tab.c"
    break;

  case 85: /* expression: expression OP_NEQ expression  */
#line 606 "myanalyzer.y"
                                         {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			
			fprintf(stderr, "Not equal: %s != %s\n", (yyvsp[-2].string), (yyvsp[0].string));        

			sprintf(code, "%s != %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2540 "out/myanalyzer.tab.c"
    break;

  case 86: /* expression: expression OP_LT expression  */
#line 613 "myanalyzer.y"
                                        {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			
			fprintf(stderr, "Less than: %s < %s\n", (yyvsp[-2].string), (yyvsp[0].string));
			
			sprintf(code, "%s < %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2553 "out/myanalyzer.tab.c"
    break;

  case 87: /* expression: expression OP_LEQ expression  */
#line 620 "myanalyzer.y"
                                         {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			
			fprintf(stderr, "Less than or equal: %s <= %s\n", (yyvsp[-2].string), (yyvsp[0].string));
			
			sprintf(code, "%s <= %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2566 "out/myanalyzer.tab.c"
    break;

  case 88: /* expression: expression OP_GT expression  */
#line 627 "myanalyzer.y"
                                        {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);

			fprintf(stderr, "Greater than: %s > %s\n", (yyvsp[-2].string), (yyvsp[0].string));

			sprintf(code, "%s > %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2579 "out/myanalyzer.tab.c"
    break;

  case 89: /* expression: expression OP_GEQ expression  */
#line 634 "myanalyzer.y"
                                         {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			
			fprintf(stderr, "Greater than or equal: %s >= %s\n", (yyvsp[-2].string), (yyvsp[0].string));

			sprintf(code, "%s >= %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2592 "out/myanalyzer.tab.c"
    break;

  case 90: /* expression: expression KW_AND expression  */
#line 641 "myanalyzer.y"
                                         {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			sprintf(code, "%s && %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2602 "out/myanalyzer.tab.c"
    break;

  case 91: /* expression: expression KW_OR expression  */
#line 645 "myanalyzer.y"
                                        {
			char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			sprintf(code, "%s || %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2612 "out/myanalyzer.tab.c"
    break;

  case 92: /* expression: KW_NOT expression  */
#line 649 "myanalyzer.y"
                                           {
			char* code = malloc(strlen((yyvsp[0].string)) + 5);
			sprintf(code, "!%s", (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2622 "out/myanalyzer.tab.c"
    break;

  case 93: /* expression: OP_MINUS expression  */
#line 653 "myanalyzer.y"
                                             {
			char* code = malloc(strlen((yyvsp[0].string)) + 2);
			sprintf(code, "-%s", (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2632 "out/myanalyzer.tab.c"
    break;

  case 94: /* expression: LPAREN expression RPAREN  */
#line 657 "myanalyzer.y"
                                     {
			char* code = malloc(strlen((yyvsp[-1].string)) + 3);

			fprintf(stderr, "Parentheses: (%s)\n", (yyvsp[-1].string));

			sprintf(code, "(%s)", (yyvsp[-1].string));
			(yyval.string) = code;
	}
#line 2645 "out/myanalyzer.tab.c"
    break;

  case 95: /* expression: expression DOT IDENTIFIER  */
#line 664 "myanalyzer.y"
                                      {
		char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
		
		fprintf(stderr, "Field access: %s.%s\n", (yyvsp[-2].string), (yyvsp[0].string));

		sprintf(code, "%s.%s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = code;
	}
#line 2658 "out/myanalyzer.tab.c"
    break;

  case 96: /* expression: expression LBRACKET expression RBRACKET  */
#line 671 "myanalyzer.y"
                                                    {
		char* code = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
		
		fprintf(stderr, "Array access: %s[%s]\n", (yyvsp[-3].string), (yyvsp[-1].string));

		sprintf(code, "%s[%s]", (yyvsp[-3].string), (yyvsp[-1].string));
		(yyval.string) = code;
	}
#line 2671 "out/myanalyzer.tab.c"
    break;

  case 97: /* expression: primary_expression DOT IDENTIFIER  */
#line 679 "myanalyzer.y"
                                            {
		char* code = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
		sprintf(code, "%s.%s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = code;
	}
#line 2681 "out/myanalyzer.tab.c"
    break;

  case 98: /* expression: primary_expression LBRACKET expression RBRACKET  */
#line 683 "myanalyzer.y"
                                                            {
		char* code = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
		sprintf(code, "%s[%s]", (yyvsp[-3].string), (yyvsp[-1].string));
		(yyval.string) = code;
	}
#line 2691 "out/myanalyzer.tab.c"
    break;

  case 99: /* expression: primary_expression DOT IDENTIFIER LPAREN arg_list RPAREN  */
#line 688 "myanalyzer.y"
                                                                   {
		char* code = malloc(strlen((yyvsp[-5].string)) + strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 8);
		sprintf(code, "%s.%s(%s)", (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string));
		(yyval.string) = code;
		free((yyvsp[-5].string)); free((yyvsp[-3].string)); free((yyvsp[-1].string));
	}
#line 2702 "out/myanalyzer.tab.c"
    break;

  case 100: /* expression: primary_expression DOT IDENTIFIER LPAREN RPAREN  */
#line 693 "myanalyzer.y"
                                                            {
		char* code = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + 8);
		sprintf(code, "%s.%s()", (yyvsp[-4].string), (yyvsp[-2].string));
		(yyval.string) = code;
		free((yyvsp[-4].string)); free((yyvsp[-2].string));
	}
#line 2713 "out/myanalyzer.tab.c"
    break;

  case 101: /* expression: expression LPAREN arg_list RPAREN  */
#line 699 "myanalyzer.y"
                                            {
		char* code = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
		sprintf(code, "%s(%s)", (yyvsp[-3].string), (yyvsp[-1].string));
		(yyval.string) = code;
		free((yyvsp[-3].string)); free((yyvsp[-1].string));
	}
#line 2724 "out/myanalyzer.tab.c"
    break;

  case 102: /* expression: expression LPAREN RPAREN  */
#line 704 "myanalyzer.y"
                                     {
		char* code = malloc(strlen((yyvsp[-2].string)) + 4);
		sprintf(code, "%s()", (yyvsp[-2].string));
		(yyval.string) = code;
		free((yyvsp[-2].string));
	}
#line 2735 "out/myanalyzer.tab.c"
    break;

  case 103: /* primary_expression: CONST_INT  */
#line 713 "myanalyzer.y"
              {
			char* code = malloc(strlen((yyvsp[0].string)) + 16);
			sprintf(code, "%s", (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2745 "out/myanalyzer.tab.c"
    break;

  case 104: /* primary_expression: CONST_FLOAT  */
#line 717 "myanalyzer.y"
                        {
			char* code = malloc(strlen((yyvsp[0].string)) + 16);
			sprintf(code, "%s", (yyvsp[0].string));
	}
#line 2754 "out/myanalyzer.tab.c"
    break;

  case 105: /* primary_expression: CONST_STRING  */
#line 720 "myanalyzer.y"
                         {
			char* code = malloc(strlen((yyvsp[0].string)) + 16);
			sprintf(code, "%s", (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2764 "out/myanalyzer.tab.c"
    break;

  case 106: /* primary_expression: CONST_BOOL_TRUE  */
#line 724 "myanalyzer.y"
                            {
			char* code = malloc(16);
			sprintf(code, "true");
			(yyval.string) = code;
	}
#line 2774 "out/myanalyzer.tab.c"
    break;

  case 107: /* primary_expression: CONST_BOOL_FALSE  */
#line 728 "myanalyzer.y"
                             {
			char* code = malloc(16);
			sprintf(code, "false");
			(yyval.string) = code;
	}
#line 2784 "out/myanalyzer.tab.c"
    break;

  case 108: /* primary_expression: IDENTIFIER  */
#line 732 "myanalyzer.y"
                       {
			char* code = malloc(strlen((yyvsp[0].string)) + 16);
			sprintf(code, "%s", (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2794 "out/myanalyzer.tab.c"
    break;

  case 109: /* primary_expression: HASH IDENTIFIER  */
#line 736 "myanalyzer.y"
                            {
			char* code = malloc(strlen((yyvsp[0].string)) + 2);
			sprintf(code, "#%s", (yyvsp[0].string));
			(yyval.string) = code;
	}
#line 2804 "out/myanalyzer.tab.c"
    break;

  case 110: /* primary_expression: IDENTIFIER LPAREN arg_list RPAREN  */
#line 740 "myanalyzer.y"
                                              {
			char* code = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
			sprintf(code, "%s(%s)", (yyvsp[-3].string), (yyvsp[-1].string));
			(yyval.string) = code;
			free((yyvsp[-3].string));
			free((yyvsp[-1].string));
	}
#line 2816 "out/myanalyzer.tab.c"
    break;

  case 111: /* primary_expression: IDENTIFIER LPAREN RPAREN  */
#line 746 "myanalyzer.y"
                                     {
			char* code = malloc(strlen((yyvsp[-2].string)) + 4);
			sprintf(code, "%s()", (yyvsp[-2].string));
			(yyval.string) = code;
			free((yyvsp[-2].string));
	}
#line 2827 "out/myanalyzer.tab.c"
    break;

  case 112: /* primary_expression: primary_expression DOT IDENTIFIER LPAREN arg_list RPAREN  */
#line 751 "myanalyzer.y"
                                                                     {
			char* code = malloc(strlen((yyvsp[-5].string)) + strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 8);
			sprintf(code, "%s.%s(%s)", (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string));
			(yyval.string) = code;
			free((yyvsp[-5].string)); free((yyvsp[-3].string)); free((yyvsp[-1].string));
	}
#line 2838 "out/myanalyzer.tab.c"
    break;

  case 113: /* primary_expression: primary_expression DOT IDENTIFIER LPAREN RPAREN  */
#line 756 "myanalyzer.y"
                                                            {
			char* code = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + 8);
			sprintf(code, "%s.%s()", (yyvsp[-4].string), (yyvsp[-2].string));
			(yyval.string) = code;
			free((yyvsp[-4].string)); free((yyvsp[-2].string));
	}
#line 2849 "out/myanalyzer.tab.c"
    break;

  case 114: /* block: decl_list stmt_list  */
#line 765 "myanalyzer.y"
                        {
        char* code = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
        sprintf(code, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
        (yyval.string) = add_indentation(code);
        free(code);
    }
#line 2860 "out/myanalyzer.tab.c"
    break;

  case 115: /* decl_list: %empty  */
#line 774 "myanalyzer.y"
                    { (yyval.string) = strdup(""); }
#line 2866 "out/myanalyzer.tab.c"
    break;

  case 116: /* decl_list: decl_list var_declaration  */
#line 775 "myanalyzer.y"
                              {
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			free((yyvsp[-1].string));
			free((yyvsp[0].string));
	}
#line 2878 "out/myanalyzer.tab.c"
    break;


#line 2882 "out/myanalyzer.tab.c"

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

#line 784 "myanalyzer.y"


int main() {
	return yyparse();
}
