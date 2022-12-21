#include "Secure.hpp"

using namespace CDC;

CDC::Secure::Secure(std::string MainCFG) {
    // read LoginFilePath
    std::string tmp_str = GetEntry_InConfig(MainCFG, "SysLogin");
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


bool CDC::Secure::Enter(std::string Login, std::string Passwd){
    // check user existance
    if (! CheckGroup_InConfig(LoginFilePath, Login)) {
        std::cerr << "No such user: " << Login << std::endl;
        return false;
    }

    // get real passwd
    std::string RealHash = GetStringEntry_InGroup(LoginFilePath, Login, "passwd");
    if (RealHash.size() == 0) {
        std::cerr << "No such field: " << "passwd" << std::endl;
        return false;           // maybe registration was not executed
    }

    // get input hash
    std::string InputHash = Hide(Passwd);

    // compare passwords
    if (InputHash != RealHash) {
        std::cerr << "Wrong password" << std::endl;
        return false;
    }

    // OK enter -> set Secure Level
    SecureLevel = GetIntEntry_InGroup(LoginFilePath, Login, "level");
    if (SecureLevel == -1) {
        std::cerr << "No such field: " << "level" << std::endl;
        return false;           // WHAT???
    }

    // check entered
    if (CheckGroup_InConfig(EnteredUsersPath, Login)) {
    // entry was not removed
        // kill process
        int pid = GetIntEntry_InGroup(EnteredUsersPath, Login, "pid");
        if (pid != -1) {
            std::cerr << "Process of " << Login << " was found -> kill " << pid << std::endl;
            std::string cmd = "kill " + std::to_string(pid) + " 2> /dev/null; sleep 1; kill -9 " + std::to_string(pid) + " 2> /dev/null";
            system(cmd.c_str());    // in shell :-)
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


void CDC::Secure::Exit(bool ExitVal) {
    if (CheckGroup_InConfig(EnteredUsersPath, CurrentLogin))
        DelGroup_InConfig(EnteredUsersPath, CurrentLogin);

    if (ExitVal)
        exit(0);
}


bool CDC::Secure::Register(std::string Login, std::string Passwd){
    if (! CheckGroup_InConfig(LoginFilePath, Login)) {
        std::cerr << "No such user: " << Login << std::endl;
        return false;
    }

    std::string InputHash = Hide(Passwd);
    return AddGroup_InConfig(LoginFilePath, Login, "passwd", InputHash.c_str());
}


bool CDC::Secure::CheckCapability(unsigned short RequiredLevel){
    std::string cmd = "cat " + EmergencyPath + " | grep -q 1";
    if (! system(cmd.c_str()))
        return false;

    if (SecureLevel <= RequiredLevel)
        return true;
    else
        return false;

}


// HASH
// ---------------------------------------------------------------------------
//bool CDC::Secure::invalidChar(char c) {
bool invalidChar(char c) {
    return !(c>=33 && c <126);
}

//void CDC::Secure::stripUnicode(string & str) {
void stripUnicode(std::string & str) {
    str.erase(remove_if(str.begin(),str.end(), invalidChar), str.end());
}

std::string CDC::Secure::Hide(std::string Passwd){
    unsigned char hash[SHA256_DIGEST_LENGTH];

    // create hash
    SHA256(reinterpret_cast<const unsigned char*>(Passwd.c_str()), Passwd.size() - 1, hash);

    // remove non-print characters
    std::string HASH(reinterpret_cast<const char*>(hash));

    stripUnicode(HASH);
    return HASH;
}
// ---------------------------------------------------------------------------

