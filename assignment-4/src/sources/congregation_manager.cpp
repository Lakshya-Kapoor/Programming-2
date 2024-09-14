#include "../includes/congregation_manager.h"

#include <iostream>
#include <string>
#include <vector>

#include "../includes/congregation.h"
#include "../includes/macros.h"
#include "../includes/program.h"
#include "../includes/reservation.h"
#include "../includes/venue.h"
#include "../includes/venue_manager.h"

using namespace std;

int CongregationManager::congregationExists(string name) const {
    for (int i = 0; i < congregation_list.size(); i++) {
        if (congregation_list[i]->getName() == name) {
            return i;
        }
    }
    return -1;
}

void CongregationManager::addCongregation(string name, string congregation_type,
                                          Date start_date, Date end_date) {
    int index = congregationExists(name);

    // Congregation with this name already exists
    if (index != -1) {
        ERROR_OUTPUT;
    }

    Congregation* congregation_ptr = nullptr;
    if (congregation_type == "Games") {
        congregation_ptr = new Games(name, start_date, end_date);
    } else if (congregation_type == "Concert") {
        congregation_ptr = new Concert(name, start_date, end_date);
    } else if (congregation_type == "Convention") {
        congregation_ptr = new Convention(name, start_date, end_date);
    } else {
        congregation_ptr = new Conference(name, start_date, end_date);
    }

    congregation_list.push_back(congregation_ptr);
    SUCCESS_OUTPUT;
}

// TODO: delete any program reservations and the congregation
void CongregationManager::delCongregation(string name) {
    int index = congregationExists(name);

    // No congregation with this name exists
    if (index == -1) {
        ERROR_OUTPUT;
    }

    congregation_list.erase(congregation_list.begin() + index);
    SUCCESS_OUTPUT;
}

void CongregationManager::showCongregations() const {
    int n = congregation_list.size();

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << *congregation_list[i] << endl;
    }
}

void CongregationManager::addProgramToCong(string cong_name,
                                           string program_type,
                                           string program_name, Date start_date,
                                           Date end_date) const {
    int index = congregationExists(cong_name);

    // No congregation with this name exists
    if (index == -1) {
        ERROR_OUTPUT;
    }

    Congregation* congregation_ptr = congregation_list[index];

    if (!congregation_ptr->allowedProgramType(program_type) ||
        !(start_date >= congregation_ptr->getStartDate() &&
          end_date <= congregation_ptr->getEndDate())) {
        ERROR_OUTPUT;
    }

    congregation_ptr->addProgram(program_name, program_type, start_date,
                                 end_date);
}

void CongregationManager::delProgramFromCong(string cong_name,
                                             string program_name) const {
    int index = congregationExists(cong_name);

    // No congregation with this name exists
    if (index == -1) {
        ERROR_OUTPUT;
    }

    Congregation* congregation_ptr = congregation_list[index];
    congregation_ptr->delProgram(program_name);
}

void CongregationManager::showProgramsInCong(string cong_name) const {
    int index = congregationExists(cong_name);

    // No congregation with this name exists
    if (index == -1) {
        ERROR_OUTPUT;
    }

    Congregation* congregation_ptr = congregation_list[index];
    congregation_ptr->showPrograms();
}

void CongregationManager::reserveVenue(string ven_name, string country,
                                       string cong_name, string prog_name,
                                       VenueManager& ven_manager) {
    int index = congregationExists(cong_name);
    if (index == -1) {
        ERROR_OUTPUT;
    }
    Congregation* congregation_ptr = congregation_list[index];

    index = ven_manager.venueExists(ven_name, country);
    if (index == -1) {
        ERROR_OUTPUT;
    }
    Venue* venue_ptr = ven_manager.getVenue(index);

    index = congregation_ptr->programExists(prog_name);
    if (index == -1) {
        ERROR_OUTPUT;
    }
    Program* program_ptr = congregation_ptr->getProgram(index);

    if (!venue_ptr->allowedProgramType(program_ptr->getType())) {
        ERROR_OUTPUT;
    }

    if (venue_ptr->isReserved(program_ptr->getStartDate(),
                              program_ptr->getEndDate())) {
        ERROR_OUTPUT;
    }
    Reservation* new_reservation = new Reservation(venue_ptr, program_ptr);
    venue_ptr->addReservation(new_reservation);
    program_ptr->addReservation(new_reservation);
    SUCCESS_OUTPUT;
}

void CongregationManager::freeVenue(string ven_name, string country,
                                    string cong_name, string prog_name,
                                    VenueManager& ven_manager) {
    int index = congregationExists(cong_name);
    if (index == -1) {
        ERROR_OUTPUT;
    }
    Congregation* congregation_ptr = congregation_list[index];

    index = ven_manager.venueExists(ven_name, country);
    if (index == -1) {
        ERROR_OUTPUT;
    }
    Venue* venue_ptr = ven_manager.getVenue(index);

    index = congregation_ptr->programExists(prog_name);
    if (index == -1) {
        ERROR_OUTPUT;
    }
    Program* program_ptr = congregation_ptr->getProgram(index);
    Reservation* reservation_ptr = venue_ptr->getReservation(program_ptr);
    if (reservation_ptr == nullptr) {
        ERROR_OUTPUT;
    }
    venue_ptr->delReservation(reservation_ptr);
    program_ptr->delReservation(reservation_ptr);
    SUCCESS_OUTPUT;
}

// TODO complete showReserved
void CongregationManager::showReserved(string congregation_name) const {
    int index = congregationExists(congregation_name);
    if (index == -1) {
        ERROR_OUTPUT;
    }
    Congregation* congregation_ptr = congregation_list[index];
    congregation_ptr->showReservations();
}
