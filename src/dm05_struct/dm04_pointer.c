//
// Created by bruce on 2019-03-24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
    char name[64];
    char *alias;
    int age;
} Teacher;


void printTeachers(Teacher *t, int num) {
    for (int i = 0; i < num; i++) {
        printf("teacher age:%d\n", t[i].age);
    }
}

void sortTeacher(Teacher *t, int num) {
    Teacher temp;
    for (int i = 0; i < num; i++) {
        for (int j = i; j < num; j++) {
            if (t[i].age > t[j].age) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

int createTeachers(Teacher **t, int num) {
    Teacher *temp = (Teacher *) malloc(sizeof(Teacher) * num);
    if (temp == NULL) {
        return -1;
    }
    memset(temp, 0, sizeof(Teacher) * num);
    for (int i = 0; i < num; i++) {
        temp[i].alias = (char *) malloc(60);
    }
    *t = temp;
    return 0;
}

int freeTeachers(Teacher *t, int num) {
    if (t == NULL) {
        return -1;
    }
    for (int i = 0; i < num; i++) {
        free(t[i].alias);
    }

    free(t);
    return 0;
}

int main() {

    int num = 3;

    //内存分配在堆上，不建议使用
//    Teacher teachers[num];

    Teacher *teachers = NULL;
    int ret = createTeachers(&teachers, num);
    if (ret != 0) {
        printf("creat teacher failed\n");
        return -1;
    }


    for (int i = 0; i < num; i++) {
        printf("输入老师的年龄:\n");
        scanf("%d", &(teachers[i].age));

        printf("输入老师的名字:\n");
        scanf("%s", teachers[i].name);

        printf("输入老师的别名:\n");
        scanf("%s", teachers[i].alias);
    }

    printTeachers(teachers, num);

    sortTeacher(teachers, num);
    printf("排序之后的结果：\n");
    printTeachers(teachers, num);

    freeTeachers(teachers, num);
}