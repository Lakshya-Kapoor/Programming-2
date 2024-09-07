#include "../includes/venue_manager.h"

#include <iostream>
#include <string>
#include <vector>

#include "../includes/macros.h"
#include "../includes/venue.h"

using namespace std;

int VenueManager::venueExists(string name, string country) const {
    for (int i = 0; i < venue_list.size(); i++) {
        if (venue_list[i]->getName() == name &&
            venue_list[i]->getLocation().getCountry() == country) {
            return i;
        }
    }
    return -1;
}

void VenueManager::addVenue(string name, Location location, string type,
                            int capacity) {
    int index = venueExists(name, location.getCountry());

    // Venue with this name and country already exists
    if (index != -1) {
        ERROR_OUTPUT;
    }

    Venue* venue_ptr = nullptr;

    if (type == "Hotel") {
        venue_ptr = new Hotel(name, location, capacity);
    } else if (type == "Convention Center") {
        venue_ptr = new ConventionCenter(name, location, capacity);
    } else if (type == "Concert Hall") {
        venue_ptr = new ConcertHall(name, location, capacity);
    } else if (type == "Outdoor Stadium" || type == "Indoor Stadium" ||
               type == "Swimming Pool") {
    } else {
        ERROR_OUTPUT;
    }

    venue_list.push_back(venue_ptr);
    SUCCESS_OUTPUT;
}

void VenueManager::delVenue(string name, string country) {
    int index = venueExists(name, country);

    // Venue with this indec and country doesn't exist
    if (index == -1) {
        ERROR_OUTPUT;
    }

    // TODO may have to check some other conditions before deleting the venue

    delete venue_list[index];
    venue_list.erase(venue_list.begin() + index);
    SUCCESS_OUTPUT;
}
