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

Password generate_password(int upper_limit, int lower_limit)
{
    int result = 0, low_num = 0, hi_num = 0;
    int i = 0;
    Password password;
    password.password[0] = 1;


    if (lower_limit < upper_limit)
    {
        low_num = lower_limit;
        hi_num = upper_limit + 1;
    } else {
        low_num = upper_limit + 1;
        hi_num = lower_limit;
    }

    for(i = 0; i < 4; i++){
        result = (rand() % (hi_num - low_num)) + low_num;
        password.password[i] = result;
    }

    return password;
}

bool input_password(Guess *player_guess, int pos)
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

    /* Read input password */
    printf("Enters the password guess:\n");
    while ((c = getchar()) != '\n') {
        printf("%i %c\n", count, c);
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
            printf("%c, ", COLORS[i]);
        }
        printf("%c].\n", COLORS[l-1]);
        printf("\n");
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
        for (j = 0; j < PASSWORD_LENGTH; j++) {
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

    game_board->password = generate_password(2,7);
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
    /* clear_screen(); */
    printf("Still have %d tries. \n\n", BOARD_SIZE - i);

    return still_have_tries;

}

void start_game(){

    Board game_board;
    Guess player_guess;
    int board_pos = 0;
    game_board.tried = 0;

    initialize_board(&game_board);

    while(check_tries(game_board))
    {
        /* clear_screen(); */
        show_board(game_board);
        if (input_password(&game_board.rounds[board_pos], board_pos)) {
            board_pos++;
            game_board.tried++;
        }
    }

}
