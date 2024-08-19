#include <iostream>
#include <string>
using namespace std;

#include "day.h"
#include "event.h"

Day::Day() {
    no_of_events = 0;
    for (int i = 0; i < 24; i++) {
        events_list[i] = nullptr;
    }
}

bool Day::eventClashing(int start_time, int end_time) const {
    for (int i = start_time; i < end_time; i++) {
        if (events_list[i] != nullptr) return true;
    }
    return false;
}

bool Day::eventExists(string event_name, int start_time) const {
    if (events_list[start_time] == nullptr) {
        return false;
    } else if (!(events_list[start_time]->name == event_name &&
                 events_list[start_time]->start_time == start_time)) {
        return false;
    }
    return true;
}

void Day::addEvent(string event_name, int start_time, int end_time) {
    if (eventClashing(start_time, end_time)) {
        cout << "-1\nError\n";
        return;
    }

    Event* newEventPtr = new Event(event_name, start_time, end_time);

    for (int i = start_time; i < end_time; i++) {
        events_list[i] = newEventPtr;
    }

    no_of_events++;

    cout << "0\n";
}
void Day::delEvent(string event_name, int start_time) {
    if (!eventExists(event_name, start_time)) {
        cout << "-1\nError\n";
        return;
    }

    Event* event = events_list[start_time];

    for (int i = event->start_time; i < event->end_time; i++) {
        events_list[i] = nullptr;
    }

    delete event;
    no_of_events--;

    cout << "0\n";
}

void Day::showEvents() const {
    cout << no_of_events << endl;

    int i = 0;
    while (i < 24) {
        if (events_list[i] == nullptr) {
            i++;
        } else {
            Event* event = events_list[i];
            cout << event->name << " " << event->start_time << " "
                 << event->end_time << endl;
            i = events_list[i]->end_time;
        }
    }
}

Day::~Day() {
    int i = 0;
    while (i < 24) {
        if (events_list[i] == nullptr) {
            i++;
        } else {
            i = events_list[i]->end_time;
            delete events_list[i];
        }
    }
}