#include "../includes/reservation.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Reservation constructor */
Reservation::Reservation(Date startDate, Date endDate,
                         Congregation* congregation, Venue* venue)
    : startDate(startDate),
      endDate(endDate),
      congregation(congregation),
      venue(venue) {}

/* Returns start date of reservation */
Date Reservation::getStartDate() const { return startDate; }

/* Returns end date of reservation */
Date Reservation::getEndDate() const { return endDate; }

/* Returns congregation of reservation */
Congregation* Reservation::getCongregation() const { return congregation; }

/* Returns venue of reservation */
Venue* Reservation::getVenue() const { return venue; }