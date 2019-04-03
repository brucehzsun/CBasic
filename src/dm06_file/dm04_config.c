//
// Created by bruce on 2019-04-02.
//

#include "dm04_config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define  LINE_MAX_SIZE 1024

int setConfigItem(const char *filename, const char *key, const char *value, const int len) {

    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("file open failed\n");
        fp = fopen(filename, "w+t");
        if (fp == NULL) {
            printf("file open failed 2\n");
            goto end;
        }
    }

    fseek(fp, 0, SEEK_END);
    long fileLen = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (fileLen > 1024 * 8) {
        printf("file too big\n");
        goto end;
    }

    int isChange = 0;
    char *tempP = NULL;
    char lineBuf[LINE_MAX_SIZE];
    char fileBuf[LINE_MAX_SIZE * 8];
    while (!feof(fp)) {

        memset(lineBuf, 0, sizeof(lineBuf));
        tempP = fgets(lineBuf, LINE_MAX_SIZE, fp);
        if (tempP == NULL) {
            break;
        }

        tempP = strstr(lineBuf, key);
        if (tempP == NULL) {
            //关键字不存在
            strcat(fileBuf, lineBuf);
            continue;
        } else {
            //关键词存在，替换
            sprintf(lineBuf, "%s = %s\n", key, value);
            strcat(fileBuf, lineBuf);
            isChange = 1;
        }
    }

    if (isChange == 0) {
        //关键词不存在，追加
        fprintf(fp, "%s = %s\n", key, value);
    } else {
        //关键词存在，从新创建文件
        if (fp != NULL) {
            fclose(fp);
            fp = NULL;
        }
        fp = fopen(filename, "w+t");
        if (fp == NULL) {
            goto end;
        }
        fputs(fileBuf, fp);
    }

    end:
    fclose(fp);
    return 0;
}

int getConfigItem(const char *filename, const char *key, const char *value, int *len) {

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    char lineBuf[LINE_MAX_SIZE];
    char *tempP = NULL;

    char *endP = NULL;
    char *startP = NULL;

    while (!feof(fp)) {
        memset(lineBuf, 0, sizeof(lineBuf));
        fgets(lineBuf, LINE_MAX_SIZE, fp);

        tempP = strstr(lineBuf, key);
        if (tempP == NULL) {
            continue;
        }

        tempP = strchr(lineBuf, '=');
        if (tempP == NULL) {
            continue;
        }
        tempP = tempP + 1;

        while (1) {
            if (*tempP == ' ') {
                tempP++;
            } else if (*tempP == '\n') {
                goto clearn;
            } else {
                startP = tempP;
                break;
            }
        }

        while (1) {
            if ((*tempP == ' ' || *tempP == '\n')) {
                endP = tempP;
                break;
            } else {
                tempP++;
            }
        }

        *len = (int) (endP - startP);
        memcpy(value, startP, endP - startP);
    }

    clearn:
    fclose(fp);
    return 0;
}
