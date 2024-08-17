#include <iostream>
#include <string>
using namespace std;

#include "event.h"

Event::Event(string event_name, int start_time, int end_time) {
    this->name = event_name;
    this->start_time = start_time;
    this->end_time = end_time;
}