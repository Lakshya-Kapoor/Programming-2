#include "parsing_input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "congregation.h"
#include "venue.h"

#define printError             \
    {                          \
        printf("-1\nError\n"); \
        return;                \
    }

CongregationManager congManager;
VenueManager venManager;

void parseAddCongregation(char* input) {
    char name[100];
    char type[50];
    char startDate[20];
    char endDate[20];

    int parsedItems =
        sscanf(input, "\"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\"", name, type,
               startDate, endDate);

    if (parsedItems < 4) {
        printError
    }
    // TODO: check date validity
    // TODO: check cong type validity
    congManager.addCongregation(name, type, startDate, endDate);
}

void parseDelCongregation(char* input) {
    char name[100];

    int parsedItems = sscanf(input, "\"%[^\"]\"", name);

    if (parsedItems < 1) {
        printError
    }

    congManager.delCongregation(name);
}

void parseShowCongregations(char* input) { congManager.showCongregations(); }

void parseAddVenue(char* input) {
    char name[100];
    char location[100];
    int capacity;

    int parsedItems =
        sscanf(input, "\"%[^\"]\" \"%[^\"]\" %d", name, location, &capacity);

    if (parsedItems < 3) {
        printError
    }
}

void parseDelVenue(char* input) {
    char name[50];
    char country[50];
    int parsedItems = sscanf(input, "\"%[^\"]\" \"%[^\"]\"", name, country);
    if (parsedItems < 2) {
        printError
    }
}

void parseShowVenues(char* input) {
    char location[100];
    int parsedItems = sscanf(input, "\"%[^\"]\"", location);
    if (parsedItems < 1) {
        printError
    }
}