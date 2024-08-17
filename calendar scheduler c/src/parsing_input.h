#ifndef PARSING_INPUT_H
#define PARSING_INPUT_H

/* Parsing add venue command */
extern void parseAddVenue(char* input);

/* Parsing delete venue command */
extern void parseDeleteVenue(char* input);

/* Parsing show venues command */
extern void parseShowVenues(char* input);

/* Parsing add event command */
extern void parseAddEvent(char* input);

/* Parsing delete event command */
extern void parseDeleteEvent(char* input);

/* Parsing show events command */
extern void parseShowEvents(char* input);

/* Parsing show calendar command */
extern void parseShowCalendar(char* input);

#endif