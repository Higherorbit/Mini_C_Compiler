%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "y.tab.h"
    int num_vars = 0;
    int num_format = 0,line=1;
    // make a symbol table of tokens and print it
    char symbol_table_lex[10000][3][20];
    int si = 0;
%}
INT "int"
VOID "void"
FLOAT "float"
CHAR "char"
NEWLINE \n
ID [_a-zA-Z][_a-zA-Z0-9]*
PRINTFID [_a-zA-Z][_a-zA-Z0-9]*['['{NUM}']']*
NUM [0-9][1-9]*|0|" "
space [ \t]*
spaceCOMP [ \t\n]+
alpha [A-Za-z]
digit [0-9]
und "_"
STRING [a-zA-Z0-9_%]

%x MLC
%%
<<EOF>> {
    printf("Symbol Table:\n");
    for(int i = 0;i<si;i++){
        printf("%s %s %s\n",symbol_table_lex[i][0],symbol_table_lex[i][1],symbol_table_lex[i][2]);
    }
    // return END_OF_FILE;
    return 0;
}

[_a-zA-Z][_a-zA-Z0-9]*\[{NUM}\]\[{NUM}\] {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "ID2");
    si++;
    return ID2;
}

{NEWLINE} {line++;}

"+" {
    printf("plus\n");
    sprintf(symbol_table_lex[si][0],"%d",line);
    strcpy(symbol_table_lex[si][1] , "+");
    strcpy(symbol_table_lex[si][2] ,"PLUS");
    si++;
    return PLUS;
}

"-" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "-");
    strcpy(symbol_table_lex[si][2], "MINUS");
    si++;
    return MINUS;
}

"*" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "*");
    strcpy(symbol_table_lex[si][2], "MULT");
    si++;
    return MULT;
}

"/" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "/");
    strcpy(symbol_table_lex[si][2], "DIV");
    si++;
    return DIV;
}

"%" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "%");
    strcpy(symbol_table_lex[si][2], "MOD");
    si++;
    return MOD;
}

"=" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "=");
    strcpy(symbol_table_lex[si][2], "ASSIGNMENT");
    si++;
    printf("assignment\n");
    return ASSIGNMENT;
}

"==" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "==");
    strcpy(symbol_table_lex[si][2], "EQUALS");
    si++;
    return EQUALS;
}

"!=" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "!=");
    strcpy(symbol_table_lex[si][2], "NOTEQ");
    si++;
    return NOTEQ;
}

"<" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "<");
    strcpy(symbol_table_lex[si][2], "LT");
    si++;
    return LT;
}

">" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ">");
    strcpy(symbol_table_lex[si][2], "GT");
    si++;
    return GT;
}

"<=" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "<=");
    strcpy(symbol_table_lex[si][2], "LTE");
    si++;
    return LTE;
}

">=" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ">=");
    strcpy(symbol_table_lex[si][2], "GTE");
    si++;
    return GTE;
}

"&&" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "&&");
    strcpy(symbol_table_lex[si][2], "LAND");
    si++;
    return LAND;
}

"||" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "||");
    strcpy(symbol_table_lex[si][2], "LOR");
    si++;
    return LOR;
}

"!" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "!");
    strcpy(symbol_table_lex[si][2], "LNOT");
    si++;
    return LNOT;
}

"if" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "if");
    strcpy(symbol_table_lex[si][2], "IF");
    si++;
    return IF;
}

"else" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "else");
    strcpy(symbol_table_lex[si][2], "ELSE");
    si++;
    return ELSE;
}

"while" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "while");
    strcpy(symbol_table_lex[si][2], "WHILE");
    si++;
    return WHILE;
}

"for" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "for");
    strcpy(symbol_table_lex[si][2], "FOR");
    si++;
    printf("for\n");
    return FOR;
}

"switch" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "switch");
    strcpy(symbol_table_lex[si][2], "SWITCH");
    si++;
    return SWITCH;
}

"case" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "case");
    strcpy(symbol_table_lex[si][2], "CASE");
    si++;
    return CASE;
}

"default" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "default");
    strcpy(symbol_table_lex[si][2], "DEFAULT");
    si++;
    return DEFAULT;
}

"break" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "break");
    strcpy(symbol_table_lex[si][2], "BREAK");
    si++;
    return BREAK;
}

"continue" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "continue");
    strcpy(symbol_table_lex[si][2], "CONTINUE");
    si++;
    return CONTINUE;
}

"return" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "return");
    strcpy(symbol_table_lex[si][2], "RETURN");
    si++;
    return RETURN;
}

{INT} {
    printf("INT\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "int");
    strcpy(symbol_table_lex[si][2], "INT");
    si++;
    return INT;
}

{FLOAT} {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "float");
    strcpy(symbol_table_lex[si][2], "FLOAT");
    si++;
    return FLOAT;
}

{CHAR} {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "char");
    strcpy(symbol_table_lex[si][2], "CHAR");
    si++;
    return CHAR;
}

"void" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "void");
    strcpy(symbol_table_lex[si][2], "VOID");
    si++;
    return VOID;
}

[1-9][0-9]* {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "NUM");
    si++;
    return NUM;
}
[0-9]*\.[0-9]+ {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "FLOATNUM");
    si++;
    return FLOATNUM;
}
"\'[a-zA-Z0-9]\'" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "CHARCONST");
    si++;
    return CHARCONST;
}

"(" {
    printf("(");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "(");
    strcpy(symbol_table_lex[si][2], "LPAREN");
    si++;
    printf("LPAREN\n");
    return LPAREN;
}

")" {
    printf("RPAREN\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ")");
    strcpy(symbol_table_lex[si][2], "RPAREN");
    si++;
    return RPAREN;
}

"{" {
    printf("LBRACE\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "{");
    strcpy(symbol_table_lex[si][2], "LBRACE");
    si++;
    return LBRACE;
}

"}" {
    printf("RBRACE\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "}");
    strcpy(symbol_table_lex[si][2], "RBRACE");
    si++;
    return RBRACE;
}

"[" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "[");
    strcpy(symbol_table_lex[si][2], "LBRACKET");
    si++;
    return LBRACKET;
}

"]" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "]");
    strcpy(symbol_table_lex[si][2], "RBRACKET");
    si++;
    return RBRACKET;
}

";" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ";");
    strcpy(symbol_table_lex[si][2], "SEMICOLON");
    si++;
    printf("semicolon\n");
    return SEMICOLON;
}

"printf" {
    printf("PRINTF\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "printf");
    strcpy(symbol_table_lex[si][2], "PRINTF");
    si++;
    return PRINTF;
}

"," {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ",");
    strcpy(symbol_table_lex[si][2], "COMMA");
    si++;
    return COMMA;
}

\/\/[.^\n]*\n {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "yytext");
    strcpy(symbol_table_lex[si][2], "SLCOMMENT");
    si++;
    return SLCOMMENT;
}

{space}"/*" BEGIN(MLC);
<MLC>"*/"{space} {
    BEGIN(INITIAL); 
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "MLCOMMENT");
    si++;
    return MLCOMMENT;}
<MLC>\n {line++;}
<MLC>. {;}


"%c" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "%c");
    strcpy(symbol_table_lex[si][2], "CHARFORMAT");
    si++;
    return CHARFORMAT;
}

"%d" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "%d");
    strcpy(symbol_table_lex[si][2], "INTFORMAT");
    si++;
    return INTFORMAT;
}

"%f" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "%f");
    strcpy(symbol_table_lex[si][2], "FLOATFORMAT");
    si++;
    return FLOATFORMAT;
}

{ID} {
    printf("ID\n");
    printf("%s",yytext);
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "ID");
    si++;
    return ID;
}



[_a-zA-Z][_a-zA-Z0-9]*\[{NUM}\] {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "ID1");
    si++;
    return ID1;
}

"\""[^\"]*"\"" {
    printf("STRING\n");
    sprintf(symbol_table_lex[si][0],"%d",line);
    strcpy(symbol_table_lex[si][1] , """");
    strcpy(symbol_table_lex[si][2] ,"STRING");
    si++;
    return STRING;
}

%%

