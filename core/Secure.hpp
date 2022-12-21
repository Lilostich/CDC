#ifndef CDC_SECURE_HPP
#define CDC_SECURE_HPP

#include <stdio.h>
#include "stdlib.h"
#include <fstream>

#include <openssl/sha.h>        // passwd hash
#include <iostream>
#include <algorithm>

// pid
#include <sys/types.h>
#include <unistd.h>

#include "Config.hpp"           // cfg work
#include "Base.hpp"             // constants


/// @class CDC::Secure
/// @brief Secure panel functions without GUI
namespace CDC {

    // constants
    // -----------------------------------------------------------------------

    // -----------------------------------------------------------------------

    class Secure {
        public:
            /// @fn CDC::Secure()
            /// @brief default constructor
            Secure(){};

            /// @fn CDC::Secure(string MainCFG)
            /// @brief Init Secure class via CFG file
            /// @param ConfigPath path to .cfg file
            Secure(string MainCFG);

            ~Secure(){};

            /// @fn void CDC::Secure::GetPaths()
            /// @brief Print paths of Secure
            void GetPaths();


            // functions
            // ---------------------------------------------------------------
            /// @fn string CDC::Secure::Hide(string Passwd)
            /// @brief Return hash of password via SHA512 method
            /// @param Passwd password string
            /// @return [string] password hash
            string Hide(string Passwd);

            /// @fn bool CDC::Secure::Enter(string Login, string Passwd)
            /// @brief Enter of user to CDC app
            /// @details - Check user existance
            ///          - Compare passwd hash
            ///          - Set Secure level and current login
            ///          - Add entry to Entered File (remove entry if login is exists there)
            ///          - (?) Open Interface (?)
            /// @param Login login
            /// @param Passwd password
            /// @return return true in case of success else false
            bool Enter(string Login, string Passwd);

            /// @fn bool CDC::Secure::Exit(bool exit)
            /// @brief Exit CDC app
            /// @param ExitVal value, if = 1 close prog else remove entry only
            /// @details - Del entry from Entered File
            ///          - if exit = 1 close prog
            void Exit(bool ExitVal);

            /// @fn void CDC::Secure::Register(string Login, string Passwd)
            /// @brief Update password of user
            /// @param Login login
            /// @param Passwd password
            /// @return return true in case of success else false
            bool Register(string Login, string Passwd);

            /// @fn bool CDC::Secure::CheckCapability()
            /// @brief Check access to secure level
            /// @return return true in case of success else false
            bool CheckCapability(unsigned short RequiredLevel);
            // ---------------------------------------------------------------



        private:
            string LoginFilePath;
            string EnteredUsersPath;
            string EmergencyPath;
            unsigned short SecureLevel;

            string CurrentLogin;

            // secure private functions
            //bool invalidChar(char c);
            //void stripUnicode(std::string & str);
    };

}

#endif // CDC_SECURE_HPP
