#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t process_id = getpid();
    pid_t parent_process_id = getpid();

    printf("Process ID: %d\n", process_id);
    printf("Parent Process ID: %d\n", parent_process_id);
	FILE *fptr1, *fptr2;
	char source_filename[] = "filea.txt"; 
    char destination_filename[] = "fileb.txt"; 
    char c;

    fptr1 = fopen(source_filename, "r");
    if (fptr1 == NULL) {
        printf("Cannot open file %s\n", source_filename);
        exit(0);
    }

    fptr2 = fopen(destination_filename, "w");
    if (fptr2 == NULL) {
        printf("Cannot open file %s\n", destination_filename);
        exit(0);
    }
    c = fgetc(fptr1);
    while (c != EOF) {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    printf("\nContents copied from %s to %s\n", source_filename, destination_filename);
    fclose(fptr1);
    fclose(fptr2);

    return 0;
}

