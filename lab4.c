#include <stdio.h>
#include <stdlib.h>

extern int sum_array(int* array, int size);

int main() {

    char userInput[100];

    printf("Enter data file name: ");
    scanf("%99s", userInput);

    // Reads the file
    FILE *fileName = fopen(userInput, "r");
    if (fileName == NULL) {
        perror("Error opening file");
        return 1;
    }

    int counter;
    // grabs amount of data to be read
    fscanf(fileName, "%d", &counter);

    // 
    int dataArray[counter];
    for (int i = 0; i < counter; i++) {
        fscanf(fileName, "%d", &dataArray[i]);
    }

    fclose(fileName);

    int total = sum_array(dataArray, counter);
    printf("Sum is: %d\n", total);

    return 0;
}