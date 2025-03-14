#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int foo(char *str) {
    char buffer[100];

    strcpy(buffer, str); //Vulnerability

    return 1;
}

int main() {
    char str[400];
    FILE *badfile;

    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 300, badfile);
    foo(str);

    printf("Returned Properly\n");
    return 1;
}