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

    int after_game_decision = 0;
    int game_loop = 1;
    int display_menu = 0;
    
    /* Initialize the seed for rand function */
    srand(time(NULL)); /* Should be called ONCE per program. */

    while(game_loop){

        clear_screen();
        
        if(display_menu == 1){
            
            display_menu = 0;
            print_logo();
            show_menu();
        }

        after_game_decision = start_game();
        switch(after_game_decision){

            case 1:
                break;

            case 2:
                display_menu = 1;
                break;

            case 3:
                game_loop = 0;
                break;

            default:
                printf("UNEXPECTED ERROR HAPPENED AT start_game().\n\n");
        }
    }

    printf("Goodbye! See you soon!.\n\n");
    /* printf("Press any key to exit...\n\n"); */

    return 0;
}



