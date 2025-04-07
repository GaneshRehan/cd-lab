%{
#include <stdio.h>

int l = 0;
int t = 0;
int s = 0;
%}

%%

\n      { l++; }  // Count newlines (lines)
\t      { t++; }   // Count tabs
" "     { s++; } // Count spaces

%%

int yywrap(){
return 1;
}

int main(int argc, char **argv) {
    yylex();  
    printf("Number of lines: %d\n", l);
    printf("Number of tabs: %d\n", t);
    printf("Number of spaces: %d\n", s);

    return 0;
}
