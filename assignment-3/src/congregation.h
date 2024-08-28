#ifndef CONGREGATION_H
#define CONGREGATION_H
#include <iostream>
#include <string>
#include <vector>

#include "venue.h"
using namespace std;

class Congregation {
   private:
    vector<Venue*> reservations;
    string name;
    string congregationType;
    string startDate;
    string endDate;

   public:
    /* Congregation constructor */
    Congregation(string name, string congregationType, string startDate,
                 string endDate);

    /* Show congregation */
    void displayCongregation() const;

    friend class CongregationManager;
};

class CongregationManager {
   private:
    vector<Congregation> congregationList;  // List of congregations

    /* Returns index of congregation if exists else -1 */
    int congregationExists(string name) const;

   public:
    /* Add congregation */
    void addCongregation(string name, string congregationType, string startDate,
                         string endDate);

    /* Delete congregation */
    void delCongregation(string name);

    /* Show congregations */
    void showCongregations() const;

    /* Reserve a venue */
    void reserveVenue(string venue_name, string country,
                      string congregation_name, VenueManager& venManager);

    /* Remove reservation from venue */
    void freeVenue(string venue_name, string country, string congregation_name);

    /* Show reservations */
    void showReserved(string name) const;
};

#endif