#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

#include "date.h"

extern std::vector<std::string> parseLocationString(std::string locationString);
extern std::pair<bool, Date> validDate(std::string isoDateString);
extern int daysInMonth(int year, int month);
extern bool validTime(int time);
extern bool validCongregaionType(std::string type);

#endif
