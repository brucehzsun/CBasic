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
void ruler2(int *p) {
    *p = 30;
}

int main() {
    int a = 10;

    //间接修改值
    int *p = NULL;
    p = &a;
    *p = 20;


    printf("a:%d\n", a);
    ruler2(&a);
    printf("a:%d\n", a);

}
