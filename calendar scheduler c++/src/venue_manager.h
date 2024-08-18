#include <iostream>
#include <string>
using namespace std;

#include "venue.h"

#ifndef VENUE_MANAGER_H
#define VENUE_MANAGER_H

class VenueManager {
   private:
    /* Returns index of venue */
    int venueIndex(string venue_name) const;

   public:
    int no_of_venues;        /* Number of venues */
    Venue* venues_list[100]; /* List of pointers to venue objects */

    /* Venue manager constructor */
    VenueManager();

    /* Creating a new venue */
    void addVenue(string venue_name, string location, int capacity);

    /* Deleting a venue */
    void delVenue(string venue_name);

    /* Displaying all venues */
    void showVenues() const;

    /* Adding an event to a venue */
    void addEvent(string venue_name, string event_name, int date,
                  int start_time, int end_time);

    /* Deleting an event from a venue */
    void delEvent(string venue_name, string event_name, int date,
                  int start_time);

    void showEvents(string venue_name, int date) const;

    void showCalendar(string venue_name) const;
};

#endif