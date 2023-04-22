%{
#include <stdio.h>
#include<stdlib.h>
int yylex();
void yyerror();
%}
%token ID PLUS MINUS MULT DIV MOD
%token EQUAL NOTEQ LT GT LTE GTE LAND LOR LNOT EQUALS
%token IF ELSE WHILE FOR SWITCH CASE BREAK DEFAULT CONTINUE RETURN 
%token INT FLOAT CHAR VOID MAIN 
%token PRINTF SCANF
%token NUM FLOATNUM CHARCONST 
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA
%token QUOTE SLCOMMENT MLCOMMENTOPEN MLCOMMENTCLOSE 
%token CHARFORMAT INTFORMAT FLOATFORMAT  
%%
start : statement
    | statement start
    ;
statement : B
;
B : ID
;
%%
void main(){
    printf("Enter the sentence:\n");
    yyparse();
}
void yyerror(){
    printf("Invalid Expression:\n");
    exit(0);
}
