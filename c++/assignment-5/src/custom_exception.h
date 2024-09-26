#ifndef CUSTOM_EXCEPTION_HH
#define CUSTOM_EXCEPTION_HH

#include <string>
using namespace std;

class CustomException {
   private:
    string err_message;

   public:
    CustomException(string message);
    string get_error();
};

#endif