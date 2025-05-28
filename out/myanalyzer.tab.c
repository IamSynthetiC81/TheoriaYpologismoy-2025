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

// void yyerror(const char *fmt, ...) {
// 	va_list args;
// 	va_start(args, fmt);
// 	fprintf(stderr, "Parse error: ");
// 	vfprintf(stderr, fmt, args);
// 	fprintf(stderr, "\n");
// 	va_end(args);
// }


#line 178 "out/myanalyzer.tab.c"

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
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

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
       0,   175,   175,   181,   182,   195,   208,   209,   219,   222,
     225,   229,   233,   240,   253,   267,   279,   294,   295,   299,
     304,   313,   326,   327,   336,   337,   338,   339,   340,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   358,   366,
     378,   388,   398,   413,   426,   439,   445,   451,   458,   469,
     470,   481,   488,   496,   501,   502,   510,   511,   519,   523,
     532,   533,   537,   540,   543,   546,   549,   552,   555,   558,
     561,   564,   567,   570,   573,   576,   577,   578,   579,   580,
     584,   592,   593,   594,   603,   604,   605,   606,   607,   609,
     613,   621,   622,   628
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

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -114,    13,   -29,  -114,    36,  -114,   178,   182,  -114,    37,
       5,    42,  -114,  -114,  -114,  -114,  -114,  -114,    16,    -3,
    -114,  -114,  -114,  -114,  -114,   182,   182,   182,   405,  -114,
     -52,    25,     7,     9,     6,    56,    77,   182,   247,  -114,
     346,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,    79,   182,    87,    44,
    -114,  -114,  -114,  -114,  -114,  -114,    38,  -114,   405,   -19,
    -114,   247,   304,    60,   188,   188,   188,   188,   188,   188,
     141,   141,    60,    60,    60,   288,  -114,   230,    45,    49,
      51,    47,    85,  -114,  -114,   182,  -114,    56,    56,   -51,
     115,  -114,    66,  -114,   116,    72,  -114,  -114,  -114,    68,
     405,    75,  -114,  -114,    56,    69,    55,  -114,  -114,   131,
      56,   135,  -114,    78,    88,    56,    89,     3,    99,   144,
     100,   104,   108,   110,   182,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,   111,   118,   120,  -114,
     121,  -114,  -114,  -114,   182,   182,   164,   182,  -114,  -114,
    -114,   172,  -114,   137,  -114,  -114,    93,   201,   360,   140,
     391,  -114,    56,   143,  -114,   145,   182,   146,   148,  -114,
    -114,   259,  -114,  -114,    32,   182,   119,     3,   150,   151,
    -114,   317,   152,  -114,  -114,   170,  -114,   142,  -114,   153,
     154,  -114,   174,  -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     6,     1,     0,     4,     2,     0,    58,     0,
       0,     0,     7,    11,    12,     8,     9,    10,     0,    87,
      84,    85,    86,    79,    78,     0,     0,     0,     5,    88,
      60,     0,     0,     0,     0,     0,     0,    81,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
      49,    28,    24,    25,    26,    27,     0,    59,    82,     0,
      77,    73,    74,    66,    67,    68,    69,    70,    71,    72,
      61,    62,    63,    64,    65,     0,    90,     0,     0,     0,
      18,     0,     0,    13,    80,     0,    89,     0,     0,     0,
       0,    91,     0,    56,     0,     0,    54,    53,    50,     0,
      83,     0,    19,    91,     0,     0,     0,    55,    48,     0,
       0,     0,    14,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,    47,    92,    93,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,     0,    57,
       0,    91,    20,    38,     0,     0,     0,     0,    45,    46,
      21,     0,    37,     0,    51,    16,     0,     0,     0,     0,
       0,    40,     0,     0,    39,     0,     0,     0,     0,    15,
      22,     0,    22,    52,     0,     0,     0,     0,     0,     0,
      23,     0,     0,    22,    41,     0,    44,     0,    22,     0,
       0,    42,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,  -114,  -114,  -114,   193,  -114,   165,  -114,
    -114,  -114,   -32,   -83,   -73,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   -25,  -113,
    -114,  -114,  -107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,    12,   136,    14,    15,    89,
      90,    16,   184,    66,   190,   138,   139,   140,   141,   142,
     143,   144,   145,    17,    92,   108,   109,    18,    28,    29,
      69,    30,   116
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    39,    40,   146,    55,     4,   123,   113,    32,    56,
     146,   114,    68,     3,   111,   112,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   124,    87,   126,    33,   187,    94,   148,   154,     7,
      31,    95,   152,   137,   166,    34,   128,   188,   189,   129,
     137,    37,   130,   146,   131,   132,   126,    37,   127,    61,
      57,    58,   134,    59,    60,    62,    63,    64,    65,   128,
     110,   146,   129,   146,    35,   130,    36,   131,   132,   126,
      67,   127,    86,   133,   146,   134,   102,   146,   103,   178,
      88,   135,   128,   137,   126,   129,   127,    93,   130,    91,
     131,   132,    43,    98,    99,   101,   150,   128,   134,   161,
     129,   100,   104,   130,   135,   131,   132,   105,   115,    32,
     126,   173,   187,   134,   119,   117,   120,   125,   121,   167,
     168,   118,   170,   128,   122,   147,   129,   135,   149,   130,
     192,   131,   132,   126,   106,   187,   151,   156,   153,   134,
     186,   181,   135,   155,   157,   126,   128,   187,   199,   129,
     191,   197,   130,   158,   131,   132,   200,   159,   128,   160,
     162,   129,   134,   202,   130,   163,   131,   132,   135,   164,
     165,     8,   169,    43,   134,    19,    20,    21,    22,    23,
      24,     9,    52,    53,    54,   172,   176,    41,    42,    13,
       0,   135,   179,   180,   182,    10,    25,   183,   193,    11,
     194,   196,   201,   135,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    41,    42,   198,     0,
      43,   171,    26,   203,     0,     0,    27,    50,    51,    52,
      53,    54,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    41,    42,   107,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    41,    42,     0,     0,    97,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    41,    42,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    41,    42,     0,    96,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     0,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    41,    42,     0,   195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    42,     0,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,    70,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     0,   175,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     0,   177,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54
};

static const yytype_int16 yycheck[] =
{
      25,    26,    27,   116,    56,    34,   113,    58,     3,    61,
     123,    62,    37,     0,    97,    98,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   114,    57,     1,    29,     3,    55,   120,    35,     3,
       3,    60,   125,   116,   151,     3,    14,    15,    16,    17,
     123,    54,    20,   166,    22,    23,     1,    54,     3,     3,
      35,    54,    30,    54,    58,     9,    10,    11,    12,    14,
      95,   184,    17,   186,    58,    20,    60,    22,    23,     1,
       3,     3,     3,    28,   197,    30,     1,   200,     3,   172,
       3,    59,    14,   166,     1,    17,     3,    59,    20,    55,
      22,    23,    42,    58,    55,    58,    28,    14,    30,   134,
      17,    60,    27,    20,    59,    22,    23,    32,     3,     3,
       1,    28,     3,    30,    56,    59,    58,    58,    60,   154,
     155,    59,   157,    14,    59,     4,    17,    59,     3,    20,
      21,    22,    23,     1,    59,     3,    58,     3,    59,    30,
     182,   176,    59,    54,    54,     1,    14,     3,    16,    17,
     185,   193,    20,    59,    22,    23,   198,    59,    14,    59,
      59,    17,    30,    19,    20,    57,    22,    23,    59,    59,
      59,     3,    18,    42,    30,     3,     4,     5,     6,     7,
       8,    13,    51,    52,    53,    58,    56,    25,    26,     6,
      -1,    59,    59,    58,    58,    27,    24,    59,    58,    31,
      59,    59,    59,    59,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    25,    26,    58,    -1,
      42,    59,    50,    59,    -1,    -1,    54,    49,    50,    51,
      52,    53,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    25,    26,    92,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    25,    26,    -1,    -1,    58,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    25,    26,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    25,    26,    -1,    57,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    42,
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
       4,     5,     6,     7,     8,    24,    50,    54,    97,    98,
     100,     3,     3,    29,     3,    58,    60,    54,    97,    97,
      97,    25,    26,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    56,    61,    35,    54,    54,
      58,     3,     9,    10,    11,    12,    82,     3,    97,    99,
      55,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,     3,    97,     3,    78,
      79,    55,    93,    59,    55,    60,    57,    58,    58,    55,
      60,    58,     1,     3,    27,    32,    59,    77,    94,    95,
      97,    82,    82,    58,    62,     3,   101,    59,    59,    56,
      58,    60,    59,   101,    82,    58,     1,     3,    14,    17,
      20,    22,    23,    28,    30,    59,    75,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    98,     4,    82,     3,
      28,    58,    82,    59,    35,    54,     3,    54,    59,    59,
      59,    97,    59,    57,    59,    59,   101,    97,    97,    18,
      97,    59,    58,    28,    59,    55,    56,    55,    82,    59,
      58,    97,    58,    59,    81,    58,    81,     3,    15,    16,
      83,    97,    21,    58,    59,    57,    59,    81,    58,    16,
      81,    59,    19,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    73,    73,    74,    74,
      74,    74,    74,    75,    76,    77,    77,    78,    78,    79,
      79,    80,    81,    81,    82,    82,    82,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      85,    86,    86,    87,    88,    89,    90,    91,    92,    93,
      93,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    99,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     0,     2,     1,     1,
       1,     1,     1,     4,     7,    11,     9,     0,     1,     3,
       5,     8,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       3,     8,    11,    12,     8,     2,     2,     1,     6,     0,
       2,     4,     7,     1,     1,     2,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       4,     0,     1,     3,     1,     1,     1,     1,     1,     4,
       3,     0,     2,     2
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
#line 175 "myanalyzer.y"
                                      {
		printf("#include \"lambdalib.h\"\n\n%s%s", (yyvsp[-1].string), (yyvsp[0].string));
	}
#line 1462 "out/myanalyzer.tab.c"
    break;

  case 3: /* macro_def_list: %empty  */
#line 181 "myanalyzer.y"
                            { (yyval.string) = safe_strdup("");}
#line 1468 "out/myanalyzer.tab.c"
    break;

  case 4: /* macro_def_list: macro_def_list macro_def  */
#line 182 "myanalyzer.y"
                                           {
			fprintf(stderr, "Macro definition: %s\n", (yyvsp[-1].string));
			(yyval.string) = (yyvsp[-1].string);
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			free((yyvsp[-1].string));
			free((yyvsp[0].string));

		}
#line 1483 "out/myanalyzer.tab.c"
    break;

  case 5: /* macro_def: KW_DEFMACRO IDENTIFIER expression  */
#line 195 "myanalyzer.y"
                                                  {
		fprintf(stderr, "Macro defined: %s\n", (yyvsp[-1].string));
		add_macro((yyvsp[-1].string), (yyvsp[0].string));
		char* macro_code = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 16);
		sprintf(macro_code, "#define %s %s\n", (yyvsp[-1].string), (yyvsp[0].string));
		(yyval.string) = add_indentation(macro_code);
		free(macro_code);
		free((yyvsp[-1].string));
		free((yyvsp[0].string));
	}
#line 1498 "out/myanalyzer.tab.c"
    break;

  case 6: /* top_level_list: %empty  */
#line 208 "myanalyzer.y"
                            { (yyval.string) = safe_strdup(""); }
#line 1504 "out/myanalyzer.tab.c"
    break;

  case 7: /* top_level_list: top_level_list top_level  */
#line 209 "myanalyzer.y"
                                          {
			fprintf(stderr, "Top level: %s\n", (yyvsp[-1].string));
			char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = tmp;
			free((yyvsp[-1].string)); safe_free((yyvsp[0].string));
		}
#line 1516 "out/myanalyzer.tab.c"
    break;

  case 8: /* top_level: function  */
#line 219 "myanalyzer.y"
                 {
		fprintf(stderr, "Function: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1525 "out/myanalyzer.tab.c"
    break;

  case 9: /* top_level: main_function  */
#line 222 "myanalyzer.y"
                          {
		fprintf(stderr, "Main function: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1534 "out/myanalyzer.tab.c"
    break;

  case 10: /* top_level: component  */
#line 225 "myanalyzer.y"
                      {
		fprintf(stderr, "Component: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1543 "out/myanalyzer.tab.c"
    break;

  case 11: /* top_level: var_declaration  */
#line 229 "myanalyzer.y"
                          {
		fprintf(stderr, "Variable declaration: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1552 "out/myanalyzer.tab.c"
    break;

  case 12: /* top_level: const_declaration  */
#line 233 "myanalyzer.y"
                            {
		fprintf(stderr, "Constant declaration: %s\n", (yyvsp[0].string));
		(yyval.string) = (yyvsp[0].string);
	}
#line 1561 "out/myanalyzer.tab.c"
    break;

  case 13: /* var_declaration: ident_list COLON type SEMICOLON  */
#line 240 "myanalyzer.y"
                                                {
		// $1 is the variable name, $3 is the type
		fprintf(stderr, "Processing declaration: %s of type %s\n", (yyvsp[-3].string), (yyvsp[-1].string));
		char* decl = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
		free((yyvsp[-3].string));
		free((yyvsp[-1].string));
	}
#line 1576 "out/myanalyzer.tab.c"
    break;

  case 14: /* const_declaration: KW_CONST IDENTIFIER OP_ASSIGN expression COLON type SEMICOLON  */
#line 253 "myanalyzer.y"
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
#line 1592 "out/myanalyzer.tab.c"
    break;

  case 15: /* function: KW_DEF IDENTIFIER LPAREN param_list RPAREN OP_ARROW type COLON block KW_ENDDEF SEMICOLON  */
#line 267 "myanalyzer.y"
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
#line 1609 "out/myanalyzer.tab.c"
    break;

  case 16: /* function: KW_DEF IDENTIFIER LPAREN param_list RPAREN COLON block KW_ENDDEF SEMICOLON  */
#line 279 "myanalyzer.y"
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
#line 1626 "out/myanalyzer.tab.c"
    break;

  case 17: /* param_list: %empty  */
#line 294 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 1632 "out/myanalyzer.tab.c"
    break;

  case 18: /* param_list: param_decl_list  */
#line 295 "myanalyzer.y"
                          { fprintf(stderr, "Param list %s\n", (yyvsp[0].string));  (yyval.string) = (yyvsp[0].string); }
#line 1638 "out/myanalyzer.tab.c"
    break;

  case 19: /* param_decl_list: IDENTIFIER COLON type  */
#line 299 "myanalyzer.y"
                                      {
			fprintf(stderr, "Param: %s\n", (yyvsp[-2].string));

			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
			sprintf((yyval.string), "%s %s", (yyvsp[0].string), (yyvsp[-2].string));
		}
#line 1649 "out/myanalyzer.tab.c"
    break;

  case 20: /* param_decl_list: param_decl_list COMMA IDENTIFIER COLON type  */
#line 304 "myanalyzer.y"
                                                                {
			fprintf(stderr, "Param: %s\n", (yyvsp[-2].string));

			char* tmp = malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf(tmp, "%s, %s %s", (yyvsp[-4].string), (yyvsp[0].string), (yyvsp[-2].string));
			(yyval.string) = tmp;
		}
#line 1661 "out/myanalyzer.tab.c"
    break;

  case 21: /* main_function: KW_DEF KW_MAIN LPAREN RPAREN COLON block KW_ENDDEF SEMICOLON  */
#line 313 "myanalyzer.y"
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
#line 1676 "out/myanalyzer.tab.c"
    break;

  case 22: /* stmt_list: %empty  */
#line 326 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 1682 "out/myanalyzer.tab.c"
    break;

  case 23: /* stmt_list: stmt_list stmt  */
#line 327 "myanalyzer.y"
                         {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
		(yyval.string) = tmp;
		safe_free((yyvsp[-1].string)); safe_free((yyvsp[0].string));
	}
#line 1693 "out/myanalyzer.tab.c"
    break;

  case 24: /* type: KW_INTEGER  */
#line 336 "myanalyzer.y"
                            { (yyval.string) = safe_strdup("int"); }
#line 1699 "out/myanalyzer.tab.c"
    break;

  case 25: /* type: KW_SCALAR  */
#line 337 "myanalyzer.y"
                      { (yyval.string) = safe_strdup("float"); }
#line 1705 "out/myanalyzer.tab.c"
    break;

  case 26: /* type: KW_STR  */
#line 338 "myanalyzer.y"
                      { (yyval.string) = safe_strdup("char*"); }
#line 1711 "out/myanalyzer.tab.c"
    break;

  case 27: /* type: KW_BOOL  */
#line 339 "myanalyzer.y"
                      { (yyval.string) = safe_strdup("bool"); }
#line 1717 "out/myanalyzer.tab.c"
    break;

  case 28: /* type: IDENTIFIER  */
#line 340 "myanalyzer.y"
                      { (yyval.string) = safe_strdup((yyvsp[0].string)); safe_free((yyvsp[0].string));}
#line 1723 "out/myanalyzer.tab.c"
    break;

  case 37: /* stmt: function_call SEMICOLON  */
#line 352 "myanalyzer.y"
                                  {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + 3);
		sprintf(tmp, "%s;\n", (yyvsp[-1].string));
		(yyval.string) = add_indentation(tmp);
		free(tmp);
		free((yyvsp[-1].string));
	}
#line 1735 "out/myanalyzer.tab.c"
    break;

  case 38: /* stmt: error SEMICOLON  */
#line 358 "myanalyzer.y"
                            {
		yyerror("Invalid statement");
		yyerrok;
		(yyval.string) = safe_strdup("/* ERROR */\n");
	}
#line 1745 "out/myanalyzer.tab.c"
    break;

  case 39: /* assignment_stmt: IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 366 "myanalyzer.y"
                                                  {
		fprintf(stderr, "Matched assignment: %s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
		char* line = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(line, "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].string));
		(yyval.string) = safe_strdup(line);
		safe_free(line);
		safe_free((yyvsp[-3].string));
		safe_free((yyvsp[-1].string));
	}
#line 1759 "out/myanalyzer.tab.c"
    break;

  case 40: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 378 "myanalyzer.y"
                                               {
				fprintf(stderr, "Returning: %s\n", (yyvsp[-1].string));
				char* line = malloc(strlen((yyvsp[-1].string)) + 16);
				sprintf(line, "return %s;\n", (yyvsp[-1].string));
				(yyval.string) = add_indentation(line);
				safe_free(line);
		}
#line 1771 "out/myanalyzer.tab.c"
    break;

  case 41: /* if_stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ENDIF SEMICOLON  */
#line 388 "myanalyzer.y"
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
#line 1786 "out/myanalyzer.tab.c"
    break;

  case 42: /* if_stmt: KW_IF LPAREN expression RPAREN COLON stmt_list KW_ELSE COLON stmt_list KW_ENDIF SEMICOLON  */
#line 398 "myanalyzer.y"
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
#line 1803 "out/myanalyzer.tab.c"
    break;

  case 43: /* for_stmt: KW_FOR IDENTIFIER KW_IN LBRACKET expression COLON expression RBRACKET COLON stmt_list KW_ENDFOR SEMICOLON  */
#line 413 "myanalyzer.y"
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
#line 1818 "out/myanalyzer.tab.c"
    break;

  case 44: /* while_stmt: KW_WHILE LPAREN expression RPAREN COLON stmt_list KW_ENDWHILE SEMICOLON  */
#line 426 "myanalyzer.y"
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
#line 1833 "out/myanalyzer.tab.c"
    break;

  case 45: /* break_stmt: KW_BREAK SEMICOLON  */
#line 439 "myanalyzer.y"
                                   {
				(yyval.string) = add_indentation("break;\n");
		}
#line 1841 "out/myanalyzer.tab.c"
    break;

  case 46: /* continue_stmt: KW_CONTINUE SEMICOLON  */
#line 445 "myanalyzer.y"
                                      {
				(yyval.string) = add_indentation("continue;\n");
		}
#line 1849 "out/myanalyzer.tab.c"
    break;

  case 47: /* empty_stmt: SEMICOLON  */
#line 451 "myanalyzer.y"
                          {
				(yyval.string) = safe_strdup(";");
		}
#line 1857 "out/myanalyzer.tab.c"
    break;

  case 48: /* component: KW_COMP IDENTIFIER COLON component_body KW_ENDCOMP SEMICOLON  */
#line 458 "myanalyzer.y"
                                                                             {
				fprintf(stderr, "Component: %s\n", (yyvsp[-4].string));

				char* code = malloc(strlen((yyvsp[-4].string)) + 16);
				sprintf(code, "struct %s {\n%s};\n", (yyvsp[-4].string), (yyvsp[-2].string));
				(yyval.string) = add_indentation(code);
				free(code);
		}
#line 1870 "out/myanalyzer.tab.c"
    break;

  case 49: /* component_body: %empty  */
#line 469 "myanalyzer.y"
                            { (yyval.string) = safe_strdup(""); }
#line 1876 "out/myanalyzer.tab.c"
    break;

  case 50: /* component_body: component_body component_member  */
#line 470 "myanalyzer.y"
                                          {
			fprintf(stderr, "Component member: %s\n", (yyvsp[0].string));

			char* code = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 16);
			sprintf(code, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
			(yyval.string) = code;
			free(code);
	}
#line 1889 "out/myanalyzer.tab.c"
    break;

  case 51: /* component_member: hash_ident_list COLON type SEMICOLON  */
#line 481 "myanalyzer.y"
                                             {
		char* decl = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s;\n", (yyvsp[-1].string), (yyvsp[-3].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
		free((yyvsp[-3].string));
		free((yyvsp[-1].string));
	}
#line 1902 "out/myanalyzer.tab.c"
    break;

  case 52: /* component_member: hash_ident_list LBRACKET CONST_INT RBRACKET COLON type SEMICOLON  */
#line 488 "myanalyzer.y"
                                                                             {
		char* decl = malloc(strlen((yyvsp[-6].string)) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 16);
		sprintf(decl, "%s %s[%s];\n", (yyvsp[-1].string), (yyvsp[-6].string), (yyvsp[-4].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
		free((yyvsp[-6].string));
		free((yyvsp[-4].string));
		free((yyvsp[-1].string));
	}
#line 1916 "out/myanalyzer.tab.c"
    break;

  case 53: /* component_member: function  */
#line 496 "myanalyzer.y"
                     {
		char* decl = malloc(strlen((yyvsp[0].string)) + 16);
		sprintf(decl, "%s", (yyvsp[0].string));
		(yyval.string) = add_indentation(decl);
		free(decl);
	}
#line 1927 "out/myanalyzer.tab.c"
    break;

  case 54: /* component_member: SEMICOLON  */
#line 501 "myanalyzer.y"
                      { (yyval.string) = safe_strdup("");
	}
#line 1934 "out/myanalyzer.tab.c"
    break;

  case 55: /* component_member: error SEMICOLON  */
#line 502 "myanalyzer.y"
                            {
		yyerror("Invalid variable declaration");
		yyerrok;
		(yyval.string) = safe_strdup("/* BAD DECLARATION */\n");
	}
#line 1944 "out/myanalyzer.tab.c"
    break;

  case 56: /* hash_ident_list: IDENTIFIER  */
#line 510 "myanalyzer.y"
                                   { (yyval.string) = safe_strdup((yyvsp[0].string)); }
#line 1950 "out/myanalyzer.tab.c"
    break;

  case 57: /* hash_ident_list: hash_ident_list COMMA IDENTIFIER  */
#line 511 "myanalyzer.y"
                                           {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
		sprintf(tmp, "%s, %s", (yyvsp[-2].string), (yyvsp[0].string)); // No # inserted
		(yyval.string) = tmp;
	}
#line 1960 "out/myanalyzer.tab.c"
    break;

  case 58: /* ident_list: IDENTIFIER  */
#line 519 "myanalyzer.y"
                   {
		(yyval.string) = safe_strdup((yyvsp[0].string));
		safe_free((yyvsp[0].string));
	}
#line 1969 "out/myanalyzer.tab.c"
    break;

  case 59: /* ident_list: ident_list COMMA IDENTIFIER  */
#line 523 "myanalyzer.y"
                                      {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s, %s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = tmp;
	}
#line 1979 "out/myanalyzer.tab.c"
    break;

  case 60: /* expression: primary_expression  */
#line 532 "myanalyzer.y"
                                   { (yyval.string) = safe_strdup((yyvsp[0].string)); safe_free((yyvsp[0].string)); }
#line 1985 "out/myanalyzer.tab.c"
    break;

  case 61: /* expression: expression OP_PLUS expression  */
#line 533 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s + %s", (yyvsp[-2].string), (yyvsp[0].string));
			safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 1995 "out/myanalyzer.tab.c"
    break;

  case 62: /* expression: expression OP_MINUS expression  */
#line 537 "myanalyzer.y"
                                                 {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s - %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2004 "out/myanalyzer.tab.c"
    break;

  case 63: /* expression: expression OP_MULT expression  */
#line 540 "myanalyzer.y"
                                          {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s * %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2013 "out/myanalyzer.tab.c"
    break;

  case 64: /* expression: expression OP_DIV expression  */
#line 543 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s / %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2022 "out/myanalyzer.tab.c"
    break;

  case 65: /* expression: expression OP_MOD expression  */
#line 546 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s %% %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2031 "out/myanalyzer.tab.c"
    break;

  case 66: /* expression: expression OP_POW expression  */
#line 549 "myanalyzer.y"
                                                      {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s ^ %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2040 "out/myanalyzer.tab.c"
    break;

  case 67: /* expression: expression OP_EQ expression  */
#line 552 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s == %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2049 "out/myanalyzer.tab.c"
    break;

  case 68: /* expression: expression OP_NEQ expression  */
#line 555 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s != %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2058 "out/myanalyzer.tab.c"
    break;

  case 69: /* expression: expression OP_LT expression  */
#line 558 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s < %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2067 "out/myanalyzer.tab.c"
    break;

  case 70: /* expression: expression OP_LEQ expression  */
#line 561 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s <= %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2076 "out/myanalyzer.tab.c"
    break;

  case 71: /* expression: expression OP_GT expression  */
#line 564 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s > %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2085 "out/myanalyzer.tab.c"
    break;

  case 72: /* expression: expression OP_GEQ expression  */
#line 567 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 4);
			sprintf((yyval.string), "%s >= %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2094 "out/myanalyzer.tab.c"
    break;

  case 73: /* expression: expression KW_AND expression  */
#line 570 "myanalyzer.y"
                                         {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 6);
			sprintf((yyval.string), "%s && %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2103 "out/myanalyzer.tab.c"
    break;

  case 74: /* expression: expression KW_OR expression  */
#line 573 "myanalyzer.y"
                                        {
			(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 5);
			sprintf((yyval.string), "%s || %s", (yyvsp[-2].string), (yyvsp[0].string)); safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2112 "out/myanalyzer.tab.c"
    break;

  case 75: /* expression: KW_NOT expression  */
#line 576 "myanalyzer.y"
                                           { (yyval.string) = (yyvsp[0].string); }
#line 2118 "out/myanalyzer.tab.c"
    break;

  case 76: /* expression: OP_MINUS expression  */
#line 577 "myanalyzer.y"
                                           { (yyval.string) = (yyvsp[0].string); }
#line 2124 "out/myanalyzer.tab.c"
    break;

  case 77: /* expression: LPAREN expression RPAREN  */
#line 578 "myanalyzer.y"
                                   { (yyval.string) = (yyvsp[-1].string); }
#line 2130 "out/myanalyzer.tab.c"
    break;

  case 78: /* expression: CONST_BOOL_FALSE  */
#line 579 "myanalyzer.y"
                           { (yyval.string) = safe_strdup("false"); }
#line 2136 "out/myanalyzer.tab.c"
    break;

  case 79: /* expression: CONST_BOOL_TRUE  */
#line 580 "myanalyzer.y"
                          { (yyval.string) = safe_strdup("true"); }
#line 2142 "out/myanalyzer.tab.c"
    break;

  case 80: /* function_call: IDENTIFIER LPAREN arg_list RPAREN  */
#line 584 "myanalyzer.y"
                                          {
		(yyval.string) = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
		sprintf((yyval.string), "%s(%s)", (yyvsp[-3].string), (yyvsp[-1].string));
		safe_free((yyvsp[-3].string)); safe_free((yyvsp[-1].string));
	}
#line 2152 "out/myanalyzer.tab.c"
    break;

  case 81: /* arg_list: %empty  */
#line 592 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 2158 "out/myanalyzer.tab.c"
    break;

  case 82: /* arg_list: expression  */
#line 593 "myanalyzer.y"
                     { (yyval.string) = safe_strdup((yyvsp[0].string));}
#line 2164 "out/myanalyzer.tab.c"
    break;

  case 83: /* arg_list: arg_list COMMA expression  */
#line 594 "myanalyzer.y"
                                    {
		char* tmp = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s,%s", (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.string) = tmp;
		safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2175 "out/myanalyzer.tab.c"
    break;

  case 88: /* primary_expression: function_call  */
#line 607 "myanalyzer.y"
                        { (yyval.string) = (yyvsp[0].string); }
#line 2181 "out/myanalyzer.tab.c"
    break;

  case 89: /* primary_expression: primary_expression LBRACKET expression RBRACKET  */
#line 609 "myanalyzer.y"
                                                          {
		(yyval.string) = malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 4);
		sprintf((yyval.string), "%s[%s]", (yyvsp[-3].string), (yyvsp[-1].string));
		safe_free((yyvsp[-3].string)); safe_free((yyvsp[-1].string));
	}
#line 2191 "out/myanalyzer.tab.c"
    break;

  case 90: /* primary_expression: primary_expression DOT IDENTIFIER  */
#line 613 "myanalyzer.y"
                                              {
		(yyval.string) = malloc(strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf((yyval.string), "%s.%s", (yyvsp[-2].string), (yyvsp[0].string));
		safe_free((yyvsp[-2].string)); safe_free((yyvsp[0].string));
	}
#line 2201 "out/myanalyzer.tab.c"
    break;

  case 91: /* block: %empty  */
#line 621 "myanalyzer.y"
                    { (yyval.string) = safe_strdup(""); }
#line 2207 "out/myanalyzer.tab.c"
    break;

  case 92: /* block: block var_declaration  */
#line 622 "myanalyzer.y"
                                {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
		// safe_free($1); safe_free($2);
		(yyval.string) = tmp;

	}
#line 2219 "out/myanalyzer.tab.c"
    break;

  case 93: /* block: block stmt  */
#line 628 "myanalyzer.y"
                       {
		char* tmp = malloc(strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 2);
		sprintf(tmp, "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
		safe_free((yyvsp[-1].string)); safe_free((yyvsp[0].string));
		(yyval.string) = tmp;

	}
#line 2231 "out/myanalyzer.tab.c"
    break;


#line 2235 "out/myanalyzer.tab.c"

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

#line 648 "myanalyzer.y"


# ifndef TTLEXER
	int main() {
		yydebug = 1;
		return yyparse();
	}
# endif
