#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H

#include <string>
#include <vector>

class Test_manager
{
public:

    Test_manager();

    void run_auto_test(std::string test_name);
    void run_auto_list(std::string list_name);
    void run_auto_task(std::string task_name);

    void run_manual_test(std::string test_name);
    void run_manual_list(std::string list_name);
    void run_manual_task(std::string task_name);

    std::vector<std::string> get_lists();
    std::vector<std::string> get_tests();
    std::vector<std::string> get_runs();

private:
    /// Директория со всеми списками тестов
    static std::string lists_path;
    /// Директория со всеми тестами
    static std::string tests_path;
    /// Директория с таском
    static std::string task_path;

    void create_session(std::string session_name);
    void kill_run();
};

#endif // TEST_MANAGER_H
