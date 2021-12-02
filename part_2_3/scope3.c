//
// Created by muyi on 2021/10/29.
//

#include <stdio.h>

void func3();

void func2();

void func1();

int j = 42;

int main() {
    int i = 3;
    printf("[in main] i @ 0x%08x = %d\n", &i, i);
    printf("[in main] j @ 0x%08x = %d\n", &i, j);
    func1();
    printf("[back in main] i @ 0x%08x = %d\n", &i, i);
    printf("[back in main] j @ 0x%08x = %d\n", &i, i);
}

void func3() {
    int i = 11;
    j = 999;
    printf("[in func3] i = %d,j = %d\n", i, j);
}

void func2() {
    int i = 7;
    printf("[in func2] i= %d\n", i);
    func3();
    printf("[back in func2] i = %d\n", i);
}

void func1() {
    int i = 7;
    printf("[in func1] i= %d\n", i);
    func2();
    printf("[back in func1] i = %d\n", i);
}