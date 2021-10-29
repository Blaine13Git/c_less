//
// Created by muyi on 2021/10/29.
//
#include <stdio.h>

void function();

int main() {
    int i;
    static int static_var = 1337;

    for (i = 0; i < 5; i++) {
        printf("[in main] static_var @ %p = %d\n", &static_var, static_var);
        function();
    }
}

void function() {
    int var = 5;
    static int static_var = 50;

    printf("[in function] var @ %p = %d\n", &var, var);
    printf("[in function] static_var @ %p = %d\n", &static_var, static_var);

    var++;
    static_var++;
}

/*
 * 留意内存地址：
 * 1、局部变量的内存地址不同于全局变量和静态变量
 * 2、局部变量的地址非常高，全局变量和静态变量地址非常低）
 * why？？
[in main] static_var @ 0x10cae6010 = 1337
[in function] var @ 0x7ffee312197c = 5
[in function] static_var @ 0x10cae6014 = 50
[in main] static_var @ 0x10cae6010 = 1337
[in function] var @ 0x7ffee312197c = 5
[in function] static_var @ 0x10cae6014 = 51
[in main] static_var @ 0x10cae6010 = 1337
[in function] var @ 0x7ffee312197c = 5
[in function] static_var @ 0x10cae6014 = 52
[in main] static_var @ 0x10cae6010 = 1337
[in function] var @ 0x7ffee312197c = 5
[in function] static_var @ 0x10cae6014 = 53
[in main] static_var @ 0x10cae6010 = 1337
[in function] var @ 0x7ffee312197c = 5
[in function] static_var @ 0x10cae6014 = 54
 */