//
// Created by bruce on 2019-03-30.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void fileWrite() {

    char *name = "../data/file_test1.txt";
    FILE *file = fopen(name, "r+");
    if (file == NULL) {
        printf("file open filed\n");
        return;
    }

    char buf[] = {"abcdefg"};

    size_t len = strlen(buf);
    for (int i = 0; i < len; i++) {
        fputc(buf[i], file);
    }

    fclose(file);
}


void fileRead() {
    char *name = "../data/file_test1.txt";
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("file open filed\n");
        return;
    }

    while (!feof(file)) {
        printf("%c", fgetc(file));
    }


    fclose(file);
}

int main() {
    printf("file write:\n");
    fileWrite();
    printf("file read:\n");
    fileRead();
}
