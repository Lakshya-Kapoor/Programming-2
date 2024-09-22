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
    this->events.resize((endDate - startDate) + 1);
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
bool Reservation::addEvent(int index, Event* event) {
    int left = 0;
    int right = events[index].size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (events[index][mid]->getStartTime() < event->getStartTime()) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    // Not adding in last position
    if (left != events[index].size() && ((events[index][left]->getStartTime() -
                                          event->getEndTime()) < Time(0, 30))) {
        return false;
    }
    // Adding in last position
    if (left == events[index].size() && index < events.size() - 1 &&
        events[index + 1].size() > 0) {
        Time diffNext = events[index + 1].front()->getStartTime() - Time(0, 0);
        Time diffCurr = Time(24, 0) - event->getEndTime();
        if (diffNext + diffCurr < Time(0, 30)) {
            return false;
        }
    }

    // Not adding in first position
    if (left != 0 && ((event->getStartTime() -
                       events[index][left - 1]->getEndTime()) < Time(0, 30))) {
        return false;
    }
    // Adding in first position
    if (left == 0 && index > 0 && events[index - 1].size() > 0) {
        Time diffPrev = Time(24, 0) - events[index - 1].back()->getEndTime();
        Time diffCurr = event->getStartTime() - Time(0, 0);
        if (diffPrev + diffCurr < Time(0, 30)) {
            return false;
        }
    }

    events[index].insert(events[index].begin() + left, event);
    totalEvents++;
    return true;
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

Reservation::~Reservation() {
    for (int i = 0; i < events.size(); i++) {
        for (int j = 0; j < events[i].size(); j++) {
            delete events[i][j];
        }
    }
}