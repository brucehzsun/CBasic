//
// Created by bruce on 2019/1/31.
//
#include <stdlib.h>
#include <stdio.h>

int main() {
    int a;

    //直接复制
    a = 10;
    printf("a:%d，&a:%d \n", a, &a);

    //间接复制
    int *p;
    p = &a;
    *p = 20;
    printf("a:%d, &p:%d \n", a, &p);
}