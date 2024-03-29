%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int yylex();
void yyerror();

struct identifier {
    char *id_name;
    char *data_type;
    char *type;
    union {
        int i;
        float f;
        char c;
    } val;
    union {
        int *i;
        float *f;
        char *c;
    } arr;
    int arr_len;
    int arr_len2;
    char *plist;
} id_table[50];
int id_cnt = 0;


struct node { 
    struct node *left; 
    struct node *right; 
    char *token; 
};

struct node *head;
int is_char(char *tk);
int find_id(char *iden_name);
char *get_type(char *iden_name);
void add_id(char c, char *iden_name, char *value, char *d_type, int d1, int d2);
int lookup_i(char *iden_name, int idx1, int idx2);
float lookup_f(char *iden_name, int idx1, int idx2);
char lookup_c(char *iden_name, int idx1, int idx2);
void update_id(char *iden_name, char *value, int idx1, int idx2);
struct node* mknode(struct node *left, struct node *right, char *token);

%}

%union { 
    struct type1 { 
        char name[100]; 
        struct node* nd;
        int idc;
    } nd_obj;
    struct type2 { 
        char name[100]; 
        struct node* nd;
        char type[6];
    } nd_obj2;
}

%token <nd_obj> CHARFORMAT INTFORMAT FLOATFORMAT 
%token <nd_obj> STRING
%token <nd_obj> INT FLOAT CHAR VOID IF ELSE WHILE FOR SWITCH CASE BREAK DEFAULT CONTINUE RETURN PRINTF COLON
%token <nd_obj> ID ID1 ID2 NUM FLOATNUM CHARCONST FUNC
%token <nd_obj> LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

%right ASSIGNMENT
%left LAND LOR 
%left NOTEQ EQUALS
%left GTE LTE LT GT
%left PLUS MINUS
%left MULT DIV MOD 
%right LNOT 

%type <nd_obj> start statement TYPE PARAMETER_LIST STATEMENT_LIST STATEMENT PRINT_STATEMENTS RETURN_STATEMENTS ULTIMATE_LIST FOR_STATEMENT DECLARATION IF_STATEMENT SWITCH_STMT MATCHED UNMATCHED WHILE_STATEMENT ASGNSTMT ASGNSTMT_LIST CASES STATEMENT_BLOCK

%type <nd_obj2> FUNCTION EXPRESSION TREEM TREEM2 FUNCTION_CALLSTMTS ALLID CONST
%%

start : statement {$$.nd = mknode($1.nd, NULL, "start"); head = $$.nd;}
    ;
statement : FUNCTION statement {$$.nd = mknode($1.nd, $2.nd, "statement");}
| FUNCTION {$$.nd = mknode($1.nd, NULL, "statement");}
    ;
TYPE: INT {$$.nd = mknode(NULL, NULL, $1.name);}
| FLOAT {$$.nd = mknode(NULL, NULL, $1.name);}
| CHAR {$$.nd = mknode(NULL, NULL, $1.name);}
| VOID {$$.nd = mknode(NULL, NULL, $1.name);}
    ;
FUNCTION: TYPE FUNC RPAREN LBRACE STATEMENT_LIST RBRACE { 
    char *fname = strdup($2.name); 
    fname[strlen(fname) - 1] = '\0';
    printf("Should call add_id here for %s\n", fname);
    id_cnt = $5.idc;
    add_id('F', fname, "", $1.name, 0, 0);
    strcpy($$.type, $1.name);
    $$.nd = mknode($1.nd, $5.nd, fname);
}
| TYPE FUNC PARAMETER_LIST RPAREN LBRACE STATEMENT_LIST RBRACE {
    char *fname = strdup($2.name); 
    fname[strlen(fname) - 1] = '\0';
    char *plist = $3.name;
    id_cnt = $3.idc;
    add_id('F', fname, plist, $1.name, 0, 0);
    strcpy($$.type, $1.name);
    $$.nd = mknode($1.nd, mknode($3.nd, $5.nd, fname), fname);
}
    ;
PARAMETER_LIST: PARAMETER_LIST COMMA TYPE ID {
    $$.idc = $1.idc;
    printf("%s added to id_table\n", $4.name);
    add_id('V', $4.name, "0", $3.name, 0, 0);
    char *pname = malloc(strlen($1.name) + strlen($3.name) + 1);
    strcpy(pname, $1.name);
    strcat(pname, $3.name);
    strcpy($$.name, pname);
    $$.nd = mknode(NULL, NULL, "plist");
} | TYPE ID  {
    $$.idc = id_cnt;
    printf("%s added to id_table\n", $2.name);
    add_id('V', $2.name, "0", $1.name, 0, 0);
    strcpy($$.name, $1.name);
}
    ;
STATEMENT_LIST: STATEMENT STATEMENT_LIST {$$.idc = $1.idc; $$.nd = mknode($1.nd, $2.nd, "statement list");}
| STATEMENT {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "statement list");}
| STATEMENT_BLOCK STATEMENT_LIST {$$.idc = $1.idc; $$.nd = mknode($1.nd, $2.nd, "statement list");}
| STATEMENT_BLOCK {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "statement list");}
;

STATEMENT_BLOCK: LBRACE STATEMENT_LIST RBRACE {id_cnt = $2.idc; $$.nd = mknode($2.nd, NULL, "statement block");}

STATEMENT : PRINT_STATEMENTS {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "statement");}
| RETURN_STATEMENTS {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "statement");}
| CONTINUE SEMICOLON {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "statement");}
| BREAK SEMICOLON {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "statement");}
| IF_STATEMENT {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "statement");}
| SWITCH_STMT {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "statement");}
| WHILE_STATEMENT {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "statement");}
| FOR_STATEMENT {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "statement");}
| EXPRESSION SEMICOLON {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "statement");}
| ASGNSTMT SEMICOLON {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "statement");}
| DECLARATION SEMICOLON {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "statement");}
| SEMICOLON {$$.idc = id_cnt; $$.nd = mknode(NULL, NULL, ";");}
    ;
 
PRINT_STATEMENTS : PRINTF STRING RPAREN SEMICOLON {$$.nd = mknode($2.nd, NULL, "printf");}
| PRINTF STRING COMMA ULTIMATE_LIST RPAREN SEMICOLON {$$.nd = mknode($2.nd, $4.nd, "printf");}
;
 
 
RETURN_STATEMENTS: RETURN ALLID SEMICOLON {$$.nd=mknode($2.nd,NULL,"return");}
| RETURN SEMICOLON {$$.nd=mknode(NULL,NULL,"return");}
| RETURN CONST SEMICOLON {$$.nd=mknode($2.nd,NULL,"return");}
    ;
 
CONST: NUM {$$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type, "int");}
| FLOATNUM {$$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type,"float");}
| CHARCONST {$$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type,"char");}
    ;
 
ULTIMATE_LIST: ALLID COMMA ULTIMATE_LIST {
    strcpy($$.name, get_type($1.name));
    strcat($$.name, $3.name);
    $$.nd = mknode($1.nd, $3.nd, "params");
}
| CONST COMMA ULTIMATE_LIST {
    strcpy($$.name, $1.type);
    strcat($$.name, $3.name);
    $$.nd = mknode($1.nd, $3.nd, "params");
}
| ALLID {
    strcpy($$.name, get_type($1.name));
    $$.nd = mknode($1.nd, NULL, "params");
}
| CONST {
    strcpy($$.name, $1.type);
    $$.nd = mknode($1.nd, NULL, "params");
}
    ;
 
FOR_STATEMENT : FOR DECLARATION SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE {
    $$.idc = $9.idc - 1;
    $$.nd = mknode($2.nd, mknode($4.nd, mknode($6.nd, $9.nd, "for3"), "for2"), "for1");}
|FOR ASGNSTMT SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE {
    $$.idc = $9.idc;
    $$.nd = mknode($2.nd, mknode($4.nd, mknode($6.nd, $9.nd, "for3"), "for2"), "for1");}
|FOR SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE {
    $$.idc = $9.idc;
    $$.nd = mknode(NULL, mknode($3.nd, mknode($5.nd, $8.nd, "for3"), "for2"), "for1");}
;

DECLARATION: TYPE ID ASSIGNMENT EXPRESSION {
    printf("Declaration of %s\n", $2.name);
    if (is_char($1.name) != is_char($4.type)) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", $4.type, $1.name);
        exit(1);
    }
    $$.idc = id_cnt;
    add_id('V', $2.name, "0", $1.name, 0, 0);
    $$.nd = mknode($1.nd, mknode($2.nd, $4.nd, "id=exp"), "decl");
}
| TYPE ALLID {
    strcpy($2.type, $1.name);
    $$.idc = id_cnt;
    char *id_name = strdup($2.nd->token);
    if (id_name[strlen(id_name) - 1] == ']') {
        int d1 = 1, d2 = 0;
        char *id_nodim = malloc(strlen(id_name) * sizeof(char));
        for (int i = 0; ;i++) {
            id_nodim[i] = id_name[i];
            if (id_name[i] == '[') {
                id_nodim[i] = '\0';
                for (int j = i + 1; j < strlen(id_name); ++j) {
                    if (id_name[j] == '[') {
                        d2 = 1;
                        break;
                    }
                }
                break;
            }
        }
        add_id('A', id_nodim, "0", $1.name, d1, d2);
    } else
        add_id('V', $2.name, "0", $1.name, 0, 0);
    $$.nd = mknode($1.nd, $2.nd, "decl");
}
    ;
 
IF_STATEMENT : MATCHED {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "if");}
| UNMATCHED {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "if");}
    ;
MATCHED: IF EXPRESSION RPAREN STATEMENT_BLOCK {$$.idc = $4.idc; $$.nd = mknode($2.nd, $4.nd, "matched_if");}
    ;
UNMATCHED : IF EXPRESSION RPAREN STATEMENT_BLOCK ELSE STATEMENT_BLOCK {$$.idc = $4.idc; $$.nd = mknode(mknode($2.nd, $4.nd, "if_then"), $6.nd, "unmatched_if");}
    ;
 
WHILE_STATEMENT : WHILE EXPRESSION RPAREN STATEMENT_BLOCK {$$.idc = $4.idc; $$.nd = mknode($2.nd, $4.nd, "while");}
    ;
 
ASGNSTMT : ALLID ASSIGNMENT EXPRESSION ASGNSTMT_LIST {
    char *id_type = get_type($1.name);
    if (is_char(id_type) != is_char($3.type)) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", $3.type, id_type);
        exit(1);
    }
    $$.nd = mknode(mknode($1.nd, $3.nd, "id=exp"), $4.nd, "assn_st");}
    ;
ASGNSTMT_LIST: COMMA ALLID ASSIGNMENT EXPRESSION ASGNSTMT_LIST{
    char *id_type = get_type($2.name);
    if (is_char(id_type) != is_char($4.type)) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", $4.type, id_type);
        exit(1);
    }
    $$.nd = mknode(mknode($2.nd, $4.nd, "id=exp"), $5.nd, "assn_st");
}
    | {$$.nd=NULL;}
    ;
 
EXPRESSION: EXPRESSION Comperator TREEM {
    strcpy($$.type, $3.type);
    $$.nd=mknode($1.nd,$3.nd,"other_exp1");
}
| TREEM {
    strcpy($$.type, $1.type);
    // printf("Matched EXPRESSION: TREEM for %s\n", $1.name);
    $$.nd = mknode($1.nd, NULL, "other_exp1");
}
;
 
TREEM : TREEM PLUS TREEM2 {
    if (is_char($1.type) != 0 || is_char($3.type) != 0) {
        printf("Incompatible types: trying to add char\n");
        exit(1);
    }
    strcpy($$.type, "float");
    $$.nd = mknode($1.nd, $3.nd, "+");
}
| TREEM MINUS TREEM2 {
    if (is_char($1.type) != 0 || is_char($3.type) != 0) {
        printf("Incompatible types: trying to subtract char\n");
        exit(1);
    }
    strcpy($$.type, "float");
    $$.nd = mknode($1.nd, $3.nd, "-");
}
| TREEM MULT TREEM2 {
    if (is_char($1.type) != 0 || is_char($3.type) != 0) {
        printf("Incompatible types: trying to multiply char\n");
        exit(1);
    }
    strcpy($$.type, "float");
    $$.nd = mknode($1.nd, $3.nd, "*"); 
}
| TREEM DIV TREEM2 {
    if (is_char($1.type) != 0 || is_char($3.type) != 0) {
        printf("Incompatible types: trying to divide char\n");
        exit(1);
    }
    strcpy($$.type, "float");
    $$.nd = mknode($1.nd, $3.nd, "/"); 
}
| TREEM MOD TREEM2 {
    if (is_char($1.type) != 0 || is_char($3.type) != 0) {
        printf("Incompatible types: trying to divide char\n");
        exit(1);
    }
    strcpy($$.type, "float");
    $$.nd = mknode($1.nd, $3.nd, "%"); 
}
| TREEM2 {
    strcpy($$.type, $1.type);
    $$.nd = mknode($1.nd, NULL, "other_exp2");
}
    ;
 
TREEM2: ALLID {
    if (!find_id($1.name)) {
        printf("Error: Undeclared Variable %s\n", $1.name);
        exit(1);
    }
    strcpy($$.type, get_type($1.name));
    $$.nd = mknode($1.nd,NULL,"base_exp");
}
| CONST{
    strcpy($$.type,$1.type);
    $$.nd = mknode($1.nd, NULL, "base_exp");
}
| LPAREN EXPRESSION RPAREN {
    strcpy($$.type,$2.type);
    $$.nd = mknode($2.nd, NULL, "base_exp");   
}
| FUNCTION_CALLSTMTS {
    strcpy($$.type, $1.type);
    $$.nd = mknode($1.nd, NULL, "base_exp");   
}
    ;

FUNCTION_CALLSTMTS: FUNC RPAREN {
    char *fname = strdup($1.name); 
    fname[strlen(fname) - 1] = '\0';
    if (!find_id(fname)) {
        printf("Error: Undeclared Function Call %s\n", fname);
        exit(1);
    }
    strcpy($$.type, get_type(fname));
    char *fcname = malloc(strlen(fname) + 6);
    strcpy(fcname, fname);
    strcat(fcname, "_call");
    $$.nd = mknode(NULL, NULL, fcname);
}
| FUNC ULTIMATE_LIST RPAREN {
    char *fname = strdup($1.name); 
    fname[strlen(fname) - 1] = '\0';
    if (!find_id(fname)) {
        printf("Error: Undeclared Function Call %s\n", fname);
        exit(1);
    }
    strcpy($$.type, get_type(fname));
    char *fcname = malloc(strlen(fname) + 6);
    strcpy(fcname, fname);
    strcat(fcname, "_call");
    $$.nd = mknode(NULL, NULL, fcname);
}
;

ALLID: ID { strcpy($$.name, $1.name); $$.nd = mknode($1.nd, NULL, $1.name);}
| ID1 {
    char *id_nodim = malloc(strlen($1.name) * sizeof(char));
    for (int i = 0; ;i++) {
        id_nodim[i] = $1.name[i];
        if ($1.name[i] == '[') {
            id_nodim[i] = '\0';
            break;
        }
    }
    strcpy($$.name, id_nodim);
    $$.nd = mknode($1.nd, NULL, $1.name);
}
| ID2 {
    char *id_nodim = malloc(strlen($1.name) * sizeof(char));
    for (int i = 0; ;i++) {
        id_nodim[i] = $1.name[i];
        if ($1.name[i] == '[') {
            id_nodim[i] = '\0';
            break;
        }
    }
    strcpy($$.name, id_nodim);
    $$.nd = mknode($1.nd, NULL, $1.name);
}
;

Comperator: NOTEQ |LT |GT |LTE |GTE |LAND |LOR |EQUALS |LNOT 
    ;

CASES: CASE NUM COLON STATEMENT_LIST CASES {$$.nd = mknode(mknode($2.nd, $4.nd, "case"), $5.nd, "cases");}
| DEFAULT COLON STATEMENT_LIST {$$.nd = mknode($1.nd, $3.nd, "def_case");} 
| {$$.nd = NULL;}
;

SWITCH_STMT: SWITCH ID RPAREN LBRACE CASES RBRACE {$$.nd = mknode($2.nd, $5.nd, "switch");}
;

%%
void main()
{

    printf("\nOUTPUT:\n ");
    freopen("input.txt", "r", stdin);
    yyparse();
    printf("Valid Input\n");
    /* printf("Symbol table \n %s %s %s",symbol_table[0][0],symbol_table[0][1],symbol_table[0][2])  ; */
}
void yyerror()
{
    printf("Syntax Error:\n");
    exit(0);
}

int is_char(char *tk)
{
    return strcmp(tk, "char") == 0;
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

char *get_type(char *iden_name)
{
    if (!find_id(iden_name)) {
        assert(0 && "Finding type of identifier not in table\n");
    }
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            return id_table[i].data_type;
        }
    }
    return NULL;
}
void add_id(char c, char *iden_name, char *value, char *d_type, int d1, int d2)
{
    /* printf("add_id has been called!!!!!!!!!!!!!!"); */
    if (!find_id(iden_name))
    {
        id_table[id_cnt].id_name = strdup(iden_name);
        id_table[id_cnt].data_type = strdup(d_type);
        if (c == 'F')
        {
            id_table[id_cnt].type = strdup("Function");
            id_table[id_cnt].plist = strdup(value);
        }
        else if (c == 'V')
        {
            id_table[id_cnt].type = strdup("Variable");
            if (strcmp(d_type, "int") == 0)
                id_table[id_cnt].val.i = atoi(value);
            else if (strcmp(d_type, "float") == 0)
                id_table[id_cnt].val.f = atof(value);
            else if (strcmp(d_type, "char") == 0)
                id_table[id_cnt].val.c = value[0];
            else
                assert(0 && "Invalid d_type for add_id, variable\n");
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
                    id_table[id_cnt].arr.i = malloc(d1 * sizeof(int));
                else if (strcmp(d_type, "float") == 0)
                    id_table[id_cnt].arr.f = malloc(d1 * sizeof(float));
                else if (strcmp(d_type, "char") == 0)
                    id_table[id_cnt].arr.c = malloc(d1 * sizeof(char));
                else
                    assert(0 && "Invalid d_type for add_id, 1d array\n");
            }
            else
            {
                id_table[id_cnt].type = strdup("Array2D");
                if (strcmp(d_type, "int") == 0)
                    id_table[id_cnt].arr.i = malloc(d1 * d2 * sizeof(int));
                else if (strcmp(d_type, "float") == 0)
                    id_table[id_cnt].arr.f = malloc(d1 * d2 * sizeof(float));
                else if (strcmp(d_type, "char") == 0)
                    id_table[id_cnt].arr.c = malloc(d1 * d2 * sizeof(char));
                else
                    assert(0 && "Invalid d_type for add_id, 2d array\n");
            }
        }
        else
        {
            assert(0 && "Invalid c for add_id\n");
        }
        /* printf("Declared variable: %s with data type: %s and value: ", id_table[id_cnt].id_name, id_table[id_cnt].data_type); */
        /* if (strcmp(d_type, "int") == 0)
            printf("%d\n", id_table[id_cnt].val.i);
        else if (strcmp(d_type, "float") == 0)
            printf("%f\n", id_table[id_cnt].val.f);
        else if (strcmp(d_type, "char") == 0)
            printf("%c\n", id_table[id_cnt].val.c); */
        id_cnt++;
    }
    else
    {
        printf("Error: Redeclaration of existing identifier %s\n", iden_name);
        exit(1);
    }
}

int lookup_i(char *iden_name, int idx1, int idx2)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val.i;
            else if (idx2 == -1)
                return id_table[i].arr.i[idx1];
            else
                return id_table[i].arr.i[idx1 * id_table[i].arr_len2 + idx2];
        }
    }
    printf("Error: Acessing undeclared identifier %s\n", iden_name);
    exit(1);
}

float lookup_f(char *iden_name, int idx1, int idx2)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val.f;
            else if (idx2 == -1)
                return id_table[i].arr.f[idx1];
            else
                return id_table[i].arr.f[idx1 * id_table[i].arr_len2 + idx2];
        }
    }
    printf("Error: Acessing undeclared identifier %s\n", iden_name);
    exit(1);
}

char lookup_c(char *iden_name, int idx1, int idx2)
{
    for (int i = id_cnt - 1; i >= 0; i--)
    {
        if (strcmp(id_table[i].id_name, iden_name) == 0)
        {
            if (idx1 == -1 && idx2 == -1)
                return id_table[i].val.c;
            else if (idx2 == -1)
                return id_table[i].arr.c[idx1];
            else
                return id_table[i].arr.c[idx1 * id_table[i].arr_len2 + idx2];
        }
    }
    printf("Error: Accessing undeclared identifier %s\n", iden_name);
    exit(1);
}
void update_id(char *iden_name, char *value, int idx1, int idx2)
{
    if (find_id(iden_name))
    {
        for (int i = id_cnt - 1; i >= 0; i--)
        {
            if (strcmp(id_table[i].id_name, iden_name) == 0)
            {
                if (idx1 == -1 && idx2 == -1)
                {
                    if (strcmp(id_table[i].data_type, "int") == 0)
                        id_table[i].val.i = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].val.f = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].val.c = value[0];
                    else
                        assert(0 && "Invalid d_type for update_id, variable\n");
                }
                else if (idx2 == -1)
                {
                    if (strcmp(id_table[i].data_type, "int") == 0)
                        id_table[i].arr.i[idx1] = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].arr.f[idx1] = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].arr.c[idx1] = value[0];
                    else
                        assert(0 && "Invalid d_type for update_id, array1d\n");
                }
                else
                {
                    if (strcmp(id_table[i].data_type, "int") == 0)
                        id_table[i].arr.i[idx1 * id_table[i].arr_len2 + idx2] = atoi(value);
                    else if (strcmp(id_table[i].data_type, "float") == 0)
                        id_table[i].arr.f[idx1 * id_table[i].arr_len2 + idx2] = atof(value);
                    else if (strcmp(id_table[i].data_type, "char") == 0)
                        id_table[i].arr.c[idx1 * id_table[i].arr_len2 + idx2] = value[0];
                    else
                        assert(0 && "Invalid d_type for update_id, array2d\n");
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

struct node* mknode(struct node *left, struct node *right, char *token) {
  struct node *newnode = (struct node*) malloc(sizeof(struct node));
  char *newstr = (char*) malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  return(newnode);
}