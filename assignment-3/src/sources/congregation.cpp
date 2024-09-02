#include "../includes/congregation.h"

#define printError                   \
    {                                \
        cout << "-1\nError" << endl; \
        return;                      \
    }

#define printSuccess \
    { cout << 0 << endl; }

#include <iostream>
#include <string>
#include <vector>

#include "../includes/reservation.h"
#include "../includes/venue.h"

using namespace std;

/* Congregation constructor */
Congregation::Congregation(string name, string congregationType, Date startDate,
                           Date endDate)
    : name(name),
      congregationType(congregationType),
      startDate(startDate),
      endDate(endDate) {}

/* Print the congregation name, type, start and end date */
void Congregation::displayCongregation() const {
    cout << name << " ";
    cout << congregationType << " ";
    cout << startDate.dateString() << " ";
    cout << endDate.dateString() << endl;
}

/* Get congregation name */
string Congregation::getName() const { return name; }

/* Returns index of congregation if exists else -1 */
int CongregationManager::congregationExists(string name) const {
    for (int i = 0; i < congregationList.size(); i++) {
        if (congregationList[i].name == name) return i;
    }
    return -1;
}

/* Add congregation */
void CongregationManager::addCongregation(string name, string congregationType,
                                          Date startDate, Date endDate) {
    int index = congregationExists(name);
    if (index != -1) {
        printError
    }

    Congregation newCongregation(name, congregationType, startDate, endDate);
    congregationList.push_back(newCongregation);
    printSuccess
}

/* Delete congregation */
void CongregationManager::delCongregation(string name,
                                          VenueManager& venManager) {
    int index = congregationExists(name);
    if (index == -1) {
        printError
    }

    // Freeing all the reserved venues
    vector<Reservation*> reservations = congregationList[index].reservations;
    for (int i = 0; i < reservations.size(); i++) {
        string venueName = reservations[i]->getVenue()->name;
        string countryName = reservations[i]->getVenue()->location.getCountry();
        freeVenue(venueName, countryName, name, venManager, false);
    }

    congregationList.erase(congregationList.begin() + index);

    printSuccess
}

/* Show congregations */
void CongregationManager::showCongregations() const {
    int n = congregationList.size();

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        congregationList[i].displayCongregation();
    }
}

/* Reserve a venue */
void CongregationManager::reserveVenue(string venue_name, string country,
                                       string congregation_name,
                                       VenueManager& venManager) {
    int congIndex = congregationExists(congregation_name);
    int venIndex = venManager.venueNameExists(venue_name, country);
    if (congIndex == -1 || venIndex == -1) {
        printError
    }
    Venue* venue = &venManager.venueList[venIndex];
    Congregation* congregation = &congregationList[congIndex];
    // Checking whether venue is free to be reserved from start to end date
    Date dateIterator = congregation->startDate;
    while (dateIterator <= congregation->endDate) {
        if (venue->isReserved(dateIterator)) {
            printError
        }
        dateIterator++;
    }

    Reservation* newReservation = new Reservation(
        congregation->startDate, congregation->endDate, congregation, venue);

    congregation->reservations.push_back(newReservation);
    venue->addReservation(newReservation);
    printSuccess
}

/* Remove reservation from venue and congregation*/
void CongregationManager::freeVenue(string venue_name, string country,
                                    string congregation_name,
                                    VenueManager& venManager, bool printOut) {
    int congIndex = congregationExists(congregation_name);
    int venIndex = venManager.venueNameExists(venue_name, country);
    if (congIndex == -1 || venIndex == -1) {
        printError
    }

    Congregation& cong = congregationList[congIndex];
    Venue& venue = venManager.venueList[venIndex];

    Reservation* reservation = nullptr;
    for (int i = 0; i < cong.reservations.size(); i++) {
        if (cong.reservations[i]->getVenue() == &venue) {
            reservation = cong.reservations[i];
            cong.reservations.erase(cong.reservations.begin() + i);
            break;
        }
    }
    // No reservation made by congregation in this venue
    if (reservation == nullptr) {
        printError
    }
    venue.delReservation(reservation);
    delete reservation;

    if (printOut) printSuccess
}

/* Show reservations */
void CongregationManager::showReserved(string name) const {
    int congIndex = congregationExists(name);
    if (congIndex == -1) {
        printError
    }

    Congregation congregation = congregationList[congIndex];
    int noOfReservations = congregation.reservations.size();

    cout << noOfReservations << endl;
    for (int i = 0; i < noOfReservations; i++) {
        congregation.reservations[i]->getVenue()->displayVenue();
    }
}
