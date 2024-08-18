#include <iostream>
#include <string>
using namespace std;

#include "venue.h"

Venue::Venue(string venue_name, string venue_location, int capacity) {
    this->name = venue_name;
    this->location = venue_location;
    this->capacity = capacity;
    for (int i = 0; i < 31; i++) {
        calendar[i] = new Day;
    }
}

void Venue::showCalendar() const {
    int total_events = 0;
    for (int date = 1; date < 31; date++) {
        total_events += calendar[date]->no_of_events;
    }

    cout << total_events << endl;

    for (int date = 1; date < 31; date++) {
        cout << date << " ";
        calendar[date]->showEvents();
    }
}