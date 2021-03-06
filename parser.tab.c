/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <iostream>
#include <cctype>
#include <vector>
#include <cstring>
#include "compiler.h"

using namespace std;

extern "C" int yylex();
extern "C" int yylineno;
extern "C" int yytext;

FILE* file;
char* fn;
int nerrors = 0;
AST ast;

void yyerror(const char *s);


#line 88 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    INT_LIT = 258,
    IDENT = 259,
    STRING_LIT = 260,
    CLASS = 261,
    DEF = 262,
    IF = 263,
    ELIF = 264,
    ELSE = 265,
    WHILE = 266,
    EXTENDS = 267,
    RETURN = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    ATMOST = 272,
    ATLEAST = 273,
    EQUALS = 274,
    UNKNOWN = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:355  */

	Node* node;
	NExpression* expr;
	NStatement* stmt;
	NClass* clas;
	int ival;
	string *sval;

#line 158 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 175 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    26,    24,    30,    25,    21,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    35,
      22,    34,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    60,    63,    69,    73,    80,    89,    94,
     100,   103,   109,   112,   115,   122,   126,   132,   138,   143,
     150,   153,   159,   163,   170,   174,   181,   188,   193,   196,
     199,   203,   207,   210,   217,   221,   227,   230,   233,   236,
     241,   246,   251,   256,   261,   266,   271,   276,   281,   286,
     291,   295,   298,   302,   306,   310,   318,   321,   324,   331,
     335,   342,   345,   352,   357,   363,   371,   374,   380,   387,
     390,   396,   400,   406,   414,   417
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LIT", "IDENT", "STRING_LIT",
  "CLASS", "DEF", "IF", "ELIF", "ELSE", "WHILE", "EXTENDS", "RETURN",
  "AND", "OR", "NOT", "ATMOST", "ATLEAST", "EQUALS", "UNKNOWN", "'.'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "','", "':'",
  "'{'", "'}'", "'='", "';'", "$accept", "program", "class_section",
  "classes", "class", "class_sig", "extends", "formal_arg_section",
  "formal_args", "formal_arg", "class_body", "statement_section",
  "statement_block", "statements", "statement", "l_exp", "r_exp",
  "actual_arg_section", "actual_args", "elif_section", "elif_blocks",
  "elif_block", "else_section", "else_block", "method_section", "methods",
  "method", "return_type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    46,    60,    62,    43,    45,    42,    47,    40,    41,
      44,    58,   123,   125,    61,    59
};
# endif

#define YYPACT_NINF -32

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-32)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    21,    27,     8,     4,   -32,    17,    40,    35,   -32,
      31,   -32,    44,   -32,   166,   166,   140,   166,   161,   -32,
      43,   -32,    -5,   178,   -32,    57,   -32,    71,   -32,    16,
      40,   -32,   145,   -32,   -32,   238,   238,   -32,   193,   297,
      54,   254,   -32,    80,   166,   166,   166,   166,   166,   166,
      85,   166,   166,   166,   166,   166,   166,   -32,    22,    86,
     -32,    65,    66,   -32,   -15,   -32,   -32,    67,   -32,   286,
      52,   126,    89,   -32,   -32,   -32,   -32,    69,   208,   297,
     297,    53,    53,    53,    91,    53,    53,    60,    60,   -32,
     -32,   -32,    95,    78,    86,   -32,   -32,    96,   -32,   100,
     -32,   -32,   166,    34,    99,   105,   114,    89,   -32,   166,
     -32,   -32,   -32,    35,   -32,   -32,   -32,   -32,   286,   -32,
     -32,   166,   103,   -32,   -32,   -32,   223,    97,   270,   -32,
     -32,   132,   103,   103,   -32,   -32,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     4,     6,     0,    10,     0,     1,
       0,    36,    35,    37,     0,     0,     0,     0,     0,     2,
       0,    25,    38,     0,     5,     0,     7,     0,     9,     0,
      10,    33,     0,    52,    38,     0,     0,    32,     0,    50,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    69,
      11,     0,     0,    12,     0,    16,     8,     0,    56,    60,
       0,     0,    61,    27,    31,    54,    53,     0,     0,    48,
      49,    44,    46,    43,     0,    45,    47,    39,    40,    41,
      42,    19,     0,     0,    70,    72,    14,     0,    13,     0,
      58,    57,     0,     0,     0,     0,    66,    62,    64,     0,
      29,    55,    51,     0,    18,    71,    17,    15,    59,    23,
      22,     0,     0,    26,    67,    63,     0,    74,     0,    68,
      28,     0,     0,     0,    75,    73,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   -32,   -32,   134,   -32,   110,    28,   -32,    48,
     -32,   -18,   -31,   -32,   131,     3,   -14,    68,   -32,   -32,
     -32,    46,   -32,   -32,   -32,   -32,    61,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    28,    30,    64,    65,
      26,    19,    72,    20,    21,    34,    23,    33,    70,   106,
     107,   108,   123,   124,    93,    94,    95,   132
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    36,    38,    39,    41,    73,    22,    59,   -20,    10,
       1,    11,    12,    13,    98,    99,    14,    61,    69,    15,
      62,    16,     7,    22,    17,     8,    43,     9,    22,    44,
      78,    79,    80,    81,    82,    83,    18,    85,    86,    87,
      88,    89,    90,   -21,    10,    63,    11,    12,    13,    25,
     -21,    14,    27,   104,    15,    91,    16,    31,    58,    17,
      11,    12,    13,    29,   -20,    14,    31,   119,    15,    31,
      16,    18,    32,    17,    22,    60,   -21,    53,    54,    55,
      56,   101,   102,    75,    77,    18,    55,    56,   118,    84,
     -20,   129,   111,    92,    96,   126,   100,    97,   105,   113,
     116,   135,   136,   109,    62,   -34,   -34,   128,   -34,   -34,
     -34,   114,   -34,   -34,   -34,   -34,   -34,   -34,   -34,    32,
     -34,   -34,   -34,   -34,   122,   -34,   -34,   103,   131,    11,
      12,    13,   120,   121,    14,    71,   134,    15,    24,    16,
      66,   127,    17,    11,    12,    13,    67,   117,    11,    12,
      13,    42,   112,   125,    18,   115,    17,     0,     0,   -20,
       0,    17,    40,     0,    11,    12,    13,     0,    18,    11,
      12,    13,     0,    18,    68,    37,     0,    17,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    45,    46,    18,    47,    48,    49,     0,    50,
      51,    52,    53,    54,    55,    56,     0,    45,    46,     0,
      47,    48,    49,    57,    50,    51,    52,    53,    54,    55,
      56,     0,    45,    46,     0,    47,    48,    49,    74,    50,
      51,    52,    53,    54,    55,    56,     0,    45,    46,     0,
      47,    48,    49,   110,    50,    51,    52,    53,    54,    55,
      56,     0,    45,    46,     0,    47,    48,    49,   130,    50,
      51,    52,    53,    54,    55,    56,     0,     0,    45,    46,
      71,    47,    48,    49,     0,    50,    51,    52,    53,    54,
      55,    56,     0,    76,    45,    46,     0,    47,    48,    49,
       0,    50,    51,    52,    53,    54,    55,    56,     0,   133,
      45,    46,     0,    47,    48,    49,     0,    50,    51,    52,
      53,    54,    55,    56,    47,    48,    49,     0,     0,    51,
      52,    53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
      14,    15,    16,    17,    18,    36,     3,    25,     0,     1,
       6,     3,     4,     5,    29,    30,     8,     1,    32,    11,
       4,    13,     1,    20,    16,     4,    31,     0,    25,    34,
      44,    45,    46,    47,    48,    49,    28,    51,    52,    53,
      54,    55,    56,     0,     1,    29,     3,     4,     5,    32,
       7,     8,    12,    71,    11,    33,    13,    35,     1,    16,
       3,     4,     5,    28,     7,     8,    35,    33,    11,    35,
      13,    28,    28,    16,    71,     4,    33,    24,    25,    26,
      27,    29,    30,    29,     4,    28,    26,    27,   102,     4,
      33,   122,     1,     7,    29,   109,    29,    31,     9,     4,
       4,   132,   133,    34,     4,    14,    15,   121,    17,    18,
      19,    33,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    10,    34,    35,     1,    31,     3,
       4,     5,    33,    28,     8,    32,     4,    11,     4,    13,
      30,   113,    16,     3,     4,     5,     1,    99,     3,     4,
       5,    20,    84,   107,    28,    94,    16,    -1,    -1,    33,
      -1,    16,     1,    -1,     3,     4,     5,    -1,    28,     3,
       4,     5,    -1,    28,    29,    35,    -1,    16,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    14,    15,    28,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    14,    15,    -1,
      17,    18,    19,    35,    21,    22,    23,    24,    25,    26,
      27,    -1,    14,    15,    -1,    17,    18,    19,    35,    21,
      22,    23,    24,    25,    26,    27,    -1,    14,    15,    -1,
      17,    18,    19,    35,    21,    22,    23,    24,    25,    26,
      27,    -1,    14,    15,    -1,    17,    18,    19,    35,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    14,    15,
      32,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    14,    15,    -1,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      14,    15,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    17,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    37,    38,    39,    40,    41,     1,     4,     0,
       1,     3,     4,     5,     8,    11,    13,    16,    28,    47,
      49,    50,    51,    52,    40,    32,    46,    12,    42,    28,
      43,    35,    28,    53,    51,    52,    52,    35,    52,    52,
       1,    52,    50,    31,    34,    14,    15,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    27,    35,     1,    47,
       4,     1,     4,    29,    44,    45,    42,     1,    29,    52,
      54,    32,    48,    48,    35,    29,    29,     4,    52,    52,
      52,    52,    52,    52,     4,    52,    52,    52,    52,    52,
      52,    33,     7,    60,    61,    62,    29,    31,    29,    30,
      29,    29,    30,     1,    47,     9,    55,    56,    57,    34,
      35,     1,    53,     4,    33,    62,     4,    45,    52,    33,
      33,    28,    10,    58,    59,    57,    52,    43,    52,    48,
      35,    31,    63,    29,     4,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    41,    41,
      42,    42,    43,    43,    43,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     1,     2,     4,     3,
       0,     2,     2,     3,     3,     3,     1,     3,     4,     3,
       0,     1,     3,     3,     2,     1,     5,     3,     6,     4,
       2,     3,     2,     2,     3,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     4,     2,     3,     3,     4,     2,     3,     3,     3,
       1,     0,     1,     2,     1,     5,     0,     1,     2,     0,
       1,     2,     1,     5,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 51 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("program", NPROGRAM, yylineno);
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));

		ast.root = (yyval.node);
	}
#line 1387 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 61 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", NCLASS_SEC, yylineno);
	}
#line 1394 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 64 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);
	}
#line 1401 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-1].node);
		(yyval.node)->addChild((yyvsp[0].clas));
	}
#line 1409 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("classes", NCLASS_SEC, yylineno);
		(yyval.node)->addChild((yyvsp[0].clas));
	}
#line 1417 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "parser.y" /* yacc.c:1646  */
    {	(yyval.clas) = new NClass((yyvsp[-1].node)->label, (yyvsp[-1].node)->ch.back()->label, yylineno);
		(yyval.clas)->addChild((yyvsp[-1].node));
		(yyval.clas)->addChild((yyvsp[0].node));
		ast.addClass((yyval.clas));
	}
#line 1427 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node(*(yyvsp[-2].sval), NCLASS_SIG, yylineno);
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 95 "parser.y" /* yacc.c:1646  */
    {	nerrors++;
	}
#line 1443 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 101 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("Obj", "Obj", NEXTENDS, yylineno);
	}
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 104 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node(*(yyvsp[0].sval), *(yyvsp[0].sval), NEXTENDS, yylineno);
	}
#line 1457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 110 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", NFORMAL_ARG_SEC, yylineno);
	}
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 113 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-1].node);
	}
#line 1471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "parser.y" /* yacc.c:1646  */
    { 	(yyval.node) = new Node("ERROR", NFORMAL_ARG_SEC, yylineno);
		nerrors++;
	}
#line 1479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-2].node);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("formal_args", NFORMAL_ARG_SEC, yylineno);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 133 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node(*(yyvsp[-2].sval), *(yyvsp[0].sval), NFORMAL_ARG, yylineno);
	}
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 139 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("class_body", NCLASS_BODY, yylineno);
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "parser.y" /* yacc.c:1646  */
    { 	(yyval.node) = new Node("ERROR", NCLASS_BODY, yylineno);
		nerrors++;
	}
#line 1519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 151 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", NSTATEMENT_SEC, yylineno);
	}
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 154 "parser.y" /* yacc.c:1646  */
    {	(yyval.node)=(yyvsp[0].node);
	}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 160 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("statement_section", NSTATEMENT_BLOCK, yylineno);
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 164 "parser.y" /* yacc.c:1646  */
    { 	(yyval.node) = new Node("ERROR", NSTATEMENT_BLOCK, yylineno);
		nerrors++;
	}
#line 1549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 171 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-1].node);
		(yyval.node)->addChild((yyvsp[0].stmt));
	}
#line 1557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 175 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("statements", NSTATEMENT_SEC, yylineno);
		(yyval.node)->addChild((yyvsp[0].stmt));
	}
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 182 "parser.y" /* yacc.c:1646  */
    {	(yyval.stmt) = new NStatement("IF statement", NSTIF, yylineno);
		(yyval.stmt)->addChild((yyvsp[-3].expr));
		(yyval.stmt)->addChild((yyvsp[-2].node));
		(yyval.stmt)->addChild((yyvsp[-1].node));
		(yyval.stmt)->addChild((yyvsp[0].node));
	}
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 189 "parser.y" /* yacc.c:1646  */
    {	(yyval.stmt) = new NStatement("while loop", NSTWHILE, yylineno);
		(yyval.stmt)->addChild((yyvsp[-1].expr));
		(yyval.stmt)->addChild((yyvsp[0].node));
	}
#line 1585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 194 "parser.y" /* yacc.c:1646  */
    {	(yyval.stmt) = new NAssignment("typed assignment" + *(yyvsp[-3].sval), *(yyvsp[-3].sval), (yyvsp[-5].expr), (yyvsp[-1].expr), yylineno);
	}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 197 "parser.y" /* yacc.c:1646  */
    {	(yyval.stmt) = new NAssignment("assignment", (yyvsp[-3].expr), (yyvsp[-1].expr), yylineno);
	}
#line 1599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 200 "parser.y" /* yacc.c:1646  */
    {	(yyval.stmt) = new NStatement((yyvsp[-1].expr)->label, NSTEX, yylineno);
		(yyval.stmt)->addChild((yyvsp[-1].expr));
	}
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 204 "parser.y" /* yacc.c:1646  */
    {	(yyval.stmt) = new NStatement("return stmt " + (yyvsp[-1].expr)->label, NSTRETURN, yylineno);
		(yyval.stmt)->addChild((yyvsp[-1].expr));
	}
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 208 "parser.y" /* yacc.c:1646  */
    {	(yyval.stmt) = new NStatement("return blank", NSTRETURN, yylineno);
	}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 211 "parser.y" /* yacc.c:1646  */
    {	(yyval.stmt) = new NStatement("ERROR", NSTATEMENT, yylineno);
		nerrors++;
	}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 218 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression(*(yyvsp[0].sval), NLEXQ, yylineno);
		(yyval.expr)->addChild((yyvsp[-2].expr));
	}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 222 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression(*(yyvsp[0].sval), NLEX, yylineno);
	}
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 228 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NInt((yyvsp[0].ival), yylineno);
	}
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 231 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NString(*(yyvsp[0].sval), yylineno);
	}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 234 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = (yyvsp[0].expr);
	}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 237 "parser.y" /* yacc.c:1646  */
    {	Node* arg = new Node("actual_args", NACTUAL_ARGS, yylineno);
		arg->addChild((yyvsp[0].expr));
		(yyval.expr) = new NMethod("PLUS", (yyvsp[-2].expr), arg, yylineno);
	}
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 242 "parser.y" /* yacc.c:1646  */
    {	Node* arg = new Node("actual_args", NACTUAL_ARGS, yylineno);
		arg->addChild((yyvsp[0].expr));
		(yyval.expr) = new NMethod("MINUS", (yyvsp[-2].expr), arg, yylineno);
	}
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 247 "parser.y" /* yacc.c:1646  */
    {	Node* arg = new Node("actual_args", NACTUAL_ARGS, yylineno);
		arg->addChild((yyvsp[0].expr));
		(yyval.expr) = new NMethod("TIMES", (yyvsp[-2].expr), arg, yylineno);
	}
#line 1693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 252 "parser.y" /* yacc.c:1646  */
    {	Node* arg = new Node("actual_args", NACTUAL_ARGS, yylineno);
		arg->addChild((yyvsp[0].expr));
		(yyval.expr) = new NMethod("DIVIDE", (yyvsp[-2].expr), arg, yylineno);
	}
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 257 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression("==", NEXEQ, yylineno);
		(yyval.expr)->addChild((yyvsp[-2].expr));
		(yyval.expr)->addChild((yyvsp[0].expr));
	}
#line 1711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 262 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression("<=", NEXMOST, yylineno);
		(yyval.expr)->addChild((yyvsp[-2].expr));
		(yyval.expr)->addChild((yyvsp[0].expr));
	}
#line 1720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 267 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression("<", NEXLESS, yylineno);
		(yyval.expr)->addChild((yyvsp[-2].expr));
		(yyval.expr)->addChild((yyvsp[0].expr));
	}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 272 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression(">=", NEXLEAST, yylineno);
		(yyval.expr)->addChild((yyvsp[-2].expr));
		(yyval.expr)->addChild((yyvsp[0].expr));
	}
#line 1738 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 277 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression(">", NEXGREATER, yylineno);
		(yyval.expr)->addChild((yyvsp[-2].expr));
		(yyval.expr)->addChild((yyvsp[0].expr));
	}
#line 1747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 282 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression("AND", NEXAND, yylineno);
		(yyval.expr)->addChild((yyvsp[-2].expr));
		(yyval.expr)->addChild((yyvsp[0].expr));
	}
#line 1756 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 287 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression("OR", NEXOR, yylineno);
		(yyval.expr)->addChild((yyvsp[-2].expr));
		(yyval.expr)->addChild((yyvsp[0].expr));
	}
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 292 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression("NOT", NEXNOT, yylineno);
		(yyval.expr)->addChild((yyvsp[0].expr));
	}
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 296 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NMethod(*(yyvsp[-1].sval), (yyvsp[-3].expr), (yyvsp[0].node), yylineno);
	}
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 299 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression(*(yyvsp[-1].sval), *(yyvsp[-1].sval), NEXCLASS, yylineno);
		(yyval.expr)->addChild((yyvsp[0].node));
	}
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 303 "parser.y" /* yacc.c:1646  */
    {	(yyval.expr) = new NExpression("REX", NEXPAR, yylineno);
		(yyval.expr)->addChild((yyvsp[-1].expr));
	}
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 307 "parser.y" /* yacc.c:1646  */
    { 	nerrors++;
		(yyval.expr) = new NExpression("ERROR", NEXERR, yylineno);
	}
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 311 "parser.y" /* yacc.c:1646  */
    {	cout << "!!" << endl;
	(yyval.expr) = new NExpression("ERROR", NEXERR, yylineno);
		nerrors++;
  }
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 319 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", NACTUAL_ARGS, yylineno);
	}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 322 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-1].node);
	}
#line 1827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 325 "parser.y" /* yacc.c:1646  */
    { 	(yyval.node) = new Node("ERROR", NACTUAL_ARGS, yylineno);
		nerrors++;
	}
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 332 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-2].node);
		(yyval.node)->addChild((yyvsp[0].expr));
	}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 336 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("actual_args", NACTUAL_ARGS, yylineno);
		(yyval.node)->addChild((yyvsp[0].expr));
	}
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 343 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", NELIF, yylineno);
	}
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 346 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("elif_secion", NELIF, yylineno);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1866 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 353 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("elif_blocks", NELIF_BLOCKS, yylineno);
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 358 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("elif_blocks", NELIF_BLOCKS, yylineno);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 364 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("ELIF", NELIF_BLOCK, yylineno);
		(yyval.node)->addChild((yyvsp[-2].expr));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 372 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", NELSE, yylineno);
	}
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 375 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("else_section", NELSE, yylineno);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1907 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 381 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("ELSE", NELSE_BLOCK, yylineno);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 388 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", NMETHOD_SEC, yylineno);
	}
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 391 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);
	}
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 397 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-1].node);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 401 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("methods", NMETHOD_SEC, yylineno);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 407 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node(*(yyvsp[-3].sval), *(yyvsp[-1].sval), NMETHOD, yylineno);
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1954 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 415 "parser.y" /* yacc.c:1646  */
    {	(yyval.sval) = new string("Nothing");
	}
#line 1961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 418 "parser.y" /* yacc.c:1646  */
    {	(yyval.sval) = (yyvsp[0].sval);
	}
#line 1968 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1972 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 422 "parser.y" /* yacc.c:1906  */

void yyerror(const char *s)
{	cerr << fn << ":" << yylineno << ": " << s << endl;
}
