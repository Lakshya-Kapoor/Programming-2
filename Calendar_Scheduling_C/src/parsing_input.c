#include "parsing_input.h"
#define printError             \
    {                          \
        printf("-1\nError\n"); \
        return;                \
    }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "event.h"
#include "venue.h"

void parseAddVenue(char* input) {
    char venue_name[50];
    char location[50];
    int capacity;
    int parsedItems = sscanf(input, "\"%[^\"]\" \"%[^\"]\" %d", venue_name,
                             location, &capacity);

    if (parsedItems < 3) {
        printError
    }

    addVenue(venue_name, location, capacity);
}

void parseDeleteVenue(char* input) {
    char venue_name[50];
    int parsedItems = sscanf(input, "\"%[^\"]\"", venue_name);
    if (parsedItems < 1) {
        printError
    }

    delVenue(venue_name, 1);
}

void parseShowVenues(char* input) { showVenues(); }

void parseAddEvent(char* input) {
    char venue_name[50];
    char event_name[50];
    int event_date, start_hour, end_hour;
    int parsedItems =
        sscanf(input, "\"%[^\"]\" %d %d %d \"%[^\"]\"", venue_name, &event_date,
               &start_hour, &end_hour, event_name);

    if (parsedItems < 5) {
        printError
    }
    if (!(event_date >= 1 && event_date <= 30) ||
        (start_hour < 0 || start_hour > 23) ||
        (end_hour < 0 || end_hour > 23) || (start_hour >= end_hour)) {
        printError
    }

    addEvent(venue_name, event_date, start_hour, end_hour, event_name);
}

void parseDeleteEvent(char* input) {
    char venue_name[50];
    char event_name[50];
    int event_date, start_hour;
    int parsedItems = sscanf(input, "\"%[^\"]\" %d %d \"%[^\"]\"", venue_name,
                             &event_date, &start_hour, event_name);

    if (parsedItems < 4) {
        printError
    }
    if (!(event_date >= 1 && event_date <= 30) ||
        (start_hour < 0 || start_hour > 23)) {
        printError
    }

    delEvent(venue_name, event_date, start_hour, event_name);
}

void parseShowEvents(char* input) {
    char venue_name[50];
    int event_date;
    int parsedItems = sscanf(input, "\"%[^\"]\" %d", venue_name, &event_date);

    if (parsedItems < 2) {
        printError
    }
    if (!(event_date >= 1 && event_date <= 30)) {
        printError
    }

    showEvents(venue_name, event_date);
}

void parseShowCalendar(char* input) {
    char venue_name[50];
    int parsedItems = sscanf(input, "\"%[^\"]\"", venue_name);

    if (parsedItems < 1) {
        printError
    }

    showCalendar(venue_name);
}