#ifndef CONGREGATION_H
#define CONGREGATION_H

#include <string>
#include <vector>

#include "date.h"

class VenueManager;
class Reservation;

class Congregation {
   private:
    std::string name;
    std::string congregationType;
    Date startDate;
    Date endDate;
    std::vector<Reservation*> reservations;  // List of reservations

   public:
    Congregation(std::string name, std::string congregationType, Date startDate,
                 Date endDate);

    void displayCongregation() const;

    friend class CongregationManager;
};

class CongregationManager {
   private:
    std::vector<Congregation> congregationList;  // List of congregations

   public:
    int congregationExists(std::string name) const;

    void addCongregation(std::string name, std::string congregationType,
                         Date startDate, Date endDate);

    void delCongregation(std::string name, VenueManager& venManager);

    void showCongregations() const;

    void reserveVenue(std::string venue_name, std::string country,
                      std::string congregation_name, VenueManager& venManager);

    void freeVenue(std::string venue_name, std::string country,
                   std::string congregation_name, VenueManager& venManager);

    void showReserved(std::string name) const;
};

#endif
