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
    PLUS = 259,
    MINUS = 260,
    MULT = 261,
    DIV = 262,
    MOD = 263,
    EQUAL = 264,
    NOTEQ = 265,
    LT = 266,
    GT = 267,
    LTE = 268,
    GTE = 269,
    LAND = 270,
    LOR = 271,
    LNOT = 272,
    EQUALS = 273,
    IF = 274,
    ELSE = 275,
    WHILE = 276,
    FOR = 277,
    SWITCH = 278,
    CASE = 279,
    BREAK = 280,
    DEFAULT = 281,
    CONTINUE = 282,
    RETURN = 283,
    INT = 284,
    FLOAT = 285,
    CHAR = 286,
    VOID = 287,
    MAIN = 288,
    PRINTF = 289,
    SCANF = 290,
    NUM = 291,
    FLOATNUM = 292,
    CHARCONST = 293,
    LPAREN = 294,
    RPAREN = 295,
    LBRACE = 296,
    RBRACE = 297,
    LBRACKET = 298,
    RBRACKET = 299,
    SEMICOLON = 300,
    COMMA = 301,
    QUOTE = 302,
    SLCOMMENT = 303,
    MLCOMMENT = 304,
    CHARFORMAT = 305,
    INTFORMAT = 306,
    FLOATFORMAT = 307,
    ARR = 308,
    FUNC = 309,
    TDARR = 310
  };
#endif
/* Tokens.  */
#define ID 258
#define PLUS 259
#define MINUS 260
#define MULT 261
#define DIV 262
#define MOD 263
#define EQUAL 264
#define NOTEQ 265
#define LT 266
#define GT 267
#define LTE 268
#define GTE 269
#define LAND 270
#define LOR 271
#define LNOT 272
#define EQUALS 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define FOR 277
#define SWITCH 278
#define CASE 279
#define BREAK 280
#define DEFAULT 281
#define CONTINUE 282
#define RETURN 283
#define INT 284
#define FLOAT 285
#define CHAR 286
#define VOID 287
#define MAIN 288
#define PRINTF 289
#define SCANF 290
#define NUM 291
#define FLOATNUM 292
#define CHARCONST 293
#define LPAREN 294
#define RPAREN 295
#define LBRACE 296
#define RBRACE 297
#define LBRACKET 298
#define RBRACKET 299
#define SEMICOLON 300
#define COMMA 301
#define QUOTE 302
#define SLCOMMENT 303
#define MLCOMMENT 304
#define CHARFORMAT 305
#define INTFORMAT 306
#define FLOATFORMAT 307
#define ARR 308
#define FUNC 309
#define TDARR 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
