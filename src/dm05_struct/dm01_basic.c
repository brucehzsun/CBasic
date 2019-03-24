//
// Created by bruce on 2019-03-24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Teacher1 {
    char name[64];
    int age;
};

typedef struct Teacher2 {
    char name[64];
    int age;
} Teacher2;

struct Student1 {
    char name[64];
    int age;
} s2 = {"name1", 10};

int main() {
    struct Teacher1 t1 = {"teache1 name", 20};
    Teacher2 t2;

    printf("s2 name :%s, age:%d\n", s2.name, s2.age);
    strcpy(s2.name, "new name");
    s2.age = 40;
    printf("s2 name :%s, age:%d\n", s2.name, s2.age);


    struct Teacher1 *p1;
    p1 = &t1;
    printf("t1->name:%s, t1->age:%d\n", p1->name, p1->age);
    p1->age = 30;
    strcpy(p1->name, "new name");
    printf("t1->name:%s, t1->age:%d\n", p1->name, p1->age);

}
