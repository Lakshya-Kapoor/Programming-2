#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>

#include "date.h"
#include "time.h"

class Congregation;
class Venue;
class Event;

class Reservation {
   private:
    Date startDate;
    Date endDate;
    Congregation* congregation;
    Venue* venue;
    std::vector<std::vector<Event*>> events;
    int totalEvents;

   public:
    Reservation(Date startDate, Date endDate, Congregation* congregation,
                Venue* venue);
    Date getStartDate() const;
    Date getEndDate() const;
    Congregation* getCongregation() const;
    Venue* getVenue() const;
    void addEvent(int index, Event* event);
    void delEvent(int index, Event* event);
    void showEvents(int index) const;
    void showCalendar() const;
    Event* getEvent(int index, Time startTime, std::string eventName) const;
};

#endif