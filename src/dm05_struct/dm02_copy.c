//
// Created by bruce on 2019-03-24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
    char name[64];
    int age;
} Teacher;


/**
 * 错误方法
 * 拷贝失败，必须使用指针间接赋值的方法
 * @param to
 * @param from
 */
void copyTeacher1(Teacher to, Teacher from) {
    to = from;
}

/**
 * 正确方法，使用指针间接赋值
 * @param to
 * @param from
 */
void copyTeacher2(Teacher *to, Teacher *from) {
    *to = *from;
}

int main() {
    Teacher t1 = {"teacher name", 30};

    Teacher t2;
    t2 = t1;
    strcpy(t2.name, "teacher2Name");
    t2.age = 40;

    printf("t1:name:%s, t1.age:%d\n", t1.name, t1.age);
    printf("t2:name:%s, t2.age:%d\n", t2.name, t2.age);

    Teacher t3;
    copyTeacher1(t3, t1);
    printf("t3:name:%s, t3.age:%d\n", t3.name, t3.age);

    copyTeacher2(&t3, &t1);
    printf("t3:name:%s, t3.age:%d\n", t3.name, t3.age);

}