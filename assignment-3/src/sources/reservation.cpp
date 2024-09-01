#include "../includes/reservation.h"

#include <iostream>
#include <string>
#include <vector>

#include "../includes/event.h"
using namespace std;

/* Reservation constructor */
Reservation::Reservation(Date startDate, Date endDate,
                         Congregation* congregation, Venue* venue)
    : startDate(startDate),
      endDate(endDate),
      congregation(congregation),
      venue(venue),
      totalEvents(0) {
    this->events.resize(endDate - startDate + 1);
}

/* Returns start date of reservation */
Date Reservation::getStartDate() const { return startDate; }

/* Returns end date of reservation */
Date Reservation::getEndDate() const { return endDate; }

/* Returns congregation of reservation */
Congregation* Reservation::getCongregation() const { return congregation; }

/* Returns venue of reservation */
Venue* Reservation::getVenue() const { return venue; }

/* adds Event to the reservation in time sorted order */
void Reservation::addEvent(int index, Event* event) {
    // TODO: Need to add this in time sorted order and overlap check
    events[index].push_back(event);
    totalEvents++;
}

/* deletes Event from the reservation*/
void Reservation::delEvent(int index, Event* event) {
    for (int i = 0; i < events[index].size(); i++) {
        if (events[index][i] == event) {
            totalEvents--;
            events[index].erase(events[index].begin() + i);
            return;
        }
    }
}

/* Returns Event pointer if exists else nullptr */
Event* Reservation::getEvent(int index, Time startTime,
                             std::string eventName) const {
    for (int i = 0; i < events[index].size(); i++) {
        if (events[index][i]->getStartTime() == startTime &&
            events[index][i]->getName() == eventName) {
            return events[index][i];
        }
    }
    return nullptr;
}

/* Displays all the events on a particular index */
void Reservation::showEvents(int index) const {
    int noOfEvents = events[index].size();
    cout << noOfEvents << endl;
    for (int i = 0; i < noOfEvents; i++) {
        cout << *events[index][i];
    }
}

void Reservation::showCalendar() const {
    cout << totalEvents << endl;
    for (Date iterator = startDate; iterator <= endDate; iterator++) {
        cout << iterator.dateString() << " ";
        showEvents(iterator - startDate);
    }
}