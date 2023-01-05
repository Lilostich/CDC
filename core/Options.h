#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include "Secure.hpp"

const std::string MAIN_PATH = "CDC";
const std::string TEST_PATH = MAIN_PATH + "/tests";
const std::string LIST_PATH = MAIN_PATH + "/lists";
const std::string PROJ_PATH = MAIN_PATH + "/Projects";
const std::string TASK_DIR_NAME = "tasks";

class CDC::Secure secure_glob;

#endif // OPTIONS_H
