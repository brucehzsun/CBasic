//
// Created by bruce on 2019/2/1.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 堆内存
 * @return
 */
char *getHeapStr(int num) {
    char *p = (char *) malloc(sizeof(char) * num);
    return p;
}

char *getStackStr() {
    char buf[64];
    strcpy(buf, "abcdefg");
    printf("stack str = %s \n", buf);
    return buf;
}

int main() {
    char *temp = getHeapStr(10);
    if (temp == NULL) {
        return 0;
    }
    strcpy(temp, "abcd");
    printf("堆内存，p=%d,p=%s \n", temp, temp);

    char *temp2 = getStackStr();
    if (temp2 != NULL) {
        printf("栈内存：%s,%d \n", temp2, temp2);
    }
}
