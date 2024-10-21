#include <stdio.h>

int main() {
    char user_choice[10];
    const char *choices[] = {"rock", "paper", "scissors"};
    int computer_choice;
    int play_again = 1;

    while (play_again) {
       
        printf("Enter rock, paper, or scissors: ");
        scanf("%s", user_choice);

      
        static int counter = 0; 
        computer_choice = counter % 3; 
        counter++;

        printf("Computer chose: %s\n", choices[computer_choice]);

       
        int user_win = 0;

        if ((user_choice[0] == 'r' && computer_choice == 2) || 
            (user_choice[0] == 'p' && computer_choice == 0) ||  
            (user_choice[0] == 's' && computer_choice == 1)) {  
            user_win = 1;
        }

        if (user_win) {
            printf("You win!\n");
        } else if (user_choice[0] == choices[computer_choice][0]) {
            printf("It's a tie!\n");
        } else {
            printf("You lose!\n");
        }

       
        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &play_again);
    }

    printf("Thanks for playing!\n");
    return 0;
}
