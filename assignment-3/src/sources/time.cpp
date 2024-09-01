#include "../includes/time.h"

#include <iostream>
#include <string>
using namespace std;

Time::Time() {};

Time::Time(int hour, int minute) : hour(hour), minute(minute) {};

Time Time::operator-(const Time& other) const {
    return Time(this->hour - other.hour, this->minute - other.minute);
}

bool Time::operator<(const Time& other) const {
    if (this->hour != other.hour) return this->hour < other.hour;
    return this->minute < other.minute;
}

bool Time::operator==(const Time& other) const {
    return (this->hour == other.hour && this->minute == other.minute);
}

bool Time::operator>(const Time& other) const {
    return !(*this == other) && !(*this < other);
}

ostream& operator<<(ostream& os, const Time& time) {
    os << time.hour << ":" << time.minute;
    return os;
}

int Time::getHour() const { return hour; }

int Time::getMinute() const { return minute; }