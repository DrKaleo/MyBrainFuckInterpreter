#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int runProgram(char myProgramArray[MAX_SIZE], unsigned char myDataArray[MAX_SIZE], int sizeOfArr) {
    int currentDataPointer = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        char current = myProgramArray[i];
      //  printf("%c ", current);
        switch (current) {
            case '+': // INCREMENT
                myDataArray[currentDataPointer]++;
                break;
            case '-': // DECREMENT
                if (myDataArray[currentDataPointer] == 0) break; //underflow
                myDataArray[currentDataPointer]--;
                break;
            case '<': // MOVE POINTER LEFT
                if (currentDataPointer == 0) break; // below 0
                currentDataPointer--;
                break;
            case ',': // TAKE INPUT
                
                break;
            case '>': // MOVE POINTER RIGHT
                currentDataPointer++;
                break;
            case '[': { // IF ZERO JUMP TO ]
                if (myDataArray[currentDataPointer] != 0) break;
                int stack = 0;
                for (int j = i + 1; j < sizeOfArr; j++) {
                    if (myProgramArray[j] == '[') stack++;
                    if (myProgramArray[j] == ']') {
                        if (stack == 0) {
                            i = j;
                            break;
                        }
                        stack--;
                    }
                }
                break;
            }
            case ']': { // IF NONZERO JUMP TO [
                if (myDataArray[currentDataPointer] == 0) break;
                int stack = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (myProgramArray[j] == ']') stack++;
                    if (myProgramArray[j] == '[') {
                        if (stack == 0) {
                            i = j;
                            break;
                        }
                        stack--;
                    }
                }
                break;
            }
            case '.': // PRINT
                printf("%c", myDataArray[currentDataPointer]);
                break;
            default:
                break;
        }
    }
    printf("\n");
    return 0;
}

int readfile(char charArray[MAX_SIZE]) {
    FILE *file;
    char filename[100];
    int index = 0;

    // Get the filename
    printf("Enter the filename to open: ");
    scanf("%99s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read from file and store in array
    char ch;
    while ((ch = fgetc(file)) != EOF && index < MAX_SIZE) {
        charArray[index++] = ch;
    }

    // Close file
    fclose(file);

    // Print enterd program
    printf("\nFile contents stored in the array:\n");
    for (int i = 0; i < index; i++) {
        putchar(charArray[i]);
    }
    printf("\n");
    return index;
}

int main() {
    char programArray[MAX_SIZE] = {0}; // holds the program instructions
    unsigned char dataArray[MAX_SIZE] = {0}; //holds the tape data

    int size = readfile(programArray);
    runProgram(programArray, dataArray, size);
    return 0;
}