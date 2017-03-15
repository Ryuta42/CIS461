#include <iostream>
#include <fstream>
#include <string>

#include "scanner.tab.h"
#include "parser.tab.h"
#include "ast.h"

using namespace std;

extern "C" FILE *yyin;

extern FILE* file;
extern char* fn;
extern int nerrors;
extern AST ast;

int main(int argc, char* argv[])
{	if (argc > 1)
	{	file = fopen(argv[1], "r");
		if (!file)
		{	cerr << "Error opening file!" << endl;
			return -1;
		}
		fn = argv[1];
		yyin = file;
	}
	do
	{	yyparse();
	} while (!feof(yyin));

	// Work with AST
	if (!ast.checkSyntax(nerrors))
		return -1;
	ast.process();

    ofstream out;
    int scope = 0;
    out.open("output.c");
    out << string(scope, '\t') << "#include <stdio.h>\n" << endl;
    out << string(scope, '\t') << "int main() {" << endl;
    scope++;
    out << string(scope, '\t') << "int i = 3;" << endl;
    out << string(scope, '\t') << "int j = 5;" << endl;
    out << string(scope, '\t') << "printf(\"Hello World! %d\\n\", i + j);" << endl;
    out << string(scope, '\t') << "return 0;" << endl;
    scope--;
    out << string(scope, '\t') << "}" << endl;
    out.close();

	return 0;
}

/*
if you call the method of a subtype, it should return a subtype of thre super's return
the parameters of a subtype must be as uper type of a super class parameters
*/
