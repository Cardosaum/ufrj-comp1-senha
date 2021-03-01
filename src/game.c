#include "game.h"
#include "defs.h"
#include "interface.h"

size_t trimwhitespace(char *out, size_t len, const char *str)
{
    /* TODO: refactor this function */
    if(len == 0)
      return 0;

    const char *end;
    size_t out_size;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
    {
      *out = 0;
      return 1;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end++;

    // Set output size to minimum of trimmed string length and buffer size minus 1
    out_size = (unsigned long)(end - str) < len-1 ? (end - str) : len-1;

    // Copy trimmed string and add null terminator
    memcpy(out, str, out_size);
    out[out_size] = 0;

    return out_size;
}

Password generate_password()
{
    int i = 0;
    Password password;
    char c;

    for(i = 0; i < PL; i++){
        c = COLORS[(rand() % (strlen(COLORS)))];
        /* printf("%i, %c, %i\n", i, c, c); */
        password.password[i] = c;
    }
    password.password[PL] = '\0';

    return password;
}

bool input_password(Guess *player_guess, Board game_board)
{
    /*
     * Return true if the the input was valid
     * Return false otherwise
     */

    int i;
    char c;
    int count = 0;
    char whipeout_stdin;
    bool is_ok = true;
    char password[PASSWORD_LENGTH];
    char new[PASSWORD_LENGTH];

    int tries_left = 0;
    for (tries_left = 0; tries_left < BOARD_SIZE; tries_left++) {
        if (!game_board.rounds[tries_left].feedback_given) {
            tries_left = BOARD_SIZE - tries_left;
            break;
        }
    }
    printf("%i Tries left\n", tries_left);
    printf("Password guess:\n");
    printf("> ");

    /* Read input password */
    while ((c = getchar()) != '\n') {
        switch (c) {
            case ' ':
                continue;
                break;
            default:
                c = toupper(c);
                if (count >= PL) {
                    password[PL] = '\0';
                    is_ok = false;
                    while ((whipeout_stdin = getchar()) != '\n' && whipeout_stdin != EOF){}
                    break;
                }
                password[count] = c;
                count++;
                    }
        if (!is_ok) {
            break;
        }
    }

    trimwhitespace(new, PASSWORD_LENGTH, password);
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = new[i];
    }

    is_ok = is_ok && check_password(password);
    if(is_ok)
    {
        int i;
        for (i = 0; i < PASSWORD_LENGTH; i++) {
            player_guess->player_password.password[i] = password[i];
        }
        player_guess->feedback_given = true;
    }
    else
    {
        printf("\n");
        printf("Please, enter the password in a valid format.\n");
        printf("The password must have exactly %i characters,\n", PL);
        printf("and the inserted characters must be in this array:\n[");
        int i;
        int l = strlen(COLORS);
        for (i = 0; i < l-1; i++) {
            switch (COLORS[i])
            {
                case 'R':
                    printf("%s%c%s",KRED,COLORS[i],KNIL);
                    break;

                case 'G':
                    printf("%s%c%s",KGRN,COLORS[i],KNIL);
                    break;

                case 'Y':
                    printf("%s%c%s",KYEL,COLORS[i],KNIL);
                    break;

                case 'B':
                    printf("%s%c%s",KBLU,COLORS[i],KNIL);
                    break;

                case 'M':
                    printf("%s%c%s",KMAG,COLORS[i],KNIL);
                    break;

                case 'C':
                    printf("%s%c%s",KCYN,COLORS[i],KNIL);
                    break;
                
                default:
                    break;
            }
            printf(", ");
        }
        switch (COLORS[l-1])
        {
            case 'R':
                printf("%s%c%s",KRED,COLORS[l-1],KNIL);
                break;

            case 'G':
                printf("%s%c%s",KGRN,COLORS[l-1],KNIL);
                break;

            case 'Y':
                printf("%s%c%s",KYEL,COLORS[l-1],KNIL);
                break;

            case 'B':
                printf("%s%c%s",KBLU,COLORS[l-1],KNIL);
                break;

            case 'M':
                printf("%s%c%s",KMAG,COLORS[l-1],KNIL);
                break;

            case 'C':
                printf("%s%c%s",KCYN,COLORS[l-1],KNIL);
                break;
            
            default:
                break;
        }
        printf("].\n");
        printf("\n");
        printf("Press <enter> to continue.\n");
        while ((whipeout_stdin = getchar()) != '\n' && whipeout_stdin != EOF){}
        return false;
    }

    return true;
}

bool check_password(const char *password)
{
    /*
    ** Return "true" if password is of length == PASSWORD_LENGTH
    ** and if all the colors in the input match the hardcoded ones.
     */
    int length = strlen(password);
    if (!(length == PL)) {
        /* Password does not have the correct length */
        return false;
    }

    /**
     * Check password letters. (R,Y,B,...)
     *
     * If there is at least one that does not match
     * the intended ones, the function will return
     * false.
     */
    int i;
    int s = 0;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int j;
        for (j = 0; j < COLORS_LENGTH; j++) {
            if (password[i] == COLORS[j]) {
                s++;
                break;
            }
        }
    }
    if (s == PL)
        return true;
    else
        return false;
}

void initialize_board(Board *game_board){

    int i;

    game_board->password = generate_password();
    for(i = 0; i < BOARD_SIZE; i++){
        game_board->rounds[i].feedback_given = false;
    }

}

bool check_tries(const Board game_board){

    bool still_have_tries = false;
    int i;
    for(i = 0; i < BOARD_SIZE; i++){
        if(!game_board.rounds[i].feedback_given){
            still_have_tries = true;
            break;
        }
    }
    clear_screen();

    return still_have_tries;

}

int start_game(){

    Board game_board;
    int board_pos = 0;
    int after_game_decision = 0;
    int correct = 0;
    game_board.tried = 0;
    game_board.won = 0;

    clear_screen();
    initialize_board(&game_board);

    while((correct = calc_pins(game_board.rounds[board_pos-1].player_password.password, game_board.password.password, 'W')) != PL && check_tries(game_board))
    {
        show_board(game_board);
        if (input_password(&game_board.rounds[board_pos], game_board)) {
            board_pos++;
            game_board.tried++;
        }
        clear_screen();
    }

    if (correct == PL)
        game_board.won = 1;
    after_game_decision = finish_game(game_board);
    return after_game_decision;

}

int finish_game(Board board){

    int decision = 0;
    char c;
    char whipeout_stdin;

    clear_screen();

    show_board(board);
    if(board.won == 1){
        /* printf("CONGRATULATIONS! YOU WON!\n\n"); */
        print_win();
    }
    else{
        /* printf("YOU LOSE! BETTER LUCK NEXT TIME!\n\n"); */
        print_lose();
    }


    /* TODO Program still gets char inputs from buffer on the next game */
    printf("1. Play again.\n"); 
    printf("2. Return to main menu.\n");
    printf("3. Exit game.\n");

    while(decision == 0){
        c = getchar();
        c = atoi(&c);
        while ((whipeout_stdin = getchar()) != '\n' && whipeout_stdin != EOF){}

        if(c < 1 || c > 3){
            printf("Please, enters the following options.\n\n");
            printf("1. Play again.\n");
            printf("2. Return to main menu.\n");
            printf("3. Exit game.\n");
        } else {
            decision = c;
        }
    }

    return decision;

}
