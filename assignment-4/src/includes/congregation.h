#ifndef CONGREGATION_H
#define CONGREGATION_H

#include <string>

#include "date.h"
using namespace std;

class Congregation {
   private:
    string name;
    Date start_date;
    Date end_date;

   public:
    Congregation(string name, Date start_date, Date end_date);

    string getName() const;
};

class Conference : public Congregation {
    // Can have different types of events
    // for which different invitations have to be generated
    // And different rules apply for entry
    // 1. Workshops: Occupy a day or more of conference
    // 2. Main conference
    // 3.Banquet
   public:
    Conference();
};

class Games : public Congregation {
    // Has the following events:
    // i. Opening ceremony (program type “Ceremony”)
    // ii. Closing ceremony (program type “Ceremony”)
    // iii. Sports competition–let’s consider only these program types for now
    //      1. “Track and ﬁeld” – includes athleHcs, football, cricket, hockey
    //      as well. Can only be held in an Outdoor Stadium,
    //      2. “Indoor games” – basketball, volleyball, tennis, badminton etc.
    //      Can only be held in an Indoor Stadium
    //      3. “Water sports” – swimming and diving. Can only be held in a
    //      Swimming Pool.
   public:
    Games();
};

class Concert : public Congregation {
    // Concerts will typically have just one venue and:
    // i. A pre-concert performance by a lesser-known arHst (program type “Pre-
    // concert”)
    // ii. The main performance by the main arHst (program type “Main Concert”)
   public:
    Concert();
};

class Convention : public Congregation {
    // A convenHon will have everything that a conference has, plus:
    // i. Food and beverage stalls selling food and beverages to a]endees
    // (program type “Food Court”)
    // ii. One or more exhibiHons on diﬀerent themes with vendor exhibits
    // (program type “ExhibiHon”)
   public:
    Convention();
};

#endif