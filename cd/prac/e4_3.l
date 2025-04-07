%{
#include <stdio.h>
int l = 0, t = 0, s = 0;    
%}

%%
[\t] t ++;
[\n] l ++;
[" "] s ++;
%%

int main(){
    yylex();
    printf("l %d, t %d, s %d", l, t, s);
    return 0;
}