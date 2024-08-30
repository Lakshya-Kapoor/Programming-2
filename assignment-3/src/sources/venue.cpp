#include "../includes/venue.h"

#include <iostream>
#include <string>
#include <vector>

#include "../includes/location.h"
#include "../includes/utils.h"
using namespace std;

Venue::Venue(string name, Location location, int capacity)
    : name(name), location(location), capacity(capacity) {}

void Venue::displayVenue() const {
    cout << name << " " << location.locationString() << " " << capacity << endl;
}

int VenueManager::venueNameExists(string name, string country) const {
    int index = 0;
    for (Venue ven : venueList) {
        if (ven.location.getCountry() == country && ven.name == name) {
            return index;
        }
        index++;
    }
    return -1;
}

void VenueManager::addVenue(string name, Location location, int capacity) {
    int index = venueNameExists(name, location.getCountry());
    if (index != -1) {
        cout << -1 << "\n";
        return;
    }

    Venue newVenue(name, location, capacity);
    venueList.push_back(newVenue);

    cout << 0 << "\n";
}

// TODO venue can't be deleted if  any reservation for currently active or
// future congregation

void VenueManager::delVenue(string name, string country) {
    int index = venueNameExists(name, country);
    if (index == -1) {
        cout << -1 << "\n";
        return;
    }

    for (int i = index; i < venueList.size() - 1; i++) {
        venueList[i] = venueList[i + 1];
    }

    venueList.pop_back();

    cout << 0 << "\n";
}

void VenueManager::showVenues(string locationString) const {
    vector<string> res = parseLocationString(locationString);
    string city = res[0];
    string state = res[1];
    string postalCode = res[2];
    string country = res[3];

    // :::country
    bool type1 = (postalCode.empty() && !country.empty() && city.empty() &&
                  state.empty());

    // city:state::country
    bool type2 = (!city.empty() && !state.empty() && !country.empty() &&
                  postalCode.empty());

    // ::postal-code:country
    bool type3 = (!postalCode.empty() && !country.empty() && city.empty() &&
                  state.empty());

    // city:state:postal-code:country
    bool type4 = (!city.empty() && !state.empty() && !postalCode.empty() &&
                  !country.empty());

    vector<Venue> venuesToDisplay;

    for (Venue ven : venueList) {
        if (ven.location.getCountry() == country) {
            if (type4 && ven.location.getCity() == city &&
                ven.location.getState() == state &&
                ven.location.getPostalCode() == postalCode) {
                venuesToDisplay.push_back(ven);
            } else if (type3 && ven.location.getPostalCode() == postalCode) {
                venuesToDisplay.push_back(ven);
            } else if (type2 && ven.location.getCity() == city &&
                       ven.location.getState() == state) {
                venuesToDisplay.push_back(ven);
            } else if (type1) {
                venuesToDisplay.push_back(ven);
            }
        }
    }

    cout << venuesToDisplay.size() << "\n";
    for (Venue ven : venuesToDisplay) {
        ven.displayVenue();
    }
}