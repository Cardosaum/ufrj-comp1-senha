#ifndef GAME_H
#define GAME_H
#include "defs.h"
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Generates the secret password for the game.
 */
Password generate_password();

/**
 * Gets and validates the player's input password.
 */
bool input_password(Guess *player_guess, Board game_board);

/**
 * Checks the player's input password against the secret password.  
 */
bool check_password(const char *password);

/**
 * Check if the player still have any tries in the current game. Returns true if the player still have tries. If not, false.
 */
bool check_tries();

/**
 * Initialize all the default values for the game.
 */
void initialize_board(Board *game_board);

/**
 * Starts the game.
 */
int start_game();

/**
 * Finishes the game.
 */
int finish_game(Board board);

#endif


