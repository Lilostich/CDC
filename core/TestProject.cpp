#include "Project.hpp"

// Проверка работы класса Project
// g++ -std=c++17 TestProject.cpp Project.cpp Config.cpp -o TestProject -lconfig++ -I /usr/include/x86_64-linux-gnu/qt5/QtCore -I /usr/include/x86_64-linux-gnu/qt5 -fPIC -lQt5Core -lcrypto

using namespace CDC;

void print_pl(Project &PROJECT){
    cout << "[QStringList]" << endl;
    for (int i = 0; i < PROJECT.ListProjects().length(); i++) {
        cout << PROJECT.ListProjects()[i].toStdString() << endl;
    }

    cout << "[QStringList Names]" << endl;
    for (int i = 0; i < PROJECT.ListProjectNames().length(); i++) {
        cout << PROJECT.ListProjectNames()[i].toStdString() << endl;
    }
}

int main(int argc, char* argv[]){
    Project PROJECT = Project("../CDC.cfg");    // check constructor

    cout << endl;
    cout << "Add project: TestProject" << endl;
    PROJECT.CreateProject("TestProject", "Release");

    cout << endl;
    cout << "Check Meta File" << endl;
    system("cat /var/lib/CDC/Projects/TestProject/TestProject.cfg");

    cout << endl;
    cout << "List of projects" << endl;
    // cout << PROJECT.ListProjects() << endl;
    print_pl(PROJECT);

    cout << endl;
    cout << "Add project: TestProject2" << endl;
    PROJECT.CreateProject("TestProject2", "Development");

    cout << endl;
    cout << "Check Meta File" << endl;
    system("cat /var/lib/CDC/Projects/TestProject2/TestProject2.cfg");

    cout << endl;
    cout << "List of projects" << endl;
    // cout << PROJECT.ListProjects() << endl;
    print_pl(PROJECT);

    cout << endl;
    cout << "Find TestProject2" << endl;
    cout << PROJECT.FindProjects("TestProject2") << endl;

    cout << endl;
    cout << "Delete TestProject2" << endl;
    PROJECT.DeleteProject("TestProject2");

    cout << endl;
    cout << "List of projects" << endl;
    // cout << PROJECT.ListProjects() << endl;
    print_pl(PROJECT);

    cout << endl;
    cout << "Delete TestProject" << endl;
    PROJECT.DeleteProject("TestProject");

    cout << endl;
    cout << "List of projects" << endl;
    // cout << PROJECT.ListProjects() << endl;
    print_pl(PROJECT);

    return 0;
}
