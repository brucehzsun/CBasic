//
// Created by bruce on 2019-03-31.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
    char name[64];
    int age;
} Teacher;

void dm_write(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    Teacher teachers[3];
    for (int i = 0; i < 3; i++) {
        sprintf(teachers[i].name, "teacher%d", i);
        teachers[i].age = (30 + i);
    }

    for (int i = 0; i < 3; i++) {
        int ret = fwrite(&teachers[i], sizeof(Teacher), 1, fp);
        printf("fwrite ret:%d\n", ret);
    }

    if (fp != NULL) {
        fclose(fp);
    }
}

void dm_read(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return;
    }

    Teacher teachers[3];
    for (int i = 0; i < 3; i++) {
        int ret = fread(&teachers[i], sizeof(Teacher), 1, fp);
        printf("fread ret:%d\n", ret);
    }

    for (int i = 0; i < 3; i++) {
        printf("teacher name:%s, age:%d\n", teachers[i].name, teachers[i].age);
    }

    if (fp != NULL) {
        fclose(fp);
    }
}

int main() {
    char *filename = "../data/file3.data";
    dm_write(filename);
    dm_read(filename);
}