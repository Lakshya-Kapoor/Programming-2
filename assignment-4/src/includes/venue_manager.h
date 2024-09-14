#ifndef VENUE_MANAGER_H
#define VENUE_MANAGER_H

#include <string>
#include <vector>

#include "location.h"

using namespace std;

class Venue;

class VenueManager {
   private:
    vector<Venue*> venue_list;

   public:
    int venueExists(string name, string country) const;
    Venue* getVenue(int index) const;
    void addVenue(string name, Location location, string type, int capacity);
    void delVenue(string name, string country);
    void showVenues(string locationString) const;
};

#endif