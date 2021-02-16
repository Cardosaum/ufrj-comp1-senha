#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

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

void input_password(Guess *player_guess, int pos)
{    
    char password[5];
    printf("Enters the password guess:\n");
    fgets(password, 4, stdin);
    check_password(password);

}

int check_password(const char *password)
{
    /**
     * Returns 0 if the password is valid. Returns 1 if there is some error in the input password.
     */ 
     

    int valid_password = 0;
    int length = strlen(password);
    if(!(length == 4))
        valid_password = 1;

    /**
     * TODO: Check password letters. (R,Y,B,...)
     */
    
    if(valid_password)
        return 0;
    else
        return 1;
}