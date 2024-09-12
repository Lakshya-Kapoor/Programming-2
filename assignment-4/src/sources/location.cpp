#include "../includes/location.h"

#include <iostream>
#include <string>
using namespace std;

/* Location constructor */
Location::Location(string address, string city, string state, string postalCode,
                   string country)
    : address(address),
      city(city),
      state(state),
      postalCode(postalCode),
      country(country) {}

/* Prints location string "address:city:state:postal-code:country" */
ostream& operator<<(ostream& os, const Location& location) {
    os << location.address << ":" << location.city << ":" << location.state
       << ":" << location.postalCode << ":" << location.country;
    return os;
}

/* Get country */
string Location::getCountry() const { return country; }

/* Get postal-code */
string Location::getPostalCode() const { return postalCode; }

/* Get state */
string Location::getState() const { return state; }

/* Get city */
string Location::getCity() const { return city; }