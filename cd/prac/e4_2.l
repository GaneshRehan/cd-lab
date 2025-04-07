%{
    #include<stdio.h>    
%}

%%
[A-Z] {printf("Captial");}
[a-z] {printf("Not captail");}
;
%%

int main(){
    yylex();
    return 0;
}