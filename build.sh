bison -d parser.y
flex scanner.l
g++ parser.tab.c lex.yy.c ast.cpp -lfl -std=c++11 -g -o quack
