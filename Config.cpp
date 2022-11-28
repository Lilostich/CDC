#include "Config.hpp"


/// @fn string CDC::GetEntryFromConfig(string ConfigPath, string Entry)
/// @brief Function allows read some entry from .cfg file
/// @param ConfigPath path to .cfg file
/// @param Entry path entry to get from .cfg file
/// @return [string] entry from cfg file. In case of fail returns empty string.
string CDC::GetEntryFromConfig(string ConfigPath, string Entry) {
    libconfig::Config cfg;
    string answer = "";

    // read config
    try {
        cfg.readFile(ConfigPath);
    } catch(const FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return answer;
    } catch(const ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << std::endl;
        return answer;
    }

    // Get and set the Login File Path.
    try {
        answer = cfg.lookup(Entry);
    } catch(const SettingNotFoundException &nfex) {
        cerr << "No" << Entry << "setting in configuration file " << ConfigPath << endl;
        return answer;
    }
}
