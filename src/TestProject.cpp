#include "Project.hpp"

// Проверка работы класса Project
// g++ -std=c++17 TestProject.cpp Project.cpp Config.cpp -o TestProject -lconfig++

using namespace CDC;


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
    cout << PROJECT.ListProjects() << endl;

    cout << endl;
    cout << "Add project: TestProject2" << endl;
    PROJECT.CreateProject("TestProject2", "Development");

    cout << endl;
    cout << "Check Meta File" << endl;
    system("cat /var/lib/CDC/Projects/TestProject2/TestProject2.cfg");

    cout << endl;
    cout << "List of projects" << endl;
    cout << PROJECT.ListProjects() << endl;

    cout << endl;
    cout << "Find TestProject2" << endl;
    cout << PROJECT.FindProjects("TestProject2") << endl;

    cout << endl;
    cout << "Delete TestProject2" << endl;
    PROJECT.DeleteProject("TestProject2");

    cout << endl;
    cout << "List of projects" << endl;
    cout << PROJECT.ListProjects() << endl;

    cout << endl;
    cout << "Delete TestProject" << endl;
    PROJECT.DeleteProject("TestProject");

    cout << endl;
    cout << "List of projects" << endl;
    cout << PROJECT.ListProjects() << endl;

    return 0;
}
