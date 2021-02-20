#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Password {
    int password[4];
} Password;

typedef struct Guess {
    Password player_password;
    int feedback[4];
} Guess;

typedef struct Board {
    Guess rounds[8];
    Password password;
} Board;

#endif
