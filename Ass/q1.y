%{
#include <stdio.h>
#include<stdlib.h>
int yylex();
void yyerror();

%}
%token ID ID1 ID2 PLUS MINUS MULT DIV MOD PLUSPLUS
%token EQUAL NOTEQ LT GT LTE GTE LAND LOR LNOT EQUALS
%token IF ELSE WHILE FOR SWITCH CASE BREAK DEFAULT CONTINUE RETURN 
%token INT FLOAT CHAR VOID MAIN 
%token PRINTF SCANF
%token NUM FLOATNUM CHARCONST  CONST_SIGNED 
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA
%token SLCOMMENT MLCOMMENT
%token CHARFORMAT INTFORMAT FLOATFORMAT 
%token ARR TDARR ARR_EHAI
%token SPACE ASSIGNMENT
%token STRING
%%
start : statement
    ;
statement : FUNCTION statement | FUNCTION
    ;
TYPE: INT | FLOAT | CHAR | VOID
    ;
FUNCTION: TYPE ID LPAREN RPAREN LBRACE STATEMENT_LIST RBRACE  
    |
    TYPE ID LPAREN PARAMETER_LIST RPAREN LBRACE STATEMENT_LIST RBRACE
    ;
PARAMETER_LIST: TYPE ID COMMA PARAMETER_LIST | TYPE ID  
    ;
STATEMENT_LIST: STATEMENT STATEMENT_LIST
    | STATEMENT 
    | LBRACE STATEMENT_LIST RBRACE 
    | LBRACE STATEMENT_LIST RBRACE STATEMENT_LIST
    ;

STATEMENT : PRINT_STATEMENTS | RETURN_STATEMENTS | FUNCTION_CALLSTMTS | CONTINUE SEMICOLON | BREAK SEMICOLON | ARRAY_DECLSTMTS| IF_STATEMENT | WHILE_STATEMENT | FOR_STATEMENT | EXPRESSION | ASGNSTMT SEMICOLON | DECLARATION SEMICOLON
    | SEMICOLON    
    |
    ;

PRINT_STATEMENTS : PRINTF LPAREN STRING RPAREN SEMICOLON
    | PRINTF LPAREN STRING COMMA VARIABLE_LIST RPAREN SEMICOLON 
    ;


RETURN_STATEMENTS: RETURN ID SEMICOLON
    | RETURN SEMICOLON
    | RETURN CONST SEMICOLON
    ;

CONST: NUM | FLOATNUM | CHARCONST | CONST_SIGNED
    ;


FUNCTION_CALLSTMTS: ID LPAREN RPAREN SEMICOLON 
    | ID ASSIGNMENT ID LPAREN RPAREN SEMICOLON
    | TYPE ID ASSIGNMENT ID LPAREN ULTIMATE_LIST RPAREN SEMICOLON
    | ID ASSIGNMENT ID LPAREN ULTIMATE_LIST RPAREN SEMICOLON
    | ID LPAREN ULTIMATE_LIST RPAREN SEMICOLON
    | TYPE ID ASSIGNMENT ID LPAREN RPAREN SEMICOLON 
    ;

ULTIMATE_LIST: ID COMMA ULTIMATE_LIST | CONST COMMA ULTIMATE_LIST | ID | CONST
    ;

ARRAY_DECLSTMTS : TYPE TDARR SEMICOLON 
    | TYPE ARR ASSIGNMENT LBRACE CONSTANT_LIST RBRACE SEMICOLON 
    | TYPE TDARR ASSIGNMENT LBRACE ANOTHERCONST_LIST RBRACE SEMICOLON
    | TYPE ARR SEMICOLON 
    | TYPE ARR_EHAI ASSIGNMENT LBRACE ANOTHERCONST_LIST RBRACE SEMICOLON
    ; 
ANOTHERCONST_LIST: LBRACE CONSTANT_LIST RBRACE
    | LBRACE CONSTANT_LIST RBRACE COMMA ANOTHERCONST_LIST
    ;
CONSTANT_LIST: INTEGER_WALI_LIST 
    | FLOAT_WALI_LIST
    | CHAR_WALI_LIST
    ;
INTEGER_WALI_LIST: INT COMMA INTEGER_WALI_LIST 
    | INT COMMA
    ;
FLOAT_WALI_LIST: FLOAT COMMA FLOAT_WALI_LIST
    | FLOAT COMMA
    ;
CHAR_WALI_LIST: CHAR COMMA CHAR_WALI_LIST
    | CHAR COMMA
    ;


FOR_STATEMENT : FOR LPAREN DECLARATION SEMICOLON EXPRESSION SEMICOLON ASSIGNMENT RPAREN LBRACE STATEMENT_LIST RBRACE
    |FOR LPAREN TYPE ASGNSTMT SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE
    |FOR LPAREN ASGNSTMT SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE
    |FOR LPAREN SEMICOLON EXPRESSION SEMICOLON ASSIGNMENT RPAREN LBRACE STATEMENT_LIST RBRACE
;
DECLARATION: TYPE ID DECLARATION_LIST
    ;

DECLARATION_LIST: COMMA ID DECLARATION_LIST | ASSIGNMENT EXPRESSION DECLARATION_LIST 
    | 
    ;

VARIABLE_LIST: ID COMMA VARIABLE_LIST | ID
    ;

IF_STATEMENT : MATCHED | UNMATCHED
    ;
MATCHED: IF LPAREN EXPRESSION RPAREN LBRACE STATEMENT_LIST RBRACE 
    ;
UNMATCHED : IF LPAREN EXPRESSION RPAREN LBRACE STATEMENT_LIST RBRACE ELSE LBRACE STATEMENT_LIST RBRACE 
    ;

WHILE_STATEMENT : WHILE LPAREN EXPRESSION RPAREN LBRACE STATEMENT_LIST RBRACE
    ;

ASGNSTMT : ID ASSIGNMENT EXPRESSION ASGNSTMT_LIST 
    |ID ASSIGNMENT ASGNSTMT_LIST 
    |ID PLUSPLUS
    ;
ASGNSTMT_LIST: COMMA ID ASSIGNMENT EXPRESSION ASGNSTMT_LIST
    | 
    ;

EXPRESSION: TREEM Comperator TREEM| TREEM
;

TREEM : TREEM PLUS TREEM2 
    | TREEM MINUS TREEM2
    | TREEM MULT TREEM2
    | TREEM DIV TREEM2
    | TREEM2
    ;

TREEM2: ID
    | CONST
    | LPAREN EXPRESSION RPAREN
    ;

Comperator: EQUAL |NOTEQ |LT |GT |LTE |GTE |LAND |LOR |LNOT |EQUALS
    ;


%%
void main(){

    printf("\nOUTPUT:\n ");
    freopen("input.txt","r",stdin);
    yyparse();
    /* printf("Symbol table \n %s %s %s",symbol_table[0][0],symbol_table[0][1],symbol_table[0][2])  ; */


}
void yyerror(){
    printf("Invalid Expression:\n");
    exit(0);
}
