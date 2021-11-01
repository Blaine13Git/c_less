//
// Created by muyi on 2021/11/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *char_ptr;
    int *int_ptr;
    int mem_size;

    if (argc < 2)
        mem_size = 50;
    else
        mem_size = atoi(argv[1]); // ASCI码转换成int

    printf("[+] allocating %d bytes of memory on the heap for char_ptr\n", mem_size);
    char_ptr = (char *) malloc(mem_size);

    if (char_ptr == NULL) {
        fprintf(stderr, "Error-1: could not allocate heap memory.\n");
        exit(-1);
    }

    strcpy(char_ptr, "This is memory is located on the heap.");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

    //------------
    puts("[+] allocating 12 bytes of memory on the heap for int_ptr");
    int_ptr = (int *) malloc(12);

    if (int_ptr == NULL) {
        fprintf(stderr, "Error-2: could not allocate heap memory.\n");
        exit(-1);
    }

    *int_ptr = 31337;
    printf("int_ptr (%p) --> %d\n", int_ptr, *int_ptr);

    puts("[-] freeing char_ptr's heap memory...");
    free(char_ptr);

    puts("[+] allocating another 15 bytes for char_ptr");
    char_ptr = (char *) malloc(15);

    if (char_ptr == NULL) {
        fprintf(stderr, "Error-3: could not allocate heap memory.\n");
        exit(-1);
    }

    strcpy(char_ptr, "new memory");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

    puts("[-] freeing int_ptr's heap memory");
    free(int_ptr);

    puts("[-] freeing char_ptr's heap memory...");
    free(char_ptr);

    return 0;
}