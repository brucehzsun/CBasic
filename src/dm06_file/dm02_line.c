//
// Created by bruce on 2019-03-31.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void dm_fputs(const char *filename) {

    //w+没有文件会创建文件
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        goto release;
    }
    fputs("ABCDEFG\n", fp);
    fputs("abcdefg\n", fp);
    fputs("ABCDEFG\n", fp);
    fputs("abcdefg\n", fp);

    release:
    fclose(fp);
}

void dm_fgets(const char *filename) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        goto release;
    }
    char buf[1024];
    while (!feof(fp)) {
        char *p = fgets(buf, 1024, fp);
        if (p == NULL) {
            goto release;
        }
        printf("%s", buf);
    }

    release:
    fclose(fp);
}

int main() {
    char *filename = "../data/file2.txt";
    dm_fputs(filename);
    dm_fgets(filename);
}
