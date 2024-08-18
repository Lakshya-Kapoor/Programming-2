#include <iostream>
#include <string>
using namespace std;

#define printError             \
    {                          \
        cout << "-1\nError\n"; \
        return;                \
    }

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
        printError
    }

    venues_list[no_of_venues++] = new Venue(venue_name, location, capacity);

    cout << "0\n";
}

void VenueManager::delVenue(string venue_name) {
    int index = venueIndex(venue_name);

    if (index == no_of_venues) {
        printError
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

void VenueManager::addEvent(string venue_name, string event_name, int date,
                            int start_time, int end_time) {
    int index = venueIndex(venue_name);

    if (index == no_of_venues) {
        printError
    }

    Day* dayToAddEvent = venues_list[index]->calendar[date];
    dayToAddEvent->addEvent(event_name, start_time, end_time);
}

void VenueManager::delEvent(string venue_name, string event_name, int date,
                            int start_time) {
    int index = venueIndex(venue_name);

    if (index == no_of_venues) {
        printError
    }

    Day* dayToDelEvent = venues_list[index]->calendar[date];
    dayToDelEvent->delEvent(event_name, start_time);
}

void VenueManager::showEvents(string venue_name, int date) const {
    int index = venueIndex(venue_name);

    if (index == no_of_venues) {
        printError
    }

    Day* dayToShowEvents = venues_list[index]->calendar[date];
    dayToShowEvents->showEvents();
}

void VenueManager::showCalendar(string venue_name) const {
    int index = venueIndex(venue_name);

    if (index == no_of_venues) {
        printError;
    }

    venues_list[index]->showCalendar();
}