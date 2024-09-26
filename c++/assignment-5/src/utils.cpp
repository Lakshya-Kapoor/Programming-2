#include "utils.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>

#include "custom_exception.h"
#include "zoo_manager.h"

using namespace std;

void parse_add(string input, Zoo_manager& manager) {
    istringstream stream(input);

    string category, name, attribute;
    int count;

    stream >> category >> name >> count >> attribute;

    if (stream.fail()) {
        throw CustomException("Incorrect input format");
    }

    if (category != "M" && category != "R" && category != "B" &&
        category != "Q") {
        throw CustomException("Invalid category");
    }

    if (count <= 0) {
        throw CustomException("Count of animals must be positive");
    }

    manager.add(category, name, count, attribute);
    cout << "Success: " << count << " " << name << "successfully added\n";
}

void parse_delete(string input, Zoo_manager& manager) {
    istringstream stream(input);

    string category, name;
    int count;

    stream >> category >> name >> count;
    if (stream.fail()) {
        throw CustomException("Incorrect input format");
    }
    if (category != "M" && category != "R" && category != "B" &&
        category != "Q") {
        throw CustomException("Invalid category");
    }
    if (count <= 0) {
        throw CustomException("Count of animals must be positive");
    }
    manager.del(category, name, count);
    cout << "Success: " << count << " " << name << "successfully deleted\n";
}

void parse_show(string input, Zoo_manager& manager) {
    istringstream stream(input);

    string category;

    stream >> category;
    if (stream.fail()) {
        throw CustomException("Incorrect input format");
    }
    if (category != "M" && category != "R" && category != "B" &&
        category != "Q" && category != "A") {
        throw CustomException("Invalid category");
    }
    manager.show(category);
}

void save_to_db(Zoo_manager& manager) {
    ofstream file("db.txt");
    if (!file.is_open()) {
        throw CustomException("Error opening file");
    }

    // Save the original buffer of cout
    streambuf* originalCoutBuffer = cout.rdbuf();

    // Redirect cout to the file's stream buffer
    cout.rdbuf(file.rdbuf());

    // Call the function that prints to cout
    manager.show("A");  // This will write to output.txt

    // Restore the original buffer
    cout.rdbuf(originalCoutBuffer);

    file.close();
}

void load_from_db(Zoo_manager& manager) {
    ifstream file("db.txt");
    if (!file.is_open()) {
        throw CustomException("Error opening file");
    }

    string line, category;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, attribute;
        int count;

        ss >> name;  // Try reading the first word

        if (name == "total") {
            // Ignore the 'total' line
            continue;
        }

        // If it's a known category (mammal, reptile, etc.), update the category
        if (name == "mammal" || name == "reptile" || name == "bird" ||
            name == "aquatic") {
            category = toupper(name[0]);
            continue;  // Continue to the next line for actual animals
        }

        // For animal entries
        ss >> count >> attribute;
        manager.add(category, name, count, attribute);
    }

    file.close();
}
