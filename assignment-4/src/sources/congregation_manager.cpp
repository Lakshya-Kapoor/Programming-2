#include "../includes/congregation_manager.h"

#include <iostream>
#include <string>
#include <vector>

#include "../includes/macros.h"

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
    } else if (congregation_type == "Conference") {
        congregation_ptr = new Conference(name, start_date, end_date);
    } else {
        ERROR_OUTPUT;
    }

    congregation_list.push_back(congregation_ptr);
    SUCCESS_OUTPUT;
}

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
        cout << *congregation_list[i];
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

    if (!congregation_ptr->validProgramType(program_type) ||
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