#include "Admin.hpp"
#include

using namespace CDC;

CDC::Admin::Admin(string MainCFG) {
    string tmp_str;

    // read LoginFilePath
    string tmp_str = GetEntryFromConfig(MainCFG, "SysLogin");
    if (tmp_str.empty()) {
        throw std::invalid_argument("Error to read Login Path from CFG file");
    } else {
        LoginFilePath = tmp_str;
    }

    // read EnteredUsersPath
    string tmp_str = GetEntryFromConfig(MainCFG, "SysEntered");
    if (tmp_str.empty()) {
        throw std::invalid_argument("Error to read Entered Users Path from CFG file");
    } else {
        EnteredUsersPath = tmp_str;
    }

    // read EmregencyPath
    string tmp_str = GetEntryFromConfig(MainCFG, "SysEmergency");
    if (tmp_str.empty()) {
        throw std::invalid_argument("Error to read Emeregency Path from CFG file");
    } else {
        EmergencyPath = tmp_str;
    }
}


int CDC::Admin::AddUser(string login, unsigned short secure_level) {
    // check login existance
    if (CheckEntryOfGroupInList(LoginFilePath, "users", "login", login))
        return true;

    // open file and write new entry about user;
    // User is added without passwd.
    return AddGroupToList(LoginFilePath, "users", "login", "level", login, secure_level);
}


int CDC::Admin::DeleteUser(string login); {
    // check login existance
    if (! CheckEntryOfGroupInList(LoginFilePath, "users", "login", login))
        return true;

    // open file and remove user group entry from one
    return DeleteGroupFromList(LoginFilePath, "users", "login", login);
}


int CDC::Admin::SetLevel(string login, unsigned short secure_level) {
    // check login existance
    if (! CheckEntryOfGroupInList(LoginFilePath, "users", "login", login))
        return false;

    // open file and update level
    return UpdateGroupOfList(LoginFilePath, "users", "login", "level", login, secure_level);
}


void CDC::Admin::BanAll(){
    ofstream ofs;
    ofs.open("test.txt", ofstream::out | ofstream::trunc);
    off << "1";
    ofs.close();
}

void CDC::Admin::UnBanAll(){
    ofstream ofs;
    ofs.open("test.txt", ofstream::out | ofstream::trunc);
    ofs << "0";
    ofs.close();
}

