#include <stdio.h>
#include <string.h>

int main() {
    int a = 7;
    int *aPtr = &a;

    printf("The address of a is %p\n", &a);
    printf("The value of aPtr is %p\n", aPtr);

    puts("===================");

    printf("The value of a is %d\n", a);
    printf("The value of *aPtr is %d\n", *aPtr);

    puts("===================");

    // & 和 *运算是互补的，不论着两个运算符以何种顺序连续出现，结果都是相同的
    printf("&*aPtr = %p\n", &*aPtr);
    printf("*&aPtr = %p\n", *&aPtr);
    return 0;
}
