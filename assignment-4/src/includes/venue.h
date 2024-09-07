#ifndef VENUE_H
#define VENUE_H

#include <string>

#include "location.h"
using namespace std;

class Venue {
   private:
    string name;
    Location location;
    int capacity;

   protected:
    string type;

   public:
    Venue(string name, Location location, int capacity);
    string getName() const;
    Location getLocation() const;
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

class Stadium : public Venue {};

#endif