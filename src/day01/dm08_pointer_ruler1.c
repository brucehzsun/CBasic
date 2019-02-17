//
// Created by bruce on 2019/2/2.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    //1.指针的大小
    int a = 10;
    char *p = "hello world,aaaaaaaaaaaaaaaaaa";
    printf("a:%d,p:%d \n", sizeof(a), sizeof(p));

    //2.间接修改志
    int *p2 = NULL;
    p2 = &a;
    *p2 = 20;
    printf("a:%d,p2:%d\n", a, *p2);
}
