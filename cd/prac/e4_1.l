%{
    #include<stdio.h>

%}

%%
[aeiouAEIOU] {printf("Vowel");}
[a-z, A-Z] {printf("Consonant");}

;
%%

int main(){
    yylex();
    return 0;
}