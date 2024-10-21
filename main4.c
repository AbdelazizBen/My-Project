#include <stdio.h>

const char *words[] = {"apple", "banana", "cherry", "date", "fig"};

void display_word(const char *word, char guessed[], int word_length) {
    for (int i = 0; i < word_length; i++) {
        int found = 0;
        for (int j = 0; guessed[j] != '\0'; j++) {
            if (word[i] == guessed[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    
    int max_attempts = 6;
    int word_count = 5;

 
    const char *chosen_word = words[2];  
    char guessed[26] = {0};  
    int attempts = max_attempts;
    int word_length = 0;


    while (chosen_word[word_length] != '\0') {
        word_length++;
    }

    printf("Welcome to the Letter Guessing Game!\n");
    printf("You have %d attempts to guess the word.\n", max_attempts);

    while (attempts > 0) {
        printf("\nCurrent word: ");
        display_word(chosen_word, guessed, word_length);
        printf("Attempts left: %d\n", attempts);

        char guess;
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        int already_guessed = 0;
        for (int i = 0; guessed[i] != '\0'; i++) {
            if (guessed[i] == guess) {
                already_guessed = 1;
                break;
            }
        }

        if (already_guessed) {
            printf("You already guessed '%c'. Try again.\n", guess);
            continue;
        }

      
        int i;
        for (i = 0; i < 26; i++) {
            if (guessed[i] == '\0') {
                guessed[i] = guess;
                break;
            }
        }

     
        int correct_guess = 0;
        for (int i = 0; i < word_length; i++) {
            if (chosen_word[i] == guess) {
                correct_guess = 1;
                break;
            }
        }

        if (correct_guess) {
            printf("Correct! '%c' is in the word.\n", guess);
        } else {
            printf("Incorrect! '%c' is not in the word.\n", guess);
            attempts--;
        }

        int guessed_all = 1;
        for (int i = 0; i < word_length; i++) {
            int found = 0;
            for (int j = 0; guessed[j] != '\0'; j++) {
                if (chosen_word[i] == guessed[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                guessed_all = 0;
                break;
            }
        }

        if (guessed_all) {
            printf("Congratulations! You've guessed the word: %s\n", chosen_word);
            break;
        }
    }

    if (attempts == 0) {
        printf("Game over! The word was: %s\n", chosen_word);
    }

    return 0;
}
