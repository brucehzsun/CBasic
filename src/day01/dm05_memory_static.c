//
// Created by bruce on 2019/2/1.
//
#include <stdlib.h>
#include <stdio.h>

/**
 * 全局区的内存由系统控制，不会在方法执行完毕后自动释放掉；
 */
void getStr0() {
    char *p0 = "abcdefg";
    printf("p0:%s,%d\n", p0, p0);
    //方法执行完毕p0不会自动释放掉
}

char *getStr1() {
    //不会重复创建内存空间
    char *p1 = "abcdefg";
    return p1;
}

char *getStr2() {
    //不会重复创建内存空间
    char *p2 = "abcdefg";
    return p2;
}

/**
 * C编译器很聪明，在全局区不会重复创建一样的字符串
 * @return
 */
int main() {
    getStr0();
    char *p1 = getStr1();
    char *p2 = getStr2();
    printf("打印字符串：p1:%s, p2:%s \n", p1, p2);
    printf("打印指针的值：p1:%d, p2:%d \n", p1, p2);

    //编译器不会重复创建一样的内存空间在全局区
    char *p3 = "abc";
    char *p4 = "abc";
    printf("打印字符串：p3:%s, p4:%s \n", p3, p4);
    printf("打印指针的值：p3:%d, p4:%d \n", p3, p4);
}
