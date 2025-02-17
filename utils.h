
#ifndef UTILS_H
#define UTILS_H


#include <stdio.h>
#include <stdbool.h>


void init_database(const char *filename);

bool equal_strings(char *str1, char *str2);
int read_int();
char *read_string();

#endif