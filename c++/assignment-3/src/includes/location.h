#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
   private:
    std::string address, city, state, postalCode, country;

   public:
    Location(std::string address, std::string city, std::string state,
             std::string postalCode, std::string country);
    std::string locationString() const;
    std::string getCountry() const;
    std::string getPostalCode() const;
    std::string getState() const;
    std::string getCity() const;
};

#endif