//
// Created by bruce on 2019/2/22.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void stringCopy1(char *from, char *to) {
    while (*from != '\0') {
        *to = *from;
        from++;
        to++;
    }

    *to = '\0';
}

void stringCopy2(char *from, char *to) {
    while (*from != '\0') {
        *to++ = *from++;
    }

    *to = '\0';
}

void stringCopy3(char *from, char *to) {
    while ((*to = *from) != '\0') {
        from++;
        to++;
    }
}

/**
 * 不使用辅助指针变量，很容易改变初始的参数的值。建议使用辅助指针变量；
 * @param from
 * @param to
 */
void stringCopy4(const char *from, char *to) {
    printf("stringCopy4 start,from:%s \n", from);
    while ((*to++ = *from++) != '\0') {
    }
    //from指针变了
    printf("stringCopy4 end,from:%s \n", from);
}

int stringCopy5(const char *from, char *to) {
    if (from == NULL || to == NULL) {
        return -1;
    }
    //辅助指针变量,使用辅助指针变量，可以有效的解决入参变化的问题；
    char *tmpFrom = from;
    char *tmpTo = to;
    while ((*tmpTo++ = *tmpFrom++)) {
    }
    return 0;
}

int main() {
    char *from = "abcefg";
    char buf[100];

//    stringCopy1(from, buf);
//    stringCopy2(from, buf);
//    stringCopy3(from, buf);
    stringCopy4(from, buf);
//    stringCopy5(from, buf);
//    {
//        char *to = NULL;
//        int ret = stringCopy5(from, to);
//        printf("ret = %d \n", ret);
//    }

    printf("buf:%s \n", buf);
}
