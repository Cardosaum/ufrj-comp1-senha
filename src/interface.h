#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "defs.h"

/* Code for terminal colors */
#define KNIL "\x1B[0m"  /* NULL    */
#define KBLK "\x1B[30m" /* Red     */
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
 * Prints the player guesses colored. 
 */
void print_guesses(char *guesses);

/**
 * Show the instructions. How to play the game.
 */
void show_instructions();

/**
 * Show the credits. Who are the ones responsibles
 * for this?
 */
void show_credits();

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

/**
 * Prints the ASCII Dart Vader art.
 */
void print_vader();

/**
 * Calculate how many White and Black pins
 * we need to show to user
 */
int calc_pins(char* player_password, char* game_password, char color);

/**
 * Calculate List Occurrence
 * Return how many times item is present in list
 */
int clo(char* list, int list_len, char item);

/**
 * Prints game win art.
 */
void print_win();

/**
 * Prints game lose art.
 */
void print_lose();

#endif
