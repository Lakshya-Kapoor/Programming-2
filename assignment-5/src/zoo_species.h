#ifndef ZOO_SPECIES_H
#define ZOO_SPECIES_H

#include <string>

#include "custom_types.h"
using namespace std;

class Zoo_species {
   protected:
    string Species_name;
    string Species_count;

   public:
    Zoo_species(string name, int count);
    void Set_name(string name);
    void Set_count(int count);
    virtual void Print() const;
    // Zoo_species destructor
    virtual ~Zoo_species();
};

class Mammal : public Zoo_species {
   private:
    diet_type Diet_type;

   public:
    Mammal(string name, int count);
    void Set_diet_type(diet_type type);
    void Print() const override;
};

class Reptile : public Zoo_species {
   private:
    size_type Feed_size;

   public:
    Reptile(string name, int count);
    void Set_diet_type(size_type type);
    void Print() const override;
};

class Bird : public Zoo_species {
   private:
    bird_feed_type Bird_feed;

   public:
    Bird(string name, int count);
    void Set_bird_feed(bird_feed_type type);
    void Print() const override;
};

class Aquatic : public Zoo_species {
   private:
    aqua_feed_type Aqua_feed;

   public:
    Aquatic(string name, int count);
    void Set_aqua_feed(aqua_feed_type type);
    void Print() const override;
};
#endif