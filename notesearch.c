//
// Created by kali on 11/5/21.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "hacking.h"

#define FILENAME "/home/kali/Work/c_programs/c_lesson/data"

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

    return 0;
}


int print_notes(int fd, int uid, char *search_string) {
    int note_length;
    char byte = 0, note_buffer[100];

    note_length = find_user_note(fd, uid);

    // if end of file reached,return 0
    if (note_length == -1)
        return 0;

    read(fd, note_buffer, note_length); // read note data
    note_buffer[note_length] = 0; // terminate the string

    if (search_note(note_buffer, search_string))
        printf(note_buffer);

    return 1;
}

int find_user_note(int fd, int uid) {
    int note_uid = -1;
    unsigned char byte;
    int length;

    while (note_uid != uid) {
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
    int keyword_length, match = 0;
    if (keyword_length == 0)
        return 1;

    for (int i = 0; i < strlen(note); i++) {
        if (note[i] == keyword[match])
            match++;
        else {
            if (note[i] == keyword[0])
                match = 1;
            else
                match = 0; // otherwise it is 0
        }
        if (match == keyword_length) // if there is a full match
            return 1; // return matched
    }
    return 0; // return not matched
}



