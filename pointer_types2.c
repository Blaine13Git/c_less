#include <stdio.h>

// 指针运算
int main() {
    int i;
    int int_array[5] = {1, 2, 3, 4, 5};
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};

    int *int_pointer;
    char *char_pointer;

    // 指针指向不兼容的谁类型，编译器会警告，依然可以编译通过，程序运行可能产生无法预料的结果。
    int_pointer = char_array;
    char_pointer = int_array;

    for (i = 0; i < 5; i++) {
        printf("[integer pointer] points to %p,witch contains the integer %d\n", int_pointer, *int_pointer);
        int_pointer = int_pointer + 1;
    }

    for (i = 0; i < 5; i++) {
        printf("[char pointer] points to %p,witch contains the char %c\n", char_pointer, *char_pointer);
        char_pointer = char_pointer + 1;
    }
}
