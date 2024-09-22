#include "../includes/time.h"

#include <iostream>
#include <string>
using namespace std;

Time::Time() {};

Time::Time(int hour, int minute) : hour(hour), minute(minute) {};

Time Time::operator-(const Time& other) const {
    int thisMin = this->hour * 60 + this->minute;
    int otherMin = other.hour * 60 + other.minute;

    Time res;
    res.hour = (thisMin - otherMin) / 60;
    res.minute = (thisMin - otherMin) % 60;
    return res;
}

Time Time::operator+(const Time& other) const {
    int min = (this->minute + other.minute);
    int hour = this->hour + other.hour + (min >= 60 ? 1 : 0);

    return Time(hour, min % 60);
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
    os << (time.hour < 10 ? "0" : "") << time.hour << ":"
       << (time.minute < 10 ? "0" : "") << time.minute;
    return os;
}

int Time::getHour() const { return hour; }

int Time::getMinute() const { return minute; }