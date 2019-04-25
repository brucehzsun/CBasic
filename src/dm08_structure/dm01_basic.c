//
// Created by bruce on 2019-04-24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
    int data;
    struct Teacher *next;
} Teacher;

/**
 * 错误案例，临时区，无法返回对象，返回的是野指针
 * @return
 */
Teacher *createLink() {
    Teacher t1, t2, t3;
    t1.data = 1;
    t2.data = 2;
    t3.data = 3;

    t1.next = &t2;
    t2.next = &t3;
    t3.next = NULL;

    return &t1;
}

int main() {
    Teacher *head = createLink();

    Teacher *temp;

    temp = head;
    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("finish\n");
}