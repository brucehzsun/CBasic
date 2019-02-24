//
// Created by bruce on 2019/2/24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strInverse(char *p1) {

    int length = strlen(p1);
    char *end = p1 + length - 1;

    char temp;
    while (p1 < end) {
        temp = *p1;
        *p1 = *end;
        *end = temp;
        p1++;
        end--;
    }
    return 0;
}

/**
 * 通过递归的方式逆转打印，使用栈。
 * @param p
 * @return
 */
void strInverse2(char *p) {
    if (*p == '\0') {
        return;
    }

    strInverse2(p + 1);
    printf("%c", *p);
}

void strInverse3(char *p, char *pOut) {
    if (*p == '\0') {
        return;
    }

    strInverse3(p + 1, pOut);
    strncat(pOut, p, 1);
}

int main() {
    char buf[] = "abc";
//    strInverse(buf);
//    strInverse2(buf);
//    printf("\np:%s\n", buf);
    {
        char out[100] = {0};
        strInverse3(buf, out);
        printf("out:%s\n", out);
    }
}