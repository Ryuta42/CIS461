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
%type <node> program class_section classes class class_sig formal_arg_section formal_args formal_arg class_body
%type <node> statement_section statement_block statements statement l_exp r_exp actual_arg_section actual_args
%type <node> elif_section elif_blocks elif_block else_section else_block method_section methods method return_type
%type <ival> INT_LIT
%type <sval> extends IDENT STRING_LIT
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
	{	$$ = new Node("program", "program");
		$$->addChild($1);
		$$->addChild($2);

		ast.root = $$;
		ast.processClasses();
		//ast.printTree();
	}
	;

class_section:
	%empty
	{	$$ = new Node("EMPTY", "class section");
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
	{	$$ = new Node("classes", "classes");
	  	$$->addChild($1);
	}
	;

class:
	class_sig class_body
	{	$$ = new ClassNode($1->label, $1->type);
		$$->addChild($1);
		$$->addChild($2);
		ast.addClass($$);
	}
	;

class_sig:
	CLASS IDENT formal_arg_section extends
	{	$$ = new Node($2, $4);
		$$->addChild($3);
	}
  | CLASS error extends
  	{	nerrors++;
	}
	;

extends:
	%empty
	{	$$ = strdup("Obj");
	}
  | EXTENDS IDENT
	{	$$ = $2;
 	}
	;

formal_arg_section:
	'(' ')'
	{	$$ = new Node("EMPTY", "formal_arg_section");
	}
  | '(' formal_args ')'
 	{	$$ = new Node("formal_arg_section", "formal_arg_section");
  		$$->addChild($2);
	}
  | '(' error ')'
    { 	$$ = new Node("ERROR", "formal_arg_section");
		nerrors++;
	}
	;

formal_args:
	formal_args ',' formal_arg
	{	$$ = new Node("formal_args", "formal_args");
		$$->addChild($1);
		$$->addChild($3);
	}
  | formal_arg
  	{	$$ = new Node("formal_args", "formal_args");
		$$->addChild($1);
	}
	;

formal_arg: IDENT ':' IDENT
	{	$$ = new Node($1, $3);
	}
	;

class_body:
	'{' statement_section method_section '}'
	{	$$ = new Node("class_body", "class_body");
		$$->addChild($2);
		$$->addChild($3);
	}
  | '{' error '}'
    { 	$$ = new Node("ERROR", "class_body");
		nerrors++;
	}
	;

statement_section:
	%empty
	{	$$ = new Node("EMPTY", "statement_section");
	}
  | statements
  	{	$$ = $1;
	}
	;

statements:
	statements statement
	{	$$ = $1;
		$$->addChild($2);
	}
	| statement
	{	$$ = new Node("statements", "statements");
		$$->addChild($1);
	}
	;

statement:
	IF r_exp statement_block elif_section else_section
	{	$$ = new Node("IF statement", "statement");
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
	}
  | WHILE r_exp statement_block
	{	$$ = new Node("while loop", "statement");
		$$->addChild($2);
		$$->addChild($3);
	}
  | l_exp ':' IDENT '=' r_exp ';'
	{	$$ = new Node("typed assignment", "statement");
		$$->addChild($1);
		$$->addChild($5);
	}
  | l_exp '=' r_exp ';'
	{	$$ = new Node("assignment", "statement");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp ';'
	{	$$ = new Node("statement", "statement");
		$$->addChild($1);
	}
  | RETURN r_exp ';'
	{	$$ = new Node("RETURN", "statement");
		$$->addChild($2);
	}
  | RETURN ';'
	{	$$ = new Node("RETURN", "statement");
	}
  | error ';'
	{	$$ = new Node("ERROR", "statement");
		nerrors++;
	}
	;

l_exp:
	r_exp '.' IDENT
	{	$$ = new Node($3, "l_exp");
		$$->addChild($1);
	}
  | IDENT
	{	$$ = new Node($1, "l_exp");
	}
	;

r_exp:
	INT_LIT
	{	$$ = new IntNode($1, "r_exp (int_lit)");
	}
  | STRING_LIT
	{	$$ = new Node($1, "r_exp (String_lit)");
	}
  | l_exp
	{	$$ = new Node("L_EXP", "r_exp");
		$$->addChild($1);
	}
  | r_exp '+' r_exp
	{	$$ = new Node("Add", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '-' r_exp
	{	$$ = new Node("Subtract", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '*' r_exp
	{	$$ = new Node("Multiply", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '/' r_exp
	{	$$ = new Node("Divide", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp EQUALS r_exp
	{	$$ = new Node("==", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp ATMOST r_exp
	{	$$ = new Node("<=", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '<' r_exp
	{	$$ = new Node("<", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp ATLEAST r_exp
	{	$$ = new Node(">=", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '>' r_exp
	{	$$ = new Node(">", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp AND r_exp
	{	$$ = new Node("AND", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp OR r_exp
	{	$$ = new Node("OR", "r_exp");
		$$->addChild($1);
		$$->addChild($3);
	}
  | NOT r_exp
	{	$$ = new Node("NOT", "r_exp");
		$$->addChild($2);
	}
  | r_exp '.' IDENT actual_arg_section
	{	$$ = new Node("r_exp", "r_exp");
		$$->addChild($1);
		$$->addChild($4);
	}
  | IDENT actual_arg_section
	{	$$ = new Node("method call", "r_exp");
		$$->addChild($2);
	}
  | '(' r_exp ')'
	{	$$ = new Node("r_exp", "r_exp");
		$$->addChild($2);
	}
  | '(' error ')'
	{ 	nerrors++;
		$$ = new Node("ERROR", "r_exp");
	}
	;

actual_arg_section:
	'(' ')'
	{	$$ = new Node("EMPTY", "actual_arg_section");
	}
  | '(' actual_args ')'
	{	$$ = new Node("actual_arg_section", "actual_arg_section");
		$$->addChild($2);
	}
  | '(' error ')'
    { 	$$ = new Node("ERROR", "actual_arg_section");
		nerrors++;
	}
	;

actual_args:
	actual_args ',' r_exp
	{	$$ = $1;
		$$->addChild($3);
	}
  | r_exp
	{	$$ = $1;
	}
	;

elif_section:
	%empty
	{	$$ = new Node("EMPTY", "elif_section");
	}
  | elif_blocks
	{	$$ = new Node("elif_secion", "elif_section");
		$$->addChild($1);
	}
	;

elif_blocks:
	elif_blocks elif_block
	{	$$ = new Node("elif_blocks", "elif_blocks");
		$$->addChild($1);
		$$->addChild($2);
	}
  | elif_block
	{	$$ = new Node("elif_blocks", "elif_blocks");
		$$->addChild($1);
	}
	;

elif_block:	ELIF r_exp statement_block
	{	$$ = new Node("ELIF", "elif_block");
		$$->addChild($2);
		$$->addChild($3);
	}
	;

else_section:
	%empty
	{	$$ = new Node("EMPTY", "else_section");
	}
  | else_block
	{	$$ = new Node("else_section", "else_section");
		$$->addChild($1);
	}
	;

else_block:	ELSE statement_block
	{	$$ = new Node("ELSE", "else_block");
		$$->addChild($2);
	}
	;

method_section:
	%empty
	{	$$ = new Node("EMPTY", "method_section");
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
	{	$$ = new Node("methods", "methods");
		$$->addChild($1);
	}
	;

method: DEF IDENT formal_arg_section return_type statement_block
	{	$$ = new Node($2, "method");
	}
	;

return_type:
	%empty
	{	$$ = new Node("EMPTY", "return_type");
	}
  | ':' IDENT
	{	$$ = new Node($2, "return_type");
	}
	;

statement_block:
	'{' statement_section '}'
	{	$$ = new Node("statement_section", "statement_block");
		$$->addChild($2);
	}
  | '{' error '}'
    { 	$$ = new Node("ERROR", "statement_block");
		nerrors++;
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

	return 0;
}

void yyerror(const char *s)
{	cerr << fn << ":" << yylineno << ": " << s << endl;
}
