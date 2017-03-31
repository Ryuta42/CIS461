/*	Compiler Project
 *	CIS 461 Winter 2017
 *  Miles Chew
 */
 
#include <iostream>
#include <fstream>
#include <string>

#include "scanner.tab.h"
#include "parser.tab.h"
#include "compiler.h"

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

	return 0;
}
