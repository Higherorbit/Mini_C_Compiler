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

#line 171 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
