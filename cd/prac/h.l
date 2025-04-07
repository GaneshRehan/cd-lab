%{
#include<stdio.h>
%}

%option noyywrap

%%
[\t \n] {fprintf(yyout, " ");}
. {fprintf(yyout, "%s", yytext);}


%%


int main(){
    yyin = fopen("test.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    return 0;
}