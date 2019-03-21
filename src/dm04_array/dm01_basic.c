//
// Created by bruce on 2019-03-19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void arrayBasic() {
    int a[] = {1, 2, 3};
    int b[100] = {1, 2, 3};
    int c[100] = {0};

    memset(c, 0, sizeof(c));

    printf("数组首元素的地址：%d, b+1：%d\n", b, b + 1);
    printf("数组的地址：%d, b+1：%d\n", &b, &b + 1);
}

void arrayBasic2() {
    typedef int(MyArrayType)[5];
    MyArrayType myArr;//int myArr[5];

    for (int i = 0; i < 5; i++) {
        myArr[i] = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d", myArr[i]);
    }
    printf("\n");

    printf("数组首元素地址%d, myArr+1:%d\n", myArr, myArr + 1);
    printf("数组地址%d, &myArr+1:%d\n", &myArr, &myArr + 1);
}

/**
 * 定义数组指针变量的第一种方法
 */
void arryPointer1() {
//    char *pArray = {"111", "222", "333"};

    typedef int(MyArrayType)[5];

    MyArrayType *myArrayType;

    int myArray2[5];
    myArrayType = &myArray2;

    for (int i = 0; i < 5; i++) {
        (*myArrayType)[i] = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d", (*myArrayType)[i]);
    }
}

/**
 * 定义数组指针变量的第二种方法
 */
void arrayPointer2() {
    typedef int (*MyArrayType)[5];
    MyArrayType myArrayType;

    int myArray2[5];
    myArrayType = &myArray2;

    for (int i = 0; i < 5; i++) {
        (*myArrayType)[i] = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d", (*myArrayType)[i]);
    }
}

/**
 * 定义数组指针变量的第三种方法
 */
void arrayPointer3() {
    int (*myArrayType)[5];

    int myArray2[5];
    myArrayType = &myArray2;

    for (int i = 0; i < 5; i++) {
        (*myArrayType)[i] = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d", (*myArrayType)[i]);
    }
}

int main() {
//    arrayBasic();
//    arrayBasic2();
//    arryPointer1();
//    arrayPointer2();
    arrayPointer3();
}