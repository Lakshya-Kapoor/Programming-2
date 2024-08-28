#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

#include "date.h"

using namespace std;

extern vector<string> parseLocation(string location);
extern pair<bool, Date> validDate(string isoDate);
extern bool validTime(int time);
extern bool validCongregaionType(string type);

#endif
