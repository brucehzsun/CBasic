//
// Created by bruce on 2019/2/24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getStrCount(char *p, int *count) {
    if (p == NULL | count == NULL) {
        printf("func getStrCount() input is null\n");
        return -1;
    }

    int start = 0;
    int end = strlen(p) - 1;
    while (isspace(p[start]) && p[start] != '\0') {
        start++;
    }
    while (isspace(p[end]) && p[end] != '\0') {
        end--;
    }

    *count = end - start + 1;
    return 0;
}

int strTrim(const char *p, char *out) {
    if (p == NULL | out == NULL) {
        printf("func getStrCount() input is null\n");
        return -1;
    }

    int start = 0;
    int end = strlen(p) - 1;
    while (isspace(p[start]) && p[start] != '\0') {
        start++;
    }
    while (isspace(p[end]) && p[end] != '\0') {
        end--;
    }

    int count = end - start + 1;

    strncpy(out, p + start, count);
    out[count] = '\0';
    return 0;
}

//错误案例
int strTrim2(char *p) {
    if (p == NULL) {
        printf("func getStrCount() input is null\n");
        return -1;
    }

    int start = 0;
    int end = strlen(p) - 1;
    while (isspace(p[start]) && p[start] != '\0') {
        start++;
    }
    while (isspace(p[end]) && p[end] != '\0') {
        end--;
    }

    int count = end - start + 1;

    strncpy(p, p + start, count);
    p[count] = '\0';
    return 0;
}

int main() {
    char *p = "   abcdeg   ";
    {
//        int count = 0;
//        int ret = getStrCount(p, &count);
//        if (ret != 0) {
//            printf("getStrCount is error\n");
//            return ret;
//        }
//        printf("str count:%d\n", count);
    }
    {
        char buf[100];
        int ret = strTrim(p, buf);
        if (ret != 0) {
            return ret;
        }
        printf("buf:%s||| \n", buf);
    }
    {
//        char buf[] = "   abcdeg   ";
//        int ret = strTrim2(buf);
//        if (ret != 0) {
//            printf("error");
//            return ret;
//        }
//        printf("buf:%s||| \n", buf);
    }
}
