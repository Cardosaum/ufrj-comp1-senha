#include "game.h"
#include "defs.h"

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
    printf("=====IN INPUT_PASSWORD FUNCTION====="); 
    char password[5];
    printf("Enters the password guess:\n");
    fgets(password, 4, stdin);
    if(check_password(password))
    {
        int i;
        for (i = 0; i < 4; i++) {
            player_guess->player_password.password[i] = password[i];
        }
    }
    else
    {
        printf("Please, enter the password in a valid format.\n"); /* TODO Detail to the user the correct input format */
        return false;
    }

    return true;
}

bool check_password(const char *password)
{
    int length = strlen(password);
    int valid_password = 0;

    printf("=====IN CHECK_PASSWORD FUNCTION=====");

    if(!(length == 4))
        valid_password = 1;

    /**
     * TODO: Check password letters. (R,Y,B,...)
     */
    
    if(valid_password)
        return true;
    else
        return false;
}

bool check_tries(const Board *game_board){

    bool still_have_tries = false;
    int i;
    for(i = 0; i < BOARD_SIZE; i++){
        if(game_board->rounds->feedback_given){
            still_have_tries = true;
            break;
        }
    }

    return still_have_tries;

}
