#ifndef CDC_TASKLOADER_HPP
#define CDC_TASKLOADER_HPP

#include "Config.hpp"           // cfg work
#include "Base.hpp"             // constants
#include "Project.hpp"

#include <qt5/QtCore/QJsonObject>
#include <qt5/QtCore/QJsonArray>
#include <qt5/QtCore/QJsonDocument>
#include <qt5/QtCore/QJsonValue>
#include <qt5/QtCore/QFile>

#include <algorithm>
#include <string>


/// @class CDC::Project
/// @brief Project management
namespace CDC {
    class TaskLoader {
        public:
            /// @fn CDC::Project()
            /// @brief default constructor
            TaskLoader(){};
            ~TaskLoader(){};

            /// @fn CDC::Project(string MainCFG)
            /// @brief Init Project class via CFG file
            /// @param ConfigPath path to .cfg file
            TaskLoader(string MainCFG);

            /// Load Json Task from specified path
            void LoadTask(string TaskPathJson);

        private:
            string ProjectsPath;
            QByteArray open_read_file(std::string JsonFile);
    };

}

#endif // CDC_TASKLOADER_HPP
