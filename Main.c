#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main() 
{

  char char2Array[MAX_SIZE];
  readfile(char2Array);

  return 0;

}


void readfile(char charArray[MAX_SIZE])
{


    FILE *file;
    char filename[100];
    //char charArray[MAX_SIZE];
    int index = 0;

    // Get the filename from the user
    printf("Enter the filename to open: ");
    scanf("%99s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read characters from the file and store in array
    char ch;
    while ((ch = fgetc(file)) != EOF && index < MAX_SIZE) {
        charArray[index++] = ch;
    }

    // Close the file
    fclose(file);

    // Print the characters stored in the array
    printf("\nFile contents stored in the array:\n");
    for (int i = 0; i < index; i++) {
        putchar(charArray[i]);
    }
    printf("\n");

}
