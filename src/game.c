#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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