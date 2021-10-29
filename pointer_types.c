#include <stdio.h>

// 指针运算
int main() {
    int i;
    int int_array[5] = {1, 2, 3, 4, 5};
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};

    int *int_pointer;
    char *char_pointer;

    int_pointer = int_array;
    char_pointer = char_array;

    for (i = 0; i < 5; i++) {
        printf("[integer pointer] points to %p,witch contains the integer %d\n", int_pointer, *int_pointer);
        int_pointer = int_pointer + 1; //int类型指针+1，增加4个字节
    }

    for (i = 0; i < 5; i++) {
        printf("[char pointer] points to %p,witch contains the char '%c'\n", char_pointer, *char_pointer);
        char_pointer = char_pointer + 1; //char类型指针+1，增加1个字节
    }
}
