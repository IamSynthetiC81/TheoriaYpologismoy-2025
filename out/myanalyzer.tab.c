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
	#include <setjmp.h>

	extern int yylex(void);
	extern int yyparse();
	extern int line_number;
	extern FILE *yyin;

	extern char* find_macro(const char*);
	extern char *yytext;

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

char *safe_strdup(const char *str) {
	if (!str) return NULL;
	char *new = strdup(str);
	if (!new) {
			yyerror("Memory allocation failed");
			exit(1);
	}
	return new;
}

void safe_free(void* ptr) {
	if (ptr) free(ptr);
}

char * includes = "#include \"lambdalib.h\"\n#include <stdbool.h>";

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
			safe_free(macros[i].replacement);
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

// void yyerror(const char *fmt, ...) {
// 	va_list args;
// 	va_start(args, fmt);
// 	fprintf(stderr, "Parse error: ");
// 	vfprintf(stderr, fmt, args);
// 	fprintf(stderr, "\n");
// 	va_end(args);
// }


#line 182 "out/myanalyzer.tab.c"

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
  YYSYMBOL_DECL_IDENT = 64,                /* DECL_IDENT  */
  YYSYMBOL_UMINUS = 65,                    /* UMINUS  */
  YYSYMBOL_DECLARATION = 66,               /* DECLARATION  */
  YYSYMBOL_STMT = 67,                      /* STMT  */
  YYSYMBOL_NO_COMPARE = 68,                /* NO_COMPARE  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_program = 70,                   /* program  */
  YYSYMBOL_macro_def_list = 71,            /* macro_def_list  */
  YYSYMBOL_macro_def = 72,                 /* macro_def  */
  YYSYMBOL_top_level_list = 73,            /* top_level_list  */
  YYSYMBOL_top_level = 74,                 /* top_level  */
  YYSYMBOL_var_declaration = 75,           /* var_declaration  */
  YYSYMBOL_const_declaration = 76,         /* const_declaration  */
  YYSYMBOL_function = 77,                  /* function  */
  YYSYMBOL_param_list = 78,                /* param_list  */
  YYSYMBOL_param_decl_list = 79,           /* param_decl_list  */
  YYSYMBOL_main_function = 80,             /* main_function  */
  YYSYMBOL_stmt_list = 81,                 /* stmt_list  */
  YYSYMBOL_type = 82,                      /* type  */
  YYSYMBOL_stmt = 83,                      /* stmt  */
  YYSYMBOL_assignment_stmt = 84,           /* assignment_stmt  */
  YYSYMBOL_return_stmt = 85,               /* return_stmt  */
  YYSYMBOL_if_stmt = 86,                   /* if_stmt  */
  YYSYMBOL_for_stmt = 87,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 88,                /* while_stmt  */
  YYSYMBOL_break_stmt = 89,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 90,             /* continue_stmt  */
  YYSYMBOL_empty_stmt = 91,                /* empty_stmt  */
  YYSYMBOL_component = 92,                 /* component  */
  YYSYMBOL_component_body = 93,            /* component_body  */
  YYSYMBOL_component_member = 94,          /* component_member  */
  YYSYMBOL_hash_ident_list = 95,           /* hash_ident_list  */
  YYSYMBOL_ident_list = 96,                /* ident_list  */
  YYSYMBOL_expression = 97,                /* expression  */
  YYSYMBOL_function_call = 98,             /* function_call  */
  YYSYMBOL_arg_list = 99,                  /* arg_list  */
  YYSYMBOL_primary_expression = 100,       /* primary_expression  */
  YYSYMBOL_block = 101                     /* block  */
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
#define YYLAST   878

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   179,   179,   185,   186,   199,   212,   213,   223,   226,
     229,   233,   237,   244,   253,   266,   280,   291,   306,   307,
     311,   316,   326,   339,   340,   349,   350,   351,   352,   353,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   371,
     379,   387,   395,   401,   402,   409,   417,   431,   446,   452,
     459,   469,   484,   498,   511,   517,   523,   530,   541,   542,
     553,   560,   568,   573,   574,   582,   586,   595,   599,   608,
     609,   613,   616,   619,   622,   625,   628,   631,   634,   637,
     640,   643,   646,   649,   652,   653,   654,   655,   656,   665,
     673,   674,   675,   684,   685,   686,   687,   688,   690,   694,
     698,   702,   703,   709
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
  "COMMA", "DOT", "OP_ARROW", "HASH", "DECL_IDENT", "UMINUS",
  "DECLARATION", "STMT", "NO_COMPARE", "$accept", "program",
  "macro_def_list", "macro_def", "top_level_list", "top_level",
  "var_declaration", "const_declaration", "function", "param_list",
  "param_decl_list", "main_function", "stmt_list", "type", "stmt",
  "assignment_stmt", "return_stmt", "if_stmt", "for_stmt", "while_stmt",
  "break_stmt", "continue_stmt", "empty_stmt", "component",
  "component_body", "component_member", "hash_ident_list", "ident_list",
  "expression", "function_call", "arg_list", "primary_expression", "block", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -214,    11,   -11,  -214,    23,  -214,    59,   116,   -23,    33,
       6,    50,  -214,  -214,  -214,  -214,  -214,  -214,    31,     9,
    -214,  -214,  -214,  -214,  -214,   116,   116,   116,    61,   825,
    -214,   -48,    69,    48,    43,    58,    56,   202,    84,   116,
     609,  -214,   766,  -214,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   112,
      71,   116,   113,    63,  -214,  -214,  -214,  -214,  -214,  -214,
      70,  -214,   825,   -43,  -214,   609,   666,    88,    97,    97,
      97,    97,    97,    97,    91,    91,    88,    88,    88,   650,
    -214,    76,   592,    77,    82,    78,    83,    29,  -214,  -214,
     116,  -214,   202,   202,   202,   -33,   148,  -214,    93,   150,
      95,  -214,   152,  -214,  -214,    22,   825,   101,   103,  -214,
    -214,   202,    98,   171,  -214,  -214,  -214,   160,   202,   102,
    -214,  -214,   215,   109,   202,   110,    40,   114,   170,   126,
     122,   123,   124,   350,  -214,   181,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,   128,   -34,   132,   131,
     189,   136,  -214,  -214,  -214,   116,   372,   379,   116,   179,
     116,  -214,  -214,  -214,  -214,   447,   163,  -214,   116,   142,
    -214,  -214,  -214,   243,   476,   116,   418,    71,   679,   780,
     146,   811,  -214,   116,   708,   202,   144,  -214,   406,   202,
    -214,   172,   159,   116,   164,   505,   173,   147,  -214,   207,
     165,   116,  -214,   621,  -214,  -214,   116,  -214,   167,  -214,
     534,    54,   116,   278,   563,    99,  -214,    44,   168,   169,
    -214,   737,   174,  -214,   166,   209,   116,  -214,  -214,   178,
    -214,   182,   228,   306,  -214,   202,   206,   183,   329,   191,
     237,  -214,   192,  -214,   195,  -214,   196,   202,   194,  -214
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     6,     1,     0,     4,     2,     0,    67,     0,
       0,     0,     7,    11,    12,     8,     9,    10,     0,    96,
      93,    94,    95,    88,    87,     0,     0,     0,     0,     5,
      97,    69,     0,     0,     0,     0,     0,     0,     0,    90,
      84,    85,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    58,    29,    25,    26,    27,    28,
       0,    68,    91,     0,    86,    82,    83,    75,    76,    77,
      78,    79,    80,    81,    70,    71,    72,    73,    74,     0,
      99,     0,     0,     0,     0,    19,     0,     0,    13,    89,
       0,    98,     0,     0,     0,     0,     0,   101,     0,     0,
       0,    63,     0,    62,    59,     0,    92,     0,     0,    20,
     101,     0,     0,     0,    64,    57,    65,     0,     0,     0,
      14,    15,     0,     0,     0,     0,    67,     0,     0,     0,
       0,     0,     0,     0,    56,     0,   102,   103,    30,    31,
      32,    33,    34,    35,    36,    37,    97,     0,     0,     0,
       0,     0,   101,    21,    40,     0,     0,     0,     0,     0,
       0,    54,    55,    22,    49,     0,   100,    38,     0,     0,
      60,    66,    17,     0,     0,     0,     0,    93,     0,     0,
       0,     0,    48,     0,     0,     0,     0,    41,     0,     0,
      44,     0,     0,     0,     0,     0,    98,     0,    16,     0,
       0,     0,    23,     0,    23,    39,     0,    61,     0,    45,
       0,     0,     0,     0,     0,     0,    42,    96,     0,     0,
      24,     0,     0,    43,     0,     0,     0,    23,    50,     0,
      53,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    51,     0,    46,     0,    52,     0,     0,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,  -214,  -214,  -214,   249,  -214,   161,  -214,
    -214,  -214,  -213,  -100,  -118,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,    -7,  -117,
    -214,  -116,  -110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,    12,   146,    14,    15,    94,
      95,    16,   221,    70,   230,   148,   149,   150,   151,   152,
     153,   154,   155,    17,    97,   114,   115,    18,   188,    30,
      73,    31,   123
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   223,   117,   118,   119,   147,   156,   157,    58,    34,
     132,     3,    99,    59,   147,   156,   157,   100,    40,    41,
      42,   133,   178,     4,   243,   120,     7,    59,   159,   121,
     108,   248,    72,    32,   163,    35,    33,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   183,    36,    92,   135,   109,   227,    20,    21,
      22,   110,     8,    39,    43,   147,   156,   157,   137,   228,
     229,   138,     9,    60,   139,   165,   140,   141,   127,   165,
     128,   166,   129,    61,   143,   166,    10,    71,   111,    37,
      11,    38,   112,   116,    39,   207,   167,    62,    39,   210,
     236,   -96,    65,   234,   156,   157,   156,   157,    66,    67,
      68,    69,    63,   144,    64,    90,    93,   145,    96,    19,
      20,    21,    22,    23,    24,   235,   156,   157,    91,    98,
      46,   156,   157,    46,   102,   104,   175,   105,   106,    46,
      25,   107,    55,    56,    57,   249,    53,    54,    55,    56,
      57,   122,   124,    34,   125,   126,   134,   258,   184,   186,
     130,   189,   131,   191,   158,   160,    26,   162,   168,   164,
      27,   194,   135,   169,   136,    20,    21,    22,   198,    28,
     170,   171,   172,   173,   176,   137,   205,   177,   138,   179,
     180,   139,   181,   140,   141,   182,   213,   190,   193,   142,
     195,   143,   203,   208,   220,    65,   217,   211,   216,   224,
     218,    66,    67,    68,    69,   231,   135,   212,   136,    20,
      21,    22,   214,   241,   219,   225,   237,   242,   238,   137,
     144,   246,   138,   240,   145,   139,   244,   140,   141,   250,
     245,   254,   251,   161,   135,   143,   136,    20,    21,    22,
     253,   255,   256,   259,   257,    13,     0,   137,   113,     0,
     138,     0,     0,   139,     0,   140,   141,     0,     0,     0,
       0,   196,     0,   143,   144,     0,     0,     0,   145,   135,
       0,   227,    20,    21,    22,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,   138,     0,     0,   139,   232,
     140,   141,   144,     0,     0,     0,   145,   135,   143,   227,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
     137,     0,   247,   138,     0,     0,   139,     0,   140,   141,
     135,     0,   227,    20,    21,    22,   143,   144,     0,     0,
       0,   145,     0,   137,     0,     0,   138,     0,   252,   139,
       0,   140,   141,    19,    20,    21,    22,    23,    24,   143,
       0,     0,     0,     0,     0,   144,     0,     0,     0,   145,
       0,     0,     0,     0,    25,    19,    20,    21,    22,    23,
      24,     0,    19,   187,    21,    22,    23,    24,   144,     0,
       0,     0,   145,     0,     0,     0,    25,     0,     0,     0,
      26,     0,     0,    25,    27,     0,     0,     0,     0,   174,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    26,   209,     0,     0,    27,     0,   185,    26,
       0,    44,    45,    27,     0,    28,     0,     0,     0,     0,
       0,     0,    28,    44,    45,     0,     0,     0,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    44,    45,     0,     0,   199,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    44,    45,     0,     0,     0,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      44,    45,     0,     0,     0,   197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    44,
      45,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    44,    45,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    44,    45,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    44,    45,     0,     0,
     103,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    44,    45,     0,     0,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    44,    45,     0,   101,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    44,    45,     0,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    44,    45,     0,   206,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    44,    45,     0,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,     0,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,    74,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,   202,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,     0,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,   204,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57
};

static const yytype_int16 yycheck[] =
{
       7,   214,   102,   103,   104,   123,   123,   123,    56,     3,
     120,     0,    55,    61,   132,   132,   132,    60,    25,    26,
      27,   121,    56,    34,   237,    58,     3,    61,   128,    62,
       1,   244,    39,    56,   134,    29,     3,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,   162,     3,    61,     1,    27,     3,     4,     5,
       6,    32,     3,    54,     3,   183,   183,   183,    14,    15,
      16,    17,    13,     4,    20,    35,    22,    23,    56,    35,
      58,    41,    60,    35,    30,    41,    27,     3,    59,    58,
      31,    60,    63,   100,    54,   195,    56,    54,    54,   199,
      56,    61,     3,     4,   221,   221,   223,   223,     9,    10,
      11,    12,    54,    59,    58,     3,     3,    63,    55,     3,
       4,     5,     6,     7,     8,   225,   243,   243,    57,    59,
      42,   248,   248,    42,    58,    58,   143,    55,    60,    42,
      24,    58,    51,    52,    53,   245,    49,    50,    51,    52,
      53,     3,    59,     3,    59,     3,    58,   257,   165,   166,
      59,   168,    59,   170,     4,    63,    50,    58,    54,    59,
      54,   178,     1,     3,     3,     4,     5,     6,   185,    63,
      54,    59,    59,    59,     3,    14,   193,    59,    17,    57,
      59,    20,     3,    22,    23,    59,   203,    18,    35,    28,
      58,    30,    56,    59,   211,     3,    59,    35,    35,   216,
       3,     9,    10,    11,    12,   222,     1,    58,     3,     4,
       5,     6,    58,    57,    59,    58,    58,    18,    59,    14,
      59,     3,    17,    59,    63,    20,    58,    22,    23,    33,
      58,     4,    59,    28,     1,    30,     3,     4,     5,     6,
      59,    59,    57,    59,    58,     6,    -1,    14,    97,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    -1,    30,    59,    -1,    -1,    -1,    63,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    17,    -1,    -1,    20,    21,
      22,    23,    59,    -1,    -1,    -1,    63,     1,    30,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    16,    17,    -1,    -1,    20,    -1,    22,    23,
       1,    -1,     3,     4,     5,     6,    30,    59,    -1,    -1,
      -1,    63,    -1,    14,    -1,    -1,    17,    -1,    19,    20,
      -1,    22,    23,     3,     4,     5,     6,     7,     8,    30,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    24,     3,     4,     5,     6,     7,
       8,    -1,     3,     4,     5,     6,     7,     8,    59,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      50,    -1,    -1,    24,    54,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    17,    -1,    -1,    54,    -1,    56,    50,
      -1,    25,    26,    54,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    25,    26,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    25,    26,    -1,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    25,    26,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      25,    26,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    25,
      26,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    25,    26,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    25,    26,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    25,    26,    -1,    -1,
      58,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    25,    26,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    25,    26,    -1,    57,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    25,    26,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    25,    26,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    25,    26,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    70,    71,     0,    34,    72,    73,     3,     3,    13,
      27,    31,    74,    75,    76,    77,    80,    92,    96,     3,
       4,     5,     6,     7,     8,    24,    50,    54,    63,    97,
      98,   100,    56,     3,     3,    29,     3,    58,    60,    54,
      97,    97,    97,     3,    25,    26,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    56,    61,
       4,    35,    54,    54,    58,     3,     9,    10,    11,    12,
      82,     3,    97,    99,    55,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
       3,    57,    97,     3,    78,    79,    55,    93,    59,    55,
      60,    57,    58,    58,    58,    55,    60,    58,     1,    27,
      32,    59,    63,    77,    94,    95,    97,    82,    82,    82,
      58,    62,     3,   101,    59,    59,     3,    56,    58,    60,
      59,    59,   101,    82,    58,     1,     3,    14,    17,    20,
      22,    23,    28,    30,    59,    63,    75,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    98,   100,     4,    82,
      63,    28,    58,    82,    59,    35,    41,    56,    54,     3,
      54,    59,    59,    59,    59,    97,     3,    59,    56,    57,
      59,     3,    59,   101,    97,    56,    97,     4,    97,    97,
      18,    97,    59,    35,    97,    58,    28,    59,    97,    58,
      59,    57,    55,    56,    55,    97,    57,    82,    59,    17,
      82,    35,    58,    97,    58,    59,    35,    59,     3,    59,
      97,    81,    58,    81,    97,    58,    59,     3,    15,    16,
      83,    97,    21,    59,     4,    82,    56,    58,    59,    57,
      59,    57,    18,    81,    58,    58,     3,    16,    81,    82,
      33,    59,    19,    59,     4,    59,    57,    58,    82,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    73,    73,    74,    74,
      74,    74,    74,    75,    75,    76,    77,    77,    78,    78,
      79,    79,    80,    81,    81,    82,    82,    82,    82,    82,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      86,    86,    87,    88,    89,    90,    91,    92,    93,    93,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     0,     2,     1,     1,
       1,     1,     1,     4,     7,     7,    11,     9,     0,     1,
       3,     5,     8,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     5,
       2,     4,     7,     7,     4,     6,    12,    16,     3,     2,
       8,    11,    12,     8,     2,     2,     1,     6,     0,     2,
       4,     7,     1,     1,     2,     2,     4,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     1,     4,
       0,     1,     3,     1,     1,     1,     1,     1,     4,     3,
       2,     0,     2,     2
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
#line 179 "myanalyzer.y"
                                      {
		printf("%s\n%s%s",includes, (yyvsp[-1].string), (yyvsp[0].string));
	}
#line 1568 "out/myanalyzer.tab.c"
    break;

  case 3: /* macro_def_list: %empty  */
#line 185 "myanalyzer.y"
                            { (yyval.string) = safe_strdup("");}
#line 1574 "out/myanalyzer.tab.c"
    break;

  case 4: /* macro_def_list: macro_def_list macro_def  */
#line 186 "myanalyzer.y"
                                           {
			fprintf(stderr, "Macro definition: %s\n", (yyvsp[-1].string));
			(yyval.string) = (yyvsp[-1].string);
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			safe_free((yyvsp[-1].string));
			safe_free((yyvsp[0].string));

		}
#line 1589 "out/myanalyzer.tab.c"
    break;

  case 5: /* macro_def: KW_DEFMACRO IDENTIFIER expression  */
#line 199 "myanalyzer.y"
                                                  {
		fprintf(stderr, "Macro defined: %s\n", (yyvsp[-1].string));
		add_macro((yyvsp[-1].string), (yyvsp[0].string));
		char* macro_code = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 16);
		sprintf(macro_code, "#define %s %s\n", (yyvsp[-1].string), (yyvsp[0].string));
		(yyval.string) = add_indentation(macro_code);
		safe_free(macro_code);
		safe_free((yyvsp[-1].string));
		safe_free((yyvsp[0].string));
	}
#line 1604 "out/myanalyzer.tab.c"
    break;

  case 6: /* top_level_list: %empty  */
#line 212 "myanalyzer.y"
                            { (yyval.string) = safe_strdup(""); }
#line 1610 "out/myanalyzer.tab.c"
    break;

  case 7: /* top_level_list: top_level_list top_level  */
#line 213 "myanalyzer.y"
                                          {
			fprintf(stderr, "Top level: %s\n", (yyvsp[-1].string));
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			safe_free((yyvsp[-1].string)); safe_free((yyvsp[0].string));
		}
#line 1622 "out/myanalyzer.tab.c"
    break;

  case 8: /* top_level: function  */
#line 223 "myanalyzer.y"
                 {
		fprintf(stderr, "Function: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1631 "out/myanalyzer.tab.c"
    break;

  case 9: /* top_level: main_function  */
#line 226 "myanalyzer.y"
                          {
		fprintf(stderr, "Main function: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1640 "out/myanalyzer.tab.c"
    break;

  case 10: /* top_level: component  */
#line 229 "myanalyzer.y"
                      {
		fprintf(stderr, "Component: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1649 "out/myanalyzer.tab.c"
    break;

  case 11: /* top_level: var_declaration  */
#line 233 "myanalyzer.y"
                          {
		fprintf(stderr, "Variable declaration: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1658 "out/myanalyzer.tab.c"
    break;

  case 12: /* top_level: const_declaration  */
#line 237 "myanalyzer.y"
                            {
		fprintf(stderr, "Constant declaration: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1667 "out/myanalyzer.tab.c"
    break;

  case 13: /* var_declaration: ident_list COLON type SEMICOLON  */
#line 244 "myanalyzer.y"
                                        {
	// $1 is the variable name, $3 is the type
	fprintf(stderr, "Processing declaration: %s of type %s\n", (yyvsp[-3].string), (yyvsp[-1].string));
	char* decl = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
	sprintf(decl, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
	(yyval.string) = add_indentation(decl);
	safe_free(decl);
	safe_free((yyvsp[-3].string));
	safe_free((yyvsp[-1].string));
}
#line 1682 "out/myanalyzer.tab.c"
    break;

  case 14: /* var_declaration: IDENTIFIER LBRACKET CONST_INT RBRACKET COLON type SEMICOLON  */
#line 253 "myanalyzer.y"
                                                                {
	// $1 = variable name, $3 = array size, $6 = type
	char* decl = malloc(strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 16);
	sprintf(decl, "%s %s[%s];\n", (yyvsp[-1].string), (yyvsp[-6].string), (yyvsp[-4].string));
	(yyval.string) = add_indentation(decl);
	safe_free(decl);
	safe_free((yyvsp[-6].string));
	safe_free((yyvsp[-4].string));
	safe_free((yyvsp[-1].string));
}
#line 1697 "out/myanalyzer.tab.c"
    break;

  case 15: /* const_declaration: KW_CONST IDENTIFIER OP_ASSIGN expression COLON type SEMICOLON  */
#line 266 "myanalyzer.y"
                                                                              {
				fprintf(stderr, "Constant declaration: %s = %s\n", (yyvsp[-5].string), (yyvsp[-3].string));

				char* decl = malloc(strlen((yyvsp[-5].string)) + strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
				sprintf(decl, "const %s %s = %s;\n", (yyvsp[-1].string), (yyvsp[-5].string), (yyvsp[-3].string));
				(yyval.string) = add_indentation(decl);
				safe_free(decl);
				safe_free((yyvsp[-5].string));
				safe_free((yyvsp[-3].string));
				safe_free((yyvsp[-1].string));
		}
#line 1713 "out/myanalyzer.tab.c"
    break;

  case 16: /* function: KW_DEF IDENTIFIER LPAREN param_list RPAREN OP_ARROW type COLON block KW_ENDDEF SEMICOLON  */
#line 280 "myanalyzer.y"
                                                                                                 {
		fprintf(stderr, "Function with return: %s\n", (yyvsp[-9].string));

		indent_level++;
		char* body = add_indentation((yyvsp[-2].string));
		indent_level--;

		char* code = malloc(strlen(body) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-9].string)) + strlen((yyvsp[-7].string)) +  64);
		sprintf(code, "%s %s(%s) {\n%s}\n", (yyvsp[-4].string), (yyvsp[-9].string), (yyvsp[-7].string), body);
		safe_free(body);
		(yyval.string) = code;
	}
#line 1730 "out/myanalyzer.tab.c"
    break;

  case 17: /* function: KW_DEF IDENTIFIER LPAREN param_list RPAREN COLON block KW_ENDDEF SEMICOLON  */
#line 291 "myanalyzer.y"
                                                                                       {
		fprintf(stderr, "Function with no return: %s\n", (yyvsp[-7].string));

		indent_level++;
		char* body = add_indentation((yyvsp[-2].string));
		indent_level--;

		char* code = malloc(strlen(body) +strlen((yyvsp[-7].string))+strlen((yyvsp[-5].string)) + 64);
		sprintf(code, "void %s(%s) {\n%s}\n", (yyvsp[-7].string), (yyvsp[-5].string), body);
		safe_free(body);
		(yyval.string) = code;
	}
#line 1747 "out/myanalyzer.tab.c"
    break;

  case 18: /* param_list: %empty  */
#line 306 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 1753 "out/myanalyzer.tab.c"
    break;

  case 19: /* param_list: param_decl_list  */
#line 307 "myanalyzer.y"
                          { fprintf(stderr, "Param list %s\n", (yyvsp[0].string));  (yyval.string) = (yyvsp[0].string); }
#line 1759 "out/myanalyzer.tab.c"
    break;

  case 20: /* param_decl_list: IDENTIFIER COLON type  */
#line 311 "myanalyzer.y"
                                      {
			fprintf(stderr, "Param: %s\n", (yyvsp[-2].string));

			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf((yyval.string), "%s %s", (yyvsp[0].string), (yyvsp[-2].string));
		}
#line 1770 "out/myanalyzer.tab.c"
    break;

  case 21: /* param_decl_list: param_decl_list COMMA IDENTIFIER COLON type  */
#line 316 "myanalyzer.y"
                                                                {
			fprintf(stderr, "Param: %s\n", (yyvsp[-2].string));

			char* tmp = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf(tmp, "%s, %s %s", (yyvsp[-4].string), (yyvsp[0].string), (yyvsp[-2].string));
			(yyval.string) = tmp;
			safe_free((yyvsp[-4].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
		}
#line 1783 "out/myanalyzer.tab.c"
    break;

  case 22: /* main_function: KW_DEF KW_MAIN LPAREN RPAREN COLON block KW_ENDDEF SEMICOLON  */
#line 326 "myanalyzer.y"
                                                                     {
		fprintf(stderr, "Main function\n");
		indent_level++;
		char* body = add_indentation((yyvsp[-2].string));
		indent_level--;
		char* code = malloc(strlen(body) + 64);
		sprintf(code, "int main() {\n%s};\n", body);
		safe_free(body);
		(yyval.string) = code;
	}
#line 1798 "out/myanalyzer.tab.c"
    break;

  case 23: /* stmt_list: %empty  */
#line 339 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 1804 "out/myanalyzer.tab.c"
    break;

  case 24: /* stmt_list: stmt_list stmt  */
#line 340 "myanalyzer.y"
                         {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
		(yyval.string) = tmp;
		safe_free((yyvsp[-1].string)); safe_free((yyvsp[0].string));
	}
#line 1815 "out/myanalyzer.tab.c"
    break;

  case 25: /* type: KW_INTEGER  */
#line 349 "myanalyzer.y"
                            { (yyval.string) = safe_strdup("int"); }
#line 1821 "out/myanalyzer.tab.c"
    break;

  case 26: /* type: KW_SCALAR  */
#line 350 "myanalyzer.y"
                      { (yyval.string) = safe_strdup("float"); }
#line 1827 "out/myanalyzer.tab.c"
    break;

  case 27: /* type: KW_STR  */
#line 351 "myanalyzer.y"
                      { (yyval.string) = safe_strdup("char*"); }
#line 1833 "out/myanalyzer.tab.c"
    break;

  case 28: /* type: KW_BOOL  */
#line 352 "myanalyzer.y"
                      { (yyval.string) = safe_strdup("bool"); }
#line 1839 "out/myanalyzer.tab.c"
    break;

  case 29: /* type: IDENTIFIER  */
#line 353 "myanalyzer.y"
                      { (yyval.string) = safe_strdup((yyvsp[0].string)); safe_free((yyvsp[0].string));}
#line 1845 "out/myanalyzer.tab.c"
    break;

  case 38: /* stmt: function_call SEMICOLON  */
#line 365 "myanalyzer.y"
                                  {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + 3);
		sprintf(tmp, "%s;\n", (yyvsp[-1].string));
		(yyval.string) = add_indentation(tmp);
		// free(tmp);
		safe_free((yyvsp[-1].string));
	}
#line 1857 "out/myanalyzer.tab.c"
    break;

  case 39: /* stmt: HASH IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 371 "myanalyzer.y"
                                                           {
    // Assignment to a struct field
    char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
    sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
    (yyval.string) = add_indentation(line);
    safe_free(line);
    safe_free((yyvsp[-3].string));
    safe_free((yyvsp[-1].string));
	}
#line 1871 "out/myanalyzer.tab.c"
    break;

  case 40: /* stmt: error SEMICOLON  */
#line 379 "myanalyzer.y"
                            {
		yyerror("Invalid statement");
		yyerrok;
		(yyval.string) = safe_strdup("/* ERROR */\n");
	}
#line 1881 "out/myanalyzer.tab.c"
    break;

  case 41: /* assignment_stmt: IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 387 "myanalyzer.y"
                                                  {
		fprintf(stderr, "Matched assignment: %s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
		char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
		(yyval.string) = safe_strdup(line);
		safe_free(line);
		safe_free((yyvsp[-3].string));
		safe_free((yyvsp[-1].string));
	}
#line 1895 "out/myanalyzer.tab.c"
    break;

  case 42: /* assignment_stmt: IDENTIFIER LBRACKET expression RBRACKET OP_ASSIGN expression SEMICOLON  */
#line 395 "myanalyzer.y"
                                                                                   {
			// $1 = array name, $3 = index, $6 = value
			char* line = malloc(strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 16);
			sprintf(line, "%s[%s] = %s;\n", (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-1].string));
			(yyval.string) = add_indentation(line);
			safe_free(line); safe_free((yyvsp[-6].string)); safe_free((yyvsp[-4].string)); safe_free((yyvsp[-1].string));
	}
#line 1907 "out/myanalyzer.tab.c"
    break;

  case 43: /* assignment_stmt: primary_expression LBRACKET expression RBRACKET OP_ASSIGN expression SEMICOLON  */
#line 401 "myanalyzer.y"
                                                                                          {
	}
#line 1914 "out/myanalyzer.tab.c"
    break;

  case 44: /* assignment_stmt: IDENTIFIER OP_DEFINE expression SEMICOLON  */
#line 402 "myanalyzer.y"
                                                      {
		char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
		(yyval.string) = safe_strdup(line);
		safe_free(line);
		safe_free((yyvsp[-3].string));
		safe_free((yyvsp[-1].string));
	}
#line 1927 "out/myanalyzer.tab.c"
    break;

  case 45: /* assignment_stmt: IDENTIFIER OP_DEFINE expression COLON type SEMICOLON  */
#line 409 "myanalyzer.y"
                                                                 {
		char* line = malloc(strlen((yyvsp[-5].string)) + strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 32);
		sprintf(line, "%s = %s; // type: %s\n", (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string));
		(yyval.string) = safe_strdup(line);
		safe_free(line);
		safe_free((yyvsp[-5].string));
		safe_free((yyvsp[-3].string));
		safe_free((yyvsp[-1].string));
	}
#line 1941 "out/myanalyzer.tab.c"
    break;

  case 46: /* assignment_stmt: IDENTIFIER OP_DEFINE LBRACKET expression KW_FOR IDENTIFIER COLON CONST_INT RBRACKET COLON type SEMICOLON  */
#line 417 "myanalyzer.y"
                                                                                                                     {
		// new_array := [expr for elm:size] : new_type;
		char* code = malloc(strlen((yyvsp[-11].string)) + strlen((yyvsp[-8].string)) + strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 256);
		// $1 is the variable name, $4 is the expression, $6 is the loop variable, $8 is the size, $11 is the type

		fprintf(stderr, "New array: %s of size %s with type %s\n", (yyvsp[-11].string), (yyvsp[-4].string), (yyvsp[-1].string));
		
		sprintf(code,
				"%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s = 0; %s < %s; ++%s) {\n    %s[%s] = %s;\n}\n",
				(yyvsp[-1].string), (yyvsp[-11].string), (yyvsp[-1].string), (yyvsp[-4].string), (yyvsp[-1].string), (yyvsp[-6].string), (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-6].string), (yyvsp[-11].string), (yyvsp[-6].string), (yyvsp[-8].string)
		);
		(yyval.string) = add_indentation(code);
		safe_free((yyvsp[-11].string)); safe_free((yyvsp[-8].string)); safe_free((yyvsp[-6].string)); safe_free((yyvsp[-4].string)); safe_free((yyvsp[-1].string)); 

	}
#line 1961 "out/myanalyzer.tab.c"
    break;

  case 47: /* assignment_stmt: IDENTIFIER OP_DEFINE LBRACKET expression KW_FOR IDENTIFIER COLON type KW_IN IDENTIFIER KW_OF CONST_INT RBRACKET COLON type SEMICOLON  */
#line 431 "myanalyzer.y"
                                                                                                                                                 {
		// new_array := [expr for elm:type in array of size] : new_type;
		char* code = malloc(strlen((yyvsp[-15].string))*2 + strlen((yyvsp[-10].string))*2 + strlen((yyvsp[-4].string))*2 + strlen((yyvsp[-1].string))*3 + 256);
		// $1 is the variable name, $12 is the size, $15 is the type

		sprintf(code,
			"%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s = 0; %s < %s; ++%s) {\n    %s[%s] = %s;\n}\n",
			(yyvsp[-1].string), (yyvsp[-15].string), (yyvsp[-1].string), (yyvsp[-4].string), (yyvsp[-1].string), (yyvsp[-10].string), (yyvsp[-10].string), (yyvsp[-4].string), (yyvsp[-10].string), (yyvsp[-15].string), (yyvsp[-10].string), (yyvsp[-12].string)
		);
		(yyval.string) = add_indentation(code);
		safe_free((yyvsp[-15].string)); safe_free((yyvsp[-12].string)); safe_free((yyvsp[-10].string)); safe_free((yyvsp[-4].string)); safe_free((yyvsp[-1].string));
	}
#line 1978 "out/myanalyzer.tab.c"
    break;

  case 48: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 446 "myanalyzer.y"
                                               {
				fprintf(stderr, "Returning: %s\n", (yyvsp[-1].string));
				char* line = malloc(strlen((yyvsp[-1].string)) + 16);
				sprintf(line, "return %s;\n", (yyvsp[-1].string));
				(yyval.string) = add_indentation(line);
				safe_free(line);
		}
#line 1990 "out/myanalyzer.tab.c"
    break;

  case 49: /* return_stmt: KW_RETURN SEMICOLON  */
#line 452 "myanalyzer.y"
                                        {
			fprintf(stderr, "Returning void\n");
			(yyval.string) = add_indentation("return;\n");
    }
#line 1999 "out/myanalyzer.tab.c"
    break;

  case 50: /* if_stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON  */
#line 459 "myanalyzer.y"
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
#line 2014 "out/myanalyzer.tab.c"
    break;

  case 51: /* if_stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ELSE COLON stmt_list KW_ENDIF SEMICOLON  */
#line 469 "myanalyzer.y"
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
#line 2031 "out/myanalyzer.tab.c"
    break;

  case 52: /* for_stmt: KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON  */
#line 484 "myanalyzer.y"
                                                                                                                  {
			indent_level++;
			// char* body = add_indentation($10);
			indent_level--;
			char* code = malloc(strlen((yyvsp[-10].string))*3 + strlen((yyvsp[-7].string)) + strlen((yyvsp[-5].string)) + strlen((yyvsp[-2].string)) + 128);
			fprintf(stderr, "For loop: %s\n", (yyvsp[-10].string));
			sprintf(code, "for (int %s = %s; %s < %s; %s++) {\n\t%s\n}\n",
				(yyvsp[-10].string), (yyvsp[-7].string), (yyvsp[-10].string), (yyvsp[-5].string), (yyvsp[-10].string),(yyvsp[-2].string) );
			(yyval.string) = code;
			safe_free((yyvsp[-10].string)); safe_free((yyvsp[-7].string)); safe_free((yyvsp[-5].string)); safe_free((yyvsp[-2].string));
	}
#line 2047 "out/myanalyzer.tab.c"
    break;

  case 53: /* while_stmt: KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON  */
#line 498 "myanalyzer.y"
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
#line 2062 "out/myanalyzer.tab.c"
    break;

  case 54: /* break_stmt: KW_BREAK SEMICOLON  */
#line 511 "myanalyzer.y"
                                   {
				(yyval.string) = add_indentation("break;\n");
		}
#line 2070 "out/myanalyzer.tab.c"
    break;

  case 55: /* continue_stmt: KW_CONTINUE SEMICOLON  */
#line 517 "myanalyzer.y"
                                      {
				(yyval.string) = add_indentation("continue;\n");
		}
#line 2078 "out/myanalyzer.tab.c"
    break;

  case 56: /* empty_stmt: SEMICOLON  */
#line 523 "myanalyzer.y"
                          {
				(yyval.string) = safe_strdup(";");
		}
#line 2086 "out/myanalyzer.tab.c"
    break;

  case 57: /* component: KW_COMP IDENTIFIER COLON component_body KW_ENDCOMP SEMICOLON  */
#line 530 "myanalyzer.y"
                                                                             {
				fprintf(stderr, "Component: %s\n", (yyvsp[-4].string));

				char* code = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + 16);
				sprintf(code, "struct %s {\n%s};\n", (yyvsp[-4].string), (yyvsp[-2].string));
				(yyval.string) = add_indentation(code);
				// free(code);
		}
#line 2099 "out/myanalyzer.tab.c"
    break;

  case 58: /* component_body: %empty  */
#line 541 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 2105 "out/myanalyzer.tab.c"
    break;

  case 59: /* component_body: component_body component_member  */
#line 542 "myanalyzer.y"
                                          {
		fprintf(stderr, "Component member: %s\n", (yyvsp[0].string));
		char* code = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(code, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
		(yyval.string) = code;
		safe_free((yyvsp[-1].string));
		safe_free((yyvsp[0].string));
	}
#line 2118 "out/myanalyzer.tab.c"
    break;

  case 60: /* component_member: hash_ident_list COLON type SEMICOLON  */
#line 553 "myanalyzer.y"
                                             {
		char* decl = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
		(yyval.string) = add_indentation(decl);
		// safe_free(decl);
		safe_free((yyvsp[-3].string));
		safe_free((yyvsp[-1].string));
	}
#line 2131 "out/myanalyzer.tab.c"
    break;

  case 61: /* component_member: hash_ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON  */
#line 560 "myanalyzer.y"
                                                                             {
		char* decl = malloc(strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s[%s];\n", (yyvsp[-1].string), (yyvsp[-6].string), (yyvsp[-4].string));
		(yyval.string) = add_indentation(decl);
		// safe_free(decl);
		safe_free((yyvsp[-6].string));
		safe_free((yyvsp[-4].string));
		safe_free((yyvsp[-1].string));
	}
#line 2145 "out/myanalyzer.tab.c"
    break;

  case 62: /* component_member: function  */
#line 568 "myanalyzer.y"
                     {
		char* decl = malloc(strlen((yyvsp[0].string)) + 16);
		sprintf(decl, "%s", (yyvsp[0].string));
		(yyval.string) = add_indentation(decl);
		// free(decl);
	}
#line 2156 "out/myanalyzer.tab.c"
    break;

  case 63: /* component_member: SEMICOLON  */
#line 573 "myanalyzer.y"
                      { (yyval.string) = safe_strdup("");
	}
#line 2163 "out/myanalyzer.tab.c"
    break;

  case 64: /* component_member: error SEMICOLON  */
#line 574 "myanalyzer.y"
                            {
		yyerror("Invalid variable declaration");
		yyerrok;
		(yyval.string) = safe_strdup("/* BAD DECLARATION */\n");
	}
#line 2173 "out/myanalyzer.tab.c"
    break;

  case 65: /* hash_ident_list: HASH IDENTIFIER  */
#line 582 "myanalyzer.y"
                        { 
		// Prepend # to the identifier for C struct fields if needed, or just use the name
		(yyval.string) = safe_strdup((yyvsp[0].string)); 
		safe_free((yyvsp[0].string));
	}
#line 2183 "out/myanalyzer.tab.c"
    break;

  case 66: /* hash_ident_list: hash_ident_list COMMA HASH IDENTIFIER  */
#line 586 "myanalyzer.y"
                                                  {
		char* tmp = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[0].string)) + 4);
		sprintf(tmp, "%s, %s", (yyvsp[-3].string), (yyvsp[0].string));
		(yyval.string) = tmp;
		safe_free((yyvsp[-3].string)); safe_free((yyvsp[0].string));
	}
#line 2194 "out/myanalyzer.tab.c"
    break;

  case 67: /* ident_list: IDENTIFIER  */
#line 595 "myanalyzer.y"
                   {
		(yyval.string) = safe_strdup((yyvsp[0].string));
		safe_free((yyvsp[0].string));
	}
#line 2203 "out/myanalyzer.tab.c"
    break;

  case 68: /* ident_list: ident_list COMMA IDENTIFIER  */
#line 599 "myanalyzer.y"
                                      {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s, %s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = tmp;
	}
#line 2213 "out/myanalyzer.tab.c"
    break;

  case 69: /* expression: primary_expression  */
#line 608 "myanalyzer.y"
                                   { (yyval.string) = safe_strdup((yyvsp[0].string)); safe_free((yyvsp[0].string)); }
#line 2219 "out/myanalyzer.tab.c"
    break;

  case 70: /* expression: expression OP_PLUS expression  */
#line 609 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s + %s", (yyvsp[-2].string), (yyvsp[0].string));
			safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2229 "out/myanalyzer.tab.c"
    break;

  case 71: /* expression: expression OP_MINUS expression  */
#line 613 "myanalyzer.y"
                                                 {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s - %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2238 "out/myanalyzer.tab.c"
    break;

  case 72: /* expression: expression OP_MULT expression  */
#line 616 "myanalyzer.y"
                                          {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s * %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2247 "out/myanalyzer.tab.c"
    break;

  case 73: /* expression: expression OP_DIV expression  */
#line 619 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s / %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2256 "out/myanalyzer.tab.c"
    break;

  case 74: /* expression: expression OP_MOD expression  */
#line 622 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s %% %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2265 "out/myanalyzer.tab.c"
    break;

  case 75: /* expression: expression OP_POW expression  */
#line 625 "myanalyzer.y"
                                                      {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s ^ %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2274 "out/myanalyzer.tab.c"
    break;

  case 76: /* expression: expression OP_EQ expression  */
#line 628 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s == %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2283 "out/myanalyzer.tab.c"
    break;

  case 77: /* expression: expression OP_NEQ expression  */
#line 631 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s != %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2292 "out/myanalyzer.tab.c"
    break;

  case 78: /* expression: expression OP_LT expression  */
#line 634 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s < %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2301 "out/myanalyzer.tab.c"
    break;

  case 79: /* expression: expression OP_LEQ expression  */
#line 637 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s <= %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2310 "out/myanalyzer.tab.c"
    break;

  case 80: /* expression: expression OP_GT expression  */
#line 640 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s > %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2319 "out/myanalyzer.tab.c"
    break;

  case 81: /* expression: expression OP_GEQ expression  */
#line 643 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s >= %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2328 "out/myanalyzer.tab.c"
    break;

  case 82: /* expression: expression KW_AND expression  */
#line 646 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 6);
			sprintf((yyval.string), "%s && %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2337 "out/myanalyzer.tab.c"
    break;

  case 83: /* expression: expression KW_OR expression  */
#line 649 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			sprintf((yyval.string), "%s || %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2346 "out/myanalyzer.tab.c"
    break;

  case 84: /* expression: KW_NOT expression  */
#line 652 "myanalyzer.y"
                                           { (yyval.string) = (yyvsp[0].string); }
#line 2352 "out/myanalyzer.tab.c"
    break;

  case 85: /* expression: OP_MINUS expression  */
#line 653 "myanalyzer.y"
                                           { (yyval.string) = (yyvsp[0].string); }
#line 2358 "out/myanalyzer.tab.c"
    break;

  case 86: /* expression: LPAREN expression RPAREN  */
#line 654 "myanalyzer.y"
                                   { (yyval.string) = (yyvsp[-1].string); }
#line 2364 "out/myanalyzer.tab.c"
    break;

  case 87: /* expression: CONST_BOOL_FALSE  */
#line 655 "myanalyzer.y"
                           { (yyval.string) = safe_strdup("false"); }
#line 2370 "out/myanalyzer.tab.c"
    break;

  case 88: /* expression: CONST_BOOL_TRUE  */
#line 656 "myanalyzer.y"
                          { (yyval.string) = safe_strdup("true"); }
#line 2376 "out/myanalyzer.tab.c"
    break;

  case 89: /* function_call: IDENTIFIER LPAREN arg_list RPAREN  */
#line 665 "myanalyzer.y"
                                          {
		(yyval.string) = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
		sprintf((yyval.string), "%s(%s)", (yyvsp[-3].string), (yyvsp[-1].string));
		safe_free((yyvsp[-3].string)); safe_free((yyvsp[-1].string));
	}
#line 2386 "out/myanalyzer.tab.c"
    break;

  case 90: /* arg_list: %empty  */
#line 673 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 2392 "out/myanalyzer.tab.c"
    break;

  case 91: /* arg_list: expression  */
#line 674 "myanalyzer.y"
                     { (yyval.string) = safe_strdup((yyvsp[0].string));}
#line 2398 "out/myanalyzer.tab.c"
    break;

  case 92: /* arg_list: arg_list COMMA expression  */
#line 675 "myanalyzer.y"
                                    {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s,%s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = tmp;
		safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2409 "out/myanalyzer.tab.c"
    break;

  case 97: /* primary_expression: function_call  */
#line 688 "myanalyzer.y"
                        { (yyval.string) = (yyvsp[0].string); }
#line 2415 "out/myanalyzer.tab.c"
    break;

  case 98: /* primary_expression: primary_expression LBRACKET expression RBRACKET  */
#line 690 "myanalyzer.y"
                                                          {
		(yyval.string) = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
		sprintf((yyval.string), "%s[%s]", (yyvsp[-3].string), (yyvsp[-1].string));
		safe_free((yyvsp[-3].string)); safe_free((yyvsp[-1].string));
	}
#line 2425 "out/myanalyzer.tab.c"
    break;

  case 99: /* primary_expression: primary_expression DOT IDENTIFIER  */
#line 694 "myanalyzer.y"
                                              {
		(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf((yyval.string), "%s.%s", (yyvsp[-2].string), (yyvsp[0].string));
		safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2435 "out/myanalyzer.tab.c"
    break;

  case 100: /* primary_expression: HASH IDENTIFIER  */
#line 698 "myanalyzer.y"
                            { (yyval.string) = safe_strdup((yyvsp[0].string)); safe_free((yyvsp[0].string)); }
#line 2441 "out/myanalyzer.tab.c"
    break;

  case 101: /* block: %empty  */
#line 702 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 2447 "out/myanalyzer.tab.c"
    break;

  case 102: /* block: block var_declaration  */
#line 703 "myanalyzer.y"
                                {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
		safe_free((yyvsp[-1].string)); safe_free((yyvsp[0].string));
		(yyval.string) = tmp;

	}
#line 2459 "out/myanalyzer.tab.c"
    break;

  case 103: /* block: block stmt  */
#line 709 "myanalyzer.y"
                       {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
		safe_free((yyvsp[-1].string)); safe_free((yyvsp[0].string));
		(yyval.string) = tmp;

	}
#line 2471 "out/myanalyzer.tab.c"
    break;


#line 2475 "out/myanalyzer.tab.c"

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

#line 729 "myanalyzer.y"


# ifndef TTLEXER
	int main() {
		yydebug = 1;
		return yyparse();
	}
# endif
