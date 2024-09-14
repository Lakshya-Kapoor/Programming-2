#include <stdio.h>
#include <string.h>

#include "../includes/parse_input.h"

using namespace std;

int main() {
    char input[500];

    FILE* file;
    char file_name[50];
    scanf("%s", file_name);

    file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error opening the file");
        return 1;
    }

    while (fgets(input, sizeof(input), file) != NULL) {
        input[strcspn(input, "\n")] = '\0';

        char command[50];
        sscanf(input, "%s", command);

        int idx = strlen(command);
        while (idx < strlen(input) && input[idx] == ' ') {
            idx++;
        }

        if (strcmp(command, "addCongregation") == 0) {
            parseAddCongregation(input + idx);
        } else if (strcmp(command, "deleteCongregation") == 0) {
            parseDeleteCongregation(input + idx);
        } else if (strcmp(command, "showCongregations") == 0) {
            parseShowCongregations();
        } else if (strcmp(command, "addProgram") == 0) {
            parseAddProgram(input + idx);
        } else if (strcmp(command, "deleteProgram") == 0) {
            parseDeleteProgram(input + idx);
        } else if (strcmp(command, "showPrograms") == 0) {
            parseShowPrograms(input + idx);
        } else if (strcmp(command, "addVenue") == 0) {
            parseAddVenue(input + idx);
        } else if (strcmp(command, "deleteVenue") == 0) {
            parseDeleteVenue(input + idx);
        } else if (strcmp(command, "showVenues") == 0) {
            parseShowVenues(input + idx);
            // } else if (strcmp(command, "reserveVenue") == 0) {
            //     parseReserveVenue(input + idx);
            // } else if (strcmp(command, "freeVenue") == 0) {
            //     parseFreeVenue(input + idx);
            // } else if (strcmp(command, "showReserved") == 0) {
            //     parseShowReserved();
        } else if (strcmp(command, "end") == 0) {
            break;
        }
    }

    // Close file
    fclose(file);
    return 0;
}