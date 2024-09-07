#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>

#include "date.h"

using namespace std;

class Program {
   private:
    string name;
    string type;
    Date start_date;
    Date end_date;

   public:
    Program(string name, string type, Date start_date, Date end_date);
    string getName() const;

    friend ostream& operator<<(ostream& os, const Program& program);
};

#endif