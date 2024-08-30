#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

#include "date.h"

using namespace std;

extern vector<string> parseLocationString(string locationString);
extern pair<bool, Date> validDate(string isoDate);
extern bool validTime(int time);
extern bool validCongregaionType(string type);

#endif
