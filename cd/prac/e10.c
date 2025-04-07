#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0 ,flag = 0;

void S();
void B();

void error() {
    printf("Syntax Error at position %d\n", pos);
    return;
}

void match(char expected) {
    if (input[pos] == expected) {
        pos++;
    } else {
        flag = 1;
    }
}

void S() {
    match('a');
    B();
}

void B() {
    match('b');
    
    if(input[pos]!= '\0' && flag == 0)
    B();

}

int main() {
    printf("Enter input string: ");
    scanf("%s", input);

    S();

    if (input[pos] == '\0') {
        printf("Parsing Successful.\n");
    } else {
        error();
    }

    return 0;
}