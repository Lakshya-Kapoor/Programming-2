#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>
#include <vector>

#include "date.h"

using namespace std;

class Reservation;

class Program {
   private:
    string name;
    string type;
    Date start_date;
    Date end_date;
    vector<Reservation*> reservations;

   public:
    Program(string name, string type, Date start_date, Date end_date);
    string getName() const;
    Date getStartDate() const;
    Date getEndDate() const;
    void addReservation(Reservation* reservation);
    void delReservation(Reservation* reservation);

    friend ostream& operator<<(ostream& os, const Program& program);
};

#endif