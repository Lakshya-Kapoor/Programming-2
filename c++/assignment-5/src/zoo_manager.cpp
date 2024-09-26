#include "zoo_manager.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "custom_exception.h"
#include "zoo_species.h"

// adding species
void Zoo_manager::add(string category, string name, int count,
                      string attribute) {
    Zoo_species* new_animal = nullptr;

    if (category == "M") {
        if (attribute == "carnivore") {
            new_animal = new Mammal(name, count, carnivore);
        } else if (attribute == "herbivore") {
            new_animal = new Mammal(name, count, herbivore);
        } else {
            throw CustomException("Invalid attribute");
        }
    } else if (category == "R") {
        if (attribute == "small") {
            new_animal = new Reptile(name, count, small);
        } else if (attribute == "medium") {
            new_animal = new Reptile(name, count, medium);
        } else if (attribute == "large") {
            new_animal = new Reptile(name, count, large);
        } else {
            throw CustomException("Invalid attribute");
        }
    } else if (category == "B") {
        if (attribute == "insect") {
            new_animal = new Bird(name, count, insect);
        } else if (attribute == "grain") {
            new_animal = new Bird(name, count, grain);
        } else if (attribute == "fish") {
            new_animal = new Bird(name, count, fish);
        } else {
            throw CustomException("Invalid attribute");
        }
    } else if (category == "Q") {
        if (attribute == "fishfood") {
            new_animal = new Aquatic(name, count, fishfood);
        } else if (attribute == "livefish") {
            new_animal = new Aquatic(name, count, livefish);
        } else if (attribute == "plants") {
            new_animal = new Aquatic(name, count, plants);
        } else {
            throw CustomException("Invalid attribute");
        }
    }

    int index = species_index(category, name);
    Zoo_species* existing_animal = nullptr;
    if (index != -1) {
        existing_animal = species[index];
    }

    // Same name animal doesn't exist
    if (existing_animal == nullptr) {
        species.push_back(new_animal);
        if (category == "M") {
            mammal_count++;
        } else if (category == "R") {
            reptile_count++;
        } else if (category == "B") {
            bird_count++;
        } else {
            aquatic_count++;
        }
        return;
    }

    // Same name animal exists
    if (category == "M" &&
        new_animal->Get_diet_type() == existing_animal->Get_diet_type()) {
        existing_animal->Update_count(count);
    } else if (category == "R" && new_animal->Get_size_type() ==
                                      existing_animal->Get_size_type()) {
        existing_animal->Update_count(count);
    } else if (category == "B" && new_animal->Get_bird_feed() ==
                                      existing_animal->Get_bird_feed()) {
        existing_animal->Update_count(count);
    } else if (category == "Q" && new_animal->Get_aqua_feed() ==
                                      existing_animal->Get_aqua_feed()) {
        existing_animal->Update_count(count);
    } else {
        throw CustomException(
            "Attribute doesn't match with existing animals attribute");
    }
}

// returns index of species
int Zoo_manager::species_index(string category, string name) const {
    for (int i = 0; i < species.size(); i++) {
        if (category == species[i]->Get_type() &&
            name == species[i]->Get_name()) {
            return i;
        }
    }
    return -1;
}

// deleting species
void Zoo_manager::del(string category, string name, int count) {
    int index = species_index(category, name);
    Zoo_species* existing_animal = nullptr;
    if (index != -1) {
        existing_animal = species[index];
    }

    if (existing_animal == nullptr) {
        throw CustomException("Animal doesn't exist");
    }

    if (existing_animal->Get_count() < count) {
        throw CustomException("Insufficient animals for deletion");
    } else if (existing_animal->Get_count() == count) {
        delete existing_animal;
        species.erase(species.begin() + index);
        if (category == "M") {
            mammal_count--;
        } else if (category == "R") {
            reptile_count--;
        } else if (category == "B") {
            bird_count--;
        } else {
            aquatic_count--;
        }
    } else {
        existing_animal->Update_count(-count);
    }
}

// showing species
void Zoo_manager::show(string category) const {
    if (category == "A") {
        int total = mammal_count + reptile_count + bird_count + aquatic_count;
        cout << "total species " << total << endl;
        cout << "mammal " << mammal_count << endl;
        print_category("M");
        cout << "reptile " << reptile_count << endl;
        print_category("R");
        cout << "bird " << bird_count << endl;
        print_category("B");
        cout << "aquatic " << aquatic_count << endl;
        print_category("Q");
        return;
    } else if (category == "M") {
        cout << "mammal " << mammal_count << endl;
    } else if (category == "R") {
        cout << "reptile " << reptile_count << endl;
    } else if (category == "B") {
        cout << "bird " << bird_count << endl;
    } else if (category == "Q") {
        cout << "aquatic " << aquatic_count << endl;
    }
    print_category(category);
}

// print all species of a category
void Zoo_manager::print_category(string category) const {
    for (int i = 0; i < species.size(); i++) {
        if (category == species[i]->Get_type()) {
            species[i]->Print();
        }
    }
}

Zoo_manager::~Zoo_manager() {
    for (int i = 0; i < species.size(); i++) {
        delete species[i];
    }
}