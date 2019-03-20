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

int main() {
    arrayBasic();
    arrayBasic2();
}