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
#include <memory>
#include <vector>
#include <cstring>

#include "ast.h"

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int yylineno;
extern "C" int yytext;

FILE* file;
char* fn;
int nerrors = 0;
AST ast;

void yyerror(const char *s);


#line 92 "parser.tab.c" /* yacc.c:339  */

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
#line 26 "parser.y" /* yacc.c:355  */

	Node* node;
	int ival;
	char *sval;

#line 159 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

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
       0,    48,    48,    60,    63,    69,    73,    80,    89,    93,
      99,   102,   108,   111,   115,   122,   127,   133,   139,   144,
     151,   154,   160,   164,   171,   178,   183,   188,   193,   197,
     201,   204,   211,   215,   221,   224,   227,   231,   236,   241,
     246,   251,   256,   261,   266,   271,   276,   281,   286,   290,
     295,   299,   303,   310,   313,   317,   324,   328,   334,   337,
     344,   349,   355,   363,   366,   372,   379,   382,   388,   392,
     398,   404,   407,   413,   417
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
  "statements", "statement", "l_exp", "r_exp", "actual_arg_section",
  "actual_args", "elif_section", "elif_blocks", "elif_block",
  "else_section", "else_block", "method_section", "methods", "method",
  "return_type", "statement_block", YY_NULLPTR
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

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    21,    27,     8,     4,   -32,    17,    40,    30,   -32,
      26,   -32,    37,   -32,   126,   126,    77,   126,   119,   -32,
      43,   -32,    -5,   134,   -32,    59,   -32,    69,   -32,    16,
      40,   -32,   112,   -32,   -32,   194,   194,   -32,   149,   237,
      49,   210,   -32,    81,   126,   126,   126,   126,   126,   126,
      82,   126,   126,   126,   126,   126,   126,   -32,    22,    92,
     -32,    73,    72,   -32,   -15,   -32,   -32,    78,   -32,   226,
      39,    93,    99,   -32,   -32,   -32,   -32,    76,   164,   237,
     237,   241,   241,   241,    37,   241,   241,    57,    57,   -32,
     -32,   -32,   107,    85,    92,   -32,   -32,   110,   -32,   115,
     -32,   -32,   126,    44,    94,   126,   122,    99,   -32,   126,
     -32,   -32,    30,   -32,   -32,   -32,   -32,   226,   -32,   -32,
     194,   101,   -32,   -32,   -32,   179,   103,   -32,   -32,   -32,
     121,   101,   -32,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     4,     6,     0,    10,     0,     1,
       0,    34,    33,    35,     0,     0,     0,     0,     0,     2,
       0,    23,    36,     0,     5,     0,     7,     0,     9,     0,
      10,    31,     0,    50,    36,     0,     0,    30,     0,    48,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,    66,
      11,     0,     0,    12,     0,    16,     8,     0,    53,    57,
       0,     0,    58,    25,    29,    52,    51,     0,     0,    46,
      47,    42,    44,    41,    32,    43,    45,    37,    38,    39,
      40,    19,     0,     0,    67,    69,    14,     0,    13,     0,
      55,    54,     0,     0,     0,     0,    63,    59,    61,     0,
      27,    49,     0,    18,    68,    17,    15,    56,    74,    73,
       0,     0,    24,    64,    60,     0,    71,    62,    65,    26,
       0,     0,    72,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   -32,   -32,   132,   -32,   108,    25,   -32,    45,
     -32,   -18,   -32,   123,     3,   -14,    55,   -32,   -32,   -32,
      38,   -32,   -32,   -32,   -32,    52,   -32,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    28,    30,    64,    65,
      26,    19,    20,    21,    34,    23,    33,    70,   106,   107,
     108,   122,   123,    93,    94,    95,   131,    72
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
     -21,    14,    27,   104,    15,    91,    16,    31,    29,    17,
      58,    31,    11,    12,    13,    32,   -20,    14,   101,   102,
      15,    18,    16,    60,    22,    17,   -21,   118,    75,    31,
      11,    12,    13,    55,    56,    77,    84,    18,   117,   127,
     128,   120,   -20,    17,   103,   125,    11,    12,    13,    92,
     133,    14,    96,    97,    15,    18,    16,   100,   105,    17,
     109,   112,    37,    67,   115,    11,    12,    13,   113,    62,
      40,    18,    11,    12,    13,   132,   -20,   119,    17,    11,
      12,    13,   121,    71,   130,    17,    24,   126,    66,   111,
      18,    68,    17,    42,   116,   124,   114,    18,    45,    46,
       0,    47,    48,    49,    18,    50,    51,    52,    53,    54,
      55,    56,     0,    45,    46,     0,    47,    48,    49,    57,
      50,    51,    52,    53,    54,    55,    56,     0,    45,    46,
       0,    47,    48,    49,    74,    50,    51,    52,    53,    54,
      55,    56,     0,    45,    46,     0,    47,    48,    49,   110,
      50,    51,    52,    53,    54,    55,    56,     0,    45,    46,
       0,    47,    48,    49,   129,    50,    51,    52,    53,    54,
      55,    56,     0,     0,    45,    46,    71,    47,    48,    49,
       0,    50,    51,    52,    53,    54,    55,    56,     0,    76,
      45,    46,     0,    47,    48,    49,     0,    50,    51,    52,
      53,    54,    55,    56,    47,    48,    49,     0,     0,    51,
      52,    53,    54,    55,    56,    53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
      14,    15,    16,    17,    18,    36,     3,    25,     0,     1,
       6,     3,     4,     5,    29,    30,     8,     1,    32,    11,
       4,    13,     1,    20,    16,     4,    31,     0,    25,    34,
      44,    45,    46,    47,    48,    49,    28,    51,    52,    53,
      54,    55,    56,     0,     1,    29,     3,     4,     5,    32,
       7,     8,    12,    71,    11,    33,    13,    35,    28,    16,
       1,    35,     3,     4,     5,    28,     7,     8,    29,    30,
      11,    28,    13,     4,    71,    16,    33,    33,    29,    35,
       3,     4,     5,    26,    27,     4,     4,    28,   102,   120,
     121,   105,    33,    16,     1,   109,     3,     4,     5,     7,
     131,     8,    29,    31,    11,    28,    13,    29,     9,    16,
      34,     4,    35,     1,     4,     3,     4,     5,    33,     4,
       1,    28,     3,     4,     5,     4,    33,    33,    16,     3,
       4,     5,    10,    32,    31,    16,     4,   112,    30,    84,
      28,    29,    16,    20,    99,   107,    94,    28,    14,    15,
      -1,    17,    18,    19,    28,    21,    22,    23,    24,    25,
      26,    27,    -1,    14,    15,    -1,    17,    18,    19,    35,
      21,    22,    23,    24,    25,    26,    27,    -1,    14,    15,
      -1,    17,    18,    19,    35,    21,    22,    23,    24,    25,
      26,    27,    -1,    14,    15,    -1,    17,    18,    19,    35,
      21,    22,    23,    24,    25,    26,    27,    -1,    14,    15,
      -1,    17,    18,    19,    35,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    14,    15,    32,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      14,    15,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    17,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    27,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    37,    38,    39,    40,    41,     1,     4,     0,
       1,     3,     4,     5,     8,    11,    13,    16,    28,    47,
      48,    49,    50,    51,    40,    32,    46,    12,    42,    28,
      43,    35,    28,    52,    50,    51,    51,    35,    51,    51,
       1,    51,    49,    31,    34,    14,    15,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    27,    35,     1,    47,
       4,     1,     4,    29,    44,    45,    42,     1,    29,    51,
      53,    32,    63,    63,    35,    29,    29,     4,    51,    51,
      51,    51,    51,    51,     4,    51,    51,    51,    51,    51,
      51,    33,     7,    59,    60,    61,    29,    31,    29,    30,
      29,    29,    30,     1,    47,     9,    54,    55,    56,    34,
      35,    52,     4,    33,    61,     4,    45,    51,    33,    33,
      51,    10,    57,    58,    56,    51,    43,    63,    63,    35,
      31,    62,     4,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    41,    41,
      42,    42,    43,    43,    43,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     1,     2,     4,     3,
       0,     2,     2,     3,     3,     3,     1,     3,     4,     3,
       0,     1,     2,     1,     5,     3,     6,     4,     2,     3,
       2,     2,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     4,
       2,     3,     3,     2,     3,     3,     3,     1,     0,     1,
       2,     1,     3,     0,     1,     2,     0,     1,     2,     1,
       5,     0,     2,     3,     3
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
#line 49 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("program", "program");
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));

		ast.root = (yyval.node);
		ast.processClasses();
		//ast.printTree();
	}
#line 1378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 61 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", "class section");
	}
#line 1385 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 64 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);
	}
#line 1392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-1].node);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1400 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("classes", "classes");
	  	(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new ClassNode((yyvsp[-1].node)->label, (yyvsp[-1].node)->type);
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));
		ast.addClass((yyval.node));
	}
#line 1418 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node((yyvsp[-2].sval), (yyvsp[0].sval));
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 94 "parser.y" /* yacc.c:1646  */
    {	nerrors++;
	}
#line 1433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 100 "parser.y" /* yacc.c:1646  */
    {	(yyval.sval) = strdup("Obj");
	}
#line 1440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "parser.y" /* yacc.c:1646  */
    {	(yyval.sval) = (yyvsp[0].sval);
 	}
#line 1447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", "formal_arg_section");
	}
#line 1454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 112 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("formal_arg_section", "formal_arg_section");
  		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "parser.y" /* yacc.c:1646  */
    { 	(yyval.node) = new Node("ERROR", "formal_arg_section");
		nerrors++;
	}
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("formal_args", "formal_args");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 128 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("formal_args", "formal_args");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node((yyvsp[-2].sval), (yyvsp[0].sval));
	}
#line 1494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 140 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("class_body", "class_body");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 145 "parser.y" /* yacc.c:1646  */
    { 	(yyval.node) = new Node("ERROR", "class_body");
		nerrors++;
	}
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 152 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", "statement_section");
	}
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 155 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);
	}
#line 1525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 161 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-1].node);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 165 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("statements", "statements");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 172 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("IF statement", "statement");
		(yyval.node)->addChild((yyvsp[-3].node));
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 179 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("while loop", "statement");
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 184 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("typed assignment", "statement");
		(yyval.node)->addChild((yyvsp[-5].node));
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 189 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("assignment", "statement");
		(yyval.node)->addChild((yyvsp[-3].node));
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 194 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("statement", "statement");
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 198 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("RETURN", "statement");
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1595 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 202 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("RETURN", "statement");
	}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 205 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("ERROR", "statement");
		nerrors++;
	}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 212 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node((yyvsp[0].sval), "l_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
	}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 216 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node((yyvsp[0].sval), "l_exp");
	}
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 222 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new IntNode((yyvsp[0].ival), "r_exp (int_lit)");
	}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 225 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node((yyvsp[0].sval), "r_exp (String_lit)");
	}
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 228 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("L_EXP", "r_exp");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 232 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("Add", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 237 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("Subtract", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 242 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("Multiply", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 247 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("Divide", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 252 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("==", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 257 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("<=", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 262 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("<", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node(">=", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 272 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node(">", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 277 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("AND", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 282 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("OR", "r_exp");
		(yyval.node)->addChild((yyvsp[-2].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 287 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("NOT", "r_exp");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 291 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("r_exp", "r_exp");
		(yyval.node)->addChild((yyvsp[-3].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 296 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("method call", "r_exp");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 300 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("r_exp", "r_exp");
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 304 "parser.y" /* yacc.c:1646  */
    { 	nerrors++;
		(yyval.node) = new Node("ERROR", "r_exp");
	}
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 311 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", "actual_arg_section");
	}
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 314 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("actual_arg_section", "actual_arg_section");
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 318 "parser.y" /* yacc.c:1646  */
    { 	(yyval.node) = new Node("ERROR", "actual_arg_section");
		nerrors++;
	}
#line 1810 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 325 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-2].node);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 329 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);
	}
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 335 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", "elif_section");
	}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 338 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("elif_secion", "elif_section");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 345 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("elif_blocks", "elif_blocks");
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 350 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("elif_blocks", "elif_blocks");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 356 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("ELIF", "elif_block");
		(yyval.node)->addChild((yyvsp[-1].node));
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1866 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 364 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", "else_section");
	}
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 367 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("else_section", "else_section");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 373 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("ELSE", "else_block");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 380 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", "method_section");
	}
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 383 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);
	}
#line 1903 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 389 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[-1].node);
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 393 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("methods", "methods");
		(yyval.node)->addChild((yyvsp[0].node));
	}
#line 1919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 399 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node((yyvsp[-3].sval), "method");
	}
#line 1926 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 405 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("EMPTY", "return_type");
	}
#line 1933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 408 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node((yyvsp[0].sval), "return_type");
	}
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 414 "parser.y" /* yacc.c:1646  */
    {	(yyval.node) = new Node("statement_section", "statement_block");
		(yyval.node)->addChild((yyvsp[-1].node));
	}
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 418 "parser.y" /* yacc.c:1646  */
    { 	(yyval.node) = new Node("ERROR", "statement_block");
		nerrors++;
	}
#line 1956 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1960 "parser.tab.c" /* yacc.c:1646  */
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
#line 423 "parser.y" /* yacc.c:1906  */

int main(int argc, char* argv[])
{	if (argc > 1)
	{	file = fopen(argv[1], "r");
		if (!file)
		{	cerr << "Error opening file!" << endl;
			return -1;
		}
		fn = argv[1];
		yyin = file;
	}

	do
	{	yyparse();
	} while (!feof(yyin));

	return 0;
}

void yyerror(const char *s)
{	cerr << fn << ":" << yylineno << ": " << s << endl;
}
