
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef struct {
    int num_of_reps;
} Set;


typedef struct {
    char *name;
    int num_of_sets;
    Set sets[];
} Exercise;

typedef struct {
    int num_of_exercises;
    Exercise *exercises;
} Workout;



void add_exercise(Workout *user_workout, int index);


void add_workout() {
    int num_of_exercises;
    puts("Enter number of exercises: ");
    num_of_exercises = read_int();

    Exercise *exercises = malloc(sizeof(Exercise) * num_of_exercises);

    Workout user_workout = {
        .num_of_exercises = num_of_exercises,
        .exercises = exercises,
    };

    for (int i = 0; i < user_workout.num_of_exercises; i++) {
        add_exercise(&user_workout, i);
    }

}

void add_exercise(Workout *user_workout, int index) {
    char *excersie_name;
    puts("1. Enter exercise name: ");
    excersie_name = read_string();
    puts(excersie_name);

}