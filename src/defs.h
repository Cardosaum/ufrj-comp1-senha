#ifndef DEFS_H
#define DEFS_H

#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct Password {
    int password[4];
} Password;

typedef struct Guess {
    Password player_password;
    int feedback[4];
    bool feedback_given;
} Guess;

typedef struct Board {
    Guess rounds[BOARD_SIZE];
    Password password;
} Board;

#endif
