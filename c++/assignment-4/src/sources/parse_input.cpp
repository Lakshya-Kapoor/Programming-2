#include "../includes/parse_input.h"

#include <iostream>
#include <string>

#include "../includes/congregation_manager.h"
#include "../includes/date.h"
#include "../includes/macros.h"
#include "../includes/utils.h"
#include "../includes/venue_manager.h"

using namespace std;

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
        ERROR_OUTPUT;
    }
    if (!validCongregaionType(type)) {
        ERROR_OUTPUT;
    }

    p1 = validDate(startDate);
    p2 = validDate(endDate);

    // Checks whether dates are valid
    if (!p1.first || !p2.first) {
        ERROR_OUTPUT;
    }
    // Checks whether startdate is before enddate and start date is not in past
    if (p1.second > p2.second || p1.second < Date()) {
        ERROR_OUTPUT;
    }

    congManager.addCongregation(name, type, p1.second, p2.second);
}

void parseDeleteCongregation(char* input) {
    char name[100];
    int parsedItems = sscanf(input, "\"%[^\"]\"", name);
    if (parsedItems != 1) {
        ERROR_OUTPUT;
    }
    congManager.delCongregation(name);
}

void parseShowCongregations() { congManager.showCongregations(); }

void parseAddProgram(char* input) {
    char cong_name[100], prog_name[100], type[50], startDate[20], endDate[20];
    pair<bool, Date> p1, p2;

    int parsedItems =
        sscanf(input, "\"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\"",
               cong_name, type, prog_name, startDate, endDate);

    if (parsedItems != 5) {
        ERROR_OUTPUT;
    }

    if (!validProgramType(type)) {
        ERROR_OUTPUT;
    }

    p1 = validDate(startDate);
    p2 = validDate(endDate);

    // Checks whether dates are valid
    if (!p1.first || !p2.first) {
        ERROR_OUTPUT;
    }
    // Checks whether startdate is before enddate and start date is not in past
    if (p1.second > p2.second || p1.second < Date()) {
        ERROR_OUTPUT;
    }

    congManager.addProgramToCong(cong_name, type, prog_name, p1.second,
                                 p2.second);
}

void parseDeleteProgram(char* input) {
    char prog_name[100], cong_name[100];

    int parsedItems =
        sscanf(input, "\"%[^\"]\" \"%[^\"]\"", cong_name, prog_name);

    if (parsedItems != 2) {
        ERROR_OUTPUT;
    }

    congManager.delProgramFromCong(cong_name, prog_name);
}

void parseShowPrograms(char* input) {
    char cong_name[100];

    int parsedItems = sscanf(input, "\"%[^\"]\"", cong_name);

    if (parsedItems != 1) {
        ERROR_OUTPUT;
    }

    congManager.showProgramsInCong(cong_name);
}

void parseAddVenue(char* input) {
    char name[100], location[100], type[100];
    char address[40], city[40], state[40], postalCode[20], country[40];
    int capacity;

    int parsedItems = sscanf(input, "\"%[^\"]\" \"%[^\"]\" \"%[^\"]\" %d", name,
                             location, type, &capacity);

    if (parsedItems != 4) {
        ERROR_OUTPUT;
    }

    parsedItems = sscanf(location, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]", address,
                         city, state, postalCode, country);

    if (parsedItems != 5) {
        ERROR_OUTPUT;
    }

    venManager.addVenue(name,
                        Location(address, city, state, postalCode, country),
                        type, capacity);
}

void parseDeleteVenue(char* input) {
    char name[100], country[50];
    int parsedItems = sscanf(input, "\"%[^\"]\" \"%[^\"]\"", name, country);

    if (parsedItems != 2) {
        ERROR_OUTPUT;
    }

    venManager.delVenue(name, country);
}

void parseShowVenues(char* input) {
    char location[100];

    int parsedItems = sscanf(input, "\"%[^\"]\"", location);

    if (parsedItems != 1) {
        ERROR_OUTPUT;
    }
    venManager.showVenues(location);
}

void parseReserveVenue(char* input) {
    char ven_name[100], country[50], cong_name[50], prog_name[50];
    int parsedItems =
        sscanf(input, "\"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\"", ven_name,
               country, cong_name, prog_name);

    if (parsedItems != 4) {
        ERROR_OUTPUT;
    }

    congManager.reserveVenue(ven_name, country, cong_name, prog_name,
                             venManager);
}

void parseFreeVenue(char* input) {
    char ven_name[100], country[50], cong_name[50], prog_name[50];
    int parsedItems =
        sscanf(input, "\"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\"", ven_name,
               country, cong_name, prog_name);

    if (parsedItems != 4) {
        ERROR_OUTPUT;
    }

    congManager.freeVenue(ven_name, country, cong_name, prog_name, venManager);
}

void parseShowReserved(char* input) {
    char cong_name[100];
    int parsedItems = sscanf(input, "\"%[^\"]\"", cong_name);

    if (parsedItems != 1) {
        ERROR_OUTPUT;
    }

    congManager.showReserved(cong_name);
}