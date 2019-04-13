//
// Created by bruce on 2019-04-13.
//

#ifndef CBASIC_MD02_SOCKET_CLIENT_H
#define CBASIC_MD02_SOCKET_CLIENT_H

int cltSocketInit(void **handler);

int cltSocketSend(void *handler, const char *buf, int len);

int cltSocketRev(void *handler, char *revBuf, int *revLen);

int cltSocketDestory(void *handler);

#endif //CBASIC_MD02_SOCKET_CLIENT_H
