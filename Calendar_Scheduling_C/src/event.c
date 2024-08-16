#include "event.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "event_utils.h"
#include "venue.h"
#include "venue_utils.h"

void addEvent(char venue_name[], int event_date, int start_hour, int end_hour,
              char event_name[]) {
    int venue_index = venueExists(venue_name);

    if (venue_index == no_of_venues) {
        printf("-1\nError\n");
        return;
    }
    Venue* venue_to_add_event = venues[venue_index];
    Date* day = venue_to_add_event->calendar[event_date];

    int event_index = eventClash(venue_to_add_event, event_name, event_date,
                                 start_hour, end_hour);
    if (event_index != day->event_count) {
        printf("-1\nError\n");
        return;
    }
    Event* newEvent = (Event*)malloc(sizeof(Event));

    strcpy(newEvent->event_name, event_name);
    newEvent->start_hour = start_hour;
    newEvent->end_hour = end_hour;

    int index_to_insert = indexToInsert(day, start_hour, end_hour);

    for (int i = day->event_count; i > index_to_insert; i--) {
        day->events_list[i] = day->events_list[i - 1];
    }
    venue_to_add_event->total_events++;
    day->event_count++;
    day->events_list[index_to_insert] = newEvent;
    printf("0\n");
}

void delEvent(char venue_name[], int event_date, int start_hour,
              char event_name[]) {
    int venue_index = venueExists(venue_name);

    if (venue_index == no_of_venues) {
        printf("-1\nError\n");
        return;
    }
    Venue* venue_to_del_event = venues[venue_index];
    Date* day = venue_to_del_event->calendar[event_date];

    int event_index =
        eventExists(venue_to_del_event, event_name, event_date, start_hour);
    if (event_index == day->event_count) {
        printf("-1\nError\n");
        return;
    }

    free(day->events_list[event_index]);
    for (int i = event_index; i < day->event_count - 1; i++) {
        day->events_list[i] = day->events_list[i + 1];
    }
    day->event_count--;
    venue_to_del_event->total_events--;
    printf("0\n");
}

void showEvents(char venue_name[], int event_date) {
    int venue_index = venueExists(venue_name);

    if (venue_index == no_of_venues) {
        printf("-1\nError\n");
        return;
    }

    Venue found_venue = *venues[venue_index];

    printf("%d\n", found_venue.calendar[event_date]->event_count);
    for (int i = 0; i < found_venue.calendar[event_date]->event_count; i++) {
        Event event_to_display =
            *found_venue.calendar[event_date]->events_list[i];
        printf("%s %d %d\n", event_to_display.event_name,
               event_to_display.start_hour, event_to_display.end_hour);
    }
}

void showCalendar(char venue_name[]) {
    int venue_index = venueExists(venue_name);

    if (venue_index == no_of_venues) {
        printf("-1\nError\n");
        return;
    }

    Venue found_venue = *venues[venue_index];

    printf("%d\n", found_venue.total_events);

    for (int date = 1; date <= 30; date++) {
        int no_of_events = found_venue.calendar[date]->event_count;
        printf("%d %d\n", date, no_of_events);
        for (int i = 0; i < no_of_events; i++) {
            Event event_to_display =
                *found_venue.calendar[date]->events_list[i];
            printf("%s %d %d\n", event_to_display.event_name,
                   event_to_display.start_hour, event_to_display.end_hour);
        }
    }
}