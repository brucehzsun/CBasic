//
// Created by bruce on 2019-03-23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printLine(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {

    int arr[3][5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = (i + 1) * 10 + j;
        }
    }

    printLine((int *) arr, 15);
}