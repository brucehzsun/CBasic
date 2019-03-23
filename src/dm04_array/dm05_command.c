//
// Created by bruce on 2019-03-23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[], char **env) {
    printf("=========== begin argv ============\n");
    for (int i = 0; i < argc; i++) {
        printf("index of argv %d : %s\n", i, argv[i]);
    }

    printf("=========== begin env ============\n");
    for (int i = 0; env[i] != NULL; i++) {
        printf("index of env %d : %s\n", i, env[i]);
    }
}