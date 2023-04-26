/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    ID = 258,
    ID1 = 259,
    ID2 = 260,
    PLUS = 261,
    MINUS = 262,
    MULT = 263,
    DIV = 264,
    MOD = 265,
    EQUAL = 266,
    NOTEQ = 267,
    LT = 268,
    GT = 269,
    LTE = 270,
    GTE = 271,
    LAND = 272,
    LOR = 273,
    LNOT = 274,
    EQUALS = 275,
    IF = 276,
    ELSE = 277,
    WHILE = 278,
    FOR = 279,
    SWITCH = 280,
    CASE = 281,
    BREAK = 282,
    DEFAULT = 283,
    CONTINUE = 284,
    RETURN = 285,
    INT = 286,
    FLOAT = 287,
    CHAR = 288,
    VOID = 289,
    MAIN = 290,
    PRINTF = 291,
    SCANF = 292,
    NUM = 293,
    FLOATNUM = 294,
    CHARCONST = 295,
    LPAREN = 296,
    RPAREN = 297,
    LBRACE = 298,
    RBRACE = 299,
    LBRACKET = 300,
    RBRACKET = 301,
    SEMICOLON = 302,
    COMMA = 303,
    QUOTE = 304,
    SLCOMMENT = 305,
    MLCOMMENT = 306,
    CHARFORMAT = 307,
    INTFORMAT = 308,
    FLOATFORMAT = 309,
    ARR = 310,
    FUNC = 311,
    TDARR = 312
  };
#endif
/* Tokens.  */
#define ID 258
#define ID1 259
#define ID2 260
#define PLUS 261
#define MINUS 262
#define MULT 263
#define DIV 264
#define MOD 265
#define EQUAL 266
#define NOTEQ 267
#define LT 268
#define GT 269
#define LTE 270
#define GTE 271
#define LAND 272
#define LOR 273
#define LNOT 274
#define EQUALS 275
#define IF 276
#define ELSE 277
#define WHILE 278
#define FOR 279
#define SWITCH 280
#define CASE 281
#define BREAK 282
#define DEFAULT 283
#define CONTINUE 284
#define RETURN 285
#define INT 286
#define FLOAT 287
#define CHAR 288
#define VOID 289
#define MAIN 290
#define PRINTF 291
#define SCANF 292
#define NUM 293
#define FLOATNUM 294
#define CHARCONST 295
#define LPAREN 296
#define RPAREN 297
#define LBRACE 298
#define RBRACE 299
#define LBRACKET 300
#define RBRACKET 301
#define SEMICOLON 302
#define COMMA 303
#define QUOTE 304
#define SLCOMMENT 305
#define MLCOMMENT 306
#define CHARFORMAT 307
#define INTFORMAT 308
#define FLOATFORMAT 309
#define ARR 310
#define FUNC 311
#define TDARR 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
