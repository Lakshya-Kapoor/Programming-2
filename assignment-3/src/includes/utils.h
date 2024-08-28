#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern vector<string> parseLocation(string location);
extern vector<int> parseDate(string date);
extern bool validDate(string date);
extern bool validTime(int time);
extern bool validCongregaionType(string type);

#endif
