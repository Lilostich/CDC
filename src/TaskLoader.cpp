#include "TaskLoader.hpp"

using namespace CDC;


CDC::TaskLoader::TaskLoader(string MainCFG) {
    // read ProjectsPath
    string tmp_str = GetEntry_InConfig(MainCFG, "SysProjects");
    if (tmp_str.empty())
        throw std::invalid_argument("Error to read Projects Path from CFG file");
    ProjectsPath = tmp_str;
}


QByteArray CDC::TaskLoader::open_read_file(std::string JsonFile) {
    QFile File;
    File.setFileName(JsonFile.c_str());
    File.open(QIODevice::ReadOnly | QIODevice::Text);
    //QFile metaFile(JsonFile.c_str());

    QByteArray contents = File.readAll();
    File.close();
    return contents;
}


void CDC::TaskLoader::LoadTask(string TaskPathJson) {
    // load json
    cout << "RAZ" << endl;
    QByteArray TaskPathJsonByte = open_read_file(TaskPathJson);
    cout << "DVA" << endl;
    QJsonDocument TaskPathJsonDoc(QJsonDocument::fromJson(TaskPathJsonByte));
    cout << "TREE" << endl;
    QJsonObject TaskJson(TaskPathJsonDoc.object());
    cout << "CH" << endl;

    // get fields
    string TaskName         = TaskJson["name"].toString().toStdString();
    string TaskDeadline     = TaskJson["deadline"].toString().toStdString();
    string TaskDate         = TaskJson["date"].toString().toStdString();
    string TaskProject      = TaskJson["project"].toString().toStdString();
    string ProjectStatus    = TaskJson["status"].toString().toStdString();

    // gen task id
    string TaskId = TaskProject + "_" + TaskName + "_" + TaskDate;
    replace(TaskId.begin(), TaskId.end(), ' ', '_'); // удалить пробелы
    cout << "ID: " << TaskId << endl;

    // create project dir
    Project ProjectManager;
    ProjectManager.SetProjectPath(ProjectsPath);
    ProjectManager.CreateProject(TaskProject, ProjectStatus);

    // mkdir task
    string TaskPath = ProjectsPath + "/" + TaskProject + "/" + TaskId;
    string cmd = "mkdir -p " + TaskPath;
    system(cmd.c_str());

    // copy task to project dir
    cmd = "cp " + TaskPathJson + " " + TaskPath + "/" + TaskId + ".json";
    system(cmd.c_str());
}
