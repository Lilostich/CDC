#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H

#include <string>
#include <vector>
#include <QStringList>

class Test_manager
{
public:

    Test_manager();

    void run_auto_test(std::string test_name);
    void run_auto_list(std::string list_name);
    void run_auto_task(std::string task_name);

    // Функции - часть запуска ручных тестов (запись результатов в файл)
    void save_manual_test(std::string test_name,std::string data);
    void save_manual_list(std::string list_name,std::string data);
    void save_manual_task(std::string task_name,std::string data);

    QStringList get_lists();
    QStringList get_tests();
    QStringList get_runs();

protected:
    /// Директория со всеми списками тестов
    std::string lists_path;
    /// Директория со всеми тестами
    std::string tests_path;
    /// Директория с таском
    std::string task_path;

    void create_session(std::string session_name);
    void kill_run();
};

#endif // TEST_MANAGER_H
