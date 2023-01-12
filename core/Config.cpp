#include "Config.hpp"

// Compile
// g++ -c Config.cpp -o Config.o

// help functions
// ---------------------------------------------------------------------------
bool CDC::OpenCfg(string ConfigPath, Config& Cfg){
    try {
        Cfg.readFile(ConfigPath.c_str());
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


bool CDC::GetListFromCfg(string ListName, Config &Cfg, Setting* List){
    Setting &root = Cfg.getRoot();          // get root of cfg

    // check List existance
    if (! root.exists(ListName)) {
        cerr << "List " << ListName << "does not exist in cfg" << endl;
        return false;
    }

    *List = *root[ListName.c_str()];          // get users List

    // check users is List
    if (! List->isList()) {
        cerr << "List " << ListName << "is not List in cfg" << endl;
        return false;
    }

    return true;
}


int CDC::GetGroupIndexFromList(Setting* List, string Entry, string EntryVal){
    // find entry in group
    string tmp_value = "";
    int list_length = List->getLength();
    for (int i = 0; i < list_length; i++) {
        Setting &list_entry = (*List)[i];
        list_entry.lookupValue(Entry, tmp_value);  // write found entry to tmp_value
        if (tmp_value == EntryVal) {
            return list_entry.getIndex();
        }
    }
    /*
    for (iterator it = List->begin(); it != List->end(); it++) {
        it->lookupValue(Entry, tmp_value);  // write found entry to tmp_value
        if (tmp_value == EntryVal) {
            return it->getIndex();
        }
    }
    */

    return -1;
}
// ---------------------------------------------------------------------------



// User functions
// ---------------------------------------------------------------------------
string CDC::GetEntry_InConfig(string ConfigPath, string Entry) {
    Config cfg;
    string answer = "";

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return answer;

    // Get and set the Login File Path.
    try {
        const char* tmp_answer = cfg.lookup(Entry);
        answer = tmp_answer;
    } catch (const SettingNotFoundException &nfex) {
        cerr << "No " << Entry << " setting in configuration file " << ConfigPath << endl;
    }

    return answer;
}

int CDC::GetIntEntry_InConfig(string ConfigPath, string Entry) {
    Config cfg;
    int answer = -1;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return answer;

    // Get and set the Login File Path.
    try {
        answer = cfg.lookup(Entry);
    } catch (const SettingNotFoundException &nfex) {
        cerr << "No " << Entry << " setting in configuration file " << ConfigPath << endl;
    }

    return answer;
}


bool CDC::AddEntry_InConfig(string ConfigPath, string Entry, string EntryVal){
    // read config
    Config cfg;
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // get root of cfg
    Setting& Root = cfg.getRoot();

    // create or updare entry
    if (Root.exists(Entry.c_str()))
        Root.remove(Entry.c_str());

    // add new field
    Root.add(Entry, Setting::TypeString) = EntryVal;
    cfg.writeFile(ConfigPath.c_str());
    return true;
}


bool CDC::AddEntry_InConfig(string ConfigPath, string Entry, int EntryVal){
    // read config
    Config cfg;
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // get root of cfg
    Setting& Root = cfg.getRoot();

    // create or updare entry
    if (Root.exists(Entry.c_str()))
        Root.remove(Entry.c_str());

    // add new field
    Root.add(Entry, Setting::TypeInt) = EntryVal;
    cfg.writeFile(ConfigPath.c_str());
    return true;
}


string CDC::GetStringEntry_InGroup(string ConfigPath, string GroupName, string Field) {
    Config cfg;
    string answer = "";

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return answer;

    // Get and set the Login File Path.
    try {
        Setting& Group = cfg.lookup(GroupName);
        try {
            const char* tmp_answer = Group.lookup(Field);
            answer = tmp_answer;
        } catch (const SettingNotFoundException &nfex) {
            cerr << "No " << Field << " setting in group " << GroupName << endl;
        }
    } catch (const SettingNotFoundException &nfex) {
        cerr << "No " << GroupName << " setting in configuration file " << ConfigPath << endl;
    }

    return answer;
}


int CDC::GetIntEntry_InGroup(string ConfigPath, string GroupName, string Field) {
    Config cfg;
    int answer = -1;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return answer;

    // Get and set the Login File Path.
    try {
        Setting& Group = cfg.lookup(GroupName);
        try {
            answer = Group.lookup(Field);
        } catch (const SettingNotFoundException &nfex) {
            cerr << "No " << Field << " setting in group " << GroupName << endl;
        }
    } catch (const SettingNotFoundException &nfex) {
        cerr << "No " << GroupName << " setting in configuration file " << ConfigPath << endl;
    }

    return answer;
}


bool CDC::CheckEntryOfGroupInList(string ConfigPath, string ListName, string Entry, string EntryValue) {
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting* List;
    if (! GetListFromCfg(ListName, cfg, List))
        return false;

    if (GetGroupIndexFromList(List, Entry, EntryValue) != -1)
        return true;

    return false;
}

// Group in cfg: 1 tree level
// ---------------------------------------------------------------------------
bool CDC::CheckGroup_InConfig(string ConfigPath, string GroupName){
    // read config
    Config cfg;
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // Find group
    try {
        cfg.lookup(GroupName);
        return true;
    } catch (const SettingNotFoundException &nfex) {
        return false;
    }
}


// add int value
bool CDC::AddGroup_InConfig(string ConfigPath, string GroupName, string Field, int EntryVal){
    // read config
    Config cfg;
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // get root of cfg
    Setting& Root = cfg.getRoot();

    if (! CheckGroup_InConfig(ConfigPath, GroupName)) {
    // if group does not exist -> add this group
        Setting& group = Root.add(GroupName, Setting::TypeGroup);
        group.add(Field, Setting::TypeInt) = EntryVal;

        // write updated cfg
        cfg.writeFile(ConfigPath.c_str());
        return true;

    } else {
    // if group exists -> add or update field
        // get Group
        Setting& group = Root[GroupName.c_str()];

        // if field exists -> remove
        if (group.exists(Field.c_str()))
            group.remove(Field.c_str());

        // add field
        group.add(Field, Setting::TypeInt) = EntryVal;
        // write updated cfg
        cfg.writeFile(ConfigPath.c_str());
        return true;
    }
}


// add string value
bool CDC::AddGroup_InConfig(string ConfigPath, string GroupName, string Field, string EntryVal){
    // read config
    Config cfg;
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // get root of cfg
    Setting& Root = cfg.getRoot();

    if (! CheckGroup_InConfig(ConfigPath, GroupName)) {
    // if group does not exist -> add this group
        Setting& group = Root.add(GroupName, Setting::TypeGroup);
        group.add(Field, Setting::TypeString) = EntryVal.c_str();

        // write updated cfg
        cfg.writeFile(ConfigPath.c_str());
        return true;

    } else {
    // if group exists -> add or update field
        // get Group
        Setting& group = Root[GroupName.c_str()];

        // if field exists -> remove
        if (group.exists(Field.c_str()))
            group.remove(Field.c_str());

        // add field
        group.add(Field, Setting::TypeString) = EntryVal.c_str();
        // write updated cfg
        cfg.writeFile(ConfigPath.c_str());
        return true;
    }
}


bool CDC::DelGroup_InConfig(string ConfigPath, string GroupName){
    // read config
    Config cfg;
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // get root of cfg
    Setting& Root = cfg.getRoot();

    if (! CheckGroup_InConfig(ConfigPath, GroupName)) {
    // if group does not exist -> OK
        return true;

    } else {
    // if group exists -> remove
        Root.remove(GroupName.c_str());

        // write updated cfg
        cfg.writeFile(ConfigPath.c_str());
        return true;
    }
}
// ---------------------------------------------------------------------------


bool CDC::AddGroupToList(string ConfigPath, string ListName, string entry_1,
                string entry_2, string entry_1_val, unsigned short entry_2_val){
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting* List;
    if (! GetListFromCfg(ListName, cfg, List))
        return false;

    // Add entry
    Setting &entry = List->add(Setting::TypeGroup);
    entry.add(entry_1, Setting::TypeString) = entry_1_val;
    entry.add(entry_2, Setting::TypeInt) = entry_2_val;

    // write updated cfg
    cfg.writeFile(ConfigPath.c_str());

    return true;
}


bool CDC::DeleteGroupFromList(string ConfigPath, string ListName,
                              string Entry, string EntryVal){
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting* List;
    if (! GetListFromCfg(ListName, cfg, List))
        return false;

    // find and remove required entry
    int index = GetGroupIndexFromList(List, Entry, EntryVal);
    if (index != - 1) {
        List->remove(index);
        return true;
    }

    return false;
}


bool CDC::AddEntryToGroupOfList(Setting *List, int GroupIndex,
                            string Entry, string EntryVal){
    Setting &Group = (*List)[GroupIndex];
    Group.add(Entry, Setting::TypeString) = EntryVal;
    return true;
}


bool CDC::DeleteEntryOfGroupOfList(Setting* List, int GroupIndex, string Entry){
    Setting &Group = (*List)[GroupIndex];
    try {
        Group.remove(Entry);
    } catch (const SettingNotFoundException &ex) {
        cerr << "No" << Entry << "setting to Group" << endl;
        return false;
    }

    return true;
}

bool CDC::UpdateGroupOfList(string ConfigPath, string ListName,
                            string Entry_1, string Entry_2,
                            string EntryVal_1, string EntryVal_2){
    Config cfg;

    // read config
    if (! OpenCfg(ConfigPath, cfg))
        return false;

    // check List in Cfg
    Setting* List;
    if (! GetListFromCfg(ListName, cfg, List))
        return false;

    // find required group with entry
    int index = GetGroupIndexFromList(List, Entry_1, EntryVal_1);

    if (! DeleteEntryOfGroupOfList(List, index, Entry_2))
        return false;

    return AddEntryToGroupOfList(List, index, Entry_2, EntryVal_2);

}
// ---------------------------------------------------------------------------
