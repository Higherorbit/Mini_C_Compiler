%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "y.tab.h"
    int num_vars = 0;
    int num_format = 0,line=1;
    // make a symbol table of tokens and print it
    int si = 0;
%}
INT "int"
VOID "void"
FLOAT "float"
CHAR "char"
NEWLINE \n
ID [_a-zA-Z][_a-zA-Z0-9]*
NUM [1-9][0-9]*|0
space [ \t]*
STRING \".*\"

%x MLC
%%
<<EOF>> {
    yylval.lexeme = strdup(yytext);return 0;
}

[_a-zA-Z][_a-zA-Z0-9]*\[({NUM}|{ID})\]\[({NUM}|{ID})\] {
    yylval.lexeme = strdup(yytext);return ID2;
}

{NEWLINE} {line++;}

"+" {
    // printf("plus\n");
    yylval.lexeme = strdup(yytext);return PLUS;
}

"-" {
    yylval.lexeme = strdup(yytext);return MINUS;
}

"*" {
    yylval.lexeme = strdup(yytext);return MULT;
}

"/" {
    yylval.lexeme = strdup(yytext);return DIV;
}

"%" {
    yylval.lexeme = strdup(yytext);return MOD;
}

"=" {
    // printf("assignment\n");
    yylval.lexeme = strdup(yytext);return ASSIGNMENT;
}

"==" {
    yylval.lexeme = strdup(yytext);return EQUALS;
}

"!=" {
    yylval.lexeme = strdup(yytext);return NOTEQ;
}

"<" {
    // printf("LT\n");
    yylval.lexeme = strdup(yytext);return LT;
}

">" {
    yylval.lexeme = strdup(yytext);return GT;
}

"<=" {
    yylval.lexeme = strdup(yytext);return LTE;
}

">=" {
    yylval.lexeme = strdup(yytext);return GTE;
}

"&&" {
    yylval.lexeme = strdup(yytext);return LAND;
}

"||" {
    yylval.lexeme = strdup(yytext);return LOR;
}

"!" {
    yylval.lexeme = strdup(yytext);return LNOT;
}

"if" {
    yylval.lexeme = strdup(yytext);return IF;
}

"else" {
    yylval.lexeme = strdup(yytext);return ELSE;
}

"while" {
    yylval.lexeme = strdup(yytext);return WHILE;
}

"for" {
    // printf("for\n");
    yylval.lexeme = strdup(yytext);return FOR;
}

"switch" {
    yylval.lexeme = strdup(yytext);return SWITCH;
}

":" {
    yylval.lexeme = strdup(yytext);return COLON;
}
"case" {
    yylval.lexeme = strdup(yytext);return CASE;
}

"default" {
    yylval.lexeme = strdup(yytext);return DEFAULT;
}

"break" {
    yylval.lexeme = strdup(yytext);return BREAK;
}

"continue" {
    yylval.lexeme = strdup(yytext);return CONTINUE;
}


{INT} {
    // printf("INT\n");
    yylval.lexeme = strdup(yytext);return INT;
}

{FLOAT} {
    yylval.lexeme = strdup(yytext);return FLOAT;
}

{CHAR} {
    yylval.lexeme = strdup(yytext);return CHAR;
}

"void" {
    yylval.lexeme = strdup(yytext);return VOID;
}

[1-9][0-9]*|0 {
    yylval.lexeme = strdup(yytext);return NUM;
}
[0-9]*\.[0-9]+ {
    yylval.lexeme = strdup(yytext);return FLOATNUM;
}
"\'[a-zA-Z0-9]\'" {
    yylval.lexeme = strdup(yytext);return CHARCONST;
}

"(" {
    // printf("(");
    // printf("LPAREN\n");
    yylval.lexeme = strdup(yytext);return LPAREN;
}

")" {
    // printf("RPAREN\n");
    yylval.lexeme = strdup(yytext);return RPAREN;
}

"{" {
    // printf("LBRACE\n");
    yylval.lexeme = strdup(yytext);return LBRACE;
}

"}" {
    // printf("RBRACE\n");
    yylval.lexeme = strdup(yytext);return RBRACE;
}

"[" {
    yylval.lexeme = strdup(yytext);return LBRACKET;
}

"]" {
    yylval.lexeme = strdup(yytext);return RBRACKET;
}

";" {
    // printf("semicolon\n");
    yylval.lexeme = strdup(yytext);return SEMICOLON;
}

"printf" {
    // printf("PRINTF\n");
    yylval.lexeme = strdup(yytext);return PRINTF;
}

"," {
    yylval.lexeme = strdup(yytext);return COMMA;
}

\/\/.* ;

{space}"/*" BEGIN(MLC);
<MLC>"*/"{space} {
    BEGIN(INITIAL); 
    }
<MLC>\n {line++;}
<MLC>. {;}


"%c" {
    yylval.lexeme = strdup(yytext);return CHARFORMAT;
}

"%d" {
    yylval.lexeme = strdup(yytext);return INTFORMAT;
}

"%f" {
    yylval.lexeme = strdup(yytext);return FLOATFORMAT;
}

{ID} {
    // printf("ID\n");
    // printf("%s",yytext);
    yylval.lexeme = strdup(yytext);return ID;
}

{ID}{space}"(" {
    //COUNT NUMBER OF WHITESPACES
    int i=0,j=0;
    int white_space = 0;
    char strr[100];
    
    while(i < yyleng){
        if(yytext[i] == ' ' || yytext[i] == '\t')
            white_space++;
        else{
            strr[j] = yytext[i];
            // printf("char = %c\n",strr[j]);
            j++;
        }
        i++;
    }
    strr[j] = '\0';
    if(strcmp("if(", strr)==0){
            yylval.lexeme = strdup(yytext);return IF;}
        else if(strcmp("printf(", strr)==0){
            yylval.lexeme = strdup(yytext);
            return PRINTF;}
        else if(strcmp("switch(", strr)==0){
            yylval.lexeme = strdup(yytext);
            return SWITCH;}
        else if(strcmp("for(", strr)==0){
            yylval.lexeme = strdup(yytext);
            return FOR;
        }
        else if(strcmp("while(", strr)==0){
            yylval.lexeme = strdup(yytext);
            return WHILE;
        }
            yylval.lexeme = strdup(yytext);
    return FUNC;
}

[_a-zA-Z][_a-zA-Z0-9]*\[{NUM}\] {
    yylval.lexeme = strdup(yytext);return ID1;
}
{STRING} {
    // printf("STRING\n");
    yylval.lexeme = strdup(yytext);return STRING;
}

%%
