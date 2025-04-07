#include<stdio.h>
#include<ctype.h>

int main(){
    FILE *filename;
    filename = fopen("output.txt", "w");
    int n;
    printf("Enter no: ");
    scanf("%d", &n);
    while(n --){
        char name[100];
        int m;
        printf("enter name ");
        scanf("%s", name);
        printf("Enter marks ");
        scanf("%d", &m);
        fprintf(filename, "%s %d", name, m);
        fprintf(filename, "\n");
    }


}