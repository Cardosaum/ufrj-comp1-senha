#include "game.h"
#include "defs.h"

size_t trimwhitespace(char *out, size_t len, const char *str)
{
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
    printf("=====IN INPUT_PASSWORD FUNCTION=====\n");
    char password[PASSWORD_LENGTH];
    printf("Enters the password guess:\n");
    fgets(password, PASSWORD_LENGTH, stdin);
    char new[PASSWORD_LENGTH];
    trimwhitespace(new, PASSWORD_LENGTH, password);
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = new[i];
    }

    if(check_password(password))
    {
        int i;
        for (i = 0; i < PASSWORD_LENGTH; i++) {
            player_guess->player_password.password[i] = password[i];
            printf("%c", player_guess->player_password.password[i]);
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("Please, enter the password in a valid format.\n"); /* TODO Detail to the user the correct input format */
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
