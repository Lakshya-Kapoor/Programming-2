#include "../includes/parsing_input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/congregation.h"
#include "../includes/date.h"
#include "../includes/location.h"
#include "../includes/utils.h"
#include "../includes/venue.h"

using namespace std;

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
    pair<bool, Date> p1, p2;

    int parsedItems =
        sscanf(input, "\"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\"", name, type,
               startDate, endDate);
    if (parsedItems != 4) {
        printError
    }
    if (!validCongregaionType(type)) {
        printError
    }
    p1 = validDate(startDate);
    p2 = validDate(endDate);

    // Checks whether dates are valid and startDate < endDate
    if (!p1.first || !p2.first || !(p1.second < p2.second)) {
        printError
    }

    congManager.addCongregation(name, type, p1.second, p2.second);
}

void parseDelCongregation(char* input) {
    char name[100];
    int parsedItems = sscanf(input, "\"%[^\"]\"", name);
    if (parsedItems != 1) {
        printError
    }
    congManager.delCongregation(name, venManager);
}

void parseShowCongregations(char* input) { congManager.showCongregations(); }

void parseAddVenue(char* input) {
    char name[100], location[100];
    int capacity;
    char city[40], state[40], postalCode[20], country[40];

    int parsedItems =
        sscanf(input, "\"%[^\"]\" \"%[^\"]\" %d", name, location, &capacity);

    if (parsedItems != 3) {
        printError
    }

    parsedItems = sscanf(location, "%[^:]:%[^:]:%[^:]:%[^:]", city, state,
                         postalCode, country);

    if (parsedItems != 4) {
        printError
    }

    venManager.addVenue(name, Location(city, state, postalCode, country),
                        capacity);
}

void parseDelVenue(char* input) {
    char name[50];
    char country[50];
    int parsedItems = sscanf(input, "\"%[^\"]\" \"%[^\"]\"", name, country);
    if (parsedItems != 2) {
        printError
    }
    venManager.delVenue(name, country);
}

void parseShowVenues(char* input) {
    char location[100];
    char city[40], state[40], postalCode[20], country[40];

    int parsedItems = sscanf(input, "\"%[^\"]\"", location);
    if (parsedItems != 1) {
        printError
    }

    venManager.showVenues(location);
}

void parseReserveVenue(char* input) {
    char venue_name[100], congregation_name[100], country[40];
    int parsedItems = sscanf(input, "\"%[^\"]\" \"%[^\"]\" \"%[^\"]\"",
                             venue_name, country, congregation_name);
    if (parsedItems != 3) {
        printError
    }
    congManager.reserveVenue(venue_name, country, congregation_name,
                             venManager);
}

void parseFreeVenue(char* input) {
    char venue_name[100], country[40], congregation_name[100];
    int parsedItems = sscanf(input, "\"%[^\"]\" \"%[^\"]\" \"%[^\"]\"",
                             venue_name, country, congregation_name);
    if (parsedItems != 3) {
        printError
    }
    congManager.freeVenue(venue_name, country, congregation_name, venManager);
}

void parseShowReserved(char* input) {
    char congregation_name[100];
    int parsedItems = sscanf(input, "\"%[^\"]\"", congregation_name);
    if (parsedItems != 1) {
        printError
    }
    congManager.showReserved(congregation_name);
}