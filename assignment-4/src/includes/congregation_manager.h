#ifndef CONGREGATION_MANAGER_H
#define CONGREGATION_MANAGER_H

#include <string>
#include <vector>

using namespace std;

#include "congregation.h"
#include "date.h"

class CongregationManager {
   private:
    vector<Congregation *> congregation_list;

   public:
    int congregationExists(string name) const;

    void addCongregation(string name, string congregation_type, Date start_date,
                         Date end_date);

    void delCongregation(string name);

    void showCongregations() const;
};

#endif
