%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}
%token ZERO ONE
%%
input:
     ZERO m ZERO{printf("Valid string\n");}
     | ONE m ONE{printf("Valid string\n");}
     ;

m:
 m ZERO
 |m ONE
 |
 ;
 
 %%
 void yyerror(const char *s){
    printf("error");
 }       
int main(){
    yyparse();
    return 0;
}