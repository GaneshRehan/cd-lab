#include<stdio.h>
#include<ctype.h>

int main(){
    FILE *ip, *even, *odd;
    ip = fopen("test.txt", "r");
    even = fopen("even.txt", "w");
    odd = fopen("odd.txt", "w");

    char c;
    while((c = fgetc(ip)) != EOF){
        if(c == '2' || c == '4' || c == '6' || c == '8' || c == '0')    fprintf(even, "%c", c);
        else fprintf(odd, "%c", c);

    }
    return 0;
}
