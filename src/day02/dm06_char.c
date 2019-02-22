//
// Created by bruce on 2019/2/21.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    //全局内存区创建空间，复制给栈内存区
    char buf[100] = "aaaaa";

    //全局内存区创建空间，复制给栈内存区
    char buf2 = "bbbb";

    //字符串在全局内存区，栈内存只有一个指针
    char *p = "cccccc";

    //在全局区创建字符串，在堆内存区创建100字节的空间，并将全区内存区的字符串拷贝到堆内存区。
    //栈内存只有一个指针。
    char *p2 = malloc(100);
    strcpy(p2,"dddd");
}
