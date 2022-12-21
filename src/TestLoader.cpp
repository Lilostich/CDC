#include "TaskLoader.hpp"
#include "stdlib.h"

// Проверка работы класса Admin
// g++ -std=c++17 TestLoader.cpp Admin.cpp Project.cpp TaskLoader.cpp Config.cpp -o TestLoader -lconfig++ -I/usr/include/x86_64-linux-gnu/qt5 -fPIC -lQt5Core

using namespace CDC;

int main(int argc, char* argv[]){
    TaskLoader TASKLOADER("../CDC.cfg");
    TASKLOADER.LoadTask("../Examples/Task.json");

    return 0;
}
