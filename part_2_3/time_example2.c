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
    for (i = 0; i < size; i++) {
        printf("%02x ", raw_ptr[i]);

        if (i % 16 == 15) { // print a new line every 16 bytes.
            puts("");
        }
    }
    puts("");
}

int main() {
    long int seconds_since_epoch;
    struct tm current_time, *time_ptr;
    int hour, minute, second, day, month, year, i, *int_ptr;

    seconds_since_epoch = time(0); // 给时间传输一个空指针作为参数
    printf("time() - seconds since epoch:1%d\n", seconds_since_epoch);

    time_ptr = &current_time;

    localtime_r(&seconds_since_epoch, time_ptr);

    // 三种方式从结构体种获取元素
    hour = current_time.tm_hour; // 直接接收
    minute = time_ptr->tm_min; // 通过指针接收
    second = *((int *) time_ptr); // hacky point access

    printf("Current time is:%02d:%02d:%02d\n", hour, minute, second);

    dump_time_struct_bytes(time_ptr, sizeof(struct tm));

    minute = hour = 0; //clear out minute and hour
    int_ptr = (int *) time_ptr;
    for (i = 0; i < 3; i++) {
        printf("int_ptr @ 0x%08x : %d\n", int_ptr, *int_ptr);
        int_ptr++;
    }
}