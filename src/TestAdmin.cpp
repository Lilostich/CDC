#include "Admin.hpp"

// Проверка работы класса Admin
// g++ TestAdmin.cpp Admin.cpp Config.cpp -o TestAdmin -lconfig++

using namespace CDC;

int main(int argc, char* argv[]){
    Admin ADMIN = Admin("../CDC.cfg");
    ADMIN.GetPaths();

    ADMIN.AddUser("MASLOV_A", 2);

    return 0;
}
