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
NUM ([1-9][0-9]*)|(0)
space [ \t]*
STRING \".*\"

%x MLC
%%
<<EOF>> {
    printf("Symbol Table:\n");
    for(int i = 0;i<si;i++){
        printf("%s %s %s\n",symbol_table_lex[i][0],symbol_table_lex[i][1],symbol_table_lex[i][2]);
    }
    return 0;
}

{NEWLINE} {line++;}

"+" {
    // printf("plus\n");
    sprintf(symbol_table_lex[si][0],"%d",line);
    strcpy(symbol_table_lex[si][1] , "+");
    strcpy(symbol_table_lex[si][2] ,"PLUS");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return PLUS;
}

"-" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "-");
    strcpy(symbol_table_lex[si][2], "MINUS");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return MINUS;
}

"*" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "*");
    strcpy(symbol_table_lex[si][2], "MULT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return MULT;
}

"/" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "/");
    strcpy(symbol_table_lex[si][2], "DIV");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return DIV;
}

"%" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "%");
    strcpy(symbol_table_lex[si][2], "MOD");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return MOD;
}

"=" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "=");
    strcpy(symbol_table_lex[si][2], "ASSIGNMENT");
    si++;
    // printf("assignment\n");
    strcpy(yylval.nd_obj.name,(yytext)); 
    return ASSIGNMENT;
}

"==" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "==");
    strcpy(symbol_table_lex[si][2], "EQUALS");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return EQUALS;
}

"!=" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "!=");
    strcpy(symbol_table_lex[si][2], "NOTEQ");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return NOTEQ;
}

"<" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "<");
    strcpy(symbol_table_lex[si][2], "LT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return LT;
}

">" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ">");
    strcpy(symbol_table_lex[si][2], "GT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return GT;
}

"<=" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "<=");
    strcpy(symbol_table_lex[si][2], "LTE");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return LTE;
}

">=" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ">=");
    strcpy(symbol_table_lex[si][2], "GTE");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return GTE;
}

"&&" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "&&");
    strcpy(symbol_table_lex[si][2], "LAND");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return LAND;
}

"||" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "||");
    strcpy(symbol_table_lex[si][2], "LOR");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return LOR;
}

"!" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "!");
    strcpy(symbol_table_lex[si][2], "LNOT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return LNOT;
}

"if" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "if");
    strcpy(symbol_table_lex[si][2], "IF");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return IF;
}

"else" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "else");
    strcpy(symbol_table_lex[si][2], "ELSE");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return ELSE;
}

"while" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "while");
    strcpy(symbol_table_lex[si][2], "WHILE");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return WHILE;
}

":" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ":");
    strcpy(symbol_table_lex[si][2], "COLON");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return COLON;
}

"case" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "case");
    strcpy(symbol_table_lex[si][2], "CASE");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return CASE;
}

"default" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "default");
    strcpy(symbol_table_lex[si][2], "DEFAULT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return DEFAULT;
}

"break" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "break");
    strcpy(symbol_table_lex[si][2], "BREAK");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return BREAK;
}

"continue" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "continue");
    strcpy(symbol_table_lex[si][2], "CONTINUE");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return CONTINUE;
}

"return" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "return");
    strcpy(symbol_table_lex[si][2], "RETURN");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return RETURN;
}

{INT} {
    // printf("INT\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "int");
    strcpy(symbol_table_lex[si][2], "INT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return INT;
}

{FLOAT} {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "float");
    strcpy(symbol_table_lex[si][2], "FLOAT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return FLOAT;
}

{CHAR} {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "char");
    strcpy(symbol_table_lex[si][2], "CHAR");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return CHAR;
}

{VOID} {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "void");
    strcpy(symbol_table_lex[si][2], "VOID");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return VOID;
}

[1-9][0-9]* {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "NUM");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return NUM;
}

-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "FLOATNUM");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return FLOATNUM;
}

"\'[a-zA-Z0-9]\'" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "CHARCONST");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return CHARCONST;
}

"(" {
    // printf("(");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "(");
    strcpy(symbol_table_lex[si][2], "LPAREN");
    si++;
    // printf("LPAREN\n");
    strcpy(yylval.nd_obj.name,(yytext));
    return LPAREN;
}

")" {
    // printf("RPAREN\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ")");
    strcpy(symbol_table_lex[si][2], "RPAREN");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return RPAREN;
}

"{" {
    // printf("LBRACE\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "{");
    strcpy(symbol_table_lex[si][2], "LBRACE");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return LBRACE;
}

"}" {
    // printf("RBRACE\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "}");
    strcpy(symbol_table_lex[si][2], "RBRACE");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return RBRACE;
}

";" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ";");
    strcpy(symbol_table_lex[si][2], "SEMICOLON");
    si++;
    // printf("semicolon\n");
    strcpy(yylval.nd_obj.name,(yytext));
    return SEMICOLON;
}

"," {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], ",");
    strcpy(symbol_table_lex[si][2], "COMMA");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return COMMA;
}

\/\/.* {line++;};

{space}"/*" BEGIN(MLC);
<MLC>"*/"{space} {
    BEGIN(INITIAL);
}
<MLC>\n {line++;}
<MLC>. {;}

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
    if(strcmp("if(", strr)==0) {
        // printf("IF\n");
        sprintf(symbol_table_lex[si][0], "%d", line);
        strcpy(symbol_table_lex[si][1], "if");
        strcpy(symbol_table_lex[si][2], "IF");
        strcpy(yylval.nd_obj.name,(yytext));
        si++;
        return IF;
    } else if(strcmp("printf(", strr)==0){
        // printf("PRINTF\n");
        sprintf(symbol_table_lex[si][0], "%d", line);
        strcpy(symbol_table_lex[si][1], "printf");
        strcpy(symbol_table_lex[si][2], "PRINTF");
        strcpy(yylval.nd_obj.name,(yytext));
        si++;
        return PRINTF;
    } else if(strcmp("switch(", strr)==0){
        // printf("SWITCH\n");
        sprintf(symbol_table_lex[si][0], "%d", line);
        strcpy(symbol_table_lex[si][1], "switch");
        strcpy(symbol_table_lex[si][2], "SWITCH");
        strcpy(yylval.nd_obj.name,(yytext));
        si++;
        return SWITCH;
    } else if(strcmp("for(", strr)==0){
        // printf("FOR\n");
        sprintf(symbol_table_lex[si][0], "%d", line);
        strcpy(symbol_table_lex[si][1], "for");
        strcpy(symbol_table_lex[si][2], "FOR");
        strcpy(yylval.nd_obj.name,(yytext));
        si++;
        return FOR;
    } else if(strcmp("while(", strr)==0){
            // printf("WHILE\n");
            sprintf(symbol_table_lex[si][0], "%d", line);
            strcpy(symbol_table_lex[si][1], "while");
            strcpy(symbol_table_lex[si][2], "WHILE");
            strcpy(yylval.nd_obj.name,(yytext));
            si++;
            return WHILE;
    }
    // printf("FUNC\n");
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "FUNC");
    strcpy(yylval.nd_obj.name,(yytext));
    si++;
    return FUNC;
}

"%c" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "%c");
    strcpy(symbol_table_lex[si][2], "CHARFORMAT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return CHARFORMAT;
}

"%d" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "%d");
    strcpy(symbol_table_lex[si][2], "INTFORMAT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return INTFORMAT;
}

"%f" {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], "%f");
    strcpy(symbol_table_lex[si][2], "FLOATFORMAT");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return FLOATFORMAT;
}

{ID} {
    // printf("ID\n");
    // printf("%s",yytext);
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "ID");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return ID;
}

[_a-zA-Z][_a-zA-Z0-9]*\[({NUM}|{ID})\] {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "ID1");
    // printf("Matched %s with ID1\n", yytext);
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return ID1;
}


[_a-zA-Z][_a-zA-Z0-9]*\[({NUM}|{ID})\]\[({NUM}|{ID})\] {
    sprintf(symbol_table_lex[si][0], "%d", line);
    strcpy(symbol_table_lex[si][1], yytext);
    strcpy(symbol_table_lex[si][2], "ID2");
    si++;
    strcpy(yylval.nd_obj.name,(yytext)); 
    return ID2;
}

{STRING} {
    // printf("STRING matched:%s\n", yytext);
    sprintf(symbol_table_lex[si][0],"%d",line);
    strcpy(symbol_table_lex[si][1] , """");
    strcpy(symbol_table_lex[si][2] ,"STRING");
    si++;
    strcpy(yylval.nd_obj.name,(yytext));
    return STRING;
}

%%

