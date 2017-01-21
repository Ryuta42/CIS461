%{
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
void pt(const char* s) {
	cout << yylineno << "  " << s << " \""<< yytext << "\"" << endl;
	return;
}
%}
%x COMMENT
%option yylineno
%%
<COMMENT,INITIAL>\n 		{ }
[ \t]						{ }
\/\/.*\n					{ }
class 						{ pt("CLASS"); }
def 						{ pt("DEF"); }
if 							{ pt("IF"); }
elif 						{ pt("ELIF"); }
else 						{ pt("ELSE"); }
while 						{ pt("WHILE"); }
extends 					{ pt("EXTEND"); }
return 						{ pt("RETURN"); }
String 						{ pt("STRING"); }
Integer						{ pt("INTEGER"); }
Obj							{ pt("OBJ"); }
Boolean						{ pt("BOOL"); }
true						{ pt("TRUE"); }
false						{ pt("FALSE"); }
and 						{ pt("AND"); }
or 							{ pt("OR"); }
not 						{ pt("NOT"); }
Nothing						{ pt("NOTHING"); }
none						{ pt("NONE"); }
"{" 						{ pt("{"); }
"}" 						{ pt("}"); }
"(" 						{ pt("("); }
")" 						{ pt(")"); }
";" 						{ pt(";"); }
":" 						{ pt(":"); }
"." 						{ pt("."); }
"," 						{ pt(","); }
"_" 						{ pt("_"); }
"+" 						{ pt("+"); }
"-" 						{ pt("-"); }
"*"							{ pt("*"); }
"/"							{ pt("/"); }
"<=" 						{ pt("ATMOST"); }
"<" 						{ pt("<"); }
">=" 						{ pt("ATLEAST"); }
">" 						{ pt(">"); }
"==" 						{ pt("EQUALS"); }
"=" 						{ pt("="); }
[0-9]+ 						{ pt("INT_LIT"); }
[_a-zA-Z0-9]+				{ pt("IDENT"); }
\"\"\"(.|\n)*\"\"\"			{ pt("STRING_LIT_TRI"); }
\"(\\[0bftnr\\]|[^"\n\\])*\"	{ pt("STRING_LIT"); }
\"(\\.|[^"\n])*\"			{ pt("STRING_LIT"); cerr << yylineno << ": Illegal escape code; only \\\\, \\0, \\t, \\n, \\r, \\n are permitted (at '" << yytext << "')\"" << endl; }
\"(\\.|[^"]|\n)*\"			{ pt("STRING_LIT_ERR"); cerr << yylineno << ": Newline before string terminated; single-quoted strings must be entirely on one line (at '" << yytext << "')\"" << endl; }
\/\*						{ BEGIN(COMMENT); }
<COMMENT>\*\/				{ BEGIN(INITIAL); }
<COMMENT>.					{ }
. 							{ pt("UNKNOWN"); }
%%
int main(int argc, char* argv[]) {
	if (argc > 1)
	{
		FILE *file = fopen(argv[1], "r");
		if (!file)
		{
			cerr << "Error opening file!" << endl;
			return -1;
		}
		yyin = file;
	}

	// lex through
	yylex();
}