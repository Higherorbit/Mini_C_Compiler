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
    char * id_name;
    char * data_type;
    char * type;
    int val_i;
    float val_f;
    char val_c;
    int *arr_i;
    float *arr_f;
    char *arr_c;
    int arr_len;
    int arr_len2;
    char* plist;
} id_table[50];
int id_cnt = 0;


struct node { 
    struct node *left; 
    struct node *right; 
    char *token; 
};

struct node *head;
int find_id(char *iden_name);
char *get_type(char *iden_name);
void add_id(char c, char *iden_name, char *value, char *d_type, int d1, int d2);
int lookup_i(char *iden_name, int idx1, int idx2);
float lookup_f(char *iden_name, int idx1, int idx2);
char lookup_c(char *iden_name, int idx1, int idx2);
void update_id(char *iden_name, char *value, int idx1, int idx2);
struct node* mknode(struct node *left, struct node *right, char *token);


#line 113 "y.tab.c"

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
    SLCOMMENT = 258,
    MLCOMMENT = 259,
    CHARFORMAT = 260,
    INTFORMAT = 261,
    FLOATFORMAT = 262,
    STRING = 263,
    INT = 264,
    FLOAT = 265,
    CHAR = 266,
    VOID = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    FOR = 271,
    SWITCH = 272,
    CASE = 273,
    BREAK = 274,
    DEFAULT = 275,
    CONTINUE = 276,
    RETURN = 277,
    PRINTF = 278,
    ID = 279,
    ID1 = 280,
    ID2 = 281,
    NUM = 282,
    FLOATNUM = 283,
    CHARCONST = 284,
    FUNC = 285,
    LPAREN = 286,
    RPAREN = 287,
    LBRACE = 288,
    RBRACE = 289,
    SEMICOLON = 290,
    COMMA = 291,
    ASSIGNMENT = 292,
    LAND = 293,
    LOR = 294,
    NOTEQ = 295,
    EQUALS = 296,
    GTE = 297,
    LTE = 298,
    LT = 299,
    GT = 300,
    PLUS = 301,
    MINUS = 302,
    MULT = 303,
    DIV = 304,
    MOD = 305,
    LNOT = 306
  };
#endif
/* Tokens.  */
#define SLCOMMENT 258
#define MLCOMMENT 259
#define CHARFORMAT 260
#define INTFORMAT 261
#define FLOATFORMAT 262
#define STRING 263
#define INT 264
#define FLOAT 265
#define CHAR 266
#define VOID 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define SWITCH 272
#define CASE 273
#define BREAK 274
#define DEFAULT 275
#define CONTINUE 276
#define RETURN 277
#define PRINTF 278
#define ID 279
#define ID1 280
#define ID2 281
#define NUM 282
#define FLOATNUM 283
#define CHARCONST 284
#define FUNC 285
#define LPAREN 286
#define RPAREN 287
#define LBRACE 288
#define RBRACE 289
#define SEMICOLON 290
#define COMMA 291
#define ASSIGNMENT 292
#define LAND 293
#define LOR 294
#define NOTEQ 295
#define EQUALS 296
#define GTE 297
#define LTE 298
#define LT 299
#define GT 300
#define PLUS 301
#define MINUS 302
#define MULT 303
#define DIV 304
#define MOD 305
#define LNOT 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "q1.y"
 
    struct vname { 
        char name[100]; 
        struct node* nd;
    } nd_obj;
    struct vname2 { 
        char name[100]; 
        struct node* nd;
        char type[6];
    } nd_obj2;

#line 279 "y.tab.c"

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
#define YYLAST   297

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    78,    79,    81,    82,    83,    84,    86,
      94,   103,   109,   113,   114,   115,   116,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   132,   133,
     137,   138,   139,   142,   143,   144,   147,   152,   157,   161,
     167,   168,   169,   172,   180,   206,   207,   209,   211,   214,
     217,   225,   233,   236,   240,   247,   255,   263,   271,   279,
     287,   293,   301,   305,   309,   315,   328,   343,   344,   356,
     370,   370,   370,   370,   370,   370,   370,   370,   370
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SLCOMMENT", "MLCOMMENT", "CHARFORMAT",
  "INTFORMAT", "FLOATFORMAT", "STRING", "INT", "FLOAT", "CHAR", "VOID",
  "IF", "ELSE", "WHILE", "FOR", "SWITCH", "CASE", "BREAK", "DEFAULT",
  "CONTINUE", "RETURN", "PRINTF", "ID", "ID1", "ID2", "NUM", "FLOATNUM",
  "CHARCONST", "FUNC", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "ASSIGNMENT", "LAND", "LOR", "NOTEQ", "EQUALS", "GTE", "LTE",
  "LT", "GT", "PLUS", "MINUS", "MULT", "DIV", "MOD", "LNOT", "$accept",
  "start", "statement", "TYPE", "FUNCTION", "PARAMETER_LIST",
  "STATEMENT_LIST", "STATEMENT", "PRINT_STATEMENTS", "RETURN_STATEMENTS",
  "CONST", "ULTIMATE_LIST", "FOR_STATEMENT", "DECLARATION", "IF_STATEMENT",
  "MATCHED", "UNMATCHED", "WHILE_STATEMENT", "ASGNSTMT", "ASGNSTMT_LIST",
  "EXPRESSION", "TREEM", "TREEM2", "FUNCTION_CALLSTMTS", "ALLID",
  "Comperator", YY_NULLPTR
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
     305,   306
};
# endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,   -95,   -95,   -95,   -95,     8,   -95,    -5,    60,   -95,
      -8,   -95,   -22,     9,   -16,    25,   -95,    12,    60,    11,
      26,    28,    32,    40,    98,    30,   -95,   -95,   -95,   -95,
     -95,   -95,   251,   260,    25,   -95,     3,    46,    25,   -95,
     -95,   -95,   -95,    48,   -95,   -95,   -95,   -95,    51,   153,
      90,   -95,   -95,    44,    25,    70,   260,   260,    53,   -95,
     -95,   -95,    55,    61,    91,   -95,    64,    71,    68,   111,
     -95,    78,    76,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   260,   260,
     260,   260,   260,   260,   260,    80,   -95,   125,   139,   260,
      82,    96,    44,   -95,   -95,   -14,   268,   -95,   268,   -95,
      25,   260,    90,   -95,   -95,   -95,   -95,   -95,   209,   -95,
     109,   113,   167,   260,   260,   123,   268,   -95,   -95,   -95,
     223,    84,   -95,    25,    25,    84,   181,   195,   -95,    83,
     107,   126,   127,   140,    84,    84,   124,   260,   159,   -95,
     141,   143,   154,   -95,   209,   152,    25,   156,   168,   -95,
      25,   165,    25,    25,   169,   -95,   179,   180,   -95,   -95,
     -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     6,     7,     8,     0,     2,     0,     4,     1,
       0,     3,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,    33,
      34,    35,     0,     0,     0,    27,     0,     0,    14,    17,
      18,    62,    23,     0,    21,    45,    46,    22,     0,     0,
      54,    60,    64,    61,     0,     0,     0,     0,     0,    20,
      19,    31,     0,     0,     0,    65,    39,     0,    38,     0,
      61,     0,    67,    44,     9,    13,    26,    25,    24,    75,
      76,    70,    77,    74,    73,    71,    72,    78,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,    32,    30,     0,     0,    66,     0,    63,
      16,     0,    53,    55,    56,    57,    58,    59,    52,    10,
       0,     0,     0,     0,     0,     0,     0,    37,    36,    15,
      43,     0,    50,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    49,
       0,     0,     0,    29,    52,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,    42,     0,     0,    48,    40,
      41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   192,    66,   -95,   -95,   -28,   -95,   -95,   -95,
     -19,   -94,   -95,   129,   -95,   -95,   -95,   -95,   -43,    63,
     -26,   155,   166,   -95,   -15,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    36,     8,    14,    37,    38,    39,    40,
      41,    67,    42,    43,    44,    45,    46,    47,    48,   132,
      49,    50,    51,    52,    70,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,     1,     2,     3,     4,    62,    71,    69,     9,    63,
      75,    15,   127,    66,   128,   101,    17,    68,   125,    53,
      18,    73,   126,    53,    12,    10,    95,    72,    27,    28,
      97,    98,   139,    16,     1,     2,     3,     4,    19,    53,
      20,    21,    56,   102,    22,    54,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    57,    34,    58,
      35,    64,     1,     2,     3,     4,     7,    59,   118,     1,
       2,     3,     4,   122,     7,    60,    13,    26,    27,    28,
      74,    94,   129,    76,    55,   130,    77,    66,    99,    66,
     103,    68,   143,    68,    96,    53,   104,   136,   137,   105,
     106,   151,   152,   107,   108,   141,   142,    66,    26,    27,
      28,    68,   110,   111,   119,   146,   140,   123,    53,    53,
     102,   154,    26,    27,    28,    29,    30,    31,   161,   102,
     102,   124,   164,    61,   166,   167,    89,    90,    91,    92,
      93,    53,   133,   109,   147,    53,   134,    53,    53,    79,
      80,    81,    82,    83,    84,    85,    86,   120,   138,   153,
     148,   149,    87,    79,    80,    81,    82,    83,    84,    85,
      86,   121,   150,   155,   156,   157,    87,    79,    80,    81,
      82,    83,    84,    85,    86,   160,   158,   100,    78,   162,
      87,    79,    80,    81,    82,    83,    84,    85,    86,   165,
      11,   163,   135,   168,    87,    79,    80,    81,    82,    83,
      84,    85,    86,   169,   170,     0,   144,   159,    87,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
     145,     0,    87,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,   112,     0,   131,    87,    79,    80,    81,
      82,    83,    84,    85,    86,   113,   114,   115,   116,   117,
      87,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,    87,    26,    27,    28,    29,    30,
      31,     0,     0,    65,    26,    27,    28,    29,    30,    31,
      32,    33,    26,    27,    28,    29,    30,    31
};

static const yytype_int16 yycheck[] =
{
      15,     9,    10,    11,    12,    24,    34,    33,     0,    24,
      38,    33,   106,    32,   108,    58,    32,    32,    32,    34,
      36,    36,    36,    38,    32,    30,    54,    24,    25,    26,
      56,    57,   126,    24,     9,    10,    11,    12,    13,    54,
      15,    16,    31,    58,    19,    33,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    31,    33,    31,
      35,    31,     9,    10,    11,    12,     0,    35,    94,     9,
      10,    11,    12,    99,     8,    35,    10,    24,    25,    26,
      34,    37,   110,    35,    18,   111,    35,   106,    35,   108,
      35,   106,   135,   108,    24,   110,    35,   123,   124,     8,
      36,   144,   145,    32,    36,   133,   134,   126,    24,    25,
      26,   126,    34,    37,    34,    32,   131,    35,   133,   134,
     135,   147,    24,    25,    26,    27,    28,    29,   156,   144,
     145,    35,   160,    35,   162,   163,    46,    47,    48,    49,
      50,   156,    33,    32,    37,   160,    33,   162,   163,    38,
      39,    40,    41,    42,    43,    44,    45,    32,    35,    35,
      34,    34,    51,    38,    39,    40,    41,    42,    43,    44,
      45,    32,    32,    14,    33,    32,    51,    38,    39,    40,
      41,    42,    43,    44,    45,    33,    32,    58,    35,    33,
      51,    38,    39,    40,    41,    42,    43,    44,    45,    34,
       8,    33,    35,    34,    51,    38,    39,    40,    41,    42,
      43,    44,    45,    34,    34,    -1,    35,   154,    51,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      35,    -1,    51,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    88,    -1,    36,    51,    38,    39,    40,
      41,    42,    43,    44,    45,    89,    90,    91,    92,    93,
      51,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    51,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    24,    25,    26,    27,    28,    29,
      30,    31,    24,    25,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    53,    54,    55,    56,     0,
      30,    54,    32,    55,    57,    33,    24,    32,    36,    13,
      15,    16,    19,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    33,    35,    55,    58,    59,    60,
      61,    62,    64,    65,    66,    67,    68,    69,    70,    72,
      73,    74,    75,    76,    33,    55,    31,    31,    31,    35,
      35,    35,    62,    76,    31,    32,    62,    63,    76,    72,
      76,    58,    24,    76,    34,    58,    35,    35,    35,    38,
      39,    40,    41,    42,    43,    44,    45,    51,    77,    46,
      47,    48,    49,    50,    37,    58,    24,    72,    72,    35,
      65,    70,    76,    35,    35,     8,    36,    32,    36,    32,
      34,    37,    73,    74,    74,    74,    74,    74,    72,    34,
      32,    32,    72,    35,    35,    32,    36,    63,    63,    58,
      72,    36,    71,    33,    33,    35,    72,    72,    35,    63,
      76,    58,    58,    70,    35,    35,    32,    37,    34,    34,
      32,    70,    70,    35,    72,    14,    33,    32,    32,    71,
      33,    58,    33,    33,    58,    34,    58,    58,    34,    34,
      34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    67,    68,    69,
      70,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     6,
       7,     4,     2,     2,     1,     4,     3,     1,     1,     2,
       2,     1,     1,     1,     2,     2,     2,     1,     5,     7,
       3,     2,     3,     1,     1,     1,     3,     3,     1,     1,
      11,    11,    10,     4,     2,     1,     1,     7,    11,     7,
       4,     5,     0,     3,     1,     3,     3,     3,     3,     3,
       1,     1,     1,     3,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 76 "q1.y"
                  {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "start"); head = (yyval.nd_obj).nd;}
#line 1596 "y.tab.c"
    break;

  case 3:
#line 78 "q1.y"
                               {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "statement");}
#line 1602 "y.tab.c"
    break;

  case 4:
#line 79 "q1.y"
           {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "statement");}
#line 1608 "y.tab.c"
    break;

  case 5:
#line 81 "q1.y"
          {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);}
#line 1614 "y.tab.c"
    break;

  case 6:
#line 82 "q1.y"
        {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);}
#line 1620 "y.tab.c"
    break;

  case 7:
#line 83 "q1.y"
       {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);}
#line 1626 "y.tab.c"
    break;

  case 8:
#line 84 "q1.y"
       {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);}
#line 1632 "y.tab.c"
    break;

  case 9:
#line 86 "q1.y"
                                                        { 
    char *fname = strdup((yyvsp[-4].nd_obj).name); 
    fname[strlen(fname) - 1] = '\0';
    // printf("Should call add_id here for %s\n", fname);
    add_id('F', fname, "", (yyvsp[-5].nd_obj).name, 0, 0);
    strcpy((yyval.nd_obj2).type, (yyvsp[-5].nd_obj).name);
    (yyval.nd_obj2).nd = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-1].nd_obj).nd, fname);
}
#line 1645 "y.tab.c"
    break;

  case 10:
#line 94 "q1.y"
                                                                   { 
    char *fname = strdup((yyvsp[-5].nd_obj).name); 
    fname[strlen(fname) - 1] = '\0';
    char *plist = (yyvsp[-4].nd_obj).name;
    add_id('F', fname, plist, (yyvsp[-6].nd_obj).name, 0, 0);
    strcpy((yyval.nd_obj2).type, (yyvsp[-6].nd_obj).name);
    (yyval.nd_obj2).nd = mknode((yyvsp[-6].nd_obj).nd, mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, fname), fname);
}
#line 1658 "y.tab.c"
    break;

  case 11:
#line 103 "q1.y"
                                             {
    char *pname = malloc(strlen((yyvsp[-3].nd_obj).name) + strlen((yyvsp[-1].nd_obj).name) + 1);
    strcpy(pname, (yyvsp[-3].nd_obj).name);
    strcat(pname, (yyvsp[-1].nd_obj).name);
    strcpy((yyval.nd_obj).name, pname);
    (yyval.nd_obj).nd = mknode(NULL, NULL, "plist");
}
#line 1670 "y.tab.c"
    break;

  case 12:
#line 109 "q1.y"
             {
    strcpy((yyval.nd_obj).name, (yyvsp[-1].nd_obj).name);
}
#line 1678 "y.tab.c"
    break;

  case 13:
#line 113 "q1.y"
                                         {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement list");}
#line 1684 "y.tab.c"
    break;

  case 14:
#line 114 "q1.y"
                {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement list");}
#line 1690 "y.tab.c"
    break;

  case 15:
#line 115 "q1.y"
                                                  {(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement list");}
#line 1696 "y.tab.c"
    break;

  case 16:
#line 116 "q1.y"
                                   {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement list");}
#line 1702 "y.tab.c"
    break;

  case 17:
#line 119 "q1.y"
                             {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1708 "y.tab.c"
    break;

  case 18:
#line 120 "q1.y"
                    {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1714 "y.tab.c"
    break;

  case 19:
#line 121 "q1.y"
                     {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement");}
#line 1720 "y.tab.c"
    break;

  case 20:
#line 122 "q1.y"
                  {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement");}
#line 1726 "y.tab.c"
    break;

  case 21:
#line 123 "q1.y"
               {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1732 "y.tab.c"
    break;

  case 22:
#line 124 "q1.y"
                  {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1738 "y.tab.c"
    break;

  case 23:
#line 125 "q1.y"
                {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 1744 "y.tab.c"
    break;

  case 24:
#line 126 "q1.y"
                       {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj2).nd, NULL, "statement");}
#line 1750 "y.tab.c"
    break;

  case 25:
#line 127 "q1.y"
                     {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement");}
#line 1756 "y.tab.c"
    break;

  case 26:
#line 128 "q1.y"
                        {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "statement");}
#line 1762 "y.tab.c"
    break;

  case 27:
#line 129 "q1.y"
            {(yyval.nd_obj).nd = mknode(NULL, NULL, ";");}
#line 1768 "y.tab.c"
    break;

  case 28:
#line 132 "q1.y"
                                                         {(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, NULL, "printf");}
#line 1774 "y.tab.c"
    break;

  case 29:
#line 133 "q1.y"
                                                            {(yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "printf");}
#line 1780 "y.tab.c"
    break;

  case 30:
#line 137 "q1.y"
                                          {(yyval.nd_obj).nd=mknode((yyvsp[-1].nd_obj2).nd,NULL,"return");}
#line 1786 "y.tab.c"
    break;

  case 31:
#line 138 "q1.y"
                   {(yyval.nd_obj).nd=mknode(NULL,NULL,"return");}
#line 1792 "y.tab.c"
    break;

  case 32:
#line 139 "q1.y"
                         {(yyval.nd_obj).nd=mknode((yyvsp[-1].nd_obj2).nd,NULL,"return");}
#line 1798 "y.tab.c"
    break;

  case 33:
#line 142 "q1.y"
           {(yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); strcpy((yyval.nd_obj2).type, "int");}
#line 1804 "y.tab.c"
    break;

  case 34:
#line 143 "q1.y"
           {(yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); strcpy((yyval.nd_obj2).type,"float");}
#line 1810 "y.tab.c"
    break;

  case 35:
#line 144 "q1.y"
            {(yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); strcpy((yyval.nd_obj2).type,"char");}
#line 1816 "y.tab.c"
    break;

  case 36:
#line 147 "q1.y"
                                         {
    strcpy((yyval.nd_obj).name, get_type((yyvsp[-2].nd_obj2).name));
    strcat((yyval.nd_obj).name, (yyvsp[0].nd_obj).name);
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "params");
}
#line 1826 "y.tab.c"
    break;

  case 37:
#line 152 "q1.y"
                            {
    strcpy((yyval.nd_obj).name, (yyvsp[-2].nd_obj2).type);
    strcat((yyval.nd_obj).name, (yyvsp[0].nd_obj).name);
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "params");
}
#line 1836 "y.tab.c"
    break;

  case 38:
#line 157 "q1.y"
        {
    strcpy((yyval.nd_obj).name, get_type((yyvsp[0].nd_obj2).name));
    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "params");
}
#line 1845 "y.tab.c"
    break;

  case 39:
#line 161 "q1.y"
        {
    strcpy((yyval.nd_obj).name, (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "params");
}
#line 1854 "y.tab.c"
    break;

  case 40:
#line 167 "q1.y"
                                                                                                                   {(yyval.nd_obj).nd = mknode((yyvsp[-8].nd_obj).nd, mknode((yyvsp[-6].nd_obj2).nd, mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "for3"), "for2"), "for1");}
#line 1860 "y.tab.c"
    break;

  case 41:
#line 168 "q1.y"
                                                                                                 {(yyval.nd_obj).nd = mknode((yyvsp[-8].nd_obj).nd, mknode((yyvsp[-6].nd_obj2).nd, mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "for3"), "for2"), "for1");}
#line 1866 "y.tab.c"
    break;

  case 42:
#line 169 "q1.y"
                                                                                        {(yyval.nd_obj).nd = mknode(NULL, mknode((yyvsp[-6].nd_obj2).nd, mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "for3"), "for2"), "for1");}
#line 1872 "y.tab.c"
    break;

  case 43:
#line 172 "q1.y"
                                           {
    if (strcmp((yyvsp[-3].nd_obj).name, "char") != strcmp((yyvsp[0].nd_obj2).type, "char")) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", (yyvsp[0].nd_obj2).type, (yyvsp[-3].nd_obj).name);
        exit(1);
    }
    add_id('V', (yyvsp[-2].nd_obj).name, "0", (yyvsp[-3].nd_obj).name, 0, 0);
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "id=exp"), "decl");
}
#line 1885 "y.tab.c"
    break;

  case 44:
#line 180 "q1.y"
             {
    strcpy((yyvsp[0].nd_obj2).type, (yyvsp[-1].nd_obj).name);
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
#line 1914 "y.tab.c"
    break;

  case 45:
#line 206 "q1.y"
                       {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "if");}
#line 1920 "y.tab.c"
    break;

  case 46:
#line 207 "q1.y"
            {(yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "if");}
#line 1926 "y.tab.c"
    break;

  case 47:
#line 209 "q1.y"
                                                                  {(yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj2).nd, (yyvsp[-1].nd_obj).nd, "matched_if");}
#line 1932 "y.tab.c"
    break;

  case 48:
#line 211 "q1.y"
                                                                                                       {(yyval.nd_obj).nd = mknode(mknode((yyvsp[-8].nd_obj2).nd, (yyvsp[-5].nd_obj).nd, "if_then"), (yyvsp[-1].nd_obj).nd, "unmatched_if");}
#line 1938 "y.tab.c"
    break;

  case 49:
#line 214 "q1.y"
                                                                              {(yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj2).nd, (yyvsp[-1].nd_obj).nd, "while");}
#line 1944 "y.tab.c"
    break;

  case 50:
#line 217 "q1.y"
                                                     {
    char *id_type = get_type((yyvsp[-3].nd_obj2).name);
    if (strcmp(id_type, "char") != strcmp((yyvsp[-1].nd_obj2).type, "char")) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", (yyvsp[-1].nd_obj2).type, id_type);
        exit(1);
    }
    (yyval.nd_obj).nd = mknode(mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[-1].nd_obj2).nd, "id=exp"), (yyvsp[0].nd_obj).nd, "assn_st");}
#line 1956 "y.tab.c"
    break;

  case 51:
#line 225 "q1.y"
                                                              {
    char *id_type = get_type((yyvsp[-3].nd_obj2).name);
    if (strcmp(id_type, "char") != strcmp((yyvsp[-1].nd_obj2).type, "char")) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", (yyvsp[-1].nd_obj2).type, id_type);
        exit(1);
    }
    (yyval.nd_obj).nd = mknode(mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[-1].nd_obj2).nd, "id=exp"), (yyvsp[0].nd_obj).nd, "assn_st");
}
#line 1969 "y.tab.c"
    break;

  case 52:
#line 233 "q1.y"
      {(yyval.nd_obj).nd=NULL;}
#line 1975 "y.tab.c"
    break;

  case 53:
#line 236 "q1.y"
                                        {
    strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd=mknode((yyvsp[-2].nd_obj2).nd,(yyvsp[0].nd_obj2).nd,"other_exp1");
}
#line 1984 "y.tab.c"
    break;

  case 54:
#line 240 "q1.y"
        {
    strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
    // printf("Matched EXPRESSION: TREEM for %s\n", $1.name);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "other_exp1");
}
#line 1994 "y.tab.c"
    break;

  case 55:
#line 247 "q1.y"
                          {
    if (strcmp((yyvsp[-2].nd_obj2).type, "char") != 0 || strcmp((yyvsp[0].nd_obj2).type, "char") != 0) {
        printf("Incompatible types: trying to add char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "+");
}
#line 2007 "y.tab.c"
    break;

  case 56:
#line 255 "q1.y"
                     {
    if (strcmp((yyvsp[-2].nd_obj2).type, "char") != 0 || strcmp((yyvsp[0].nd_obj2).type, "char") != 0) {
        printf("Incompatible types: trying to subtract char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "-");
}
#line 2020 "y.tab.c"
    break;

  case 57:
#line 263 "q1.y"
                    {
    if (strcmp((yyvsp[-2].nd_obj2).type, "char") != 0 || strcmp((yyvsp[0].nd_obj2).type, "char") != 0) {
        printf("Incompatible types: trying to multiply char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "*"); 
}
#line 2033 "y.tab.c"
    break;

  case 58:
#line 271 "q1.y"
                   {
    if (strcmp((yyvsp[-2].nd_obj2).type, "char") != 0 || strcmp((yyvsp[0].nd_obj2).type, "char") != 0) {
        printf("Incompatible types: trying to divide char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "/"); 
}
#line 2046 "y.tab.c"
    break;

  case 59:
#line 279 "q1.y"
                   {
    if (strcmp((yyvsp[-2].nd_obj2).type, "char") != 0 || strcmp((yyvsp[0].nd_obj2).type, "char") != 0) {
        printf("Incompatible types: trying to divide char\n");
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, "float");
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "%"); 
}
#line 2059 "y.tab.c"
    break;

  case 60:
#line 287 "q1.y"
         {
    strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "other_exp2");
}
#line 2068 "y.tab.c"
    break;

  case 61:
#line 293 "q1.y"
              {
    if (!find_id((yyvsp[0].nd_obj2).name)) {
        printf("Error: Undeclared Variable %s\n", (yyvsp[0].nd_obj2).name);
        exit(1);
    }
    strcpy((yyval.nd_obj2).type, get_type((yyvsp[0].nd_obj2).name));
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd,NULL,"base_exp");
}
#line 2081 "y.tab.c"
    break;

  case 62:
#line 301 "q1.y"
       {
    strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "base_exp");
}
#line 2090 "y.tab.c"
    break;

  case 63:
#line 305 "q1.y"
                           {
    strcpy((yyval.nd_obj2).type,(yyvsp[-1].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[-1].nd_obj2).nd, NULL, "base_exp");   
}
#line 2099 "y.tab.c"
    break;

  case 64:
#line 309 "q1.y"
                     {
    strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "base_exp");   
}
#line 2108 "y.tab.c"
    break;

  case 65:
#line 315 "q1.y"
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
#line 2126 "y.tab.c"
    break;

  case 66:
#line 328 "q1.y"
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
#line 2144 "y.tab.c"
    break;

  case 67:
#line 343 "q1.y"
          { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[0].nd_obj).name);}
#line 2150 "y.tab.c"
    break;

  case 68:
#line 344 "q1.y"
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
#line 2167 "y.tab.c"
    break;

  case 69:
#line 356 "q1.y"
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
#line 2184 "y.tab.c"
    break;


#line 2188 "y.tab.c"

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
#line 374 "q1.y"

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
                id_table[id_cnt].val_i = atoi(value);
            else if (strcmp(d_type, "float") == 0)
                id_table[id_cnt].val_i = atof(value);
            else if (strcmp(d_type, "char") == 0)
                id_table[id_cnt].val_c = value[0];
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
                    id_table[id_cnt].arr_i = malloc(d1 * sizeof(int));
                else if (strcmp(d_type, "float") == 0)
                    id_table[id_cnt].arr_f = malloc(d1 * sizeof(float));
                else if (strcmp(d_type, "char") == 0)
                    id_table[id_cnt].arr_c = malloc(d1 * sizeof(char));
                else
                    assert(0 && "Invalid d_type for add_id, 1d array\n");
            }
            else
            {
                id_table[id_cnt].type = strdup("Array2D");
                if (strcmp(d_type, "int") == 0)
                    id_table[id_cnt].arr_i = malloc(d1 * d2 * sizeof(int));
                else if (strcmp(d_type, "float") == 0)
                    id_table[id_cnt].arr_f = malloc(d1 * d2 * sizeof(float));
                else if (strcmp(d_type, "char") == 0)
                    id_table[id_cnt].arr_c = malloc(d1 * d2 * sizeof(char));
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
            printf("%d\n", id_table[id_cnt].val_i);
        else if (strcmp(d_type, "float") == 0)
            printf("%f\n", id_table[id_cnt].val_f);
        else if (strcmp(d_type, "char") == 0)
            printf("%c\n", id_table[id_cnt].val_c); */
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
                return id_table[i].val_i;
            else if (idx2 == -1)
                return id_table[i].arr_i[idx1];
            else
                return id_table[i].arr_i[idx1 * id_table[i].arr_len2 + idx2];
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
                return id_table[i].val_f;
            else if (idx2 == -1)
                return id_table[i].arr_f[idx1];
            else
                return id_table[i].arr_f[idx1 * id_table[i].arr_len2 + idx2];
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
                return id_table[i].val_c;
            else if (idx2 == -1)
                return id_table[i].arr_c[idx1];
            else
                return id_table[i].arr_c[idx1 * id_table[i].arr_len2 + idx2];
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
                        id_table[i].val_i = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].val_f = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].val_c = value[0];
                    else
                        assert(0 && "Invalid d_type for update_id, variable\n");
                }
                else if (idx2 == -1)
                {
                    if (strcmp(id_table[i].data_type, "int") == 0)
                        id_table[i].arr_i[idx1] = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].arr_f[idx1] = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].arr_c[idx1] = value[0];
                    else
                        assert(0 && "Invalid d_type for update_id, array1d\n");
                }
                else
                {
                    if (strcmp(id_table[i].data_type, "int") == 0)
                        id_table[i].arr_i[idx1 * id_table[i].arr_len2 + idx2] = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].arr_f[idx1 * id_table[i].arr_len2 + idx2] = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].arr_c[idx1 * id_table[i].arr_len2 + idx2] = value[0];
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
