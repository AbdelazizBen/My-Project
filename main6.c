#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int arr[], int size) {
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
    int randomNumbers[] = {34, 7, 23, 32, 5, 62, 45, 12, 99, 18};
    int size = sizeof(randomNumbers) / sizeof(randomNumbers[0]);
    int userSorted[size];


    printf("Random Numbers:\n");
    printArray(randomNumbers, size);


    int correctSorted[size];
    for (int i = 0; i < size; i++) {
        correctSorted[i] = randomNumbers[i];
    }
    sortArray(correctSorted, size);

   
    printf("Please enter your sorted list of numbers (separated by spaces):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &userSorted[i]);
    }

 
    int correctCount = 0, incorrectCount = 0;

    for (int i = 0; i < size; i++) {
        if (userSorted[i] == correctSorted[i]) {
            correctCount++;
        } else {
            incorrectCount++;
        }
    }

   
    printf("You correctly placed %d numbers.\n", correctCount);
    printf("You incorrectly placed %d numbers.\n", incorrectCount);

   
    printf("Correct sorted list:\n");
    printArray(correctSorted, size);

    return 0;
}
