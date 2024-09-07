#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

class Location {
   private:
    string address, city, state, postalCode, country;

   public:
    Location(string address, string city, string state, string postalCode,
             string country);
    string getCountry() const;
    string getPostalCode() const;
    string getState() const;
    string getCity() const;

    friend ostream& operator<<(ostream& os, const Location& location);
};

#endif