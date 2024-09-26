#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "custom_exception.h"
#include "utils.h"
#include "zoo_manager.h"

using namespace std;

int main() {
    Zoo_manager manager;

    load_from_db(manager);

    while (true) {
        string input, command;
        getline(cin, input);

        istringstream stream(input);

        stream >> command;
        try {
            if (input == "exit") {
                save_to_db(manager);
                break;
            } else if (command == "add") {
                parse_add(input.substr(command.size() + 1, input.size()),
                          manager);
            } else if (command == "delete") {
                parse_delete(input.substr(command.size() + 1, input.size()),
                             manager);
            } else if (command == "show") {
                parse_show(input.substr(command.size() + 1, input.size()),
                           manager);
            } else {
                throw CustomException("Invalid command");
            }
        } catch (CustomException& e) {
            cout << "Error: " << e.get_error() << endl;
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
