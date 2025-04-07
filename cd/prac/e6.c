#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool abb(const char * ip){
    int i = 0;
    while(i < 3){
        if(i == 0 && ip[i] == 'a'){
            i++;
            continue;
            
        }
        if((i == 1 || i == 2) && ip[i] == 'b'){
            i ++;
            continue;
        }
        return (i == 3) && ip[i] == '\0';
    }
}

bool asbp(const char * ip){
    int i = 0;
    while(ip[i]){
        if(ip[i] == 'a') i ++;
        else break;

    }

    if(ip[i] != 'b') return false;
    while(ip[i]){
        if(ip[i] == 'b') i ++;
        else break;

    }
    return ip[i] == '\0';
}

bool as(const char * ip){
    int i = 0;
    while(ip[i]){
        if(ip[i] == 'a') i ++;
        else break;
    }
    return ip[i] == '\0';
}


int main(){
    char ip[100];
    printf("Enter string: ");
    scanf("%s", ip);
    if(abb(ip)) printf("Valid abb \n");
    if(asbp(ip)) printf("Valid asbp \n");
    if(as(ip)) printf("Valid as \n");


    return 0;

}