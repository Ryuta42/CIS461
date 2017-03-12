%{
#include <iostream>
#include "ast.h"
#include "parser.tab.h"
#define YY_DECL extern "C" int yylex()

using namespace std;

%}
%x COMMENT
%option yylineno
%%
<INITIAL,COMMENT>\n 			{ }
[ \t]							{ }
\/\/.*\n						{ /* ignore comments */ }
\/\*							{ BEGIN(COMMENT); }
<COMMENT>\*\/					{ BEGIN(INITIAL); }
<COMMENT>.						{ }

class 							{ return CLASS; }
def 							{ return DEF; }
if 								{ return IF; }
elif 							{ return ELIF; }
else 							{ return ELSE; }
while 							{ return WHILE; }
extends 						{ return EXTENDS; }
return 							{ return RETURN; }
and 							{ return AND; }
or 								{ return OR; }
not 							{ return NOT; }

[=+\-*/(){}<>:;,.] 				{ return yylval.ival = yytext[0]; }
"<="							{ return ATMOST; }
">="							{ return ATLEAST; }
"=="							{ return EQUALS; }
[0-9]+ 							{ yylval.ival = atoi(yytext); return INT_LIT; }
[_a-zA-Z0-9]+					{ yylval.sval = new string(yytext, yyleng); return IDENT; }
\"\"\"(.|\n)*\"\"\"				{ yylval.sval = new string(yytext, yyleng); return STRING_LIT; cout << yylineno << yytext << endl; }
\"(\\[0bftnr\\]|[^"\n\\])*\"	{ yylval.sval = new string(yytext, yyleng); return STRING_LIT; cout << yylineno << yytext << endl; }
\"(\\.|[^"\n])*\"				{ yylval.sval = new string(yytext, yyleng); cout << yylineno << yytext << endl;
	cerr << yylineno << ": Illegal escape code; only \\\\, \\0, \\t, \\n, \\r, \\n are permitted (at '" << yytext << "')\"" << endl; return STRING_LIT; }
\"(\\.|[^"])*\n					{ yylval.sval = new string(yytext, yyleng); cout << yytext << endl;
	cerr << yylineno << ": Newline before string terminated; single-quoted strings must be entirely on one line (at '" << yytext << "')\"" << endl; return STRING_LIT; }

.								{ return UNKNOWN; }
%%
