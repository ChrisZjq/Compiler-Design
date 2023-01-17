/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TYPE = 258,
     ID = 259,
     SEMICOLON = 260,
     STARTFUN = 261,
     ENDFUN = 262,
     STARTPASS = 263,
     ENDPASS = 264,
     STARTARRAY = 265,
     ENDARRAY = 266,
     EQ = 267,
     PLUS = 268,
     COMMA = 269,
     NUMBER = 270,
     WRITE = 271,
     RETURN = 272,
     IF = 273,
     ELSE = 274,
     GREATERTHAN = 275,
     LESSTHAN = 276
   };
#endif
/* Tokens.  */
#define TYPE 258
#define ID 259
#define SEMICOLON 260
#define STARTFUN 261
#define ENDFUN 262
#define STARTPASS 263
#define ENDPASS 264
#define STARTARRAY 265
#define ENDARRAY 266
#define EQ 267
#define PLUS 268
#define COMMA 269
#define NUMBER 270
#define WRITE 271
#define RETURN 272
#define IF 273
#define ELSE 274
#define GREATERTHAN 275
#define LESSTHAN 276




/* Copy the first part of user declarations.  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
//FILE * MIPScode;


void yyerror(const char* s);
char currentScope[50] ="Global"; // "global" or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks

//The following union enables four data types, which are number character string and ast


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "parser.y"
{
	int number;
	char character;
	char* string;
	struct AST* ast;
}
/* Line 193 of yacc.c.  */
#line 171 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 184 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   90

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  22
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNRULES -- Number of states.  */
#define YYNSTATES  83

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    17,    18,
      21,    27,    28,    36,    37,    40,    44,    45,    48,    50,
      53,    55,    57,    61,    64,    68,    72,    75,    82,    89,
      95,    99,   103,   107,   111,   115,   119,   123,   127,   131,
     137,   145,   149,   153,   157,   158,   160,   162
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      23,     0,    -1,    24,    -1,    25,    24,    -1,    25,    -1,
      27,    -1,    26,     5,    -1,    31,    -1,    -1,     3,     4,
      -1,     3,     4,    10,    37,    11,    -1,    -1,     3,     4,
       8,    28,    29,     9,    30,    -1,    -1,     6,     7,    -1,
       6,    24,     7,    -1,    -1,    32,    31,    -1,     5,    -1,
      33,     5,    -1,    35,    -1,    34,    -1,     4,    12,    36,
      -1,    17,    37,    -1,     4,    12,     4,    -1,     4,    12,
      15,    -1,    16,     4,    -1,     4,    10,    15,    11,    12,
      15,    -1,     4,    10,    15,    11,    12,     4,    -1,    16,
       4,    10,    15,    11,    -1,     4,     8,     9,    -1,    15,
      20,    15,    -1,    15,    21,    15,    -1,     4,    20,    15,
      -1,     4,    21,    15,    -1,    15,    21,     4,    -1,    15,
      20,     4,    -1,     4,    20,     4,    -1,     4,    21,     4,
      -1,    18,     8,    34,     9,    30,    -1,    18,     8,    34,
       9,    30,    19,    30,    -1,     4,    13,    15,    -1,     4,
      13,     4,    -1,    15,    13,    15,    -1,    -1,     4,    -1,
      15,    -1,     6,    33,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    72,    75,    78,    79,    80,    83,    84,
     103,   126,   126,   144,   146,   147,   150,   151,   154,   155,
     156,   157,   160,   164,   167,   224,   291,   330,   345,   360,
     364,   368,   371,   375,   379,   383,   387,   391,   395,   400,
     401,   402,   441,   480,   498,   499,   500,   501
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "ID", "SEMICOLON", "STARTFUN",
  "ENDFUN", "STARTPASS", "ENDPASS", "STARTARRAY", "ENDARRAY", "EQ", "PLUS",
  "COMMA", "NUMBER", "WRITE", "RETURN", "IF", "ELSE", "GREATERTHAN",
  "LESSTHAN", "$accept", "Program", "DeclList", "Decl", "VarDecl",
  "FunDecl", "@1", "ParamDeclList", "Block", "StmtList", "Stmt", "Expr",
  "Condition", "IfExpr", "Iteration", "Primary", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    22,    23,    24,    24,    25,    25,    25,    26,    26,
      26,    28,    27,    29,    30,    30,    31,    31,    32,    32,
      32,    32,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    34,    34,    34,    34,    34,    34,    34,    34,    35,
      35,    36,    36,    36,    37,    37,    37,    37
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     0,     2,
       5,     0,     7,     0,     2,     3,     0,     2,     1,     2,
       1,     1,     3,     2,     3,     3,     2,     6,     6,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       7,     3,     3,     3,     0,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      16,     0,     0,    18,     0,     0,    44,     0,     0,     2,
       4,     0,     5,     7,    16,     0,    21,    20,     9,     0,
       0,     0,     0,     0,     0,     0,    26,    45,     0,    46,
      23,     0,     1,     3,     6,    17,    19,    11,    44,    30,
       0,    24,    25,    22,    37,    33,    38,    34,    36,    31,
      35,    32,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,    47,     0,     0,    10,     0,    42,    41,
      43,    29,     0,    39,     0,    28,    27,    14,     0,     0,
      12,    15,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,    57,    65,    73,    13,
      14,    15,    16,    17,    43,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int8 yypact[] =
{
       3,     6,    18,   -71,    43,    13,    28,    19,    53,   -71,
       3,    26,   -71,   -71,     7,    60,   -71,   -71,    44,    49,
      51,    29,    31,    32,    33,    36,    57,   -71,    25,   -71,
     -71,    41,   -71,   -71,   -71,   -71,   -71,   -71,    28,   -71,
      59,    58,    61,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,    62,    47,    65,    48,    64,   -71,    67,    63,
      45,    66,    68,   -71,    70,    71,   -71,    46,   -71,   -71,
     -71,   -71,    -2,    69,    70,   -71,   -71,   -71,    75,    70,
     -71,   -71,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -10,   -71,   -71,   -71,   -71,   -71,   -70,    72,
     -71,    55,    54,   -71,   -71,    52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,     1,     2,     3,    80,    77,     1,     2,     3,    82,
      18,     2,     3,     4,     5,     6,     7,    26,     4,     5,
       6,     7,     4,     5,     6,     7,    19,    31,    20,    53,
      21,    34,    27,    41,    28,    44,    46,    48,    22,    23,
      50,     5,     6,    29,    42,    55,    45,    47,    49,    68,
      75,    51,    37,    32,    38,    19,     4,    20,    39,    21,
      69,    76,    78,    24,    25,    36,    40,    52,    22,    23,
      59,    60,    63,    64,    61,    67,    72,    62,    66,    71,
      74,    70,    81,    54,     0,    56,    35,     0,    79,     0,
      58
};

static const yytype_int8 yycheck[] =
{
      10,     3,     4,     5,    74,     7,     3,     4,     5,    79,
       4,     4,     5,    15,    16,    17,    18,     4,    15,    16,
      17,    18,    15,    16,    17,    18,     8,     8,    10,     4,
      12,     5,     4,     4,     6,     4,     4,     4,    20,    21,
       4,    16,    17,    15,    15,     4,    15,    15,    15,     4,
       4,    15,     8,     0,    10,     8,    15,    10,     9,    12,
      15,    15,    72,    20,    21,     5,    15,    10,    20,    21,
      11,    13,     7,     9,    13,    12,     6,    15,    11,    11,
       9,    15,     7,    28,    -1,    31,    14,    -1,    19,    -1,
      38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    15,    16,    17,    18,    23,    24,
      25,    26,    27,    31,    32,    33,    34,    35,     4,     8,
      10,    12,    20,    21,    20,    21,     4,     4,     6,    15,
      37,     8,     0,    24,     5,    31,     5,     8,    10,     9,
      15,     4,    15,    36,     4,    15,     4,    15,     4,    15,
       4,    15,    10,     4,    33,     4,    34,    28,    37,    11,
      13,    13,    15,     7,     9,    29,    11,    12,     4,    15,
      15,    11,     6,    30,     9,     4,    15,     7,    24,    19,
      30,     7,    30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      case 4: /* "ID" */
#line 56 "parser.y"
	{ fprintf(yyoutput, "%s", (yyvaluep->string)); };
#line 780 "parser.tab.c"
	break;
      case 15: /* "NUMBER" */
#line 57 "parser.y"
	{ fprintf(yyoutput, "%d", (yyvaluep->number)); };
#line 785 "parser.tab.c"
	break;
      case 17: /* "RETURN" */
#line 58 "parser.y"
	{ fprintf(yyoutput, "%s", (yyvaluep->string)); };
#line 790 "parser.tab.c"
	break;
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 66 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast);
					 printf("\n--- Abstract Syntax Tree ---\n\n");
					 printAST((yyval.ast),0);
					;}
    break;

  case 3:
#line 72 "parser.y"
    { (yyvsp[(1) - (2)].ast)->left = (yyvsp[(2) - (2)].ast);
							  (yyval.ast) = (yyvsp[(1) - (2)].ast);
							;}
    break;

  case 4:
#line 75 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 8:
#line 83 "parser.y"
    {;}
    break;

  case 9:
#line 84 "parser.y"
    { printf("\n RECOGNIZED RULE: Variable declaration %s\n", (yyvsp[(2) - (2)].string));
									// Symbol Table
									symTabAccess();
									int inSymTab = found((yyvsp[(2) - (2)].string), currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									printf("Current scope is: %s\n", currentScope);

									if (inSymTab == 0) 
										addItem((yyvsp[(2) - (2)].string), "Var", (yyvsp[(1) - (2)].string),0, currentScope);
										
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (2)].string));
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    (yyval.ast) = AST_Type("Type",(yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].string));
									printf("-----------> %s", (yyval.ast)->LHS);
								;}
    break;

  case 10:
#line 103 "parser.y"
    {printf("\n RECOGNIZED RULE: Array declaration %s\n", (yyvsp[(2) - (5)].string));
									symTabAccess();
									
									int inSymTab = found((yyvsp[(2) - (5)].string) , currentScope);

									printf("Current scope is: %s\n", currentScope);

									if(inSymTab == 0)
										addItem((yyvsp[(2) - (5)].string),"Array",(yyvsp[(1) - (5)].string),(yyvsp[(4) - (5)].ast),currentScope);
										
										// showSymTable();
									else 
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (5)].string));
									showSymTable();

									// ---- SEMANTIC ACTIONS by PARSER ----
									(yyval.ast) = AST_Type("Array",(yyvsp[(1) - (5)].string),(yyvsp[(2) - (5)].string));
									printf("-----------> %s", (yyval.ast)->LHS);

									emitMIPSArray((yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].ast));
									;}
    break;

  case 11:
#line 126 "parser.y"
    { 

	sprintf(currentScope,"%s",(yyvsp[(2) - (3)].string)); 
	emitMIPSFunction((yyvsp[(2) - (3)].string));

	;}
    break;

  case 12:
#line 131 "parser.y"
    { 
		printf("\n RECOGNIZED RULE: Function declaration %s\n", (yyvsp[(2) - (7)].string));
		
		printf("Current scope is: %s\n", currentScope);
		addItem((yyvsp[(2) - (7)].string),"Fun","fun",0,"Global");
		//  sprintf(str, "%d", $3); convert $3 from int to string
		printf("new scope is: %s\n", currentScope);
		// emitMIPSFunction($2);

		showSymTable();	
		
;}
    break;

  case 13:
#line 144 "parser.y"
    { /* epsilon - no variable declarations are an option */;}
    break;

  case 15:
#line 147 "parser.y"
    {;}
    break;

  case 18:
#line 154 "parser.y"
    {;}
    break;

  case 19:
#line 155 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (2)].ast);;}
    break;

  case 20:
#line 156 "parser.y"
    {;}
    break;

  case 21:
#line 157 "parser.y"
    {;}
    break;

  case 22:
#line 160 "parser.y"
    {printf("\n\n\n\n Iteration after Expression");
				printf(": %d\n\n\n%s\n\n", (yyvsp[(3) - (3)].ast) , (yyvsp[(1) - (3)].string))	
				//emitAssignment($1, $3);
	;}
    break;

  case 23:
#line 164 "parser.y"
    { printf("\n RECOGNIZED RULE: RETURN %d\n", (yyvsp[(2) - (2)].ast));
		emitMIPSEndFunction();
	;}
    break;

  case 24:
#line 167 "parser.y"
    { printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ---- //
					  (yyval.ast) = AST_assignment("=",(yyvsp[(1) - (3)].string),(yyvsp[(3) - (3)].string));

					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared

					    if(found((yyvsp[(1) - (3)].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[(1) - (3)].string), currentScope);
							semanticCheckPassed = 0;
						}
					    if(found((yyvsp[(3) - (3)].string), currentScope) != 1){
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[(1) - (3)].string), currentScope);
							semanticCheckPassed = 0;
						}

					// Check types

						printf("\nChecking types: \n");
						int typeMatch = compareTypes ((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), currentScope);
						if (typeMatch == 0){
							printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
							semanticCheckPassed = 0;
						}
						

					if (semanticCheckPassed == 1) {
						printf("\n\n>>> AssignStmt Rule is SEMANTICALLY correct and IR code is emitted! <<<\n\n");

						// ---- EMIT IR 3-ADDRESS CODE ---- //
						
						// The IR code is printed to a separate file

						// Temporary variables management will eventually go in here
						// and the paramaters of the function below will change
						// to using T0, ..., T9 variables

						emitAssignment((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));

						// ----     EMIT MIPS CODE   ----  //

						// The MIPS code is printed to a separate file

						// MIPS registers management will eventually go in here
						// and the paramaters of the function below will change
						// to using $t0, ..., $t9 registers

						emitMIPSAssignment((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));



					}
					

				;}
    break;

  case 25:
#line 224 "parser.y"
    { printf("\n RECOGNIZED RULE: Constant Assignment statement\n"); 
	
					   // ---- SEMANTIC ACTIONS by PARSER ----
					   char str[50];
						
					   sprintf(str, "%d", (yyvsp[(3) - (3)].number)); // convert $3 from int to string
					   (yyval.ast) = AST_assignment("=",(yyvsp[(1) - (3)].string), str);

						// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

						// Check if identifiers have been declared

					    if(found((yyvsp[(1) - (3)].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[(1) - (3)].string), currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

						printf("\nChecking types: \n");

						//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
						
						printf("%s = %s\n", "int", "number");  // This temporary for now, until the line above is debugged and uncommented
						
						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							// Symbol Table Editing itemKind
							// char num[50] = $3;
							
							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file

							// Temporary variables management will eventually go in here
							// and the paramaters of the function below will change
							// to using T0, ..., T9 variables

							char itemName[50], id2[50],itemId[10];
							sprintf(itemName, "%s", (yyvsp[(1) - (3)].string));
							sprintf(id2, "%d", (yyvsp[(3) - (3)].number));

							newItemKind(itemName,id2,currentScope);

							sprintf(itemId, "%d",getIdByItemName(itemName,currentScope));

							printf("\n\n\n ITEM ID %s \n\n", (itemId));
							// Temporary variables management will eventually go in here
							// and the paramaters of the function below will change
							// to using T0, ..., T9 variables

							//emitConstantIntAssignment(id1, id2);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers


							emitMIPSConstantIntAssignment(atoi(itemId), id2);

						}
					;}
    break;

  case 26:
#line 291 "parser.y"
    { printf("\n RECOGNIZED RULE: WRITE statement\n");

					(yyval.ast) = AST_Write("write",(yyvsp[(2) - (2)].string),"");
					
					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared
					if(found((yyvsp[(2) - (2)].string), currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[(2) - (2)].string), currentScope);
							semanticCheckPassed = 0;
						}

					if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");

							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							
							emitWriteId((yyvsp[(2) - (2)].string));

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers

							char itemName[50],itemId[10];
							sprintf(itemName, "%s", (yyvsp[(2) - (2)].string));
							sprintf(itemId, "%d",getIdByItemName(itemName,currentScope));

							printf("\n\n\n ITEM ID %s \n\n", (itemId));
						
							emitMIPSWriteId(itemId);
			
						}
				;}
    break;

  case 27:
#line 330 "parser.y"
    { printf("\n Access to an element of the array.\n");
			//find array in symbol table
			//find position in symbol table and assign value
			char itemName[50], value[50],arrayPosition[10];
			sprintf(itemName, "%s", (yyvsp[(1) - (6)].string));
			sprintf(value, "%d", (yyvsp[(6) - (6)].number));
			sprintf(arrayPosition, "%d",(yyvsp[(3) - (6)].number));
			assignArray(itemName,arrayPosition,value);
			// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

			// ----     EMIT MIPS CODE   ----  //
			emitMIPSIntegerAssignmentArray((yyvsp[(3) - (6)].number),(yyvsp[(6) - (6)].number));


		;}
    break;

  case 28:
#line 345 "parser.y"
    { printf("\n Access to an element of the array.\n");
			//find array in symbol table
			//find position in symbol table and assign value
			char itemName[50], value[50],arrayPosition[10];
			sprintf(itemName, "%s", (yyvsp[(1) - (6)].string));
			int foundValue = atoi(getVariableValue((yyvsp[(6) - (6)].string), currentScope));
			sprintf(arrayPosition, "%d",(yyvsp[(3) - (6)].number));
			assignArray(itemName,arrayPosition,getVariableValue((yyvsp[(6) - (6)].string), currentScope));
			// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

			// ----     EMIT MIPS CODE   ----  //
			emitMIPSIntegerAssignmentArray((yyvsp[(3) - (6)].number),atoi(getVariableValue((yyvsp[(6) - (6)].string), currentScope)));


		;}
    break;

  case 29:
#line 360 "parser.y"
    {	printf("\n RECOGNIZED RULE: WRITE element from array\n");
			emitMIPSWriteArray((yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].number));

		;}
    break;

  case 30:
#line 364 "parser.y"
    {	printf("\n CALLING A FUNCTION");
		emitMIPSCallFunction((yyvsp[(1) - (3)].string));
	;}
    break;

  case 31:
#line 368 "parser.y"
    {printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %d Greater than %d \n\n\n",(yyvsp[(1) - (3)].number), (yyvsp[(3) - (3)].number))
			
		;}
    break;

  case 32:
#line 371 "parser.y"
    {printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %d Less than %d \n\n\n",(yyvsp[(1) - (3)].number), (yyvsp[(3) - (3)].number))
		
		
		;}
    break;

  case 33:
#line 375 "parser.y"
    {printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %s Greater than %d \n\n\n",(yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].number))
		
		
		;}
    break;

  case 34:
#line 379 "parser.y"
    {printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %s Less than %d \n\n\n",(yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].number))
		
		
		;}
    break;

  case 35:
#line 383 "parser.y"
    {printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %d Less than %s \n\n\n",(yyvsp[(1) - (3)].number), (yyvsp[(3) - (3)].string))
		
		
		;}
    break;

  case 36:
#line 387 "parser.y"
    {printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %d Greater than %s \n\n\n",(yyvsp[(1) - (3)].number), (yyvsp[(3) - (3)].string))
		
		
		;}
    break;

  case 37:
#line 391 "parser.y"
    {printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %s Greater than %s \n\n\n",(yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string))
		
		
		;}
    break;

  case 38:
#line 395 "parser.y"
    {printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %s Less than %s \n\n\n",(yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string))
		
		
		;}
    break;

  case 39:
#line 400 "parser.y"
    {;}
    break;

  case 40:
#line 401 "parser.y"
    {;}
    break;

  case 41:
#line 402 "parser.y"
    {
			printf("\nRECOGNIZED RULE: Iterating Expression:\n");
			int num = 0;
			char id1[10], id2[10];
			//sprintf(id1, "%d", $1);
			sprintf(id2, "%d", (yyvsp[(3) - (3)].number));
			//printf("\n%d,is a number add it, %d\n", $1,Iteration_Number_AST(id1));

			if(found((yyvsp[(1) - (3)].string),currentScope) == 1){
				printf("\nHere is a found number in Symbol Table %s : ",(yyvsp[(1) - (3)].string));
				int foundValue = atoi(getVariableValue((yyvsp[(1) - (3)].string), currentScope));
				printf("%d \n",foundValue);

				num += foundValue;

			} else {
				printf("\nInvalid variable used in Statement!\n");
			}

			if(!num == 0 && Iteration_Number_AST(id2) == 1){
				//printf("\n%d\n",$1->nodeType);
				//int b = $3;
				//printf("\n%d\n",$3->nodeType);
				int number = num + (yyvsp[(3) - (3)].number);
				printf("\n%d + %d = %i\n",num, (yyvsp[(3) - (3)].number), number);
				num += number;
				printf("\n new value: %d\n",number);
				char charpass[10], str[50], itemId[10];
				sprintf(charpass, "%d", number);
				sprintf(str, "%s", iterationKind(charpass,0)); 
				printf("\n\n\n\n THE VARIABLE USED: %s",str);

				sprintf(itemId, "%d",getIdByItemName(str,currentScope));
				printf("\n\n\n ITEM ID %s \n\n", (itemId));
				
				emitMIPSConstantIntAssignment(atoi(itemId),charpass);

			} 
		;}
    break;

  case 42:
#line 441 "parser.y"
    {
			printf("\nRECOGNIZED RULE: On 2 Variables Iterating Expression:\n");
			//int num = $1->nodeType;
			int num = 0;
			//sprintf(id1, "%d", $1);
			//printf("\n%d,is a number add it, %d\n", $1,Iteration_Number_AST(id1));

			if(found((yyvsp[(1) - (3)].string),currentScope) == 1 && found((yyvsp[(3) - (3)].string),currentScope) == 1){
				printf("\nHere is a found number in Symbol Table %s : ",(yyvsp[(1) - (3)].string));
				int foundValue = atoi(getVariableValue((yyvsp[(1) - (3)].string), currentScope));
				int foundValue1 = atoi(getVariableValue((yyvsp[(3) - (3)].string), currentScope));
				printf("%d \n",foundValue);
				int number  = foundValue + foundValue1;
				printf("\n%d + %d = %i\n",foundValue, foundValue1, number);
				char charpass[10];
				sprintf(charpass, "%d", number);
				char str[50],itemId[10];
				//temp work around
				sprintf(str, "%s", iterationKind(charpass,0)); 
				printf("\n\n\n\n THE VARIABLE USED: %s",str);

				sprintf(itemId, "%d",getIdByItemName(str,currentScope));
				printf("\n\n\n ITEM ID %s \n\n", (itemId));
				
				emitMIPSConstantIntAssignment(atoi(itemId),charpass);
				//when multiple iterations
				
				num += number;

			} else {
				printf("\nInvalid variable used in Statement!\n");
			}
			// else {
			// 	int number = 0 + $1->nodeType;
			// 	num += number;
			// 	printf("\n%d + %d = %i\n",0, $1->nodeType, number);
			// 	printf("Added %d\n",num);
			// }
		;}
    break;

  case 43:
#line 480 "parser.y"
    {
			printf("\nRECOGNIZED RULE: On 2 Variables Iterating Expression:\n");
			char id1[10], id2[10];
			sprintf(id1, "%d", (yyvsp[(1) - (3)].number));
			sprintf(id2, "%d", (yyvsp[(3) - (3)].number));
			if(Iteration_Number_AST(id1) == 1 && Iteration_Number_AST(id2) == 1){
				int number = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
				printf("\n%d + %d = %i\n",(yyvsp[(1) - (3)].number), (yyvsp[(3) - (3)].number), number);
				printf("\n new value: %d\n",number);
				char charpass[10];
				sprintf(charpass, "%d", number);
				iterationKind(charpass,0);
				// showSymTable();


			} 
		;}
    break;

  case 44:
#line 498 "parser.y"
    {;}
    break;

  case 45:
#line 499 "parser.y"
    {"%s",(yyvsp[(1) - (1)].string);}
    break;

  case 46:
#line 500 "parser.y"
    {"%d",(yyvsp[(1) - (1)].number);}
    break;


/* Line 1267 of yacc.c.  */
#line 2027 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 507 "parser.y"


int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}

	// Initialize IR and MIPS files

	initIRcodeFile();

	initAssemblyFile();

	// Start parser
	yyparse();

	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
