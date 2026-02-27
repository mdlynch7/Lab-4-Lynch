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

    // stores the data in the dataArray
    int dataArray[counter];
    // for loop to actually read the data
    for (int i = 0; i < counter; i++) {
        fscanf(fileName, "%d", &dataArray[i]);
    }

    // closes file
    fclose(fileName);

    // calls assembly code file
    int total = sum_array(dataArray, counter);
    // prints the total
    printf("Sum is: %d\n", total);

    return 0;
}