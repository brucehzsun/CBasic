//
// Created by bruce on 2019/2/27.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int constTest() {
    const int a = 10;
    int *p = &a;
    *p = 20;

    printf("a:%d  %d\n", &a, a);
    printf("p:%d  %d\n", p, *p);
}

int main() {
    char *p = "abcdefghijklmn";
    char *sub = malloc(100);
    strncpy(sub, p + 3, 3);

    char *newChar = malloc(100);
    strncpy(newChar, p + 6, 3);
    strcat(sub, newChar);

    printf("sub:%s\n", sub);
}
