#include "../includes/venue.h"

#include <iostream>
#include <string>

#include "../includes/program.h"
#include "../includes/reservation.h"

using namespace std;

Venue::Venue(string name, Location location, int capacity)
    : name(name), location(location), capacity(capacity) {}

string Venue::getName() const { return name; }

Location Venue::getLocation() const { return location; }

int Venue::getCapacity() const { return capacity; }

vector<Reservation*> Venue::getAllReservations() const { return reservations; }

string Venue::getVenueType() const { return venue_type; }

bool Venue::allowedProgramType(string program_type) const {
    for (int i = 0; i < programTypes.size(); i++) {
        if (programTypes[i] == program_type) {
            return true;
        }
    }
    return false;
}

bool Venue::isReserved(Date start_date, Date end_date) const {
    for (int i = 0; i < reservations.size(); i++) {
        Date res_start = reservations[i]->getProgram()->getStartDate();
        Date res_end = reservations[i]->getProgram()->getEndDate();
        if ((res_start <= start_date && start_date <= res_end) ||
            (res_start <= end_date && end_date <= res_end) ||
            (res_start >= start_date && res_end <= end_date)) {
            return true;
        }
    }
    return false;
}

void Venue::addReservation(Reservation* reservation) {
    reservations.push_back(reservation);
}

Reservation* Venue::getReservation(Program* program) const {
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i]->getProgram() == program) return reservations[i];
    }
    return nullptr;
}

void Venue::delReservation(Reservation* reservation) {
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i] == reservation) {
            reservations.erase(reservations.begin() + i);
            break;
        }
    }
}

ostream& operator<<(ostream& os, const Venue& venue) {
    os << venue.name << " " << venue.location << " " << venue.venue_type << " "
       << venue.capacity;
    return os;
}

Hotel::Hotel(string name, Location location, int capacity)
    : Venue(name, location, capacity) {
    venue_type = "Hotel";
    programTypes = {"Workshop", "Main Conference", "Banquet", "Food Court",
                    "Exhibition"};
}

ConcertHall::ConcertHall(string name, Location location, int capacity)
    : Venue(name, location, capacity) {
    venue_type = "Concert Hall";
    programTypes = {"Pre-concert", "Main Concert"};
}

ConventionCenter::ConventionCenter(string name, Location location, int capacity)
    : Venue(name, location, capacity) {
    venue_type = "Convention Center";
    programTypes = {"Pre-concert",     "Main Concert", "Workshop",
                    "Main Conference", "Banquet",      "Food Court",
                    "Exhibition"};
}

Stadium::Stadium(string name, Location location, int capacity,
                 string stadiumType)
    : Venue(name, location, capacity) {
    venue_type = stadiumType;
    if (stadiumType == "Outdoor Stadium") {
        programTypes = {"Ceremony",     "Track and field", "Pre-concert",
                        "Main Concert", "Food Court",      "Exhibition"};
    } else if (stadiumType == "Indoor Stadium") {
        programTypes = {"Ceremony", "Indoor games"};
    } else if (stadiumType == "Swimming Pool") {
        programTypes = {"Ceremony", "Water Sports"};
    }
}
