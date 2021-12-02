//
// Created by muyi on 2021/10/26.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    unsigned int seed;

    puts("Enter seed:");
    scanf("%u", &seed);

    srand(seed);

    for (unsigned int i = 1; i <= 10; ++i) {
        printf("%10d", 1 + (rand() % 6));

        if (i % 5 == 0) {
            puts("");
        }
    }
}
