#include "../includes/congregation.h"

#define printError          \
    {                       \
        cout << -1 << endl; \
        return;             \
    }

#define printSuccess \
    { cout << 0 << endl; }

#include <iostream>
#include <string>
#include <vector>

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

// TODO delete all reservations of venues and the events
/* Delete congregation */
void CongregationManager::delCongregation(string name) {
    int index = congregationExists(name);
    if (index == -1) {
        printError
    }

    for (int i = index; i < congregationList.size() - 1; i++) {
        congregationList[i] = congregationList[i + 1];
    }

    congregationList.pop_back();
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

// TODO: check whether venue is free for reservation in that duration
/* Reserve a venue */
void CongregationManager::reserveVenue(string venue_name, string country,
                                       string congregation_name,
                                       VenueManager& venManager) {
    int congIndex = congregationExists(congregation_name);
    int venIndex = venManager.venueNameExists(venue_name, country);
    if (congIndex == -1 || venIndex == -1) {
        printError
    }
    Venue& venue = venManager.venueList[venIndex];
    Congregation& congregation = congregationList[congIndex];

    // Checking whether venue is free to be reserved from start to end date
    Date dateIterator = congregation.startDate;
    while (!(dateIterator > congregation.endDate)) {
        if (venue.isReserved(dateIterator)) {
            printError
        }
        dateIterator++;
    }

    Reservation* newReservation = new Reservation(
        congregation.startDate, congregation.endDate, &congregation, &venue);

    congregation.reservations.push_back(newReservation);
    venue.addReservation(newReservation);
    printSuccess
}

/* Remove reservation from venue */
void CongregationManager::freeVenue(string venue_name, string country,
                                    string congregation_name) {}

/* Show reservations */
void CongregationManager::showReserved(string name) const {
    // int congIndex = congregationExists(name);
    // if (congIndex == -1) {
    //     printError
    // }

    // Congregation cong = congregationList[congIndex];
    // int noOfReservations = cong.reservations.size();

    // cout << noOfReservations << endl;
    // for (int i = 0; i < noOfReservations; i++) {
    //     cong.reservations[i]->displayVenue();
    // }
}
