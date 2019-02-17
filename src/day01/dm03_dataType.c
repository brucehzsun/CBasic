//
// Created by bruce on 2019/1/31.
//
#include <stdlib.h>
#include <stdio.h>

int dataType() {
    int a;
    int b[10];

    //4个字节
    printf("a:%d \n", sizeof(a));
    //40个字节
    printf("b:%d \n", sizeof(b));

    //b:数组第一个数的内存地址；b+1，第二个数字的内存地址，相差四个字节
    //&b:数组整个内存块的内存地址，&b+1:内存块的下一个内存地址，相差四十个字节
    printf("b:%d, b+1:%d, &b:%d, &b+1:%d \n", b, b + 1, &b, &b + 1);
}

struct Teacher {
    char *name[64];
    int age;
};

void typeDef();

void pointer();

typedef struct Teacher2 {
    char *name[64];
    int age;
} Teacher2;

typedef int u32;

void typeDef() {
    //struct比较加struct关键字
    struct Teacher t1;
    t1.age = 10;

    //typedef后不需要加struct关键字
    Teacher2 t2;
    t2.age = 20;

    printf("t1:%d,t2:%d \n", t1.age, t2.age);

    printf("int u32:%d \n", sizeof(u32));
}

void voidPointer() {
    char *p2 = NULL;
    p2 = (char *) malloc(100);
    printf("sizeof(p2):%d \n", sizeof(p2));

    void *p3 = NULL;
    p3 = &p2;

    printf("p2:%d,p3:%d", p3, p2);
}

int main() {
    dataType();

    typeDef();

    voidPointer();
}



