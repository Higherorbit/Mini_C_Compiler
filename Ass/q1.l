%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "y.tab.h"
    int num_vars = 0;
    int num_format = 0,line=1;
    // make a symbol table of tokens and print it
    char symbol_table[1000][3][20];
    int si = 0;
%}
ID [a-zA-Z][a-zA-Z0-9]*
space [ \t\n]*
%x MLC
%%
<<EOF>> {
    for(int i = 0;i<si;i++){
        printf("%s %s %s\n",symbol_table[i][0],symbol_table[i][1],symbol_table[i][2]);
    }
    // return END_OF_FILE;
    return 0;
}
"+" {
    sprintf(symbol_table[si][0],"%d",line);
    strcpy(symbol_table[si][1] , "+");
    strcpy(symbol_table[si][2] ,"PLUS");
    si++;
    return PLUS;
}

"-" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "-");
    strcpy(symbol_table[si][2], "MINUS");
    si++;
    return MINUS;
}

"*" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "*");
    strcpy(symbol_table[si][2], "MULT");
    si++;
    return MULT;
}

"/" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "/");
    strcpy(symbol_table[si][2], "DIV");
    si++;
    return DIV;
}

"%" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "%");
    strcpy(symbol_table[si][2], "MOD");
    si++;
    return MOD;
}

"=" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "=");
    strcpy(symbol_table[si][2], "EQUAL");
    si++;
    return EQUAL;
}

"==" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "==");
    strcpy(symbol_table[si][2], "EQUALS");
    si++;
    return EQUALS;
}

"!=" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "!=");
    strcpy(symbol_table[si][2], "NOTEQ");
    si++;
    return NOTEQ;
}

"<" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "<");
    strcpy(symbol_table[si][2], "LT");
    si++;
    return LT;
}

">" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], ">");
    strcpy(symbol_table[si][2], "GT");
    si++;
    return GT;
}

"<=" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "<=");
    strcpy(symbol_table[si][2], "LTE");
    si++;
    return LTE;
}

">=" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], ">=");
    strcpy(symbol_table[si][2], "GTE");
    si++;
    return GTE;
}

"&&" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "&&");
    strcpy(symbol_table[si][2], "LAND");
    si++;
    return LAND;
}

"||" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "||");
    strcpy(symbol_table[si][2], "LOR");
    si++;
    return LOR;
}

"!" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "!");
    strcpy(symbol_table[si][2], "LNOT");
    si++;
    return LNOT;
}

"if" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "if");
    strcpy(symbol_table[si][2], "IF");
    si++;
    return IF;
}

"else" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "else");
    strcpy(symbol_table[si][2], "ELSE");
    si++;
    return ELSE;
}

"while" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "while");
    strcpy(symbol_table[si][2], "WHILE");
    si++;
    return WHILE;
}

"for" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "for");
    strcpy(symbol_table[si][2], "FOR");
    si++;
    return FOR;
}

"switch" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "switch");
    strcpy(symbol_table[si][2], "SWITCH");
    si++;
    return SWITCH;
}

"case" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "case");
    strcpy(symbol_table[si][2], "CASE");
    si++;
    return CASE;
}

"default" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "default");
    strcpy(symbol_table[si][2], "DEFAULT");
    si++;
    return DEFAULT;
}

"break" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "break");
    strcpy(symbol_table[si][2], "BREAK");
    si++;
    return BREAK;
}

"continue" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "continue");
    strcpy(symbol_table[si][2], "CONTINUE");
    si++;
    return CONTINUE;
}

"return" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "return");
    strcpy(symbol_table[si][2], "RETURN");
    si++;
    return RETURN;
}

"int" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "int");
    strcpy(symbol_table[si][2], "INT");
    si++;
    return INT;
}

"float" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "float");
    strcpy(symbol_table[si][2], "FLOAT");
    si++;
    return FLOAT;
}

"char" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "char");
    strcpy(symbol_table[si][2], "CHAR");
    si++;
    return CHAR;
}

"void" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "void");
    strcpy(symbol_table[si][2], "VOID");
    si++;
    return VOID;
}

"main" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "main");
    strcpy(symbol_table[si][2], "MAIN");
    si++;
    return MAIN;
}



[1-9][0-9]* {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], yytext);
    strcpy(symbol_table[si][2], "NUM");
    si++;
    return NUM;
}
[0-9]*\.[0-9]+ {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], yytext);
    strcpy(symbol_table[si][2], "FLOATNUM");
    si++;
    return FLOATNUM;
}
"\'[a-zA-Z0-9]\'" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], yytext);
    strcpy(symbol_table[si][2], "CHARCONST");
    si++;
    return CHARCONST;
}



"(" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "(");
    strcpy(symbol_table[si][2], "LPAREN");
    si++;
    return LPAREN;
}

")" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], ")");
    strcpy(symbol_table[si][2], "RPAREN");
    si++;
    return RPAREN;
}

"{" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "{");
    strcpy(symbol_table[si][2], "LBRACE");
    si++;
    return LBRACE;
}

"}" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "}");
    strcpy(symbol_table[si][2], "RBRACE");
    si++;
    return RBRACE;
}

"[" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "[");
    strcpy(symbol_table[si][2], "LBRACKET");
    si++;
    return LBRACKET;
}

"]" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "]");
    strcpy(symbol_table[si][2], "RBRACKET");
    si++;
    return RBRACKET;
}

";" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], ";");
    strcpy(symbol_table[si][2], "SEMICOLON");
    si++;
    return SEMICOLON;
}

"," {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], ",");
    strcpy(symbol_table[si][2], "COMMA");
    si++;
    return COMMA;
}

"\"" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "\"");
    strcpy(symbol_table[si][2], "QUOTE");
    si++;
    return QUOTE;
}


\/\/[.^\n]*\n {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "yytext");
    strcpy(symbol_table[si][2], "SLCOMMENT");
    si++;
    return SLCOMMENT;
}



{space}"/*" BEGIN(MLC);
<MLC>"*/"{space} {
    BEGIN(INITIAL); 
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], yytext);
    strcpy(symbol_table[si][2], "MLCOMMENT");
    si++;
    return MLCOMMENT;}
<MLC>.|\n {}


"%c" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "%c");
    strcpy(symbol_table[si][2], "CHARFORMAT");
    si++;
    return CHARFORMAT;
}

"%d" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "%d");
    strcpy(symbol_table[si][2], "INTFORMAT");
    si++;
    return INTFORMAT;
}

"%f" {
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], "%f");
    strcpy(symbol_table[si][2], "FLOATFORMAT");
    si++;
    return FLOATFORMAT;
}



{ID} {
    
    sprintf(symbol_table[si][0], "%d", line);
    strcpy(symbol_table[si][1], yytext);
    strcpy(symbol_table[si][2], "ID");
    si++;
    return ID;
}


^{space}printf{space}\({space}\".*\"{space}(,{space}{ID}{space})*{space}\){space};{space} {
    num_vars = 0;
    num_format = 0;
    printf("%s\n",yytext);
    int i = 8;
    while(i<yyleng && yytext[i]!='"'){
        if(yytext[i]=='%'){
            printf("ghus gaye");
            if(yytext[i +1]=='c' || yytext[i+1]=='d' || yytext[i+1]=='f'){
            
                num_format++;
            }
            else{
                yyerror("Invalid printf statement");
            }
        }  
        i++;
    }
    printf("\nNUM FORMAT %d",num_format);
    i++;
    printf("%c\n",yytext[i]);
    // print the length of yytext
    printf("%d\n",yyleng);
     if(yytext[i]==','){
        printf("ghus gaye\n");
         while(i<yyleng-1 && yytext[i]!=')'){
            printf("while m ghus gaye\n");
             if(yytext[i]==','){
                 num_vars++;
             }
             i++;
         }
     }
    printf("\nNUM var %d",num_vars);

     if(yytext[i] != ')') {
        yyerror("Invalid printf statement");
     }
     if(num_vars!=num_format){
         
        yyerror("Invalid printf statement");
     }
    printf("Waleed");
    return PRINTF;
} 

^{space}scanf{space}\({space}\".*\"{space}(,{space}&{space}{ID}{space})*{space}\){space};{space} {
    num_vars = 0;
    num_format = 0;
    printf("%s\n",yytext);
    int i = 8;
    while(i<yyleng && yytext[i]!='"'){
        if(yytext[i]=='%'){
            printf("ghus gaye");
            if(yytext[i +1]=='c' || yytext[i+1]=='d' || yytext[i+1]=='f'){
                num_format++;
            }
            else{
                yyerror("Invalid scanf statement");
            }
        }  
        i++;
    }
    printf("\nNUM FORMAT %d",num_format);
    i++;
    printf("%c\n",yytext[i]);
    // print the length of yytext
    printf("%d\n",yyleng);
     if(yytext[i]==','){
        printf("ghus gaye\n");
         while(i<yyleng-1 && yytext[i]!=')'){
            printf("while m ghus gaye\n");
            if(yytext[i]==','){
                num_vars++;
            }
            i++;
         }
     }
    printf("\nNUM var %d",num_vars);

     if(yytext[i] != ')') {
        yyerror("Invalid scanf statement");
     }
     if(num_vars!=num_format){
         
        yyerror("Invalid scanf statement");
     }
    printf("Waleed");
    return SCANF;
}





\n {line++;return *yytext;}
%%

