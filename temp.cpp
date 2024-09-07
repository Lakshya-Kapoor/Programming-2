#include <iostream>
using namespace std;

class Base {
   public:
    void print() { cout << "base" << endl; }
    ~Base() { cout << "Destroying Base object" << endl; }
};

class Derived : public Base {
   public:
    void print() { cout << "derived" << endl; }
    ~Derived() { cout << "Destroying Derived object" << endl; }
};

class Derived1 : public Base {
   public:
    void print() { cout << "derived1" << endl; }
    ~Derived1() { cout << "Destroying Derived1 object" << endl; }
};

class Derived2 : public Base {
   public:
    void print() { cout << "derived2" << endl; }
    ~Derived2() { cout << "Destroying Derived2 object" << endl; }
};

int main() {
    // Base* array[3];
    // array[0] = new Derived();
    // array[1] = new Derived1();
    // array[2] = new Derived2();
    // for (int i = 0; i < 3; i++) {
    //     array[i]->print();
    // }
    // for (int i = 0; i < 3; i++) {
    //     delete array[i];
    // }
    for (int i = 0; i < __LONG_MAX__; i++) {
        int *ptr = new int;
    }
}