#ifndef EVENT_H
#define EVENT_H

#include <string>

#include "date.h"
#include "time.h"

class Event {
   private:
    std::string name;
    Date date;
    Time startTime;
    Time endTime;

   public:
    Event(std::string name, Date date, Time startTime, Time endTime);
    std::string getName() const;
    Date getDate() const;
    Time getStartTime() const;
    Time getEndTime() const;
    friend std::ostream& operator<<(std::ostream& os, const Event& event);
};

#endif