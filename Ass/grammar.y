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
%token QUOTE SLCOMMENT MLCOMMENT
%token CHARFORMAT INTFORMAT FLOATFORMAT 
%%
start : declaration start 
    ;
declaration : type ID SEMICOLON|
    type ID EQUAL expr |
    ;
type : INTFORMAT|FLOATFORMAT|CHARFORMAT;
expr: const|ID|
    expr PLUS expr |
    expr MINUS expr |
    expr MULT expr |
    expr DIV expr |
    expr MOD expr |
    LPAREN expr RPAREN
    ;
assn: ID EQUAL expr SEMICOLON;

const: NUM | FLOATNUM | CHARCONST;

control_stmts : if | FOR | WHILE | SWITCH;

if : IF LPAREN expr RPAREN compstmt optionalelse;
optionalelse : ELSE compstmt|
               ELSE IF compstmt
             ;




return_stmts : RETURN 




compstmt : '{' statements '}'
        ;
statements : statements stmt |
        compstmt
        ;
stmt : declaration | control_stmts | compstmt | SEMICOLON | PRINTF;




%%
void main(){
    printf("Enter the sentence:\n ");
    freopen("input.txt","r",stdin);
    yyparse();
    /* printf("Symbol table \n %s %s %s",symbol_table[0][0],symbol_table[0][1],symbol_table[0][2])  ; */
}
void yyerror(){
    printf("Invalid Expression:\n");
    exit(0);
}

