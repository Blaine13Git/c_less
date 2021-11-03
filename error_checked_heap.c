//
// Created by muyi on 2021/11/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *error_checked_malloc(unsigned int size);

int main(int argc, char *argv[]) {
    char *char_ptr;
    int *int_ptr;
    int mem_size;

    if (argc < 2)
        mem_size = 50;
    else
        mem_size = atoi(argv[1]); // ASCI码转换成int

    printf("[+] allocating %d bytes of memory on the heap for char_ptr\n", mem_size);
    char_ptr = (char *) error_checked_malloc(mem_size);

    strcpy(char_ptr, "This is memory is located on the heap.");
    printf("\tchar_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

    //------------
    puts("[+] allocating 12 bytes of memory on the heap for int_ptr");
    int_ptr = (int *) error_checked_malloc(12);

    *int_ptr = 31337;
    printf("\tint_ptr (%p) --> %d\n", int_ptr, *int_ptr);

    puts("[-] freeing char_ptr's heap memory...");
    free(char_ptr);

    puts("[+] allocating another 15 bytes for char_ptr");
    char_ptr = (char *) error_checked_malloc(15);

    strcpy(char_ptr, "new memory");
    printf("\tchar_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

    puts("[-] freeing int_ptr's heap memory");
    free(int_ptr);

    puts("[-] freeing char_ptr's heap memory...");
    free(char_ptr);

    return 0;
}

void *error_checked_malloc(unsigned int size) {
    void *ptr;
    ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Error: could not allocate %d heap memory.\n", size);
        exit(-1);
    }
}