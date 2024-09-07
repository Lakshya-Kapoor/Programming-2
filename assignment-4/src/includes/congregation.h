#ifndef CONGREGATION_H
#define CONGREGATION_H

#include <string>
#include <vector>

#include "date.h"
#include "program.h"
using namespace std;

class Congregation {
   private:
    string name;
    Date start_date;
    Date end_date;
    vector<Program*> program_list;

   protected:
    vector<string> programTypes;

   public:
    Congregation(string name, Date start_date, Date end_date);
    string getName() const;
    Date getStartDate() const;
    Date getEndDate() const;
    bool validProgramType(string program_type) const;
    virtual string getCongregationType() const = 0;
    int programExists(string program_name) const;
    void addProgram(string program_name, string program_type, Date start_date,
                    Date end_date);
    void delProgram(string program_name);
    void showPrograms() const;

    friend ostream& operator<<(ostream& os, const Congregation& congregation);
};

class Conference : public Congregation {
   public:
    Conference(string name, Date start_date, Date end_date);
    string getCongregationType() const override;
};

class Games : public Congregation {
   public:
    Games(string name, Date start_date, Date end_date);
    string getCongregationType() const override;
};

class Concert : public Congregation {
   public:
    Concert(string name, Date start_date, Date end_date);
    string getCongregationType() const override;
};

class Convention : public Congregation {
    // A convenHon will have everything that a conference has, plus:
    // i. Food and beverage stalls selling food and beverages to a]endees
    // (program type “Food Court”)
    // ii. One or more exhibiHons on diﬀerent themes with vendor exhibits
    // (program type “ExhibiHon”)
   public:
    Convention(string name, Date start_date, Date end_date);
    string getCongregationType() const override;
};

#endif