#ifndef RESERVATION_H
#define RESERVATION_H

#include "congregation.h"
#include "date.h"
#include "venue.h"

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
};

#endif