#include <stdio.h>

int main() {
    int number_to_guess = 50; 
    int user_guess, attempts = 0;
    int guessed_correctly = 0;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I've selected a number between 1 and 100. Can you guess it?\n");

    while (!guessed_correctly) {
        printf("Enter your guess: ");
        scanf("%d", &user_guess);
        attempts++;

      
        if (user_guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (user_guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d correctly!\n", number_to_guess);
            guessed_correctly = 1;
        }
    }

   
    printf("You found the number in %d attempts!\n", attempts);
    
    return 0;
}