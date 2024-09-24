#ifndef ZOO_SPECIES_H
#define ZOO_SPECIES_H

#include <string>

using namespace std;

enum diet_type { herbivore, carnivore };
enum size_type { small, medium, large };
enum bird_feed_type { grain, insect, fish };
enum aqua_feed_type { fishfood, livefish, plants };

class Zoo_species {
   protected:
    string Species_name;
    int Species_count;
    string Species_type;

   public:
    Zoo_species(string name, int count);
    void Set_name(string name);
    void Set_count(int count);
    void Update_count(int increment);
    string Get_name() const;
    int Get_count() const;
    string Get_type() const;
    virtual diet_type Get_diet_type() const;
    virtual size_type Get_size_type() const;
    virtual bird_feed_type Get_bird_feed() const;
    virtual aqua_feed_type Get_aqua_feed() const;
    virtual void Print() const;
    virtual ~Zoo_species() = 0;
};

class Mammal : public Zoo_species {
   private:
    diet_type Diet_type;

   public:
    Mammal(string name, int count, diet_type type);
    void Set_diet_type(diet_type type);
    diet_type Get_diet_type() const override;
    void Print() const override;
};

class Reptile : public Zoo_species {
   private:
    size_type Feed_size;

   public:
    Reptile(string name, int count, size_type type);
    void Set_size_type(size_type type);
    size_type Get_size_type() const override;
    void Print() const override;
};

class Bird : public Zoo_species {
   private:
    bird_feed_type Bird_feed;

   public:
    Bird(string name, int count, bird_feed_type type);
    void Set_bird_feed(bird_feed_type type);
    bird_feed_type Get_bird_feed() const override;
    void Print() const override;
};

class Aquatic : public Zoo_species {
   private:
    aqua_feed_type Aqua_feed;

   public:
    Aquatic(string name, int count, aqua_feed_type type);
    void Set_aqua_feed(aqua_feed_type type);
    aqua_feed_type Get_aqua_feed() const override;
    void Print() const override;
};
#endif