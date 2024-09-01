#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

#include "date.h"
#include "time.h"

extern std::vector<std::string> parseLocationString(std::string locationString);
extern std::pair<bool, Date> validDate(std::string isoDateString);
extern int daysInMonth(int year, int month);
extern std::pair<bool, Time> validTime(std::string timeString);
extern bool validCongregaionType(std::string type);
extern int getLocationType(std::string city, std::string state,
                           std::string postalCode, std::string country);

#endif
