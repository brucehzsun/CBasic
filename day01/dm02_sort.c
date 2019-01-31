//
// Created by bruce on 2019/1/30.
//

#include <stdlib.h>
#include <stdio.h>

void arraySort(int arr[], int len);

void printArray(int arr[], int len);

int main() {

    int arr[] = {4, 8, 2, 6, 5};
    printf("arr[] sizeof:%d\n", sizeof(arr));
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("len = %d\n", len);
    printf("排序之前:\n");
    printArray(arr, len);

    arraySort(arr, len);

    printf("排序之后:\n");
    printArray(arr, len);

}

void arraySort(int arr[], int len) {

    printf("arraySort arr sizeof:%d\n", sizeof(arr));
    printf("arraySort arr sizeof:%d\n", sizeof(arr[0]));
    int temp = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

