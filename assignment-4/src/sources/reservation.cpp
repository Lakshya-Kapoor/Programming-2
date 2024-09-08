#include "../includes/reservation.h"

#include <iostream>

#include "../includes/program.h"
#include "../includes/venue.h"

using namespace std;

Reservation::Reservation(Venue* venue, Program* program)
    : program(program), venue(venue) {}

Venue* Reservation::getVenue() const { return venue; }
Program* Reservation::getProgram() const { return program; }
