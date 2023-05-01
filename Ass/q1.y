%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int yylex();
void yyerror();

struct identifier {
    char * id_name;
    char * data_type;
    char * type;
    int val_i;
    float val_f;
    char val_f;
    int *arr_i;
    float *arr_f;
    char *arr_c;
    int arr_len;
    int arr_len2;
    char* fvalue;
} id_table[50];
int id_cnt = 0;

%}
%left PLUS MINUS
%left MULT DIV MOD
%token ID ID1 ID2
%token EQUAL NOTEQ LT GT LTE GTE LAND LOR LNOT EQUALS
%token IF ELSE WHILE FOR SWITCH CASE BREAK DEFAULT CONTINUE RETURN 
%token INT FLOAT CHAR VOID MAIN 
%token PRINTF 
%token NUM FLOATNUM CHARCONST  CONST_SIGNED 
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA
%token SLCOMMENT MLCOMMENT
%token CHARFORMAT INTFORMAT FLOATFORMAT 
%token ARR TDARR ARR_EHAI
%token SPACE ASSIGNMENT
%token STRING


%left ASSIGN
%left LOR
%left LAND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD 
%left NOT
%%
start : statement
    ;
statement : FUNCTION statement | FUNCTION
    ;
TYPE: INT | FLOAT | CHAR | VOID
    ;
FUNCTION: TYPE ID LPAREN RPAREN LBRACE STATEMENT_LIST RBRACE  
    | TYPE ID LPAREN PARAMETER_LIST RPAREN LBRACE STATEMENT_LIST RBRACE
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
    ;

PRINT_STATEMENTS : PRINTF LPAREN STRING RPAREN SEMICOLON
    | PRINTF LPAREN STRING COMMA VARIABLE_LIST RPAREN SEMICOLON 
    ;


RETURN_STATEMENTS: RETURN ID SEMICOLON
    | RETURN SEMICOLON
    | RETURN CONST SEMICOLON
    ;

CONST: NUM | FLOATNUM | CHARCONST 
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

    ; 
ANOTHERCONST_LIST: LBRACE CONSTANT_LIST RBRACE
    | LBRACE CONSTANT_LIST RBRACE COMMA ANOTHERCONST_LIST
    ;
CONSTANT_LIST: INTEGER_WALI_LIST 
    | FLOAT_WALI_LIST
    | CHAR_WALI_LIST
    ;
INTEGER_WALI_LIST: INT COMMA INTEGER_WALI_LIST 
    | INT
    ;
FLOAT_WALI_LIST: FLOAT COMMA FLOAT_WALI_LIST
    | FLOAT 
    ;
CHAR_WALI_LIST: CHAR COMMA CHAR_WALI_LIST
    | CHAR 
    ;


FOR_STATEMENT : FOR LPAREN DECLARATION SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE
    |FOR LPAREN ASGNSTMT SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE
    |FOR LPAREN SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE
;
DECLARATION: TYPE ID ASSIGNMENT EXPRESSION DECLARATION_LIST | TYPE ID DECLARATION_LIST
    ;

DECLARATION_LIST: COMMA ID DECLARATION_LIST | COMMA ID ASSIGNMENT EXPRESSION DECLARATION_LIST 
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
    
    
    ;
ASGNSTMT_LIST: COMMA ID ASSIGNMENT EXPRESSION ASGNSTMT_LIST
    | 
    ;

EXPRESSION: EXPRESSION Comperator TREEM 
| TREEM 
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

Comperator: NOTEQ |LT |GT |LTE |GTE |LAND |LOR |LNOT |EQUALS
    ;


%%
void main()
{

    printf("\nOUTPUT:\n ");
    freopen("input.txt", "r", stdin);
    yyparse();
    /* printf("Symbol table \n %s %s %s",symbol_table[0][0],symbol_table[0][1],symbol_table[0][2])  ; */
}
void yyerror()
{
    printf("Invalid Expression:\n");
    exit(0);
}

int find_id(char *iden_name)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void add_id(char c, char *iden_name, char *value, char *d_type, int d1 = 0, int d2 = 0)
{
    if (!find_id(iden_name))
    {
        id_table[id_cnt].id_name = strdup(iden_name);
        id_table[id_cnt].data_type = strdup(d_type);
        if (c == 'F')
        {
            id_table[id_cnt].type = strdup("Function");
            id_table[id_cnt].value = strdup(value);
        }
        else if (c == 'V')
        {
            id_table[id_cnt].type = strdup("Variable");
            if (strcmp(d_type, "int") == 0)
                id_table[id_cnt].val_i = atoi(value);
            else if (strcmp(d_type, "float") == 0)
                id_table[id_cnt].val_i = atof(value);
            else if (strcmp(d_type, "char") == 0)
                id_table[id_cnt].val_c = value[0];
            else
                assert(0 and "Invalid d_type for add_id, variable\n");
        }
        else if (c == 'A')
        {
            if (!d1)
            {
                printf("Error: Array size cannot be 0");
                exit(1);
            }
            id_table[id_cnt].arr_len = d1;
            id_table[id_cnt].arr_len2 = d2;
            if (!d2)
            {
                id_table[id_cnt].type = strdup("Array1D");
                if (strcmp(d_type, "int") == 0)
                    id_table[id_cnt].arr_i = malloc(d1 * sizeof(int));
                else if (strcmp(d_type, "float") == 0)
                    id_table[id_cnt].arr_f = malloc(d1 * sizeof(float));
                else if (strcmp(d_type, "char") == 0)
                    id_table[id_cnt].arr_c = malloc(d1 * sizeof(char));
                else
                    assert(0 and "Invalid d_type for add_id, 1d array\n");
            }
            else
            {
                id_table[id_cnt].type = strdup("Array2D");
                if (strcmp(d_type, "int") == 0)
                    id_table[id_cnt].arr_i = malloc(d1 * d2 * sizeof(int));
                else if (strcmp(d_type, "float") == 0)
                    id_table[id_cnt].arr_f = malloc(d1 * d2 * sizeof(float));
                else if (strcmp(d_type, "char") == 0)
                    id_table[id_cnt].arr_c = malloc(d1 * d2 * sizeof(char));
                else
                    assert(0 and "Invalid d_type for add_id, 2d array\n");
            }
        }
        else
        {
            assert(0 and "Invalid c for add_id\n");
        }
        printf("Declared variable: %s with data type: %s and value: ", id_table[id_cnt].id_name, id_table[id_cnt].data_type);
        if (strcmp(d_type, "int") == 0)
            printf("%d\n", id_table[id_cnt].val_i);
        else if (strcmp(d_type, "float") == 0)
            printf("%f\n", id_table[id_cnt].val_f);
        else if (strcmp(d_type, "char") == 0)
            printf("%c\n", id_table[id_cnt].val_c);
        id_cnt++;
    }
    else
    {
        printf("Error: Redeclaration of existing identifier %s\n", iden_name);
        exit(1);
    }
}

int lookup(char *iden_name, int idx1 = -1, int idx2 = -1)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val_i;
            else if (idx2 == -1)
                return id_table[i].arr_i[idx1];
            else
                return id_table[i].arr_i[idx1 * d2 + idx2];
        }
    }
    printf("Error: Acessing undeclared identifier %s\n", iden_name);
    exit(1);
}

float lookup(char *iden_name, int idx1 = -1, int idx2 = -1)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val_f;
            else if (idx2 == -1)
                return id_table[i].arr_f[idx1];
            else
                return id_table[i].arr_f[idx1 * d2 + idx2];
        }
    }
    printf("Error: Acessing undeclared identifier %s\n", iden_name);
    exit(1);
}

char lookup(char *iden_name, int idx1 = -1, int idx2 = -1)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val_c;
            else if (idx2 == -1)
                return id_table[i].arr_c[idx1];
            else
                return id_table[i].arr_c[idx1 * d2 + idx2];
        }
    }
    printf("Error: Accessing undeclared identifier %s\n", iden_name);
    exit(1);
}

void update_id(char *iden_name, char *value, int idx1 = -1, int idx2 = -1)
{
    if (find_id(iden_name))
    {
        for (int i = id_cnt - 1; i >= 0; i--)
        {
            if (strcmp(id_table[i].id_name, iden_name) == 0)
            {
                if (idx1 == -1 && idx2 == -1)
                {
                    if (strcmp(id_table[i].d_type, "int") == 0)
                        id_table[i].val_i = atoi(value);
                    else if (strcmp(d_type, "float") == 0)
                        id_table[i].val_f = atof(value);
                    else if (strcmp(d_type, "char") == 0)
                        id_table[i].val_c = value[0];
                    else
                        assert(0 and "Invalid d_type for update_id, variable\n");
                }
                else if (idx2 == -1)
                {
                    if (strcmp(id_table[i].d_type, "int") == 0)
                        id_table[i].arr_i[idx1] = atoi(value);
                    else if (strcmp(d_type, "float") == 0)
                        id_table[i].arr_f[idx1] = atof(value);
                    else if (strcmp(d_type, "char") == 0)
                        id_table[i].arr_c[idx1] = value[0];
                    else
                        assert(0 and "Invalid d_type for update_id, array1d\n");
                }
                else
                {
                    if (strcmp(id_table[i].d_type, "int") == 0)
                        id_table[i].arr_i[idx1 * d2 + idx2] = atoi(value);
                    else if (strcmp(d_type, "float") == 0)
                        id_table[i].arr_f[idx1 * d2 + idx2] = atof(value);
                    else if (strcmp(d_type, "char") == 0)
                        id_table[i].arr_c[idx1 * d2 + idx2] = value[0];
                    else
                        assert(0 and "Invalid d_type for update_id, array2d\n");
                }
            }
        }
    }
    else
    {
        printf("Error: Assigning undeclared identifier %s\n", iden_name);
        exit(1);
    }
}
