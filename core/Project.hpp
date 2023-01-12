#ifndef CDC_PROJECT_HPP
#define CDC_PROJECT_HPP

#include <string>
#include "stdlib.h"
#include <filesystem>
namespace fs = std::filesystem;

#include "Config.hpp"           // cfg work
#include "Base.hpp"             // constants

#include <QStringList>
#include <QString>


/// @class CDC::Project
/// @brief Project management
namespace CDC {

    class Project {
        public:
            /// @fn CDC::Project()
            /// @brief default constructor
            Project(){};
            ~Project(){};

            /// @fn CDC::Project(string MainCFG)
            /// @brief Init Project class via CFG file
            /// @param ConfigPath path to .cfg file
            Project(string MainCFG);

            /// @fn CDC::Project(string project_path)
            /// @brief Init Project class via project path
            /// @param project_path path to projects
            void SetProjectPath(string project_path){ ProjectsPath = project_path; }

            /// @fn bool CDC::Project::CreateProject(string ProjectName, string ProjectStatus)
            /// @brief Create project dir and meta file. If project exists, update status only.
            /// @return return true in case of success else false
            bool CreateProject(string ProjectName, string ProjectStatus);

            /// @fn bool CDC::Project::DeleteProject(string ProjectName)
            /// @brief Remove project dir
            void DeleteProject(string ProjectName);

            /// @fn bool CDC::Project::FindProjects(string Pattern)
            /// @brief Find project via specified pattern
            /// @return [string] Lines of found projects by Pattern
            string FindProjects(string Pattern);

            /// @fn bool CDC::Project::ListProjects()
            /// @brief List all projects (paths)
            /// @return [string array] Array of found projects
            QStringList ListProjects();

            /// @fn bool CDC::Project::ListProjectNames()
            /// @brief List all project names
            /// @return [string array] Array of found project names
            QStringList ListProjectNames();


        private:
            string ProjectsPath;
    };

}

#endif // CDC_PROJECT_HPP
