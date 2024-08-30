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
    Venue(string name, Location location, int capacity);

    void displayVenue() const;

    friend class VenueManager;
};

class VenueManager {
   private:
    vector<Venue> venueList;  // List of venues

    int venueNameExists(string name, string country) const;

   public:
    void addVenue(string name, Location location, int capacity);

    void delVenue(string name, string country);

    void showVenues(string locationString) const;

    friend class CongregationManager;
};

#endif