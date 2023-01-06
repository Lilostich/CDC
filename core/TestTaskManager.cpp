#include "task_manager.h"
#include "stdlib.h"
#include "../src/TaskLoader.hpp"



// Проверка работы класса Admin
// g++ -std=c++17 TestTaskManager.cpp ../src/Project.cpp ../src/TaskLoader.cpp ../src/Config.cpp task_manager.cpp -o TestTaskManager
// -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCore -fPIC -lQt5Core -lconfig++

using namespace CDC;

int main(int argc, char* argv[]){
    Task_manager TASKMAN("../CDC.cfg");

    cout << "List projects" << endl;
    system("mkdir -p /var/lib/CDC/Projects/project1 /var/lib/CDC/Projects/project2");
    cout << TASKMAN.print_list_project() << endl;

    cout << "\nList Tasks" << endl;
    system("mkdir -p /var/lib/CDC/Projects/project1/task1 /var/lib/CDC/Projects/project1/task2");
    cout << TASKMAN.print_list_task("project1")<< endl;

    TaskLoader TASKLOADER("../CDC.cfg");
    TASKLOADER.LoadTask("../Examples/Task.json");

    cout << "\nUpload TaskId" << endl;
    TASKMAN.UploadTaskID("Firefox", "Firefox_Тестирование_браузера_20221201");
    system("cat /var/lib/CDC/Reports/Firefox_Тестирование_браузера_20221201_TASKID.json");

    cout << "\nUpload Run" << endl;
    system("cp ../Examples/Run.meta /var/lib/CDC/Projects/Firefox/Firefox_Тестирование_браузера_20221201");
    TASKMAN.UploadRun("Firefox", "Firefox_Тестирование_браузера_20221201", "Run");
    system("cat /var/lib/CDC/Reports/Firefox_Тестирование_браузера_20221201_RUN.json");

    cout << "\nUpload Result" << endl;
    system("cp ../Examples/Result.meta /var/lib/CDC/Results");
    TASKMAN.UploadResults("Firefox", "Firefox_Тестирование_браузера_20221201", "Result");
    system("cat /var/lib/CDC/Reports/Firefox_Тестирование_браузера_20221201_Result_RESULTS.json");

    cout << "\nClose Task" << endl;
    TASKMAN.close_task("Firefox", "Firefox_Тестирование_браузера_20221201");
    system("cat /var/lib/CDC/Projects/Firefox/Firefox_Тестирование_браузера_20221201/Firefox_Тестирование_браузера_20221201.json");

    return 0;
}
