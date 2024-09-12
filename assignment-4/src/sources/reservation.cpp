#include "../includes/reservation.h"

#include <iostream>

#include "../includes/program.h"
#include "../includes/venue.h"

using namespace std;

Reservation::Reservation(Venue* venue, Program* program)
    : program(program), venue(venue) {}

Venue* Reservation::getVenue() const { return venue; }
Program* Reservation::getProgram() const { return program; }

ostream& operator<<(ostream& os, const Reservation& reservation) {
    Venue* venue = reservation.getVenue();
    os << venue->getName() << " " << venue->getLocation() << " "
       << venue->getCapacity();
}