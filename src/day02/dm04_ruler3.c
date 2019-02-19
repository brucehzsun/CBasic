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

void init(char **p, int *len) {

    char *temp = (char *) malloc(100);
    strcpy(temp, "abcdefghij");
    //二级指针间接赋值
    *p = temp;

    //一级指针间接赋值
    *len = strlen(temp);
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


    //间接赋值的意义
    char *p3 = NULL;
    int len3;
    init(&p3, &len3);
    printf("p3:%s,len:%d\n", p3, len3);
}
