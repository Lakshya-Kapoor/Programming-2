#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;

#include <iostream>

#include "date.h"

class Program;
class Venue;

class Reservation {
   private:
    Venue* venue;
    Program* program;
    Date start_date;
    Date end_date;

   public:
    Reservation(Venue* venue, Program* program);
    Date getStartDate() const;
    Date getEndDate() const;
    Venue* getVenue() const;
    Program* getProgram() const;

    friend ostream& operator<<(ostream& os, const Reservation& reservation);
};

#endif