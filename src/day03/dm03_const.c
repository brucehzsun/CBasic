//
// Created by bruce on 2019/2/27.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int constTest() {
    const int a = 10;
    int *p = &a;
    *p = 20;

    printf("a:%d  %d\n", &a, a);
    printf("p:%d  %d\n", p, *p);
}

int main() {
    char *buffer = "abcdefghijklmn";
    int size = strlen(buffer);
    printf("size:%d\n", size);

    int subCount = 3;
    if (size % 3 > 0) {
        subCount++;
    }
    int subSize = size / 3;
    printf("切成的分段数:%d\n", subCount);

    char *newBuffer = (char *) malloc(size);
    int offset = 0;
    char *p = buffer;
    for (int i = 0; i < subCount; i++) {
        int subLength = 0;
        if (i == subCount - 1) {
            subLength = size - i * subSize;
        } else {
            subLength = subSize;
        }
        printf("每段 %d size：%d\n", i, subLength);
        char *subData = (char *) malloc(subLength);
        strncpy(subData, p + offset, subLength);
        strcat(newBuffer, subData);
        offset += subLength;
    }
    printf("newBuffer:%s\n", newBuffer);
}
