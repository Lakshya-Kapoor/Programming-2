#include <iostream>
#include <string>
using namespace std;

#include "venue.h"
#include "venue_manager.h"

VenueManager::VenueManager() { no_of_venues = 0; }

int VenueManager::venueIndex(string venue_name) const {
    for (int i = 0; i < no_of_venues; i++) {
        if (venues_list[i]->name == venue_name) {
            return i;
        }
    }
    return no_of_venues;
}

void VenueManager::addVenue(string venue_name, string location, int capacity) {
    int index = venueIndex(venue_name);

    if (index != no_of_venues) {
        cout << "-1\nError\n";
        return;
    }

    Venue* newVenuePtr = new Venue(venue_name, location, capacity);

    venues_list[no_of_venues++] = newVenuePtr;

    cout << "0\n";
}

void VenueManager::delVenue(string venue_name) {
    int index = venueIndex(venue_name);

    if (index == no_of_venues) {
        cout << "-1\nError\n";
        return;
    }

    delete venues_list[index];

    for (int i = index; i < no_of_venues - 1; i++) {
        venues_list[i] = venues_list[i + 1];
    }

    no_of_venues--;

    cout << "0\n";
}

void VenueManager::showVenues() const {
    cout << no_of_venues << endl;
    for (int i = 0; i < no_of_venues; i++) {
        Venue* venue = venues_list[i];
        cout << venue->name << " " << venue->location << " " << venue->capacity
             << endl;
    }
}