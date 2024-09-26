#include "zoo_species.h"

#include <iostream>
#include <string>

#include "custom_exception.h"

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

// Increment species count
void Zoo_species::Update_count(int increment) { Species_count += increment; }

// Get species name
string Zoo_species::Get_name() const { return Species_name; }

// Get species count
int Zoo_species::Get_count() const { return Species_count; }

// Get species type
string Zoo_species::Get_type() const { return Species_type; }

// Print species data
void Zoo_species::Print() const {
    cout << Species_name << " " << Species_count << " ";
}

diet_type Zoo_species::Get_diet_type() const {
    throw CustomException("This function is not accessible");
}
size_type Zoo_species::Get_size_type() const {
    throw CustomException("This function is not accessible");
}
bird_feed_type Zoo_species::Get_bird_feed() const {
    throw CustomException("This function is not accessible");
}
aqua_feed_type Zoo_species::Get_aqua_feed() const {
    throw CustomException("This function is not accessible");
}

// Mammal constructor
Mammal::Mammal(string name, int count, diet_type type)
    : Zoo_species(name, count) {
    Set_diet_type(type);
    Species_type = "M";
}

// Set diet type of mammal
void Mammal::Set_diet_type(diet_type type) { Diet_type = type; }

// Get diet type of mammal
diet_type Mammal::Get_diet_type() const { return Diet_type; }

void Mammal::Print() const {
    Zoo_species::Print();
    if (Diet_type == herbivore) {
        cout << "herbivore" << endl;
    } else {
        cout << "carnivore" << endl;
    }
}

// Reptile constructor
Reptile::Reptile(string name, int count, size_type type)
    : Zoo_species(name, count) {
    Set_size_type(type);
    Species_type = "R";
}

// Set diet type of mammal
void Reptile::Set_size_type(size_type type) { Feed_size = type; }

// Get diet type of mammal
size_type Reptile::Get_size_type() const { return Feed_size; }

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
Bird::Bird(string name, int count, bird_feed_type type)
    : Zoo_species(name, count) {
    Set_bird_feed(type);
    Species_type = "B";
}

// Set diet type of mammal
void Bird::Set_bird_feed(bird_feed_type type) { Bird_feed = type; }

// Get diet type of mammal
bird_feed_type Bird::Get_bird_feed() const { return Bird_feed; }

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
Aquatic::Aquatic(string name, int count, aqua_feed_type type)
    : Zoo_species(name, count) {
    Set_aqua_feed(type);
    Species_type = "Q";
}

// Set diet type of mammal
void Aquatic::Set_aqua_feed(aqua_feed_type type) { Aqua_feed = type; }

// Get diet type of mammal
aqua_feed_type Aquatic::Get_aqua_feed() const { return Aqua_feed; }

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