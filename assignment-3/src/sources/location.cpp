#include "../includes/location.h"

#include <iostream>
#include <string>
using namespace std;

Location::Location(string city, string state, string postalCode, string country)
    : city(city), state(state), postalCode(postalCode), country(country) {}

string Location::locationString() const {
    return city + ":" + state + ":" + postalCode + ":" + country;
}

string Location::getCountry() const { return country; }
string Location::getPostalCode() const { return postalCode; }
string Location::getState() const { return state; }
string Location::getCity() const { return city; }