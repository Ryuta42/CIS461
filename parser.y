%{
#include <iostream>
#include <cctype>
#include <memory>
#include <vector>
#include <cstring>

#include "ast.h"

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int yylineno;
extern "C" int yytext;

FILE* file;
char* fn;
int nerrors = 0;
AST ast;

void yyerror(const char *s);

%}
%union {
	Node* node;
	int ival;
	char *sval;
}
%define parse.error verbose
%type <node> program class_section classes class class_sig formal_arg_section formal_args formal_arg class_body extends
%type <node> statement_section statement_block statements statement LEX REX actual_arg_section actual_args
%type <node> elif_section elif_blocks elif_block else_section else_block method_section methods method return_type
%type <ival> INT_LIT
%type <sval> IDENT STRING_LIT
%token INT_LIT
%token IDENT STRING_LIT
%token <sval> CLASS DEF IF ELIF ELSE WHILE EXTENDS RETURN AND OR NOT ATMOST ATLEAST EQUALS UNKNOWN

%left '.'
%left AND OR NOT
%left '<' ATMOST '>' ATLEAST EQUALS
%left '+' '-'
%left '*' '/'
%%
program:
	class_section statement_section
	{	$$ = new Node("program", NPROGRAM, yylineno);
		$$->addChild($1);
		$$->addChild($2);

		ast.root = $$;
	}
	;

class_section:
	%empty
	{	$$ = new Node("EMPTY", NCLASS_SEC, yylineno);
	}
  | classes
	{	$$ = $1;
	}
	;

classes:
	classes class
	{	$$ = $1;
		$$->addChild($2);
	}
  | class
	{	$$ = new Node("classes", NCLASS_SEC, yylineno);
		$$->addChild($1);
	}
	;

class:
	class_sig class_body
	{	$$ = new ClassNode($1->label, $1->ch.back()->label, yylineno);
		// do something with $1->type
		$$->addChild($1);
		$$->addChild($2);
		ast.addClass($$);
	}
	;

class_sig:
	CLASS IDENT formal_arg_section extends
	{	$$ = new Node($2, NCLASS_SIG, yylineno);
		$$->addChild($3);
		$$->addChild($4);
	}
  | CLASS error extends
	{	nerrors++;
	}
	;

extends:
	%empty
	{	$$ = new Node("Obj", NEXTENDS, yylineno);
	}
  | EXTENDS IDENT
	{	$$ = new Node($2, NEXTENDS, yylineno);
	}
	;

formal_arg_section:
	'(' ')'
	{	$$ = new Node("EMPTY", NFORMAL_ARG_SEC, yylineno);
	}
  | '(' formal_args ')'
	{	$$ = $2;
	}
  | '(' error ')'
	{ 	$$ = new Node("ERROR", NFORMAL_ARG_SEC, yylineno);
		nerrors++;
	}
	;

formal_args:
	formal_args ',' formal_arg
	{	$$ = $1;
		$$->addChild($3);
	}
  | formal_arg
	{	$$ = new Node("formal_args", NFORMAL_ARG_SEC, yylineno);
		$$->addChild($1);
	}
	;

formal_arg: IDENT ':' IDENT
	{	$$ = new TypedNode($1, $3, NFORMAL_ARG, yylineno);
	}
	;

class_body:
	'{' statement_section method_section '}'
	{	$$ = new Node("class_body", NCLASS_BODY, yylineno);
		$$->addChild($2);
		$$->addChild($3);
	}
  | '{' error '}'
	{ 	$$ = new Node("ERROR", NCLASS_BODY, yylineno);
		nerrors++;
	}
	;

statement_section:
	%empty
	{	$$ = new Node("EMPTY", NSTATEMENT_SEC, yylineno);
	}
  | statements
	{	$$=$1;
	}
	;

statement_block:
	'{' statement_section '}'
	{	$$ = new Node("statement_section", NSTATEMENT_BLOCK, yylineno);
		$$->addChild($2);
	}
  | '{' error '}'
	{ 	$$ = new Node("ERROR", NSTATEMENT_BLOCK, yylineno);
		nerrors++;
	}
	;

statements:
	statements statement
	{	$$ = $1;
		$$->addChild($2);
	}
	| statement
	{	$$ = new Node("statements", NSTATEMENT_SEC, yylineno);
		$$->addChild($1);
	}
	;

statement:
	IF REX statement_block elif_section else_section
	{	$$ = new Node("IF statement", NSTIF, yylineno);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
	}
  | WHILE REX statement_block
	{	$$ = new Node("while loop", NSTWHILE, yylineno);
		$$->addChild($2);
		$$->addChild($3);
	}
  | LEX ':' IDENT '=' REX ';'
	{	$$ = new Node($3, NSTASSIGN, yylineno);
		$$->addChild($1);
		$$->addChild($5);
	}
  | LEX '=' REX ';'
	{	$$ = new Node("assignment", NSTASSIGN, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX ';'
	{	$$ = new Node("statement", NSTATEMENT, yylineno);
		$$->addChild($1);
	}
  | RETURN REX ';'
	{	$$ = new Node("RETURN", NSTRETURN, yylineno);
		$$->addChild($2);
	}
  | RETURN ';'
	{	$$ = new Node("RETURN", NSTRETURN, yylineno);
	}
  | error ';'
	{	$$ = new Node("ERROR", NSTATEMENT, yylineno);
		nerrors++;
	}
	;

LEX:
	REX '.' IDENT
	{	$$ = new Node($3, NLEXQ, yylineno);
		$$->addChild($1);
	}
  | IDENT
	{	$$ = new Node($1, NLEX, yylineno);
	}
	;

REX:
	INT_LIT
	{	$$ = new IntNode($1, yylineno);
	}
  | STRING_LIT
	{	$$ = new Node($1, NREX, yylineno);
	}
  | LEX
	{	$$ = new Node("Left expression", NREX, yylineno);
		$$->addChild($1);
	}
  | REX '+' REX
	{	$$ = new Node("Add", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX '-' REX
	{	$$ = new Node("Subtract", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX '*' REX
	{	$$ = new Node("Multiply", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX '/' REX
	{	$$ = new Node("Divide", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX EQUALS REX
	{	$$ = new Node("==", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX ATMOST REX
	{	$$ = new Node("<=", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX '<' REX
	{	$$ = new Node("<", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX ATLEAST REX
	{	$$ = new Node(">=", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX '>' REX
	{	$$ = new Node(">", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX AND REX
	{	$$ = new Node("AND", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | REX OR REX
	{	$$ = new Node("OR", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | NOT REX
	{	$$ = new Node("NOT", NREX, yylineno);
		$$->addChild($2);
	}
  | REX '.' IDENT actual_arg_section
	{	$$ = new Node("method call", NREX, yylineno);
		$$->addChild($1);
		$$->addChild($4);
	}
  | IDENT actual_arg_section
	{	$$ = new Node($1, NREXCC, yylineno);
		$$->addChild($2);
	}
  | '(' REX ')'
	{	$$ = new Node("REX", NREX, yylineno);
		$$->addChild($2);
	}
  | '(' error ')'
	{ 	nerrors++;
		$$ = new Node("ERROR", NREX, yylineno);
	}
	;

actual_arg_section:
	'(' ')'
	{	$$ = new Node("EMPTY", NACTUAL_ARG_SEC, yylineno);
	}
  | '(' actual_args ')'
	{	$$ = $2;
	}
  | '(' error ')'
	{ 	$$ = new Node("ERROR", NACTUAL_ARG_SEC, yylineno);
		nerrors++;
	}
	;

actual_args:
	actual_args ',' REX
	{	$$ = $1;
		$$->addChild($3);
	}
  | REX
	{	$$ = new Node("actual_arg_section", NACTUAL_ARG_SEC, yylineno);
		$$->addChild($1);
	}
	;

elif_section:
	%empty
	{	$$ = new Node("EMPTY", NELIF, yylineno);
	}
  | elif_blocks
	{	$$ = new Node("elif_secion", NELIF, yylineno);
		$$->addChild($1);
	}
	;

elif_blocks:
	elif_blocks elif_block
	{	$$ = new Node("elif_blocks", NELIF_BLOCKS, yylineno);
		$$->addChild($1);
		$$->addChild($2);
	}
  | elif_block
	{	$$ = new Node("elif_blocks", NELIF_BLOCKS, yylineno);
		$$->addChild($1);
	}
	;

elif_block:	ELIF REX statement_block
	{	$$ = new Node("ELIF", NELIF_BLOCK, yylineno);
		$$->addChild($2);
		$$->addChild($3);
	}
	;

else_section:
	%empty
	{	$$ = new Node("EMPTY", NELSE, yylineno);
	}
  | else_block
	{	$$ = new Node("else_section", NELSE, yylineno);
		$$->addChild($1);
	}
	;

else_block:	ELSE statement_block
	{	$$ = new Node("ELSE", NELSE_BLOCK, yylineno);
		$$->addChild($2);
	}
	;

method_section:
	%empty
	{	$$ = new Node("EMPTY", NMETHOD_SEC, yylineno);
	}
  | methods
	{	$$ = $1;
	}
	;

methods:
	methods method
	{	$$ = $1;
		$$->addChild($2);
	}
  | method
	{	$$ = new Node("methods", NMETHOD_SEC, yylineno);
		$$->addChild($1);
	}
	;

method: DEF IDENT formal_arg_section return_type statement_block
	{	$$ = new Node($2, NMETHOD, yylineno);
	}
	;

return_type:
	%empty
	{	$$ = new Node("EMPTY", NRETURN_TYPE, yylineno);
	}
  | ':' IDENT
	{	$$ = new Node($2, NRETURN_TYPE, yylineno);
	}
	;

%%
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
	ast.process();

	return 0;
}

void yyerror(const char *s)
{	cerr << fn << ":" << yylineno << ": " << s << endl;
}
