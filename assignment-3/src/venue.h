#include "congregation.h"
#ifndef VENUE_H
#define VENUE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Venue {
   public:
    string name;
    string city, state, postalCode, country;
    int capacity;

    /* Venue constructor */
    Venue(string name, string location, int capacity);

    /* Display venue */
    void displayVenue() const;
};

class VenueManager {
   private:
    vector<Venue> venueList;  // List of venues

    /* Returns index of venue if exists in country else -1 */
    int venueNameExists(string name, string country) const;

   public:
    /* Add venue */
    void addVenue(string name, string location, int capacity);

    /* Delete venue */
    void delVenue(string name, string country);

    /* Show venues */
    void showVenues(string location) const;

    friend class CongregationManager;
};

#endif