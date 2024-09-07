#include "../includes/congregation.h"

#include <iostream>
#include <string>

using namespace std;

#include "../includes/date.h"
#include "../includes/macros.h"

// Congregation constructor
Congregation::Congregation(string name, Date start_date, Date end_date)
    : name(name), start_date(start_date), end_date(end_date) {}

// Conference constructor
Conference::Conference(string name, Date start_date, Date end_date)
    : Congregation(name, start_date, end_date) {
    programTypes = {"Workshop", "Main Conference", "Banquet"};
}

// Convention constructor
Convention::Convention(string name, Date start_date, Date end_date)
    : Congregation(name, start_date, end_date) {
    programTypes = {"Workshop", "Main Conference", "Banquet", "Food Court",
                    "Exhibition"};
}

// Games constructor
Games::Games(string name, Date start_date, Date end_date)
    : Congregation(name, start_date, end_date) {
    programTypes = {"Ceremony", "Track and field", "Indoor games",
                    "Water sports"};
}

// Concert constructor
Concert::Concert(string name, Date start_date, Date end_date)
    : Congregation(name, start_date, end_date) {
    programTypes = {"Pre-concert", "Main Concert"};
}

// Returns the name of the congregation
string Congregation::getName() const { return name; }

// Returns the start date of the congregation
Date Congregation::getStartDate() const { return start_date; }

// Returns the end date of the congregation
Date Congregation::getEndDate() const { return end_date; }

// Checks whether the given program type is valid for the congregation
bool Congregation::validProgramType(string program_type) const {
    for (int i = 0; i < programTypes.size(); i++) {
        if (programTypes[i] == program_type) {
            return true;
        }
    }
    return false;
}

int Congregation::programExists(string program_name) const {
    for (int i = 0; i < program_list.size(); i++) {
        if (program_list[i]->getName() == program_name) {
            return i;
        }
    }
    return -1;
}

void Congregation::addProgram(string program_name, string program_type,
                              Date start_date, Date end_date) {
    int index = programExists(program_name);

    if (index != -1) {
        ERROR_OUTPUT;
    }

    Program* newProgram =
        new Program(program_name, program_type, start_date, end_date);
    program_list.push_back(newProgram);
    SUCCESS_OUTPUT;
}

void Congregation::delProgram(string program_name) {
    int index = programExists(program_name);

    if (index == -1) {
        ERROR_OUTPUT;
    }

    // TODO: Delete any reservations made for this program

    delete program_list[index];
    program_list.erase(program_list.begin() + index);
    SUCCESS_OUTPUT;
}

void Congregation::showPrograms() const {
    int n = program_list.size();

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << *program_list[i];
    }
}

// Print congregation details
ostream& operator<<(ostream& os, const Congregation& congregation) {
    os << congregation.name << " ";
    os << congregation.getCongregationType() << " ";
    os << congregation.start_date << " " << congregation.end_date << endl;
    return os;
}

string Conference::getCongregationType() const { return "Conference"; }

string Convention::getCongregationType() const { return "Convention"; }

string Games::getCongregationType() const { return "Games"; }

string Concert::getCongregationType() const { return "Concert"; }
