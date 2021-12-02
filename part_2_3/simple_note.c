//
// Created by muyi on 2021/11/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <libc.h>

void usage(char *prog_name, char *filename) {
    printf("Usage: %s <data to add to %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char *message); // fatal(致命的)
void *ec_malloc(unsigned int); // error check malloc

int main(int argc, char *argv[]) {
    int fd;// 文件描述符
    char *buffer, *datafile;

    buffer = ec_malloc(100);
    datafile = ec_malloc(20);

    strcpy(datafile, "/Users/muyi/CLionProjects/c_lesson/data");

    if (argc < 2)
        usage(argv[0], datafile);

    strcpy(buffer, argv[1]); // copy into buffer

    printf("[DEBUG] buffer @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    strncat(buffer, "\n", 1);// add a newline on the end

    // open file
    fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
        fatal("in main() while opening file");
    printf("[DEBUG] file descriptor is %d\n", fd);

    // write file
    if (write(fd, buffer, strlen(buffer)) == -1)
        fatal("in main() while writing buffer file\n");

    // close file
    if (close(fd) == -1)
        fatal("in main() while closing file");

    puts("Note has been saved!");
    free(buffer);
    free(datafile);
}

void fatal(char *message) {
    char error_message[100];

    strcpy(error_message, "[!!] Fatal error");
    strncat(error_message, message, 83);
    perror(error_message); // print error 的缩写，可在退出前打印辅助错误信息
    exit(-1);
}

void *ec_malloc(unsigned int size) {
    void *ptr;
    ptr = malloc(size);

    if (ptr == NULL) {
        fatal("in ec_malloc on memory allocation");
    }
    return ptr;
}