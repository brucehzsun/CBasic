//
// Created by bruce on 2019-04-13.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dm02_socket_client.h"

int main() {

    void *handler = NULL;
    int ret;

    ret = cltSocketInit(&handler);
    if (ret != 0) {
        printf("socket init failed\n");
        return -1;
    }

    const char buf[] = {"abcdegf"};
    int len = strlen(buf);

    ret = cltSocketSend(handler, buf, len);
    if (ret != 0) {
        printf("socket send failed\n");
        return -2;
    }

    char revBuf[128];
    int revLen = 0;
    ret = cltSocketRev(handler, revBuf, &revLen);
    if (ret != 0) {
        printf("socket receive failed\n");
        return -3;
    }
    printf("output message:%s\n", revBuf);

    ret = cltSocketDestory(handler);
    if (ret != 0) {
        printf("socket destory failed\n");
        return -4;
    }


    return 0;
}