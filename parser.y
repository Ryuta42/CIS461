%{
#include <iostream>
#include <cctype>
#include <vector>
#include <cstring>
#include "ast.h"

using namespace std;

extern "C" int yylex();
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
	NExpression* expr;
	NStatement* stmt;
	NClass* clas;
	int ival;
	string *sval;
}
%define parse.error verbose
%type <node> program class_section classes class_sig formal_arg_section formal_args formal_arg class_body extends
%type <node> statement_section statement_block statements actual_arg_section actual_args
%type <node> elif_section elif_blocks elif_block else_section else_block method_section methods method
%type <expr> r_exp l_exp
%type <stmt> statement
%type <clas> class
%type <ival> INT_LIT
%type <sval> IDENT STRING_LIT return_type
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
	{	$$ = new NClass($1->label, $1->ch.back()->label, yylineno);
		$$->addChild($1);
		$$->addChild($2);
		ast.addClass($$);
	}
	;

class_sig:
	CLASS IDENT formal_arg_section extends
	{	$$ = new Node(*$2, NCLASS_SIG, yylineno);
		$$->addChild($3);
		$$->addChild($4);
	}
  | CLASS error extends
	{	nerrors++;
	}
	;

extends:
	%empty
	{	$$ = new Node("Obj", "Obj", NEXTENDS, yylineno);
	}
  | EXTENDS IDENT
	{	$$ = new Node(*$2, *$2, NEXTENDS, yylineno);
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
	{	$$ = new Node(*$1, *$3, NFORMAL_ARG, yylineno);
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
	IF r_exp statement_block elif_section else_section
	{	$$ = new NStatement("IF statement", NSTIF, yylineno);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
	}
  | WHILE r_exp statement_block
	{	$$ = new NStatement("while loop", NSTWHILE, yylineno);
		$$->addChild($2);
		$$->addChild($3);
	}
  | l_exp ':' IDENT '=' r_exp ';'
	{	$$ = new NAssignment("typed assignment" + *$3, *$3, $1, $5, yylineno);
	}
  | l_exp '=' r_exp ';'
	{	$$ = new NAssignment("assignment", $1, $3, yylineno);
	}
  | r_exp ';'
	{	$$ = new NStatement($1->label, NSTEX, yylineno);
		$$->addChild($1);
	}
  | RETURN r_exp ';'
	{	$$ = new NStatement("return stmt " + $2->label, NSTRETURN, yylineno);
		$$->addChild($2);
	}
  | RETURN ';'
	{	$$ = new NStatement("return blank", NSTRETURN, yylineno);
	}
  | error ';'
	{	$$ = new NStatement("ERROR", NSTATEMENT, yylineno);
		nerrors++;
	}
	;

l_exp:
	r_exp '.' IDENT
	{	$$ = new NExpression(*$3, NLEXQ, yylineno);
		$$->addChild($1);
	}
  | IDENT
	{	$$ = new NExpression(*$1, NLEX, yylineno);
	}
	;

r_exp:
	INT_LIT
	{	$$ = new NInt($1, yylineno);
	}
  | STRING_LIT
	{	$$ = new NString(*$1, yylineno);
	}
  | l_exp
	{	$$ = $1;
	}
  | r_exp '+' r_exp
	{	$$ = new NExpression("Add", NEXADD, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '-' r_exp
	{	$$ = new NExpression("Subtract", NEXSUB, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '*' r_exp
	{	$$ = new NExpression("Multiply", NEXMUL, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '/' r_exp
	{	$$ = new NExpression("Divide", NEXDIV, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp EQUALS r_exp
	{	$$ = new NExpression("==", NEXEQ, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp ATMOST r_exp
	{	$$ = new NExpression("<=", NEXMOST, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '<' r_exp
	{	$$ = new NExpression("<", NEXLESS, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp ATLEAST r_exp
	{	$$ = new NExpression(">=", NEXLEAST, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp '>' r_exp
	{	$$ = new NExpression(">", NEXGREATER, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp AND r_exp
	{	$$ = new NExpression("AND", NEXAND, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | r_exp OR r_exp
	{	$$ = new NExpression("OR", NEXOR, yylineno);
		$$->addChild($1);
		$$->addChild($3);
	}
  | NOT r_exp
	{	$$ = new NExpression("NOT", NEXNOT, yylineno);
		$$->addChild($2);
	}
  | r_exp '.' IDENT actual_arg_section
	{	$$ = new NExpression(*$3, NEXMETH, yylineno);
		$$->addChild($1);
		$$->addChild($4);
	}
  | IDENT actual_arg_section
	{	$$ = new NExpression(*$1, *$1, NEXCLASS, yylineno);
		$$->addChild($2);
	}
  | '(' r_exp ')'
	{	$$ = new NExpression("REX", NEXPAR, yylineno);
		$$->addChild($2);
	}
  | '(' error ')'
	{ 	nerrors++;
		$$ = new NExpression("ERROR", NEXERR, yylineno);
	}
  | r_exp '.' IDENT error
  	{	cout << "!!" << endl;
		$$ = new NExpression("ERROR", NEXERR, yylineno);
  		nerrors++;
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
	actual_args ',' r_exp
	{	$$ = $1;
		$$->addChild($3);
	}
  | r_exp
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

elif_block:	ELIF '(' r_exp ')' statement_block
	{	$$ = new Node("ELIF", NELIF_BLOCK, yylineno);
		$$->addChild($3);
		$$->addChild($5);
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
	{	$$ = new Node(*$2, *$4, NMETHOD, yylineno);
		$$->addChild($3);
		$$->addChild($5);
	}
	;

return_type:
	%empty
	{	$$ = new string("Nothing");
	}
  | ':' IDENT
	{	$$ = $2;
	}
	;

%%
void yyerror(const char *s)
{	cerr << fn << ":" << yylineno << ": " << s << endl;
}
