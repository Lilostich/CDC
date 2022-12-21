#ifndef SECURE_MANAGER_H
#define SECURE_MANAGER_H

#include "task_manager.h"

class Secure_manager
{
public:
    Secure_manager();

    void enter(std::string login, std::string password);
    void exit(std::string login);
protected:
    enum secure_level {
        admin = 0,
        test_analit = 1,
        tester = 2
    };
private:
    static std::string login_file_path;

    secure_level level;

    std::string entered_user_path;

    void regist(std::string login, std::string new_password);
    /// hash
    std::string hide(std::string pass);

    int check_capability (secure_level);
};

#endif // SECURE_MANAGER_H
