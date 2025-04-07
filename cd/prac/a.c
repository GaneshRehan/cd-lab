#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    FILE *ip, *op;
    ip = fopen("test.txt", "r");
    op = fopen("output.txt", "w");
    char c;
    int l = 1, dl = 3;
    while((c = fgetc(ip)) != EOF){
        if(c == '\n') l++;
        if(l != dl) fprintf(op, "%c", c);

    }
    return 0;
}