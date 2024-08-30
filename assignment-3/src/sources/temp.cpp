#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Temp {
   public:
    // Default constructor
    Temp(int a) { cout << a; }
};

void func(Temp t) { cout << "Function called"; }

int main() { func(1); }