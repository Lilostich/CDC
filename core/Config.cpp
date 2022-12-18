#include "Config.hpp"

// help functions
// ---------------------------------------------------------------------------
bool CDC::OpenCfg(std::string ConfigPath, Config& Cfg){
    try {
        cfg.readFile(ConfigPath);
    } catch(const std::FileIOException &fioex) {
        std::cerr << "I/O error while reading file " << ConfigPath << endl;
        return false;
    } catch(const std::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << std::endl;
        return false;
    }

    return true;
}


bool CDC::GetListFromCfg(std::string ListName, Config &Cfg, Setting &List){
    Setting &root = cfg.getRoot();          // get root of cfg

    // check List existance
    if (! root.exists(ListName)) {
        std::cerr << "List " << ListName << "does not exist in cfg" << std::endl;
        return false;
    }

    List = root[ListName];          // get users List

    // check users is List
    if (! List.isList()) {
        std::cerr << "List " << ListName << "is not List in cfg" << std::endl;
        return false;
    }

    return true;
}


int CDC::GetGroupFromList(Setting &List, std::string Entry, std::string EntryVal){
    // find entry in group
    std::string tmp_value = "";
    for (auto it = List.begin(); it < List.end(); it++) {
        it->lookupValue(Entry, tmp_value);  // write found entry to tmp_value
        if (tmp_value == EntryValue) {
            return it->getIndex();
        }
    }
}
// ---------------------------------------------------------------------------



// User functions
// ---------------------------------------------------------------------------
std::string CDC::GetEntryFromConfig(std::string ConfigPath, std::string Entry) {
    Config cfg;
    std::string answer = "";

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return answer;

    // Get and set the Login File Path.
    try {
        answer = cfg.lookup(Entry);
    } catch (const SettingNotFoundException &nfex) {
        std::cerr << "No" << Entry << "setting in configuration file " << ConfigPath << std::endl;
    }

    return answer;
}


bool CDC::CheckEntryOfGroupInList(std::string ConfigPath, std::string ListName, std::string Entry, std::string EntryValue) {
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting List;
    if (! GetListFromCfg(ListName, cfg, List))
        return false;

    if (GetGroupFromList(List, Entry, EntryValue) != -1)
        return true;

    return false;
}


/*
bool CDC::CheckEntriesInList(string ConfigPath, string ListName, string Entries[], string EntryValues[], int num){
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting List;
    if (! GetListFromCfg(ListName, Cfg, List))
        return false;

    // check required entry
    string tmp_value = "";
    int checked_num = 0;
    for (auto it = List.begin(); it < List.end(); it++) {
        // check every specified entry
        for (int checked_num_tmp = checked_num; checked_num_tmp < num; checked_num_tmp++) {
            *it.lookupValue(Entries[checked_num_tmp], tmp_value);  // write found entry to tmp_value
            if (tmp_value == EntryValues[checked_num_tmp])
                checked_num++;
            else {
                // if almost one entry is not OK -> go to the next List element
                checked_num = 0;
                break;
            }
        }

        if (checked_num >= num)
            return true;
    }

    return false;
}
*/


bool CDC::AddGroupToList(std::string ConfigPath, std::string ListName, std::string entry_1,
                std::string entry_2, std::string entry_1_val, unsigned short entry_2_val){
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting List;
    if (! GetListFromCfg(ListName, cfg, List))
        return false;

    // Add entry
    Setting &entry = List.add(Setting::TypeGroup);
    entry.add(entry_1, Setting::TypeString) = entry_1_val;
    entry.add(entry_2, Setting::TypeInt) = entry_2_val;

    // write updated cfg
    cfg.writeFile(ConfigPath);

    return true;
}


bool CDC::DeleteGroupFromList(std::string ConfigPath, std::string ListName,
                              std::string Entry, std::string EntryVal){
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting List;
    if (! GetListFromCfg(ListName, cfg, List))
        return false;

    // find and remove required entry
    int index = GetGroupFromList(List, Entry, EntryValue);
    if (index != - 1) {
        List.remove(index);
        return true;
    }

    return false;
}


bool CDC::AddEntryToGroupOfList(Setting &List, int GroupIndex,
                            std::string Entry, std::string EntryVal){
    Setting Group = List[GroupIndex];
    Group.add(Entry, Setting::TypeString) = EntryVal;
    return true;
}


bool CDC::DeleteEntryOfGroupOfList(Setting &List, int GroupIndex, std::string Entry){
    Setting = Group = List[GroupIndex];
    try {
        Group.remove(Entry);
    } catch (const SettingNotFoundException &ex) {
        std::cerr << "No" << Entry << "setting in Group" << std::endl;
        return false;
    }

    return true;
}

bool CDC::UpdateGroupOfList(std::string ConfigPath, std::string ListName,
                            std::string Entry_1, std::string Entry_2,
                            std::string EntryVal_1, std::string EntryVal_2);{
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting List;
    if (! GetListFromCfg(ListName, cfg, List))
        return false;

    // find required group with entry
    int index = GetGroupFromList(List, Entry_1, EntryVal_1);

    if (! DeleteEntryOfGroupOfList(List, index, Entry_2))
        return false;

    return AddEntryToGroupOfList(List, index, Entry_2, EntryVal_1);

}
// ---------------------------------------------------------------------------
