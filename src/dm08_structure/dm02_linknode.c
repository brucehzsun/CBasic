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
    LIST *pM = (LIST *) malloc(sizeof(LIST));
    if (pM == NULL) {
        return -1;
    }
    pM->data = y;
    pM->next = NULL;

    LIST *pPre = head;
    LIST *pCur = pPre->next;

    while (pCur) {
        if (pCur->data == x) {
            pPre->next = pM;
            pM->next = pCur;
            break;
        }
        pPre = pCur;
        pCur = pCur->next;
    }

    return 0;
}

int printList(LIST *head) {
    if (head == NULL) {
        return -1;
    }
    LIST *pCur = head;
    while (pCur) {
        printf("%d ", pCur->data);
        pCur = pCur->next;
    }

    printf("\n");
    return 0;
}

int deleteList(LIST *head, int y) {
    if (head == NULL) {
        return -1;
    }

    LIST *pPre = head;
    LIST *pCur = pPre->next;
    while (pCur) {
        if (pCur->data == y) {
            pPre->next = pCur->next;
            free(pCur);
            break;
        }
        pPre = pCur;
        pCur = pCur->next;
    }

    return 0;
}

int destroyList(LIST *head) {
    if (head == NULL) {
        return -1;
    }
    LIST *temp = NULL;
    LIST *pCur = head;
    while (pCur) {
        temp = pCur->next;
        free(pCur);
        pCur = temp;
    }
    return 0;
}

int main() {

    LIST *head = createList();
    if (head == NULL) {
        return -1;
    }
    int ret;
    ret = printList(head);

    printf("20前面插入19\n");
    ret = insertList(head, 20, 19);
    if (ret != 0) {
        return ret;
    }
    printList(head);

    printf("删除19\n");
    ret = deleteList(head, 19);
    if (ret != 0) {
        return ret;
    }
    printList(head);

    printf("销毁链表\n");
    destroyList(head);
}
