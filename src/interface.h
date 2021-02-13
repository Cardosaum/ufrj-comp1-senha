#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

/**
 * Show the menu options for the game.
 */
void show_menu();

/**
 * Gets the player menu input.
 */
void choose_menu_option();

/**
 * Show the entire board of the current game.
 */
void show_board();

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



