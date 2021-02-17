#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "defs.h"

void show_menu()
{
    printf("---------------------\n");
    printf("1. Play\n");
    printf("2. Instructions\n");
    printf("3. Configurations\n");
    printf("4. Exit\n");
    printf("---------------------\n");
}

void show_board(Board board)
{
    
}

void clear_screen()
{
    system("@cls||clear");
}

void print_logo()
{
    printf("___  ___  ___   _____ _____ ______________  ________ _   _______  \n");
    printf("|  \\/  | / _ \\ /  ___|_   _|  ___| ___ \\  \\/  |_   _| \\ | |  _  \\ \n");
    printf("| .  . |/ /_\\ \\ `--.  | | | |__ | |_/ / .  . | | | |  \\| | | | | \n");
    printf("| |\\/| ||  _  | `--. \\ | | |  __||    /| |\\/| | | | | . ` | | | | \n");
    printf("| |  | || | | |/\\__/ / | | | |___| |\\ \\| |  | |_| |_| |\\  | |/ /  \n");
    printf("\\_|  |_/\\_| |_/\\____/  \\_/ \\____/\\_| \\_\\_|  |_/\\___/\\_| \\_/___/   \n");
    printf("                                                                  \n");
}
