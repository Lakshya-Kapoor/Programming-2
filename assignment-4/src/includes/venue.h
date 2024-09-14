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

   public:
    Venue(string name, Location location, int capacity);
    string getName() const;
    Location getLocation() const;
    int getCapacity() const;
    bool allowedProgramType(string program_type) const;
    virtual string getVenueType() const = 0;
    bool isReserved(Date start_date, Date end_date) const;
    Reservation* getReservation(Program* program) const;
    void addReservation(Reservation* reservation);
    void delReservation(Reservation* reservation);

    friend ostream& operator<<(ostream& os, const Venue& venue);
};

class Hotel : public Venue {
   public:
    Hotel(string name, Location location, int capacity);
    string getVenueType() const override;
};

class ConcertHall : public Venue {
   public:
    ConcertHall(string name, Location location, int capacity);
    string getVenueType() const override;
};

class ConventionCenter : public Venue {
   public:
    ConventionCenter(string name, Location location, int capacity);
    string getVenueType() const override;
};

class Stadium : public Venue {
   public:
    Stadium(string name, Location location, int capacity, string stadiumType);
    string getVenueType() const override;
};

#endif