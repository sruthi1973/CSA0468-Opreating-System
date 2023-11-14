#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char content[100];

    file = fopen("sruthi1", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "This is the content for sruthi1.");
    fclose(file);

    file = fopen("sruthi1", "r");

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }
    printf("Content read from the file 'sruthi1':\n");
    while (fscanf(file, "%s", content) != EOF) {
        printf("%s ", content);
    }
    fclose(file);
    file = fopen("sruthi2", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "This is the content for sruthi2.");
    fclose(file);
    file = fopen("sruthi2", "r");

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }
    printf("\nContent read from the file 'sruthi2':\n");
    while (fscanf(file, "%s", content) != EOF) {
        printf("%s ", content);
    }
    fclose(file);

    return 0; 
}

