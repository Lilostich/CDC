#ifndef TEST_OMNIMANAGER_H
#define TEST_OMNIMANAGER_H

#include "test_manager.h"

class Test_omnimanager : public Test_manager
{
public:
    Test_omnimanager();
    QByteArray open_read_list_file(std::string listFile);
    QByteArray open_read_test_file(std::string testFile);
    QByteArray open_read_run_file(std::string runFile);
    void write_list_file(std::string listFile,QByteArray&& data);
    void write_test_file(std::string testFile,QByteArray&& data);
    void write_test_run(std::string runFile,QByteArray&& data);


    void add_test_to_list(std::string test_name, std::string list_name);
    void add_test_to_run(std::string test_name, std::string run_name);
    void add_list_to_run(std::string list_name, std::string run_name);

    void delete_test(std::string test_name);
    void delete_test_from_list(std::string test_name,std::string list_name);
    void delete_test_from_run(std::string test_name,std::string run_name);

    void delete_list(std::string list_name);
    void delete_list_from_run(std::string list_name,std::string run_name);

};

#endif // TEST_OMNIMANAGER_H
