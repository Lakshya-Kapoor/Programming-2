#include "utils.h"

#include <iostream>
#include <string>

using namespace std;

vector<int> extractDate(string date) {
    vector<int> res;

    int start = 0;
    int end = 0;
    while (end < date.length()) {
        if (date[end] == '-') {
            res.push_back(stoi(date.substr(start, end - start)));
            start = end + 1;
        }
        end++;
    }
    res.push_back(stoi(date.substr(start, end - start)));
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

bool validDate(string date) {
    vector<int> res = extractDate(date);

    int year = res[0];
    int month = res[1];
    int day = res[2];

    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((month < 1 || month > 12)) {
        return false;
    }
    if (month != 2) {
        if (day < 1 || day > daysInMonth[month]) {
            return false;
        }
    } else {
        if (isLeapYear(year) ? (day < 1 || day > 29) : (day < 1 || day > 28)) {
            return false;
        }
    }

    return true;
}

bool validCongregaionType(string type) {
    return type == "Games" || type == "Concerts" || type == "Conventions" ||
           type == "Conferences";
}