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
	#include "myanalyzer.tab.h"

	extern int yylex();
	extern int yyparse();
	extern int line_number;
	extern FILE *yyin;

	extern char* find_macro(const char*);
	extern char *yytext; 

	#define YYABORT do { yyerror("Aborting"); return 1; } while (0)

	int indent_level = 0;
	int line_num = 1;

	int yydebug = 1;

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

	char* safe_strdup(const char* s) {
		char* new = strdup(s);
		if (!new) { yyerror("Memory allocation failed"); YYABORT; }
    	return new;
	}

	void safe_free(void* ptr) {
		if (ptr) free(ptr);
	}

	// Για την αποθήκευση defmacro αντικαταστάσεων
	typedef struct {
		char* name;
		char* replacement;
	} Macro;

	#define MAX_MACROS 100
	Macro macros[MAX_MACROS];
	int macro_count = 0;

	void add_macro(const char* name, const char* replacement) {

    fprintf(stderr, "Adding macro: %s -> %s\n", name, replacement);

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

    fprintf(stderr, "Added macro: %s -> %s\n", name, replacement);
    fprintf(stderr, "Total macros: %d\n", macro_count);
		if (macro_count >= MAX_MACROS) {
				fprintf(stderr, "Error: Too many macros defined\n");
				exit(1);
			}
	}

	char* find_macro(const char* name) {
		for (int i = macro_count - 1; i >= 0; --i) {
			if (strcmp(macros[i].name, name) == 0)
				return macros[i].replacement;
		}
		return NULL;
	}

#line 165 "out/myanalyzer.tab.c"

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
  YYSYMBOL_DECLARATION = 65,               /* DECLARATION  */
  YYSYMBOL_STMT = 66,                      /* STMT  */
  YYSYMBOL_NO_COMPARE = 67,                /* NO_COMPARE  */
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_program = 69,                   /* program  */
  YYSYMBOL_macro_def_list = 70,            /* macro_def_list  */
  YYSYMBOL_macro_def = 71,                 /* macro_def  */
  YYSYMBOL_top_level_list = 72,            /* top_level_list  */
  YYSYMBOL_top_level = 73,                 /* top_level  */
  YYSYMBOL_var_declaration = 74,           /* var_declaration  */
  YYSYMBOL_const_declaration = 75,         /* const_declaration  */
  YYSYMBOL_function = 76,                  /* function  */
  YYSYMBOL_param_list = 77,                /* param_list  */
  YYSYMBOL_param_decl_list = 78,           /* param_decl_list  */
  YYSYMBOL_main_function = 79,             /* main_function  */
  YYSYMBOL_stmt_list = 80,                 /* stmt_list  */
  YYSYMBOL_type = 81,                      /* type  */
  YYSYMBOL_stmt = 82,                      /* stmt  */
  YYSYMBOL_assignment_stmt = 83,           /* assignment_stmt  */
  YYSYMBOL_return_stmt = 84,               /* return_stmt  */
  YYSYMBOL_if_stmt = 85,                   /* if_stmt  */
  YYSYMBOL_for_stmt = 86,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 87,                /* while_stmt  */
  YYSYMBOL_break_stmt = 88,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 89,             /* continue_stmt  */
  YYSYMBOL_empty_stmt = 90,                /* empty_stmt  */
  YYSYMBOL_component = 91,                 /* component  */
  YYSYMBOL_component_body = 92,            /* component_body  */
  YYSYMBOL_component_member = 93,          /* component_member  */
  YYSYMBOL_hash_ident_list = 94,           /* hash_ident_list  */
  YYSYMBOL_ident_list = 95,                /* ident_list  */
  YYSYMBOL_expression = 96,                /* expression  */
  YYSYMBOL_function_call = 97,             /* function_call  */
  YYSYMBOL_arg_list = 98,                  /* arg_list  */
  YYSYMBOL_primary_expression = 99,        /* primary_expression  */
  YYSYMBOL_block = 100,                    /* block  */
  YYSYMBOL_decl_list = 101                 /* decl_list  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   513

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   160,   160,   166,   167,   180,   188,   189,   199,   202,
     205,   208,   211,   218,   226,   235,   243,   257,   269,   284,
     285,   289,   294,   303,   316,   317,   326,   327,   328,   329,
     330,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     348,   356,   368,   378,   388,   403,   416,   429,   435,   441,
     448,   459,   460,   471,   478,   486,   491,   492,   500,   501,
     509,   512,   521,   522,   526,   529,   532,   535,   538,   541,
     544,   547,   550,   553,   556,   559,   562,   565,   566,   567,
     568,   569,   573,   577,   585,   586,   587,   596,   597,   598,
     599,   600,   601,   602,   606,   617,   618
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
  "COMMA", "DOT", "OP_ARROW", "HASH", "UMINUS", "DECLARATION", "STMT",
  "NO_COMPARE", "$accept", "program", "macro_def_list", "macro_def",
  "top_level_list", "top_level", "var_declaration", "const_declaration",
  "function", "param_list", "param_decl_list", "main_function",
  "stmt_list", "type", "stmt", "assignment_stmt", "return_stmt", "if_stmt",
  "for_stmt", "while_stmt", "break_stmt", "continue_stmt", "empty_stmt",
  "component", "component_body", "component_member", "hash_ident_list",
  "ident_list", "expression", "function_call", "arg_list",
  "primary_expression", "block", "decl_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-95)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -124,    16,   -17,  -124,    26,  -124,   411,   135,   -29,    -3,
      47,    -2,    53,  -124,  -124,  -124,  -124,  -124,  -124,   -52,
      23,  -124,  -124,  -124,  -124,  -124,   135,   135,   135,   153,
     -38,  -124,   135,    44,    30,    37,    22,   235,    91,   135,
     257,  -124,   401,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,  -124,   135,    93,
     240,   135,    96,    51,  -124,  -124,  -124,  -124,  -124,  -124,
      59,  -124,   460,     3,  -124,   257,   343,    70,   167,   167,
     167,   167,   167,   167,    72,    72,    70,    70,    70,   327,
    -124,   235,   269,    68,    73,    67,    74,     1,  -124,  -124,
     135,  -124,    71,   235,   235,   -53,   128,  -124,    77,  -124,
     130,    86,  -124,  -124,  -124,    27,   460,  -124,    88,  -124,
    -124,   235,    94,   121,    75,  -124,  -124,   156,   235,   159,
    -124,   139,   110,   235,   111,  -124,    87,   116,   117,  -124,
     118,  -124,  -124,  -124,   122,   -28,   126,   180,   132,   129,
     131,   135,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   133,   136,  -124,  -124,   185,  -124,   135,     7,
     135,   169,   135,  -124,  -124,   182,  -124,   235,   151,   211,
    -124,    10,   415,   158,   446,  -124,   162,  -124,  -124,  -124,
     157,   135,   164,  -124,  -124,   298,  -124,    52,   135,    99,
     165,   181,   356,   183,  -124,  -124,   190,  -124,   134,  -124,
     184,   152,  -124,   191,  -124
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     6,     1,     0,     4,     0,     0,     0,    60,
       0,     0,     0,     7,    11,    12,     8,     9,    10,     0,
      90,    87,    88,    89,    81,    80,     0,     0,     0,     0,
      62,    15,     0,     0,     0,     0,     0,     0,     0,    84,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,    19,     0,    51,    30,    26,    27,    28,    29,
       0,    61,    85,     0,    79,    75,    76,    68,    69,    70,
      71,    72,    73,    74,    63,    64,    65,    66,    67,     0,
      93,     0,     0,     0,     0,    20,     0,     0,    13,    91,
       0,    92,     0,     0,     0,     0,     0,    95,     0,    58,
       0,     0,    56,    55,    52,     0,    86,    14,     0,    21,
      95,     0,     0,     0,     0,    57,    50,     0,     0,     0,
      16,     0,     0,     0,     0,    96,     0,     0,     0,    59,
       0,    95,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    25,    31,    32,    33,    34,    35,    36,
      37,    38,     0,     0,    53,    18,     0,    40,     0,    84,
       0,     0,     0,    47,    48,     0,    39,     0,     0,     0,
      83,     0,     0,     0,     0,    42,     0,    17,    41,    82,
       0,     0,     0,    54,    24,     0,    24,     0,     0,     0,
       0,     0,     0,     0,    24,    43,     0,    46,     0,    24,
       0,     0,    44,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,  -124,  -124,  -124,   115,  -124,   154,  -124,
    -124,  -124,  -123,   -69,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,    -7,  -124,
      80,  -124,  -117,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,    13,    14,    15,    16,    94,
      95,    17,   136,    70,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    18,    97,   114,   115,    19,    72,   162,
      73,    30,   123,   124
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    34,   108,   131,   109,   120,    37,   168,    38,   121,
      20,    21,    22,    23,    24,    25,     3,     4,    58,    40,
      41,    42,   102,    59,   166,    60,   169,    35,   110,     7,
      31,    26,    32,   111,   118,   119,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      33,    89,   132,   144,    92,   145,    36,    27,    99,   138,
     112,    28,   180,   100,   142,   189,   146,   200,   201,   147,
     100,   197,   148,   199,   149,   150,     8,    39,     9,    61,
      64,   208,   151,   127,    62,   128,   211,   129,   144,   -24,
     145,    63,   -24,   116,    71,   -24,    90,   -24,   -24,    93,
     144,   146,   145,   -24,   147,   -24,    96,   148,   186,   149,
     150,   152,    45,   146,    45,   -94,   147,   151,    98,   148,
     203,   149,   150,    54,    55,    56,   104,   106,   105,   151,
     117,   122,   107,    34,   -24,   144,   125,   145,    20,    21,
      22,    23,    24,    25,   175,   126,   152,   130,   146,   134,
     210,   147,   133,   144,   148,   145,   149,   150,   152,    26,
     137,   179,   139,   182,   151,   184,   146,   140,   141,   147,
     143,   213,   148,   163,   149,   150,   164,   165,    43,    44,
     170,   167,   151,   171,   195,    27,   172,   183,   173,    28,
     174,   202,   176,   152,   177,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    43,    44,    45,
     187,   152,    57,   178,   191,   194,    52,    53,    54,    55,
      56,   193,   196,   204,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    43,    44,    65,   135,
     205,   185,   207,   212,    66,    67,    68,    69,   209,   181,
     214,   113,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    43,    44,     0,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    43,    44,     0,     0,    91,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    43,    44,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    43,    44,     0,     0,   198,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    43,    44,     0,   101,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,    -2,     8,   206,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
      43,    44,    12,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,    74,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
     190,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,   192,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
       7,     3,     1,   120,     3,    58,    58,    35,    60,    62,
       3,     4,     5,     6,     7,     8,     0,    34,    56,    26,
      27,    28,    91,    61,   141,    32,    54,    29,    27,     3,
      59,    24,    35,    32,   103,   104,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       3,    58,   121,     1,    61,     3,     3,    50,    55,   128,
      59,    54,    55,    60,   133,    55,    14,    15,    16,    17,
      60,   194,    20,   196,    22,    23,     1,    54,     3,    35,
      58,   204,    30,    56,    54,    58,   209,    60,     1,    14,
       3,    54,    17,   100,     3,    20,     3,    22,    23,     3,
       1,    14,     3,    28,    17,    30,    55,    20,   177,    22,
      23,    59,    42,    14,    42,    28,    17,    30,    59,    20,
      21,    22,    23,    51,    52,    53,    58,    60,    55,    30,
      59,     3,    58,     3,    59,     1,    59,     3,     3,     4,
       5,     6,     7,     8,   151,    59,    59,    59,    14,    28,
      16,    17,    58,     1,    20,     3,    22,    23,    59,    24,
       4,   168,     3,   170,    30,   172,    14,    28,    58,    17,
      59,    19,    20,    57,    22,    23,    59,    59,    25,    26,
      54,    59,    30,     3,   191,    50,    54,    18,    59,    54,
      59,   198,    59,    59,    58,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    25,    26,    42,
      59,    59,    59,    28,    56,    58,    49,    50,    51,    52,
      53,    59,    58,    58,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    25,    26,     3,   124,
      59,    59,    59,    59,     9,    10,    11,    12,    58,   169,
      59,    97,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    25,    26,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    25,    26,    -1,    -1,    58,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    25,    26,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    25,    26,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    25,    26,    -1,    57,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,     0,     1,    57,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      25,    26,    31,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    69,    70,     0,    34,    71,    72,     3,     1,     3,
      13,    27,    31,    73,    74,    75,    76,    79,    91,    95,
       3,     4,     5,     6,     7,     8,    24,    50,    54,    96,
      99,    59,    35,     3,     3,    29,     3,    58,    60,    54,
      96,    96,    96,    25,    26,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    59,    56,    61,
      96,    35,    54,    54,    58,     3,     9,    10,    11,    12,
      81,     3,    96,    98,    55,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
       3,    58,    96,     3,    77,    78,    55,    92,    59,    55,
      60,    57,    81,    58,    58,    55,    60,    58,     1,     3,
      27,    32,    59,    76,    93,    94,    96,    59,    81,    81,
      58,    62,     3,   100,   101,    59,    59,    56,    58,    60,
      59,   100,    81,    58,    28,    74,    80,     4,    81,     3,
      28,    58,    81,    59,     1,     3,    14,    17,    20,    22,
      23,    30,    59,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    97,    57,    59,    59,   100,    59,    35,    54,
      54,     3,    54,    59,    59,    96,    59,    58,    28,    96,
      55,    98,    96,    18,    96,    59,    81,    59,    59,    55,
      55,    56,    55,    59,    58,    96,    58,    80,    58,    80,
      15,    16,    96,    21,    58,    59,    57,    59,    80,    58,
      16,    80,    59,    19,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    74,    75,    76,    76,    77,
      77,    78,    78,    79,    80,    80,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    84,    85,    85,    86,    87,    88,    89,    90,
      91,    92,    92,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    98,    98,    98,    99,    99,    99,
      99,    99,    99,    99,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     4,     0,     2,     1,     1,
       1,     1,     1,     4,     6,     2,     7,    11,     9,     0,
       1,     3,     5,     8,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     3,     8,    11,    12,     8,     2,     2,     1,
       6,     0,     2,     4,     7,     1,     1,     2,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       1,     1,     4,     3,     0,     1,     3,     1,     1,     1,
       1,     4,     4,     3,     2,     0,     2
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
#line 160 "myanalyzer.y"
                                  {
        printf("%s", (yyvsp[0].string));
    }
#line 1464 "out/myanalyzer.tab.c"
    break;

  case 3: /* macro_def_list: %empty  */
#line 166 "myanalyzer.y"
                { (yyval.string) = safe_strdup("");}
#line 1470 "out/myanalyzer.tab.c"
    break;

  case 4: /* macro_def_list: macro_def_list macro_def  */
#line 167 "myanalyzer.y"
                               {
			fprintf(stderr, "Macro definition: %s\n", (yyvsp[-1].string));
			(yyval.string) = (yyvsp[-1].string);
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			free((yyvsp[-1].string));
			free((yyvsp[0].string));

		}
#line 1485 "out/myanalyzer.tab.c"
    break;

  case 5: /* macro_def: KW_DEFMACRO IDENTIFIER expression SEMICOLON  */
#line 180 "myanalyzer.y"
                                                {
    fprintf(stderr, "Macro defined: %s\n", (yyvsp[-2].string));
    add_macro((yyvsp[-2].string), (yyvsp[-1].string));
    (yyval.string) = safe_strdup("");
	}
#line 1495 "out/myanalyzer.tab.c"
    break;

  case 6: /* top_level_list: %empty  */
#line 188 "myanalyzer.y"
                { (yyval.string) = safe_strdup(""); }
#line 1501 "out/myanalyzer.tab.c"
    break;

  case 7: /* top_level_list: top_level_list top_level  */
#line 189 "myanalyzer.y"
                              {
			fprintf(stderr, "Top level: %s\n", (yyvsp[-1].string));
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			free((yyvsp[-1].string)); safe_free((yyvsp[0].string));
		}
#line 1513 "out/myanalyzer.tab.c"
    break;

  case 8: /* top_level: function  */
#line 199 "myanalyzer.y"
                 {
		fprintf(stderr, "Function: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1522 "out/myanalyzer.tab.c"
    break;

  case 9: /* top_level: main_function  */
#line 202 "myanalyzer.y"
                          {
		fprintf(stderr, "Main function: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1531 "out/myanalyzer.tab.c"
    break;

  case 10: /* top_level: component  */
#line 205 "myanalyzer.y"
                      {
		fprintf(stderr, "Component: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1540 "out/myanalyzer.tab.c"
    break;

  case 11: /* top_level: var_declaration  */
#line 208 "myanalyzer.y"
                            {
		fprintf(stderr, "Variable declaration: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1549 "out/myanalyzer.tab.c"
    break;

  case 12: /* top_level: const_declaration  */
#line 211 "myanalyzer.y"
                              {
		fprintf(stderr, "Constant declaration: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1558 "out/myanalyzer.tab.c"
    break;

  case 13: /* var_declaration: ident_list COLON type SEMICOLON  */
#line 218 "myanalyzer.y"
                                        {
		fprintf(stderr, "Processing declaration: %s of type %s\n", (yyvsp[-3].string), (yyvsp[-1].string));
		char* decl = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
		free((yyvsp[-3].string));
		free((yyvsp[-1].string));
	}
#line 1572 "out/myanalyzer.tab.c"
    break;

  case 14: /* var_declaration: IDENTIFIER OP_ASSIGN expression COLON type SEMICOLON  */
#line 226 "myanalyzer.y"
                                                                 {
		fprintf(stderr, "Processing initialized declaration: %s = %s of type %s\n", (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string));
		char* decl = malloc(strlen((yyvsp[-5].string)) + strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s = %s;\n", (yyvsp[-1].string), (yyvsp[-5].string), (yyvsp[-3].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
		free((yyvsp[-5].string));
		free((yyvsp[-3].string));
		free((yyvsp[-1].string));
	}
#line 1587 "out/myanalyzer.tab.c"
    break;

  case 15: /* var_declaration: error SEMICOLON  */
#line 235 "myanalyzer.y"
                            {
		yyerror("Invalid variable declaration");
		yyerrok;
		(yyval.string) = safe_strdup("/* BAD DECLARATION */\n");
	}
#line 1597 "out/myanalyzer.tab.c"
    break;

  case 16: /* const_declaration: KW_CONST IDENTIFIER OP_ASSIGN expression COLON type SEMICOLON  */
#line 243 "myanalyzer.y"
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
#line 1613 "out/myanalyzer.tab.c"
    break;

  case 17: /* function: KW_DEF IDENTIFIER LPAREN param_list RPAREN OP_ARROW type COLON block KW_ENDDEF SEMICOLON  */
#line 257 "myanalyzer.y"
                                                                                             {
        fprintf(stderr, "Function with return: %s\n", (yyvsp[-9].string));

        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;

        char* code = malloc(strlen(body) + 64);
        sprintf(code, "%s %s(%s) {\n%s}\n", (yyvsp[-4].string), (yyvsp[-9].string), (yyvsp[-7].string), body);
        safe_free(body);
        (yyval.string) = code;
    }
#line 1630 "out/myanalyzer.tab.c"
    break;

  case 18: /* function: KW_DEF IDENTIFIER LPAREN param_list RPAREN COLON block KW_ENDDEF SEMICOLON  */
#line 269 "myanalyzer.y"
                                                                               {
        fprintf(stderr, "Function with no return: %s\n", (yyvsp[-7].string));

        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;

        char* code = malloc(strlen(body) + 64);
        sprintf(code, "void %s(%s) {\n%s}\n", (yyvsp[-7].string), (yyvsp[-5].string), body);
        safe_free(body);
        (yyval.string) = code;
    }
#line 1647 "out/myanalyzer.tab.c"
    break;

  case 19: /* param_list: %empty  */
#line 284 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 1653 "out/myanalyzer.tab.c"
    break;

  case 20: /* param_list: param_decl_list  */
#line 285 "myanalyzer.y"
                          { fprintf(stderr, "Param list %s\n", (yyvsp[0].string));  (yyval.string) = (yyvsp[0].string); }
#line 1659 "out/myanalyzer.tab.c"
    break;

  case 21: /* param_decl_list: IDENTIFIER COLON type  */
#line 289 "myanalyzer.y"
                          {
			fprintf(stderr, "Param: %s\n", (yyvsp[-2].string));

			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf((yyval.string), "%s %s", (yyvsp[0].string), (yyvsp[-2].string));
    }
#line 1670 "out/myanalyzer.tab.c"
    break;

  case 22: /* param_decl_list: param_decl_list COMMA IDENTIFIER COLON type  */
#line 294 "myanalyzer.y"
                                                    {
			fprintf(stderr, "Param: %s\n", (yyvsp[-2].string));

			char* tmp = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf(tmp, "%s, %s %s", (yyvsp[-4].string), (yyvsp[0].string), (yyvsp[-2].string));
			(yyval.string) = tmp;
    }
#line 1682 "out/myanalyzer.tab.c"
    break;

  case 23: /* main_function: KW_DEF KW_MAIN LPAREN RPAREN COLON block KW_ENDDEF SEMICOLON  */
#line 303 "myanalyzer.y"
                                                                 {
        fprintf(stderr, "Main function\n");
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen(body) + 64);
        sprintf(code, "int main() {\n%s}\n", body);
        safe_free(body);
        (yyval.string) = code;
    }
#line 1697 "out/myanalyzer.tab.c"
    break;

  case 24: /* stmt_list: %empty  */
#line 316 "myanalyzer.y"
                { (yyval.string) = safe_strdup(""); }
#line 1703 "out/myanalyzer.tab.c"
    break;

  case 25: /* stmt_list: stmt_list stmt  */
#line 317 "myanalyzer.y"
                     {
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			free((yyvsp[-1].string)); free((yyvsp[0].string));
    }
#line 1714 "out/myanalyzer.tab.c"
    break;

  case 26: /* type: KW_INTEGER  */
#line 326 "myanalyzer.y"
                { (yyval.string) = safe_strdup("int"); }
#line 1720 "out/myanalyzer.tab.c"
    break;

  case 27: /* type: KW_SCALAR  */
#line 327 "myanalyzer.y"
                { (yyval.string) = safe_strdup("float"); }
#line 1726 "out/myanalyzer.tab.c"
    break;

  case 28: /* type: KW_STR  */
#line 328 "myanalyzer.y"
                { (yyval.string) = safe_strdup("char*"); }
#line 1732 "out/myanalyzer.tab.c"
    break;

  case 29: /* type: KW_BOOL  */
#line 329 "myanalyzer.y"
                { (yyval.string) = safe_strdup("bool"); }
#line 1738 "out/myanalyzer.tab.c"
    break;

  case 30: /* type: IDENTIFIER  */
#line 330 "myanalyzer.y"
                { (yyval.string) = safe_strdup((yyvsp[0].string)); safe_free((yyvsp[0].string));}
#line 1744 "out/myanalyzer.tab.c"
    break;

  case 39: /* stmt: function_call SEMICOLON  */
#line 342 "myanalyzer.y"
                            {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + 3);
		sprintf(tmp, "%s;\n", (yyvsp[-1].string));
		(yyval.string) = add_indentation(tmp);
		free(tmp);
		free((yyvsp[-1].string));
}
#line 1756 "out/myanalyzer.tab.c"
    break;

  case 40: /* stmt: error SEMICOLON  */
#line 348 "myanalyzer.y"
                    { 
		yyerror("Invalid statement");
		yyerrok;
		(yyval.string) = safe_strdup("/* ERROR */\n"); 
	}
#line 1766 "out/myanalyzer.tab.c"
    break;

  case 41: /* assignment_stmt: IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 356 "myanalyzer.y"
                                              {
        fprintf(stderr, "Matched assignment: %s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
        (yyval.string) = safe_strdup(line);
        safe_free(line);
        safe_free((yyvsp[-3].string));
        safe_free((yyvsp[-1].string));
    }
#line 1780 "out/myanalyzer.tab.c"
    break;

  case 42: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 368 "myanalyzer.y"
                                   {
        fprintf(stderr, "Returning: %s\n", (yyvsp[-1].string));
        char* line = malloc(strlen((yyvsp[-1].string)) + 16);
        sprintf(line, "return %s;\n", (yyvsp[-1].string));
        (yyval.string) = add_indentation(line);
        safe_free(line);
    }
#line 1792 "out/myanalyzer.tab.c"
    break;

  case 43: /* if_stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON  */
#line 378 "myanalyzer.y"
                                                                      {
        fprintf(stderr, "If statement: %s\n", (yyvsp[-5].string));
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-5].string)) + strlen(body) + 64);
        sprintf(code, "if (%s) {\n%s}\n", (yyvsp[-5].string), body);
        (yyval.string) = code;
        safe_free(body);
    }
#line 1807 "out/myanalyzer.tab.c"
    break;

  case 44: /* if_stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ELSE COLON stmt_list KW_ENDIF SEMICOLON  */
#line 388 "myanalyzer.y"
                                                                                              {
        indent_level++;
        char* then_part = add_indentation((yyvsp[-5].string));
        char* else_part = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-8].string)) + strlen(then_part) + strlen(else_part) + 128);
        fprintf(stderr, "If-else statement: %s\n", (yyvsp[-8].string));
        sprintf(code, "if (%s) {\n%s} else {\n%s}\n", (yyvsp[-8].string), then_part, else_part);
        (yyval.string) = code;
        safe_free(then_part);
        safe_free(else_part);
    }
#line 1824 "out/myanalyzer.tab.c"
    break;

  case 45: /* for_stmt: KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON  */
#line 403 "myanalyzer.y"
                                                                                                              {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        char* code = malloc(strlen((yyvsp[-10].string)) + strlen((yyvsp[-7].string)) + strlen((yyvsp[-5].string)) + strlen(body) + 128);
        fprintf(stderr, "For loop: %s\n", (yyvsp[-10].string));
        sprintf(code, "for (int %s = %s; %s < %s; ++%s) {\n%s}\n", (yyvsp[-10].string), (yyvsp[-7].string), (yyvsp[-10].string), (yyvsp[-5].string), (yyvsp[-10].string), body);
        (yyval.string) = code;
        safe_free(body);
    }
#line 1839 "out/myanalyzer.tab.c"
    break;

  case 46: /* while_stmt: KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON  */
#line 416 "myanalyzer.y"
                                                                            {
        indent_level++;
        char* body = add_indentation((yyvsp[-2].string));
        indent_level--;
        fprintf(stderr, "While loop: %s\n", (yyvsp[-5].string));
        char* code = malloc(strlen((yyvsp[-5].string)) + strlen(body) + 64);
        sprintf(code, "while (%s) {\n%s}\n", (yyvsp[-5].string), body);
        (yyval.string) = code;
        safe_free(body);
    }
#line 1854 "out/myanalyzer.tab.c"
    break;

  case 47: /* break_stmt: KW_BREAK SEMICOLON  */
#line 429 "myanalyzer.y"
                       {
        (yyval.string) = add_indentation("break;\n");
    }
#line 1862 "out/myanalyzer.tab.c"
    break;

  case 48: /* continue_stmt: KW_CONTINUE SEMICOLON  */
#line 435 "myanalyzer.y"
                          {
        (yyval.string) = add_indentation("continue;\n");
    }
#line 1870 "out/myanalyzer.tab.c"
    break;

  case 49: /* empty_stmt: SEMICOLON  */
#line 441 "myanalyzer.y"
              {
        (yyval.string) = safe_strdup(";");
    }
#line 1878 "out/myanalyzer.tab.c"
    break;

  case 50: /* component: KW_COMP IDENTIFIER COLON component_body KW_ENDCOMP SEMICOLON  */
#line 448 "myanalyzer.y"
                                                                 {
				fprintf(stderr, "Component: %s\n", (yyvsp[-4].string));

				char* code = malloc(strlen((yyvsp[-4].string)) + 16);
				sprintf(code, "struct %s {\n%s};\n", (yyvsp[-4].string), (yyvsp[-2].string));
				(yyval.string) = add_indentation(code);
				free(code);
		}
#line 1891 "out/myanalyzer.tab.c"
    break;

  case 51: /* component_body: %empty  */
#line 459 "myanalyzer.y"
                { (yyval.string) = safe_strdup(""); }
#line 1897 "out/myanalyzer.tab.c"
    break;

  case 52: /* component_body: component_body component_member  */
#line 460 "myanalyzer.y"
                                    {
			fprintf(stderr, "Component member: %s\n", (yyvsp[0].string));

			char* code = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 16);
			sprintf(code, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = code;
			free(code);
	}
#line 1910 "out/myanalyzer.tab.c"
    break;

  case 53: /* component_member: hash_ident_list COLON type SEMICOLON  */
#line 471 "myanalyzer.y"
                                             {
		char* decl = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
		free((yyvsp[-3].string));
		free((yyvsp[-1].string));
	}
#line 1923 "out/myanalyzer.tab.c"
    break;

  case 54: /* component_member: hash_ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON  */
#line 478 "myanalyzer.y"
                                                                             {
		char* decl = malloc(strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s[%s];\n", (yyvsp[-1].string), (yyvsp[-6].string), (yyvsp[-4].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
		free((yyvsp[-6].string));
		free((yyvsp[-4].string));
		free((yyvsp[-1].string));
	}
#line 1937 "out/myanalyzer.tab.c"
    break;

  case 55: /* component_member: function  */
#line 486 "myanalyzer.y"
                     {
		char* decl = malloc(strlen((yyvsp[0].string)) + 16);
		sprintf(decl, "%s", (yyvsp[0].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
	}
#line 1948 "out/myanalyzer.tab.c"
    break;

  case 56: /* component_member: SEMICOLON  */
#line 491 "myanalyzer.y"
                      { (yyval.string) = safe_strdup(""); 
	}
#line 1955 "out/myanalyzer.tab.c"
    break;

  case 57: /* component_member: error SEMICOLON  */
#line 492 "myanalyzer.y"
                            {
		yyerror("Invalid variable declaration");
		yyerrok;
		(yyval.string) = safe_strdup("/* BAD DECLARATION */\n");
	}
#line 1965 "out/myanalyzer.tab.c"
    break;

  case 58: /* hash_ident_list: IDENTIFIER  */
#line 500 "myanalyzer.y"
                 { (yyval.string) = safe_strdup((yyvsp[0].string)); }
#line 1971 "out/myanalyzer.tab.c"
    break;

  case 59: /* hash_ident_list: hash_ident_list COMMA IDENTIFIER  */
#line 501 "myanalyzer.y"
                                           {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
		sprintf(tmp, "%s, %s", (yyvsp[-2].string), (yyvsp[0].string)); // No # inserted
		(yyval.string) = tmp;
	}
#line 1981 "out/myanalyzer.tab.c"
    break;

  case 60: /* ident_list: IDENTIFIER  */
#line 509 "myanalyzer.y"
                   {
		(yyval.string) = safe_strdup((yyvsp[0].string));
		safe_free((yyvsp[0].string));
	}
#line 1990 "out/myanalyzer.tab.c"
    break;

  case 61: /* ident_list: ident_list COMMA IDENTIFIER  */
#line 512 "myanalyzer.y"
                                        {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s, %s", (yyvsp[-2].string), (yyvsp[0].string));
			(yyval.string) = tmp;
	}
#line 2000 "out/myanalyzer.tab.c"
    break;

  case 62: /* expression: primary_expression  */
#line 521 "myanalyzer.y"
                       { (yyval.string) = safe_strdup((yyvsp[0].string)); safe_free((yyvsp[0].string)); }
#line 2006 "out/myanalyzer.tab.c"
    break;

  case 63: /* expression: expression OP_PLUS expression  */
#line 522 "myanalyzer.y"
                                  { 
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s + %s", (yyvsp[-2].string), (yyvsp[0].string));  // Fixed sprintf
			safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2016 "out/myanalyzer.tab.c"
    break;

  case 64: /* expression: expression OP_MINUS expression  */
#line 526 "myanalyzer.y"
                                                 {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s - %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2025 "out/myanalyzer.tab.c"
    break;

  case 65: /* expression: expression OP_MULT expression  */
#line 529 "myanalyzer.y"
                                          { 
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s * %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2034 "out/myanalyzer.tab.c"
    break;

  case 66: /* expression: expression OP_DIV expression  */
#line 532 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s / %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2043 "out/myanalyzer.tab.c"
    break;

  case 67: /* expression: expression OP_MOD expression  */
#line 535 "myanalyzer.y"
                                         { 
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s %% %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2052 "out/myanalyzer.tab.c"
    break;

  case 68: /* expression: expression OP_POW expression  */
#line 538 "myanalyzer.y"
                                                      {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s ^ %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2061 "out/myanalyzer.tab.c"
    break;

  case 69: /* expression: expression OP_EQ expression  */
#line 541 "myanalyzer.y"
                                        { 
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s == %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2070 "out/myanalyzer.tab.c"
    break;

  case 70: /* expression: expression OP_NEQ expression  */
#line 544 "myanalyzer.y"
                                         { 
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s != %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2079 "out/myanalyzer.tab.c"
    break;

  case 71: /* expression: expression OP_LT expression  */
#line 547 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s < %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2088 "out/myanalyzer.tab.c"
    break;

  case 72: /* expression: expression OP_LEQ expression  */
#line 550 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s <= %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2097 "out/myanalyzer.tab.c"
    break;

  case 73: /* expression: expression OP_GT expression  */
#line 553 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s > %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2106 "out/myanalyzer.tab.c"
    break;

  case 74: /* expression: expression OP_GEQ expression  */
#line 556 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s >= %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2115 "out/myanalyzer.tab.c"
    break;

  case 75: /* expression: expression KW_AND expression  */
#line 559 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 6);
			sprintf((yyval.string), "%s && %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2124 "out/myanalyzer.tab.c"
    break;

  case 76: /* expression: expression KW_OR expression  */
#line 562 "myanalyzer.y"
                                        { 
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			sprintf((yyval.string), "%s || %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2133 "out/myanalyzer.tab.c"
    break;

  case 77: /* expression: KW_NOT expression  */
#line 565 "myanalyzer.y"
                                           { (yyval.string) = (yyvsp[0].string); }
#line 2139 "out/myanalyzer.tab.c"
    break;

  case 78: /* expression: OP_MINUS expression  */
#line 566 "myanalyzer.y"
                                     { (yyval.string) = (yyvsp[0].string); }
#line 2145 "out/myanalyzer.tab.c"
    break;

  case 79: /* expression: LPAREN expression RPAREN  */
#line 567 "myanalyzer.y"
                             { (yyval.string) = (yyvsp[-1].string); }
#line 2151 "out/myanalyzer.tab.c"
    break;

  case 80: /* expression: CONST_BOOL_FALSE  */
#line 568 "myanalyzer.y"
                     { (yyval.string) = safe_strdup("false"); }
#line 2157 "out/myanalyzer.tab.c"
    break;

  case 81: /* expression: CONST_BOOL_TRUE  */
#line 569 "myanalyzer.y"
                          { (yyval.string) = safe_strdup("true"); }
#line 2163 "out/myanalyzer.tab.c"
    break;

  case 82: /* function_call: IDENTIFIER LPAREN arg_list RPAREN  */
#line 573 "myanalyzer.y"
                                          {
		(yyval.string) = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
		sprintf((yyval.string), "%s(%s)", (yyvsp[-3].string), (yyvsp[-1].string));
		free((yyvsp[-3].string)); free((yyvsp[-1].string));
	}
#line 2173 "out/myanalyzer.tab.c"
    break;

  case 83: /* function_call: IDENTIFIER LPAREN RPAREN  */
#line 577 "myanalyzer.y"
                                     {
		(yyval.string) = malloc(strlen((yyvsp[-2].string)) + 3);
		sprintf((yyval.string), "%s()", (yyvsp[-2].string));
		free((yyvsp[-2].string));
	}
#line 2183 "out/myanalyzer.tab.c"
    break;

  case 84: /* arg_list: %empty  */
#line 585 "myanalyzer.y"
                { (yyval.string) = safe_strdup(""); }
#line 2189 "out/myanalyzer.tab.c"
    break;

  case 85: /* arg_list: expression  */
#line 586 "myanalyzer.y"
               { (yyval.string) = safe_strdup((yyvsp[0].string)); safe_free((yyvsp[0].string)); }
#line 2195 "out/myanalyzer.tab.c"
    break;

  case 86: /* arg_list: arg_list COMMA expression  */
#line 587 "myanalyzer.y"
                              {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s,%s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = tmp;
		safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2206 "out/myanalyzer.tab.c"
    break;

  case 91: /* primary_expression: IDENTIFIER LPAREN arg_list RPAREN  */
#line 600 "myanalyzer.y"
                                      { /* function call */ }
#line 2212 "out/myanalyzer.tab.c"
    break;

  case 92: /* primary_expression: primary_expression LBRACKET expression RBRACKET  */
#line 601 "myanalyzer.y"
                                                    { /* array access */ }
#line 2218 "out/myanalyzer.tab.c"
    break;

  case 93: /* primary_expression: primary_expression DOT IDENTIFIER  */
#line 602 "myanalyzer.y"
                                      { /* member access */ }
#line 2224 "out/myanalyzer.tab.c"
    break;

  case 94: /* block: decl_list stmt_list  */
#line 606 "myanalyzer.y"
                            {
		fprintf(stderr, "Processing block:\nDeclarations: %s\nStatements: %s\n", (yyvsp[-1].string), (yyvsp[0].string));
		char* code = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(code, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
		(yyval.string) = add_indentation(code);
		free(code);
		free((yyvsp[-1].string)); free((yyvsp[0].string));
	}
#line 2237 "out/myanalyzer.tab.c"
    break;

  case 95: /* decl_list: %empty  */
#line 617 "myanalyzer.y"
                { (yyval.string) = safe_strdup(""); }
#line 2243 "out/myanalyzer.tab.c"
    break;

  case 96: /* decl_list: decl_list var_declaration  */
#line 618 "myanalyzer.y"
                                {
        char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
        sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
        (yyval.string) = tmp;
        free((yyvsp[-1].string)); free((yyvsp[0].string));
    }
#line 2254 "out/myanalyzer.tab.c"
    break;


#line 2258 "out/myanalyzer.tab.c"

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

#line 626 "myanalyzer.y"


int main() {
	yydebug = 1;
	return yyparse();
}

// void yyerror(const char *pat, ...) {
//     va_list args;
//     va_start(args, pat);
//     vfprintf(stderr, pat, args);
//     va_end(args);
//     fprintf(stderr, "\n");
// }
