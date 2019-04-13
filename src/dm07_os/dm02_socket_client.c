//
// Created by bruce on 2019-04-13.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dm02_socket_client.h"

//动态库内部数据类型
typedef struct ScmHandler {
    char ip[128];
    int port;
    unsigned char *p;
    int pLen;
    char version[64];
} ScmHandler;


int cltSocketInit(void **handler) {
    //必须用gmalloc，否则会被自动释放
    ScmHandler *scmHandler = (ScmHandler *) malloc(sizeof(ScmHandler));
    if (scmHandler == NULL) {
        printf("malloc handler failed\n");
        return -1;
    }

    memset(scmHandler, 0, sizeof(ScmHandler));

    strcpy(scmHandler->ip, "192.168.0.1");
    scmHandler->port = 7001;

    *handler = scmHandler;
    return 0;
}

int cltSocketSend(void *handler, const char *buf, int len) {
    if (handler == NULL || buf == NULL) {
        printf("cltSocketSend handler == NULL || buf == NULL\n");
        return -1;
    }

    ScmHandler *scmHandler = (ScmHandler *) handler;
    scmHandler->p = (unsigned char *) malloc(sizeof(unsigned char *) * len);
    if (scmHandler->p == NULL) {
        printf("cltSocketSend malloc handler p failed\n");
        return -2;
    }

    memcpy(scmHandler->p, buf, len);
    scmHandler->pLen = len;

    return 0;
}

int cltSocketRev(void *handler, char *revBuf, int *revLen) {
    if (handler == NULL || revBuf == NULL || revLen == NULL) {
        printf("cltSocketRev handler == NULL || buf == NULL || revLen == NULL\n");
        return -1;
    }
    ScmHandler *scmHandler = (ScmHandler *) handler;
    memcpy(revBuf, scmHandler->p, scmHandler->pLen);
    *revLen = scmHandler->pLen;
    return 0;
}

int cltSocketDestory(void *handler) {
    if (handler == NULL) {
        printf("cltSocketDestory handler == NULL\n");
        return -1;
    }
    ScmHandler *scmHandler = (ScmHandler *) handler;
    if (scmHandler->p) {
        free(scmHandler->p);
    }
    if (scmHandler) {
        free(scmHandler);
    }
    return 0;
}