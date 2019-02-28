//
// Created by bruce on 2019/2/28.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int create(char **p1, int *len) {
    *len = 10;
    *p1 = malloc(*len);
    strcpy(*p1, "aaaaa");
    return 0;
}

void freeStr(char **p) {
    free(*p);
    *p = NULL;
}

void freeStr2(char *p) {
    free(p);
}

int main() {
    char *p1 = NULL;
    int len = 0;
    int ret = create(&p1, &len);
    printf("p1:%s\n", p1);
    printf("len:%d\n", len);

//    freeStr(&p1);
//    printf("p1:%s\n", p1);

    //只能释放指针指向的内存，指针没有置空，是野指针；
    freeStr2(p1);
    p1 = NULL;
    printf("p1:%d\n", p1);
}
