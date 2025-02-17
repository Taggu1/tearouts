

#include <stdio.h>

#include "utils.h"
#include "database.h"

void run_app(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    init_database("database.txt"); // init database
    run_app(argc, argv);
}


void run_app(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (equal_strings(argv[i], "add")) {
            add_workout();
        }
    }

}