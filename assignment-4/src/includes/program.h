#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>

#include "date.h"

using namespace std;

class Program {
   private:
    string name;
    string type;
    Date start_date;
    Date end_date;
};

#endif