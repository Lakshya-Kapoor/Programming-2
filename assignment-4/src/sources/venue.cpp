#include "../includes/venue.h"

#include <iostream>
#include <string>

using namespace std;

Venue::Venue(string name, Location location, int capacity)
    : name(name), location(location), capacity(capacity) {}

string Venue::getName() const { return name; }

Location Venue::getLocation() const { return location; }

Hotel::Hotel(string name, Location location, int capacity)
    : Venue(name, location, capacity) {
    type = "Hotel";
}

ConcertHall::ConcertHall(string name, Location location, int capacity)
    : Venue(name, location, capacity) {
    type = "Concert Hall";
}

ConventionCenter::ConventionCenter(string name, Location location, int capacity)
    : Venue(name, location, capacity) {
    type = "Convention Center";
}
