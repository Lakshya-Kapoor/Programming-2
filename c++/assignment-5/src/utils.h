#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "zoo_manager.h"

extern void parse_add(std::string input, Zoo_manager& manager);
extern void parse_delete(std::string input, Zoo_manager& manager);
extern void parse_show(std::string input, Zoo_manager& manager);
extern void save_to_db(Zoo_manager& manager);
extern void load_from_db(Zoo_manager& manager);

#endif