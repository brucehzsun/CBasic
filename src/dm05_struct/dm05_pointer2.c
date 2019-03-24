//
// Created by bruce on 2019-03-24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
    char name[64];
    char *alias;
    char **stuNames;
    int age;
} Teacher;


void printTeachers(Teacher *t, int num) {
    for (int i = 0; i < num; i++) {
        printf("teacher age:%d\n", t[i].age);
        for (int j = 0; j < 3; j++) {
            printf("%s ", t[i].stuNames[j]);
        }
        printf("\n");
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

        //打造二维内存模型
        char **p = (char **) malloc(sizeof(char *) * 3);
        for (int j = 0; j < 3; j++) {
            p[j] = (char *) malloc(sizeof(64));
        }
        temp[i].stuNames = p;
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

        //释放二级指针
        if (t[i].stuNames != NULL) {
            char **p = t[i].stuNames;
            for (int j = 0; j < 3; j++) {
                free(p[j]);
            }
            free(p);

            //避免野指针
            t[i].stuNames = NULL;
        }
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

        for (int j = 0; j < 3; j++) {
            printf("输入学生的名字:\n");
            scanf("%s", teachers[i].stuNames[j]);

        }
    }

    printTeachers(teachers, num);

    sortTeacher(teachers, num);
    printf("排序之后的结果：\n");
    printTeachers(teachers, num);

    printf("释放内存\n");
    freeTeachers(teachers, num);
}