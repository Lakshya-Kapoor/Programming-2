#ifndef EVENT_UTILS_H
#define EVENT_UTILS_H

#include "venue.h"

/* Check if event exists */
extern int eventExists(Venue* venue, char event_name[], int event_date,
                       int start_hour);

/* Check if event clashes with existing events */
extern int eventClash(Venue* venue, char event_name[], int event_date,
                      int start_hour, int end_hour);

/* Find index to insert new event into */
extern int indexToInsert(Date* day, int start_hour, int end_hour);

#endif