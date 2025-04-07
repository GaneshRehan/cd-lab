%{
#include <stdio.h>
%}

%%

[A-Z]          { printf("%s is a captail letter.\n", yytext); }
.              { printf("%s is not a captail letter.\n", yytext); }

%%

int yywrap() {
    return 1; // End of input
}


int main(int argc, char **argv) {
    yylex();  // Call the lexical analyzer
    return 0;
}
