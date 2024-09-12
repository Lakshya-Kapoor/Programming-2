#include "../includes/utils.h"

#include <iostream>
#include <string>

using namespace std;

vector<string> parseLocationString(string locationString) {
    int start = 0;
    int end = 0;

    vector<string> res;

    while (end < locationString.size()) {
        if (locationString[end] == ':') {
            res.push_back(locationString.substr(start, end - start));
            start = end + 1;
        }
        end++;
    }
    res.push_back(locationString.substr(start, end - start));
    return res;
}

bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    }
    if (year % 100 != 0) {
        return true;
    }
    if (year % 400 == 0) {
        return true;
    }
    return false;
}

int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }

    static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month];
}

// Returns date object if a valid iso date string
pair<bool, Date> validDate(string isoDateString) {
    int year, month, day;
    int parsedItems =
        sscanf(isoDateString.c_str(), "%d-%d-%d", &year, &month, &day);

    if (parsedItems != 3) {
        return {false, Date()};
    }
    if (month < 1 || month > 12) {
        return {false, Date()};
    }
    if (day < 1 || day > daysInMonth(year, month)) {
        return {false, Date()};
    }
    return {true, Date(year, month, day)};
}

bool validCongregaionType(string type) {
    return type == "Games" || type == "Concert" || type == "Convention" ||
           type == "Conference";
}

int getLocationType(string city, string state, string postalCode,
                    string country) {
    if (postalCode.empty() && !country.empty() && city.empty() && state.empty())
        return 1;
    if (!city.empty() && !state.empty() && !country.empty() &&
        postalCode.empty())
        return 2;
    if (!postalCode.empty() && !country.empty() && city.empty() &&
        state.empty())
        return 3;
    if (!city.empty() && !state.empty() && !postalCode.empty() &&
        !country.empty())
        return 4;
    return -1;
}