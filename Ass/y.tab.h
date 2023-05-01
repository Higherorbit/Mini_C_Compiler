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
    ASSIGNMENT = 258,
    PLUS = 259,
    MINUS = 260,
    MULT = 261,
    DIV = 262,
    MOD = 263,
    STRING = 264,
    INT = 265,
    FLOAT = 266,
    CHAR = 267,
    VOID = 268,
    IF = 269,
    ELSE = 270,
    WHILE = 271,
    FOR = 272,
    SWITCH = 273,
    CASE = 274,
    BREAK = 275,
    DEFAULT = 276,
    CONTINUE = 277,
    RETURN = 278,
    PRINTF = 279,
    GTE = 280,
    LTE = 281,
    NOTEQ = 282,
    LAND = 283,
    LOR = 284,
    LNOT = 285,
    EQUALS = 286,
    LT = 287,
    GT = 288,
    ID = 289,
    ID1 = 290,
    ID2 = 291,
    NUM = 292,
    FLOATNUM = 293,
    CHARCONST = 294,
    FUNC = 295,
    LPAREN = 296,
    RPAREN = 297,
    LBRACE = 298,
    RBRACE = 299,
    SEMICOLON = 300,
    COMMA = 301,
    SLCOMMENT = 302,
    MLCOMMENT = 303,
    CHARFORMAT = 304,
    INTFORMAT = 305,
    FLOATFORMAT = 306
  };
#endif
/* Tokens.  */
#define ASSIGNMENT 258
#define PLUS 259
#define MINUS 260
#define MULT 261
#define DIV 262
#define MOD 263
#define STRING 264
#define INT 265
#define FLOAT 266
#define CHAR 267
#define VOID 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define FOR 272
#define SWITCH 273
#define CASE 274
#define BREAK 275
#define DEFAULT 276
#define CONTINUE 277
#define RETURN 278
#define PRINTF 279
#define GTE 280
#define LTE 281
#define NOTEQ 282
#define LAND 283
#define LOR 284
#define LNOT 285
#define EQUALS 286
#define LT 287
#define GT 288
#define ID 289
#define ID1 290
#define ID2 291
#define NUM 292
#define FLOATNUM 293
#define CHARCONST 294
#define FUNC 295
#define LPAREN 296
#define RPAREN 297
#define LBRACE 298
#define RBRACE 299
#define SEMICOLON 300
#define COMMA 301
#define SLCOMMENT 302
#define MLCOMMENT 303
#define CHARFORMAT 304
#define INTFORMAT 305
#define FLOATFORMAT 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
