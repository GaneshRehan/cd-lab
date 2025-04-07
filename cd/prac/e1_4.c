#include<stdio.h>
#include<ctype.h>
int main(){
    FILE *ip, *op;
    ip = fopen("test.txt", "r");
    op = fopen("output.txt", "w");
    char t[1000];
    while(fgets(t, sizeof(t), ip)){
        fputs(t, op);
    }
}