%{
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include "headerss.h"
extern int *yyin;
int label = 0; 
%}
%union{
    char* lexeme;
}
%left <lexeme> ASSIGNMENT
%left <lexeme> PLUS MINUS
%left <lexeme> MULT DIV MOD 
%token COLON
%token IF ELSE WHILE FOR SWITCH CASE BREAK DEFAULT CONTINUE RETURN PRINTF
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA
%token SLCOMMENT MLCOMMENT
%token CHARFORMAT INTFORMAT FLOATFORMAT 
%token <lexeme> INT FLOAT CHAR VOID GTE LTE NOTEQ LAND LOR LNOT EQUALS LT GT
%token <lexeme> ID ID1 ID2 NUM FLOATNUM CHARCONST FUNC STRING
%type <lexeme> CONST TYPE DECLARATION EXPRESSION TREEM2 TREEM Comperator PARAMETER_LIST
%%
start : initiall;
initiall : FUNCTION initiall | FUNCTION;




STATEMENT_LIST: STATEMENT | LBRACE STATEMENT_LIST RBRACE STATEMENT_LIST
| LBRACE STATEMENT_LIST RBRACE |STATEMENT STATEMENT_LIST;
 




STATEMENT :PRINT_STATEMENTS | 
RETURN_STATEMENTS | 
BREAK SEMICOLON | 
ARRAY_DECLSTMTS| 
{printf("\nL%d: \n", ++label);} IF_STATEMENT | 
FUNCTION_CALLSTMTS | 
CONTINUE SEMICOLON | 
{printf("\nL%d: \n", ++label);} WHILE_STATEMENT | 
{printf("\nL%d: \n", ++label);} FOR_STATEMENT |  
DECLARATION SEMICOLON | 
EXPRESSION | 
ASGNSTMT SEMICOLON 
    | Switch_stmt
    | SEMICOLON    
    ;

TYPE: VOID{$$=$1;} | INT{$$=$1;}  | CHAR {$$=$1;} | FLOAT {$$=$1;} ;






PRINT_STATEMENTS : PRINTF STRING RPAREN SEMICOLON
    | PRINTF STRING COMMA VARIABLE_LIST RPAREN SEMICOLON 
    ;
 
 
RETURN_STATEMENTS: RETURN ID SEMICOLON
    | RETURN SEMICOLON
    | RETURN CONST SEMICOLON
    ;
 
CONST: NUM{$$ = $1;} | FLOATNUM{$$ = $1;} | CHARCONST{$$ = $1;} 
    ;
 
FUNCTION_CALLSTMTS: FUNC RPAREN SEMICOLON 
    | ID ASSIGNMENT FUNC RPAREN SEMICOLON
    | TYPE ID ASSIGNMENT FUNC ULTIMATE_LIST RPAREN SEMICOLON
    | ID ASSIGNMENT FUNC ULTIMATE_LIST RPAREN SEMICOLON
    | FUNC ULTIMATE_LIST RPAREN SEMICOLON
    | TYPE ID ASSIGNMENT FUNC RPAREN SEMICOLON 
    ;

FOR_STATEMENT : FOR DECLARATION SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST {printf("\niftrue %s goto L%d\n", $4, label);} RBRACE
    |FOR ASGNSTMT SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST {printf("\niftrue %s goto L%d\n", $4, label);} RBRACE
    |FOR SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST {printf("\niftrue %s goto L%d\n", $3, label);} RBRACE
;

MATCHED: IF  EXPRESSION RPAREN LBRACE STATEMENT_LIST RBRACE 
    ;

 
ASGNSTMT : ID ASSIGNMENT EXPRESSION ASGNSTMT_LIST {assignment($1, $3);}
| ID1 ASSIGNMENT EXPRESSION COMMA ASGNSTMT {assignment($1, $3);}
      | ID1 ASSIGNMENT EXPRESSION {assignment($1, $3);}
      | ID2 ASSIGNMENT EXPRESSION COMMA ASGNSTMT {assignment($1, $3);}
      | ID2 ASSIGNMENT EXPRESSION {assignment($1, $3);}
    ;

ULTIMATE_LIST: ID COMMA ULTIMATE_LIST | CONST COMMA ULTIMATE_LIST | ID | CONST
    ;

FUNCTION:  TYPE FUNC PARAMETER_LIST RPAREN LBRACE STATEMENT_LIST RBRACE | TYPE FUNC RPAREN LBRACE STATEMENT_LIST RBRACE  ;
PARAMETER_LIST: PARAMETER_LIST COMMA TYPE ID | 
TYPE ID  
;


ARRAY_DECLSTMTS : TYPE ID1 SEMICOLON
         | TYPE ID1 ASSIGNMENT LBRACE CONSTANT_LIST RBRACE SEMICOLON
         | TYPE ID2 SEMICOLON
         | TYPE ID2 ASSIGNMENT LBRACE ANOTHERCONST_LIST RBRACE SEMICOLON


    ; 
ANOTHERCONST_LIST: LBRACE CONSTANT_LIST RBRACE
    | LBRACE CONSTANT_LIST RBRACE COMMA ANOTHERCONST_LIST
    ;
CONSTANT_LIST: INTEGER_WALI_LIST 
    | FLOAT_WALI_LIST
    | CHAR_WALI_LIST
    ;
INTEGER_WALI_LIST: NUM COMMA INTEGER_WALI_LIST 
    | NUM
    ;
FLOAT_WALI_LIST: FLOATNUM COMMA FLOAT_WALI_LIST
    | FLOATNUM 
    ;
CHAR_WALI_LIST: CHARCONST COMMA CHAR_WALI_LIST
    | CHARCONST 
    ;
 


 
DECLARATION_LIST: COMMA ID DECLARATION_LIST 
    | COMMA ID ASSIGNMENT EXPRESSION DECLARATION_LIST {assignment($2, $4);}
    | 
    ;


WHILE_STATEMENT :  WHILE EXPRESSION RPAREN LBRACE STATEMENT_LIST {printf("\niftrue %s goto L%d\n", $2, label);} RBRACE
    ;
 
VARIABLE_LIST: ID COMMA VARIABLE_LIST | ID
    ;
 
IF_STATEMENT : MATCHED | UNMATCHED
    ;
UNMATCHED : IF  EXPRESSION RPAREN LBRACE STATEMENT_LIST RBRACE ELSE LBRACE STATEMENT_LIST RBRACE 
    ;
 

ASGNSTMT_LIST: COMMA ID ASSIGNMENT EXPRESSION ASGNSTMT_LIST {assignment($2, $4);}
    |
    ;
 
EXPRESSION: EXPRESSION Comperator TREEM 
{    $$ = treemFunctions($1, $2, $3);
varTemp = varTemp + 1;
}
    | TREEM 
;

DECLARATION: TYPE ID ASSIGNMENT EXPRESSION DECLARATION_LIST {assignment($2, $4);} 
| TYPE ID DECLARATION_LIST
    ;

TREEM : TREEM PLUS TREEM2   {
        $$ = treemFunctions($1, $2, $3);
        varTemp = varTemp + 1;
    }
    | TREEM2
    | TREEM DIV TREEM2 {
        $$ = treemFunctions($1, $2, $3);
        varTemp = varTemp + 1;
    }
    | TREEM MULT TREEM2 {
        $$ = treemFunctions($1, $2, $3);
        varTemp = varTemp + 1;
    }
    
    | TREEM MINUS TREEM2 {
        $$ = treemFunctions($1, $2, $3);
        varTemp = varTemp + 1;
    }
    | TREEM MOD TREEM2 {
        $$ = treemFunctions($1, $2, $3);
        varTemp = varTemp + 1;
    }
   
    ;

TREEM2: ID {$$ = $1;}
    | CONST{$$ = $1;}
    | LPAREN EXPRESSION RPAREN {$$ = $2;}
    ;

Comperator: LAND {$$ = $1;}|LOR {$$ = $1;}|EQUALS{$$ = $1;} |LNOT{$$ = $1;} | LT {$$ = $1;}| GT {$$ = $1;}|LTE {$$ = $1;} | NOTEQ {$$ = $1;}|GTE {$$ = $1;}
;


Switch_stmt: SWITCH ID RPAREN LBRACE CASES RBRACE ;
CASES : CASE NUM COLON STATEMENT_LIST  CASES
    | DEFAULT COLON STATEMENT_LIST 
    ;
%%
int main(int argc, char const *argv[])
{
    yyin = fopen(argv[1], "r");
    freopen("output.txt", "w", stdout);
    if(yyparse()==0){
        printf("success\n");
    }
}
void yyerror(char* s){
    printf("Error: %s\n", s);
    return 0;
    
}