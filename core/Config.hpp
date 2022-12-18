// Config module
#ifndef CDC_CONFIG_HPP
#define CDC_CONFIG_HPP

#include <string>
#include <iostream>
#include <libconfig.h>      // Read cfg files

using namespace libconfig;
//using namespace std;

namespace CDC {

    // paths
    // -----------------------------------------------------------------------
    const std::string MAIN_CFG = "./CDC.cfg";
    // -----------------------------------------------------------------------


    // help functions - check and set specified param
    // -----------------------------------------------------------------------
    /// @fn bool CDC::OpenCfg(string ConfigPath, Config& Cfg)
    /// @brief Read cfg file to Config object
    /// @details Print error string to stderr in case of some error and return false
    /// @param ConfigPath path to .cfg file
    /// @param Cfg Config object to store read file
    /// @return true in case of successful read else false
    bool OpenCfg(std::string ConfigPath, Config& Cfg);

    /// @fn bool CDC::GetListFromCfg(string ListName, Config &Cfg, Setting &List)
    /// @brief Check existing of List in cfg object, set List from cfg to List variable
    /// @param ListName name of list entry in cfg
    /// @param Cfg Config object which stores list
    /// @param List Setting object where to set found List
    /// @return true in case of successful gettting else false
    bool GetListFromCfg(std::string ListName, Config &Cfg, Setting &List);

    /// @fn int CDC::GetGroupFromList(Setting &List, string Entry, string EntryVal)
    /// @brief Get index of group of list with specified entry
    /// @param List setting object
    /// @param Entry entry name
    /// @param EntryVal entry values
    /// @return Grpup Index of list else -1
    int GetGroupFromList(Setting &List, std::string Entry, std::string EntryVal);
    // -----------------------------------------------------------------------

    // user functions
    // -----------------------------------------------------------------------
    /// @fn string CDC::GetEntryFromConfig(string ConfigPath, string Entry)
    /// @brief Function allows read simple string entry from .cfg file
    /// @details Print info to stderr in case of some error
    /// @param ConfigPath path to .cfg file
    /// @param Entry path entry to get from .cfg file
    /// @return [string] entry from cfg file. In case of fail returns empty string.
    std::string GetEntryFromConfig(std::string ConfigPath, std::string Entry);

    /// @fn bool CDC::CheckEntryOfGroupInList(string ConfigPath,
    ///               string ListName, string Entry, string EntryValue)
    /// @brief Check entry value of specified group in specified list
    /// @details Check only the first level of cfg tree. Print info to stderr in case of some error
    /// @param ConfigPath path to .cfg file
    /// @param ListName name of list
    /// @param Entry name of entry of group of list
    /// @param EntryValue value of entry
    /// @return True in case of success otherwise false
    bool CheckEntryOfGroupInList(std::string ConfigPath, std::string ListName,
                                 std::string Entry, std::string EntryValue);

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

    /// @fn CDC::AddGroupToList(string ConfigPath, string ListName, string entry_1,
    ///                         string entry_2, string entry_1_val, unsigned short entry_2_val)
    /// @brief Add group entry to list of cfg
    /// @details Check only the first level of cfg tree. Print info to stderr in case of some error
    /// @param ConfigPath path toList
    /// @param entry_1 name of the first entry
    /// @param entry_2 name of the second entry
    /// @param entry_1_val value of the first entry [string]
    /// @param entry_2_val value of the second entry [unsigned short]
    /// @return True in case of success otherwise false
    bool AddGroupToList(std::string ConfigPath, std::string ListName, std::string entry_1,
                        std::string entry_2, std::string entry_1_val, unsigned short entry_2_val);

    /// @fn bool CDC::DeleteGroupFromList(string ConfigPath, string ListName, string Entry, string EntryVal)
    /// @brief Remove group entry from list of cfg
    /// @details Check only the first level of cfg tree. Print info to stderr in case of some error
    /// @param ConfigPath path to .cfg
    /// @param ListName list name in config
    /// @param Entry name of the entry in list
    /// @param EntryVal value of the fentry
    /// @return True in case of success otherwise false
    bool DeleteGroupFromList(std::string ConfigPath, std::string ListName,
                             std::string Entry, std::string EntryVal);

    /// @fn CDC::bool AddEntryToGroupOfList(Setting &List, int GroupIndex,
    ///                                     string Entry, string EntryVal);
    /// @brief Add entry to group with specified index of List
    /// @param List Setting object
    /// @param GroupIndex index of group of list
    /// @param Entry name of the entry
    /// @param EntryVal value of the entry
    /// @return True in case of success otherwise false
    bool AddEntryToGroupOfList(Setting &List, int GroupIndex,
                               std::string Entry, std::string EntryVal);

    /// @fn CDC::bool DeleteEntryOfGroupOfList(Setting &List, int GroupIndex,
    ///                                        string Entry);
    /// @brief Remove entry of group with specified index of List
    /// @param List Setting object
    /// @param GroupIndex index of group of list
    /// @param Entry name of the entry
    /// @return True in case of success otherwise false
    bool DeleteEntryOfGroupOfList(Setting &List, int GroupIndex, std::string Entry);

    /// @fn CDC::bool UpdateGroupOfList(std::string ConfigPath, std::string ListName,
    ///                                 std::string FindEntry, std::string SetEntry,
    ///                                 std::string FindEntryVal, std::string SetEntryVal);
    /// @brief Update entry of list's group
    /// @param ConfigPath path to .cfg
    /// @param ListName name of list on cfg file
    /// @param FindEntry entry which will help find required group
    /// @param SetEntry entry which will been update in found group
    /// @param FindEntryVal entry value which will help find required group
    /// @param SetEntryVal entry value which will been written to found group
    /// @return True in case of success otherwise false
    bool UpdateGroupOfList(std::string ConfigPath, std::string ListName,
                        std::string FindEntry, std::string SetEntry,
                        std::string FindEntryVal, std::string SetEntryVal);
    // -----------------------------------------------------------------------

}

#endif // CDC_CONFIG_HPP
