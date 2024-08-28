#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Temp {
   public:
    Temp() { cout << "Constructor is called\n"; }
};

int main() {
    Temp t;
    vector<Temp> arr;
    // Temp arr1[10];
    arr.push_back(t);
    // arr1[0] = t;
    cout << &t << " " << &arr[0] << endl;
}
