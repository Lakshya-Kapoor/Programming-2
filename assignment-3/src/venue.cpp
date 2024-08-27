#include "venue.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> parseLocation(string location) {
    int start = 0;
    int end = 0;

    vector<string> res;

    while (end < location.size()) {
        if (location[end] == ':') {
            res.push_back(location.substr(start, end - start));
            start = end + 1;
        }
        end++;
    }
    res.push_back(location.substr(start, end - start));
    return res;
}

Venue::Venue(string name, string location, int capacity) {
    this->name = name;
    this->capacity = capacity;
    vector<string> res = parseLocation(location);
    this->city = res[0];
    this->state = res[1];
    this->postalCode = res[2];
    this->country = res[3];
}

void Venue::displayVenue() const {
    cout << name << " " << city << ":" << state << ":" << postalCode << ":"
         << country << " " << capacity << endl;
}

int VenueManager::venueNameExists(string name, string country) const {
    int index = 0;
    for (Venue ven : venueList) {
        if (ven.country == country && ven.name == name) {
            return index;
        }
        index++;
    }
    return -1;
}

void VenueManager::addVenue(string name, string location, int capacity) {
    int index = venueNameExists(name, parseLocation(location)[3]);
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

void VenueManager::showVenues(string location) const {
    vector<string> res = parseLocation(location);
    string city = res[0];
    string state = res[1];
    string postalCode = res[2];
    string country = res[3];

    bool type1 = (postalCode.empty() && !country.empty() && city.empty() &&
                  state.empty());
    bool type2 = (!city.empty() && !state.empty() && !country.empty() &&
                  postalCode.empty());
    bool type3 = (!postalCode.empty() && !country.empty() && city.empty() &&
                  state.empty());
    bool type4 = (!city.empty() && !state.empty() && !postalCode.empty() &&
                  !country.empty());

    vector<Venue> venuesToDisplay;

    for (Venue ven : venueList) {
        if (ven.country == country) {
            if (type4 && ven.city == city && ven.state == state &&
                ven.postalCode == postalCode) {
                venuesToDisplay.push_back(ven);
            } else if (type3 && ven.postalCode == postalCode) {
                venuesToDisplay.push_back(ven);
            } else if (type2 && ven.city == city && ven.state == state) {
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