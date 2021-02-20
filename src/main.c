/**
 * 
 * Senha
 * Autores: github.com/Albuquerque-David, github.com/Cardosaum, github.com/sunnyseth
 * Under Apache License Version 2.0, January 2004
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "interface.h"

int main(int argc, char *argv[]) {
    
    /* Initialize the seed for rand function */
    srand(time(NULL)); /* Should be called ONCE per program. */

    clear_screen();
    print_logo();
    show_menu();

    return 0;
}



