//
// Created by kali on 11/12/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_authentication(char *passwd) {
    char passwd_buffer[16];
    int auth_flag = 0;

    strcpy(passwd_buffer, passwd);

    if (strcmp(passwd_buffer, "brillig") == 0)
        auth_flag = 1;

    if (strcmp(passwd_buffer, "outgrabe") == 0)
        auth_flag = 1;

    return auth_flag;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <passwd>\n", argv[0]);
        exit(0);
    }

    puts("=============================");

    if (check_authentication(argv[1])) {
        puts("Access Granted");
    } else {
        puts("Access Denied");
    }

}