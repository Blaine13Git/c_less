//
// Created by muyi on 2021/10/26.
//

#include <stdio.h>
#include <string.h>

int main() {
    char str_a[20];

    strcpy(str_a, "Hello,world\n");

    printf("string is: %s\n", str_a);
    printf("str_a address is:%08x\n", str_a);
}
