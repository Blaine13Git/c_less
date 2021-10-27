//
// Created by muyi on 2021/10/26.
//

#include <stdio.h>
#include <string.h>

int main() {
    char message[20];
    int count, i;

    strcpy(message, "Hello,world！");

    puts("Repeat how many times?");

    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("%1d - %s\n", i, message);
    }
}
