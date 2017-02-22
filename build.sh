bison -d parser.y
flex scanner.l
g++ parser.tab.c lex.yy.c -lfl -std=c++11 -o quack
