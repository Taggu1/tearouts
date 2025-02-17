
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

#define MAX_DIGITS 100
#define MAX_CHARACTERS 1000


int power(int num, int pow);

void init_database(const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        fp = fopen("database.txt", "w");
    }

    fclose(fp);
}

bool equal_strings(char *str1, char *str2) {
    if (strcmp(str1, str2) == 0) {
        return true;
    } else {
        return false;
    }
}



int read_int() {
    int number = 0;
    int digits[MAX_DIGITS];
    int count = 0;
    int current_pow = 0;

    char ch;

    while ((ch = (char)getchar()) != '\n' && count != MAX_DIGITS) {
        if (isdigit(ch)) {
            digits[count++] = ch - '0';
        }
    }


    // Ignore the rest of the line
    if (count == MAX_DIGITS) while (getchar() != '\n');

    for (int i = count - 1; i >= 0; i--) {
        number += digits[i] * power(10, current_pow++);

    }


    return number;
}

char *read_string() {
    char ch;
    int count = 0;

    char *buffer = malloc(MAX_CHARACTERS);

    while ((ch = (char)getchar()) != '\n' && count != MAX_CHARACTERS) {
        buffer[count++] = ch;
    }

    // Ignore the rest of the line
    if (count == MAX_CHARACTERS) while (getchar() != '\n');
    buffer[count] = '\0';

    char *new_string = malloc(strlen(buffer));
    strcpy(new_string, buffer);
    free(buffer);

    return new_string;
}

int power(int num, int pow) {
    int final_num = 1;
    for (int i = 0; i < pow; i++) {
        final_num *= num;
    }
    return final_num;
}