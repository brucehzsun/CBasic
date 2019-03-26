//
// Created by bruce on 2019-03-26.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sort(const char **p1, const int len1, const char (*p2)[30], const int len2, char ***p3, int *len3) {

    char **retP = (char **) malloc(sizeof(char *) * (len1 + len2));
    if (retP == NULL) {
        return -1;
    }

    int i = 0;
    for (i = 0; i < len1; i++) {
        int tempLen = strlen(p1[i]) + 1;
        retP[i] = (char *) malloc(sizeof(char) * tempLen);
        if (retP[i] == NULL) {
            return -2;
        }
        strcpy(retP[i], p1[i]);
    }

    for (int j = 0; j < len2; j++, i++) {
        int tempLen = strlen(p2[j]) + 1;
        retP[i] = (char *) malloc(sizeof(char) * tempLen);
        if (retP[i] == NULL) {
            return -3;
        }
        strcpy(retP[i], p2[j]);
    }

    int p3Len = len1 + len2;
    char *tempP;
    for (i = 0; i < p3Len; i++) {
        for (int j = i; j < p3Len; j++) {
            if (strcmp(retP[i], retP[j]) > 0) {
                tempP = retP[i];
                retP[i] = retP[j];
                retP[j] = tempP;
            }
        }
    }

    *len3 = p3Len;
    *p3 = retP;
    return 0;
}

void printArr(char **p, int len) {
    for (int i = 0; i < len; i++) {
        printf("%s\n", p[i]);
    }
}

void freeArr(char ***p, int len) {
    if (p == NULL) {
        return;
    }
    char **myp = *p;
    if (myp == NULL) {
        return;
    }

    for (int i = 0; i < len; i++) {
        free(myp[i]);
    }
    free(myp);
    *myp = NULL;
}

int main() {
    char *p1[] = {"aaaaa", "ccccc", "bbb"};
    char buf2[10][30] = {"11111111", "33333333", "22222222"};
    char **p3 = NULL;


    int len1 = sizeof(p1) / sizeof(*p1);
    int len2 = 3;
    int len3 = 0;

    int ret = sort(p1, len1, buf2, len2, &p3, &len3);
    if (ret != 0) {
        return ret;
    }

    printArr(p3, len3);
    freeArr(&p3, len3);
    return 0;
}
