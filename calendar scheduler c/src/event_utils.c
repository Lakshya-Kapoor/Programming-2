#include "event_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eventExists(Venue* venue, char event_name[], int event_date,
                int start_hour) {
    Date* day = venue->calendar[event_date];

    for (int j = 0; j < day->event_count; j++) {
        if ((strcmp(day->events_list[j]->event_name, event_name) == 0) &&
            (day->events_list[j]->start_hour == start_hour))
            return j;
    }
    return day->event_count;
}

int eventClash(Venue* venue, char event_name[], int event_date, int start_hour,
               int end_hour) {
    Date* day = venue->calendar[event_date];
    for (int j = 0; j < day->event_count; j++) {
        int event_start = day->events_list[j]->start_hour;
        int event_end = day->events_list[j]->end_hour;
        if ((start_hour <= event_start && end_hour > event_start) ||
            (start_hour < event_end && event_end <= end_hour) ||
            (start_hour >= event_start && end_hour <= event_end)) {
            return j;
        }
    }
    return day->event_count;
}

int indexToInsert(Date* day, int start_hour, int end_hour) {
    if (day->event_count == 0) {
        return 0;
    }

    int low = 0, high = day->event_count - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (day->events_list[mid]->start_hour <= start_hour) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}