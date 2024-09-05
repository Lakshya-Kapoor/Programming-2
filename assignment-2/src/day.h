#include <iostream>
#include <string>
using namespace std;

#include "event.h"

#ifndef DAY_H
#define DAY_H

class Day {
   private:
    /* Checks for clashes with existing events */
    bool eventClashing(int start_time, int end_time) const;

    /* Checks whether event exists */
    bool eventExists(string event_name, int start_time) const;

   public:
    int no_of_events;       /* Number of events in a day */
    Event* events_list[24]; /*List of events in a day*/

    /* Day constructor */
    Day();

    /* Adding new event */
    void addEvent(string event_name, int start_time, int end_time);

    /* Deleting existing event */
    void delEvent(string event_name, int start_time);

    /* Displaying all events */
    void showEvents() const;

    /* Destructor */
    ~Day();
};

#endif