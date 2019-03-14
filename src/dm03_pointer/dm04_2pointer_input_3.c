//
// Created by bruce on 2019-03-13.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char **createCharArray(int num) {
    char **p = (char **) malloc(sizeof(char *) * num);
    for (int i = 0; i < num; i++) {
        p[i] = (char *) malloc(sizeof(char) * 100);
        sprintf(p[i], "%d%d%d", i + 1, i + 1, i + 1);
    }
    return p;
}

void printArr(char **p, int num) {
    for (int i = 0; i < num; i++) {
        printf("%s\n", *(p + i));
    }
}

void sort(char **p, int num) {

    char *temp = NULL;
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (strcmp(p[i], p[j]) < 0) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void freeArr(char **p, int num) {
    for (int i = 0; i < num; i++) {
        free(p[i]);
        p[i] = NULL;
    }

    free(p);
}

int main() {

    int num = 5;
    char **p = createCharArray(num);

    printf("排序前：\n");
    printArr(p, num);

    sort(p, num);

    printf("排序后：\n");
    printArr(p, num);

    printf("释放内存：\n");
    freeArr(p, num);

    printf("over\n");
}