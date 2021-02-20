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
bool input_password();

/**
 * Checks the player's input password against the secret password.  
 */
bool check_password(const char *password);

/**
 * Check if the player still have any tries in the current game. Returns true if the player still have tries. If not, false.
 */
bool check_tries();

/**
 * Starts the game.
 */
void start_game();

/**
 * Finishes the game.
 */
void finish_game();

#endif


