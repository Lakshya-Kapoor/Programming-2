#include "congregation.h"
#include "location.h"
#ifndef VENUE_H
#define VENUE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Venue {
   private:
    string name;
    Location location;
    int capacity;

   public:
    /* Venue constructor */
    Venue(string name, Location location, int capacity);

    /* Display venue */
    void displayVenue() const;

    friend class VenueManager;
};

class VenueManager {
   private:
    vector<Venue> venueList;  // List of venues

    /* Returns index of venue if exists in country else -1 */
    int venueNameExists(string name, string country) const;

   public:
    /* Add venue */
    void addVenue(string name, Location location, int capacity);

    /* Delete venue */
    void delVenue(string name, string country);

    /* Show venues */
    void showVenues(string locationString) const;

    friend class CongregationManager;
};

#endif