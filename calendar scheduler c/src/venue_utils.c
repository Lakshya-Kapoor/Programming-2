#include "venue_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "venue.h"

int venueExists(char name[]) {
    for (int i = 0; i < no_of_venues; i++) {
        if (strcmp(venues[i]->venue_name, name) == 0) {
            return i;
        }
    }
    return no_of_venues;
}