//
// Created by bruce on 2019-03-23.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printArr(const char *arr[]) {
    for (int i = 0; arr[i] != NULL; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    const char *arr1[] = {"while", "case", "static", "do", "\0"};

    printArr(arr1);

    const char *arr2[] = {"while", "case", "static", "do", 0};
    printArr(arr2);

    const char *arr3[] = {"while", "case", "static", "do", NULL};
    printArr(arr3);

}