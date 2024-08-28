#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
   private:
    int year;
    int month;
    int day;

   public:
    // Converts iso date string to object
    Date(int year, int month, int day);

    // Creats new object of current date
    Date();

    // Returns iso date string from Date object
    string dateString() const;
};

#endif