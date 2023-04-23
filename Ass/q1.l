%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    /*
    Lexical Analysis
- For this phase, write a LEX program that brakes the
input program into tokens (identifiers, operators, numbers, keywords, punctuators).
A symbol table is created with the list of tokens obtained from the input ( no need to print
the symbol table ).
Further, report if any invalid printf and scanf statements are in the given program.
A valid printf statement has one of the following structure:
 printf (“text”) where text is a non-empty string of symbols in the language alphabet.
 printf (“text”, list _ of _ variables) where text is a non-empty string of symbols in
the language alphabet and list _ of _ variables is a nonempty sequence of variables
separated by a comma ( , ).
Further, the number of variables in list _ of _ variables is must be the same as the
number of %d , %c , and %f terms in text .
A valid scanf statement has one of the following structure:
 scanf (“text”) where text is a non-empty string of symbols in the language alphabet.
 scanf (“text”, list _ of _ variables) where text is a non-empty string of symbols in
the language alphabet and list _ of _ variables is a nonempty sequence of variables
separated by a comma ( , ) and each variable is preceded by & .
Further, the number of variables in list _ of _ variables is must be the same as the
number of %d , %c , and %f terms in text .
    */
    int num_vars = 0;
    int num_format = 0;
    
%}
ID [a-zA-Z][a-zA-Z0-9]*
space [ \t\n]*
%x MLC
%%
"+" {printf("plus mil gya");return PLUS;}
"-" return MINUS;
"*" return MULT;
"/" return DIV;
"%" return MOD;
"=" return EQUAL;
"==" return EQUALS;
"!=" return NOTEQ;
"<" return LT;
">" return GT;
"<=" return LTE;
">=" return GTE;
"&&" return LAND;
"||" return LOR;
"!" return LNOT;


"if" return IF;
"else" return ELSE;
"while" return WHILE;
"for" return FOR;
"switch" return SWITCH;
"case" return CASE;
"default" return DEFAULT;
"break" return BREAK;
"continue" return CONTINUE;
"return" return RETURN;
"int" return INT;
"float" return FLOAT;
"char" return CHAR;
"void" return VOID;
"main" return MAIN;

[1-9][0-9]* return NUM;
[0-9]*\.[0-9]+ return FLOATNUM;
"\'[a-zA-Z0-9]\'" return CHARCONST;

\( return LPAREN;
\) return RPAREN;
\{ return LBRACE;
\} return RBRACE;
\[ return LBRACKET;
\] return RBRACKET;
\; return SEMICOLON;
\, return COMMA;
\" return QUOTE;
\/\/[.^\n]*\n return SLCOMMENT;
\/\*.*\*\/ return MLCOMMENT;
"%c" return CHARFORMAT;
"%d" return INTFORMAT;
"%f" return FLOATFORMAT;

{ID} {printf("ID mil gya");return ID;}


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


\/\/.*\n {return SLCOMMENT;}


{space}"/*" BEGIN(MLC);
<MLC>"*/"{space} {BEGIN(INITIAL); printf("MLC working"); return MLCOMMENT;}
<MLC>.|\n {}


\n return *yytext;
%%
