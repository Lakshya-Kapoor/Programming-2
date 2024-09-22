#include "zoo_manager.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "macro.h"
#include "zoo_species.h"

void Zoo_manager::add(species_type category, string name, int count,
                      string attribute) {
    Zoo_species* species = nullptr;

    switch (category) {
        case M: {
            Mammal* mammal = new Mammal(name, count);

            if (attribute == "carnivore") {
                mammal->Set_diet_type(carnivore);
            } else if (attribute == "herbivore") {
                mammal->Set_diet_type(herbivore);
            } else {
                ERROR("Invalid attribute");
            }
            species = mammal;
            break;
        }
        case R: {
            Reptile* reptile = new Reptile(name, count);

            if (attribute == "small") {
                reptile->Set_size_type(small);
            } else if (attribute == "medium") {
                reptile->Set_size_type(medium);
            } else if (attribute == "large") {
                reptile->Set_size_type(large);
            } else {
                ERROR("Invalid attribute");
            }
            species = reptile;
            break;
        }
        case B: {
            Bird* bird = new Bird(name, count);

            if (attribute == "grain") {
                bird->Set_bird_feed(grain);
            } else if (attribute == "insect") {
                bird->Set_bird_feed(insect);
            } else if (attribute == "fish") {
                bird->Set_bird_feed(fish);
            } else {
                ERROR("Invalid attribute");
            }
            species = bird;
            break;
        }
        case Q: {
            Aquatic* aquatic = new Aquatic(name, count);

            if (attribute == "fishfood") {
                aquatic->Set_aqua_feed(fishfood);
            } else if (attribute == "livefish") {
                aquatic->Set_aqua_feed(livefish);
            } else if (attribute == "plants") {
                aquatic->Set_aqua_feed(plants);
            } else {
                ERROR("Invalid attribute");
            }
            species = aquatic;
            break;
        }
    }
}
