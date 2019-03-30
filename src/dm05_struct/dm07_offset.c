//
// Created by bruce on 2019-03-30.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct AdvTeacher {
    char name[64];
    int age;
    char *aliase;
} AdvTeacher;

int main() {

    AdvTeacher *p = NULL;

    int offset = (int) &(p->age);
    printf("offset:%d\n", offset);
    int offset2 = (int) &(((AdvTeacher *) 0)->age);
    printf("offset2:%d\n", offset2);
}