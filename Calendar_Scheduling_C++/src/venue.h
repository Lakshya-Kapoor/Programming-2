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
    Day* calendar[31]; /*Calendar*/

    /* Venue constructor */
    Venue(string venue_name, string venue_location, int capacity);
};

#endif