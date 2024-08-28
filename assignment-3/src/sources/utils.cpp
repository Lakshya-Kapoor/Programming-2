#include "../includes/utils.h"

#include <iostream>
#include <string>

using namespace std;

vector<string> parseLocation(string location) {
    int start = 0;
    int end = 0;

    vector<string> res;

    while (end < location.size()) {
        if (location[end] == ':') {
            res.push_back(location.substr(start, end - start));
            start = end + 1;
        }
        end++;
    }
    res.push_back(location.substr(start, end - start));
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

pair<bool, Date> validDate(string isoDate) {
    int year, month, day;
    int parsedItems = sscanf(isoDate.c_str(), "%d-%d-%d", &year, &month, &day);

    if (parsedItems != 3) {
        return {false, Date()};
    }

    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((month < 1 || month > 12)) {
        return {false, Date()};
    }
    if (month != 2) {
        if (day < 1 || day > daysInMonth[month]) {
            return {false, Date()};
        }
    } else {
        if (isLeapYear(year) ? (day < 1 || day > 29) : (day < 1 || day > 28)) {
            return {false, Date()};
        }
    }
    return {true, Date(year, month, day)};
}

bool validCongregaionType(string type) {
    return type == "Games" || type == "Concerts" || type == "Conventions" ||
           type == "Conferences";
}