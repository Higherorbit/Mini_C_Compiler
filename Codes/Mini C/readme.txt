Name of group members:
Sai Panda [2020A7PS0080H]
Harshit Verma [2020A7PS0041H]
Rishi Poddar [2020A7PS1195H]
Luv Ghilothia [2020A7PS1700H]
Samandeep Singh [2020A7PS0065H]
Ishan Chhangani [2020A7PS0230H]

For running lex and yacc files, we need to use standard commands.
For example, if the name of the lex and yacc files are dummy.l and dummy.y,
we will use the following commands:

yacc -d dummy.y
lex dummy.l
cc y.tab.c lex.yy.c -ll
./a.out input.txt

Here input.txt is the file containing the inputs.
