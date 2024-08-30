#ifndef CONGREGATION_H
#define CONGREGATION_H
#include <iostream>
#include <string>
#include <vector>

#include "date.h"
#include "venue.h"
using namespace std;

class Congregation {
   private:
    vector<Venue*> reservations; /* List of reservations */
    string name;
    string congregationType;
    Date startDate;
    Date endDate;

   public:
    Congregation(string name, string congregationType, Date startDate,
                 Date endDate);

    void displayCongregation() const;

    friend class CongregationManager;
};

class CongregationManager {
   private:
    vector<Congregation> congregationList;  // List of congregations

    int congregationExists(string name) const;

   public:
    void addCongregation(string name, string congregationType, Date startDate,
                         Date endDate);

    void delCongregation(string name);

    void showCongregations() const;

    void reserveVenue(string venue_name, string country,
                      string congregation_name, VenueManager& venManager);

    void freeVenue(string venue_name, string country, string congregation_name);

    void showReserved(string name) const;
};

#endif