#ifndef INPUT_PARSE_H
#define INPUT_PARSE_H

// Congregation functions

extern void parseAddCongregation(char* input);
extern void parseDeleteCongregation(char* input);
extern void parseShowCongregations();

// Program functions

extern void parseAddProgram(char* input);
extern void parseDeleteProgram(char* input);
extern void parseShowPrograms(char* input);

// Venue functions

extern void parseAddVenue(char* input);
extern void parseDeleteVenue(char* input);
extern void parseShowVenues(char* input);

// Venue functions

extern void parseReserveVenue(char* input);
extern void parseFreeVenue(char* input);
extern void parseShowReserved(char* input);

#endif