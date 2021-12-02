//
// Created by muyi on 2021/11/9.
//

#include <stdio.h>
#include <time.h>

int main() {
    long int seconds_since_epoch;
    struct tm current_time, *time_ptr;
    int hour, minute, second, day, month, year;

    seconds_since_epoch = time(0);
    printf("time() - seconds since epoch:1%d\n", seconds_since_epoch);

    time_ptr = &current_time;

    localtime_r(&seconds_since_epoch, time_ptr);

    // 三种方式从结构体种获取元素
    hour = current_time.tm_hour; // 直接接收
    minute = time_ptr->tm_min; // 通过指针接收
    second = *((int *) time_ptr); // hacky point access

    printf("Current time is:%02d:%02d:%02d\n", hour, minute, second);

}