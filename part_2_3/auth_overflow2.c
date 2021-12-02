//
// Created by muyi on 2021/11/16.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_authentication(char *password) {
    char password_buffer[16];
    int auth_flag = 0;

    strcpy(password_buffer, password);

    if (strcmp(password_buffer, "brillig") == 0) auth_flag = 1;
    if (strcmp(password_buffer, "outgrabe") == 0) auth_flag = 1;

    return auth_flag;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:%s <password>\n", argv[0]);
        exit(0);
    }

    puts("===========================");

    if (check_authentication(argv[1])) {
        puts("Access Granted.");
    } else {
        puts("Access Denied.");
    }
}

