%{
#include <cstdio>
#include <iostream>
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int yylineno;
extern "C" int yytext;

void yyerror(const char *s);
FILE* file;
char* fn;
int nerrors = 0;
%}
%union {
	int ival;
	char *sval;
}

%token <ival> INT_LIT
%token <sval> CLASS DEF IF ELIF ELSE WHILE EXTENDS RETURN STRING_LIT IDENT AND OR NOT ATMOST ATLEAST EQUALS UNKNOWN

%left '.'
%left AND OR NOT
%left '<' ATMOST '>' ATLEAST EQUALS
%left '+' '-'
%left '*' '/'

%define parse.error verbose
%%
program:
	class_section statement_section 	{ if (nerrors)	cout << "Finished parse with (" << nerrors << ") errors" << endl;
										else 			cout << "Finished parse with no errors" << endl; }
	;

class_section:
	%empty
	| classes
	;

classes:
	classes class
	| class
	;

class:
	class_sig class_body
	;

class_sig:
	CLASS IDENT formal_arg_section extends_opt
	| CLASS error extends_opt				{ nerrors++; }
	;

extends_opt:
	%empty
	| EXTENDS IDENT
	;

formal_arg_section:
	'(' ')'
	| '(' formal_args ')'
	| '(' error ')'
	;

formal_args:
	formal_args ',' formal_arg
	| formal_arg
	;

formal_arg: IDENT ':' IDENT

class_body: 
	'{' statement_section method_section '}'
	| '{' error '}'							{ nerrors++; }
	;

statement_section:
	%empty
	| statements
	;

statements:
	statements statement
	| statement
	;

statement: 
	IF r_exp statement_block elif_section else_section
	| WHILE r_exp statement_block
	| l_exp ':' IDENT '=' r_exp ';'
	| l_exp '='	r_exp ';'
	| r_exp ';'
	| RETURN r_exp ';'
	| RETURN ';'
	| error ';'								{ nerrors++; }
	;

l_exp:
	r_exp '.' IDENT
	| IDENT
	;

r_exp:
	INT_LIT
	| STRING_LIT
	| l_exp
	| r_exp '+' r_exp
	| r_exp '-' r_exp
	| r_exp '*' r_exp
	| r_exp '/' r_exp
	| r_exp EQUALS r_exp
	| r_exp ATMOST r_exp
	| r_exp '<' r_exp
	| r_exp ATLEAST r_exp
	| r_exp '>' r_exp
	| r_exp AND r_exp
	| r_exp OR r_exp
	| NOT r_exp
	| r_exp '.' IDENT actual_arg_section 
	| IDENT actual_arg_section
	| '(' r_exp ')'
	| '(' error ')'						{ nerrors++; }
	;

actual_arg_section:
	'(' ')'
	| '(' actual_args ')'
	| '(' error ')'						{ nerrors++; }
	;

actual_args:
	actual_args ',' r_exp
	| r_exp
	;

elif_section:
	%empty
	| elif_blocks
	;

elif_blocks:
	elif_blocks elif_block
	| elif_block
	;

elif_block:	ELIF r_exp statement_block

else_section:
	%empty
	| else_block
	;

else_block:	ELSE statement_block
	
method_section:
	%empty
	| methods
	;

methods:
	methods method
	| method 
	;

method: DEF IDENT formal_arg_section return_type statement_block

return_type:
	%empty
	| ':' IDENT
	;

statement_block: 
	'{' statement_section '}'
	| '{' error '}'						{ nerrors++; }
	;

%%
int main(int argc, char* argv[]) {
	if (argc > 1)
	{
		file = fopen(argv[1], "r");
		if (!file)
		{
			cerr << "Error opening file!" << endl;
			return -1;
		}
		fn = argv[1];
		yyin = file;
	}

	do {
		yyparse();
	} while (!feof(yyin));
}

void yyerror(const char *s) {
	//char* filename;
	//sprintf(filename, "%s", file);
	cerr << fn << ":" << yylineno << ": " << s << endl;
}