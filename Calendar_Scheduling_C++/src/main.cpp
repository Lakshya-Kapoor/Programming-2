#include <bits/stdc++.h>

#include "venue.h"
#include "venue_manager.h"

using namespace std;

int main() {
    VenueManager manager;

    while (true) {
        cout << "Menu\n1. Add venue\n2. Delete Venue\n3. Show Venues\n";
        cout << "Enter option: ";
        int option;
        cin >> option;

        switch (option) {
            case 1: {
                string venue_name, venue_location;
                int capacity;

                cout << "Venue name: ";
                cin >> venue_name;
                cout << "Venue location: ";
                cin >> venue_location;
                cout << "Venue capacity: ";
                cin >> capacity;

                manager.addVenue(venue_name, venue_location, capacity);
                break;
            }
            case 2: {
                string venue_name;
                cout << "Venue name: ";
                cin >> venue_name;

                manager.delVenue(venue_name);
                break;
            }
            case 3: {
                manager.showVenues();
            }
        }
    }

    return 0;
}