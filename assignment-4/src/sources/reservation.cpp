#include "../includes/reservation.h"

#include <iostream>

#include "../includes/program.h"
#include "../includes/venue.h"

using namespace std;

Reservation::Reservation(Venue* venue, Program* program)
    : program(program), venue(venue) {}

Venue* Reservation::getVenue() const { return venue; }
Program* Reservation::getProgram() const { return program; }
Date Reservation::getStartDate() const { return start_date; }
Date Reservation::getEndDate() const { return end_date; }

ostream& operator<<(ostream& os, const Reservation& reservation) {
    Venue* venue = reservation.getVenue();
    os << venue->getName() << " " << venue->getLocation() << " "
       << venue->getVenueType() << " " << venue->getCapacity();
    return os;
}