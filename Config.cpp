#include "Config.hpp"

// help functions
// ---------------------------------------------------------------------------
bool CDC::OpenCfg(string ConfigPath, Config& Cfg){
    try {
        cfg.readFile(ConfigPath);
    } catch(const FileIOException &fioex) {
        cerr << "I/O error while reading file " << ConfigPath << endl;
        return false;
    } catch(const ParseException &pex) {
        cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << endl;
        return false;
    }

    return true;
}


bool CDC::GetListFromCfg(string ListName, Config &Cfg, Setting &List){
    Setting &root = cfg.getRoot();          // get root of cfg

    // check List existance
    if (! root.exists(ListName)) {
        cerr << "List " << ListName << "does not exist in cfg" << endl;
        return false;
    }

    List = root[ListName];          // get users List

    // check users is List
    if (! List.isList()) {
        cerr << "List " << ListName << "is not List in cfg" << endl;
        return false;
    }

    return true;
}


int CDC::GetGroupFromList(Setting &List, string Entry, string EntryVal){
    // find entry in group
    string tmp_value = "";
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
string CDC::GetEntryFromConfig(string ConfigPath, string Entry) {
    Config cfg;
    string answer = "";

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return answer;

    // Get and set the Login File Path.
    try {
        answer = cfg.lookup(Entry);
    } catch (const SettingNotFoundException &nfex) {
        cerr << "No" << Entry << "setting in configuration file " << ConfigPath << endl;
    }

    return answer;
}


bool CDC::CheckEntryOfGroupInList(string ConfigPath, string ListName, string Entry, string EntryValue) {
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


bool CDC::AddGroupToList(string ConfigPath, string ListName, string entry_1,
                string entry_2, string entry_1_val, unsigned short entry_2_val){
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


bool CDC::DeleteGroupFromList(string ConfigPath, string ListName,
                              string Entry, string EntryVal){
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


bool CDC::AddEntryToGroupOfList(Setting &List, int GroupIndex
                            string Entry, string EntryVal){
    Setting Group = List[GroupIndex];
    Group.add(Entry, Setting::TypeString) = EntryVal;
    return true;
}


bool CDC::DeleteEntryOfGroupOfList(Setting &List, int GroupIndex, string Entry){
    Setting = Group = List[GroupIndex];
    try {
        Group.remove(Entry);
    } catch (const SettingNotFoundException &ex) {
        cerr << "No" << Entry << "setting in Group" << endl;
        return false;
    }

    return true;
}

bool CDC::UpdateGroupOfList(string ConfigPath, string ListName,
                            string Entry_1, string Entry_2,
                            string EntryVal_1, string EntryVal_1);{
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
