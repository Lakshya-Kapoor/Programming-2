#include "../includes/congregation.h"

#include <iostream>
#include <string>
#include <vector>

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
        cout << -1 << endl;
        return;
    }

    Congregation newCongregation(name, congregationType, startDate, endDate);
    congregationList.push_back(newCongregation);

    cout << 0 << endl;
}

// TODO delete all reservations of venues and the events
/* Delete congregation */
void CongregationManager::delCongregation(string name) {
    int index = congregationExists(name);
    if (index == -1) {
        cout << -1 << endl;
        return;
    }

    for (int i = index; i < congregationList.size() - 1; i++) {
        congregationList[i] = congregationList[i + 1];
    }

    congregationList.pop_back();

    cout << 0 << endl;
}

/* Show congregations */
void CongregationManager::showCongregations() const {
    int n = congregationList.size();

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        congregationList[i].displayCongregation();
    }
}

// TODO: store which congregation reserved the venue inside the venue object
// TODO: check whether venue is free for reservation in that duration
/* Reserve a venue */
void CongregationManager::reserveVenue(string venue_name, string country,
                                       string congregation_name,
                                       VenueManager& venManager) {
    int congIndex = congregationExists(congregation_name);
    int venIndex = venManager.venueNameExists(venue_name, country);
    if (congIndex == -1 || venIndex == -1) {
        cout << "-1\n";
        return;
    }
    Venue* venueToReserve = &venManager.venueList[venIndex];
    congregationList[congIndex].reservations.push_back(venueToReserve);

    cout << "0\n";
}

/* Remove reservation from venue */
void CongregationManager::freeVenue(string venue_name, string country,
                                    string congregation_name) {}

/* Show reservations */
void CongregationManager::showReserved(string name) const {
    int congIndex = congregationExists(name);
    if (congIndex == -1) {
        cout << "-1\n";
        return;
    }

    Congregation cong = congregationList[congIndex];
    int noOfReservations = cong.reservations.size();

    cout << noOfReservations << endl;
    for (int i = 0; i < noOfReservations; i++) {
        cong.reservations[i]->displayVenue();
    }
}

// Idea for the reservations is following
// Store which venue was reserved inside the congregation
// Also store which congregation reserved the venue inside the venue

// A better idea is to create a single reservation class
// Both the venue and the congregation have a reservation object
// Indicating the reservation was made by who and where was it made for
