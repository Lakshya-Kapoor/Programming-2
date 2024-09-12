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
    os << venue.name << " " << venue.location << " " << venue.getVenueType()
       << " " << venue.capacity;
    return os;
}

Hotel::Hotel(string name, Location location, int capacity)
    : Venue(name, location, capacity) {}

ConcertHall::ConcertHall(string name, Location location, int capacity)
    : Venue(name, location, capacity) {}

ConventionCenter::ConventionCenter(string name, Location location, int capacity)
    : Venue(name, location, capacity) {}

string ConventionCenter::getVenueType() const { return "Convention Center"; }
string ConcertHall::getVenueType() const { return "Concert Hall"; }
string Hotel::getVenueType() const { return "Hotel"; }