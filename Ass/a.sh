yacc -d q1.y
lex q1.l
cc y.tab.c lex.yy.c -ll
./a.out 
rm a.out