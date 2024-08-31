#ifndef VENUE_H
#define VENUE_H

#include <string>
#include <vector>

#include "date.h"
#include "location.h"

class Reservation;

class Venue {
   private:
    std::string name;
    Location location;
    int capacity;
    std::vector<Reservation*> reservations; /* List of reservations */

   public:
    Venue(std::string name, Location location, int capacity);

    void displayVenue() const;

    bool isReserved(Date date) const;

    void addReservation(Reservation* reservation);

    friend class VenueManager;
};

class VenueManager {
   private:
    std::vector<Venue> venueList;  // List of venues

    int venueNameExists(std::string name, std::string country) const;

   public:
    void addVenue(std::string name, Location location, int capacity);

    void delVenue(std::string name, std::string country);

    void showVenues(std::string locationString) const;

    friend class CongregationManager;
};

#endif