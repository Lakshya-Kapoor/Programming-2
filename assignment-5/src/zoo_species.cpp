#include "zoo_species.h"

#include <iostream>
#include <string>

using namespace std;

// Zoo_species constructor
Zoo_species::Zoo_species(string name, int count) {
    Set_name(name);
    Set_count(count);
}

// Set species name
void Zoo_species::Set_name(string name) { Species_name = name; }

// Set species count
void Zoo_species::Set_count(int count) { Species_count = count; }

// Print species data
void Zoo_species::Print() const {
    cout << Species_name << " " << Species_count << " ";
}

// Mammal constructor
Mammal::Mammal(string name, int count) : Zoo_species(name, count) {}

// Set diet type of mammal
void Mammal::Set_diet_type(diet_type type) { Diet_type = type; }

void Mammal::Print() const {
    Zoo_species::Print();
    if (Diet_type == herbivore) {
        cout << "herbivore" << endl;
    } else {
        cout << "carnivore" << endl;
    }
}

// Reptile constructor
Reptile::Reptile(string name, int count) : Zoo_species(name, count) {}

// Set diet type of mammal
void Reptile::Set_diet_type(size_type type) { Feed_size = type; }

void Reptile::Print() const {
    Zoo_species::Print();
    if (Feed_size == small) {
        cout << "small" << endl;
    } else if (Feed_size == medium) {
        cout << "medium" << endl;
    } else {
        cout << "large" << endl;
    }
}

// Bird constructor
Bird::Bird(string name, int count) : Zoo_species(name, count) {}

// Set diet type of mammal
void Bird::Set_bird_feed(bird_feed_type type) { Bird_feed = type; }

void Bird::Print() const {
    Zoo_species::Print();
    if (Bird_feed == grain) {
        cout << "grain" << endl;
    } else if (Bird_feed == insect) {
        cout << "insect" << endl;
    } else {
        cout << "fish" << endl;
    }
}

// Aquatic constructor
Aquatic::Aquatic(string name, int count) : Zoo_species(name, count) {}

// Set diet type of mammal
void Aquatic::Set_aqua_feed(aqua_feed_type type) { Aqua_feed = type; }

void Aquatic::Print() const {
    Zoo_species::Print();
    if (Aqua_feed == fishfood) {
        cout << "fishfood" << endl;
    } else if (Aqua_feed == livefish) {
        cout << "livefish" << endl;
    } else {
        cout << "plants" << endl;
    }
}