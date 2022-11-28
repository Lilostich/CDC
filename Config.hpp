// Config module
#ifndef CDC_CONFIG_HPP
#define CDC_CONFIG_HPP

#include <string.h>

namespace CDC {

    // paths
    // -----------------------------------------------------------------------
    const string MAIN_CFG = "./CDC.cfg";
    // -----------------------------------------------------------------------


    // contants
    // -----------------------------------------------------------------------
    unsigned short ADMIN_LEVEL = 0;
    unsigned short ANALYST_LEVEL = 1;
    unsigned short TESTER_LEVEL = 2;
    unsigned short GUEST_LEVEL = 3;
    unsigned short BAN_LEVEL = 10;
    // -----------------------------------------------------------------------

    // functions
    // -----------------------------------------------------------------------
    string GetEntryFromConfig(strnig ConfigPath, string Entry);
    // -----------------------------------------------------------------------

}

#endif // CDC_CONFIG_HPP
