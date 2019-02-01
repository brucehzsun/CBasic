//
// Created by bruce on 2019/1/31.
//
#include <stdlib.h>
#include <stdio.h>

int main() {
    int a;//开辟内存空间

    //直接复制
    a = 10;//CPU执行
    printf("a:%d，&a:%d \n", a, &a);

    //间接复制
    int *p;
    p = &a;
    *p = 20;
    //a:20, &p:-311817792, p:-311817780, *p:20
    //&p != p
    //p代表数据首元素的地址
    //&p代表整个数组的地址
    printf("a:%d, &p:%d, p:%d, *p:%d \n", a, &p, p, *p);
}