#include "venue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "venue_utils.h"

Venue* venues[100];
int no_of_venues = 0;

void addVenue(char name[], char location[], int capacity) {
    int venue_index = venueExists(name);

    if (venue_index != no_of_venues) {
        printf("-1\nError\n");
        return;
    }

    Venue* newVenue = (Venue*)malloc(sizeof(Venue));

    strcpy(newVenue->venue_name, name);
    strcpy(newVenue->venue_location, location);
    newVenue->venue_capacity = capacity;
    newVenue->total_events = 0;
    for (int i = 0; i < 31; i++) {
        newVenue->calendar[i] = (Date*)malloc(sizeof(Date));
        newVenue->calendar[i]->event_count = 0;
    }

    venues[no_of_venues++] = newVenue;
    printf("0\n");
}

void delVenue(char name[], int printRes) {
    int venue_index = venueExists(name);

    if (venue_index == no_of_venues) {
        printf("-1\nError\n");
        return;
    }
    for (int i = 0; i < 31; i++) {
        Date* day = venues[venue_index]->calendar[i];
        for (int j = 0; j < day->event_count; j++) {
            free(day->events_list[j]);
        }
        free(day);
    }
    // Free the entire venue
    free(venues[venue_index]);
    for (int i = venue_index; i < no_of_venues - 1; i++) {
        venues[i] = venues[i + 1];
    }
    no_of_venues--;
    if (printRes) {
        printf("0\n");
    }
}

void showVenues() {
    printf("%d\n", no_of_venues);
    for (int i = 0; i < no_of_venues; i++) {
        printf("%s %s %d\n", venues[i]->venue_name, venues[i]->venue_location,
               venues[i]->venue_capacity);
    }
}