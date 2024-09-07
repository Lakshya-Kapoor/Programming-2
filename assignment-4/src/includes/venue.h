#ifndef VENUE_H
#define VENUE_H

#include <string>
using namespace std;

class Location {};

class Venue {
   private:
    string name;
    Location location;
    int capacity;

   public:
    Venue(string name, Location location, int capacity);
};

class Hotel : public Venue {};

class ConcertHall : public Venue {};

class ConventionCenter : public Venue {};

class Stadium : public Venue {};

class OutdoorStadium : public Stadium {};

class IndoorStadium : public Stadium {};

class SwimmingPool : public Stadium {};

#endif