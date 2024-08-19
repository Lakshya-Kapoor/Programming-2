#include <iostream>
#include <string>
using namespace std;

#include "venue.h"

Venue::Venue(string venue_name, string location, int capacity) {
    this->name = venue_name;
    this->location = location;
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

Venue::~Venue() {
    for (int i = 0; i < 31; i++) {
        delete calendar[i];
    }
}