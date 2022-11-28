// Config module
#ifndef CDC_CONFIG_HPP
#define CDC_CONFIG_HPP

#include <string.h>

namespace CDC {

    // constants
    // -----------------------------------------------------------------------
    const string MainCFG = "./CDC.cfg";
    // -----------------------------------------------------------------------

    // functions
    // -----------------------------------------------------------------------
    string GetEntryFromConfig(strnig ConfigPath, string Entry);
    // -----------------------------------------------------------------------

}

#endif // CDC_CONFIG_HPP
