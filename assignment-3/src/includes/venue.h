#ifndef VENUE_H
#define VENUE_H

#include <string>
#include <vector>

#include "date.h"
#include "location.h"
#include "time.h"

using namespace std;

class Reservation;

class Venue {
   private:
    string name;
    Location location;
    int capacity;
    vector<Reservation*> reservations; /* List of reservations */

   public:
    Venue(string name, Location location, int capacity);
    void displayVenue() const;
    bool isReserved(Date date) const;
    void addReservation(Reservation* reservation);
    void delReservation(Reservation* reservation);
    Reservation* getReservationByCongName(string name) const;

    friend class VenueManager;
    friend class CongregationManager;
};

class VenueManager {
   private:
    vector<Venue> venueList;  // List of venues

   public:
    int venueNameExists(string name, string country) const;
    void addVenue(string name, Location location, int capacity);
    void delVenue(string name, string country);
    void showVenues(string locationString) const;
    void addEvent(string congregation_name, string venue_name, string country,
                  Date date, Time startTime, Time endTime, string event_name);

    void delEvent(string congregation_name, string venue_name, string country,
                  Date date, Time startTime, string event_name);
    void showEvents(string venue_name, string country, Date date) const;
    void showCalendar(string congregation_name, string venue_name,
                      string country) const;

    friend class CongregationManager;
};

#endif