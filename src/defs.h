#ifndef DEFS_H
#define DEFS_H

#define PL 4                   /* This is the actual length we expect the user to input.   */
                               /* But as we use strlen to calculate the len of the string, */
                               /* we need to add 1 to it's value because strlen expects a  */
                               /* null-terminated string.                                  */
#define PASSWORD_LENGTH PL + 1 /* Thus the "plus one" here. */

#define OPTION_LENGTH 100

#define COLORS "RGYBMC" /* Red, Green, Yellow, Blue, Magento, Cyan */
#define COLORS_LENGTH 6

#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct Password {
    char password[PASSWORD_LENGTH];
} Password;

typedef struct Guess {
    Password player_password;
    int feedback[4];
    bool feedback_given;
} Guess;

typedef struct Board {
    Guess rounds[BOARD_SIZE];
    Password password;
    int tried;
    int won;
} Board;

#endif
