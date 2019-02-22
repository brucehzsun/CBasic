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

void stringCopy4(char *from, char *to) {
    while ((*to++ = *from++) != '\0') {
    }
}

void stringCopy5(char *from, char *to) {
    while ((*to++ = *from++)) {
    }
}

int main() {
    char *from = "abcefg";
    char buf[100];

//    stringCopy1(from, buf);
//    stringCopy2(from, buf);
//    stringCopy3(from, buf);
//    stringCopy4(from, buf);
    stringCopy5(from, buf);

    printf("buf:%s \n", buf);
}
