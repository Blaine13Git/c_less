#include <stdio.h>

// void pointer 无类型指针，实际上是存储一个内存地址。
int main() {
    int i;
    int int_array[5] = {1, 2, 3, 4, 5};
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};

    void *void_pointer;

    // 强转成无类型指针
    void_pointer = (void *) int_array;

    for (i = 0; i < 5; i++) {
        printf("[void pointer] points to %p,witch contains the integer %d\n", void_pointer, *((int *) void_pointer));
        void_pointer = (void *) ((int *) void_pointer + 1);
    }

    // 强转成无类型指针
    void_pointer = (void *) char_array;

      for (i = 0; i < 5; i++) {
        printf("[void pointer] points to %p,witch contains the char '%c'\n", void_pointer, *((char *) void_pointer));
        void_pointer = (void *) ((char *) void_pointer + 1);
    }
}
