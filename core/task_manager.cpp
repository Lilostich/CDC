#include "task_manager.h"
#include <QDir>
#include <iostream>

Task_manager::Task_manager()
{

}


Task_manager::Task_manager(string MainCFG) {
    // read ProjectsPath
    string tmp_str = GetEntry_InConfig(MainCFG, "SysProjects");
    if (tmp_str.empty())
        throw std::invalid_argument("Error to read Projects Path from CFG file");
    ProjectsPath = tmp_str;

    // read ReportsPath
    string tmp_str = GetEntry_InConfig(MainCFG, "SysReports");
    if (tmp_str.empty())
        throw std::invalid_argument("Error to read Projects Path from CFG file");
    ReportsPath = tmp_str;

    // read ResultsPath
    string tmp_str = GetEntry_InConfig(MainCFG, "SysResults");
    if (tmp_str.empty())
        throw std::invalid_argument("Error to read Projects Path from CFG file");
    ResultsPath = tmp_str;
}


std::string Task_manager::print_list_project() {
    std::string Answer;

    QDir dir((ProjectsPath.c_str());
    QStringList list = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (int i = 0; i <list.size(); i++) {
        // std::cout << i << ") " << list[i].toStdString() << std::endl;
        Answer = Answer + "\n" + list[i].toStdString();
    }

    return Answer;
}


std::string Task_manager::print_list_task(std::string ProjectName) {
    std::string Answer;
    string FullProjectPath = ProjectsPath + "/" + ProjectName;

    QDir dir(FullProjectPath.c_str());
    QStringList list = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (int i = 0; i <list.size(); i++){
        //QDir dirTask(dir.path() + "/" + list[i]);
        //QStringList listTask = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        //for (int j = 0; j < listTask.size(); j++){
        //    std::cout << i << "." << j << ") " << listTask[j].toStdString() << std::endl;;
        //}
        Answer = Answer + "\n" + list[i].toStdString();
    }
    return Answer;
}


QByteArray Task_manager::open_read_file(std::string JsonFile) {
    QFile File;
    File.setFileName(JsonFile.c_str());
    File.open(QIODevice::ReadOnly | QIODevice::Text);
    //QFile metaFile(JsonFile.c_str());

    QByteArray contents = File.readAll();
    File.close();
    return contents;
}


void Task_manager::close_task(std::string project_name, std::string task_id) {
    std::string TaskFilePath = ProjectsPath + "/" + project_name + "/" + task_id + "/" + task_id + ".json"

    // load json
    QByteArray TaskPathJsonByte = open_read_file(TaskFilePath);
    QJsonDocument TaskPathJsonDoc(QJsonDocument::fromJson(TaskPathJsonByte));
    QJsonObject TaskJson(TaskPathJsonDoc.object());

    // get fields
    QString closed("closed");
    TaskJson["status"] = closed;

    TaskPathJsonDoc.setObject(TaskJson);
    QFile OutFile(TaskFilePath.c_str());
    OutFile.write(TaskPathJsonDoc.toJson());
}

void UploadTaskID(std::string project_name, std::string task_id){
    std::string TaskFilePath = ProjectsPath + "/" + project_name + "/" + task_id + "/" + task_id + ".json"
    std::string ReportFilePath = ReportsPath + "/" + task_id + "_TASKID.json"

    // load json
    QByteArray TaskPathJsonByte = open_read_file(TaskFilePath);
    QJsonDocument TaskPathJsonDoc(QJsonDocument::fromJson(TaskPathJsonByte));
    QJsonObject TaskJson(TaskPathJsonDoc.object());

    // get fields
    QString TaskID(task_id);
    TaskJson["TaskID"] = TaskID;

    TaskPathJsonDoc.setObject(TaskJson);
    QFile OutFile(ReportFilePath.c_str());
    OutFile.write(TaskPathJsonDoc.toJson());
}

void UploadRun(std::string project_name, std::string task_id, std::string test_run) {
    std::string ReportFilePath = ReportsPath + "/" + task_id + "_RUN.json"
    std::string RunFilePath = ProjectsPath + "/" + project_name + "/" + task_id + "/" + test_run + ".meta"

    // load run json
    QByteArray RunPathJsonByte = open_read_file(RunFilePath);
    QJsonDocument RunPathJsonDoc(QJsonDocument::fromJson(RunPathJsonByte));
    QJsonObject RunJson(RunPathJsonDoc.object());

    // set fields
    QString TaskID(task_id);
    RunJson["TaskID"] = TaskID;

    RunPathJsonDoc.setObject(RunJson);
    QFile OutFile(ReportFilePath.c_str());
    OutFile.write(RunPathJsonDoc.toJson());
}

void UploadResults(std::string project_name, std::string task_id, std::string log) {
std::string TaskFilePath = ProjectsPath + "/" + project_name + "/" + task_id + "/" + task_id + ".json"
    std::string ReportFilePath = ReportsPath + "/" + task_id + "_" + log + "_RESULTS.json";
    std::string ResultsFilePath = ProjectsPath + "/" + project_name + "/" + task_id + "/" + test_run + ".meta"

    // load resutls as string
    std::string ResultsString = open_read_file(ResultsFilePath).toStdString();

    // load json Task
    QByteArray TaskPathJsonByte = open_read_file(TaskFilePath);
    QJsonDocument TaskPathJsonDoc(QJsonDocument::fromJson(TaskPathJsonByte));
    QJsonObject TaskJson(TaskPathJsonDoc.object());

    // set fields
    QString Results(ResultsString);
    RunJson["Results"] = Results;

    TaskPathJsonDoc.setObject(RunJson);
    QFile OutFile(ReportFilePath.c_str());
    OutFile.write(TaskPathJsonDoc.toJson());
}
