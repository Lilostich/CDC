#include "Admin.hpp"
#include "Secure.hpp"
#include "stdlib.h"

// Проверка работы класса Admin
// g++ TestAdmin.cpp Admin.cpp Config.cpp -o TestAdmin -lconfig++
//
// g++ TestAdmin.cpp Secure.cpp Admin.cpp Config.cpp -o TestAdmin -lconfig++ -I /usr/include/x86_64-linux-gnu/qt5/QtCore -I /usr/include/x86_64-linux-gnu/qt5 -fPIC -lQt5Core -lcrypto

using namespace CDC;

int main(int argc, char* argv[]){
    Admin ADMIN = Admin("../CDC.cfg");  // check constructor
    ADMIN.GetPaths();                   // print paths
    Secure SECURE = Secure("../CDC.cfg");

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
    for (int i = 0; i < ADMIN.ListUsers().length(); i++) {
        cout << ADMIN.ListUsers()[i].toStdString() << endl;
    }

    // User info
    cout << endl;
    cout << "Unregistered User Info" << endl;
    for (int i = 0; i < ADMIN.UserInfo("poserenin_a").length(); i++) {
        cout << ADMIN.UserInfo("poserenin_a")[i].toStdString() << endl;
    }
    cout << endl;
    SECURE.Register("MASLOV_A", "MASLOV12345");
    cout << "Registered User Info" << endl;
    for (int i = 0; i < ADMIN.UserInfo("MASLOV_A").length(); i++) {
        cout << ADMIN.UserInfo("MASLOV_A")[i].toStdString() << endl;
    }

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
