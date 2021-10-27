#include <stdio.h>
// 强制类型转换
int main() {
    int a, b;
    float c, d;

    a = 13;
    b = 5;

    c = a / b;
    d = (float) a / (float) b;

    printf("c = %0.2f\n", c); // 2.00
    printf("d = %0.2f\n", d); // 2.60
}
