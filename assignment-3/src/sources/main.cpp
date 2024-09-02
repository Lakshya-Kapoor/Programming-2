#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/parsing_input.h"

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
        } else if (strcmp(command, "reserveVenue") == 0) {
            parseReserveVenue(input + strlen(command) + 1);
        } else if (strcmp(command, "showReserved") == 0) {
            parseShowReserved(input + strlen(command) + 1);
        } else if (strcmp(command, "freeVenue") == 0) {
            parseFreeVenue(input + strlen(command) + 1);
        } else if (strcmp(command, "addEvent") == 0) {
            parseAddEvent(input + strlen(command) + 1);
        } else if (strcmp(command, "deleteEvent") == 0) {
            parseDelEvent(input + strlen(command) + 1);
        } else if (strcmp(command, "showEvents") == 0) {
            parseShowEvents(input + strlen(command) + 1);
        } else if (strcmp(command, "showCalendar") == 0) {
            parseShowCalendar(input + strlen(command) + 1);
        } else if (strcmp(command, "End") == 0) {
            break;
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
