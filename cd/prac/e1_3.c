#include<stdio.h>
#include<ctype.h>
int main()
{
    FILE *ip, *op;
    ip = fopen("test.txt", "r");
    op = fopen("output.txt", "w");
    char t[100]; 
    int ln = 1;
    int c = 1;
    while(fgets(t, sizeof(t), ip)){
// if(c != ln) fputs(t, op);
        if(c != ln) fprintf(op, "%s", t);
        c ++;
    }
}