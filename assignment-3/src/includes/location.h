#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Location {
   private:
    string city, state, postalCode, country;

   public:
    /* Location constructor */
    Location(string city, string state, string postalCode, string country);

    /* Returns location string "city:state:postal-code:country" */
    string locationString() const;

    string getCountry() const;
    string getPostalCode() const;
    string getState() const;
    string getCity() const;
};

#endif