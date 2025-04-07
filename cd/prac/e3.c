#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE *ip, *op;
    ip = fopen("e1_3.c", "r");
    op = fopen("output.txt", "w");
    int mlc = 0;
    char t[1000];
    while(fgets(t, sizeof(t), ip)){
        char *sls = strstr(t, "//");
        char * mls = strstr(t, "/*");
        if(mlc){
            fprintf(op, "%s", t);
            if(t == "*/") mlc = 0;
            
        }
        else if(sls) fprintf(op, "%s", sls);
        else if(mls){
            fprintf(op, "%s", mls);
            mlc = 1;
        }

    }
    return 0;
}