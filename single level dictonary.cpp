#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

struct File {
    char name[MAX_FILENAME_LENGTH];
};

struct File directory[MAX_FILES];
int fileCount = 0;

void addFile(const char* name) {
    if (fileCount < MAX_FILES) {
        strncpy(directory[fileCount].name, name, MAX_FILENAME_LENGTH);
        fileCount++;
        printf("File '%s' added to the directory, Sruthi.\n", name);
    } else {
        printf("Directory is full, Sruthi. Cannot add more files.\n");
    }
}

void listFiles() {
    int i;
    printf("Files in the directory, Sruthi:\n");
    for (i = 0; i < fileCount; i++) {
        printf("%s\n", directory[i].name);
    }
}

int main() {
    int choice;
    char fileName[MAX_FILENAME_LENGTH];

    printf("Single-Level Directory Organization, Sruthi\n");

    while (1) {
        printf("Options, Sruthi:\n");
        printf("1. Add a file\n");
        printf("2. List files\n");
        printf("3. Exit\n");
        printf("Enter your choice, Sruthi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the file name, Sruthi: ");
                scanf("%s", fileName);
                addFile(fileName);
                break;
            case 2:
                listFiles();
                break;
            case 3:
                printf("Exiting the program, Sruthi. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, Sruthi. Please try again.\n");
        }
    }

    return 0;
}

