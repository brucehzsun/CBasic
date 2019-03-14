//
// Created by bruce on 2019-03-11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printArray(char **myArr, int len) {
    for (int i = 0; i < len; i++) {
//        printf("%s\n", myArr[i]);
        printf("%s\n", *(myArr + i));
    }
}

void sort(char **myArr, int len) {

    char *temp = NULL;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (strcmp(myArr[i], myArr[j]) > 0) {
                temp = myArr[i];
                myArr[i] = myArr[j];
                myArr[j] = temp;
            }
        }
    }
}

int main() {
    //指针数组，数组的每个元素是指针ß
    char *myArr[] = {"aaaa", "dddd", "ccc", "bbb"};
    int len = sizeof(myArr)/ sizeof(myArr[0]);
    printf("排序之前\n");
    printArray(myArr, len);

    sort(myArr,len);

    printf("排序之后\n");
    printArray(myArr, len);


}
