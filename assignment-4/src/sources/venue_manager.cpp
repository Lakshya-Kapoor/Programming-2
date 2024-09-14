#include "../includes/venue_manager.h"

#include <iostream>
#include <string>
#include <vector>

#include "../includes/macros.h"
#include "../includes/utils.h"
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

Venue* VenueManager::getVenue(int index) const { return venue_list[index]; }

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
        venue_ptr = new Stadium(name, location, capacity, type);
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

void VenueManager::showVenues(string locationString) const {
    vector<string> res = parseLocationString(locationString);
    string city = res[0];
    string state = res[1];
    string postalCode = res[2];
    string country = res[3];

    int type = getLocationType(city, state, postalCode, country);
    vector<Venue*> venuesToDisplay;

    for (auto ven : venue_list) {
        if (ven->getLocation().getCountry() == country) {
            if (type == 4 && ven->getLocation().getCity() == city &&
                ven->getLocation().getState() == state &&
                ven->getLocation().getPostalCode() == postalCode) {
                venuesToDisplay.push_back(ven);
            } else if (type == 3 &&
                       ven->getLocation().getPostalCode() == postalCode) {
                venuesToDisplay.push_back(ven);
            } else if (type == 2 && ven->getLocation().getCity() == city &&
                       ven->getLocation().getState() == state) {
                venuesToDisplay.push_back(ven);
            } else if (type == 1) {
                venuesToDisplay.push_back(ven);
            }
        }
    }

    cout << venuesToDisplay.size() << endl;
    for (Venue* ven : venuesToDisplay) {
        cout << *ven << endl;
    }
}
