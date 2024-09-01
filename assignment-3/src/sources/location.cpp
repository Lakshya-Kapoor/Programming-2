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

/* Returns location string "city:state:postal-code:country" */
string Location::locationString() const {
    return address + ":" + city + ":" + state + ":" + postalCode + ":" +
           country;
}

/* Get country */
string Location::getCountry() const { return country; }

/* Get postal-code */
string Location::getPostalCode() const { return postalCode; }

/* Get state */
string Location::getState() const { return state; }

/* Get city */
string Location::getCity() const { return city; }