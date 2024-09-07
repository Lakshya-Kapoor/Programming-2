#include "../includes/program.h"

#include <iostream>
#include <string>

using namespace std;

Program::Program(string name, string type, Date start_date, Date end_date)
    : name(name), type(type), start_date(start_date), end_date(end_date) {}

string Program::getName() const { return name; }

ostream& operator<<(ostream& os, const Program& program) {
    os << program.name << " " << program.type << " " << program.start_date
       << " " << program.end_date << endl;
    return os;
}