#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Location {
   private:
    string city, state, postalCode, country;

   public:
    Location(string city, string state, string postalCode, string country);
    string locationString() const;
    string getCountry() const;
    string getPostalCode() const;
    string getState() const;
    string getCity() const;
};

#endif