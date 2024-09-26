#include "custom_exception.h"

#include <string>
using namespace std;

// Exception constructor
CustomException::CustomException(string message) : err_message(message) {}

// Get error message
string CustomException::get_error() { return err_message; }