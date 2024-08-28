#include "../includes/date.h"

#include <chrono>
#include <iostream>
#include <string>

#include "../includes/utils.h"

using namespace std;

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date() {
    auto now = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(now);
    tm tm = *localtime(&time_t);
    year = tm.tm_year + 1900;
    month = tm.tm_mon + 1;
    day = tm.tm_mday;
}

string Date::dateString() const {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
    return std::string(buffer);
}
