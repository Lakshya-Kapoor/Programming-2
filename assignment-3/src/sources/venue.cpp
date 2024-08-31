#include "../includes/venue.h"

#include <iostream>
#include <string>
#include <vector>

#include "../includes/date.h"
#include "../includes/location.h"
#include "../includes/reservation.h"
#include "../includes/utils.h"
using namespace std;

/* Venue constructor */
Venue::Venue(string name, Location location, int capacity)
    : name(name), location(location), capacity(capacity) {}

/* Display venue */
void Venue::displayVenue() const {
    cout << name << " " << location.locationString() << " " << capacity << endl;
}

/* Checks whether venue is reserved on a particular date */
bool Venue::isReserved(Date date) const {
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i]->getStartDate() <= date &&
            date <= reservations[i]->getEndDate()) {
            return true;
        }
    }
    return false;
}

/* Add reservation to a venue */
void Venue::addReservation(Reservation* reservation) {
    reservations.push_back(reservation);
}

/* Delete reservation from a venue */
void Venue::delReservation(Reservation* reservation) {
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i] == reservation) {
            reservations.erase(reservations.begin() + i);
            break;
        }
    }
}

/* Returns index of venue if exists in a country else -1 */
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

/* Add venue */
void VenueManager::addVenue(string name, Location location, int capacity) {
    int index = venueNameExists(name, location.getCountry());
    if (index != -1) {
        cout << "-1\n";
        return;
    }

    Venue newVenue = Venue(name, location, capacity);
    venueList.push_back(newVenue);

    cout << "0\n";
}

/* Delete venue */
void VenueManager::delVenue(string name, string country) {
    int index = venueNameExists(name, country);
    if (index == -1) {
        cout << "-1\n";
        return;
    }

    Date currDate = Date();
    // Checking whether venue is reserved in some future date
    for (int i = 0; i < venueList[index].reservations.size(); i++) {
        if (venueList[index].reservations[i]->getStartDate() <= currDate &&
            currDate <= venueList[index].reservations[i]->getEndDate()) {
            cout << "-1\n";
            return;
        }
    }

    venueList.erase(venueList.begin() + index);

    cout << "0\n";
}

/* Show venues */
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

    cout << venuesToDisplay.size() << endl;
    for (Venue ven : venuesToDisplay) {
        ven.displayVenue();
    }
}
