#include "congregation.h"

#include <iostream>
#include <string>
#include <vector>

Congregation::Congregation(string name, string congregationType,
                           string startDate, string endDate) {
    this->name = name;
    this->congregationType = congregationType;
    this->startDate = startDate;
    this->endDate = endDate;
}

void Congregation::displayCongregation() const {
    cout << name << " ";
    cout << congregationType << " ";
    cout << startDate << " ";
    cout << endDate << endl;
}

int CongregationManager::CongregationExists(string name) const {
    for (int i = 0; i < congregationList.size(); i++) {
        if (congregationList[i].name == name) return i;
    }
    return -1;
}

// TODO add date format validation while parsing
void CongregationManager::addCongregation(string name, string congregationType,
                                          string startDate, string endDate) {
    int index = CongregationExists(name);
    if (index != -1) {
        cout << -1 << endl;
        return;
    }

    Congregation newCongregation(name, congregationType, startDate, endDate);
    congregationList.push_back(newCongregation);

    cout << 0 << endl;
}

// TODO delete all reservations of venues and the events
void CongregationManager::delCongregation(string name) {
    int index = CongregationExists(name);
    if (index == -1) {
        cout << -1 << endl;
        return;
    }

    for (int i = index; i < congregationList.size() - 1; i++) {
        congregationList[i] = congregationList[i + 1];
    }

    congregationList.pop_back();

    cout << 0 << endl;
}

void CongregationManager::showCongregations() const {
    int n = congregationList.size();

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        congregationList[i].displayCongregation();
    }
}