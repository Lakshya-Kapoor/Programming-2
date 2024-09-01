#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
   private:
    int hour, minute;

   public:
    Time();
    Time(int hour, int minute);
    Time operator-(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;
    bool operator>(const Time& other) const;
    int getHour() const;
    int getMinute() const;

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

#endif