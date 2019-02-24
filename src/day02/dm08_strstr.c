//
// Created by bruce on 2019/2/24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int findCount(char *p, char *find) {
    int count = 0;

    while (p) {
        p = strstr(p, find);
        if (p) {
            count++;
            p = p + strlen(find);
        } else {
            break;
        }

    }
    return count;
}

int findCountGood(char *p, char *find, int *count) {
    int ret = 0;
    if (p == NULL || find == NULL || count == NULL) {
        ret = -1;
        printf("func findCountGood() error:%d p == NULL || find == NULL || count == NULL\n", ret);
        return ret;
    }
    while ((p = strstr(p, find))) {
        (*count)++;
        p = p + strlen(find);
    }
    return ret;
}

int main() {
    char *p = "abcd111abcd2222abcd333abcd444";
    char *find = "abcd";
    char *find2 = NULL;
    int count = 0;
    int ret = findCountGood(p, find2, &count);
    if (ret != 0) {
        printf("error");
        return -1;
    }
    printf("findCount:%d \n", count);
    printf("print p:%s \n", p);
}