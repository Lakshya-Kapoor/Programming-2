#ifndef ZOO_MANAGER_H
#define ZOO_MANAGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum species_type { M, R, B, Q };
class Zoo_species;

class Zoo_manager {
   private:
    vector<Zoo_species*> mammals;
    vector<Zoo_species*> reptiles;
    vector<Zoo_species*> birds;
    vector<Zoo_species*> aquatics;

   public:
    void add(species_type category, string name, int count, string attribute);
    void del(species_type category, string name, int count);
    void show(species_type category);
};

#endif