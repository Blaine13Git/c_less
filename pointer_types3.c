#include <stdio.h>

// 指针运算
int main() {
    int i;
    int int_array[5] = {1, 2, 3, 4, 5};
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};

    int *int_pointer;
    char *char_pointer;

    // 对指针进行初始设置时，数据被强制转换为指针的数据类型
    int_pointer = (int *) char_array;
    char_pointer = (char *) int_array;

    for (i = 0; i < 5; i++) {
        printf("[integer pointer] points to %p,witch contains the integer %d\n", int_pointer, *int_pointer);
        int_pointer = (int *) ((char *) int_pointer + 1;)
    }

    for (i = 0; i < 5; i++) {
        printf("[char pointer] points to %p,witch contains the char %c\n", char_pointer, *char_pointer);
        char_pointer = (char *) ((int *) char_pointer + 1;)
    }
}
