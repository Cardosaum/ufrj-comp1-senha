#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

/* Code for terminal colors */
#define KNIL "\x1B[0m"  /* NULL    */
#define KRED "\x1B[31m" /* Red     */
#define KGRN "\x1B[32m" /* Green   */
#define KYEL "\x1B[33m" /* Yellow  */
#define KBLU "\x1B[34m" /* Blue    */
#define KMAG "\x1B[35m" /* Magento */
#define KCYN "\x1B[36m" /* Cyan    */
#define KWHT "\x1B[37m" /* White   */

/**
 * Show the menu options for the game.
 */
void show_menu();

/**
 * Gets the player menu input.
 */
int choose_menu_option();

/**
 * Show the entire board of the current game.
 */
void show_board(Board board);

/**
 * Show the instructions. How to play the game.
 */
void show_instructions();

/**
 * Finishes the game and closes the program.
 */
void exit_game();

/**
 * Clear the entire screen.
 */
void clear_screen();

/**
 * Prints the ASCII Mastermind game art.
 */
void print_logo();

#endif
