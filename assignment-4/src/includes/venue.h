#ifndef VENUE_H
#define VENUE_H

#include <iostream>
#include <string>
#include <vector>

#include "date.h"
#include "location.h"
using namespace std;

class Reservation;
class Program;

class Venue {
   private:
    string name;
    Location location;
    int capacity;
    vector<Reservation*> reservations;

   protected:
    vector<string> programTypes;
    string venue_type;

   public:
    Venue(string name, Location location, int capacity);
    string getName() const;
    Location getLocation() const;
    int getCapacity() const;
    vector<Reservation*> getAllReservations() const;
    bool allowedProgramType(string program_type) const;
    string getVenueType() const;
    bool isReserved(Date start_date, Date end_date) const;
    Reservation* getReservation(Program* program) const;
    void addReservation(Reservation* reservation);
    void delReservation(Reservation* reservation);

    friend ostream& operator<<(ostream& os, const Venue& venue);
};

class Hotel : public Venue {
   public:
    Hotel(string name, Location location, int capacity);
};

class ConcertHall : public Venue {
   public:
    ConcertHall(string name, Location location, int capacity);
};

class ConventionCenter : public Venue {
   public:
    ConventionCenter(string name, Location location, int capacity);
};

class Stadium : public Venue {
   public:
    Stadium(string name, Location location, int capacity, string stadiumType);
};

#endif