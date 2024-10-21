#include <stdio.h>

void sort(int arr[], int size) {
 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
  
    int random_numbers[10] = {34, 12, 5, 78, 23, 56, 1, 89, 45, 67};
    int user_sorted_list[10];
    int correct_sorted_list[10];
    int correct_count = 0;
    int incorrect_count = 0;

    for (int i = 0; i < 10; i++) {
        correct_sorted_list[i] = random_numbers[i];
    }
    sort(correct_sorted_list, 10);

    printf("Random Numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", random_numbers[i]);
    }
    printf("\n");

    printf("Please sort these numbers in ascending order and input your sorted list (separated by spaces):\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &user_sorted_list[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (user_sorted_list[i] == correct_sorted_list[i]) {
            correct_count++;
        } else {
            incorrect_count++;
        }
    }

 
    printf("You correctly placed %d numbers.\n", correct_count);
    printf("You incorrectly placed %d numbers.\n", incorrect_count);
    printf("The correct sorted list is: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", correct_sorted_list[i]);
    }
    printf("\n");

    return 0;
}
