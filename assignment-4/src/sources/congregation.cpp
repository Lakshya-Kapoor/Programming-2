#include "../includes/congregation.h"

#include <iostream>
#include <string>

using namespace std;

#include "../includes/date.h"

Congregation::Congregation(string name, Date start_date, Date end_date)
    : name(name), start_date(start_date), end_date(end_date) {}

string Congregation::getName() const { return name; }