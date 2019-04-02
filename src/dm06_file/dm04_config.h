//
// Created by bruce on 2019-04-02.
//

#ifndef CBASIC_DM04_CONFIG_H
#define CBASIC_DM04_CONFIG_H

int setConfigItem(const char *filename, const char *key, const char *value, const int len);

int getConfigItem(const char *filename, const char *key, const char *value, int *len);

#endif //CBASIC_DM04_CONFIG_H
