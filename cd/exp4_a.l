%{
#include <stdio.h>
%}

%%

[aeiouAEIOU]   { printf("%s is a vowel.\n", yytext); }
[a-zA-Z]       { printf("%s is not a vowel.\n", yytext); }

%%

int yywrap() {
    return 1; 
}


int main(int argc, char **argv) {
    yylex();  // Call the lexical analyzer
    return 0;
}
