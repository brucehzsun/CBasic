//
// Created by bruce on 2019-03-27.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
    char name[64];
    int age;
    char *alias;
} Teacher;


int copyTeacher(Teacher *to, Teacher *from) {
//    *to = *from;
    memcpy(to, from, sizeof(Teacher));
    to->alias = (char *) malloc(100);
    strcpy(to->alias, from->alias);
    return 0;
}

int main() {

    Teacher t1;
    Teacher t2;

    strcpy(t1.name, "t1-name");
    t1.alias = (char *) malloc(100);
    if (t1.alias == NULL) {
        return -1;
    }
    strcpy(t1.alias, "t1-alias");

    copyTeacher(&t2, &t1);

    if (t1.alias != NULL) {
        free(t1.alias);
    }

    if (t2.alias != NULL) {
        free(t2.alias);
    }

}
