#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "test_omnimanager.h"
// Для qt json нужна версия qt повыше (5)
//#include <Qt/qt
#include <QJsonObject>
#include <QJsonDocument>
typedef int json; // TODO поменять json на QJsonObject

#include "../src/Config.hpp" // TODO: REPLACE

const std::string PATH_MAIN = "CDC";

class Task_manager
{
public:
    Task_manager();
    Task_manager(std::string MainCFG);   // подгрузка пути до проектов

    // void update_unchecked_tasks();
    // void check_task(std::string project,std::string task_id);

    std::string print_list_project();
    std::string print_list_task(std::string ProjectName);
    std::string print_run(std::string project_name, std::string task_id, std::string test_run);

    //void run_test_manager(std::string project_name, std::string task_id);
    //void run_test_manager();

    void close_task(std::string project_name, std::string task_id);  // status: closed

    void UploadTaskID(std::string project_name, std::string task_id);                       // 1 answer: выгрузить в ReportsPath (task id)
    void UploadRun(std::string project_name, std::string task_id, std::string test_run);    // 2 answer: выгрузить в ReportsPath (run)
    void UploadResults(std::string project_name, std::string task_id, std::string log);     // 3 answer: выгрузить в ReportsPath (run)

    //json send_run(std::string project_name, std::string task_id, std::string run_name);
    //json send_run_result(std::string project_name, std::string task_id, std::string session);

private:
    std::string ProjectsPath;
    std::string ReportsPath;
    std::string ResultsPath;

    //json fit_task_answer(std::string project,std::string task_id);
    //void send_result(json);
    //void run_test_omnimanager(std::string project_name, std::string task_id);
    QByteArray open_read_file(std::string JsonFile);  // read Json
};

#endif // TASK_MANAGER_H
