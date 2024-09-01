#include "../includes/venue.h"

#define printError             \
    {                          \
        cout << "-1\nError\n"; \
        return;                \
    }

#include <iostream>
#include <string>
#include <vector>

#include "../includes/congregation.h"
#include "../includes/event.h"
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
        printError
    }

    Venue newVenue = Venue(name, location, capacity);
    venueList.push_back(newVenue);

    cout << "0\n";
}

/* Delete venue */
void VenueManager::delVenue(string name, string country) {
    int index = venueNameExists(name, country);
    if (index == -1) {
        printError
    }

    Date currDate = Date();
    // Checking whether venue is reserved in some future date
    for (int i = 0; i < venueList[index].reservations.size(); i++) {
        if (venueList[index].reservations[i]->getStartDate() <= currDate &&
            currDate <= venueList[index].reservations[i]->getEndDate()) {
            printError
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

    int type = getLocationType(city, state, postalCode, country);
    vector<Venue> venuesToDisplay;

    for (Venue ven : venueList) {
        if (ven.location.getCountry() == country) {
            if (type == 4 && ven.location.getCity() == city &&
                ven.location.getState() == state &&
                ven.location.getPostalCode() == postalCode) {
                venuesToDisplay.push_back(ven);
            } else if (type == 3 &&
                       ven.location.getPostalCode() == postalCode) {
                venuesToDisplay.push_back(ven);
            } else if (type == 2 && ven.location.getCity() == city &&
                       ven.location.getState() == state) {
                venuesToDisplay.push_back(ven);
            } else if (type == 1) {
                venuesToDisplay.push_back(ven);
            }
        }
    }

    cout << venuesToDisplay.size() << endl;
    for (Venue ven : venuesToDisplay) {
        ven.displayVenue();
    }
}

Reservation* Venue::getReservationByCongName(std::string name) const {
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i]->getCongregation()->getName() == name) {
            return reservations[i];
        }
    }
    return nullptr;
}

/* Add event */
void VenueManager::addEvent(string congregation_name, string venue_name,
                            string country, Date date, Time startTime,
                            Time endTime, string event_name) {
    int index = venueNameExists(venue_name, country);
    if (index == -1) {
        printError
    }
    Venue& venue = venueList[index];

    Reservation* reservation =
        venue.getReservationByCongName(congregation_name);

    // Congregation reservation does't exist or invalid date
    if (reservation == nullptr || !(reservation->getStartDate() <= date &&
                                    date <= reservation->getEndDate())) {
        printError
    }

    Event* event = new Event(event_name, date, startTime, endTime);
    reservation->addEvent(date - reservation->getStartDate(), event);
    cout << "0\n";
}

void VenueManager::delEvent(std::string congregation_name,
                            std::string venue_name, std::string country,
                            Date date, Time startTime, std::string event_name) {
    int index = venueNameExists(venue_name, country);
    if (index == -1) {
        printError
    }
    Venue& venue = venueList[index];

    Reservation* reservation =
        venue.getReservationByCongName(congregation_name);

    // Congregation reservation does't exist or invalid date
    if (reservation == nullptr || !(reservation->getStartDate() <= date &&
                                    date <= reservation->getEndDate())) {
        printError
    }

    Event* event = reservation->getEvent(date - reservation->getStartDate(),
                                         startTime, event_name);

    if (event == nullptr) {
        printError
    }
    reservation->delEvent(date - reservation->getStartDate(), event);
    delete event;
    cout << "0\n";
}

void VenueManager::showEvents(std::string venue_name, std::string country,
                              Date date) const {
    int index = venueNameExists(venue_name, country);
    if (index == -1) {
        printError
    }
    const Venue& venue = venueList[index];

    for (int i = 0; i < venue.reservations.size(); i++) {
        if (venue.reservations[i]->getStartDate() <= date &&
            date <= venue.reservations[i]->getEndDate()) {
            venue.reservations[i]->showEvents(
                date - venue.reservations[i]->getStartDate());
            break;
        }
    }
}

void VenueManager::showCalendar(string congregation_name, string venue_name,
                                string country) const {
    int index = venueNameExists(venue_name, country);
    if (index == -1) {
        printError
    }
    const Venue& venue = venueList[index];

    Reservation* reservation =
        venue.getReservationByCongName(congregation_name);

    reservation->showCalendar();
}