#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct operator{
    char sym[3];
    char nm[100];
};

struct operator op[] = {
    {"+", "Add"},
    {"==", "Is equal"},
    {"-", "sub"}
};

int main(){
    char ip[10];
    scanf("%s", ip);
    int i = 0;
    int l = sizeof(op)/sizeof(op[0]);
    for (i = 0; i < l; i++){
        if(strcmp(ip, op[i].sym) == 0) {printf("Valid, %s", op[i].nm); return 0;}
    }
    printf("Not valid");
    return 0;
}