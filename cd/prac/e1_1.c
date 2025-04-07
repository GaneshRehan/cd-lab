#include<stdio.h>
#include<ctype.h>

int main(){
    char fn[100];
    scanf("%s", fn);
    FILE *filename;
    filename = fopen(fn, "r");
    char c;
    int words = 0, lines = 0, chars = 0;
    while((c = fgetc(filename)) != EOF){
        if (c == ' ') words ++;
        if (c == '\n') lines ++;
        if (c != ' ' && c != '\n') chars ++;
    }
    lines ++;
    printf("%d, %d, %d", chars, words, lines);
    return 0;

}