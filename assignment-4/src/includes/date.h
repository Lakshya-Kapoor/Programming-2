#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date {
   private:
    int year;
    int month;
    int day;

   public:
    Date();
    Date(int year, int month, int day);
    Date(const Date& other);
    Date& operator=(const Date& other);
    bool operator==(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;
    void operator++(int n);
    int operator-(const Date& other) const;
    friend ostream& operator<<(ostream& os, const Date& date);
};

#endif