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
    PLUSPLUS = 266,
    EQUAL = 267,
    NOTEQ = 268,
    LT = 269,
    GT = 270,
    LTE = 271,
    GTE = 272,
    LAND = 273,
    LOR = 274,
    LNOT = 275,
    EQUALS = 276,
    IF = 277,
    ELSE = 278,
    WHILE = 279,
    FOR = 280,
    SWITCH = 281,
    CASE = 282,
    BREAK = 283,
    DEFAULT = 284,
    CONTINUE = 285,
    RETURN = 286,
    INT = 287,
    FLOAT = 288,
    CHAR = 289,
    VOID = 290,
    MAIN = 291,
    PRINTF = 292,
    SCANF = 293,
    NUM = 294,
    FLOATNUM = 295,
    CHARCONST = 296,
    CONST_SIGNED = 297,
    LPAREN = 298,
    RPAREN = 299,
    LBRACE = 300,
    RBRACE = 301,
    LBRACKET = 302,
    RBRACKET = 303,
    SEMICOLON = 304,
    COMMA = 305,
    SLCOMMENT = 306,
    MLCOMMENT = 307,
    CHARFORMAT = 308,
    INTFORMAT = 309,
    FLOATFORMAT = 310,
    ARR = 311,
    TDARR = 312,
    ARR_EHAI = 313,
    SPACE = 314,
    ASSIGNMENT = 315,
    STRING = 316
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
#define PLUSPLUS 266
#define EQUAL 267
#define NOTEQ 268
#define LT 269
#define GT 270
#define LTE 271
#define GTE 272
#define LAND 273
#define LOR 274
#define LNOT 275
#define EQUALS 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define FOR 280
#define SWITCH 281
#define CASE 282
#define BREAK 283
#define DEFAULT 284
#define CONTINUE 285
#define RETURN 286
#define INT 287
#define FLOAT 288
#define CHAR 289
#define VOID 290
#define MAIN 291
#define PRINTF 292
#define SCANF 293
#define NUM 294
#define FLOATNUM 295
#define CHARCONST 296
#define CONST_SIGNED 297
#define LPAREN 298
#define RPAREN 299
#define LBRACE 300
#define RBRACE 301
#define LBRACKET 302
#define RBRACKET 303
#define SEMICOLON 304
#define COMMA 305
#define SLCOMMENT 306
#define MLCOMMENT 307
#define CHARFORMAT 308
#define INTFORMAT 309
#define FLOATFORMAT 310
#define ARR 311
#define TDARR 312
#define ARR_EHAI 313
#define SPACE 314
#define ASSIGNMENT 315
#define STRING 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
