#ifndef DATE_H
#define DATE_H

#include <string>

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
    std::string dateString() const;
    bool operator==(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;
    void operator++(int n);
};

#endif