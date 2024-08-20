#include <iostream>
#include <string>
using namespace std;

#include "day.h"

#ifndef VENUE_H
#define VENUE_H

class Venue {
   public:
    string name;       /* Venue name */
    string location;   /* Venue location */
    int capacity;      /* Venue capacity */
    Day* calendar[31]; /* Calendar of venue */

    /* Venue constructor */
    Venue(string venue_name, string location, int capacity);

    /* Display venue */
    void display() const;

    /* Show calendar */
    void showCalendar() const;

    /* Destructor */
    ~Venue();
};

#endif