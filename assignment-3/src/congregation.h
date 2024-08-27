#ifndef CONGREGATION_H
#define CONGREGATION_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Congregation {
   public:
    string name;
    string congregationType;
    string startDate;
    string endDate;

    /* Congregation constructor */
    Congregation(string name, string congregationType, string startDate,
                 string endDate);

    /* Show congregation */
    void displayCongregation() const;
};

class CongregationManager {
   private:
    vector<Congregation> congregationList;  // List of congregations

    /* Returns index of congregation if exists else -1 */
    int CongregationExists(string name) const;

   public:
    /* Add congregation */
    void addCongregation(string name, string congregationType, string startDate,
                         string endDate);

    /* Delete congregation */
    void delCongregation(string name);

    /* Show congregations */
    void showCongregations() const;
};

#endif