#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

#include "date.h"

using namespace std;

extern vector<string> parseLocationString(string locationString);
extern pair<bool, Date> validDate(string isoDateString);
extern int daysInMonth(int year, int month);
extern bool validCongregaionType(string type);
extern bool validProgramType(string type);
extern int getLocationType(string city, string state, string postalCode,
                           string country);

#endif
