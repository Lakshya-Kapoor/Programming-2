#ifndef EVENT_H
#define EVENT_H
typedef struct event Event;
typedef struct date Date;

#include "venue.h"

struct date {
    Event* events_list[24];  // List of all events on a specific day
    int event_count;         // Count of events on a specific day
};

struct event {
    int start_hour;       // Event start time
    int end_hour;         // Event end time
    char event_name[50];  // Event name
};

/* Add event */
extern void addEvent(char venue_name[], int event_date, int start_hour,
                     int end_hour, char event_name[]);

/* Delete event */
extern void delEvent(char venue_name[], int event_date, int start_hour,
                     char event_name[]);

/* Show events of a venue on a specific date */
extern void showEvents(char venue_name[], int event_date);

/* Show all events of a venue */
extern void showCalendar(char venue_name[]);

#endif