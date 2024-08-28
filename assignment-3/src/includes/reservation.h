#include "congregation.h"
#include "date.h"
#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation {
   private:
    Date date;
    Congregation* congregation;
};

#endif