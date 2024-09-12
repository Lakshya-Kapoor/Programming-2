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
