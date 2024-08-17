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