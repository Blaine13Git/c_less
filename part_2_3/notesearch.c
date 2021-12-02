#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "hacking.h"

#define FILENAME "/Users/muyi/CLionProjects/c_lesson/data_new"

int print_notes(int, int, char *);

int find_user_note(int, int);

int search_note(char *, char *);

void fatal(char *);

int main(int argc, char *argv[]) {
    int userid, printing = 1, fd;
    char search_string[100];

    if (argc > 1)
        strcpy(search_string, argv[1]);
    else
        search_string[0] = 0;

    userid = getuid();
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1)
        fatal("in main() while opening file for reading");

    while (printing)
        printing = print_notes(fd, userid, search_string);

    printf("------[end of note data]-------");

    close(fd);
}


int print_notes(int fd, int uid, char *search_string) {
    int note_length;
    char byte = 0, note_buffer[100];

    note_length = find_user_note(fd, uid);
    if (note_length == -1)// if end of file reached,return 0
        return 0;

    read(fd, note_buffer, note_length); // read note data
    note_buffer[note_length] = 0; // terminate the string

    if (search_note(note_buffer, search_string))
        puts(note_buffer);

    return 1;
}

int find_user_note(int fd, int user_uid) {
    int note_uid = -1;
    unsigned char byte;
    int length;

    while (note_uid != user_uid) {
        if (read(fd, &note_uid, 4) != 4)
            return -1;

        if (read(fd, &byte, 1) != 1)
            return -1;

        byte = length = 0;
        while (byte != '\n') {
            if (read(fd, &byte, 1) != 1)
                return -1;
            length++;
        }
    }

    lseek(fd, length * -1, SEEK_CUR);

    printf("[DEBUG] found a %d byte note for user id %d\n", length, note_uid);
    return length;

}

int search_note(char *note, char *keyword) {
    int i, keyword_length, match = 0;

    keyword_length = strlen(keyword);
    if (keyword_length == 0) // if there is no search string
        return 1; // always match

    for (i = 0; i < strlen(note); i++) {
        if (note[i] == keyword[match]) // if byte matches keyword
            match++; // get ready to check the next byte
        else {
            if (note[i] == keyword[0]) // if that byte matches first keyword byte
                match = 1; // start the match count at 1
            else
                match = 0; // otherwise it is 0
        }
        if (match == keyword_length) // if there is a full match
            return 1; // return matched
    }
    return 0; // return not matched
}



