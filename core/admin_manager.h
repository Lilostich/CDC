#ifndef ADMIN_MANAGER_H
#define ADMIN_MANAGER_H

#include <string>
#include "secure_manager.h"

class Admin_manager : public Secure_manager
{



public:
    Admin_manager();

    void add_user(std::string login,secure_level level);
    void set_level(std::string login, secure_level level);
    void delete_user(std::string login);
    void ban_all();
    void unban_all();
};

#endif // ADMIN_MANAGER_H
