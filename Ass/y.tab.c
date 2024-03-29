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
#line 1 "q1.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int yylex();
void yyerror();

struct identifier {
    char *id_name;
    char *data_type;
    char *type;
    union {
        int i;
        float f;
        char c;
    } val;
    union {
        int *i;
        float *f;
        char *c;
    } arr;
    int arr_len;
    int arr_len2;
    char *plist;
} id_table[50];
int id_cnt = 0;


struct node { 
    struct node *left; 
    struct node *right; 
    char *token; 
};

struct node *head;
int is_char(char *tk);
int find_id(char *iden_name);
char *get_type(char *iden_name);
void add_id(char c, char *iden_name, char *value, char *d_type, int d1, int d2);
int lookup_i(char *iden_name, int idx1, int idx2);
float lookup_f(char *iden_name, int idx1, int idx2);
char lookup_c(char *iden_name, int idx1, int idx2);
void update_id(char *iden_name, char *value, int idx1, int idx2);
struct node* mknode(struct node *left, struct node *right, char *token);


#line 118 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CHARFORMAT = 258,
    INTFORMAT = 259,
    FLOATFORMAT = 260,
    STRING = 261,
    INT = 262,
    FLOAT = 263,
    CHAR = 264,
    VOID = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    FOR = 269,
    SWITCH = 270,
    CASE = 271,
    BREAK = 272,
    DEFAULT = 273,
    CONTINUE = 274,
    RETURN = 275,
    PRINTF = 276,
    COLON = 277,
    ID = 278,
    ID1 = 279,
    ID2 = 280,
    NUM = 281,
    FLOATNUM = 282,
    CHARCONST = 283,
    FUNC = 284,
    LPAREN = 285,
    RPAREN = 286,
    LBRACE = 287,
    RBRACE = 288,
    SEMICOLON = 289,
    COMMA = 290,
    ASSIGNMENT = 291,
    LAND = 292,
    LOR = 293,
    NOTEQ = 294,
    EQUALS = 295,
    GTE = 296,
    LTE = 297,
    LT = 298,
    GT = 299,
    PLUS = 300,
    MINUS = 301,
    MULT = 302,
    DIV = 303,
    MOD = 304,
    LNOT = 305
  };
#endif
/* Tokens.  */
#define CHARFORMAT 258
#define INTFORMAT 259
#define FLOATFORMAT 260
#define STRING 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define VOID 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define SWITCH 270
#define CASE 271
#define BREAK 272
#define DEFAULT 273
#define CONTINUE 274
#define RETURN 275
#define PRINTF 276
#define COLON 277
#define ID 278
#define ID1 279
#define ID2 280
#define NUM 281
#define FLOATNUM 282
#define CHARCONST 283
#define FUNC 284
#define LPAREN 285
#define RPAREN 286
#define LBRACE 287
#define RBRACE 288
#define SEMICOLON 289
#define COMMA 290
#define ASSIGNMENT 291
#define LAND 292
#define LOR 293
#define NOTEQ 294
#define EQUALS 295
#define GTE 296
#define LTE 297
#define LT 298
#define GT 299
#define PLUS 300
#define MINUS 301
#define MULT 302
#define DIV 303
#define MOD 304
#define LNOT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "q1.y"
 
    struct type1 { 
        char name[100]; 
        struct node* nd;
        int idc;
    } nd_obj;
    struct type2 { 
        char name[100]; 
        struct node* nd;
        char type[6];
    } nd_obj2;

#line 283 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    83,    84,    86,    87,    88,    89,    91,
     100,   110,   119,   126,   127,   128,   129,   132,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     148,   149,   153,   154,   155,   158,   159,   160,   163,   168,
     173,   177,   183,   186,   189,   194,   204,   231,   232,   234,
     236,   239,   242,   250,   258,   261,   265,   272,   280,   288,
     296,   304,   312,   318,   326,   330,   334,   340,   353,   368,
     369,   381,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   398,   399,   400,   403
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHARFORMAT", "INTFORMAT", "FLOATFORMAT",
  "STRING", "INT", "FLOAT", "CHAR", "VOID", "IF", "ELSE", "WHILE", "FOR",
  "SWITCH", "CASE", "BREAK", "DEFAULT", "CONTINUE", "RETURN", "PRINTF",
  "COLON", "ID", "ID1", "ID2", "NUM", "FLOATNUM", "CHARCONST", "FUNC",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA",
  "ASSIGNMENT", "LAND", "LOR", "NOTEQ", "EQUALS", "GTE", "LTE", "LT", "GT",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "LNOT", "$accept", "start",
  "statement", "TYPE", "FUNCTION", "PARAMETER_LIST", "STATEMENT_LIST",
  "STATEMENT_BLOCK", "STATEMENT", "PRINT_STATEMENTS", "RETURN_STATEMENTS",
  "CONST", "ULTIMATE_LIST", "FOR_STATEMENT", "DECLARATION", "IF_STATEMENT",
  "MATCHED", "UNMATCHED", "WHILE_STATEMENT", "ASGNSTMT", "ASGNSTMT_LIST",
  "EXPRESSION", "TREEM", "TREEM2", "FUNCTION_CALLSTMTS", "ALLID",
  "Comperator", "CASES", "SWITCH_STMT", YY_NULLPTR
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
     305
};
# endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      80,  -102,  -102,  -102,  -102,     1,  -102,   -21,    80,  -102,
      24,  -102,   -23,    -4,    -5,    39,  -102,   -11,    80,   256,
     256,    72,     4,    -6,    10,   244,    45,  -102,  -102,  -102,
    -102,  -102,  -102,    12,   256,    39,  -102,    94,    37,    39,
      39,  -102,  -102,  -102,  -102,    38,  -102,  -102,  -102,  -102,
      44,   160,   228,  -102,  -102,    47,  -102,    39,    70,   118,
    -102,   132,   256,    64,    67,    47,    89,  -102,  -102,  -102,
      88,    90,    26,  -102,    91,    96,    98,   146,   101,    95,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,   256,   256,   256,   256,
     256,   256,   256,   105,  -102,   111,   111,   174,   256,   256,
     112,  -102,  -102,   113,   264,   264,  -102,   264,  -102,  -102,
     256,   228,  -102,  -102,  -102,  -102,  -102,   216,  -102,   134,
    -102,   141,   188,   202,    -2,  -102,   119,  -102,  -102,    71,
     141,  -102,   111,   120,   141,   141,   128,   145,   147,   144,
     143,  -102,   149,   161,   162,   169,    39,  -102,  -102,   256,
      39,   163,   173,    39,  -102,   216,   176,    39,    39,    -2,
    -102,  -102,   186,   187,  -102,  -102,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     6,     7,     8,     0,     2,     0,     4,     1,
       0,     3,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      35,    36,    37,     0,     0,     0,    29,     0,     0,    16,
      14,    18,    19,    64,    25,     0,    22,    47,    48,    24,
       0,     0,    56,    62,    66,    63,    23,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,    21,    20,    33,
       0,     0,     0,    67,    41,     0,    40,     0,     0,    69,
      46,     9,    15,    13,    28,    27,    26,    77,    78,    72,
      79,    76,    75,    73,    74,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,    34,    32,     0,     0,     0,    68,     0,    65,    17,
       0,    55,    57,    58,    59,    60,    61,    54,    10,    49,
      51,     0,     0,     0,    83,    30,     0,    39,    38,    45,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,    84,    31,     0,
       0,     0,     0,     0,    82,    54,     0,     0,     0,    83,
      53,    44,     0,     0,    81,    42,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   198,    76,  -102,  -102,   -28,  -101,  -102,  -102,
    -102,   -10,   -40,  -102,   200,  -102,  -102,  -102,  -102,    -8,
      42,   -17,   127,   164,  -102,   -15,  -102,    65,  -102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    37,     8,    14,    38,    39,    40,    41,
      42,    43,    75,    44,    45,    46,    47,    48,    49,    50,
     141,    51,    52,    53,    54,    60,    96,   148,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,     9,    59,    61,   129,   130,    65,    78,    10,    15,
      71,    82,    83,    64,   146,    70,   147,    77,    76,    16,
      55,    57,    80,    74,    55,    55,    17,    66,    67,   103,
      18,     1,     2,     3,     4,    27,    28,    29,    30,    31,
      32,   151,    55,    73,    68,   107,     1,     2,     3,     4,
      19,    72,    20,    21,    22,    12,    23,   113,    24,    25,
      26,   114,    27,    28,    29,    30,    31,    32,    33,    34,
      81,    35,    84,    36,   136,   137,     7,   138,    85,     1,
       2,     3,     4,   102,     7,   127,    13,     1,     2,     3,
       4,   132,   133,   104,    58,    27,    28,    29,   108,    76,
      76,   109,    76,   139,    74,    74,    62,    74,    87,    88,
      89,    90,    91,    92,    93,    94,    65,    79,    28,    29,
     110,    95,   111,   143,   112,   150,   115,   116,   164,    65,
      65,   120,   166,   117,   119,   169,   153,   154,   128,   172,
     173,    55,   165,    35,   134,    55,   142,   135,    55,   105,
     149,   152,    55,    55,   155,    87,    88,    89,    90,    91,
      92,    93,    94,   106,    27,    28,    29,   156,    95,    87,
      88,    89,    90,    91,    92,    93,    94,   118,   158,   159,
     157,   160,    95,    87,    88,    89,    90,    91,    92,    93,
      94,   163,   161,   162,    86,   167,    95,    87,    88,    89,
      90,    91,    92,    93,    94,   168,    11,   170,   131,   171,
      95,    87,    88,    89,    90,    91,    92,    93,    94,   175,
     176,    63,   144,   121,    95,    87,    88,    89,    90,    91,
      92,    93,    94,     0,   174,     0,   145,     0,    95,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,   140,    95,    87,    88,    89,    90,    91,    92,    93,
      94,   122,   123,   124,   125,   126,    95,    27,    28,    29,
      30,    31,    32,    97,    98,    99,   100,   101,    69,    27,
      28,    29,    30,    31,    32,    33,    34,    27,    28,    29,
      30,    31,    32
};

static const yytype_int16 yycheck[] =
{
      15,     0,    19,    20,   105,   106,    21,    35,    29,    32,
      25,    39,    40,    21,    16,    25,    18,    34,    33,    23,
      35,    32,    37,    33,    39,    40,    31,    23,    34,    57,
      35,     7,     8,     9,    10,    23,    24,    25,    26,    27,
      28,   142,    57,    31,    34,    62,     7,     8,     9,    10,
      11,     6,    13,    14,    15,    31,    17,    31,    19,    20,
      21,    35,    23,    24,    25,    26,    27,    28,    29,    30,
      33,    32,    34,    34,   114,   115,     0,   117,    34,     7,
       8,     9,    10,    36,     8,   102,    10,     7,     8,     9,
      10,   108,   109,    23,    18,    23,    24,    25,    34,   114,
     115,    34,   117,   120,   114,   115,    34,   117,    37,    38,
      39,    40,    41,    42,    43,    44,   131,    23,    24,    25,
      31,    50,    34,   131,    34,   140,    35,    31,   156,   144,
     145,    36,   160,    35,    33,   163,   144,   145,    33,   167,
     168,   156,   159,    32,    32,   160,    12,    34,   163,    31,
      31,    31,   167,   168,    26,    37,    38,    39,    40,    41,
      42,    43,    44,    31,    23,    24,    25,    22,    50,    37,
      38,    39,    40,    41,    42,    43,    44,    31,    34,    36,
      33,    32,    50,    37,    38,    39,    40,    41,    42,    43,
      44,    22,    31,    31,    34,    32,    50,    37,    38,    39,
      40,    41,    42,    43,    44,    32,     8,   165,    34,    33,
      50,    37,    38,    39,    40,    41,    42,    43,    44,    33,
      33,    21,    34,    96,    50,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,   169,    -1,    34,    -1,    50,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    35,    50,    37,    38,    39,    40,    41,    42,    43,
      44,    97,    98,    99,   100,   101,    50,    23,    24,    25,
      26,    27,    28,    45,    46,    47,    48,    49,    34,    23,
      24,    25,    26,    27,    28,    29,    30,    23,    24,    25,
      26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    52,    53,    54,    55,     0,
      29,    53,    31,    54,    56,    32,    23,    31,    35,    11,
      13,    14,    15,    17,    19,    20,    21,    23,    24,    25,
      26,    27,    28,    29,    30,    32,    34,    54,    57,    58,
      59,    60,    61,    62,    64,    65,    66,    67,    68,    69,
      70,    72,    73,    74,    75,    76,    79,    32,    54,    72,
      76,    72,    34,    65,    70,    76,    23,    34,    34,    34,
      62,    76,     6,    31,    62,    63,    76,    72,    57,    23,
      76,    33,    57,    57,    34,    34,    34,    37,    38,    39,
      40,    41,    42,    43,    44,    50,    77,    45,    46,    47,
      48,    49,    36,    57,    23,    31,    31,    72,    34,    34,
      31,    34,    34,    31,    35,    35,    31,    35,    31,    33,
      36,    73,    74,    74,    74,    74,    74,    72,    33,    58,
      58,    34,    72,    72,    32,    34,    63,    63,    63,    72,
      35,    71,    12,    70,    34,    34,    16,    18,    78,    31,
      76,    58,    31,    70,    70,    26,    22,    33,    34,    36,
      32,    31,    31,    22,    57,    72,    57,    32,    32,    57,
      71,    33,    57,    57,    78,    33,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    57,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      68,    69,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     6,
       7,     4,     2,     2,     1,     2,     1,     3,     1,     1,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     1,
       4,     6,     3,     2,     3,     1,     1,     1,     3,     3,
       1,     1,    10,    10,     9,     4,     2,     1,     1,     4,
       6,     4,     4,     5,     0,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     0,     6
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
#line 81 "q1.y"
                  {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "start"); head = (yyval.nd_obj).nd;}
#line 1603 "y.tab.c"
    break;

  case 3:
#line 83 "q1.y"
                               {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "statement");}
#line 1609 "y.tab.c"
    break;

  case 4:
#line 84 "q1.y"
           {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "statement");}
#line 1615 "y.tab.c"
    break;

  case 5:
#line 86 "q1.y"
          {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);}
#line 1621 "y.tab.c"
    break;

  case 6:
#line 87 "q1.y"
        {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);}
#line 1627 "y.tab.c"
    break;

  case 7:
#line 88 "q1.y"
       {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);}
#line 1633 "y.tab.c"
    break;

  case 8:
#line 89 "q1.y"
       {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);}
#line 1639 "y.tab.c"
    break;

  case 9:
#line 91 "q1.y"
                                                        { 
    char *fname = strdup((yyvsp[-4].nd_obj).name); 
    fname[strlen(fname) - 1] = '\0';
    printf("Should call add_id here for %s\n", fname);
    id_cnt = (yyvsp[-1].nd_obj).idc;
    add_id('F', fname, "", (yyvsp[-5].nd_obj).name, 0, 0);
    strcpy((yyval.nd_obj2).type, (yyvsp[-5].nd_obj).name);
    (yyval.nd_obj2).nd = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-1].nd_obj).nd, fname);
}
#line 1653 "y.tab.c"
    break;

  case 10:
#line 100 "q1.y"
                                                               {
    char *fname = strdup((yyvsp[-5].nd_obj).name); 
    fname[strlen(fname) - 1] = '\0';
    char *plist = (yyvsp[-4].nd_obj).name;
    id_cnt = (yyvsp[-4].nd_obj).idc;
    add_id('F', fname, plist, (yyvsp[-6].nd_obj).name, 0, 0);
    strcpy((yyval.nd_obj2).type, (yyvsp[-6].nd_obj).name);
    (yyval.nd_obj2).nd = mknode((yyvsp[-6].nd_obj).nd, mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, fname), fname);
}
#line 1667 "y.tab.c"
    break;

  case 11:
#line 110 "q1.y"
                                             {
    (yyval.nd_obj).idc = (yyvsp[-3].nd_obj).idc;
    printf("%s added to id_table\n", (yyvsp[0].nd_obj).name);
    add_id('V', (yyvsp[0].nd_obj).name, "0", (yyvsp[-1].nd_obj).name, 0, 0);
    char *pname = malloc(strlen((yyvsp[-3].nd_obj).name) + strlen((yyvsp[-1].nd_obj).name) + 1);
    strcpy(pname, (yyvsp[-3].nd_obj).name);
    strcat(pname, (yyvsp[-1].nd_obj).name);
    strcpy((yyval.nd_obj).name, pname);
    (yyval.nd_obj).nd = mknode(NULL, NULL, "plist");
}
#line 1682 "y.tab.c"
    break;

  case 12:
#line 119 "q1.y"
             {
    (yyval.nd_obj).idc = id_cnt;
    printf("%s added to id_table\n", (yyvsp[0].nd_obj).name);
    add_id('V', (yyvsp[0].nd_obj).name, "0", (yyvsp[-1].nd_obj).name, 0, 0);
    strcpy((yyval.nd_obj).name, (yyvsp[-1].nd_obj).name);
}
#line 1693 "y.tab.c"
    break;

  case 13:
#line 126 "q1.y"
                                         {(yyval.nd_obj).idc = (yyvsp[-1].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement list");}
#line 1699 "y.tab.c"
    break;

  case 14:
#line 127 "q1.y"
            {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement list");}
#line 1705 "y.tab.c"
    break;

  case 15:
#line 128 "q1.y"
                                 {(yyval.nd_obj).idc = (yyvsp[-1].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement list");}
#line 1711 "y.tab.c"
    break;

  case 16:
#line 129 "q1.y"
                  {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement list");}
#line 1717 "y.tab.c"
    break;

  case 17:
#line 132 "q1.y"
                                              {id_cnt = (yyvsp[-1].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement block");}
#line 1723 "y.tab.c"
    break;

  case 18:
#line 134 "q1.y"
                             {(yyval.nd_obj).idc = id_cnt; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1729 "y.tab.c"
    break;

  case 19:
#line 135 "q1.y"
                    {(yyval.nd_obj).idc = id_cnt; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1735 "y.tab.c"
    break;

  case 20:
#line 136 "q1.y"
                     {(yyval.nd_obj).idc = id_cnt; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement");}
#line 1741 "y.tab.c"
    break;

  case 21:
#line 137 "q1.y"
                  {(yyval.nd_obj).idc = id_cnt; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement");}
#line 1747 "y.tab.c"
    break;

  case 22:
#line 138 "q1.y"
               {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1753 "y.tab.c"
    break;

  case 23:
#line 139 "q1.y"
              {(yyval.nd_obj).idc = id_cnt; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1759 "y.tab.c"
    break;

  case 24:
#line 140 "q1.y"
                  {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1765 "y.tab.c"
    break;

  case 25:
#line 141 "q1.y"
                {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1771 "y.tab.c"
    break;

  case 26:
#line 142 "q1.y"
                       {(yyval.nd_obj).idc = id_cnt; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj2).nd, NULL, "statement");}
#line 1777 "y.tab.c"
    break;

  case 27:
#line 143 "q1.y"
                     {(yyval.nd_obj).idc = id_cnt; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement");}
#line 1783 "y.tab.c"
    break;

  case 28:
#line 144 "q1.y"
                        {(yyval.nd_obj).idc = (yyvsp[-1].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement");}
#line 1789 "y.tab.c"
    break;

  case 29:
#line 145 "q1.y"
            {(yyval.nd_obj).idc = id_cnt; (yyval.nd_obj).nd = mknode(NULL, NULL, ";");}
#line 1795 "y.tab.c"
    break;

  case 30:
#line 148 "q1.y"
                                                  {(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, NULL, "printf");}
#line 1801 "y.tab.c"
    break;

  case 31:
#line 149 "q1.y"
                                                     {(yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "printf");}
#line 1807 "y.tab.c"
    break;

  case 32:
#line 153 "q1.y"
                                          {(yyval.nd_obj).nd=mknode((yyvsp[-1].nd_obj2).nd,NULL,"return");}
#line 1813 "y.tab.c"
    break;

  case 33:
#line 154 "q1.y"
                   {(yyval.nd_obj).nd=mknode(NULL,NULL,"return");}
#line 1819 "y.tab.c"
    break;

  case 34:
#line 155 "q1.y"
                         {(yyval.nd_obj).nd=mknode((yyvsp[-1].nd_obj2).nd,NULL,"return");}
#line 1825 "y.tab.c"
    break;

  case 35:
#line 158 "q1.y"
           {(yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); strcpy((yyval.nd_obj2).type, "int");}
#line 1831 "y.tab.c"
    break;

  case 36:
#line 159 "q1.y"
           {(yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); strcpy((yyval.nd_obj2).type,"float");}
#line 1837 "y.tab.c"
    break;

  case 37:
#line 160 "q1.y"
            {(yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); strcpy((yyval.nd_obj2).type,"char");}
#line 1843 "y.tab.c"
    break;

  case 38:
#line 163 "q1.y"
                                         {
    strcpy((yyval.nd_obj).name, get_type((yyvsp[-2].nd_obj2).name));
    strcat((yyval.nd_obj).name, (yyvsp[0].nd_obj).name);
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "params");
}
#line 1853 "y.tab.c"
    break;

  case 39:
#line 168 "q1.y"
                            {
    strcpy((yyval.nd_obj).name, (yyvsp[-2].nd_obj2).type);
    strcat((yyval.nd_obj).name, (yyvsp[0].nd_obj).name);
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "params");
}
#line 1863 "y.tab.c"
    break;

  case 40:
#line 173 "q1.y"
        {
    strcpy((yyval.nd_obj).name, get_type((yyvsp[0].nd_obj2).name));
    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "params");
}
#line 1872 "y.tab.c"
    break;

  case 41:
#line 177 "q1.y"
        {
    strcpy((yyval.nd_obj).name, (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "params");
}
#line 1881 "y.tab.c"
    break;

  case 42:
#line 183 "q1.y"
                                                                                                            {
    (yyval.nd_obj).idc = (yyvsp[-1].nd_obj).idc - 1;
    (yyval.nd_obj).nd = mknode((yyvsp[-8].nd_obj).nd, mknode((yyvsp[-6].nd_obj2).nd, mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "for3"), "for2"), "for1");}
#line 1889 "y.tab.c"
    break;

  case 43:
#line 186 "q1.y"
                                                                                          {
    (yyval.nd_obj).idc = (yyvsp[-1].nd_obj).idc;
    (yyval.nd_obj).nd = mknode((yyvsp[-8].nd_obj).nd, mknode((yyvsp[-6].nd_obj2).nd, mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "for3"), "for2"), "for1");}
#line 1897 "y.tab.c"
    break;

  case 44:
#line 189 "q1.y"
                                                                                 {
    (yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc;
    (yyval.nd_obj).nd = mknode(NULL, mknode((yyvsp[-6].nd_obj2).nd, mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "for3"), "for2"), "for1");}
#line 1905 "y.tab.c"
    break;

  case 45:
#line 194 "q1.y"
                                           {
    printf("Declaration of %s\n", (yyvsp[-2].nd_obj).name);
    if (is_char((yyvsp[-3].nd_obj).name) != is_char((yyvsp[0].nd_obj2).type)) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", (yyvsp[0].nd_obj2).type, (yyvsp[-3].nd_obj).name);
        exit(1);
    }
    (yyval.nd_obj).idc = id_cnt;
    add_id('V', (yyvsp[-2].nd_obj).name, "0", (yyvsp[-3].nd_obj).name, 0, 0);
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "id=exp"), "decl");
}
#line 1920 "y.tab.c"
    break;

  case 46:
#line 204 "q1.y"
             {
    strcpy((yyvsp[0].nd_obj2).type, (yyvsp[-1].nd_obj).name);
    (yyval.nd_obj).idc = id_cnt;
    char *id_name = strdup((yyvsp[0].nd_obj2).nd->token);
    if (id_name[strlen(id_name) - 1] == ']') {
        int d1 = 1, d2 = 0;
        char *id_nodim = malloc(strlen(id_name) * sizeof(char));
        for (int i = 0; ;i++) {
            id_nodim[i] = id_name[i];
            if (id_name[i] == '[') {
                id_nodim[i] = '\0';
                for (int j = i + 1; j < strlen(id_name); ++j) {
                    if (id_name[j] == '[') {
                        d2 = 1;
                        break;
                    }
                }
                break;
            }
        }
        add_id('A', id_nodim, "0", (yyvsp[-1].nd_obj).name, d1, d2);
    } else
        add_id('V', (yyvsp[0].nd_obj2).name, "0", (yyvsp[-1].nd_obj).name, 0, 0);
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "decl");
}
#line 1950 "y.tab.c"
    break;

  case 47:
#line 231 "q1.y"
                       {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "if");}
#line 1956 "y.tab.c"
    break;

  case 48:
#line 232 "q1.y"
            {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "if");}
#line 1962 "y.tab.c"
    break;

  case 49:
#line 234 "q1.y"
                                              {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "matched_if");}
#line 1968 "y.tab.c"
    break;

  case 50:
#line 236 "q1.y"
                                                                      {(yyval.nd_obj).idc = (yyvsp[-2].nd_obj).idc; (yyval.nd_obj).nd = mknode(mknode((yyvsp[-4].nd_obj2).nd, (yyvsp[-2].nd_obj).nd, "if_then"), (yyvsp[0].nd_obj).nd, "unmatched_if");}
#line 1974 "y.tab.c"
    break;

  case 51:
#line 239 "q1.y"
                                                          {(yyval.nd_obj).idc = (yyvsp[0].nd_obj).idc; (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "while");}
#line 1980 "y.tab.c"
    break;

  case 52:
#line 242 "q1.y"
                                                     {
    char *id_type = get_type((yyvsp[-3].nd_obj2).name);
    if (is_char(id_type) != is_char((yyvsp[-1].nd_obj2).type)) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", (yyvsp[-1].nd_obj2).type, id_type);
        exit(1);
    }
    (yyval.nd_obj).nd = mknode(mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[-1].nd_obj2).nd, "id=exp"), (yyvsp[0].nd_obj).nd, "assn_st");}
#line 1992 "y.tab.c"
    break;

  case 53:
#line 250 "q1.y"
                                                              {
    char *id_type = get_type((yyvsp[-3].nd_obj2).name);
    if (is_char(id_type) != is_char((yyvsp[-1].nd_obj2).type)) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", (yyvsp[-1].nd_obj2).type, id_type);
        exit(1);
    }
    (yyval.nd_obj).nd = mknode(mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[-1].nd_obj2).nd, "id=exp"), (yyvsp[0].nd_obj).nd, "assn_st");
}
#line 2005 "y.tab.c"
    break;

  case 54:
#line 258 "q1.y"
      {(yyval.nd_obj).nd=NULL;}
#line 2011 "y.tab.c"
    break;

  case 55:
#line 261 "q1.y"
                                        {
    strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd=mknode((yyvsp[-2].nd_obj2).nd,(yyvsp[0].nd_obj2).nd,"other_exp1");
}
#line 2020 "y.tab.c"
    break;

  case 56:
#line 265 "q1.y"
        {
    strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
    // printf("Matched EXPRESSION: TREEM for %s\n", $1.name);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "other_exp1");
}
#line 2030 "y.tab.c"
    break;

  case 57:
#line 272 "q1.y"
                          {
    if (is_char((yyvsp[-2].nd_obj2).type) != 0 || is_char((yyvsp[0].nd_obj2).type) != 0) {
        printf("Incompatible types: trying to add char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "+");
}
#line 2043 "y.tab.c"
    break;

  case 58:
#line 280 "q1.y"
                     {
    if (is_char((yyvsp[-2].nd_obj2).type) != 0 || is_char((yyvsp[0].nd_obj2).type) != 0) {
        printf("Incompatible types: trying to subtract char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "-");
}
#line 2056 "y.tab.c"
    break;

  case 59:
#line 288 "q1.y"
                    {
    if (is_char((yyvsp[-2].nd_obj2).type) != 0 || is_char((yyvsp[0].nd_obj2).type) != 0) {
        printf("Incompatible types: trying to multiply char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "*"); 
}
#line 2069 "y.tab.c"
    break;

  case 60:
#line 296 "q1.y"
                   {
    if (is_char((yyvsp[-2].nd_obj2).type) != 0 || is_char((yyvsp[0].nd_obj2).type) != 0) {
        printf("Incompatible types: trying to divide char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "/"); 
}
#line 2082 "y.tab.c"
    break;

  case 61:
#line 304 "q1.y"
                   {
    if (is_char((yyvsp[-2].nd_obj2).type) != 0 || is_char((yyvsp[0].nd_obj2).type) != 0) {
        printf("Incompatible types: trying to divide char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "%"); 
}
#line 2095 "y.tab.c"
    break;

  case 62:
#line 312 "q1.y"
         {
    strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "other_exp2");
}
#line 2104 "y.tab.c"
    break;

  case 63:
#line 318 "q1.y"
              {
    if (!find_id((yyvsp[0].nd_obj2).name)) {
        printf("Error: Undeclared Variable %s\n", (yyvsp[0].nd_obj2).name);
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, get_type((yyvsp[0].nd_obj2).name));
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd,NULL,"base_exp");
}
#line 2117 "y.tab.c"
    break;

  case 64:
#line 326 "q1.y"
       {
    strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "base_exp");
}
#line 2126 "y.tab.c"
    break;

  case 65:
#line 330 "q1.y"
                           {
    strcpy((yyval.nd_obj2).type,(yyvsp[-1].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[-1].nd_obj2).nd, NULL, "base_exp");   
}
#line 2135 "y.tab.c"
    break;

  case 66:
#line 334 "q1.y"
                     {
    strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "base_exp");   
}
#line 2144 "y.tab.c"
    break;

  case 67:
#line 340 "q1.y"
                                {
    char *fname = strdup((yyvsp[-1].nd_obj).name); 
    fname[strlen(fname) - 1] = '\0';
    if (!find_id(fname)) {
        printf("Error: Undeclared Function Call %s\n", fname);
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, get_type(fname));
    char *fcname = malloc(strlen(fname) + 6);
    strcpy(fcname, fname);
    strcat(fcname, "_call");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, fcname);
}
#line 2162 "y.tab.c"
    break;

  case 68:
#line 353 "q1.y"
                            {
    char *fname = strdup((yyvsp[-2].nd_obj).name); 
    fname[strlen(fname) - 1] = '\0';
    if (!find_id(fname)) {
        printf("Error: Undeclared Function Call %s\n", fname);
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, get_type(fname));
    char *fcname = malloc(strlen(fname) + 6);
    strcpy(fcname, fname);
    strcat(fcname, "_call");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, fcname);
}
#line 2180 "y.tab.c"
    break;

  case 69:
#line 368 "q1.y"
          { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[0].nd_obj).name);}
#line 2186 "y.tab.c"
    break;

  case 70:
#line 369 "q1.y"
      {
    char *id_nodim = malloc(strlen((yyvsp[0].nd_obj).name) * sizeof(char));
    for (int i = 0; ;i++) {
        id_nodim[i] = (yyvsp[0].nd_obj).name[i];
        if ((yyvsp[0].nd_obj).name[i] == '[') {
            id_nodim[i] = '\0';
            break;
        }
    }
    strcpy((yyval.nd_obj2).name, id_nodim);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[0].nd_obj).name);
}
#line 2203 "y.tab.c"
    break;

  case 71:
#line 381 "q1.y"
      {
    char *id_nodim = malloc(strlen((yyvsp[0].nd_obj).name) * sizeof(char));
    for (int i = 0; ;i++) {
        id_nodim[i] = (yyvsp[0].nd_obj).name[i];
        if ((yyvsp[0].nd_obj).name[i] == '[') {
            id_nodim[i] = '\0';
            break;
        }
    }
    strcpy((yyval.nd_obj2).name, id_nodim);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[0].nd_obj).name);
}
#line 2220 "y.tab.c"
    break;

  case 81:
#line 398 "q1.y"
                                           {(yyval.nd_obj).nd = mknode(mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "case"), (yyvsp[0].nd_obj).nd, "cases");}
#line 2226 "y.tab.c"
    break;

  case 82:
#line 399 "q1.y"
                               {(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "def_case");}
#line 2232 "y.tab.c"
    break;

  case 83:
#line 400 "q1.y"
  {(yyval.nd_obj).nd = NULL;}
#line 2238 "y.tab.c"
    break;

  case 84:
#line 403 "q1.y"
                                                  {(yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "switch");}
#line 2244 "y.tab.c"
    break;


#line 2248 "y.tab.c"

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
#line 406 "q1.y"

void main()
{

    printf("\nOUTPUT:\n ");
    freopen("input.txt", "r", stdin);
    yyparse();
    printf("Valid Input\n");
    /* printf("Symbol table \n %s %s %s",symbol_table[0][0],symbol_table[0][1],symbol_table[0][2])  ; */
}
void yyerror()
{
    printf("Syntax Error:\n");
    exit(0);
}

int is_char(char *tk)
{
    return strcmp(tk, "char") == 0;
}
int find_id(char *iden_name)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

char *get_type(char *iden_name)
{
    if (!find_id(iden_name)) {
        assert(0 && "Finding type of identifier not in table\n");
    }
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            return id_table[i].data_type;
        }
    }
    return NULL;
}
void add_id(char c, char *iden_name, char *value, char *d_type, int d1, int d2)
{
    /* printf("add_id has been called!!!!!!!!!!!!!!"); */
    if (!find_id(iden_name))
    {
        id_table[id_cnt].id_name = strdup(iden_name);
        id_table[id_cnt].data_type = strdup(d_type);
        if (c == 'F')
        {
            id_table[id_cnt].type = strdup("Function");
            id_table[id_cnt].plist = strdup(value);
        }
        else if (c == 'V')
        {
            id_table[id_cnt].type = strdup("Variable");
            if (strcmp(d_type, "int") == 0)
                id_table[id_cnt].val.i = atoi(value);
            else if (strcmp(d_type, "float") == 0)
                id_table[id_cnt].val.f = atof(value);
            else if (strcmp(d_type, "char") == 0)
                id_table[id_cnt].val.c = value[0];
            else
                assert(0 && "Invalid d_type for add_id, variable\n");
        }
        else if (c == 'A')
        {
            if (!d1)
            {
                printf("Error: Array size cannot be 0");
                exit(1);
            }
            id_table[id_cnt].arr_len = d1;
            id_table[id_cnt].arr_len2 = d2;
            if (!d2)
            {
                id_table[id_cnt].type = strdup("Array1D");
                if (strcmp(d_type, "int") == 0)
                    id_table[id_cnt].arr.i = malloc(d1 * sizeof(int));
                else if (strcmp(d_type, "float") == 0)
                    id_table[id_cnt].arr.f = malloc(d1 * sizeof(float));
                else if (strcmp(d_type, "char") == 0)
                    id_table[id_cnt].arr.c = malloc(d1 * sizeof(char));
                else
                    assert(0 && "Invalid d_type for add_id, 1d array\n");
            }
            else
            {
                id_table[id_cnt].type = strdup("Array2D");
                if (strcmp(d_type, "int") == 0)
                    id_table[id_cnt].arr.i = malloc(d1 * d2 * sizeof(int));
                else if (strcmp(d_type, "float") == 0)
                    id_table[id_cnt].arr.f = malloc(d1 * d2 * sizeof(float));
                else if (strcmp(d_type, "char") == 0)
                    id_table[id_cnt].arr.c = malloc(d1 * d2 * sizeof(char));
                else
                    assert(0 && "Invalid d_type for add_id, 2d array\n");
            }
        }
        else
        {
            assert(0 && "Invalid c for add_id\n");
        }
        /* printf("Declared variable: %s with data type: %s and value: ", id_table[id_cnt].id_name, id_table[id_cnt].data_type); */
        /* if (strcmp(d_type, "int") == 0)
            printf("%d\n", id_table[id_cnt].val.i);
        else if (strcmp(d_type, "float") == 0)
            printf("%f\n", id_table[id_cnt].val.f);
        else if (strcmp(d_type, "char") == 0)
            printf("%c\n", id_table[id_cnt].val.c); */
        id_cnt++;
    }
    else
    {
        printf("Error: Redeclaration of existing identifier %s\n", iden_name);
        exit(1);
    }
}

int lookup_i(char *iden_name, int idx1, int idx2)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val.i;
            else if (idx2 == -1)
                return id_table[i].arr.i[idx1];
            else
                return id_table[i].arr.i[idx1 * id_table[i].arr_len2 + idx2];
        }
    }
    printf("Error: Acessing undeclared identifier %s\n", iden_name);
    exit(1);
}

float lookup_f(char *iden_name, int idx1, int idx2)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val.f;
            else if (idx2 == -1)
                return id_table[i].arr.f[idx1];
            else
                return id_table[i].arr.f[idx1 * id_table[i].arr_len2 + idx2];
        }
    }
    printf("Error: Acessing undeclared identifier %s\n", iden_name);
    exit(1);
}

char lookup_c(char *iden_name, int idx1, int idx2)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val.c;
            else if (idx2 == -1)
                return id_table[i].arr.c[idx1];
            else
                return id_table[i].arr.c[idx1 * id_table[i].arr_len2 + idx2];
        }
    }
    printf("Error: Accessing undeclared identifier %s\n", iden_name);
    exit(1);
}
void update_id(char *iden_name, char *value, int idx1, int idx2)
{
    if (find_id(iden_name))
    {
        for (int i = id_cnt - 1; i >= 0; i--)
        {
            if (strcmp(id_table[i].id_name, iden_name) == 0)
            {
                if (idx1 == -1 && idx2 == -1)
                {
                    if (strcmp(id_table[i].data_type, "int") == 0)
                        id_table[i].val.i = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].val.f = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].val.c = value[0];
                    else
                        assert(0 && "Invalid d_type for update_id, variable\n");
                }
                else if (idx2 == -1)
                {
                    if (strcmp(id_table[i].data_type, "int") == 0)
                        id_table[i].arr.i[idx1] = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].arr.f[idx1] = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].arr.c[idx1] = value[0];
                    else
                        assert(0 && "Invalid d_type for update_id, array1d\n");
                }
                else
                {
                    if (strcmp(id_table[i].data_type, "int") == 0)
                        id_table[i].arr.i[idx1 * id_table[i].arr_len2 + idx2] = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].arr.f[idx1 * id_table[i].arr_len2 + idx2] = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].arr.c[idx1 * id_table[i].arr_len2 + idx2] = value[0];
                    else
                        assert(0 && "Invalid d_type for update_id, array2d\n");
                }
            }
        }
    }
    else
    {
        printf("Error: Assigning undeclared identifier %s\n", iden_name);
        exit(1);
    }
}

struct node* mknode(struct node *left, struct node *right, char *token) {
  struct node *newnode = (struct node*) malloc(sizeof(struct node));
  char *newstr = (char*) malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  return(newnode);
}
