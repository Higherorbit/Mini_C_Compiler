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
LETTER [a-zA-Z]
DIGIT [0-9]

%%

[LETTER][LETTER|DIGIT]* return ID; 

"+" return PLUS;
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
"printf" return PRINTF;
"scanf" return SCANF;

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
"//" return SLCOMMENT;
"/*" return MLCOMMENTOPEN;
"*/" return MLCOMMENTCLOSE;
"%c" return CHARFORMAT;
"%d" return INTFORMAT;
"%f" return FLOATFORMAT;


"printf\(\"" {
    num_vars = 0;
    num_format = 0;
    yytext[0]=getchar();
    while(yytext[0]!='"'){
        if(yytext[0]=='%'){
            yytext[0]=getchar();
            if(yytext[0]=='c' || yytext[0]=='d' || yytext[0]=='f'){
                num_format++;
            }
            else if (yytext[0]=='"'){
                break;
            }
            else{
                yyerror("Invalid printf statement");
            }
        }
        else{

        }   
        yytext[0]=getchar();
    }
    if(getchar()==","){
        yytext[0]=getchar();
        while(yytext[0]!=")"){
            if(yytext[0]==","){
                num_vars++;
            }
            yytext[0]=getchar();
        }
        num_vars++;
    }
    else{
        ungetc(yytext[0],stdin);
    }
    
    if(num_vars!=num_format){
        yyerror("Invalid printf statement");
    }
    return PRINTF;
} 
"scanf\(\"" {
    num_vars = 0;
    num_format = 0;
    yytext[0]=getchar();
    while(yytext[0]!='"'){
        if(yytext[0]=='%'){
            yytext[0]=getchar();
            if(yytext[0]=='c' || yytext[0]=='d' || yytext[0]=='f'){
                num_format++;
            }
            else if (yytext[0]=='"'){
                break;
            }
            else{
                yyerror("Invalid printf statement");
            }
        }
        else{

        }   
        yytext[0]=getchar();
    }
    if(getchar()==","){
        yytext[0]=getchar();
        if(yytext[0]!='&'){
            yyerror("Invalid scanf statement");
        }
        yytext[0]=getchar();
        while(yytext[0]!=")"){
            if(yytext[0]==","){
                num_vars++;
            }
            yytext[0]=getchar();
        }
        num_vars++;
    }
    else{
        ungetc(yytext[0],stdin);
    }
    if(num_vars-1==num_format){
        yyerror("Invalid scanf statement");
    }
    return SCANF;
} 
\n return yytext;
%%
