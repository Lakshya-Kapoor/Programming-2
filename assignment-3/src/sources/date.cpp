#include "../includes/date.h"

#include <chrono>
#include <iostream>
#include <string>

#include "../includes/utils.h"

using namespace std;

// Converts iso date string to object
Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

// Creats new object of current date
Date::Date() {
    auto now = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(now);
    tm tm = *localtime(&time_t);
    year = tm.tm_year + 1900;
    month = tm.tm_mon + 1;
    day = tm.tm_mday;
}

// Copy constructor
Date::Date(const Date& other)
    : year(other.year), month(other.month), day(other.day) {}

// Assignment operator overloading
Date& Date::operator=(const Date& other) {
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
    return *this;
}

// Returns iso date string from Date object
string Date::dateString() const {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
    return string(buffer);
}

// Increments The current date
void Date::operator++(int n) {
    day++;
    if (day > daysInMonth(year, month)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// Returns whether date1 == date2
bool Date::operator==(const Date& other) const {
    return (this->year == other.year && this->month == other.month &&
            this->day == other.day);
}

// Returns whether date1 < date2
bool Date::operator<(const Date& other) const {
    if (this->year != other.year) return this->year < other.year;
    if (this->month != other.month) return this->month < other.month;
    return this->day < other.day;
}
// Returns whether date1 > date2
bool Date::operator>(const Date& other) const {
    if (this->year != other.year) return this->year > other.year;
    if (this->month != other.month) return this->month > other.month;
    return this->day > other.day;
}

// Returns whether date1 <= date2
bool Date::operator<=(const Date& other) const {
    return *this == other && *this < other;
}

// Returns whether date1 >= date2
bool Date::operator>=(const Date& other) const {
    return *this == other && *this > other;
}

// Returns number of days between two days, -1 if date1 < date2
int Date::operator-(const Date& other) const {
    if (*this < other) return -1;
    int days = 0;
    Date temp = *this;
    while (!(temp == other)) {
        temp++;
        days++;
    }
    return days;
}