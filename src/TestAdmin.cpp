#include "Admin.hpp"
#include "stdlib.h"

// Проверка работы класса Admin
// g++ TestAdmin.cpp Admin.cpp Config.cpp -o TestAdmin -lconfig++

using namespace CDC;

int main(int argc, char* argv[]){
    Admin ADMIN = Admin("../CDC.cfg");  // check constructor
    ADMIN.GetPaths();                   // print paths
    cout << endl;

    // add users
    // ---------
    cout << "------------- ADD USER ----------------" << endl;
    cout << "[Before adding]" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;

    ADMIN.AddUser("MASLOV_A", TESTER_LEVEL);
    ADMIN.AddUser("poserenin_a", GUEST_LEVEL);

    cout << "[After adding]" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;
    // ---------

    //list
    cout << "List users" << endl;
    cout << ADMIN.ListUsers() << endl;;

    // remove user
    // ---------
    cout << "------------- RM USER ----------------" << endl;
    cout << "[Before removing]" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;

    ADMIN.DeleteUser("poserenin_a");

    cout << "[After removing]" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;
    // ---------

    // remove user
    // ---------
    cout << "------------- SET LEVEL ----------------" << endl;
    cout << "[Before setting]" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;

    ADMIN.SetLevel("MASLOV_A", ANALYST_LEVEL);

    cout << "[After setting]" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;
    // ---------

    // ban all
    // ---------
    cout << "------------- BAN ALL ----------------" << endl;
    cout << "[Before ban]" << endl;
    system("cat /var/lib/CDC/Emergency");       // hardcode

    ADMIN.BanAll();

    cout << "[After ban]" << endl;
    system("cat /var/lib/CDC/Emergency");       // hardcode
    cout << endl;
    // ---------

    // unban all
    // ---------
    cout << "------------- UNBAN ALL ----------------" << endl;
    cout << "[Before ban]" << endl;
    system("cat /var/lib/CDC/Emergency");       // hardcode

    ADMIN.UnBanAll();

    cout << "[After ban]" << endl;
    system("cat /var/lib/CDC/Emergency");       // hardcode
    // ---------

    // clean
    ADMIN.DeleteUser("MASLOV_A");

    return 0;
}
