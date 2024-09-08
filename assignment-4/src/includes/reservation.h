#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;

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
    Venue* getVenue() const;
    Program* getProgram() const;
};

#endif