//
// Created by bruce on 2019-04-25.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} LIST;

LIST *createList();

int insertList(LIST *head, int x, int y);

int printList(LIST *head);

int deleteList(LIST *head, int y);

int destroyList(LIST *head);

LIST *createList() {
    LIST *pHead, *pCur, *pMalloc;
    int data;

    pHead = (LIST *) malloc(sizeof(LIST));
    pHead->data = 0;
    pHead->next = NULL;

    printf("请输入链表数据：\n");
    scanf("%d", &data);
    pCur = pHead;

    while (data != -1) {
        pMalloc = (LIST *) malloc(sizeof(LIST));
        if (pMalloc == NULL) {
            return NULL;
        }
        pMalloc->data = data;
        pMalloc->next = NULL;

        pCur->next = pMalloc;
        pCur = pMalloc;

        printf("请输入链表数据：\n");
        scanf("%d", &data);
    }


    return pHead;
}

int insertList(LIST *head, int x, int y) {
    return 0;
}

int printList(LIST *head) {
    if (head == NULL) {
        return -1;
    }
    LIST *pCur = head;
    while (pCur) {
        printf(">> %d\n", pCur->data);
        pCur = pCur->next;
    }

    return 0;
}

int deleteList(LIST *head, int y) {
    return 0;
}

int destroyList(LIST *head) {
    return 0;
}

int main() {

    LIST *head = createList();
    if (head == NULL) {
        return -1;
    }
    int ret;
    ret = printList(head);

}
