#include "../includes/program.h"

#include <iostream>
#include <string>

using namespace std;

#include "../includes/reservation.h"

Program::Program(string name, string type, Date start_date, Date end_date)
    : name(name),
      programType(type),
      start_date(start_date),
      end_date(end_date) {}

string Program::getName() const { return name; }
string Program::getType() const { return programType; }
Date Program::getStartDate() const { return start_date; }
Date Program::getEndDate() const { return end_date; }

void Program::addReservation(Reservation* reservation) {
    reservations.push_back(reservation);
}

void Program::delReservation(Reservation* reservation) {
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i] == reservation) {
            reservations.erase(reservations.begin() + i);
            break;
        }
    }
}

ostream& operator<<(ostream& os, const Program& program) {
    os << program.programType << " " << program.name << " "
       << program.start_date << " " << program.end_date;
    return os;
}