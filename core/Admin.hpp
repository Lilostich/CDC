#ifndef CDC_ADMIN_HPP
#define CDC_ADMIN_HPP

#include <stdio.h>

//#include "CDC.h"            // global basic configs
#include "Config.hpp"         // cfg work

#include <string>

/// @class CDC::Admin
/// @brief Admin panel functions without GUI
namespace CDC {

// constants
// -----------------------------------------------------------------------
unsigned short ADMIN_LEVEL      = 0;
unsigned short ANALYST_LEVEL    = 1;
unsigned short TESTER_LEVEL     = 2;
unsigned short GUEST_LEVEL      = 3;
unsigned short BAN_LEVEL        = 10;
// -----------------------------------------------------------------------

class Admin {
public:
    /// @fn CDC::Admin()
    /// @brief default constructor
    Admin();

    /// @fn CDC::Admin(string MainCFG)
    /// @brief Init Admin class via CFG file
    /// @param ConfigPath path to .cfg file
    Admin(std::string MainCFG);

    ~Admin();

    // login management
    // ---------------------------------------------------------------
    /// @fn bool CDC::Admin::AddUser(string login, unsigned short secure_level)
    /// @brief Add User to Login file
    /// @details If user exists, secure_level will no been changed.
    ///          Use SetLevel func updating secure level of user.
    /// @param login string
    /// @param secure_level level
    /// @return true in case of success or login is in cfg else false
    bool AddUser(std::string login, unsigned short secure_level);

    /// @fn bool CDC::Admin::DeleteUser(string login)
    /// @brief Delete User from Login file
    /// @details If user exists return true
    /// @param login string
    /// @return true in case of success or login is not in cfg else false
    int DeleteUser(std::string login);

    /// @fn bool CDC::Admin::SetLevel(string login)
    /// @brief Update secure level for login. Func does not add new user
    /// @param login login value
    /// @param secure_level secure level
    /// @return true in case of success else false
    int SetLevel(std::string login, unsigned short secure_level);
    // ---------------------------------------------------------------

    // emergency managment
    // ---------------------------------------------------------------
    /// @fn void CDC::Admin::BanAll()
    /// @brief write 1 to emergency file - set emergency mode
    /// @details Secure manager will check this file to allow/deny all actions on system
    void BanAll();

    /// @fn void CDC::Admin::UnbanAll()
    /// @brief write 0 to emergency file - set normal mode
    /// @details Secure manager will check this file to allow/deny all actions on system
    void UnbanAll();
    // ---------------------------------------------------------------



private:
    std::string LoginFilePath;
    std::string EnteredUsersPath;
    std::string EmergencyPath;
};

} // namespace CDC

#endif // CDC_ADMIN_HPP
