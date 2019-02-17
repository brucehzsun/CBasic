//
// Created by bruce on 2019/2/17.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ruler1() {
    char *p1 = NULL;
//    错误，空指针不能拷贝
//    strcopy(p1, "abcdef");
}

void ruler2() {
    char buf[128];
    char *p1 = NULL;
    for (int i = 0; i < 10; i++) {
        p1 = &buf[i];
        printf("p1 : %d \n", p1);
    }

    printf("打印第二段\n");
    char *p2 = (char *) malloc(128);
    strcpy(p2, "abcdefghjiklmn");
    for (int i = 0; i < 10; i++) {
        p1 = p2 + i;
        printf("p1:%c \n", *p1);
    }
}

int main() {
//    ruler1();
    ruler2();
}
