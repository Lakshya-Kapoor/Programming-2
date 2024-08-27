#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing_input.h"

using namespace std;

int main() {
    char input[500];
    char command[20];

    FILE *file;

    char file_name[50];
    scanf("%s", file_name);

    // Open the file in read mode
    file = fopen(file_name, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file line by line
    while (fgets(input, sizeof(input), file) != NULL) {
        // Removing new line character
        input[strcspn(input, "\n")] = '\0';

        // Extracting the command
        sscanf(input, "%s", command);

        if (strcmp(command, "addVenue") == 0) {
            parseAddVenue(input + strlen(command) + 1);
        } else if (strcmp(command, "deleteVenue") == 0) {
            parseDelVenue(input + strlen(command) + 1);
        } else if (strcmp(command, "showVenues") == 0) {
            parseShowVenues(input + strlen(command) + 1);
        } else if (strcmp(command, "addCongregation") == 0) {
            parseAddCongregation(input + strlen(command) + 1);
        } else if (strcmp(command, "deleteCongregation") == 0) {
            parseDelCongregation(input + strlen(command) + 1);
        } else if (strcmp(command, "showCongregations") == 0) {
            parseShowCongregations(input + strlen(command) + 1);
        } else if (strcmp(command, "End") == 0) {
            break;
        }
    }

    // Close the file
    fclose(file);

    return 0;
}