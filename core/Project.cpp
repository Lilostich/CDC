#include "Project.hpp"

using namespace CDC;


CDC::Project::Project(string MainCFG) {
    // read ProjectsPath
    string tmp_str = GetEntry_InConfig(MainCFG, "SysProjects");
    if (tmp_str.empty())
        throw std::invalid_argument("Error to read Projects Path from CFG file");
    ProjectsPath = tmp_str;
}


bool CDC::Project::CreateProject(string ProjectName, string ProjectStatus){
    // create project path
    string NewProjectPath = ProjectsPath + "/" + ProjectName;
    string cmd = "mkdir -p " + NewProjectPath;
    if (system(cmd.c_str()))
        return false;

    // create or update meta-file
    string ProjectMeta = NewProjectPath + "/" + ProjectName + ".cfg";
    cmd = "touch " + ProjectMeta;
    if (system(cmd.c_str()))
        return false;

    // update fields
    AddEntry_InConfig(ProjectMeta, "Name", ProjectName);
    AddEntry_InConfig(ProjectMeta, "Status", ProjectStatus);

    return true;
}


void CDC::Project::DeleteProject(string ProjectName) {
    // remove project path
    string ProjectPath = ProjectsPath + "/" + ProjectName;
    string cmd = "rm -rf " + ProjectPath + " 2> /dev/null";
    system(cmd.c_str());
}


string CDC::Project::FindProjects(string Pattern) {
    string Answer = "";
    string tmp_str;
    for (const auto & entry : fs::directory_iterator(ProjectsPath)) {
        // std::cout << entry.path() << std::endl;
        tmp_str = entry.path().string();
        if (tmp_str.find(Pattern) != std::string::npos)
            Answer = Answer + "\n" + tmp_str;
    }

    return Answer;
}


QStringList CDC::Project::ListProjects() {
     QStringList Answer = {};
    for (const auto & entry : fs::directory_iterator(ProjectsPath)) {
        Answer << QString::fromStdString(entry.path().string());
    }

    return Answer;
}


QStringList CDC::Project::ListProjectNames() {
     QStringList Answer = {};
    for (const auto & entry : fs::directory_iterator(ProjectsPath)) {
        Answer << QString::fromStdString(entry.path().string().substr(entry.path().string().find_last_of("/\\") + 1));
    }

    return Answer;
}
