#ifndef PARSING_INPUT_H
#define PARSING_INPUT_H

/* Congregation-related functions */

extern void parseAddCongregation(char *input);
extern void parseDelCongregation(char *input);
extern void parseShowCongregations(char *input);

/* Venue-related functions */

extern void parseAddVenue(char *input);
extern void parseDelVenue(char *input);
extern void parseShowVenues(char *input);

/* Reservation-related functions */

extern void parseReserveVenue(char *input);
extern void parseFreeVenue(char *input);
extern void parseShowReserved(char *input);

/*  Event-related functions */
extern void parseAddEvent(char *input);
extern void parseDelEvent(char *input);
extern void parseShowEvents(char *input);
extern void parseShowCalendar(char *input);

#endif