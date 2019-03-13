//
// Created by bruce on 2019-03-12.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printfArr(char myArr[10][30], int num) {
    for (int i = 0; i < num; i++) {
        printf("%s\n", myArr[i]);
    }
}

void sort(char myArr[10][30], int num) {

    char temp[30];
    for (int i = 0; i < num; i++) {
        for (int j = i; j < num; j++) {
            if (strcmp(myArr[i], myArr[j]) > 0) {
                strcpy(temp, myArr[i]);
                strcpy(myArr[i], myArr[j]);
                strcpy(myArr[j], temp);
            }
        }
    }
}

int main() {
    char myArr[10][30] = {"aaaa", "cccc", "bbbb", "1111"};
    int num = 4;

    printf("排序前：\n");
    printfArr(myArr, num);

    sort(myArr,num);

    printf("排序后：\n");
    printfArr(myArr, num);

}
