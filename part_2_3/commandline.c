#include <stdio.h>
#include <string.h>
/**
 * 访问命令行参数
 * @param count
 * @param arg_list
 * @return
 */

// 第一个参数，整数 arg_count 表示参数个数
// 第二个参数，arg_list[] 字符串数组指针，字符串数组包含所有参数
int main(int arg_count, char *arg_list[]) {
    printf("there were %d arguments provided:\n", arg_count);

    for (int i = 0; i < arg_count; i++) {
        printf("argument #%d - %s\n", i, arg_list[i]);
    }
}
