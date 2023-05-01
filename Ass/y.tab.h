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

#line 170 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
