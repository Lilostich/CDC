#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "test_omnimanager.h"
// Для qt json нужна версия qt повыше (5)
//#include <Qt/qt
#include <QJsonObject>
typedef int json; // TODO поменять json на QJsonObject

const std::string PATH_MAIN = "CDC";

class Task_manager
{
public:
    Task_manager();

    void update_unchecked_tasks();
    void check_task(std::string project,std::string task_id);

    void print_list_project();
    void print_list_task();

    void run_test_manager(std::string project_name, std::string task_id);
    void run_test_manager();

    void close_task(std::string project_name, std::string task_id);
    json send_run(std::string project_name, std::string task_id, std::string run_name);
    json send_run_result(std::string project_name, std::string task_id, std::string session);

private:
    std::string projects_path;

    json fit_task_answer(std::string project,std::string task_id);
    void send_result(json);
    void run_test_omnimanager(std::string project_name, std::string task_id);
};

#endif // TASK_MANAGER_H
