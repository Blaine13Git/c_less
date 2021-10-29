//
// Created by muyi on 2021/10/26.
// 指针被定义为指向某种类型的数据，而不是定义成一个这种类型的变量。
//

#include <stdio.h>
#include <string.h>

int main() {
    char str_a[20];

    char *pointer;
    char *pointer2;

    strcpy(str_a, "Hello,world!\n");

    pointer = str_a; // 设置该指针指向字符数组str_a内存地址的开头
    printf("pointer is: %s", pointer);

    pointer2 = pointer + 2;
    printf("pointer2 is: %s", pointer2);

    strcpy(pointer2, "y you!\n");
    printf(pointer);
    return 0;
}
