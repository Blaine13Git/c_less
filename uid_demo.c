//
// Created by muyi on 2021/11/3.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    printf("real uid: %d\n", getuid());
    printf("effective uid: %d\n", geteuid());

    return 0;
}
