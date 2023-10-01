%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int yylex();
void yyerror();

struct node { 
    struct node *left; 
    struct node *right; 
    char *token;
    char *etoken;
};

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
    struct node *fnode;
} id_table[50];
int id_cnt = 0;

int simulate(struct node *root);

struct node *head;
void print_tree();
void print_id_table();
int is_char(char *tk);
int find_id(char *iden_name);
char *get_type(char *iden_name);
void add_id(char c, char *iden_name, char *value, char *d_type, int d1, int d2);
int lookup_i(char *iden_name, int idx1, int idx2);
float lookup_f(char *iden_name, int idx1, int idx2);
char lookup_c(char *iden_name, int idx1, int idx2);
void update_id(char *iden_name, char *value, int idx1, int idx2);
struct node* mknode(struct node *left, struct node *right, char *token);
struct node* mknode2(struct node *left, struct node *right, char *token, char*etoken);
void get_val(char *idconst, int *ival, float *fval, char *cval, int *dt);
int simulate_stmt_list(struct node *stmt_list);
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

%type <nd_obj> start FUNCTION_LIST TYPE PARAMETER_LIST STATEMENT_LIST STATEMENT PRINT_STATEMENTS RETURN_STATEMENTS ULTIMATE_LIST FOR_STATEMENT DECLARATION IF_STATEMENT SWITCH_STMT MATCHED UNMATCHED WHILE_STATEMENT ASGNSTMT ASGNSTMT_LIST CASES STATEMENT_BLOCK Comparator

%type <nd_obj2> FUNCTION EXPRESSION TREEM TREEM2 FUNCTION_CALLSTMTS ALLID CONST
%%

start : FUNCTION_LIST {$$.nd = mknode($1.nd, NULL, "start"); head = $$.nd;}
    ;
FUNCTION_LIST : FUNCTION FUNCTION_LIST {$$.nd = mknode($1.nd, $2.nd, "function_list");}
| FUNCTION {$$.nd = mknode($1.nd, NULL, "function_list");}
    ;
TYPE: INT {$$.nd = mknode(NULL, NULL, $1.name);}
| FLOAT {$$.nd = mknode(NULL, NULL, $1.name);}
| CHAR {$$.nd = mknode(NULL, NULL, $1.name);}
| VOID {$$.nd = mknode(NULL, NULL, $1.name);}
    ;
FUNCTION: TYPE FUNC RPAREN LBRACE STATEMENT_LIST RBRACE { 
    char *fname = strdup($2.name); 
    fname[strlen(fname) - 1] = '\0';
    // printf("Should call add_id here for %s\n", fname);
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
STATEMENT_LIST: STATEMENT STATEMENT_LIST {$$.idc = $1.idc; $$.nd = mknode($1.nd, $2.nd, "statement_list");}
| STATEMENT_BLOCK STATEMENT_LIST {$$.idc = $1.idc; $$.nd = mknode($1.nd, $2.nd, "statement_list");}
| STATEMENT {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "statement_list");}
| STATEMENT_BLOCK {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "statement_list");}
;

STATEMENT_BLOCK: LBRACE STATEMENT_LIST RBRACE {id_cnt = $2.idc; $$.nd = mknode($2.nd, NULL, "statement_block");}

STATEMENT : PRINT_STATEMENTS {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "print_statement");}
| RETURN_STATEMENTS {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "return_statement");}
| CONTINUE SEMICOLON {$$.idc = id_cnt; $$.nd = mknode(NULL, NULL, "continue_statement");}
| BREAK SEMICOLON {$$.idc = id_cnt; $$.nd = mknode(NULL, NULL, "break_statement");}
| IF_STATEMENT {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "if_statement");}
| SWITCH_STMT {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "switch_statement");}
| WHILE_STATEMENT {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "while_statement");}
| FOR_STATEMENT {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "for_statement");}
| EXPRESSION SEMICOLON {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "exp_statement");}
| ASGNSTMT SEMICOLON {$$.idc = id_cnt; $$.nd = mknode($1.nd, NULL, "ass_statement");}
| DECLARATION SEMICOLON {$$.idc = $1.idc; $$.nd = mknode($1.nd, NULL, "dec_statement");}
| SEMICOLON {$$.idc = id_cnt; $$.nd = mknode(NULL, NULL, ";");}
    ;
 
PRINT_STATEMENTS : PRINTF STRING RPAREN SEMICOLON {
    int leng = strlen($2.name);
    for (int i = 0; i + 1 < leng; ++i) {
        if ($2.name[i] == '%') {
            if ($2.name[i + 1] == 'd' || $2.name[i + 1] == 'f' || $2.name[i + 1] == 'c') {
                printf("Format specifier mismatch in printf\n");
                exit(1);
            }
            i++;
        }
    }
    $$.nd = mknode2($2.nd, NULL, "printf", $2.name);}
| PRINTF STRING COMMA ULTIMATE_LIST RPAREN SEMICOLON {
    // printf("Printf string: %s\n", $2.name);
    // printf("Ultimate list: %s\n", $4.name);
    char *mod_list = malloc(100 * sizeof(char));
    int leng = strlen($2.name);
    for (int i = 0; i + 1 < leng; ++i) {
        if ($2.name[i] == '%') {
            if ($2.name[i + 1] == 'd')
                strcat(mod_list, "int");
            else if ($2.name[i + 1] == 'f')
                strcat(mod_list, "float");
            else if ($2.name[i + 1] == 'c')
                strcat(mod_list, "char");
            i++;
        }
    }
    printf("mod_list:%s\n", mod_list);
    if (strcmp(mod_list, $4.name) != 0) {
        printf("Format specifier mismatch in printf\n");
        exit(1);
    }
    $$.nd = mknode2($2.nd, $4.nd, "printf", $2.name);}
;
 
 
RETURN_STATEMENTS: RETURN ALLID SEMICOLON {$$.nd=mknode2($2.nd,NULL,"return", $2.name);}
| RETURN SEMICOLON {$$.nd=mknode2(NULL,NULL,"return", "");}
| RETURN CONST SEMICOLON {$$.nd=mknode2($2.nd,NULL,"return", $2.name);}
    ;
 
CONST: NUM {$$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type, "int");}
| FLOATNUM {$$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type,"float");}
| CHARCONST {$$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type,"char");}
    ;
 
ULTIMATE_LIST: ALLID COMMA ULTIMATE_LIST {
    strcpy($$.name, get_type($1.name));
    strcat($$.name, $3.name);
    char *utk = malloc(100 * sizeof(char));
    strcpy(utk, $1.name);
    strcat(utk, ",");
    strcat(utk, $3.nd->etoken);
    $$.nd = mknode2($1.nd, $3.nd, "params", utk);
}
| CONST COMMA ULTIMATE_LIST {
    strcpy($$.name, $1.type);
    strcat($$.name, $3.name);
    char *utk = malloc(100 * sizeof(char));
    strcpy(utk, $1.name);
    strcat(utk, ",");
    strcat(utk, $3.nd->etoken);
    $$.nd = mknode2($1.nd, $3.nd, "params", utk);
}
| ALLID {
    strcpy($$.name, get_type($1.name));
    char *utk = malloc(100 * sizeof(char));
    strcpy(utk, $1.name);
    $$.nd = mknode2($1.nd, NULL, "id_param", utk);
}
| CONST {
    strcpy($$.name, $1.type);
    char *utk = malloc(100 * sizeof(char));
    strcpy(utk, $1.name);
    $$.nd = mknode2($1.nd, NULL, "const_param", utk);
}
    ;
 
FOR_STATEMENT : FOR DECLARATION SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE {
    $$.idc = $9.idc - 1;
    $$.nd = mknode($2.nd, mknode($4.nd, mknode($6.nd, $9.nd, "for3"), "for2"), "for1");}
|FOR ASGNSTMT SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE {
    $$.idc = $9.idc;
    $$.nd = mknode($2.nd, mknode($4.nd, mknode($6.nd, $9.nd, "for3"), "for2"), "for2");}
|FOR SEMICOLON EXPRESSION SEMICOLON ASGNSTMT RPAREN LBRACE STATEMENT_LIST RBRACE {
    $$.idc = $9.idc;
    $$.nd = mknode(NULL, mknode($3.nd, mknode($5.nd, $8.nd, "for3"), "for2"), "for3");}
;

DECLARATION: TYPE ID ASSIGNMENT EXPRESSION {
    printf("Declaration of %s\n", $2.name);
    if (is_char($1.name) != is_char($4.type)) {
        printf("Incompatible types: trying to assign %s to variable of type %s\n", $4.type, $1.name);
        exit(1);
    }
    $$.idc = id_cnt;

    add_id('V', $2.name, "0", $1.name, 0, 0);
    $2.nd = mknode(NULL, NULL, $2.name);
    $$.nd = mknode($1.nd, mknode($2.nd, $4.nd, "id=exp"), "decl_ass");
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
 
EXPRESSION: EXPRESSION Comparator TREEM {
    strcpy($$.type, $3.type);
    $$.nd = mknode($1.nd, $3.nd, $2.name);
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
    if (strcmp($1.type, "int") != 0 || strcmp($3.type, "int") != 0) {
        printf("Incompatible types: trying to find remainder of non-integer\n");
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
        print_id_table();
        printf("Error: Undeclared Variable %s\n", $1.name);
        exit(1);
    }
    strcpy($$.type, get_type($1.name));
    $$.nd = mknode2($1.nd,NULL,"allid_exp", $1.name);
}
| CONST{
    strcpy($$.type,$1.type);
    $$.nd = mknode2($1.nd, NULL, "const_exp", $1.name);
}
| LPAREN EXPRESSION RPAREN {
    strcpy($$.type,$2.type);
    $$.nd = mknode2($2.nd, NULL, "(exp)_exp", $1.name);   
}
| FUNCTION_CALLSTMTS {
    strcpy($$.type, $1.type);
    $$.nd = mknode2($1.nd, NULL, "funcall_exp", $1.name);   
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
    $$.nd = mknode($2.nd, NULL, fcname);
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

Comparator: NOTEQ {strcpy($$.name, "!=");}
|LT {strcpy($$.name, "<");}
|GT {strcpy($$.name, ">");}
|LTE {strcpy($$.name, "<=");}
|GTE {strcpy($$.name, ">=");}
|LAND {strcpy($$.name, "&&");}
|LOR {strcpy($$.name, "||");}
|EQUALS {strcpy($$.name,"==");}
|LNOT {strcpy($$.name,"!");}
    ;

CASES: CASE NUM COLON STATEMENT_LIST CASES {
    $2.nd = mknode(NULL, NULL, $2.name);
    $$.nd = mknode(mknode($2.nd, $4.nd, "case"), $5.nd, "cases");}
| DEFAULT COLON STATEMENT_LIST {$$.nd = mknode($1.nd, $3.nd, "def_case");} 
| {$$.nd = NULL;}
;

SWITCH_STMT: SWITCH ID RPAREN LBRACE CASES RBRACE {
    $2.nd = mknode(NULL, NULL, $2.name);
    $$.nd = mknode($2.nd, $5.nd, "switch");
}
;

%%
void main()
{

    printf("\nOUTPUT:\n ");
    freopen("input.txt", "r", stdin);
    yyparse();
    printf("Valid Input\n");
    print_tree();
    simulate(head);
    /* printf("Symbol table \n %s %s %s",symbol_table[0][0],symbol_table[0][1],symbol_table[0][2])  ; */
}
void yyerror()
{
    printf("Syntax Error:\n");
    exit(0);
}

void print_id_table()
{
    printf("id_table has %d entries:\n", id_cnt);
    for (int i = 0; i < id_cnt; ++i) 
        printf("%s, ", id_table[i].id_name);
    printf("\n");
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
        printf("Could not find identifier: %s in the id_table\n", iden_name);
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

struct node* mknode2(struct node *left, struct node *right, char *token, char *etk) {
  struct node *newnode = (struct node*) malloc(sizeof(struct node));
  char *newstr = (char*) malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  newnode->etoken = strdup(etk);
  return(newnode);
}

void print_tree2(FILE *fp, struct node *root) {
    if (!root) {
        fprintf(fp, "()");
        return;
    }
    fprintf(fp,"( %s ", root->token);
    print_tree2(fp, root->left);
    print_tree2(fp, root->right);
    fprintf(fp, ")");
}
void print_tree() {
    FILE *fp = fopen("tree.txt", "w");
    print_tree2(fp, head);
}


char *strip_indexing(char *with_index)
{
    char *res = strdup(with_index);
    int n = strlen(res);
    for (int i = 0; i < n; ++i)
    {
        if (res[i] == '[')
        {
            while (i < n)
            {
                res[i] = '\0';
                i++;
            }
        }
    }
    return res;
}

char *get_det(char *idname, int *d1, int *d2)
{
    *d1 = 0;
    *d2 = 0;
    for (int i = 0; i < id_cnt; ++i) {
        if (strcmp(id_table[i].id_name, idname) == 0)
        {
            *d1 = id_table[i].arr_len;
            *d2 = id_table[i].arr_len2;
            return id_table[i].data_type;
        }
    }
    assert(0 && "Tried looking for dimensions of id not in id_table");
}

void extract_dims(char *idconst, int *d1, int *d2, int dim1, int dim2, int j)
{
    if (dim1)
    {
        d1 = 0;
        char *d1_str = malloc(strlen(idconst) * sizeof(char));
        int idx = 0;
        j++;
        while (idconst[j] != ']')
        {
            d1_str[idx] = idconst[j];
            idx++, j++;
        }
        j++;
        d1_str[idx] = '\0';
        int tmp;
        get_val(d1_str, &d1, NULL, NULL, &tmp);
        if (tmp != 0)
        {
            printf("Error: Array index is not integer!\n");
            exit(1);
        }       
    }
    if (dim2)
    {
        d2 = 0;
        char *d2_str = malloc(strlen(idconst) * sizeof(char));
        int idx = 0;
        j++;
        while (idconst[j] != ']')
        {
            d2_str[idx] = idconst[j];
            idx++, j++;
        }
        j++;
        d2_str[idx] = '\0';
        int tmp;
        get_val(d2_str, &d2, NULL, NULL, &tmp);
        if (tmp != 0)
        {
            printf("Error: Array index is not integer!\n");
            exit(1);
        }
    }
}

void get_val(char *idconst, int *ival, float *fval, char *cval, int *dt)
{
    if (idconst[0] == '\'') {
        *cval = idconst[1];
        *dt = 3;
    } else if (idconst[0] >= 'a' && idconst[0] <= 'z') {
        char *idname = strip_indexing(idconst);
        int dim1, dim2;
        char *idtype = get_det(idname, &dim1, &dim2);
        int j = strlen(idname);
        int d1 = -1, d2 = -1;
        extract_dims(idconst, &d1, &d2, dim1, dim2, j);
        if (strcmp(idtype, "int") == 0)
        {
            *ival = lookup_i(idname, d1, d2);
            *dt = 1;
        }
        else if (strcmp(idtype, "float") == 0)
        {
            *fval = lookup_f(idname, d1, d2);
            *dt = 2;
        }
        else
        {
            *cval = lookup_c(idname, d1, d2);
            *dt = 3;
        }
    } else {
        int isf = 0;
        for (int i = 0; idconst[i] != '\0'; ++i)
            if (idconst[i] < '0' || idconst[i] > '9')
            {
                isf = 1;
                break;
            }
        if (isf > 0)
        {
            *fval = atof(idconst);
            *dt = 2;
        }
        else
        {
            *ival = atoi(idconst);
            *dt = 1;
        }
    }
}

int simulate_print(struct node *print_stmt)
{
    struct node *ult_list = print_stmt->right;
    if (!ult_list)
    {
        printf("%s", print_stmt->etoken);
        return 1;
    }
    // etoken : "The fox %d jumped %c.."
    // ult_list->etoken : "x,'c',a,10" => "x", "'c'", "a", "10"
    /* int ivals[10], dts[10];
    float fvals[10];
    char cvals[10]; */
    int *ivals = malloc(10 * sizeof(int));
    int *dts = malloc(10 * sizeof(int));
    float *fvals = malloc(10 * sizeof(float));
    char *cvals = malloc(10 * sizeof(char));
    int valc = 0;
    int r = strlen(ult_list->etoken);
    for(int i = 0; i < r; i++) {
        if(ult_list->etoken[i]==','){
            continue;
        } else {
            char to[80];
            int j;
            for(j = i; ult_list->etoken[j] != ','&&j<r ;j++){
                to[j-i] = ult_list->etoken[j];
            }
            to[j] = '\0';
            /* printf("Token from ult_list: %s\n", to); */
            i = j-1;
            get_val(to, &ivals[valc], &fvals[valc], &cvals[valc], &dts[valc]);
            valc++;
        }
    }
    char *form_str = print_stmt->etoken;
    int len = strlen(form_str);
    char res[len + 20];
    int ires = 0, idx_v = 0;
    for (int i = 1; i < len - 1; ++i, ++ires)
    {
        /* printf("i: %d, len: %d\n", i, len); */
        if (form_str[i] == '%' && i + 1 < len)
        {
            char buff[10];
            if (form_str[i + 1] == 'd')
            {
                sprintf(buff, "%d", ivals[idx_v]);
                /* printf("%s", buff); */
            }
            else if (form_str[i + 1] == 'f')
                sprintf(buff, "%f", fvals[idx_v]);
            else
                sprintf(buff, "%c", cvals[idx_v]);
            idx_v++;
            /* printf("Value of buff:%s\n", buff); */
            for (int j = 0; buff[j] != '\0'; ++j, ++ires)
            {
                res[ires] = buff[j];
                /* printf("j: %d, buff[j]: %c\n", j, buff[j]);
                printf("ires: %d, res[ires]: %c\n", ires, res[ires]); */
            }
            ires--;
            i++;
        }
        else
            res[ires] = form_str[i];
        /* printf("ires: %d, %c\n", ires, res[ires]); */
    }
    res[ires] = '\0';
    printf("%s", res);
    return 1;
}


float simulate_exp_f(struct node *expnode);

float simulate_treem2_f(struct node *treem2node)
{
    if (strcmp(treem2node->token, "allid_exp") == 0)
    {
        float val = 0, dt;
        get_val(treem2node->etoken, NULL, &val, NULL, &dt);
        return val;
    }
    else if (strcmp(treem2node->token, "const_exp") == 0)
    {
        float val = 0, dt;
        get_val(treem2node->etoken, NULL, &val, NULL, dt);
        return val;
    }
    else if (strcmp(treem2node->token, "(exp)_exp") == 0)
    {
        return simulate_exp_f(treem2node->left);
    }
}

float simulate_treem_f(struct node *treemnode)
{
    if (strcmp(treemnode->token, "other_exp2") == 0)
    {
        return simulate_treem2_f(expnode->left);
    }
    else
    {
        if (strcmp(expnode->token, "+") == 0)
            return simulate_exp_f(expnode->left) != simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, "-") == 0)
            return simulate_exp_f(expnode->left) < simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, "*") == 0)
            return simulate_exp_f(expnode->left) > simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, "/") == 0) {
            float den = simulate_treem_f(expnode->right);
            if (!den) {
                printf("Runtime error: Division by 0\n");
                exit(1);
            }
            return simulate_exp_f(expnode->left) <= den;
        }
    }
}

float simulate_exp_f(struct node *expnode)
{
    if (strcmp(expnode->token, "other_exp1") == 0)
    {
        return simulate_treem_f(expnode->left);
    }
    else
    {
        if (strcmp(expnode->token, "!=") == 0)
            return simulate_exp_f(expnode->left) != simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, "<") == 0)
            return simulate_exp_f(expnode->left) < simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, ">") == 0)
            return simulate_exp_f(expnode->left) > simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, "<=") == 0)
            return simulate_exp_f(expnode->left) <= simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, ">=") == 0)
            return simulate_exp_f(expnode->left) >= simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, "&&") == 0)
            return simulate_exp_f(expnode->left) && simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, "||") == 0)
            return simulate_exp_f(expnode->left) || simulate_treem_f(expnode->right);
        else if (strcmp(expnode->token, "==") == 0)
            return simulate_exp_f(expnode->left) == simulate_treem_f(expnode->right);
    }
}

int simulate_exp_i(struct node *expnode);

int simulate_treem2_i(struct node *treem2node)
{
    if (strcmp(treem2node->token, "allid_exp") == 0)
    {
        int val = 0, dt;
        get_val(treem2node->etoken, &val, NULL, NULL, &dt);
        return val;
    }
    else if (strcmp(treem2node->token, "const_exp") == 0)
    {
        int val = 0, dt;
        get_val(treem2node->etoken, &val, NULL, NULL, dt);
        return val;
    }
    else if (strcmp(treem2node->token, "(exp)_exp") == 0)
    {
        return simulate_exp_i(treem2node->left);
    }
}

int simulate_treem_i(struct node *treemnode)
{
    if (strcmp(treemnode->token, "other_exp2") == 0)
    {
        return simulate_treem2_i(treemnode->left);
    }
    else
    {
        if (strcmp(expnode->token, "+") == 0)
            return simulate_exp_i(expnode->left) != simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, "-") == 0)
            return simulate_exp_i(expnode->left) < simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, "*") == 0)
            return simulate_exp_i(expnode->left) > simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, "/") == 0) {
            int den = simulate_treem_i(expnode->right);
            if (!den) {
                printf("Runtime error: Division by 0\n");
                exit(1);
            }
            return simulate_exp_i(expnode->left) <= den;
        }
        else if (strcmp(expnode->token, "%") == 0) {
            int den = simulate_treem_i(expnode->right);
            if (!den) {
                printf("Runtime error: Division by 0\n");
                exit(1);
            }
            return simulate_exp_i(expnode->left) % den;
        }
    }
}
char simulate_exp_c(struct node *expnode)
{
    return 'a';
}
int simulate_exp_i(struct node *expnode)
{
    if (strcmp(expnode->token, "other_exp1") == 0)
    {
        return simulate_treem_i(expnode->left);
    }
    else
    {
        if (strcmp(expnode->token, "!=") == 0)
            return simulate_exp_i(expnode->left) != simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, "<") == 0)
            return simulate_exp_i(expnode->left) < simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, ">") == 0)
            return simulate_exp_i(expnode->left) > simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, "<=") == 0)
            return simulate_exp_i(expnode->left) <= simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, ">=") == 0)
            return simulate_exp_i(expnode->left) >= simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, "&&") == 0)
            return simulate_exp_i(expnode->left) && simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, "||") == 0)
            return simulate_exp_i(expnode->left) || simulate_treem_i(expnode->right);
        else if (strcmp(expnode->token, "==") == 0)
            return simulate_exp_i(expnode->left) == simulate_treem_i(expnode->right);
    }
}

int handle_assn(struct node *idexp)
{
    assert(strcmp(idexp->token, "id=exp") == 0);
    struct node *idnode = idexp->left;
    struct node *expnode = idexp->right;
    char *idname = idnode->token;
    char *id_noidx = strip_indexing(idname);

    int j = strlen(id_noidx);
    int dim1, dim2;
    char *type = get_det(id_noidx, &dim1, &dim2);
    int d1 = -1, d2 = -1;
    extract_dims(idname, &d1, &d2, dim1, dim2, j);
    int i = find_id(id_noidx) - 1;

    if (strcmp(get_type(id_noidx), "int") == 0)
    {
        int val = simulate_exp_i(expnode);
        if (d1 >= 0 && d2 >= 0)
            id_table[i].arr.i[d1 * dim2 + d1] = val;
        else if (d1 >= 0)
            id_table[i].arr.i[d1] = val;
        else
            id_table[i].val.i = val;
    }
    else if (strcmp(get_type(id_noidx), "float") == 0)
    {
        float val = simulate_exp_f(expnode);
        if (d1 >= 0 && d2 >= 0)
            id_table[i].arr.f[d1 * dim2 + d1] = val;
        else if (d1 >= 0)
            id_table[i].arr.f[d1] = val;
        else
            id_table[i].val.f = val;
    }
    else
    {
        char val = simulate_exp_c(expnode);
        if (d1 >= 0 && d2 >= 0)
            id_table[i].arr.c[d1 * dim2 + d1] = val;
        else if (d1 >= 0)
            id_table[i].arr.c[d1] = val;
        else
            id_table[i].val.c = val;
    }
    
}

int declare_arr(struct node *arrid)
{
    char *idname = arrid->token;
    char *id_noidx = strip_indexing(idname);
    if (strlen(idname) == strlen(id_noidx))
        return 1;
    int j = strlen(id_noidx);
    int dim1, dim2;
    char *type = get_det(id_noidx, &dim1, &dim2);
    int d1 = -1, d2 = -1;
    extract_dims(idname, &d1, &d2, dim1, dim2, j);
    int i = find_id(id_noidx) - 1;
    id_table[i].arr_len = d1;
    id_table[i].arr_len2 = d2;
    if (strcmp(type, "int") == 0)
    {
        if (d2 > 0)
            id_table[i].arr.i = malloc(d1 * d2 * sizeof(int));
        else
            id_table[i].arr.i = malloc(d1 * sizeof(int));
    }
    else if (strcmp(type, "float") == 0)
    {
        if (d2 > 0)
            id_table[i].arr.f = malloc(d1 * d2 * sizeof(float));
        else
            id_table[i].arr.f = malloc(d1 * sizeof(float));
    }
    else
    {
        if (d2 > 0)
            id_table[i].arr.c = malloc(d1 * d2 * sizeof(char));
        else
            id_table[i].arr.c = malloc(d1 * sizeof(char));
    }
}

int simulate_decl(struct node *decl)
{
    if (strcmp(decl->token, "decl_ass") == 0)
    {
        handle_assn(decl->right);
    }
    else
    {
        declare_arr(decl->right);
    }
    return 1;
}
int simulate_assn(struct node* n){    
    handle_assn(n->left);
    if(n->right!=NULL){
        struct node* r=n->right;
        simulate_assn(r);   
    }
    return 1;
}
int simulate_for(struct node*for_stmt){
    if(strcmp(for_stmt->token,"for1")==0){
        struct node* dec = for_stmt->left;
        for_stmt=for_stmt->right;
        struct node* ex=(for_stmt->left);
        for_stmt=for_stmt->right;
        for(simulate_decl(dec);simulate_exp_i(ex);simulate_assn(for_stmt->left)){
            simulate_stmt_list(for_stmt->right);
        }
    }
    else if(strcmp(for_stmt->token,"for2")==0){
        struct node* as=for_stmt->left;
        for_stmt=for_stmt->right;
        struct node* ex=(for_stmt->left);
        for_stmt=for_stmt->right;
        for(simulate_assn(as);simulate_exp_i(ex);simulate_assn(for_stmt->left)){
            simulate_stmt_list(for_stmt->right);
        }
    }
    else{
        for_stmt=for_stmt->right;
        struct node* ex=(for_stmt->left);
        for_stmt=for_stmt->right;
        for(;simulate_exp_i(ex);simulate_assn(for_stmt->left)){
            simulate_stmt_list(for_stmt->right);
        }
    }
    return 1;
}
int simulate_if(struct node *if_stmt)
{
    if_stmt = if_stmt->left;
    if (strcmp(if_stmt->token, "matched_if") == 0)
    {
        if (simulate_exp_i(if_stmt->left)){
            simulate_stmt_list((if_stmt->right)->left);
        }
    }
    else
    {
        struct node* tr=if_stmt->left;
        if(simulate_exp_i(tr->left)){
            simulate_stmt_list((tr->right)->left);
        }
        else{
            simulate_stmt_list((if_stmt->right)->left);            
        }
    }
}
int simulate_while(struct node* stmt){
    while(simulate_exp_i(stmt->left)){
        simulate_stmt_list((stmt->right)->left);
    }
    return 1;
}
int simulate_stmt(struct node *stmt)
{
    if (strcmp(stmt->token, "print_statement") == 0)
    {
        simulate_print(stmt->left);
        return 1;
    } else if (strcmp(stmt->token, "if_statment") == 0)
    {
        simulate_if(stmt->left);
        return 1;
    }
    else if(strcmp(stmt->token,"for_statement")==0){
        simulate_for(stmt->left);
        return 1;
    }
    else if(strcmp(stmt->token,"while_statement")){
        simulate_while(stmt->left);
    }
    else if(strcmp(stmt->token,";")){
        ;
        return 1;
    }
}

int simulate_stmt_list(struct node *stmt_list) 
{
    
    assert(strcmp(stmt_list->token, "statement_list") == 0);

    if (strcmp(stmt_list->left->token, "statement_block") == 0)
        simulate_stmt_list(stmt_list->left->left);
    else    // left of statement_list is statment
        simulate_stmt(stmt_list->left);
    
    if (stmt_list->right)
        simulate_stmt_list(stmt_list->right);
    return 1;
}

void update_fnode(char *fname, struct node *stmt_list)
{
    for (int i = 0; i < id_cnt; ++i)
    {
        if (strcmp(fname, id_table[i].id_name) == 0)
        {
            id_table[i].fnode = stmt_list;
            return;
        }
    }
    assert(0 && "Couldn't update fnode");
}

struct node *get_fnode(char *fname)
{
    for (int i = 0; i < id_cnt; ++i)
    {
        if (strcmp(fname, id_table[i].id_name) == 0)
        {
            return id_table[i].fnode;
        }
    }
    assert(0 && "Couldn't find fnode");
    return NULL;
}

int simulate_function_decl(struct node *func) 
{
    char *fname = func->token;
    char *type = func->left->token;
    struct node *stmt_list = func->right;
    /* printf("Entered fun decl of %s\n", fname); */
    if (strcmp(stmt_list->token, "statement_list") != 0)
        stmt_list = stmt_list->right;
    update_fnode(fname, stmt_list);
    /* printf("Updated fnode of %s\n", fname); */
    return 1;
}

int simulate(struct node *head)
{
    printf("Entered simulate, token:%s\n", head->token);
    if (!head) return 0;
    if (strcmp(head->token, "start") == 0) {
        head = head->left;  // head is now function_list
        simulate(head);
        return 1;
    } else if (strcmp(head->token, "function_list") == 0) {
        simulate_function_decl(head->left);
        if (head->right)
            simulate(head->right);
        else {
            char *fname = head->left->token;
            assert(strcmp(fname, "main") == 0);
            simulate_stmt_list(get_fnode(fname));
        }
        return 1;
    } 
}