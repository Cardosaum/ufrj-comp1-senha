#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Guess {
    int player_guess[4];
    int feedback[4];
} Guess;

typedef struct Password {
    int password[4];
} Password;

typedef struct Board {
    Guess rounds[8];
    Password password;
} Board;

#endif