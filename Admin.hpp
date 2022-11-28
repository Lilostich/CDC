#ifndef CDC_ADMIN_HPP
#define CDC_ADMIN_HPP

#include "CDC.h"            // global basic configs
#include "Config.h"         //

#include <libconfig.h>      // Read cfg files
#include <stdio.h>

/// @class CDC::Admin
/// @brief Admin panel functions without GUI
namespace CDC {

    class Admin {
        public:
            Admin();
            Admin(string CFG);

            int AddUser(string login, unsigned short secure_level);
            int DeleteUser(string login);
            int SetLevel(string login, unsigned short secure_level);
            int BanAll();
            int UnbanAll;

            ~Admin();

        private:
            string LoginFilePath;
            string EnteredUsersPath;
    }

}

#endif // CDC_ADMIN_HPP
