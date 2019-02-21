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

//间接修改值
int main() {
    //条件1：定义两个边路
    int a = 10;
    int *p = NULL;

    p = &a;//条件2：建立关联
    *p = 20;//条件3：通过*p修改内容


    printf("a:%d\n", a);
    ruler2(&a);
    printf("a:%d\n", a);

}
