#include <iostream>
#include <string>
using namespace std;

#ifndef EVENT_H
#define EVENT_H

class Event {
   public:
    string name;    /* Name of event*/
    int start_time; /* Start time of event */
    int end_time;   /* End time of event */

    /* Event constructor */
    Event(string event_name, int start_time, int end_time);

    /* Display event */
    void display() const;
};

#endif