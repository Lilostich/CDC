#include "Secure.hpp"
#include "Admin.hpp"
#include "stdlib.h"

// Проверка работы класса Secure
// g++ TestSecure.cpp Admin.cpp Secure.cpp Config.cpp -o TestSecure -lconfig++ -lcrypto

using namespace CDC;


int main(int argc, char* argv[]){
    Secure SECURE = Secure("../CDC.cfg");   // check constructor
    SECURE.GetPaths();                      // print paths
    cout << endl;


    if (! SECURE.Enter("maslov_a", "12345678")) {
        cout << "Wrong user: OK" << endl;
    } else {
        cout << "Wrong user: FAIL" << endl;
    }
    //
    cout << "Check no new entry in Entered file" << endl;
    system("cat /var/lib/CDC/Entered.cfg");       // hardcode


    cout << endl;
    if (! SECURE.Enter("Admin", "12345678")) {
        cout << "No admin password: OK" << endl;
    } else {
        cout << "No admin password: FAIL" << endl;
    }
    //
    cout << "Check no new entry in Entered file" << endl;
    system("cat /var/lib/CDC/Entered.cfg");       // hardcode
    cout << endl;


    SECURE.Register("Admin", "Admin1234");
    cout << "Check register Admin manually" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;


    if (SECURE.Enter("Admin", "Admin1234")) {
        cout << "Enter as Admin: OK" << endl;
    } else {
        cout << "Enter as Admin: FAIL" << endl;
    }
    //
    cout << "Check new entry in Entered file" << endl;
    system("cat /var/lib/CDC/Entered.cfg");       // hardcode
    cout << endl;


    if (SECURE.CheckCapability(ANALYST_LEVEL)) {
        cout << "Admin can manage tests: OK" << endl;
    } else {
        cout << "Admin can manage tests: FAIL" << endl;
    }
    cout << endl;


    if (! SECURE.Register("maslov_a", "12345678")) {
        cout << "Cant register new user without adding of user: OK" << endl;
    } else {
        cout << "Cant register new user without adding of user: FAIL" << endl;
    }
    cout << "Check That no new user" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;


    SECURE.Exit(0);
    //
    cout << "Check remove entry in Entered file" << endl;
    system("cat /var/lib/CDC/Entered.cfg");       // hardcode
    cout << endl;


    // add new user
    Admin ADMIN = Admin("../CDC.cfg");  // check constructor
    ADMIN.AddUser("maslov_a", TESTER_LEVEL);


    if (SECURE.Register("maslov_a", "12345678")) {
        cout << "Can register new after adding: OK" << endl;
    } else {
        cout << "Can register new after addin: FAIL" << endl;
    }
    cout << "Check That new user" << endl;
    system("cat /var/lib/CDC/Login.cfg");       // hardcode
    cout << endl;


    if (SECURE.Enter("maslov_a", "12345678")) {
        cout << "Enter as user: OK" << endl;
    } else {
        cout << "Enter as user: FAIL" << endl;
    }
    //
    cout << "Check new entry in Entered file" << endl;
    system("cat /var/lib/CDC/Entered.cfg");       // hardcode
    cout << endl;


    if (!SECURE.CheckCapability(ANALYST_LEVEL)) {
        cout << "User cant manage tests: OK" << endl;
    } else {
        cout << "User cant manage tests: FAIL" << endl;
    }
    cout << endl;


    SECURE.GetPaths();
    if (SECURE.CheckCapability(TESTER_LEVEL)) {
        cout << "User can run tests: OK" << endl;
    } else {
        cout << "User can run tests: FAIL" << endl;
    }
    cout << endl;


    ADMIN.BanAll();
    system("cat /var/lib/CDC/Emergency");       // hardcode
    if (! SECURE.CheckCapability(TESTER_LEVEL)) {
        cout << "User cant run tests in emergency mode: OK" << endl;
    } else {
        cout << "User cant run tests in emergency mode: FAIL" << endl;
    }
    cout << endl;


    cout << "Soft kill" << endl;
    SECURE.Exit(1);
    //
    cout << "Check remove entry in Entered file" << endl;
    system("cat /var/lib/CDC/Entered.cfg");       // hardcode

    SECURE.GetPaths();

    return 0;
}
