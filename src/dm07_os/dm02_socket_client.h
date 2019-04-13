//
// Created by bruce on 2019-04-13.
//

#ifndef CBASIC_MD02_SOCKET_CLIENT_H
#define CBASIC_MD02_SOCKET_CLIENT_H

int cltSocketInit(void **handler);

int cltSocketSend(void *handler, const char *buf, int len);

int cltSocketRev(void *handler, char *revBuf, int *revLen);

int cltSocketDestory(void *handler);

//第二套接口函数
int cltSocketInit2(void **handler);

int cltSocketSend2(void *handler, const char *buf, int len);

int cltSocketRev2(void *handler, char **revBuf, int *revLen);

int cltSocketRev2Free(char **revBuf);

int cltSocketDestory2(void **handler);

#endif //CBASIC_MD02_SOCKET_CLIENT_H
