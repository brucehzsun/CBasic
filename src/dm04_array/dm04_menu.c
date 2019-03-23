//
// Created by bruce on 2019-03-23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM(a)(sizeof(a)/sizeof(*a))

int searchKeyTable(const char *table[], const int size, const char *key, int *pos) {
    if (table == NULL || key == NULL || pos == NULL) {
        printf("input params is error\n");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (strcmp(key, table[i]) == 0) {
            *pos = i;
            return 0;
        }
    }
    return -1;
}

int main() {

    const char *c_keyword[] = {
            "while",
            "case",
            "static",
            "do"
    };

    printf("a %d\n", c_keyword);
    printf("*a %s\n", *c_keyword);//while

    int ret_pos;
    searchKeyTable(c_keyword, DIM(c_keyword), "while", &ret_pos);
    printf("while pos:%d\n", ret_pos);

    searchKeyTable(c_keyword, DIM(c_keyword), "static", &ret_pos);
    printf("static pos:%d\n", ret_pos);
}