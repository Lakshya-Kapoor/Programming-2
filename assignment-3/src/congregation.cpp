#include "congregation.h"

#include <iostream>
#include <string>
#include <vector>

Congregation::Congregation(string name, string congregationType,
                           string startDate, string endDate) {
    this->name = name;
    this->congregationType = congregationType;
    this->startDate = startDate;
    this->endDate = endDate;
}

void Congregation::displayCongregation() const {
    cout << name << " ";
    cout << congregationType << " ";
    cout << startDate << " ";
    cout << endDate << endl;
}

int CongregationManager::congregationExists(string name) const {
    for (int i = 0; i < congregationList.size(); i++) {
        if (congregationList[i].name == name) return i;
    }
    return -1;
}

void CongregationManager::addCongregation(string name, string congregationType,
                                          string startDate, string endDate) {
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

void CongregationManager::showCongregations() const {
    int n = congregationList.size();

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        congregationList[i].displayCongregation();
    }
}

// TODO: store which congregation reserved the venue inside the venue object
// TODO: check whether venue is free for reservation in that duration
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
