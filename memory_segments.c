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
    puts("in data segment:");
    printf("\tglobal_initialized_var @ 0x%08x\n", &global_initialized_var);
    printf("\tstatic_initialized_var @ 0x%08x\n", &static_initialized_var);

    // in bss segment
    puts("in bss segment:");
    printf("\tglobal_var @ 0x%08x\n", &global_var);
    printf("\tstatic_var @ 0x%08x\n", &static_var);

    // in heap segment
    puts("in heap segment:");
    printf("\theap_var_ptr @ 0x%08x\n", heap_var_ptr);

    // in stack segment
    puts("in stack segment:");
    printf("\tstack_0x @ var%08x\n", &stack_var);
    function();

    return 0;
}

/*
 *
in data segment:
	global_initialized_var @ 0x24ff2040
	static_initialized_var @ 0x24ff2044
in bss segment:
	global_var @ 0x24ff204c
	static_var @ 0x24ff2050
in heap segment:
	heap_var_ptr @ 0x267212a0
in stack segment:
	stack_var @ 0xc6039b94
	the function's stack_var is at address 0xc6039b7c
 */