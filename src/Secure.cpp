#include "Admin.hpp"

using namespace CDC;

CDC::Secure::Secure(string MainCFG) {
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


void CDC::Secure::GetPaths(){
    printf("%-20s\n", "Secure paths");
    printf("%-20s%-20s\n", "LoginFilePath", LoginFilePath.c_str());
    printf("%-20s%-20s\n", "EnteredUsersPath", EnteredUsersPath.c_str());
    printf("%-20s%-20s\n", "EmergencyPath", EmergencyPath.c_str());
    printf("%-20s%-20d\n", "SecureLevel", SecureLevel);
}


bool Enter(string Login, string Passwd){
    // check user existance
    if (! CheckGroup_InConfig(LoginFilePath, Login)) {
        cerr << "No such user: " << Login << endl;
        return false;
    }

    // get real passwd
    string RealHash = GetStringEntry_InGroup(LoginFilePath, Login, "passwd");
    if (RealHash.size() == 0) {
        cerr << "No such field: " << "passwd" << endl;
        return false;           // maybe registration was not executed
    }

    // get input hash
    string InputHash = Hide(Passwd);

    // compare passwords
    if (InputHash != RealHash) {
        cerr << "Wrong password" << endl;
        return false;
    }

    // OK enter -> set Secure Level
    SecureLevel = GetIntEntry_InGroup(LoginFilePath, Login, "level");
    if (SecureLevel == -1) {
        cerr << "No such field: " << "level" << endl;
        return false;           // WHAT???
    }

    // check entered
    if (CheckGroup_InConfig(EnteredUsersPath, Login)) {
    // entry was not removed
        // kill process
        int pid = GetIntEntry_InGroup(EnteredUsersPath, Login, "pid");
        if (pid != -1) {
            string cmd = "kill " + to_string(pid) + "; sleep 1; kill -9 " + to_string(pid);
            system(cmd);    // in shell :-)
        }
    }

    // update entry
    pid_t pid = getpid();
    AddGroup_InConfig(EnteredUsersPath, Login, "level", SecureLevel);
    AddGroup_InConfig(EnteredUsersPath, Login, "pid", pid);

    // set current login
    CurrentLogin = Login;

    return true;
}


void Exit() {
    if (CheckGroup_InConfig(EnteredUsersPath, CurrentLogin))
        DelGroup_InConfig(EnteredUsersPath, CurrentLogin);

    // TODO: THINK (maybe this must be inside of GUI)
    exit(0);
}


bool CDC::Secure::Register(string Login, string Passwd){
    string InputHash = Hide(Passwd);
    return AddGroup_InConfig(LoginFilePath, Login, "passwd", InputHash.c_str());
}


bool CDC::Secure::CheckCapability(unsigned short RequiredLevel){
    if (SecureLevel <= RequiredLevel)
        return true;
    else
        return false;

}


// HASH
// ---------------------------------------------------------------------------
bool CDC::Secure::invalidChar(char c) {
    return !(c>=21 && c <128);
}

void CDC::Secure::stripUnicode(std::string & str) {
    str.erase(remove_if(str.begin(),str.end(), invalidChar), str.end());
}

string CDC::Secure::Hide(string Passwd){
    unsigned char hash[100];

    // create hash
    SHA512(reinterpret_cast<const unsigned char*>(Passwd.c_str()), Passwd.size() - 1, hash);

    // remove non-print characters
    string HASH(reinterpret_cast<const char*>(hash));
    stripUnicode(HASH);

    return HASH;
}
// ---------------------------------------------------------------------------

