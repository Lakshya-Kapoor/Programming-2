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

    // Congregation with same name already exists
    if (index != -1) {
        ERROR_OUTPUT;
    }

    Congregation* congregation_ptr = nullptr;
    if (congregation_type == "Games") {
        congregation_ptr = new Games();
    } else if (congregation_type == "Concert") {
        congregation_ptr = new Concert();
    } else if (congregation_type == "Convention") {
        congregation_ptr = new Convention();
    } else if (congregation_type == "Conference") {
        congregation_ptr = new Conference();
    } else {
        ERROR_OUTPUT;
    }

    congregation_list.push_back(congregation_ptr);
    SUCCESS_OUTPUT;
}
