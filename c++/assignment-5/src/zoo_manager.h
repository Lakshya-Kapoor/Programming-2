#ifndef ZOO_MANAGER_H
#define ZOO_MANAGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Zoo_species;

class Zoo_manager {
   private:
    vector<Zoo_species*> species;
    int mammal_count = 0;
    int reptile_count = 0;
    int bird_count = 0;
    int aquatic_count = 0;

   public:
    void print_category(string category) const;
    int species_index(string category, string name) const;
    void add(string category, string name, int count, string attribute);
    void del(string category, string name, int count);
    void show(string category) const;
};

#endif