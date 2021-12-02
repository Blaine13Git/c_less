#include <stdio.h>
#include "stdlib.h"

// 定义一个函数的原型 或者 声明一个函数
int square(int y); // 函数声明，函数头（返回值类型、函数名、行参列表）

// 程序入口
int main() {
    printf("Hello, World!\n");

    puts("OK~");

    for (int x = 1; x <= 10; ++x) {
        printf("%d\n", square(x));
    }

    puts("=======================");

    printf("随机数：%d\n", rand());
    printf("随机数10d：%10d\n", rand());

    for (unsigned int i = 1; i <= 20; ++i) {
        printf("%10d", 1 + (rand() % 6));

        if (i == 5) {
            puts("");
        }
    }

    return 0;
}

// 实现定义的方法
int square(int y) {
    return y * y;
}