#include "Admin.hpp"

using namespace CDC;

CDC::Admin::Admin(string MainCFG) {
    // read LoginFilePath
    string tmp_str = GetEntry_InConfig(MainCFG, "SysLogin");
    if (tmp_str.empty())
        throw std::invalid_argument("Error to read Login Path from CFG file");
    LoginFilePath = tmp_str;

    // read EnteredUsersPath
    tmp_str = GetEntry_InConfig(MainCFG, "SysEntered");
    if (tmp_str.empty())
        throw std::invalid_argument("Error to read Entered Users Path from CFG file");
    EnteredUsersPath = tmp_str;

    // read EmregencyPath
    tmp_str = GetEntry_InConfig(MainCFG, "SysEmergency");
    if (tmp_str.empty())
        throw std::invalid_argument("Error to read Emeregency Path from CFG file");
    EmergencyPath = tmp_str;
}


void CDC::Admin::GetPaths(){
    printf("%-20s\n", "Admin paths");
    printf("%-20s%-20s\n", "LoginFilePath", LoginFilePath.c_str());
    printf("%-20s%-20s\n", "EnteredUsersPath", EnteredUsersPath.c_str());
    printf("%-20s%-20s\n", "EmergencyPath", EmergencyPath.c_str());
}


bool CDC::Admin::AddUser(string login, unsigned short secure_level) {
    // check login existance
    if (CheckGroup_InConfig(LoginFilePath, login))
        return true;
    //if (CheckEntryOfGroupInList(LoginFilePath, "users", "login", login))
        //return true;

    // open file and write new entry about user;
    // User is added without passwd.
    //return AddGroupToList(LoginFilePath, "users", "login", "level", login, secure_level);
    return AddGroup_InConfig(LoginFilePath, login, "level", secure_level);
}


QStringList CDC::Admin::ListUsers(){
    QStringList Answer = {};
    string tmp_string;

    // read config
    Config cfg;
    if (! OpenCfg(LoginFilePath, cfg))
        return Answer;

    // get root of cfg
    Setting& Root = cfg.getRoot();

    int root_length = Root.getLength();
    for (int i = 0; i < root_length; i++) {
        Setting &group = Root[i];
        tmp_string = group.getName();

        Answer << QString::fromStdString(tmp_string);
    }

    return Answer;
}


QStringList CDC::Admin::UserInfo(string login){
    QStringList Answer = {};
    int tmp_level;
    string tmp_str = "Not registered";

    // read config
    Config cfg;
    if (! OpenCfg(LoginFilePath, cfg))
        return Answer;

    // Find group
    try {
        Setting &user = cfg.lookup(login);
        // login
        Answer << user.getName();
        qDebug("User::Name");
        qDebug(user.getName());
        // level
        user.lookupValue("level", tmp_level);
        Answer << QString::fromStdString(to_string(tmp_level));
        qDebug("User::level");
        qDebug(to_string(tmp_level).c_str());

        // register
        if (user.lookupValue("passwd", tmp_str))
            tmp_str = "Registered";
        Answer << QString::fromStdString(tmp_str);
        qDebug("User::pass");
        qDebug(to_string(tmp_level).c_str());
        return Answer;
    } catch (const SettingNotFoundException &nfex) {
        qDebug("User::Error");
        return Answer;
    }
}


bool CDC::Admin::DeleteUser(string login) {
    // check login existance
    //if (! CheckEntryOfGroupInList(LoginFilePath, "users", "login", login))
    //    return true;
    if (! CheckGroup_InConfig(LoginFilePath, login))
        return true;

    // open file and remove user group entry from one
    //return DeleteGroupFromList(LoginFilePath, "users", "login", login);
    return DelGroup_InConfig(LoginFilePath, login);
}


bool CDC::Admin::SetLevel(string login, unsigned short secure_level) {
    // check login existance
    //if (! CheckEntryOfGroupInList(LoginFilePath, "users", "login", login))
    //    return false;
    if (! CheckGroup_InConfig(LoginFilePath, login))
        return false;

    // open file and update level
    // return UpdateGroupOfList(LoginFilePath, "users", "login", "level", login, secure_level);
    return AddGroup_InConfig(LoginFilePath, login, "level", secure_level);
}


void CDC::Admin::BanAll(){
    ofstream ofs;
    ofs.open(EmergencyPath, ofstream::out | ofstream::trunc);
    ofs << "1" << endl;
    ofs.close();
}

void CDC::Admin::UnBanAll(){
    ofstream ofs;
    ofs.open(EmergencyPath, ofstream::out | ofstream::trunc);
    ofs << "0" << endl;
    ofs.close();
}

