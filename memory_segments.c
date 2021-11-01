//
// Created by muyi on 2021/11/1.
//
#include <stdio.h>
#include <stdlib.h>

int global_var;
int global_initialized_var = 5;

void function() {
    int stack_var;
    printf("the function's stack_var is at address 0x%08x\n", &stack_var);
}

int main() {
    int stack_var;
    static int static_initialized_var = 6;
    static int static_var;
    int *heap_var_ptr;

    heap_var_ptr = (int *) malloc(4);

    // in data segment
    printf("global_initialized_var @ 0x%08x\n", &global_initialized_var);
    printf("static_initialized_var @ 0x%08x\n", &static_initialized_var);

    // in bss segment
    printf("global_var @ 0x%08x\n", &global_var);
    printf("static_var @ 0x%08x\n", &static_var);

    // in heap
    printf("heap_var_ptr @ 0x%08x\n", heap_var_ptr);

    // in stack segment
    printf("static_var @ 0x%08x\n", &stack_var);
}
