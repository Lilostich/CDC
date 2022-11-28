#ifndef CDC_ADMIN_HPP
#define CDC_ADMIN_HPP

#include "CDC.h"            // global basic configs
#include "Config.h"         //

#include <libconfig.h>      // Read cfg files
#include <stdio.h>


namespace CDC {

    class Admin {
        public:
            Admin();
            Admin(string MainCFG);

            ~Admin();

        private:
            string LoginFilePath;
            string EnteredUsersPath;
    }

}

#endif // CDC_ADMIN_HPP
