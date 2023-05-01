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
    PLUS = 258,
    MINUS = 259,
    MULT = 260,
    DIV = 261,
    MOD = 262,
    ID = 263,
    ID1 = 264,
    ID2 = 265,
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
    NUM = 292,
    FLOATNUM = 293,
    CHARCONST = 294,
    CONST_SIGNED = 295,
    LPAREN = 296,
    RPAREN = 297,
    LBRACE = 298,
    RBRACE = 299,
    LBRACKET = 300,
    RBRACKET = 301,
    SEMICOLON = 302,
    COMMA = 303,
    SLCOMMENT = 304,
    MLCOMMENT = 305,
    CHARFORMAT = 306,
    INTFORMAT = 307,
    FLOATFORMAT = 308,
    ARR = 309,
    TDARR = 310,
    ARR_EHAI = 311,
    SPACE = 312,
    ASSIGNMENT = 313,
    STRING = 314
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define MULT 260
#define DIV 261
#define MOD 262
#define ID 263
#define ID1 264
#define ID2 265
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
#define NUM 292
#define FLOATNUM 293
#define CHARCONST 294
#define CONST_SIGNED 295
#define LPAREN 296
#define RPAREN 297
#define LBRACE 298
#define RBRACE 299
#define LBRACKET 300
#define RBRACKET 301
#define SEMICOLON 302
#define COMMA 303
#define SLCOMMENT 304
#define MLCOMMENT 305
#define CHARFORMAT 306
#define INTFORMAT 307
#define FLOATFORMAT 308
#define ARR 309
#define TDARR 310
#define ARR_EHAI 311
#define SPACE 312
#define ASSIGNMENT 313
#define STRING 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
