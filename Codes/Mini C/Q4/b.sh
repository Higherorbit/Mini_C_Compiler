yacc -d FINAL_TC.y
lex FINAL_TC.l
cc y.tab.c lex.yy.c -ll
./a.out input.txt
