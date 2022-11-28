#include "Admin.hpp"

namespace CDC {

    /// @fn CDC::Admin(string MainCFG)
    /// @brief Init Admin class via CFG file
    /// @param ConfigPath path to .cfg file
    CDC::Admin(string MainCFG) {
        string tmp_str;

        // read LoginFilePath
        string tmp_str = GetEntryFromConfig(MainCFG, "SysLogin");
        if (tmp_str.empty()) {
            throw std::invalid_argument("Error to read Login Path from CFG file");
        } else {
            LoginFilePath = tmp_str;
        }

        // read EnteredUsersPath
        string tmp_str = GetEntryFromConfig(MainCFG, "SysEntered");
        if (tmp_str.empty()) {
            throw std::invalid_argument("Error to read Entered Users Path from CFG file");
        } else {
            EnteredUsersPath = tmp_str;
        }
    }


    /// @fn CDC::AddUser(string login, unsigned short secure_level)
    /// @brief Add User to Login files
    /// @param login string
    /// @param secure_level level
    /// @return 0 in case of success else 1
    int AddUser(string login, unsigned short secure_level) {
        // check login existance


        // open file and write info

    }

}
