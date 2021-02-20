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

int choose_menu_option()
{
	char chosen_option[2];
	int option;
	int len;
	
	while(1){
		printf("Which option will you choose? (1/2/3/4) ");
		gets(chosen_option);
		
		len = strlen(chosen_option);
		option = atoi(chosen_option);
		
		if(len > 1 || option != 1 && option != 2 && option != 3 && option != 4){
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
