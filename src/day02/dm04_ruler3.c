//
// Created by bruce on 2019/2/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 通过指针，间接修改变量的值
 * @param p
 */
void ruler3(int **p) {
    *p = 300;
}

int main() {

    char *p1 = NULL;
    p1 = 100;

    char **p2 = NULL;
    p2 = &p1;
    *p2 = 200;
    printf("p1:%d\n", p1);

    ruler3(&p1);
    printf("p1:%d\n", p1);
}
