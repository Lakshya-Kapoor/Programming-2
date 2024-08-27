#ifndef VENUE_H
#define VENUE_H

class Venue {
   public:
    string name;
    string city, state, postalCode, country;
    int capacity;

    /* Venue constructor */
    Venue(string name, string location, int capacity);

    /* Display venue */
    void displayVenue() const;
};

class VenueManager {
   private:
    vector<Venue> venueList;  // List of venues

    /* Returns index of venue if exists in country else -1 */
    int venueNameExists(string name, string country) const;

   public:
    void addVenue(string name, string location, int capacity); /* Add venue */
    void delVenue(string name, string country); /* Delete venue */
    void showVenues(string location) const;     /* Show venues */
};

#endif