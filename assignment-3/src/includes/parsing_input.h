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

#endif