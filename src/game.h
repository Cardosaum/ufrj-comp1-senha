#ifndef GAME_H
#define GAME_H
#include "defs.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/**
 * Generates the secret password for the game.
 */
Password generate_password();

/**
 * Gets and validates the player's input password.
 */
void input_password();

/**
 * Checks the player's input password against the secret password.  
 */
int check_password();

/**
 * Check if the player still have any tries in the current game.
 */
void check_tries();

/**
 * Finishes the game.
 */
void finish_game();

#endif


