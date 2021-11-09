//
// Created by muyi on 2021/11/9.
//

#include <stdio.h>
#include <time.h>

void dump_time_struct_bytes(struct tm *time_ptr, int size) {
    int i;
    unsigned char *raw_ptr;
    printf("bytes of struct located at 0x%08x\n", time_ptr);

    raw_ptr = (unsigned char *) time_ptr;
}

int main() {


}