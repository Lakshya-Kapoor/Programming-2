#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> parseLocation(string location) {
    int start = 0;
    int end = 0;

    vector<string> res;

    while (end < location.size()) {
        if (location[end] == ':') {
            res.push_back(location.substr(start, end - start));
            start = end + 1;
        }
        end++;
    }
    res.push_back(location.substr(start, end - start));
    return res;
}

int main() {
    vector<string> res = {"hi", "hello", "bye"};
    string s1 = res[0];
    string s2 = res[1];
    string s3 = res[2];
    cout << s1 << "\n";
    cout << s2 << "\n";
    cout << s3 << "\n";
}
