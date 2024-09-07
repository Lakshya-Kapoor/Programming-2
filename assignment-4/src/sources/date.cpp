#include "../includes/date.h"

#include <chrono>
#include <iostream>
#include <string>

using namespace std;

// Returns date object of current date
Date::Date() {
    auto now = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(now);
    tm tm = *localtime(&time_t);
    year = tm.tm_year + 1900;
    month = tm.tm_mon + 1;
    day = tm.tm_mday;
}

// Date constructor
Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

// Date copy constructor
Date::Date(const Date& other) {
    year = other.year;
    month = other.month;
    day = other.day;
}

// Checks if date1 == date2
bool Date::operator==(const Date& other) const {
    return (year == other.year) && (month == other.month) && (day == other.day);
}

// Checks if date1 < date2
bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

// Checks if date1 > date2
bool Date::operator>(const Date& other) const {
    return !(*this == other || *this < other);
}
// checks whether date1 <= date2
bool Date::operator<=(const Date& other) const { return !(*this > other); }

// checks whether date1 >= date2
bool Date::operator>=(const Date& other) const { return !(*this < other); }

// Print date
ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << "-" << date.month << "-" << date.day << endl;
    return os;
}
