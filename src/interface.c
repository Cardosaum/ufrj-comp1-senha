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
    int i,j;
    int w,b;

    if (board.tried == 0) {
        return;
    }

    printf("MASTER PASS: %s\n", board.password.password);
    printf("┌───────────┬──────┐\n");
    printf("│  Guesses  │ Hint │\n");
    printf("├───────────┼──────┤\n");
    for (i = 0; i < board.tried; i++) {
        printf("│");
        print_guesses(board.rounds[i].player_password.password);
        /*printf("   %s   ", board.rounds[i].player_password.password);*/
        printf(" │ ");
        w = calc_pins(board.rounds[i].player_password.password, board.password.password, 'W');
        b = calc_pins(board.rounds[i].player_password.password, board.password.password, 'B');
        for (j = 0; j < w; j++) {
            printf("%sW%s",KWHT,KNIL);
        }
        for (j = 0; j < b; j++) {
            printf("%sB%s",KBLK,KNIL);
        }
        for (j = 0; j < (PL-(w+b)); j++) {
            printf("-");
        }
        printf(" │");
        printf("\n");
    }
    printf("└───────────┴──────┘\n");
}

void print_guesses(char* guesses)
{
    int i;
    int count = 0;

    printf("   ");
    for(i = 0; i < PASSWORD_LENGTH - 1; i++){
        count++;
        switch (guesses[i])
        {
        case 'R':
            printf("%s%c%s",KRED,guesses[i],KNIL);
            break;

        case 'G':
            printf("%s%c%s",KGRN,guesses[i],KNIL);
            break;

        case 'Y':
            printf("%s%c%s",KYEL,guesses[i],KNIL);
            break;

        case 'B':
            printf("%s%c%s",KBLU,guesses[i],KNIL);
            break;

        case 'M':
            printf("%s%c%s",KMAG,guesses[i],KNIL);
            break;

        case 'C':
            printf("%s%c%s",KCYN,guesses[i],KNIL);
            break;
        
        default:
            break;
        }
    }
    printf("   ");
}

void clear_screen()
{
    system("@cls||clear");
}

int choose_menu_option()
{
    int option;
    char c;
    char whipeout_stdin;
    
    while(1){
        while ((whipeout_stdin = getchar()) != '\n' && whipeout_stdin != EOF){}
        printf("Which option will you choose? (1/2/3/4)\n");
        printf("> ");
        c = getchar();
        option = atoi(&c);
        if (option < 1 || option > 4 || ((c = getchar()) != '\n' && c != EOF)) {
            printf("There's something wrong! Can you type again?\n\n");
        } else {
            printf("You've chosen option %d.\n", option);
            break;
        }
    }
    
    return option;
}

void show_instructions()
{
    printf("MASTERMIND is code-breaking game.\n\n");
    printf("- The program itself will choose a password and the player has to guess it's sequence.\n\n");
    
    printf("- The player must break the code within the tries given. The player has eight (8) tries\n" 
                "and each one they has to choose four (4) colors in a total of six (6) available and try\n" 
                "to guess the password.\n\n");
            
    printf("- Each time the player tries to guess and fails, the number of right answers and the\n" 
                "number of tries left will appear on the screen.\n\n");
            
    printf("- The player loses the game if there are no more tries left.\n\n");
    
    printf("Available colors: r (red) | g (green) | y (yellow) | b (blue) | m (magento) | c (cyan)\n");
    printf("Example of entry: rbby\n");
};

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

int calc_pins(char* player_password, char* game_password, char color) {

    if (color != 'W' && color != 'B') {
        printf("\n\nError in calc_pins color parameter\n\n");
        exit(3);
    }

    int i,j;
    int w = 0;
    int b = 0;
    char added[PL] = {'\0'};

    for (i = 0; i < PL; i++) {
        if (player_password[i] == game_password[i]) {
            w++;
            added[i] = player_password[i];
        }
    }
    for (i = 0; i < PL; i++) {
        for (j = 0; j < PL; j++) {
            if (player_password[i] == game_password[j] && clo(added, PL, player_password[i]) < clo(game_password, PL, player_password[i])) {
                b++;
                added[i] = player_password[i];
            }
        }
    }

    if (color == 'W') {
        return w;
    } else {
        return b;
    }
}

int clo(char* list, int list_len, char item) {
    int i;
    int s = 0;
    for (i = 0; i < list_len; i++) {
        if (list[i] == item) {
            s++;
        }
    }
    return s;
}
