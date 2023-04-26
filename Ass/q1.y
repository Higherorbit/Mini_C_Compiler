%{
#include <stdio.h>
#include<stdlib.h>
int yylex();
void yyerror();
%}
%token ID ID1 ID2 PLUS MINUS MULT DIV MOD
%token EQUAL NOTEQ LT GT LTE GTE LAND LOR LNOT EQUALS
%token IF ELSE WHILE FOR SWITCH CASE BREAK DEFAULT CONTINUE RETURN 
%token INT FLOAT CHAR VOID MAIN 
%token PRINTF SCANF
%token NUM FLOATNUM CHARCONST 
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA
%token QUOTE SLCOMMENT MLCOMMENT
%token CHARFORMAT INTFORMAT FLOATFORMAT 
%token ARR FUNC TDARR
%%
start : statement
    ;
statement : INT ID SEMICOLON '\n' INT ID SEMICOLON
    ;
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
