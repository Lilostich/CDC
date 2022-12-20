#include "task_manager.h"
#include <QDir>
#include <iostream>

Task_manager::Task_manager()
{

}

void Task_manager::print_list_project()
{
    QDir dir((PATH_MAIN + "/Projects").c_str());
    QStringList list = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (int i = 0; i <list.size(); i++)
        std::cout << i << ") " << list[i].toStdString() << std::endl;
}

void Task_manager::print_list_task()
{
    QDir dir((PATH_MAIN + "/Projects").c_str());
    QStringList list = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (int i = 0; i <list.size(); i++){
        QDir dirTask(dir.path() + "/" + list[i]);
        QStringList listTask = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for (int j = 0; j < listTask.size(); j++){
            std::cout << i << "." << j << ") " << listTask[j].toStdString() << std::endl;;
        }
    }
}
