%{
#include<stdio.h>
#include<ctype.h>
FILE *ip, *op;    
%}

%option noyywrap

%%
[\t\n] {fprintf(yyout, " ");}
[a-z] {fprintf(yyout, "%s", yytext);}

%%

int main(){
    ip = fopen("test.txt", "r");
    op = fopen("output.txt", "w");
    yyin = ip;
    yyout = op;
    yylex();
    return 0;
}
