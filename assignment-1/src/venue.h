#ifndef VENUE_H
#define VENUE_H
typedef struct venue Venue;

#include "event.h"

struct venue {
    char venue_name[50];      // Name of venue
    char venue_location[50];  // Location of venue
    int venue_capacity;       // Capacity of venue
    Date* calendar[31];       // Represents the calendar of events
    int total_events;         // Total events scheduled in this venue
};

/* List of all venues */
extern Venue* venues[100];

/* Total no of venues */
extern int no_of_venues;

/*  Adding venue */
extern void addVenue(char name[], char location[], int capacity);

/* Deleting venue */
extern void delVenue(char name[], int printRes);

/* Show venues */
extern void showVenues(void);

#endif