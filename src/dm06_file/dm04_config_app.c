//
// Created by bruce on 2019-04-02.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dm04_config.h"

#define CONFIG_FILE_NAME "../data/config.ini"

void menu() {
    printf("============================\n");
    printf("1 写配置文件\n");
    printf("2 读配置文件\n");
    printf("0 退出\n");
    printf("============================\n");
}

void testWriteConfig() {
    char key[32] = {0};
    char value[32] = {0};
    printf("写配置文件，请输入key:");
    scanf("%s", key);
    printf("\n请输入value:");
    scanf("%s", value);
    int ret = setConfigItem(CONFIG_FILE_NAME, key, value, strlen(value));
    if (ret != 0) {
        printf("setConfigItem error, ret:%d\n", ret);
    } else {
        printf("key:%s value:%s\n", key, value);
    }
}

void testReadConfig() {
    char key[32] = {0};
    char value[32] = {0};
    int len = 0;
    printf("读配置文件，请输入key:");
    scanf("%s", key);
    int ret = getConfigItem(CONFIG_FILE_NAME, key, value, &len);
    if (ret != 0) {
        printf("setConfigItem error, ret:%d\n", ret);
    } else {
        printf("key:%s value:%s\n", key, value);
    }
}

int main() {

    int choice = 0;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                testWriteConfig();
                break;
            case 2:
                testReadConfig();
                break;
            case 0:
                exit(0);
            default:
                break;
        }
    }
    return 0;
}