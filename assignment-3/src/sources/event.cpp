#include "../includes/event.h"

#include <iostream>
#include <string>

using namespace std;

Event::Event(string name, Date date, Time startTime, Time endTime)
    : name(name), date(date), startTime(startTime), endTime(endTime) {}

string Event::getName() const { return name; }

Date Event::getDate() const { return date; }

Time Event::getStartTime() const { return startTime; }

Time Event::getEndTime() const { return endTime; }

std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << event.name << " " << event.startTime << " " << event.endTime << endl;
    return os;
}
