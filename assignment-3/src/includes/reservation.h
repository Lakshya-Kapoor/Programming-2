#ifndef RESERVATION_H
#define RESERVATION_H

#include "date.h"

class Congregation;
class Venue;

class Reservation {
   private:
    Date startDate;
    Date endDate;
    Congregation* congregation;
    Venue* venue;

   public:
    Reservation(Date startDate, Date endDate, Congregation* congregation,
                Venue* venue);
    Date getStartDate() const;
    Date getEndDate() const;
    Congregation* getCongregation() const;
    Venue* getVenue() const;
};

#endif