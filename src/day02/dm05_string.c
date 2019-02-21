//
// Created by bruce on 2019/2/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void string1() {
    char buf[] = "abcd";
    //4
    printf("buf strlen:%d \n", strlen(buf));
    //5
    printf("buf sizeof:%d \n", sizeof(buf));
    printf("buf end:%d \n", buf[4]);

    char buf2[128] = "abcd";
    //4
    printf("buf strlen:%d \n", strlen(buf2));
    //128
    printf("buf sizeof:%d \n", sizeof(buf2));
    //null
    printf("buf[10]:%d \n", buf2[10]);
}


void string2() {
    char buf[] = "abcedfg";
    char *p = NULL;

    //字符数组的首地址
    p = buf;

    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        printf("%c ", *(p + i));
    }
}

int main() {
    string1();
    string2();
}
