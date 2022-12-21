// Config module
#ifndef CDC_CONFIG_HPP
#define CDC_CONFIG_HPP

#include <string.h>
#include <libconfig.h++>      // Read cfg files
#include <iostream>

using namespace libconfig;
using namespace std;

namespace CDC {

    // paths
    // -----------------------------------------------------------------------
    const string MAIN_CFG = "./CDC.cfg";
    // -----------------------------------------------------------------------


    // help functions - check and set specified param
    // -----------------------------------------------------------------------
    /// @fn bool CDC::OpenCfg(string ConfigPath, Config& Cfg)
    /// @brief Read cfg file to Config object
    /// @details Print error string to stderr in case of some error and return false
    /// @param ConfigPath path to .cfg file
    /// @param Cfg Config object to store read file
    /// @return true in case of successful read else false
    bool OpenCfg(string ConfigPath, Config& Cfg);

    /// @fn bool CDC::GetListFromCfg(string ListName, Config &Cfg, Setting &List)
    /// @brief Check existing of List in cfg object, set List from cfg to List variable
    /// @param ListName name of list entry in cfg
    /// @param Cfg Config object which stores list
    /// @param List Setting object where to set found List (write list to this param)
    /// @return true in case of successful gettting else false
    bool GetListFromCfg(string ListName, Config &Cfg, Setting* List);

    /// @fn int CDC::GetGroupFromList(Setting &List, string Entry, string EntryVal)
    /// @brief Get index of group of list with specified entry
    /// @param List setting object
    /// @param Entry entry name
    /// @param EntryVal entry values
    /// @return Group Index of list else -1
    int GetGroupIndexFromList(Setting* List, string Entry, string EntryVal);
    // -----------------------------------------------------------------------

    // user functions
    // -----------------------------------------------------------------------
    /// @fn string CDC::GetEntry_InConfig(string ConfigPath, string Entry)
    /// @brief Function allows read simple string entry from .cfg file
    /// @details Print info to stderr in case of some error
    /// @param ConfigPath path to .cfg file
    /// @param Entry path entry to get from .cfg file
    /// @return [string] entry from cfg file. In case of fail returns empty string.
    string GetEntry_InConfig(string ConfigPath, string Entry);

    /// @fn int CDC::GetEntry_InConfig(string ConfigPath, string Entry)
    /// @brief As above, but return int
    /// @return [int] entry from cfg file. In case of fail returns -1.
    int GetIntEntry_InConfig(string ConfigPath, string Entry);

    /// @fn string CDC::GetStringEntry_InGroup(string ConfigPath, string GroupName, string Field)
    /// @brief Get field of the specified group of Config file
    /// @details 1 level tree
    /// @param ConfigPath path to .cfg file
    /// @param GroupName name of group
    /// @param Field field
    /// @return [string] entry from group of cfg file. In case of fail returns empty string.
    string GetStringEntry_InGroup(string ConfigPath, string GroupName, string Field);

    /// @fn string CDC::GetIntEntry_InGroup(string ConfigPath, string GroupName, string Field)
    /// @brief As GetStringEntry_InGroup, but return int value
    /// @return [int] entry from group of cfg file. In case of fail returns -1.
    int GetIntEntry_InGroup(string ConfigPath, string GroupName, string Field);

    /// @fn bool CDC::CheckEntryOfGroupInList(string ConfigPath,
    ///               string ListName, string Entry, string EntryValue)
    /// @brief Check entry value of group in specified list
    /// @details Check, that specified entry exists in some group of list.
    ///          Check only the first level of cfg tree. Print info to stderr in case of some error.
    /// @param ConfigPath path to .cfg file
    /// @param ListName name of list
    /// @param Entry name of entry of group of list
    /// @param EntryValue value of entry
    /// @return True in case of success otherwise false
    bool CheckEntryOfGroupInList(string ConfigPath, string ListName, string Entry, string EntryValue);


    // Group in cfg: 1 tree level (for example: login file)
    // -----------------------------------------------------------------------
    /// @fn bool CDC::CheckGroup_InConfig(string ConfigPath, string GroupName)
    /// @brief Check group in cfg file
    /// @details Check only the first level of cfg tree. Print info to stderr in case of some error.
    ///          For cfg file with groups only (1 level of tree).
    /// @param ConfigPath path to .cfg file
    /// @param GroupName name cfg file
    /// @return True in case of success otherwise false
    bool CheckGroup_InConfig(string ConfigPath, string GroupName);

    /// @fn bool CDC::AddGroup_InConfig(string ConfigPath, string GroupName, string Field, unsigned short EntryVal)
    /// @brief Add group into cfg file, Add or update Field with EntryVal.
    /// @details Check only the first level of cfg tree. Print info to stderr in case of some error.
    ///          For cfg file with groups only (1 level of tree). If group does not exist -> add group.
    ///          If Field exist -> update field.
    /// @param ConfigPath path to .cfg file
    /// @param GroupName name cfg file
    /// @param Field field in group
    /// @param EntryVal Value to add into group by Field
    /// @return True in case of success otherwise false
    bool AddGroup_InConfig(string ConfigPath, string GroupName, string Field, int EntryVal);

    /// @fn bool CDC::AddGroup_InConfig(string ConfigPath, string GroupName, string Field, string EntryVal)
    /// @brief Overload the previous function.
    bool AddGroup_InConfig(string ConfigPath, string GroupName, string Field, string EntryVal);

    /// @fn bool CDC::DelGroup_InConfig(LoginFilePath, login)
    /// @brief Delete group from cfg file.
    /// @details Check only the first level of cfg tree. Print info to stderr in case of some error.
    ///          For cfg file with groups only (1 level of tree). If group does not exist -> return true.
    /// @param ConfigPath path to .cfg file
    /// @param GroupName name cfg file
    /// @return True in case of success otherwise false
    bool DelGroup_InConfig(string ConfigPath, string GroupName);
    // -----------------------------------------------------------------------

    /*
    /// @fn bool CDC::CheckEntriesInList(string ConfigPath, string ListName, string Entries[], string EntryValues[], int Num)
    /// @brief Check entries values of specified entries in specified list
    /// @details Check only the first level of cfg tree. For example, func maybe used for checking two entries of login file:
    ///          login and level.
    /// @param ConfigPath path to .cfg file
    /// @param ListName name of list
    /// @param Entries names of entries
    /// @param EntryValues values of entries
    /// @param Num - number of checkable entries and entry values
    /// @return True in case of success otherwise false
    bool CheckEntriesInList(string ConfigPath, string ListName, string Entries[], string EntryValues[], int num);
    */

    /// @fn bool CDC::AddGroupToList(string ConfigPath, string ListName, string entry_1,
    ///                         string entry_2, string entry_1_val, unsigned short entry_2_val)
    /// @brief Add group entry to list of cfg
    /// @details Check only the first level of cfg tree. Print info to stderr in case of some error
    /// @param ConfigPath path toList
    /// @param entry_1 name of the first entry
    /// @param entry_2 name of the second entry
    /// @param entry_1_val value of the first entry [string]
    /// @param entry_2_val value of the second entry [unsigned short]
    /// @return True in case of success otherwise false
    // TODO: template?
    bool AddGroupToList(string ConfigPath, string ListName, string entry_1,
                        string entry_2, string entry_1_val, unsigned short entry_2_val);

    /// @fn bool CDC::DeleteGroupFromList(string ConfigPath, string ListName, string Entry, string EntryVal)
    /// @brief Remove group entry from list of cfg
    /// @details Check only the first level of cfg tree. Print info to stderr in case of some error
    /// @param ConfigPath path to .cfg
    /// @param ListName list name in config
    /// @param Entry name of the entry in list
    /// @param EntryVal value of the fentry
    /// @return True in case of success otherwise false
    bool DeleteGroupFromList(string ConfigPath, string ListName, string Entry, string EntryVal);

    /// @fn bool CDC::AddEntryToGroupOfList(Setting &List, int GroupIndex,
    ///                                     string Entry, string EntryVal);
    /// @brief Add entry to group with specified index of List
    /// @param List Setting object
    /// @param GroupIndex index of group of list
    /// @param Entry name of the entry
    /// @param EntryVal value of the entry
    /// @return True in case of success otherwise false
    bool AddEntryToGroupOfList(Setting* List, int GroupIndex,
                               string Entry, string EntryVal);

    /// @fn bool CDC::DeleteEntryOfGroupOfList(Setting &List, int GroupIndex,
    ///                                        string Entry);
    /// @brief Remove entry of group with specified index of List
    /// @param List Setting object
    /// @param GroupIndex index of group of list
    /// @param Entry name of the entry
    /// @return True in case of success otherwise false
    bool DeleteEntryOfGroupOfList(Setting* List, int GroupIndex, string Entry);

    /// @fn bool CDC::UpdateGroupOfList(string ConfigPath, string ListName,
    ///                                 string FindEntry, string SetEntry,
    ///                                 string FindEntryVal, string SetEntryVal);
    /// @brief Update entry of list's group
    /// @param ConfigPath path to .cfg
    /// @param ListName name of list on cfg file
    /// @param FindEntry entry which will help find required group
    /// @param SetEntry entry which will been update in found group
    /// @param FindEntryVal entry value which will help find required group
    /// @param SetEntryVal entry value which will been written to found group
    /// @return True in case of success otherwise false
    bool UpdateGroupOfList(string ConfigPath, string ListName,
                        string FindEntry, string SetEntry,
                        string FindEntryVal, string SetEntryVal);
    // -----------------------------------------------------------------------

}

#endif // CDC_CONFIG_HPP
