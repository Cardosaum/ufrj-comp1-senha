#include "interface.h"
#include "defs.h"

void show_menu()
{
    printf("---------------------\n");
    printf("1. Play\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
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
    int n = 0;
    int option;
    char c;
    char whipeout_stdin;
    
    while(1){
        if(n){while ((whipeout_stdin = getchar()) != '\n' && whipeout_stdin != EOF){}}
        n++;
        printf("Which option will you choose? (1/2/3)\n");
        printf("> ");
        c = getchar();
        option = atoi(&c);
        if (option < 1 || option > 3 || ((c = getchar()) != '\n' && c != EOF)) {
            printf("There's something wrong! Can you type again?\n\n");
        } else {
            /* printf("You've chosen option %d.\n", option); */
            break;
        }
    }
    
    return option;
}

void show_instructions()
{
    char whipeout_stdin;
    clear_screen();
    printf("MASTERMIND is a code-breaking game.\n\n");
    printf("- The program itself will choose a password and the player has to guess it's sequence.\n\n");
    
    printf("- The player must break the code within the tries given. The player has eight (8) tries\n" 
                "and each one they has to choose four (4) colors in a total of six (6) available and try\n" 
                "to guess the password.\n\n");
            
    printf("- Each time the player tries to guess and fails, the number of right answers and the\n" 
                "number of tries left will appear on the screen.\n\n");
            
    printf("- The player loses the game if there are no more tries left.\n\n");
    
    printf("Available colors: r (red) | g (green) | y (yellow) | b (blue) | m (magento) | c (cyan)\n");
    printf("Example of entry (input is case insensitive): rbby or RBBY\n");
    printf("\nPress <enter> to exit the Instructions page.\n");
    while ((whipeout_stdin = getchar()) != '\n' && whipeout_stdin != EOF){}
}

void print_logo()
{
    const char logo[] = {0x20, 0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x5f, 0x20, 0x20, 0x20, 0x5f, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0xa, 0x7c, 0x20, 0x20, 0x5c, 0x2f, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x2f, 0x5c, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x7c, 0x5f, 0x5f, 0x20, 0x20, 0x20, 0x5f, 0x5f, 0x7c, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x7c, 0x20, 0x20, 0x5f, 0x5f, 0x20, 0x5c, 0x7c, 0x20, 0x20, 0x5c, 0x2f, 0x20, 0x20, 0x7c, 0x5f, 0x20, 0x20, 0x20, 0x5f, 0x7c, 0x20, 0x5c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x5f, 0x5f, 0x20, 0x5c, 0x20, 0xa, 0x7c, 0x20, 0x5c, 0x20, 0x20, 0x2f, 0x20, 0x7c, 0x20, 0x20, 0x2f, 0x20, 0x20, 0x5c, 0x20, 0x20, 0x7c, 0x20, 0x28, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x5f, 0x5f, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x5f, 0x5f, 0x29, 0x20, 0x7c, 0x20, 0x5c, 0x20, 0x20, 0x2f, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x5c, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0xa, 0x7c, 0x20, 0x7c, 0x5c, 0x2f, 0x7c, 0x20, 0x7c, 0x20, 0x2f, 0x20, 0x2f, 0x5c, 0x20, 0x5c, 0x20, 0x20, 0x5c, 0x5f, 0x5f, 0x5f, 0x20, 0x5c, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x5f, 0x5f, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x5f, 0x20, 0x20, 0x2f, 0x7c, 0x20, 0x7c, 0x5c, 0x2f, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x2e, 0x20, 0x60, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0xa, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x2f, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x5c, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x29, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x5f, 0x5f, 0x5f, 0x5f, 0x7c, 0x20, 0x7c, 0x20, 0x5c, 0x20, 0x5c, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x7c, 0x5c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x5f, 0x5f, 0x7c, 0x20, 0x7c, 0xa, 0x7c, 0x5f, 0x7c, 0x20, 0x20, 0x7c, 0x5f, 0x2f, 0x5f, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x5f, 0x5c, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x2f, 0x20, 0x20, 0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x20, 0x7c, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x7c, 0x5f, 0x7c, 0x20, 0x20, 0x5c, 0x5f, 0x5c, 0x5f, 0x7c, 0x20, 0x20, 0x7c, 0x5f, 0x7c, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x7c, 0x5f, 0x7c, 0x20, 0x5c, 0x5f, 0x7c, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x2f, 0x20, 0xa, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xa, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xa, 0x0};
    printf("%s", logo);
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
        if (added[i] != '\0') {
            continue;
        }
        for (j = 0; j < PL; j++) {
            if (player_password[i] == game_password[j] &&
                clo(added, PL, player_password[i]) < clo(game_password, PL, player_password[i]) &&
                added[i] == '\0')
            {
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

void print_win(){

    printf("█████████████████████████████████████████████████████████████████████████████████\n");
    printf("███████████████▀▀▀▀,,,╔╔╔╔╔╔⌂,,╙▀▀▀▀████████████████████████████████████████████\n");
    printf("█████████▀▀╓▄▄╣╫╫M╩╩╨░░░░╫╫╫╫╫╫░╫╫╣╫ΦUÜ░▀▀██████████████████████████████████████\n");
    printf("███████▀ φ╣M\"`   .«]ÑÑÑ╫╫Ñ╫╫╫╬╬╬╬╬╬╬╬╣╫╣▓╗\"▀████████████████████████████████████\n");
    printf("██████▀ ╟▌Ñ    j░░]Ñ╫╫╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╫╫██H╙████████████████████████████████████\n");
    printf("██▀½╓æ╗«j╣▓▄▄g, ░º╚╚ÑÑ╬╬╬╬╬╬╬╬╬╬╫╫╫╫╦▄▓▓▓Ñj╔æ╦,▀▀███████████████████████████████\n");
    printf("╔╬M^╟▀░░╫╣╢╬████████▓▄███▓▓▓▓▓▓█████▌╬▓ÑÑ░╙MM╙╬Φr▐█████████████████████████████\n");
    printf("█Ü╓██▄`░╫╣▓▓████▓▌╫╫╬Ñ╫Ñ╫Ñ╫╫Ñ╫╫▓▓███▌▓▓MÑ`,▄█▄ ╫▌▐█████████████████████████████\n");
    printf("▓Ü▐███ ░╫╣▓▓▀M╣▄▌╫╬M░▄▄▄░░╙╚╬╬╬╣▓▄╨▀▌▓▓MÑ`▐███ ╫▌▐█████████████████████████████\n");
    printf("▓Ü▐███ ░╫╣▓╬▓D╫█▌M░╣██▓MÖ▄µ░░╚╬╫▓█D║╬▓▓MÑ`▐███ ╫▌▐█████████████████████████████\n");
    printf("╬D`▐██ ░╫╣▌▀╦╫██▌M░ñM▄▄H▀▄▀░╫U╙╢▓██▄╝╫▓MÑ`▐██░j╬H▐█████████████████████████████\n");
    printf("█µ╝NUÖφ⌂.j╣▌▓Ö▓██▌M░░]▀╝Ü╔φ╗╣▓M░║▓██▌╟╫▓M░:╔Ö;╔╫½▄████▀▀▀""""""▀▀▀██████████████\n");
    printf("███▄╙╟M░`j╫Ñ╗▀╫▓█▌╦░╚Ñ╫╫╣▓▓▓▀▀░╟▓██▌╣Ñ╬▀M`░╨╚M╙▄██▀▀░╥╗╣▓▓▓▓▓▓▓▓▄▄╦░▀███████████\n");
    printf("███████▄▄,╟╫╬N▓╫██▓╬╬╗░░░Ö░░╔╬╣▓▓█▓╫▌╬▓╬░ `▄███▀▀]╗▄▄▓████████████▓▓▓╣▀█████████\n");
    printf("██████████╦╟╫▓Ñ╗▌▀██▓╫╬╫╫╫╫╬╫╣▓██▀▄╗╫▓▌M «╗▄▄▄▄╗╣▓▓██████████████████▓▌╦▀███████\n");
    printf("███████████U╚╫▓▓D╣▀Ö▓▀▓▌╣╬▀▓▌╬▌▀╫╬╣▓▌M`╔╣▓█████████████████████████████▌╗²██████\n");
    printf("████████████▄,╚╬╬▀╣╫æ╙½╬M░╣╗╙╟╫╫M▀▓M` -▓▓████████████████████]▄▓██M▄▓███▓╗ ▀████\n");
    printf("███████████████▄²╚╩N╬╬╫▀╫╫▀▀╫╬MM╩º^▄█h╔▓▓████████████████████D╝▓██╗╩▀▓███▓╬H╙███\n");
    printf("██████████████████⌐-``\"\"\"\"\"\"\"`. ▄█████⌐Φ▓▓███████████████████╬ ║██╬ ╟▓███▓▓▓@╙██\n");
    printf("███████████████████▄▄ ╙╜╨╜╜ª^.▄▄███████▄`╜▀▓▓▓███████▓▓▓▓▓▓██▌╔║███,╣██▓▓▓▓▓█▄░ █\n");
    printf("██████████████▀▀▀▀▀███^ ╔╔« ▀███▀▀▀▀▀████▄,╓▓▓███████▓▓▓▓████████████████▓▓▓█▌Ü\n");
    printf("████████████M╗,░,j╗]` ╔U,,,╗, j╗],,,╔░████▌j▓▓████████████████╨░░░░`╨█████▓▓▓█▌\n");
    printf("████████████⌐]╬D╬╬░K` ║╫╫╬╬╫Ñ ]╬╣╫╬╬M ▐███▌¿╣▓▓▓██████████████φ]╫╫╫░╣█████▓╢╣▌M,\n");
    printf("████████████⌐]╬╬╬M ,j ╫Ñ╬╬╬╬H ⌂ ╙╫╬╬M ▐████▌/╢▓▓▓██████████████▌▄▄▄█████▓▓╬\"Ü^▄█\n");
    printf("███████████▀,ª╬╬╬╬Mªº ⌂`\"░``r ªª╣╬╬╬M.▀██████░╚╣▓▓██████████████████████▓╬░ ████\n");
    printf("██████████½║╬╬╔, ╔╓╗,*╙╝╬╬MÑ*^╔╔╓« «╗] ██████H *▀▓▓▓█████████████████▓▓▓M^, ▀███\n");
    printf("█████████▌j╟╫╫M,╬▓▓▓▓▄▄▄▄▄▄▄▄▄▓▓▓╬⌂\"╫Ü █████½j]░j░║▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌M░j╬ÑNr`▀█\n");
    printf("█████████▌j╙╢╫ ░]░╠░░\"░j░]░░░Ñj░]\"¼ ╬H ███▀`Ñ╬╬╬╬Ñ]░░░╙M╣╢╢▓▀▀▀▀▀▀▀M\"╔╬╬╬╣▄▄ß«\n");
    printf("█████████▌,▄M╟ ▌║Ü▓▓╫▓▌╫#▓#▓╫▌╬M╣░▌ ½ ▐██\",╟╬╬▓╬╬M╫Ñ░░░H`,▄▄▄▄▄▄   j░░]Ñ╫░░░░ÑHµ\n");
    printf("████████████⌐« ▌║Ü╣Ñ╬╬╬Ñ╬Ñ╬╬╬Ñ╬⌐╫░▌╥▒ ▐██ ╨╝╬╬╬╬Ñ░░░░]^╔▄████████▄▄▄▄\"^^^^^╔▄▄██\n");
    printf("████████████⌐╫░Ñ║M╟.æ.@╔⌂╔.m.U╔⌂╫░╫╟Ñ ▐████▄▄▄▄▄▄▄▄▄▄███████████████████████████\n");
    printf("█████████████████████████████████████████████████████████████████████████████████\n");
    
}
