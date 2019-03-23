//
// Created by bruce on 2019-03-21.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printArr01(int arr[3][5]) {
    printf("打印数组指针01：\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void printArr02(int arr[][5]) {
    printf("打印数组指针02：\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void printArr03(int (*arr)[5]) {
    printf("打印数组指针03：\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int arr[3][5];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = (i + 1) * 10 + j;
        }
    }

    printf("打印多维数组：\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("arr : %d, arr+1 : %d \n", arr, arr + 1);
    //arr : -535672464, arr+1 : -535672444
    //步长20 = 5*4(字节);

    printf("&arr : %d, &arr+1 : %d \n", &arr, &arr + 1);
    //&arr : -380970640, &arr+1 : -380970580
    //步长60：3*20 = 3*5*4(字节);

    //===========================
    int(*pArr)[5];
    pArr = arr;

    printArr01(pArr);
    printArr02(pArr);
    printArr03(pArr);

    //结论：
    /**
     * 1.多维数组的本质就是数组指针
     */



    /**
     * (a+i):二级指针，代表整个第i行的地址
     * *(a+i):一级指针，代表第i行首元素的地址
     * *(a+i)+j == &a[i][j]
     * *(*(a+i)+j) == a[i][j]
     */

    /**
     * *(*(a+i)+j) == a[i][j] 推导过程
     *
     * a[i] => a[0+i] => a(0+i) => *(a+i)
     *
     * a[i][j] => a[0+i][j] => *(a+i)[j] = >  *(a+i)[0+j] =>  *(*(a+i)+j)
     */
}
