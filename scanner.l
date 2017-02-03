%{
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
#include "parser.tab.h"

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

class 							{ yylval.sval = (char*)"class"; return CLASS; }
def 							{ yylval.sval = (char*)"def"; return DEF; }
if 								{ yylval.sval = (char*)"if"; return IF; }
elif 							{ yylval.sval = (char*)"elif"; return ELIF; }
else 							{ yylval.sval = (char*)"else"; return ELSE; }
while 							{ yylval.sval = (char*)"while"; return WHILE; }
extends 						{ yylval.sval = (char*)"extends"; return EXTENDS; }
return 							{ yylval.sval = (char*)"return"; return RETURN; }
and 							{ yylval.sval = (char*)"and"; return AND; }
or 								{ yylval.sval = (char*)"or"; return OR; }
not 							{ yylval.sval = (char*)"not"; return NOT; }

[=+\-*/(){}<>:;,.] 				{ return yylval.ival = yytext[0]; }
"<="							{ yylval.sval = (char*)"<="; return ATMOST; }
">="							{ yylval.sval = (char*)">="; return ATLEAST; }
"=="							{ yylval.sval = (char*)">="; return EQUALS; }
[0-9]+ 							{ yylval.ival = atoi(yytext); return INT_LIT; }
[_a-zA-Z0-9]+					{ yylval.sval = strdup(yytext); return IDENT; }
\"\"\"(.|\n)*\"\"\"				{ yylval.sval = strdup(yytext); return STRING_LIT; cout << yylineno << yytext << endl; }
\"(\\[0bftnr\\]|[^"\n\\])*\"	{ yylval.sval = strdup(yytext); return STRING_LIT; cout << yylineno << yytext << endl; }
\"(\\.|[^"\n])*\"				{ yylval.sval = strdup(yytext); return STRING_LIT; cout << yylineno << yytext << endl;
	cerr << yylineno << ": Illegal escape code; only \\\\, \\0, \\t, \\n, \\r, \\n are permitted (at '" << yytext << "')\"" << endl; }
\"(\\.|[^"])*\n					{ yylval.sval = strdup(yytext); return STRING_LIT; cout << yytext << endl;
	cerr << yylineno << ": Newline before string terminated; single-quoted strings must be entirely on one line (at '" << yytext << "')\"" << endl;}

.								{ yylval.ival = yytext[0]; return UNKNOWN; }
%%